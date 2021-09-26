

//Leetcode第34题 : Find First and Last Position of Element in the Sorted Array
//在一个排好序的数组中找到给定目标数据的开始位置和起始位置

//思路:采用二分查找,如果目标存在于给定的数组中,直接跳出while循环,接下来使用两个指针指向目标的前一个数和后一个数,使用while循环判断
//前向指针所指的数是否与目标相同,相同则前移; 同理对后向指针如果所指的指与目标相同则后移(注意要防止指针下标越界)
//如果目标不在给定的数组中,这时一定是while中的判断条件不成立才跳出了while循环,所以判断low > hig,直接返回{-1,-1}


#include <iostream>
#include <vector>

std::vector<int> searchRange(std::vector<int>& nums, int target);

int main(){
    // std::vector<int> nums = {5,7,7,8,8,10}; int target = 6;
    std::vector<int> nums = {1};    int target = 1;
    std::vector<int> res = searchRange(nums, target);
    for(int i = 0; i < res.size(); i++) std::cout << res[i] << " ";
    std::cout << std::endl;


    return 0;
}

//解法一:二分查找
std::vector<int> searchRange(std::vector<int> &nums, int target)
{
    if(nums.empty()) return {-1, -1};

    int n = nums.size()-1;
    int low = 0, hig = n;
    int mid;

    while(low <= hig)
    {
        mid = (low + hig) / 2;
        if(nums[mid] == target) break;
        else if(nums[mid] < target) {
            low = mid+1;
        }else {
            hig = mid-1;
        } 
    }
    
    if(low > hig) return {-1, -1};
    int i = mid - 1;
    int j = mid + 1;

    while(i >= 0 && nums[i] == nums[mid]) i--;   //注意while中条件的判断,使用了&&符号的话,会先判断第一个条件,如果条件1为true则接着判断&&的第二项
    while(j <= n && nums[j] == nums[mid]) j++;   //如果将nums[i]==nums[mid]放在第一项,如果i=-1,判断时很可能会出现数组越界,所以一定要先判断i>=0
                                             //但是如果写作 while(nums[j]==nums[mid] && i>=0)则编译器也不会报错,但是还是得第一项先判断i>=0
    return {i + 1, j - 1};
}



//解法二:相当于自己实现一个lower_bound函数和upper_bound函数
std::vector<int> searchRange(std::vector<int> &nums, int target)
{
    if(nums.empty()) return {-1, -1};

    int lower = lower_bound(nums, target);
    int upper = upper_bound(nums, target) - 1;

    if(lower == nums.size() || nums[lower] != target) return {-1, -1};

    return {lower, upper};
}

//找到第一个 >= target 的位置
int lower_bound(std::vector<int> &nums, int target)
{
    int l = 0, r = nums.size(), mid;        //考虑需要周到,这里 r = nums.size()
    while(l < r)                            //比如 nums={1}时,target=1时,返回{0,0}
    {
        mid = (l + r) / 2;
        if(nums[mid] >= target) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    return l;
}

//找到第一个 > target 的位置
int upper_bound(std::vector<int> &nums, int target)
{
    int l = 0, r = nums.size(), mid;
    while(l < r)
    {
        mid = (l + r) / 2;
        if(nums[mid] > target) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    return l;
}



