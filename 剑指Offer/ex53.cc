

/*
    面试题53:在排序数组中查找数字
    注意：只要题目中涉及到了排序数组，一般都是考察二分查找
*/


#include <iostream>

int getFirstK(int *data, int length, int k, int start, int end);
int getLastK(int *data, int length, int k, int start, int end);
int getNumberOfK(int *data, int length, int k);

int getMissingNumber(const int *numbers, int length);

int getNumberSameAsIndex(const int *numbers, int length);


int main(){
    int data[] = {-3,-1,1,3,5};
    int n = sizeof(data)/sizeof(data[0]);

    // std::cout << getNumberOfK(data, n, 4) << std::endl;
    // std::cout << getMissingNumber(data, n) << std::endl;
    std::cout << getNumberSameAsIndex(data, n) << std::endl;

    return 0;
}


int getFirstK(int *data, int length, int k, int start, int end)
{
    if(start > end) return -1;      //数组中不包含k则返回-1

    int midIndex = (start + end)/2;
    int midData = data[midIndex];

    if(midData == k)
    {
        //如果中间数字等于k，判断前面一个数是否也等于k
        if((midIndex > 0 && data[midIndex-1] != k) || midIndex == 0) {
            return midIndex;
        }
        else {
            end = midIndex - 1;
        } 
    }
    else if(midData > k) {      //二分法更新起点start和终点end
        end = midIndex - 1;
    }
    else {
        start = midIndex + 1;
    }

    return getFirstK(data, length, k, start, end);

}


int getLastK(int *data, int length, int k, int start, int end)
{
    if(start > end) return -1;

    int midIndex = (start + end)/2;
    int midData = data[midIndex];

    if(midData == k) 
    {
        if((midIndex < length-1 && data[midIndex+1] != k) || midIndex == length-1) {
            return midIndex;
        }
        else {
            start = midIndex + 1;
        }
    } 
    else if(midData < k) {
        start = midIndex + 1;
    }
    else {
        end = midIndex - 1;
    }

    return getLastK(data, length, k, start, end);

}


int getNumberOfK(int *data, int length, int k)
{
    int number = 0;

    if(data != nullptr && length > 0)
    {
        int first = getFirstK(data, length, k, 0, length-1);
        int last = getLastK(data, length, k, 0, length-1);

        if(first > -1 && last > -1) {
            number = last - first + 1;
        }
    }

    return number;

}


//C++解法

int GetNumberOfTarget(std::vector<int> &nums, int target)
{
    if(nums.empty()) return 0;
    
    int first = GetFirstTarget(nums, 0, nums.size() - 1, target);
    int last = GetLastTarget(nums, 0, nums.size() - 1, target);

    if(first == -1 || last == -1) {
        return 0;
    }

    return last - first + 1;
}


int GetFirstTarget(std::vector<int> &nums, int left, int right, int target)
{
    //未找到目标则返回-1
    if(left > right) return -1;

    int midIndex = left + ((right - left) >> 1);
    int midData = nums[midIndex];

    if(midData == target) {
        if((midIndex > 0 && nums[midIndex-1] != target) || midIndex == 0) {
            return midIndex;
        }
        else {
            right = midIndex - 1;
        }
    }
    else if(midData > target) {
        right = midIndex - 1;
    }
    else {
        left = midIndex + 1;
    }

    return GetFirstTarget(nums, left, right, target);
}

int GetLastTarget(std::vector<int> &nums, int left, int right, int target)
{
    //未找到目标则返回-1
    if(left > right) return -1;

    int midIndex = left + ((right - left) >> 1);
    int midData = nums[midIndex];

    if(midData == target) {
        if((midIndex < nums.size()-1 && nums[midIndex+1] != target) || midIndex == nums.size() -1 ) {
            return midIndex;
        }
        else {
            left = midIndex + 1;
        }
    }
    else if(midData > target) {
        right = midIndex - 1;
    }
    else {
        left = midIndex + 1;
    }

    return GetLastTarget(nums, left, right, target);
}







//题目二：0~n-1中缺失的数字

int getMissingNumber(const int *numbers, int length)
{
    if(numbers == nullptr || length <= 0) return -1;

    int left = 0;
    int right = length - 1;
    while(left <= right)
    {
        int middle = (left + right)>>1;
        if(numbers[middle] != middle) 
        {
            if(middle == 0 || numbers[middle-1] == middle-1) return middle;

            right = middle - 1;
        }
        else 
        {
            left = middle + 1;
        }
    
    }

    //如果不缺失，则返回的是数组个数
    if(left == length) return length;

    return -1;

}



//题目三：数组中数值和下标相等的元素

int getNumberSameAsIndex(const int *numbers, int length)
{
    if(numbers == nullptr || length <= 0) return -1;

    int left = 0;
    int right = length - 1;
    
    while(left <= right)
    {
        int middle = (left + right)/2;

        if(numbers[middle] == middle) return middle;

        if(numbers[middle] > middle) {
            right = middle -1;
        }
        else {
            left = middle + 1;
        }

    }

    return -1;
}