
// 动态规划系列

// Cutting rod to maximize profit

// dp[i][j]
// if cut[i] > j  dp[i][j] = dp[i-1][j]
// if cut[i] <= j dp[i][j] = max(dp[i-1][j], dp[i][j-cut[i]] + prices[i])

std::vector<int> res;

int maxProfit(std::vector<int> cut, std::vector<int> prices, int len)
{
    int n = cut.size();

    std::vector<std::vector<int>> dp(n, std::vector<int>(len + 1, 0));

    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= len; j++) {
            if(j < cut[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = std::max(dp[i-1][j], dp[i][j-cut[i]] + prices[i]);
        }
    }

    int i = n-1, j = len;
    
    while(dp[i][j] > 0)
    {
        if(i > 0 && dp[i][j] == dp[i-1][j]) i--;
        else {
            res.push_back(cut[i]);
            j -= cut[i];            //注意这里是 j-= cut[i]
        }
    }

    reverse(res.begin(), res.end());        //将结果逆序

    return dp[n-1][len];

    /* 降维
    std::vector<int> dp(len + 1, 0);
    
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= len; j++) {
            if(j >= cut[i]) dp[j] = std::max(dp[j], dp[j-cut[i]] + prices[i]);
        }
    }

    return dp[len];
    */
}