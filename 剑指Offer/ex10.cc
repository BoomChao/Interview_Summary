//面试题10
//Fibonacci数列 + 青蛙跳台阶问题

#include <iostream>

long Fibonacci(int n);

int main(){
    int n = 100;
    std::cout << Fibonacci(n) << std::endl;     //代表求F(3)的值, F(0)=0, F(1)=1, F(2)=1

    return 0;
}


long Fibonacci(int n)
{
    int result[2]= {0, 1};

    if(n < 2) return result[n];

    long  left = 0, right = 1;
    long target;
    for(int i = 2; i <= n; i++){
        target = left + right;
        left = right;
        right = target;
    } 

    return target;
}