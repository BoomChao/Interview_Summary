
//Leetcode第69题
//(Sqrt(x)):计算一个正整数x的平方根,只要求整数位的平方根,小数位舍去
//如: sqrt(8) = 2,    sqrt(10) = 3

//思路:牛顿迭代法
//可以参考面试题中计算平方根的那道题


#include <iostream>

int mySqrt(int x);

int main(){

    std::cout << mySqrt(8) << std::endl;
    
    return 0;
}


int mySqrt(int x)
{
    long long r = x;    //这是r用long long型是为了防止相乘后数据溢出 
    while(r*r > x){
        r = (r + x/r)/2;
    }

    return r;
}