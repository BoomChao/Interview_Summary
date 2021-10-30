

/*
*
*   滑动窗口题型汇总 

    滑动窗口右边界统一使用for循环的形式移动,左边界left在循环中使用while来移动

*   第3题  : 最长不重复子串
*   第205题: 判断字符串是否同构
*   第209题: 长度最小的子数组(数组中元素全部为正数)     第862题(数组中元素存在负数)
*   第76题 : 最小覆盖子串

*   第239题: 滑动窗口中的最大值
*   第395题: 包含至少k个重复字符的最长子串
*   第340题: 至多包含k个不同字符的最长子串
*/

//Leetcode第3题:最长不重复子串

// 思路:滑动窗口
// 1.定义窗口左边界为-1,将元素下标全部存储到一个数组中,边遍历边更新
// 2.发现元素下标大于窗口左边界时发现重复元素,更新窗口左边界

int lengthOfLongestSubString(std::string s)
{
    int res = 0;
    int start = -1;
    std::vector<int> mp(128, -1);   //存储s中各元素出现的下标

    for(int i = 0; i < s.size(); i++) 
    {
        if(mp[s[i]] > start) {
            start = mp[s[i]];   //如果该元素的下标大于窗口左侧的值,则向右扩大窗口
        }
        mp[s[i]] = i;
        res = std::max(res, i - start);
    }

    return res;
}


//Leetcode第205题 : 判断字符串是否同构 (与上一题非常相似)

bool isIsomorphic(std::string s, std::string t)
{
    //记录字符出现的位置
    std::vector<int> mps(128, -1), mpt(128, -1);

    for(int i = 0; i < s.size(); i++)
    {
        if(mps[s[i]] != mpt[t[i]]) return false;
        mps[s[i]] = mpt[t[i]] = i;
    }

    return true;
}




//Leetcode第209:长度最小的子数组

int minSubArrayLen(int target, std::vector<int> &nums)
{
    int sum = 0;
    int left = 0;
    int minLen = INT_MAX;

    for(int right = 0; right < nums.size(); right++)
    {
        sum += nums[righ];

        while(sum >= target) {
            minLen = std::min(minLen, right - left + 1);
            sum -= nums[left++];
        }
    }

    return minLen == INT_MAX ? 0 : minLen;
}


//Leetcode第862题: 上一题的进阶版(数组中可能存在负数)

// 现在存在负数就不能使用上面209题的解法了
// 比如数组 {5,-3,1,2,6}  k=9, 如果用上面的解法会得到最短长度为5,而实际最短长度为3

//解法一:使用优先队列
//将数组的和及其下标全部放入优先队列
//时间复杂度O(nlogn)
//空间复杂度O(n)

int shortestSubarray(std::vector<int> &nums, int k)
{
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;

    pq.push({0, -1});

    int res = INT_MAX, sum = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        while(!pq.empty() && sum - pq.top().first >= k) {
            res = std::min(res, i - pq.top().second);
            pq.pop();
        }

        pq.push({sum, i});
    }

    return res == INT_MAX ? -1 : res;
}


//解法二:利用双端队列(思路非常好)
//时间复杂度O(n)
//空间复杂度O(n)

int shortestSubarray(std::vector<int> &nums, int k)
{
    int n = nums.size(), res = n + 1;
    std::deque<int> dq;

    for(int i = 0; i < n; i++) 
    {
        if(i > 0) nums[i] += nums[i-1];
        
        if(nums[i] >= k) res = std::min(res, i + 1);

        while(!dq.empty() && nums[i] - nums[dq.front()] >= k) {
            res = std::min(res, i - dq.front());
            dq.pop_front();
        } 

        while(!dq.empty() && nums[i] <= nums[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    return res == n+1 ? -1 : res;
}




//Leetcode第76题:最小覆盖子串

std::string minWindow(std::string s, std::string t)
{
    //统计t中每个字符出现的次数
    std::vector<int> map(128, 0);
    for(const char &c : t) {
        map[c]++;
    }

    //count用来记录窗口中字符与t中字符相同的个数
    int count = 0;
    int left = 0;
    std::vector<int> window(128, 0);

    int startIndex = 0, minLen = INT_MAX;

    for(int right = 0; right < s.size(); right++)
    {
        if(++window[s[right]] <= map[s[right]]) {
            count++;
        }

        //窗口中的字符包含了t的所有字符
        while(count == t.size()) 
        {
            if(right - left + 1 < minLen) {  
                startIndex = left;
                minLen = right - left + 1;
            }

            //移动左窗口(判断移动的这个字符是不是原来属于t中)
            if(--window[s[left]] < map[s[left]]) count--;   //注意:left千万不能写到前面的 --window[s[left++]] 里面, 否则比较的就是 s[left] 和 s[left+1]

            //也可以将left单独提取出来,if语句不做任何自增操作
            left++
        }
    }

    return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
}






// Leetcode第438题 : 找到字符串中的所有字母异位词
// 思路:先记录目标字符串每个单词出现的频率,之后滑动窗口将窗口中的字符与目标字符串出现频率比较

std::vector<int> findAnagrams(std::string s, std::string p)
{
    //记录p中每个元素出现的频率
    std::vector<int> mp(26. 0);
    for(const char &c : p) {
        mp[c-'a']++;
    }

    //存储结果
    std::vector<int> res;

    std::vector<int> window(26, 0);
    
    for(int i = 0; i < s.size(); i++) 
    {
        window[s[i]-'a']++;

        //保持窗口中的字符个数与字符串p的字符个数相同
        if(i >= p.size()) window[s[i-p.size()]-'a']--;

        if(window == mp) res.push_back(i - (p.size()-1));       //窗口和字符串p中元素出现频率相同则将起窗口起始字符串下标加入结果
    }

    return res;
}




//Leetcode第239题: 滑动窗口内的最大值

// 1.使用双端队列来模拟一个滑动窗口(递减队列)
//   队列的首部始终是窗口内的最大值
// 2.每次遍历将当前元素与队列元素比较,如果大于则将队列元素弹出,小于则直接加入队列
// 3.细节:每次加入元素要检查队头元素是否还应该在窗口中


std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
{
    std::deque<int> dq;
    std::vector<int> ans;

    for(int i = 0; i < nums.size(); i++)
    {
        //入队检查:判断当前元素是否大于队列中元素,如果大于就将队列中元素出队列
        while(!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        //入队列(这时经过上两步就能保证这时的队列队首元素就是窗口内的最大值)
        //先判断队首元素是否还应该在队列中
        if(!dq.empty() && dp.front() == i-k) {      //注意:这个pq.empty()一定要加,否则如果为空,则dp.front()会报错
            dp.pop_front();
        }
        dq.push_back(i);

        if(i >= k-1) ans.push_back(nums[dq.front()]);
    }

    return ans;
}



//Leetcode第395题 : 至少包含k个字符的最长子串
//统计每个字符出现的次数,出现次数小于k的肯定不是目的子串,以该字符左右分割字符串依次递归判断

//递归解法(很好理解)
//时间复杂度O(n^2),每递归一次就要复制一次字符串

int longestSubstring(std::string s, int k)
{
    if(s.empty() || s.size() < k) return 0;

    std::vector<int> count(26, 0);
    for(const char &c : s) {
        count[c-'a']++;
    }

    //找到第一个出现次数小于k的字符,以此字符为中心分割字符串
    int mid = 0;
    while(mid < s.size() && count[s[mid]-'a'] >= k) mid++;
    if(mid == s.size()) return s.size();                //所有字符出现字符都>=k,返回整个字符串长度

    int left = longestSubstring(s.substr(0, mid), k);

    while(mid < s.size() && count[s[mid]-'a'] < k) mid++;    //跳过中间不满足条件的字符
    if(mid == s.size()) return left;
    
    int right = longestSubstring(s.substr(mid), k);    

    return std::max(left, right);
}

//采用滑动窗口:此题很巧妙,仔细体会
//时间复杂度O(n)

int longestSubstring(std::string s, int k)
{
    if(s.empty() || s.size() < k) return 0;

    int maxLen = 0;

    //让每次窗口中的唯一字符出现n个,n由1增加到26逐个判断最长长度 (这样时间复杂度控制为O(26*n),近似与O(n))
    for(int n = 1; n <= 26; n++)
    {
        std::vector<int> count(26, 0);
        int left = 0, uniqueChar = 0;

        for(int right = 0; right < s.size(); right++)
        {
            if(count[s[right]-'a']++ == 0) uniqueChar++;

            //出现的唯一字符大于n个,则向右移动左窗口
            while(uniqueChar > n) {
                if(count[s[left++]-'a']-- == 1) uniqueChar--;
            }

            //经过上一步骤窗口中的不同字符个数肯定 <= n, 我们只需关心不同字符个数等于n的情况
            if(uniqueChar == n) {
                bool valid = true;
                // 判断这n个不同字符是否每个的出现次数都 >= k
                // 如果count[i]为0就代表该字符未出现过, 如果count[i] > 0 并且 count[i] < k,说明出现次数不满足 >=k 条件
                for(int j = 0; j < 26; j++) {
                    if(count[j] > 0 && count[j] < k) valid = false;
                }
                if(valid) maxLen = std::max(maxLen, right - left + 1);
            }
        }
    }

    return maxLen;
}




//Leetcode第340题: 至多包含k个不同字符的最长子串
//思路：哈希＋滑动窗口

int lengthOfLongestSubStringKDistinct(std::string s, int K)
{
    std::unordered_map<char,int> mp;    //记录窗口里面的字符种类数
    int res = 0;
    int left = 0;

    for(int right = 0; right < s.size(); right++)
    {
        if(mp.size() <= k) mp[s[right]]++;

        while(mp.size() > k) {
            if(--mp[s[left]] == 0) {
                mp.erase(s[left]);
                left++;
            }
        }

        res = std::max(res, right - left + 1);
    }

    return res;
}



//切记：如果利用map[key]=０来判断一个元素是否存在；即使这个元素不存在也会默认加入到map中
//所以map中元素是否存在可以用count函数或者find函数,不要使用映射值来判断

int main()
{
    std::unordered_map<int,int> hash;

    if(hash[4]) {

    }

    std::cout << hash.size() << std::endl;  //这时输出的哈希表中元素个数为1个,而不是空
}





///////////////////////////////////
//
//     双指针题型汇总
//     第283题 : 将0移动到数组末尾,保持原来的非零元素相对顺序不变
//     第392题 : 判断一个字符串是否为另外一个字符串的子序列
//     第905题 : 将偶数移动到数组前半部分,奇数移动到后半部分(剑指面试题21)
//
//     第485题 : Max Consecutive Ones  (最长1序列)
//     第487题 : Max Consecutive Ones II (最多翻转1次)
//    第1004题 : Max Consecutive Ones III (可以进行k次翻转操作，求得到的最长1序列的个数)
//
//      第30题 : 串联所有单词的子串
//
///////////////////////////////////


//Leetcode第283题: 将元素0移动到数组的末尾,并且保持非零元素的相对顺序不变

void moveZeros(std::vector<int> &nums)
{
    for(int i = 0, j = 0; j < nums.size(); j++) {
        if(nums[j]) {
            std::swap(nums[i++], nums[j]);
        }
    }
}


// Leetcdeo第392题:判断一个字符串是否为另外一个字符串的子序列

bool isSubsequence(std::string s, std::string t)
{
    int i = 0, j = 0;
    while(i < s.size() && j < t.size())
    {
        if(s[i] == t[j]) i++;
        j++;
    }

    return i == s.size();
}


// 更加简洁
bool isSubsequence(std::string s, std::string t)
{
    //如果s的长度比t的长度长,则s不可能是t的子序列
    if(s.size() > t.size()) return false;

    int i = 0;

    for(int j = 0; j < t.size(); j++) {
        if(s[i] == t[j]) i++;
    }

    return i == s.size();
}


//Leetcode第905题: Sort Array By Parity

//如果不需要维持移动后奇数和偶数的相对顺序,则使用双指针
//时间复杂度O(n),空间复杂度O(1)
//解法一:
std::vector<int> sortArrayByParity(std::vector<int> &A)
{
    for(int i = 0, j = 0; j < A.size(); j++) {
        if((A[j]&1) == 0) {
            std::swap(A[i++], A[j]);
        }
    }

    return A;
}

//解法二:这种解法只需要交换后面的偶数,而上面的解法前面的偶数也需要交换
std::vector<int> sortArrayByParity(std::vector<int> &A)
{
    int i = 0, j = A.size() - 1;
    while(i < j)
    {
        while(i < j && (A[i]&1) == 0) i++;  //找到后面的奇数
        while(i < j && (A[j]&1) == 1) j--;  //找到前面的偶数

        if(i < j) {
            std::swap(A[i], A[j]);
        } 
    }

    return A;
}


//如果需要维持移动后奇数和偶数的相对顺序,则也可以使用双指针或者冒泡排序

//牛客<剑指>面试题JZ13
//解法二:遇到(偶数,奇数)这种组合就将其交换位置,判断交换位置后之前的元素需不需要再交换
//双指针 + 冒泡排序
//时间复杂度O(n),空间复杂度O(1)

std::vector<int> sortArrayByParity(std::vector<int> &array)
{
    int n = array.size();
    for(int i = 0; i < n-1; i++)
    {
        //只要当前数为偶数,下一个数为奇数就将其交换,交换完毕接着往前移判断是否还需要进行交换
        while(i >= 0 && (array[i]&1) == 0 && (array[i+1]&1) == 1) {     //这里额外定义一个变量j用来冒泡结果也一样,不一定非要使用下标i
            std::swap(array[i], array[i+1]);
            i--;
        }
    }

    return array;
}


//Leetcode第485题：连续1的个数

//方法一：使用双指针(左指针移动到1后,移动右指针)

int findMaxConsectiveOnes(std::vector<int> &nums)
{
    int left = 0, res = 0;

    for(int right = 0; right < nums.size(); right++)
    {
        if(nums[right] == 1) {
            int left = right;
            while(right < nums.size() && nums[right] == 1) right++;
            res = std::max(res, right - left);
        }
    }

    return res;
}

//方法二：使用一个变量记录1的个数即可

int findMaxConsectiveOnes(std::vector<int> &nums)
{
    int count = 0, res = 0;

    for(const int &n : nums) {
        if(n == 1) res = std::max(res, ++count);
        else count = 0;
    }

    return maxLen;
}


//Leetcode第487题：只允许翻转一个0

//方法一：
//将第1004题中的 k=1, 即为该题的解

//方法二：类似于动态规划
//1.定义两个变量left, right, left表示遇到了0，并且翻转了该0，包含该0及其左侧的连续的1的长度
//2.right表示上次遇到0之后的连续的1的长度

int findMaxConsectiveOnes(std::vector<int> &nums)
{
    int left = 0, right = 0;
    int maxLen = 0;
    
    for(const int &n : nums)
    {
        if(n == 1) right++;
        else {
            left = right + 1;
            right = 0;
        }
        res = std::max(res, left + right);
    }

    return maxLen;
}




//Leetcode第1004题：可以进行k次翻转得到的最长1序列的个数

//保持窗口内的0的个数始终 <= k
// 1.right指针往后移动,移动过程中统计窗口内的0的个数
// 2.当窗口内的0的个数>k时移动left指针，直到窗口内的0的个数<=k
// 3.right指针移动的过程中记录下长度即可

int longestOnes(std::vector<int> &nums, int k)
{
    int count = 0, maxLen = 0;
    int left = 0;

    for(int right = 0; right < nums.size(); right++)
    {
        if(nums[right] == 0) count++;

        while(count > k) {
            if(nums[left] == 0) count--;
            left++;
        }

        maxLen = std::max(maxLen, right - left + 1);
    }

    return maxLen;
}


//Leetcode第30题: 串联所有单词的子串
//双指针

std::vector<int> findSubstring(std::string s, std::vector<std::string> &words)
{
    std::vector<int> res;

    if(s.empty() || words.empty()) return res;

    std::unordered_map<std::string, int> mp;
    for(auto &word : words) mp[word]++;         //现将单词全部存入hash表中

    int n = s.size(), num = words.size(), length = words[0].size();

    for(int i = 0; i <= n - num*length; i++)
    {
        std::unordered_map<std::string, int> seen;
        int count = 0;
        while(count < num)      //判断遍历的单词个数是否与words中的单词个数相同
        {
            std::string word = s.substr(i + count*length, length);
            seen[word]++;
            if(!mp.count(word) || seen[word] > mp[word]) break;
            count++;
        }

        if(count == num) res.push_back(i);
    }

    return res;
}