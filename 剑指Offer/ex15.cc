
/*
    面试题15:二进制中1的个数
*/

//思路:一个整数减去1,在和原整数做与运算就会把该整数的最右边的1变成0;
//这种方法整数中有几个1就只需要循环几次

#include <iostream>


int NumberOf1_1(int n);
int NumberOf1_2(int n);


int main(){
    //计算机中的数据都是以补码表示的,-2原码为:10000000 0000000 00000000 00000010
    //反码为:11111111 1111111 11111111 11111101  补码为:11111111 11111111 11111111 11111110   所以输出结果为31

    // std::cout << NumberOf1_2(-2) << std::endl;  
                                              
    std::cout << NumberOf1_2(9) << std::endl;

    return 0;
}



//常规解法(暴力解法)
int NumberOf1_1(int n)
{
    int count = 0;
    int flag = 1;

    while(flag){
        if(n&flag) count++;
        flag = flag<<1;
    }

    return count;
}


//利用减去1的数和原整数做与运算
int NumberOf1_2(int n)
{
    int count = 0;

    while(n){
        count++;
        n = (n-1)&n;
    }

    return count;
}




//相关题目一:用一条语句判断一个整数是否为2的整数次方

bool isPowerOf2(int n)
{
    return n&(n-1) == 0;
}



//相关题目二:输入两个整数m和n,计算需要改变m的二进制表示中的多少位才能得到n
//1.先计算这两个数的异或;   2.统计异或结果中的1的个数

int mTon(int m, int n)
{
    int count = 0;

    int tmp = m^n;
    whie(tmp) {
        count++;
        tmp = (tmp)&(tmp-1);
    }

    return count;
}
