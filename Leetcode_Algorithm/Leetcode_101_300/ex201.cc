

//Leetcode第201题:Bitwise AND of Number Range
//求出两个数范围内的所有数的按位与

//思路:求出m和n的高位比特的公共部分


#include <iostream>

int rangeBitwiseAnd(int m, int n);

int main(){
    std::cout << rangeBitwiseAnd(1, 63) << std::endl;

    return 0;
}


//方法一:变动m和n本身

int rangeBitwiseAnd(int m, int n)
{
    int move = 0;

    while(m != n)
    {
        m >>= 1;
        n >>= 1;
        move++;
    }

    return m << move;
}


//方法二:删除n的低位部分

int rangeBitwiseAnd(int m, int n)
{
    while(m < n) {
        n = n & (n-1);
    }

    return n;
}
