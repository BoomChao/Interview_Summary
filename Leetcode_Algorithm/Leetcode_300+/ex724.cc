

//Leetcode第724题:Find Pivot Index
//寻找数组的中心索引

//思路:利用前缀和的思想

int pivotIndex(std::vector<int> &nums)
{
    int preSum = 0;
    for(int x:nums) {
        preSum += x;
    }

    int leftSum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(leftSum ==  preSum - nums[i] - leftSum) {
            return i;
        }

        leftSum += nums[i];
    }

    return -1;

}