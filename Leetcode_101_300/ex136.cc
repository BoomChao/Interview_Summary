

//Leetcode第136题:Single Number
//给定一个数组,有一个元素出现一次,其余元素都出现两次,找到只出现一次的元素

//思路:参考<剑指>面试题56


#include <iostream>
#include <vector>

int singleNumber(std::vector<int> &nums);

int main(){
    std::vector<int> nums = {2,2,1};

    std::cout << singleNumber(nums) << std::endl;

    return 0;
}

int singleNumber(std::vector<int> &nums)
{   
    if(nums.size() == 1) return nums[0];

    int res = nums[0];

    for(int i = 1; i < nums.size(); i++) {
        res ^= nums[i];
    }

    return res;

}