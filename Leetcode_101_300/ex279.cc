

//Leetcode第279题:Perfect Squares
//判断一个数最小可以由几个完全平方数组成

//思路:动态规划

int numSquare(int n)
{
    std::vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j*j <= i; j++) 
        {
            dp[i] = std::min(dp[i], dp[i-j*j] + 1);
        }
    }

    return dp[n];
}
