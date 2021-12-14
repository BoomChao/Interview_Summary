

/*
    面试题3:数组中重复的数字(Leetcode第287题)

    1.找出数组中重复的数字

    2.不修改数组找出重复的数字
*/


#include <iostream>

bool duplicate(int numbers[], int length, int *duplication);
int getDuplication(const int *numbers, int length);
int countRange(const int *numbers, int length, int start, int end);


int main() {
    int num[] = {1,2,3,3};
    int n = sizeof(num)/sizeof(num[0]);
    // int duplication = -1;

    // if(duplicate(num, n, &duplication)) {
    //     std::cout << duplication << std::endl;
    // }

    std::cout << getDuplication(num, n) << std::endl;


    return 0;
}



//1.找出数组中重复的数字

bool duplicate(int numbers[], int length, int *duplication)
{
    if(numbers == nullptr || length <= 0) return false;

    //不满足每个数都小于数组长度的条件,直接返回
    for(int i = 0; i < length; i++)
    {
        if(numbers[i] < 0 || numbers[i] > length-1) {
            return false;
        }
    }

    for(int i = 0; i < length; i++)
    {
        while(numbers[i] != i)
        {
            if(numbers[i] == numbers[numbers[i]]) {
                *duplication = numbers[i];
                return true;
            }

            std::swap(numbers[i], numbers[numbers[i]]);
        }

    }

    return false;

}




//2.不修改数组找出重复的数字
//利用二分法(时间复杂度为O(nlogn), 空间复杂度为O(1))

int getDuplication(const int *numbers, int length)
{
    //空数组或者数组只有一个元素,直接返回-1
    if(numbers == nullptr || length <= 1) return -1;

    //不满足每个元素都小于数组长度
    for(int i = 0; i < length; i++)
    {
        if(numbers[i] < 0 || numbers[i] >= length) {
            return -1;
        }
    }


    int start = 1;
    int end = length-1;

    while(end >= start)
    {
        int middle = ((end-start)>>1) + start;
        int count = countRange(numbers, length, start, middle);
        
        if(end == start)
        {
            if(count > 1) return start;
            else break;
        }

        if(count > (middle-start+1)) {
            end = middle - 1;
        }
        else {
            start = middle + 1;
        }

    }

    return -1;

}


int countRange(const int *numbers, int length, int start, int end)
{
    if(numbers == nullptr) return 0;

    int count = 0;
    for(int i = 0; i < length; i++)
    {
        if(numbers[i] >= start && numbers[i] <= end) {
            ++count;
        }
    }

    return count;

}