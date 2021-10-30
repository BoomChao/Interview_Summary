//Leetcode第41题
//First Misiing Positive:给出一个未排序的数组,请你找出未出现在数组中的最小的正整数

//思路:将数组由低到高排列,遍历数组,如果数组的第一个数不等于下标加1,即nums[i]!=i+1; 直接返回i+1即可;否则返回数组长度加1
//所有解法二就是这种思想,但是题目要求时间复杂度要在O(n),而解法二的使用了sort函数,该函数内部的实现是快排,时间复杂度为 O(nlogn) > O(n)
//所以采用解法一,不适用sort函数,使用swap函数来交换对应的元素到相应位置

//解法三是另外构造一个辅助数组

#include <iostream>
#include <vector>
#include <algorithm>

int firstMissingPositive_1(std::vector<int> &nums);
int firstMissingPositive_2(std::vector<int> &nums);


int main(){
    // std::vector<int> nums = {3,4,-1,1};
    std::vector<int> nums = {1,2,0};
    std::cout << firstMissingPositive_1(nums) << std::endl;
    
    // for(int i = 0; i < nums.size(); i++){
    //     std::cout << nums[i] << " ";
    // }
    // std::cout << std::endl;

    return 0;
}


int firstMissingPositive_1(std::vector<int> &nums)
{
    int n = nums.size();
    for(int i = 0; i < n; i++){
        while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1]!=nums[i]){
            std::swap(nums[i], nums[nums[i]-1]);
        }
    }

    for(int i = 0; i < n; i++){
        if(nums[i] != i+1) return i+1;
    }

    return n+1;

}


int firstMissingPositive_2(std::vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i++){
        if(nums[i] <= 0) continue;
        if(nums[i] != i+1) return i+1;
    }

    return n+1;

}



int firstMissingPositive_3(std::vector<int> &nums)
{
    int j = 1;
    std::vector<int> tmp(nums.size(), 0);
    for(int i = 0; i < nums.size(); i++){
        tmp[i] = j++;
    }

    for(int i = 0; i < nums.size(); i++){
        if(find(nums.begin(),nums.end(),tmp[i]) != nums.end()) continue;    //注意find函数的用法
        else return tmp[i];
    }

    return nums.size()+1;

}