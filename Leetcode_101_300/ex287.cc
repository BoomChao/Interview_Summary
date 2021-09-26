

//Leetcode第287题:Find the Duplicate Number
//找到数组中重复的数字


#include <iostream>
#include <vector>

int findDuplicate(std::vector<int> &nums);

int main(){
    std::vector<int> nums = {3,1,3,4,2};

    std::cout << findDuplicate(nums) << std::endl;

    return 0;
}


//解法一:<剑指offer>

int findDuplicate(std::vector<int> &nums)
{
    if(nums.empty()) return -1;

    for(int i = 0; i < nums.size(); i++)
    {
        while(nums[i] != i+1)
        {
            if(nums[i] == nums[numbers[i]-1]) {
                return nums[i];
            }

            std::swap(nums[i], nums[nums[i]-1]);
        }

    }

    return -1; 
    
}


//解法二:利用标记的方法
//时间复杂度为O(n),空间复杂度为O(1),但是这种方式会改变输入的输入的原数组

int findDuplicate(std::vector<int> &nums)
{
    for(int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;       //注意:这个取绝对值的abs和下面的abs一定要加
        
        nums[index] *= -1;
        if(nums[index] > 0) {
            return abs(nums[i]);
        }

    }

    return -1;

}



//解法三:二分法搜索(参考<剑指>面试题3题目2)

int findDuplicate(std::vector<int> &nums)
{
    int start = 1, end = num.size()-1;

    while(end >= start)
    {
        int middle = start+(end-start)/2;
        int count = countRange(nums, start, middle);

        if(start == end)
        {
            if(count > 1) return start;
        }

        if(count > (middle-start+1)) {
            end = middle;
        }
        else {
            start = middle + 1;
        }

    }

    return -1;

}


int countRange(std::vector<int> &nums, int start, int end)
{
    int count = 0;
    
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] >= start && nums[i] <= end) {
            ++count;
        }
    }

    return count;
}
