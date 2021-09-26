//Leetcode第50题
//Pow(x,n) 计算浮点数x的n次幂

//思路:此题最好能先从简单的算例依据n的取值逐渐推到得出规律:即下面的 (n%2 == 0) ? myPow(x*x, n/2) : x*myPow(x*x, n/2)
//最后使用递归的手法写出代码



#include <iostream>

double myPow(double x, int n);

int main(){
    std::cout << myPow(2,-2) << std::endl;

    return 0;
}

double myPow(double x, int n)
{
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 1/x*myPow(1/x, -(n+1));     //注意题目的n的范围为-2^23 ~ 2^23-1
    }                                      //如果将上面改为myPow(1/x, -n)的话当n取值-2^23时就会溢出,所以这里采用的是 1/x*myPow(1/x, -(n+1))             

    return (n%2 == 0) ? myPow(x*x, n/2) : x*myPow(x*x, n/2);

}