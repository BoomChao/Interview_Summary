

//Leetcode第231题:Power of Two
//判断一个数是否为2的整数次幂

//方法一:辗转相除判断

bool isPowerOfTwo(int n)
{
    if(n <= 0) return false;

    while(n%2 == 0) {
        n /= 2;
    }

    return n == 1;
}


//方法二:使用位运算
//思路:如果一个数是2的整数次幂,则换算成二进制一定是这种形式 0001,0010,0100,1000
//所以减去1后与其自身做与运算后一定是等于0

bool isPowerOfTwo(int n)
{
    return n > 0 && !(n&(n-1));
}

