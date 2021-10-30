

//Leetcode第80题(第26题的升级版)
//Remove Duplicates from Sorted Array II : 删除顺序数组中重复的元素(相同元素只允许出现2次),返回的是删除后数组的长度


//思路:
//遍历原数组,如果当前下标小于2或者当前的值大于nums[i-2]则将当前值置于数组中,下标加1

//注意:该题的要求是不能申请额外内存,必须在原数组上操作


#include <iostream>
#include <vector>

int removeDuplicate(std::vector<int> &nums);

int main(){
    std::vector<int> nums = {1,1,1,2,2,3};
    int res = removeDuplicate(nums);

    for(int i = 0; i < res; i++) std::cout << nums[i] << " ";
    std::cout << std::endl;

    return 0;
}


//这种解法思路同样适用于26题

int removeDuplicate(std::vector<int> &nums)
{
    int i = 0;
    for(auto n:nums){
        if(i < 2 || n > nums[i-2]) nums[i++] = n;
    }
    
    return i;

}