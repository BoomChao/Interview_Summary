

/*
    面试题16:实现pow函数
*/


#include <iostream>

double power(double base, int exponent);
bool equal(double num1, double num2);
double powerWithUnsignedExponent(double base, unsigned int exponent);


int main(){
    std::cout << power(2.2, 2) << std::endl;

    return 0;
}


double power(double base, int exponent)
{
    //如果底数为0并且指数小于0则打印错误信息,并返回一个0.0
    if(equal(base, 0.0) && exponent < 0) 
    {
        printf("Input Error!\n");
        return 0.0;
    }

    //如果底数为0,但指数大于等于0,则直接返回0.0
    else if(equal(base, 0.0)) 
    {
        return 0.0;
    }

    else
    {
        unsigned int absExponent = (unsigned int)(exponent);
        if(exponent < 0) {
            absExponent = (unsigned int)(-exponent);
        }

        double result = powerWithUnsignedExponent(base, absExponent);

        if(exponent < 0) {
            result = 1.0/result;
        }

        return result;

    }

}


//判断两个浮点数是否相等
bool equal(double num1, double num2)
{
    if(num1-num2 <= 0.00001 && num1-num2 > -0.00001) {
        return true;
    }
    else {
        return false;
    }

}


//计算幂乘
double powerWithUnsignedExponent(double base, unsigned int exponent)
{
    double result = 1.0;
    for(int i = 1; i <= exponent; i++) {
        result *= base;
    }

    return result;

}


//优化上面做幂乘的函数
double powerWithUnsignedExponent(double base, unsigned int exponent)
{
    if(exponent == 0) {
        return 1.0;
    }
    if(exponent == 1) {
        return base;
    }

    double result = powerWithUnsignedExponent(base, exponent >> 1);
    result *= result;

    //利用位与运算符来判断一个数是奇数还是偶数
    if(exponent & 0x1 == 1) {
        result *= base;
    }

    return result;

}


