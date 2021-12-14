

/*
    面试题44:数字序列中的某一位的数字
*/

#include <iostream>
#include <cmath>

int digitAtIndex(int index);
int countOfIntegers(int digits);
int digitAtIndex(int index, int digits);
int beginNumber(int digits);


int main(){
    std::cout << digitAtIndex(1001) << std::endl;

    return 0;
}


int digitAtIndex(int index)
{
    if(index < 0) return -1;

    int digits = 1;
    
    while(true)
    {
        int numbers = countOfIntegers(digits);
        if(index < numbers*digits) {
            return digitAtIndex(index, digits);
        }

        index -= digits*numbers;
        digits++;
    }

    return -1;

}


//计算m位的数字一共有多少个
int countOfIntegers(int digits)
{
    if(digits == 1) return 10;

    int count = (int)pow(10, digits-1);
    
    return 9*count;
}


//知道要找的那位数在位于某m位数中后,就可以用如下函数找出那一位数字
int digitAtIndex(int index, int digits)
{
    int number = beginNumber(digits) + index/digits;
    int indexFromRight = digits - index%digits;
    
    for(int i = 1; i < indexFromRight; i++) {
        number /= 10;
    }

    return number % 10;
}


int beginNumber(int digits)
{
    if(digits == 1) return 0;

    return (int)pow(10, digits-1);
}
