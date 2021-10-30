

//Leetcode第416题:Partition Equal Subset Sum
//判断一个数组能否分割成两个数组和相同的子数组

//思路:动态规划


bool canPartition(std::vector<int> &nums)
{
    if(nums.empty()) return false;

    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum & 1) return false;     //如果和为奇数则直接返回false

    //这里的dp数组中的dp[i][j]表示前i个数字之和是否为j,如果前i个数字之和等于j则为true
    int target = sum/2;
    int n = nums.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(target + 1, 0));
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = nums[i-1]; j <= target; j++) {
            dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
        }
    }

    return dp[n][target];   `
}



//对上面空间复杂度的优化

bool canPartition(std::vector<int> &nums)
{
    if(nums.empty()) return false;

    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum & 1) return false;
    
    int target = sum/2;
    int n = nums.size();
    std::vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++) {           //注意这里的j是从后往前遍历,因为每个数字只能用一次,避免之前的结果影响其他的结果
        for(int j = target; j >= nums[i-1]; j--) {
            dp[j] = dp[j] || dp[j-nums[i-1]];
        }
    }

    return dp[target];
}
