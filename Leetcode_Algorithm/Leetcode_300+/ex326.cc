

// Leetcode第326题:Power of Three
// 判断是否为3的幂


bool isPowerOfThree(int n)
{
    if(n <= 0) return false;

    int maxOf3 = (int)pow(3, (int)(log(INT_MAX)/log(3)));

    return maxOf3 % n == 0;
}