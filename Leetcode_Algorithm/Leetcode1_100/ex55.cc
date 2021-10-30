//Leetcode第55题:
//Jump Game : (第45题的缩减版) 数组元素下标代表数组元素当前位置跳跃的最大距离,判断其能否跳动数组末尾



#include <iostream>
#include <vector>

int canJump_1(std::vector<int> &nums);
int canJump_2(std::vector<int> &nums);


int main(){
    std::vector<int> nums = {1,0,1,0};

    std::cout << canJump(nums) << std::endl; 


    return 0;
}


//思路一:
//判断当前位置的所跳的最远距离是否至少能达到下一位置,如果当前位置跳跃的最大位置都不能跳出当前位置,也即不能跳到下一个相邻位置,直接返回false
//否则继续遍历数组,继续判断;当跳出循环后直接返回true结束整个函数

bool canJump_1(std::vector<int> &nums){
    int maxPosition = 0;

    for(int i = 0; i < nums.size(); i++){
        if(maxPosition < i)  return false;

        int maxPosition = std::max(i+nums[i], maxPosition);

    }

    return true;

}



//思路二:
//只需判断0之前的元素能否跳过0即可,不能跳过返回false

bool canJump_2(std::vector<int> &nums)
{
    int maxPosition = 0;
    for(int i = 0; i < nums.size()-1; i++){
        if(nums[i] == 0 && maxPosition <= i) return false;

        maxPosition = std::max(maxPosition, nums[i]+i);
    }

    return true;

}