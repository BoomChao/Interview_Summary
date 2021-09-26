
//Leetcode第377题:Combination Sum IV
//判断数组中的元素组成目标target一共有几种可能


//方法一:递归(会超时)

int combinationSum4(std::vector<int> &nums, int target)
{
    if(target == 0) {
        return 1;
    }

    int res = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(target >= nums[i]) {
            res += combinationSum4(nums, target-nums[i]);
        }
    }   

    return res;
}



//上述会有大量的重复运算,所以这里每计算完一次就存储一次计算结果

int combinationSum4(std::vector<int> &nums, int target)
{
    if(nums.empty()) return 0;

    std::vector<int> dp(target+1, -1);
    dp[0] = 1;

    return dfs(nums, target, dp);

}

int dfs(std::vector<int> &nums, int target, std::vector<int> &dp)
{
    if(dp[target] != -1) {
        return dp[target];
    }

    int res = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(target >= nums[i]) {
            res += dfs(nums, target-nums[i], dp);
        }
    }

    dp[target] = res;

    return res;
}