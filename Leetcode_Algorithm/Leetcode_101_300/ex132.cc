

//Leetcode第132题 : Palindrome Partitioning II
//计算将字符串切分成回文串的最小次数

//思路:动态规划

//这题还有更好的做法

int minCut(std::string s)
{
    if(s.size() <= 1) return 0;

    int len = s.size();

    //每次判断[j:i]是否为回文串会有很多次重复
    //直接用一个二维数组来标记之前遍历过的[j:i]是否为回文串
    std::vector<std::vector<bool>> area(len, std::vector<bool>(len, false));    //辅助矩阵判断回文串

    //dp[i]表示0-i个字符用dp[i]次分割可构成回文串
    //将所有元素初始化为长度减去1,比如为3个字符,则最多切割两次就可为回文串
    std::vector<int> dp(len, len-1);    

    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            //若s[j:i]首尾相等,并且中间部分也为回文串或者s[j:i]的长度小于等于2(即中间部分为空)
            //则s[j:i]为回文串,将其在area数组中标记为true
            if(s[j] == s[i] && (i-j <= 2 || area[j+1][i-1])) {
                area[j][i] = true;
                dp[i] = (j == 0) ? 0 : std::min(dp[i], dp[j-1]+1);  //j=0表示0-i个字符是回文串,此时分割次数为0
            }
        }

    }

    return dp[len-1];

}
