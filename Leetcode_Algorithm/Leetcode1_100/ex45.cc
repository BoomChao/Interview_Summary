//Leetcode第45题:
//Jump Game II : 给出一个数组,每个元素代表可以跳跃的最大步数,求到达数组最后一个元素需要跳跃几次


//思路:贪婪算法
//找到当前位置能跳到最远的位置(称之为边界),i指针依次往前移动,如果碰到了边界,将步数+1,并更新新的边界
//依次循环,直到i指针到达倒数第二个位置

#include <iostream>
#include <vector>

int jump(std::vector<int> &nums);

int main(){
    std::vector<int> nums = {2,3,1,1,4};

    std::cout << jump(nums) << std::endl; 


    return 0;
}

int jump(std::vector<int> &nums)
{
    if(nums.size() < 2) return 0;

    int end = 0;
    int maxPosition = 0;
    int steps = 0;

    for(int i = 0; i < nums.size()-1; i++){    //这里i的范围是从数组第一个数到倒数第二个数,因为倒数第一个数是终点,不需要判断
        maxPosition = std::max(maxPosition, nums[i]+i);    //找能跳的最远的,也即更新边界
        if(i == end){    //更新边界
            end = maxPosition;
            steps++;
        }
    }

    return steps;

}