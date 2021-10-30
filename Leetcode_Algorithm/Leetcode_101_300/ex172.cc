

//Leetcode第172题:n阶乘末尾的0的个数


#include <iostream>

int trailingZeros(int n);

//思路:题目求末尾有几个0,实际就是在计算阶乘的过程中产生了几个10,有一个2*5成对就会产生一个10
//2的个数肯定会比5多,所以只需要找出有几个5,就能凑出几个10
//注意如果存在25的倍数,则会多出一个0

// 5!  末尾1个0 
// 10! 末尾2个0
// 15! 末尾3个0
// 20! 末尾4个0
// 25! 末尾6个0, 25 = 5*5, 所以while循环内部要加上一个 n/=5


int main(){
    std::cout << trailingZeros(25) << std::endl;

    return 0;
}

int trailingZeros(int n)
{
    int count = 0;
    
    while(n > 0)
    {
        //每间隔5个数有一个数可以被5整除,然后在这些可以被5整除的数中,每间隔5个数又有一个可以被25整除
        count += n/5;
        n /= 5;
    }

    return count;

}

