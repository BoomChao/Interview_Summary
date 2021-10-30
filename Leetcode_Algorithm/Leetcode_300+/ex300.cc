


//Leetcode第300题 : Longest Increasing Subsequence
//寻找最长的递增子序列


//解法一:动态规划
//时间复杂度为O(n^2)

int lengthOfLIS(std::vector<int> &nums)
{
    if(nums.size() <= 1) return nums.size();

    int maxLen = 0;
    std::vector<int> dp(nums.size(), 1);
    for(int i = 0; i < nums.size(); i++) 
    {
        for(int j = 0; j < i; j++) 
        {
            if(nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        maxLen = std::max(maxLen, dp[i]);
    }

    return maxLen;
}



// 解法二:动态规划+二分查找(这种方法思路非常好)
// 时间复杂度为O(nlogn)

int lengthOfLIS(std::vector<int> &nums)
{
    int n = nums.size();
    if(n <= 1) return n;

    std::vector<int> dp;
    dp.push_back(nums[0]);
    for(int i = 1; i < n; i++)
    {
        // 如果当前所指的数比dp数组末尾数字大则将其添加到数组中
        if(dp.back() < nums[i]) {
            dp.push_back(nums[i]);
        }
        else {  //如果当前数字比dp末尾数字小则替换dp数组中的一个数字,使得dp数字连续的数字尽可能的小
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            *it = nums[i];
        }
    }

    return dp.size();
}