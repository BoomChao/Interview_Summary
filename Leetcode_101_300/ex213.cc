


//Leetcode第213题:House Rober II 
//打家劫舍II

//思路:两次动态规划


#include <iostream>
#include <vector>

int rob(std::vector<int> &nums);

int main(){
    std::vector<int> nums = {2,3,2};

    std::cout << rob(nums) << std::endl;

    return 0;
}


int rob(std::vector<int> &nums)
{
    if(nums.empty()) return 0;
    if(nums.size() == 1) return nums[0];
    
    //第一种情况:偷了第一家就不能偷最后一家了
    std::vector<int> dp1(nums.size());
    dp1[0] = nums[0];
    dp1[1] = std::max(nums[0], nums[1]);
    
    for(int i = 2; i < nums.size()-1; i++) {
        dp1[i] = std::max(dp1[i-1], dp1[i-2] + nums[i]);
    }


    //第二种情况:不偷第一家就可以偷最后一家
    std::vector<int> dp2(nums.size());
    dp2[0] = 0;
    dp2[1] = nums[1];

    for(int i = 2; i < nums.size(); i++) {
        dp2[i] = std::max(dp2[i-1], dp2[i-2] + nums[i]);
    }

    return std::max(dp1[nums.size()-2], dp2[nums.size()-1]);

}
