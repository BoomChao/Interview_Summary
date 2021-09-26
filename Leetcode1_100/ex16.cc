//Leetcode第16题
//求出数组中最接近给定的数的三个元素的和



#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

int threeSumClosest(std::vector<int> &nums, int target);

int main(){
    std::vector<int> nums = {-1,2,1,-4};
    int target = 1;
    std::cout << threeSumClosest(nums, target) << std::endl;

    return 0;
}

int threeSumClosest(std::vector<int> &nums, int target)
{
    int diff = INT_MAX;     //先给
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size() && diff!=0; i++){    //这里设置diff!=0判断,很巧妙
        int l = i+1, r = nums.size()-1;
        while(l < r){
            int sum = nums[i] + nums[l] + nums[r];
            if(abs(sum-target) < abs(diff)){
                diff = target-sum;
            }
            else if(sum < target) l++;
            else r--;  //当sum和target的差大于等于0时,即target恰好和target相等,将末尾指针前移
        }              //即sum-target>=0; 执行r--     
    }

    return target-diff;

}

