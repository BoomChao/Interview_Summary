

/*
    面试题21:调整数组顺序使奇数位于偶数前面
    使用双指针
*/


#include <iostream>

void reorderOddEven(int *pData, unsigned int length);
void reorderOddEven(int *pData, unsigned int length, bool(*func)(int));
bool isEven(int n);
bool isPositive(int n);
bool isNotMultipleOf3(int n);


int main(){
    int num[] = {1,2,3,6,-5};
    int len = sizeof(num)/sizeof(num[0]);

    reorderOddEven(num, len, isNotMultipleOf3);

    for(int n:num) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}


//方法一:利用双指针法

void reorderOddEven(int *pData, unsigned int length)
{
    if(pData == nullptr || length == 0) return;

    int *pBegin = pData;
    int *pEnd = pData + length - 1;

    //偶数都放到后面
    while(pBegin < pEnd)
    {
        //向后移动pBegin,直到它指向偶数
        while(pBegin < pEnd && (*pBegin & 0x1) != 0) {
            pBegin++;
        }

        //向前移动pEnd,直到它指向奇数
        while(pBegin < pEnd && (*pEnd & 0x1) == 0) {
            pEnd--;
        }

        //将两指针指向的数交换
        if(pBegin < pEnd) {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }

    }

}



//对上面代码的优化

void reorderOddEven(int *pData, unsigned int length, bool(*func)(int))
{
    if(pData == nullptr || length == 0) return;

    int *pBegin = pData;
    int *pEnd = pData + length - 1;

    while(pBegin < pEnd)
    {
        while(pBegin < pEnd && !func(*pBegin)) {
            pBegin++;
        }

        while(pBegin < pEnd && func(*pEnd)) {
            pEnd--;
        }

        if(pBegin < pEnd) {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }

    }

}


bool isEven(int n)
{
    return (n & 1) == 0;
}


bool isPositive(int n)
{
    return n > 0;
}


bool isNotMultipleOf3(int n)
{
    return (n % 3) != 0;
}