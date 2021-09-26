

//Leetcode第162题 : Find Peak Element
//寻找数组中峰值元素的下标


#include <iostream>
#include <vector>

int findPeakElement(std::vector<int> &nums);


int main(){
    std::vector<int> nums = {1,2,1,3,5,6,4};
    std::cout << findPeakElement(nums) << std::endl;

    return 0;
}


//方法一:暴力破解

int findPeakElement(std::vector<int> &nums)
{
    int n = nums.size();
    if(n == 1) return 0;

    for(int i = 0; i < n; i++)
    {
        if(i == 0) {
            if(nums[0] > nums[1]) {
                return 0;
            }
        }
        else if(i == n - 1) {
            if(nums[n-1] > nums[n-2]) {
                return n-1;
            }
        }
        else {
            if(nums[i-1] < nums[i] && nums[i] > nums[i+1]) {
                return i;
            }
        }
    }

    return -1;
}



//方法二:利用二分查找

int findPeakElement(std::vector<int> &nums)
{
    if(nums.empty()) return -1;

    int left = 0;
    int right = nums.size() - 1;

    while(left < right)
    {
        int mid = left + (right - left)/2;

        if(nums[mid] < nums[mid+1]) {   //不需要使用<=,因为题目已经告知nums[i]!=nums[i+1]
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return left;
}