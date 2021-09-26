
//Leetcode第342题:Power of Four 
//判断一个数是否为4的倍数

//思路:(n-1)&n 是判断一个数是否为偶数,n可能为2,4,6,8,
//但是是4的倍数的话需要再加一个条件就是 (n-1)%3 == 0


bool isPowerOfFour(int n)
{
    return (n > 0) && ((n-1) & n) == 0 && (n-1)%3==0;    
}

