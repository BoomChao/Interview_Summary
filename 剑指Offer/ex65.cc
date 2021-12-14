

/*
    面试题65:不用加减乘除做加法
*/


#include <iostream>

int add(int num1, int num2);

int main(){

    std::cout << add(-17, -5) << std::endl;

    return 0;
}

int add(int num1, int num2)
{
    int sum;
    int carry;

    do{
        sum = num1^num2;
        carry = (num1&num2)<<1;
        num1 = sum;
        num2 = carry;

    }while(num2 != 0);

    return num1;

}

//Leetcode第371题
int getSum(int a, int b)
{
    int sum, carry;
    while(b) {
        sum = a^b;
        carry = (unsigned)(a&b)<<1;     //这里的作用是将最高位符号位置0,以防止存在负数导致溢出
        a = sum;
        b = carry;
    }

    return a;
}

