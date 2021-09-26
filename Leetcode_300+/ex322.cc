

//Leetcode第322题 : Coins Change
//凑够足够数量的钱一共需要多少个硬币

//思路:动态规划
//dp[] 数组下标表示金额,数组值表示所需的最少金额数
//则对coin = coins[i]的处理分两种情况
//(1).选中coins[i],则剩余的钱就是 amount-coins[i], 这种操作所需的硬币数量为coins[amount-coins[i]] + 1
//(2).不选中coins[i], 则剩余的钱不变，所需的硬币数量还是dp[coin]
//dp[i] = max(上述两种情况的最小值)


int coinChange(std::vector<int> &coins, int amount)
{
    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    
    for(int &coin : coins)
    {
        for(int i = coin; i <= amount; i++) {
            dp[i] = std::min(dp[i], dp[i-coin] + 1);
        }
    }
    
    //dp[amount]的初始值就是amount+1，这就大于amount，所以如果到这里还大于amount,说明
    //dp[amount]的数值在上面没有做任何改变，则不存在能组成amount方法，于是返回-1
    return dp[amount] > amount ? -1 : dp[amount];
}



