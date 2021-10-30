

//Leetcode第81题
//Search in Rotated Sorted Array II : 在旋转数组中查找目标元素(这个数组中有重复元素)


//与33题类似

//思路:
//1.按照二分查找的思想,如果中间值小于最右边的数,则说明右半段是有序的
//2.如果中间值大于最右边的数,则说明左半段是有序的
//3.另外这道题有重复元素,假设对于数组 [3,1,1]或者[1,1,3,1],我们要查找元素3,但是这时中间数和最右边的数相等,而目标元素3可能在左边也可能在右边
//对于这种情况,我们把最右值左移一位即可继续循环



#include <iostream>
#include <vector>

bool search(std::vector<int> &nums, int target);

int main(){
    std::vector<int> nums = {2,5,6,0,0,1,2};

    std::cout << search(nums, 0) << std::endl;


    return 0;
}

bool search(std::vector<int> &nums, int target)
{
    if(nums.size() == 0) return false;

    int left = 0;
    int right = nums.size()-1;

    while(left <= right){
        int mid = (left + right)/2;
        if(nums[mid] == target) return true;

        else if(nums[mid] < nums[right]){      //说明mid的右半部分是有序的
            if(nums[mid] < target && target <= nums[right]){   //说明目标是在右半部分
                left = mid + 1;
            }else{
                right = mid-1;
            }
        }

        else if(nums[mid] > nums[right]){     //说明mid的左半部分是有序的
            if(nums[left] <= target && target < nums[mid]){    //说明目标是在左半部分
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
                            //也就是这一步与33题有差别,需要多处理一次当nums[mid]=nums[right]的情况
        else { right--; }   //这种情况是中位数等于末尾数,比如[3,1,1]或者[1,1,3,1],这时如果我们要查找3则有可能在左边也可能在右边
                            //这时我们把最右边值向左移一位,如果还相同则继续左移,直到移到不同值为止
    }

    return false;

}