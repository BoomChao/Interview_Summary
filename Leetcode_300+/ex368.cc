

//Leetcode第368题:Largest Divisible Subset
//最大的整除子集合

//思路:动态规划

std::vector<int> largestDivisibleSubset(std::vector<int> &nums)
{
    std::vector<int> res;
    if(nums.empty()) return res;

    std::vector<int> dp(nums.size(), 0);
    std::vector<int> preIndex(nums.size());     //当前元素的前一个元素的下标

    int maxSize = 0;    //子数组的最大元素个数
    int maxIndex = 0;   //存储子数组的最大的元素下标

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++) 
    {
        for(int j = i; j >= 0; j--) 
        {
            if(nums[i] % nums[j] == 0 && dp[i] < dp[j]+1) {
                dp[i] = dp[j] + 1;
                preIndex[i] = j;
                if(maxSize < dp[i]) {
                    maxSize = dp[i];
                    maxIndex = i;
                }
            }
        }
    }

    for(int i = 0; i < maxSize; i++)
    {
        res.push_back(nums[maxIndex]);
        maxIndex = preIndex[maxIndex];
    }

    return res;
}
