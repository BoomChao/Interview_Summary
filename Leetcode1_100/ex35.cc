//Leetcode第35题
//Search Insert Position(在一个排好序的数组中寻找target返回其下标,若没有该target,返回target应该插入在有序数组中的位置下标) 


//解法一思路:采用二分查找,如果查找到目标target,直接返回,否则等待循环退出得到的mid是最接近target的数组元素的下标
//判断目标与该下标元素的大小,如目标大于该下标元素,则返回mid+1;目标小于该下标元素,返回mid

//解法二思路:仍然采用二分查找,跳出循环的条件是low>hig,由于low和hig都是以1为单元增加的,所以循环跳出条件相当于low>=hig+1
//所以插入变量的范围为[low, hig+1]=[low,low],这也说明low就死我们期待的返回下标值,因此循环结束后直接返回


#include <iostream>
#include <vector>

int searchInsert_1(std::vector<int> &nums, int target);
int searchInsert_2(std::vector<int> &nums, int target);


int main(){
    std::vector<int> nums = {1,3,5,6};
    int target = 0;
    std::cout << searchInsert_1(nums, target) << std::endl;
    std::cout << searchInsert_2(nums, target) << std::endl;

    return 0;
}



int searchInsert_1(std::vector<int> &nums, int target)
{
    int low = 0, hig = nums.size()-1;
    int mid;
    while(low <= hig){
        mid = (low+hig)/2;
        if(target == nums[mid]) return mid;
        if(target < nums[mid]){
            hig = mid-1;
        }else{
            low = mid+1;
        }
    }

    if(target < nums[mid]) return mid;
    if(target > nums[mid]) return mid+1;

}


int searchInsert_2(std::vector<int> &nums, int target)
{
    int low = 0, hig = nums.size()-1;
    while(low <= hig){      
        int mid = (low+hig)/2;
        if(nums[mid] < target){
            low = mid+1;
        }else{
            hig = mid-1;
        }
    }

    return low;

} 