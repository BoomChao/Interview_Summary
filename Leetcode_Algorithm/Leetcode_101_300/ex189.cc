


//Leetcode第189题:Rotate Array
//翻转数组

#include <iostream>
#include <algorithm>
#include <vector>

void rotate(std::vector<int> &nums, int k);

int main(){
    std::vector<int> nums = {1,5,3,6,7};

    //reverse函数是将数组逆序,就是单纯的逆序,并不是倒序排列
    reverse(nums.begin(), nums.end());

    for(int num:nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}


void rotate(std::vector<int> &nums, int k)
{
    k = k % nums.size();
    
    //将整个数组翻转,之后将前k个数翻转,再将后面的数翻转
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());

}
