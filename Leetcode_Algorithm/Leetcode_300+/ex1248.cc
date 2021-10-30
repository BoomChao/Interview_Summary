

//Leetcode第1248题:Count Number of Nice Subarrays
//统计"优美子数组"的数量

//思路:前缀和+哈希

int numberOfSubarrays(std::vector<int> &nums, int k)
{
    std::vector<int> mp(nums.size()+1);
    mp[0] = 1;
    int oddNum = 0;
    int count = 0;

    for(int i = 0; i < nums.size(); i++) 
    {
        oddNum += nums[i] & 1;
        if(oddNum - k >= 0) {
            count += mp[oddNum-k];
        }

        mp[oddNum]++;
    }

    return count;
}
