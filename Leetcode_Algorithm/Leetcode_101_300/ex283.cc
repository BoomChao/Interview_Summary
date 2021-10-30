

//Leetcode第283题:Move Zeroes
//将数组中元素为0全部移动到数组末尾,其他元素顺序保持不动

//思路:两个指针替换

#include <iostream>
#include <vector>

void moveZeros(std::vector<int> &nums);

int main(){
    std::vector<int> nums = {0,1,0,3,12};

    moveZeros(nums);

    for(auto num:nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}


void moveZeros(std::vector<int> &nums)
{
    if(nums.empty()) return;

    int j = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }

    for(; j < nums.size(); j++) {
        nums[j] = 0;
    }

}
