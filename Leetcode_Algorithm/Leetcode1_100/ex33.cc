

//Leetcode第33题 : Search in Rotated Sorted Array
//在一个已经排好顺序然后翻转的数组中查找指定元素,如
//如顺序数组为 {0,1,2,4,5,6}; 假设随意翻转后为 {5,6,0,1,2,4} 给定一个目标target,找出其在翻转后的数组中的索引,没有返回-1


//思路如下:看代码注释
//其改进版是81题

#include <iostream>
#include <vector>

int search(std::vector<int>& nums, int target);

int main(){
    std::vector<int> nums = {5,0,1,2,3,4};   int target = 2;
    std::cout << search(nums,target) << std::endl;

    return 0;
}


int search(std::vector<int> &nums, int target)
{
    if(nums.size() == 0) return -1;

    int left = 0;
    int right = nums.size()-1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(nums[mid] == target) {    //如果中点位置元素等于目标,则直接返回中点下标
            return mid;
        }
        else if(nums[mid] < nums[right]) {     //中点位置元素小于最右边元素,说明右半部分是有序的
            if(nums[mid] < target && target <= nums[right]) {    //判断目标是否位于右半部分
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        else {    //这种情况是左半部分是有序的
            if(nums[left] <= target && target < nums[mid]) {     //判断目标是否位于左半部分
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }

    return -1;
}