


//Leetcode第153题:旋转数组中的最小数字
//参考<剑指>面试题11

#include <iostream>
#include <vector>

int findMin(std::vector<int> &nums);


int main(){
    std::vector<int> nums = {4,5,6,7,0,1,2};
    std::cout << findMin(nums) << std::endl;

    return 0;
}

int findMin(std::vector<int> &nums)
{
    if(nums.size() == 1) return nums[0];

    int index1 = 0, index2 = nums.size()-1;
    int indexMid = index1;

    while(nums[index1] > nums[index2])
    {
        if(index2-index1 == 1) {
            indexMid = index2;
            break;
        }

        indexMid = (index1 + index2) / 2;
        if(nums[indexMid] > nums[index1]) {
            index1 = indexMid;
        }
        else if(nums[indexMid] < nums[index2]) {
            index2 = indexMid;
        }

    }    

    return nums[indexMid];
}