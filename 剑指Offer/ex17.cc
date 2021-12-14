

/*
    面试题17:打印从1到最大的n位数
    陷阱题
*/

//可以使用递归和非递归两种方法
//非递归方法比较难想到


#include <iostream>
#include <cstring>

void printNumber(char *number);
void print1ToMaxOfNDigits(int n);
void print1ToMaxOfNDigitsRecursively(char *number, int length, int index);


int main(){

    print1ToMaxOfNDigits(3);

    return 0;
}


void print1ToMaxOfNDigits(int n)
{
    if(n <= 0) return;

    char *number = new char[n+1];
    number[n] = '\0';

    for(int i = 0; i < 10; i++)
    {
        number[0] = i + '0';
        print1ToMaxOfNDigitsRecursively(number, n, 0);
    }

    delete[] number;

}

void print1ToMaxOfNDigitsRecursively(char *number, int length, int index)
{
    if(index == length-1)
    {
        printNumber(number);
        return;                  //注意:递归一定要有出口,也就是一定要有return语句
    }

    for(int i = 0; i < 10; i++)
    {
        number[index+1] = i + '0';      //注意:数字第一位数字的递增在这里设置
        print1ToMaxOfNDigitsRecursively(number, length, index+1);
    }

}


void printNumber(char *number)
{
    bool isBeginning0 = true;
    int length = strlen(number);

    for(int i = 0; i < length; i++)
    {
        if(number[i] != '0') {      //这里可以不必加isBeginning0这个条件
            isBeginning0 = false;
        }

        if(!isBeginning0) {
            printf("%c", number[i]);
        }

    }

    printf("\t");

}