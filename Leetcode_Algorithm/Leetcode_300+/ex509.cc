

// Leetcode第509题:Fibonacci Number
// 斐波那契数列

// 思路:不要使用递归,使用循环最佳

int fib(int n) 
{
    int result[2] = {0, 1};
    if(n < 2) return result[n];
    
    int fibOne = 0;
    int fibTwo = 1;
    int fibN = 0;
    for(int i = 2; i <= n; i++)
    {
        fibN = fibOne + fibTwo;
        fibOne = fibTwo;
        fibTwo = fibN;
    }
    
    return fibN;    
}