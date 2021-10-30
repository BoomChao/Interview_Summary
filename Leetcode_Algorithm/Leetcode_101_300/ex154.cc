


//Leetcode第154题 : Find Minimum in Rotated Sorted Array
//在有重复元素的旋转数组中找到最小的元素
//参考<剑指>面试题11


#include <iostream>
#include <vector>

int findMin(std::vector<int> &nums);
int minInOrder(std::vector<int> &nums, int index1, int index2);


int main(){
    std::vector<int> nums = {1};
    std::cout << findMin(nums) << std::endl;

    return 0;
}

int findMin(std::vector<int> &nums)
{
    int index1 = 0;
    int index2 = nums.size()-1;
    int indexMid = index1;

    while(nums[index1] >= nums[index2])
    {
        if(index2 - index1 == 1) {
            indexMid = index2;
            break;
        }

        indexMid = (index1 + index2)/2;

        //如果两个指针指向的数字和他们中间的数字相同,则采用顺序查找方法
        if(nums[index1] == nums[index2] && nums[indexMid] == nums[index1]) {
            return minInOrder(nums, index1, index2);
        }

        if(nums[indexMid] >= nums[index1]) {
            index1 = indexMid;
        }
        else if(nums[indexMid] <= nums[index2]) {
            index2 = indexMid;
        }

    }    

    return nums[indexMid];
}


int minInOrder(std::vector<int> &nums, int index1, int index2)
{
    int result = nums[index1];

    for(int i = index1 + 1; i <= index2; i++)
    {
        if(result > nums[i]) {
            result = nums[i];
        }
    }

    return result;
}



//解法二:更加简洁
//只需要让中间的数和右指针指向的数比较即可

int findMin(std::vector<int> &num)
{
    int left = 0;
    int right = num.size()-1;
    int mid = 0;

    while(left < right)
    {
        mid = left + (right - left)/2; 

        if(num[mid] > num[right]) {
            left = mid + 1;
        }
        else if(num[mid] < num[right]) {
            right = mid;
        }
        else {
            right--;
        }

    } 

    return num[left];
}
