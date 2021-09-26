

//Leetcode第560题:Subarray Sum Equals K
//找到数组和等于k的连续子数组,返回这些符合要求的连续子数组的个数

//思路:前缀和+哈希

int subarraySum(std::vector<int> &nums, int k)
{
    std::unordered_map<int, int> mp;
    mp[0] = 1;                          //前缀为0需要预先存储

    int count = 0;
    int preSum = 0;
    for(int x:nums) 
    {
        preSum += x;
        if(mp.find(preSum-k) != mp.end()) {
            count += mp[preSum-k];
        }

        mp[preSum]++;
    }

    return count;

}