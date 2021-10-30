

//Lettcode137题:Single Number II 
//给定一个数组,只有一个元素出现了一次,其余均元素出现了三次,找到这个只出现一次的元素

//思路:参考<剑指>面试题56


#include <iostream>
#include <vector>

int singleNumber(std::vector<int>& nums);

int main(){
    std::vector<int> nums = {2,2,3,2};

    std::cout << singleNumber(nums) << std::endl;

    return 0;
}

int singleNumber(std::vector<int>& nums)
{
    int bitSum[32] = {0};

    for(int i = 0; i < nums.size(); i++)
    {
        int bitMask = 1;
        for(int j = 31; j >= 0; j--)
        {
            int bit = nums[i] & bitMask;
            if(bit != 0) {
                bitSum[j] += 1;
            }

            nums[i] = nums[i] >> 1;

        }

    }

    int result = 0;
    for(int i = 0; i < 32; i++)
    {
        result = result << 1;
        result += bitSum[i] % 3;
    }

    return result;

}