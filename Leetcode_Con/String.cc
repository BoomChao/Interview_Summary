


/*
    以空格切分字符串:利用istringstream
    注:getline遇到以下情况会导致生成的字符串结束
    1.到达文件末尾   2.遇到函数的定界符     3.输入达到最大限度
    如: string str = "1...."
    std::stringstream in(str);
    std::string out;
    while(getline(in, out, '.')) {
        std::cout << out;           //输出结果中只有 "1"
    }

*/

int main() {
    std::string str;
                                //getline函数接受输入默认以回车键结束,接受的字符串可以包含空格
    getline(std::cin, str);     //从标准输入终端接受一行字符串,注意不能以std::cin>>str,std::cin输入字符串是以 "空格", "TAB", "回车结束"

    //利用输入流将其划分成单个字符后输入到vector中(字符串中的单个单词以空格分割)
    std::stringstream in(str);     
    std::string out;
    std::vector<std::string> strs;

    //方法一:使用这种while语句
    while(in >> out) {
        strs.push_back(out);
    }

    //方法二:使用getline语句           //getline的第一个参数只能是输入输出流
    while(getline(in, out, ' ')) {  //getline的第三个参数如果不写则默认以回车结束
        strs.push_back(out);
    }

    return 0;
}



/////////////////////////////
// KMP算法：参看Youtube
/////////////////////////////

int KMP(std::string str, std::string pattern)
{
    int m = str.size(), n = pattern.size();

    std::vector<int> prefix = computePrefix(pattern);
    
    for(int i = 0, k = 0; i < m; i++)
    {
        while(k > 0 && pattern[k] != str[i]) {
            k = prefix[k-1];
        }

        if(str[i] == pattern[k]) k++;

        //匹配成功,返回下标
        if(k == n) return i - m + 1;
    }

    return -1;  //表示不存在
}

std::vector<int> computePrefix(const std::string &pattern)
{
    int n = pattern.size();
    std::vector<int> prefix(n, 0);

    //这个i从1开始
    for(int i = 1, k = 0; i < n; i++)
    {
        while(k > 0 && pattern[k] != pattern[i]) {
            k = prefix[k-1];
        }

        if(pattern[i] == pattern[k]) {
            prefix[i] = ++k;
        }
        else {
            prefix[i] = k;
        }
    }

    return prefix;
}





/*
    按照指定字符切分字符串
    参考Leetcode第468题 : 判断IP地址是否合法
*/


// 判断是否为有效的IP地址:
// 方法一: 切分后一个一个比较

std::string validIpAddress(std::string IP)
{
    return isIPv4(IP) ? "IPv4" ? (isIPV6(IP) ? "IPv6" : "Neither");
}

bool isIPv4(const std::string &IP)
{
    if(count(IP.begin(), IP.end() '.') != 3) return false;

    std::vector<std::string> strs = spilt(IP, '.');

    if(strs.size() != 4) return false;

    for(const auto &str : strs) 
    {
        if(str.size() > 3) return false;

        if(str.size() != 1 && str[0] == '0') return false;

        for(const char &c : str) {
            if(!isdigit(c)) return false;
        }

        if(std::stol(str) > 255) return false;
    }

    return true;
}

bool isIPV6(const std::string &IP)
{
    if(count(IP.begin(), IP.end(), ':') != 7) return false;

    std::vector<std::string> strs = spilt(IP, ':');

    if(strs.size() != 8) return false;

    for(auto &str : strs)
    {
        if(str.size() > 4) return false;
        
        for(const char &c : str) 
        {
            if(!isdigit(c) && !(toupper(c) >= 'A' && toupper(c) <= 'F')) return false;
        }
    }

    return true;
}


std::vector<std::string> spilt(std::string IP, char c)
{
    std::stringstream in(IP);
    std::string out;

    std::vector<std::string> res;

    while(getline(in, out, c)) {
        if(!out.empty()) {
            res.push_back(out);
        }
    }

    return res;
}


// 方法二:使用正则表达式

std::string validIpAddress(std::string IP)
{
    // 注意:这个转译符"\\."前面的"()"一定要加,否则识别不出来,将匹配的部分需要单独使用"()"括起来
    // "\."在正则表达式中表示点
    // 但是在C++里面表示 '\' 需要利用转义 '\\',所以C++里面表示正则里面的 '\.' 就是要使用 "\\."
    regex ipv4("((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])\\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])");
    regex ipv6("((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]{1,4})");

    regex IPv4("((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])\\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])");
    regex ipv6("([0-9a-fA-F]{1,4}\\:){7}([0-9a-fA-F]{1,4})");

    //上面这两种转义都可以

    if(regex_match(IP, ipv4)) {
        return "IPv4";
    }
    else if(regex_match(IP, ipv6)) {
        return "Ipv6";
    }
    
    return "Neither";
}



/*
    两个字符串的最长公共子串 (参考牛客算法篇NC127)
*/

// dp[i][j]表示以s[i]结尾和t[j]结尾的最长公共子串长度
// if s[i]!=t[j], dp[i][j] = 0
// if s[i]=t[j],  dp[i][j] = dp[i-1][j-1] + 1, 遍历的过程中记录最大的dp[i][j](maxLen)和所对应的子串起始下标 i-dp[i][j]
// 返回 s.substr(i, maxLen)

std::string longestCommonSubstring(std::string s, std::string t)
{
    if(s.empty() || t.empty()) return "";

    int m = s.size(), n = t.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    int maxLen = 0, startIndex = 0;

    for(int i = 1; i <= m; i++) 
    {
        for(int j = 1; j <= n; j++) 
        {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;

                if(dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    startIndex = i - dp[i][j];       //注意:这里可以用i减也可以用j减,用j减去则返回结果要写为 t.substr(j, len)
                }
            }
        }
    }

    return maxLen == 0 ? "" : s.substr(startIndex, maxLen);
}


/*
    两个字符串的最长公共子序列
    Leetcode第1143题

*/

// dp[i][j]表示 到s[i]位置和t[j]位置目前最长的公共子序列长度
// 则 if s[i]=t[j], dp[i][j] = dp[i-1][j-1] + 1
//    else dp[i][j] = std::max(dp[i-1][j], dp[i][j-1])
// i从0开始, 则i-1=-1,所以集中将dp数组后移一个维度
// 则base case i = 0(代表s为空串), j = 0(代表t为空串), dp[0][j] = 0, dp[i][0] = 0

// 倒推结果时从i=m,j=n开始推
// 1.如果s[i-1] = t[j-1], 将s[i-1]加入结果, i--, j--
// 2.如果s[i-1] != t[j-1], 判断dp[m-1][n]和dp[m][n-1]
//   如果dp[m-1][n] > dp[m][n-1], 说明dp[m][n]是从dp[m-1][n]推导过来的, 将 i--
//   否则说明是从 dp[m][n-1]推导过来的, 将 j--
// 3.最后将结果逆序即可

int longesetCommonSubsequence(std::string text1, std::string text2)
{
    int m = text1.size(), n = text2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    //倒推结果
    std::string res;
    for(int i = m, j = n; i > 0 && j > 0 && dp[i][j] >= 1;)     //dp[i][j]要是小于1就没必要遍历下去了,肯定没有公共的序列
    {
        if(text1[i-1] == text2[j-1]) {
            res += text1[i-1];
            i--, j--;
        }
        else if(dp[i-1][j] >= dp[i][j-1]) i--;  //说明当前dp[i][j]是从dp[i-1][j]推导出来的,反推应该减少i,最长子序列在s[0..i-1]和t[0..j]之间
        else j--;                               //同理这说明dp[i][j]是从dp[i][j-1]推导出来的,反推应该减少j
    }

    reverse(res.begin(), res.end());   //将所得的结果正序

    std::cout << res << std::endl;

    return dp[m][n];
}


//Leetcode第792题: 字符串子序列的个数

int numMatchingSubseq(std::string s, std::vector<std::string> &words)
{
    std::vector<std::vector<int>> alpha(26);
    for(int i = 0; i < s.size(); i++) {
        alpha[s[i]-'a'].push_back(i);
    }

    int count = 0;

    for(const auto &word : words)
    {
        int x = 0;
        bool find = true;

        for(char &c : word) {
            auto it = lower_bound(alpha[c-'a'].begin(), alpha[c-'a'].end(), x);
            if(it == alpha[c-'a'].end()) {
                find = false;
                break;
            }
            x = *it + 1;
        }

        if(find) count++;
    }

    return count;
}



///////////////////////////////////
//
//      回文串系列
//
//        9题: 判断一个数字是否为回文数
//      131题: 找到将字符串切割成回文串的所有组合
//      132题: 切割成回文串的最小次数
//      516题: 最长回文子序列
//        5题: 最长回文子串
//      214题: 添加字符组成最短的回文子串
//
//      409题: 给出一个字符串,判断由该字符串的字符能组成的最大回文串的长度
//      336题: 判断字符串数组能组成回文对的个数
//      680题: 判断只删除一个字符能否构成回文串
//     1312题: 将字符串组成回文串的最少插入操作
//      
//////////////////////////////////

//Leetcode第9题:判断是否为回文数

bool isPalindrome(int x)
{
    if(x == 0) return true;
    if(x < 0 || x%10 == 0) return false;

    int ans = 0, tmp = x;
    
    while(x) {
        if(ans > INT_MAX/10 || (ans == INT_MAX/10 && x%10 > 7)) return false;     //判断是否溢出
        ans = ans*10 + (x%10);
        x /= 10;
    }

    return ans == tmp;
}

//附:Leetcode第7题:逆转数字

int reverse(int x)
{
    int res = 0;
    while(x) 
    {
        if(res > INT_MAX/10 || res < INT_MIN/10 || (res == INT_MAX/10 && x%10 > 7) || (res == INT_MIN/10 && x%10 < -8)) return 0;  //这里不能写>=,注意例子1463847412
        res = res*10 + x%10;
        x /= 10;
    }

    return res;
}



//Leetcode第131题: 将一个字符串切割成回文串,找到所有的可能的组合
//DFS

// 时间复杂度分析:一共有n个字符,则一共有n个位置可以去切割
// 只切割一次有C(N,1)=N,切割两次有C(N,2)=N(N-1),切割三次有C(N,3) = N(N-1)(N-2)
// 所以一共加起来有C(N,1)+C(N,2)+...+C(N,N) = 2^n-1
// 再加上判断回文串的时间复杂度为O(N),所以总的时间复杂度为O(N*2^N)

// 方法二:有N个位置可以切割,每个位置可以有切或者不切两种方式,则一共有2^N种可能


//解法一:
std::vector<std::vector<std::string>> res;

std::vector<std::vector<std::string>> partition(std::string s)
{
    std::vector<std::string> par;

    dfs(s, 0, par);

    return res;
}

void dfs(const std::string &s, int pos, std::vector<std::string> &par)
{
    if(pos == s.size()) {
        res.push_back(par);
        return ;
    }

    for(int i = pos; i < s.size(); i++) 
    {
        if(isPalindrome(s, pos, i)) {
            par.push_back(s.substr(pos, i - pos + 1));
            dfs(s, i + 1, par);
            par.pop_back();
        }
    }

}

bool isPalindrome(const std::string &str, int left, int right)
{
    while(left < right) {
        if(str[left++] != str[right--]) return false;
    } 

    return true;
}


// 解法二: 提前判断好哪些位置之间的字符能够组成回文串
// 1.先判断[i..j]能够组成回文串
// dp[i][j] = 1. if s[i]=s[j] && (dp[i+1][j-1] = 1 || j-i <=2)
// dp[i][j] = 0. else 其他情况
// 从下往上判断

std::vector<std::vector<std::string>> partition(std::string s)
{
    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for(int i = n - 1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            if(s[i] == s[j] && (j - i <= 2 || dp[i+1][j-1])) {
                dp[i][j] = 1;
            }
        }
    }

    std::vector<std::string> path;

    dfs(s, 0, dp, path);

    return res;
}


void dfs(const std::string &s, int pos, const std::vector<std::vector<int>> &dp, std::vector<std::string> &path)
{
    if(pos == s.size()) {
        res.push_back(path);
        return;
    }

    for(int i = pos; i < s.size(); i++)
    {
        if(dp[pos][i]) {
            path.push_back(s.substr(s, pos, i - pos + 1));
            dfs(s, i + 1, dp, path);
            path.pop_back();
        }
    }
}


/*
    切割成回文串的最小次数
    Leetcode第132题(左神P293)
*/

// dp[i][j]代表str[i...j]是否为回文串
// dp[i][j] = 1. if s[i]=s[j] && (dp[i+1][j-1] = 1 || j-i <=2)
// dp[i][j] = 0. else 其他情况
// mincut[i]代表字符串str[i..n-1]从i位置到字符串末尾的最小切割次数

// 当dp[i][j] = 1时. 
// minCut[i] = 0, if j == n-1, 表示[i..n-1]都是回文串,则minCut[i]当然就是0,不需要切割
// minCut[i] = minCut[j+1] + 1, if j != n-1 ,表示[i..j]是回文串,则minCut[i]就等于minCut[j]+1, 这个加1表示j位置需要切割一次

int minCut(std::string s)
{
    if(s.empty()) return 0;
    int n = s.size();

    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    std::vector<int> minCut(n, n-1);

    for(int i = n-1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            // 判断字符串s[i..j]是否是回文串
            if(s[i] == s[j] && (j-i <= 2 || dp[i+1][j-1]))  // 这个<=也可以换成<,这样的话当j-i=2时会进入后面的一条语句dp[i+1][j-1]判断,dp[i][i]总是为真的
            {
                dp[i][j] = 1;
                if(j == n-1) {      //j能够遍历到j=n-1 就表明[i,n-1]整个就是一个回文串,不需要分割
                    minCut[i] = 0;      
                }
                else {              //计算最小切割数
                    minCut[i] = std::min(minCut[i], minCut[j+1] + 1);
                }
            }
        }
    }

    return minCut[0];
}


//Leetcode第516题: 最长回文子序列

// dp[i][j]表示s[i..j]的最长回文子序列
// dp[i][j] = dp[i+1][j-1] + 2, if s[i] = s[j] (j > i)
// dp[i][j] = max(dp[i+1][j], dp[i][j-1]), else

// base case : j = i 时, dp[i][i] = 1

//方法一 : base case额外拿出来处理

int longestPalindromeSubseq(std::string s)
{
    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));    //dp[i][j]表示s的[i..j]的最长回文子序列长度

    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    //注意遍历的方向
    for(int i = n-1; i >= 0; i--) {
        for(int j = i + 1; j < n; j++) {    //注意这里j是从 i+1 开始遍历
            if(s[i] == s[j]) {
                dp[i][j] = dp[i+1][j-1] + 2;
            }
            else {
                dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }

    return dp[0][n-1];
}

//方法二 : 

int longestPalindrome(std::string s)
{
    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for(int i = n-1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            if(s[i] == s[j]) {
                if(i == j) dp[i][j] = 1;         //base case放在这里来处理
                else dp[i][j] = dp[i+1][j-1] + 2;
            }
            else dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
        }
    }

    return dp[0][n-1];
}



//Leetocode第1745题:　判断一个字符串是否由(三个连续)的回文串拼接成
//思路：构建dp数组，dp[i][j]表示字符串str[i...j]是否为回文串

bool checkPartitioning(std::string s)
{
    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for(int i = n-1; i >= 0; i--) {
        for(int j = i+1; j < n; j++) {
            if(s[i] == s[j]) {
                dp[i][j] = (j-i+1 <= 2) ? 1 : dp[i+1][j-1];
            }
        }
    }

    for(int i = 1; i < n-1; i++) {
        for(int j = 1; j < n-1; j++) {
            if(dp[0][i-1] && dp[i][j] && dp[j+1][n-1]) return true;
        }
    }

    return false;
}



// Leetcode第647题 : 字符串中有多少个回文串 
// 思路(方法很巧妙,对每个字符都寻找)

int countSubstrings(std::string s)
{
    int res = 0;
    
    for(int i = 0; i < s.size(); i++) 
    {
        res += extendSubstrings(s, i, i);     //以字符i为中心向两边扩张(回文串个数为奇数个)
        res += extendSubstrings(s, i, i+1);   //以窗口[i,i+1]为中心向两边扩张(回文串个数为偶数个)
    }

    return res;
}

int extendSubstrings(std::string s, int left, int right)
{
    int count = 0;
    while(left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
        count++;
    }

    return count;
}


//方法二:动态规划

//判断 s[i..j]为回文串,如果为回文串则计数+1即可

int countSubstrings(std::string s)
{
    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n,0));     //dp[i][j]表示字符串[i..j]是否为回文串

    int count = 0;

    for(int i = n-1; i >= 0; i--) {     //从后往前遍历
        for(int j = i; j < n; j++) {
            if(s[i] == s[j] && (j - i < 2 || dp[i+1][j-1]))
            dp[i]][j] = 1;
            count++;
        }
    }

    return count;
}


//Leetcode第5题 : 最长回文子串  
//思路:本质上还是利用的滑动窗口
//时间复杂度O(n)
//这一题也可以使用动态规划,但是时间复杂度为O(n^2)

std::string longestPalindrome(std::string s)
{
    if(s.empty()) return s;

    int startIndex = 0, maxLen = 0;
    int i = 0;

    while(i < s.size())
    {
        int start, end;
        start = end = i;
        while(end + 1 < s.size() && s[end] == s[end+1]) {
            end++;
        }

        i = end + 1;

        while(start - 1 >= 0 && end + 1 < s.size() && s[start-1] == s[end+1]) {
            start--;
            end++;
        }

        int curLen = end - start + 1;
        if(curLen > maxLen) {
            curLen = end - start + 1;
            startIndex = start;
        }
    }

    return s.substr(startIndex, maxLen);
}


//解法二:动态规划 (与上面的最长回文子序列对比)

int longestCommonSubstring(std::string s)
{
    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    int startIndex = 0;     
    int maxLen = 1;     //这里防止只有单个字符,所以将maxLen设置为1,因为当 s = "a"时,下面的循环是不会执行的

    //注意遍历的方向
    for(int i = n-1; i >= 0; i--) {
        for(int j = i + 1; j < n; j++) {
            if(s[i] == s[j] && (j-i+1 <= 2 || dp[i+1][j-1])) {
                dp[i][j] = 1;
            }
            if(dp[i][j] == 1 && maxLen < j-i+1) {
                startIndex = i;
                maxLen = j - i + 1;
            }
        }
    }

    return s.substr(startIndex, maxLen);
}



//Leetcode第214题:在字符串首部添加字符计算构成的完整的最短回文串的长度

//思路:计算包含首字符的最长回文串,之后将剩下的字符串翻转加在字符串首部即是最短的回文串

std::string shortestPalindrome(std::string s)
{
    int n = s.size();
    if(n < 2) return s;     //注意：这里必须要判断，否则如果要是空字符串，则maxLen=1, 下面的substr操作就是错误的

    int maxLen = 0;     //以首字母开始的最长回文串的长度

    int i = 0;      //包括首字符的最长回文串的下标
    while(i <= n/2)
    {
        int start, end;
        start = end = i;

        while(end + 1 < n && s[end] == s[end+1]) end++;

        i = end + 1;

        while(start - 1 >= 0 && end + 1 < n && s[start-1] == s[end+1]) {
            start--;
            end++;
        }

        //必须包含start = 0才行
        if(start == 0 && maxLen < end-start+1) {
            maxLen = end - start + 1;
        }
    }

    //取出剩下的非回文串的部分并翻转
    std::string remain = s.substr(maxLen);

    reverse(remain.begin(), remain.end());

    return remain + s;
}


//Leetcode第409题: 给出一个字符串,判断由该字符串的字符能组成的最大回文串的长度

// 统计字符串偶数对的个数,判断最后集合是否还存在元素，如果存在则回文串长度为2*偶数对个数+1,否则为2*偶数对个数

int longestPalindrome(std::string s)
{
    std::unordered_set<char> mySet;
    int count = 0;

    for(const char &c : s) {
        if(mySet.count(c)) {
            mySet.erase(c);
            count++;
        }
        else
            mySet.insert(c);
    }

    return mySet.empty() ? count*2 : count*2 + 1;
}



//Leetcode第336题: 字符串回文对数

// 1.如果s1空字符串,则对任何回文字符串s2,(s1+s2),(s2+s1)都是回文串
// 2.如果s2是s1的逆序字符串,则(s1+s2)和(s2+s1)都是回文串
// 3.如果s1[0:cut]是回文串,并且存在s2是s1[cut+1:]的逆字符串,则s2+s1是回文串
// 4.如果s1[cut+1:]是回文串,并且存在s2是s1[0:cut]的逆字符串,则s1+s2是回文串

std::vector<std::vector<int>> palindromePairs(std::vector<std::string> &words)
{
    std::unordered_map<std::string, int> mp;    //字符串对应的下标
    std::vector<std::vector<int>> res;

    for(int i = 0; i < words.size(); i++) {
        auto key = words[i];
        reverse(key.begin(), key.end());
        mp[key] = i;
    }

    //先处理空字符串情况
    if(mp.count(""))
    {
        for(int i = 0; i < words.size(); i++) {
            if(mp[words[i]] == i) continue;
            if(isPalindrome(words[i])) res.push_back({mp[""], i});
        }
    }

    for(int i = 0; i < words.size(); i++)
    {
        for(int j = 0; j < words[i].size(); j++)    //如何是空字符串,size=0,不会进入到这个循环中
        {
            std::string left = words[i].substr(0,j);
            std::string right = words[i].substr(j);

            // j = 0就对应第二种情况

            //对应情况4
            if(mp.count(left) && isPalindrome(right) && mp[left] != i) {
                res.push_back({i, mp[left]});
            }

            //对应情况3
            if(mp.count(right) && isPalindrome(left) && mp[right] != i) {
                res.push_back({mp[right], i});
            }
        }
    }

    return res;
}


bool isPalindrome(const std::string &s)
{
    int i = 0, j = s.size() - 1;

    while(i < j) {
        if(s[i++] != s[j--]) return false;
    }

    return true;
}


//Leetcode第680题: 判断字符串只删除一个字符能否组成回文串

// 思路: 双指针直接遍历,发现第一个不相同的字符略过,之后再继续遍历再有不相同则直接返回false

bool validPalindrome(std::string s)
{
    int left = 0, right = s.size() - 1;

    while(left < right)
    {
        if(s[left] != s[right])
        {
            int i1 = left + 1, j1 = right;        //考虑两种情况,需要略过左侧字符还是右侧字符
            int i2 = left, j2 = right - 1;

            while(i1 < j1 && s[i1] == s[j1]) { i1++; j1--; }
            while(i2 < j2 && s[i2] == s[j2]) { i2++; j2--; }

            return i1 >= j1 || i2 >= j2;    //有一种情况满足即可
        }
        left++;
        right--;
    }

    return true;
}



//Leetcode第1312题：将字符串组成回文串的最少插入操作

//思路：1.判断原来的字符串有多少个回文字符，将总字符数减去回文字符数即为结果
//     2.利用两个字符串的最长公共子序列来判断原来字符串的回文字符个数

//思维发散：这一题如果是删除操作或者删除和插入都允许，结果也是这个结果
//因为求得最长的回文字符个数后，删除或插入操作次数都是一样的,只不过插入操作是将剩下的字符组成回文串，删除操作是直接删除掉原来的字符

int minInsertions(std::string s)
{
    int n = s.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

    std::string s1 = s;
    reverse(s1.begin(), s1.end());

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == s1[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return n - dp[n][n];
}




////////////////////////////
//
//      删除字符串重复字符系列
//
//      1047题: 删除字符串所有相邻的重复元素
//      1209题: 删除字符串中所有相邻的重复元素中重复个数大于k的元素(即只删除删除k个重复元素,不足k个不用删除)
//       316题: 删除整个字符串中出现过的重复字符,使得删除后的字符串字典序最小
//      1044题: 最长重复子串
//
//////////////////////////

//Leetcode第1047题 : 删除字符串中所有相邻的重复字符串
//思路:利用栈(注意看清题目,是删除相邻字符)

std::string removeDuplicate(std::string str)
{
    std::string res;
    for(const char &c : str) {
        if(!res.empty() && res.back() == c) {
            res.pop_back();
        }
        else {
            res.push_back(c);
        }
    }

    return res;
}


//Leetcode第1209题 : 删除字符串中连续重复字符个数大于3的子串(三个三个删除)
//也是利用栈的思想(这两题出的非常好)

//思路:遍历的时候记录每个字符的次数(使用pair来记录),当出现次数 =k 时便删除掉当前pair
//最后剩余的pair累加即可

std::string removeDuplicates(std::string s, int k)
{
    std::vector<std::pair<char,int>> vec;   //将出现的字符以及对应的频数存入pair中

    for(const char &c : s)
    {
        if(vec.empty() || c != vec.back().first) {
            vec.push_back({c, 1});
        }
        else if(++vec.back().second == k) {
            vec.pop_back();
        }
    } 

    std::string res;
    for(auto &e : vec) {
        res += std::string(e.second, e.first);
    }

    return res;
}


//Leetcode第316题: 删除字符串中重复的字符,使得删除后的字典序最小

//哈希表先记录下每个字符出现的次数
//遍历字符串,如果当前字符没有被访问并且小于之前添加的前一个字符,并且前一个字符再之后还会出现
//则将前一个字符出队,访问位置为0,加入当前字符

std::string removeDuplicateLetters(std::string s)
{
    std::vector<int> count(128, 0);
    std::vector<int> visited(128, 0);   //标记,表示队列中的元素是否出现过(像例子 "abab"),如果不标记则结果为 "aab",防止队列中出现重复元素
    std::string res;

    //记录下每个字符出现的次数
    for(const char &c : s) {
        count[c]++;
    }

    for(const char &ch : s)
    {
        count[ch]--;        //出现次数减1
        if(visited[ch]) {   //这里一定不要忘了,这是为了避免出现重复元素
            continue;       
        }

        //当该字符小于res中已经添加进去的字符,并且之前添加进去的字符之后还会出现就将之前添加的字符倒出去
        while(!res.empty() && ch < res.back() && count[res.back()]) {
            visited[res.back()] = 0;
            res.pop_back();
        }

        res += ch;
        visited[ch] = 1;
    }

    return res;
}



//Leetcode第1044题:最长重复子串
//方法一:使用后缀数组

std::string longestDupsubstring(std::string s)
{
    std::vector<std::string> strs;

    for(int i = 0; i < s.size(); i++) {
        strs.push_back(s.substr(i));
    }

    sort(strs.begin(), strs.end());

    int maxLen = 0;
    std::string res;

    //求两个相邻字符串的公共前缀
    for(int i = 0; i < strs.size()-1; i++) {
        int tmp = lenTwoStr(strs[i], strs[i+1]);
        if(tmp > maxLen) {
            maxLen = tmp;
            res = strs[i].substr(0, maxLen);
        }
    }   

    return res;
}

int lenTwoStr(const std::string &str1, const std::string &str2)
{
    if(str1.empty() || str2.empty()) return 0;  

    int i = 0;
    while(i < str1.size() && i < str2.size() && str1[i]==str2[i]) i++;

    return i;
}



///////////////////////////
//
//      括号匹配系列
//
//      第20题  : 判断括号字符串是否有效
//      第22题  : 生成括号字符串
//      第32题  : 最长优先括号
//      第301题 : 删除无效的括号
//      第678题 : 判断一个字符串是否为有效字符串(含通配符'*')
//
//
////////////////////////////


//第20题:判断括号字符串是否有效
//使用栈


//第22题:生成括号
//DFS

std::vector<std::string> res;

std::vector<std::string> generateParenthesis(int n)
{
    if(n == 0) return res;

    int left = n, right = n;
    std::string path;

    dfs(left, right, path);

    return res;
}

void dfs(int left, int right, std::string &path)
{
    //如果左边括号剩的比右括号多,或者左右括号都用完了,这就相当于减枝
    if(left > right) return;
    if(left < 0 || right < 0) return;

    //左右括号刚好用完
    if(left == 0 && right == 0) {
        res.push_back(path);
        return;
    }

    //尝试放一个左括号
    path.push_back('(');
    dfs(left - 1, right, path);
    path.pop_back();

    //尝试放一个右括号
    path.push_back(')');
    dfs(left, right - 1, path);
    path.pop_back();

}


//第32题:最长的完整括号数量
//栈(vector)+滑动窗口

// 遇到'('加入栈,遇到')'弹出栈中元素,如果此时栈空,则将该坐标加入栈中当做起点
// 考虑两种特殊case "()", ")()", 

int longestValidParentheses(std::string s)
{
    if(s.empty()) return 0;

    std::vector<int> res;
    res.push_back(-1);      // 充当哨兵
    int ans = 0;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(') {
            res.push(i);    //入栈
        }
        else if(s[i] == ')') {  //出栈
            res.pop_back();
            
            if(res.empty()) res.push_back(i);

            ans = std::max(ans, i - res.back());
        }
    }

    return ans;
}



//第301题:删除无效的括号使得输入字符串有效

//思路:
//DFS:先确定需要删除多少个左右括号,之后挨个删除,当删除完后如果满足条件就加入到结果中去

std::vector<std::string> res;

std::vector<std::string> removeInvalidParentheses(std::string s)
{
    //left和right分表表示需要删除的'('个数和')'个数
    int left = 0, right = 0;
    for(const char &c : s) 
    {
        if(c == '(') left++;
        else if(c == ')') {
            if(left > 0) left--;
            else right++;
        }
    }

    dfs(left, right, s, 0);

    return res;
}

//pos表示删除哪个位置的字符
void dfs(std::string s, int left, int right, int pos)
{
    if(left < 0 || right < 0) return false;     //减枝

    if(left == 0 && right == 0) {
        if(isValid(s)) {
            res.push_back(s);
            return;
        }
    }

    for(int i = pos; i < s.size(); i++)
    {
        if(i > pos && s[i] == s[i-1]) continue;     // 比如 "((())", 前面连续的"((("只需要删除第一个就行，不需要三个都尝试删除

        //尝试删除一个'('
        if(s[i] == '(') {
            dfs(s.substr(0, i) + s.substr(i + 1), left - 1, right, i);  //注意：这里的i不能进位，因为删除后i恰好指向下一个新的字符了
        }
        //尝试删除一个')'
        else if(s[i] == ')') {
            dfs(s.substr(0, i) + s.substr(i + 1), left, right - 1, i);
        }
    }

}

bool isValid(std::string s)
{
    //计算括号'('的数量
    int count = 0;
    for(const char &c : s) 
    {
        if(c == '(') count++;
        else if(c == ')') count--;
        if(count < 0) return false;
    }

    return count == 0;      //易错:不要写成 return true;    //左括号多了也不行
}


// 678题:判断是否为一个有效的括号字符串
// 一个完整的字符串的左括号数和右括号数字一定是相等的,但是
// 由于这里'*'可匹配左或者右括号,所以左括号的数量是在一个范围内
// 如果中途匹配的过程中左括号最大值<=0,则返回false,说明左括号数量不够;  注意最小数量始终>=0
// 最后匹配结束检查左括号最小值是否等于0,等于0就说明没有多余的左括号

// 1.遍历字符串, c = '(', 将 leftMin和leftMax都++
// 2.c = ')', leftMin--, leftMax--, 如果leftMax小于0则返回false
// 3.c = '*', 如果'*'匹配'('则leftMax++, 如果'*'匹配')'则leftMin--

bool checkValidString(std::string s)
{
    int leftMax = 0, leftMin = 0;

    for(const char &c : s)
    {
        if(c == '(') {
            leftMin++;
            leftMax++;
        }
        else if(c == ')') {
            leftMax--;
            leftMin--;
            if(leftMax < 0) return false;
            if(leftMin < 0) leftMin == 0;
        }
        else if(c == '*') {
            leftMax++;
            leftMin--;
            if(leftMin < 0) leftMin = 0;
        }
    }

    return leftMin == 0;
}



///////////////////////////////////////
//
//          字符加解密
//          第443题: 压缩字符数组
//          第394题: 解码字符串
//
//          第1163题: 字典序最大的子串
//
////////////////////////////////////////


//Leetcode第443题: 压缩字符数组
//思路:双指针

int compress(std::vector<char> &chars)
{
    if(chars.empty()) return 0;

    int left = 0;

    for(int right = 0; right < chars.size();)
    {
        chars[left] = chars[right];     //这个一定不要忘记了,这是将原有字符覆盖掉
        int count = 0;
        while(right < chars.size() && chars[right] == chars[left]) {
            count++;
            right++;
        }

        if(count != 1) {
            std::string num = std::to_string(count);
            for(const char &c : num) {
                chars[++left] = c;
            }
        }
        left++;
    }

    return left;
}


//压缩字符串:如字符串为 "aabccaaa" 则压缩后结果为 "a2bc2a3"
//双指针来解决

std::string compressString(std::string s)
{
    if(s.empty()) return "";

    std::string res;
    int left = 0;

    for(int right = 0; right < s.size();)
    {
        while(right < s.size() && s[right] == s[left]) right++;

        int count = right - left;
        if(count == 1) res += s[left];
        else res += s[left] + std::to_string(count);

        left = right;
    }

    return res;
}


//Leetcode第394题: 解码字符串

//思路:本质是利用栈,利用string来模拟栈

std::string decodeString(std::string s)
{
    std::string res;

    for(const char &c : s)
    {
        if(isalnum(c) || c == '[') {
            res += c;
        }
        else if(c == ']') {
            std::string tmp;
            while(res.back() != '[') {
                tmp += res.back();
                res.pop_back();
            }
            res.pop_back();     //将res中的'['弹出去
            
            std::string num;
            while(!res.empty() && isdigit(res.back())) {
                num += res.back();
                res.pop_back();
            }

            reverse(tmp.begin(), tmp.end());
            reverse(num.begin(), num.end());

            for(int i = 0; i < std::stoi(num); i++) {
                res += tmp;
            }
        }
    }

    return res;
}


//递归解法
std::string decodeString(std::string s)
{
    int i = 0;
    return dfs(s, i);
}

std::string dfs(const std::string &s, int &i)
{
    std::string res;

    while(i < s.size() && s[i] != ']') 
    {
        if(!isdigit(s[i])) {
            res += s[i++];
        }
        else {
            int n = 0;
            while(i < s.size() && isdigit(s[i])) {
                n = n*10 + (s[i++]-'0');
            }

            i++;    //跳过 '[',否则上面的if语句中的res会包含'['这个字符
            std::string tmp = dfs(s, i);
            i++;    //跳过 ']'

            while(n--) {
                res += tmp;
            }
        }
    }

    return res;
}


//Leetcode第1163题: 字典序最大的子串

// 思路:
// 1. "i"代表第一个字符串的起始坐标
// 2. "j"代表第二个字符串的起始坐标
// 3. "k"代表子串的相关长度

// case 1: s[i+k] == s[j+k], if s.substr(i+k) = s.substr(j+k), 我们继续增长k
// case 2: s[i+k] < s[j+k], 如果第二个字符串更大, 更新 i = max(i+k+1, j)
// case 3: s[i+k] > s[j+k], 如果第二个字符串更小,更改第二个字符串的开始下标为 j+k+1

std::string lastSubstring(std::string s)
{
    int n = s.size();
    int i = 0, j = 1, k = 0;

    while(j + k < n)
    {
        if(s[i+k] == s[j+k]) k++;
        else if(s[i+k] < s[j+k]) {
            i = std::max(i+k+1, j);
            j = i + 1;
            k = 0;
        }
        else j += k+1, k = 0;
    }

    return s.substr(i);
}

