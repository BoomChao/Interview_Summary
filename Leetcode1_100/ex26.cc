//Leetcode第26题
//Remove Duplicates from Sorted Array : 给出一个已经排好序的数组,去除掉其中重复的元素



#include <iostream>
#include <vector>
#include <algorithm>    //使用unique函数需要包含这个头文件

int removeDuplicate(std::vector<int> &nums);

int main(){
    
    std::vector<int> res = {0,0,1,1,1,2,2,3,3,3};
    std::cout << removeDuplicate(res) << std::endl;

    return 0;
}


//解法一:利用库函数
int removeDuplicate(std::vector<int> &nums)
{
    nums.erase( unique(nums.begin(), nums.end()), nums.end() ); //利用unique函数和erase函数来实现,很简洁 

    return nums.size();

}



//解法二(双指针)
int removeDuplicate(std::vector<int> &nums)
{
    int i = 0, k = 0;
    while(i < nums.size())
    {
        while(i < nums.size()-1 && nums[i] == nums[i+1]) i++;

        nums[k++] = nums[i++];
    }

    return k;
}



//解法三:
int removeDuplicate(std::vector<int> &nums)
{
    int i = 0;
    for(int n:nums){
        if(i < 1 || n > nums[i-1]) nums[i++] = n;
    }

    return i;

}