

//Leetcode第198题:House Robber
//拿到最多的金币,但是相邻的金币不能同时拿

//思路:动态规划
// dp[0] = nums[0], dp[1] = max(nums[0], nums[1])
// dp[i] = max(dp[i-1], dp[i-2] + nums[i])
//求得数组dp中的最大值即可


int rob(std::vector<int> &nums)
{
    if(num.empty()) return 0;
    if(nums.size() == 1) return nums[0];

    std::vector<int> dp(nums.size());
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);

    int res = dp[1];

    for(int i = 2; i < nums.size(); i++)
    {
        dp[i] = std::max(dp[i-1], dp[i-2] + nums[i]);
        res = std::max(res, dp[i]);
    }

    return res;
}


//优化
int rob(std::vector<int> &nums)
{
    if(nums.empty()) return 0;
    if(nums.size() == 1) return nums[0];

    int first = nums[0], second = std::max(nums[0], nums[1]);
    int cur = second;

    for(int i = 2; i < nums.size(); i++) {
        cur = std::max(first + nums[i], second);
        first = second;
        second = cur;
    }

    return cur;
}


