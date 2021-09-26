


//Leetcode第309题 : 股票买卖V

//思路:画出状态转移图即可

int maxProfit(std::vector<int> &prices)
{
    if(prices.empty()) return 0;

    int n = prices.size();
    std::vector<int> buy(n), sell(n), s1(n), s2(n);
    s1[0] = buy[0] = -prices[0];
    sell[0] = s2[0] = 0;

    for(int i = 1; i < n; i++)
    {
        buy[i] = s2[i-1] - prices[i];
        s1[i] = std::max(s1[i-1], buy[i-1]);
        sell[i] = std::max(buy[i-1], s1[i-1]) + prices[i];
        s2[i] = std::max(s2[i-1], sell[i-1]);
    }

    return std::max(sell[n-1], s2[n-1]);
}
