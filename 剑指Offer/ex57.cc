
/*
    面试题57:和为s的数字
*/

//思路:利用双指针法,当两指针指向元素之和大于给定值,则将尾指针前移,小于给定值将首指针后移


#include <iostream>

bool findNumbersWithSum(int data[], int length, int sum, int *num1, int *num2);

void findContinuousSequence(int sum);
void printContinuousSequence(int small, int big);


int main(){
    int data[] = {1,2,4,7,11,15};
    int n = sizeof(data)/sizeof(data[0]);
    // int *num1 = new int(0);
    // int *num2 = new int(0);
    int num1, num2;

    if(findNumbersWithSum(data, n, 15, num1, num2)) {
        std::cout << *num1 << std::endl;
        std::cout << *num2 << std::endl;
    }

    delete num1;
    delete num2;

    // findContinuousSequence(14);

    return 0;
}


bool findNumbersWithSum(int data[], int length, int sum, int *num1, int *num2)
{
    bool found = false;
    if(length < 1 || num1 == nullptr || num2 == nullptr) return found;

    int right =  length - 1;
    int left = 0;

    while(right > left)
    {
        int curSum = data[left] + data[right];   //没必要使用long long型,下面的if判断语句拿long和int比较没有意义

        if(curSum == sum)
        {
            *num1 = data[left];
            *num2 = data[right];
            found = true;
            break;
        }
        else if(curSum > sum) {
            right--;
        }
        else {
            left++;
        }

    }

    return found;

}



//题目二:和为s的连续正序列

void findContinuousSequence(int sum)
{
    //两个连续正数的最小和为3
    if(sum < 3) return;

    int small = 1;
    int big = 2;
    int middle = (1 + sum)/2;     //small的上限(取不到)
    int curSum = small + big;

    while(small < middle)
    {
        if(curSum == sum) {
            printContinuousSequence(small, big);
        }

        while(curSum > sum && small < middle)
        {
            curSum -= small;
            small++;

            if(curSum == sum) {
                printContinuousSequence(small, big);
            }
        }

        big++;
        curSum += big;

    }

}


void printContinuousSequence(int small, int big)
{
    for(int i = small; i <= big; i++) {
        printf("%d ", i);
    }

    printf("\n");
}


//C++写法

std::vector<std::vector<int>> continueSubsequences(int target)
{
    std::vector<std::vector<int>> res;

    if(target < 3) return res;

    int small = 1, big = 2;
    int middle = (target + 1)/2;
    int curSum = small + big;

    while(small < middle)
    {
        if(curSum == target) {
            res.push_back(subsequence(small, big));
        }

        while(curSum > target && small < middle) 
        {
            curSum -= small;
            small++;

            if(curSum == target) {
                res.push_back(subsequence(small, big));
            }
        }

        big++;
        curSum += big;
    }

    return res;
}

std::vector<int> subsequence(int low, int hig)
{
    std::vector<int> res;

    for(int i = low; i <= hig; i++) {
        res.push_back(i);
    }

    return res;
}