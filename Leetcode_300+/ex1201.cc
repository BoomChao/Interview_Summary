


//Leetcode第1201题目:Ugly Number III
//丑数III

//思路:二分+数学知识

int nthUglyNumber(int n, int a, int b, int c) 
{
    long left = 1, right = 2000000000;      //这是总范围

    //求(a,b)的最小公倍数,(a,c)的最小公倍数,(b,c)的最小公倍数,以及三个数的最小公倍数
    long lcmab = lcm(a, b);
    long lcmac = lcm(a, c);
    long lcmbc = lcm(b, c);
    long lcmabc = lcm(lcmab, c);

    while(left < right)
    {
        long mid = left + ((right - left) >> 1);
        int count = mid/a + mid/b + mid/c - mid/lcmab - mid/lcmac - mid/lcmbc + mid/lcmabc;
        
        if(count < n) {         //如果个数比n小,则继续向右扩大边界
            left = mid + 1;
        }
        else {                  //如果个数比n大或者等于n,则一直像左缩小边界找到满足要求的最小的数
            right = mid;
        }
    }

    return right;

}


//(a,b)最小公倍数等于(a*b)/(最大公约数)

//Lowest Common Multiple(最小公倍数)
long lcm(long a, long b) {
    return (a*b)/gcd(a,b);
}


//Greatest Common Divisor(最大公约数)

//递归求解
/*
int gcd(int a, int b) 
{
    if(a < b) return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a%b);
}
*/

//迭代求解
long gcd(long a, long b)
{
    if(a < b) return gcd(b, a);

    while(b > 0) {
        int rem = a%b;
        a = b;
        b = rem;
    }

    return a;
}
