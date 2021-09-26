//Leetcode第29题
//Diviede Two Intergers:不使用乘法和除法运算符做除法

//思路:
//利用位运算
//假设16/3,则3<<1=6,16-6=10;  6<<1=12,16-12=4; 12<<1=24>16 跳出
//此时16-12=4; 4-3=1, 1<3结束循环

//对于16/3,先计算16对于3的倍数的最大公倍数,3<<1=6,6小于16; 6<<1=12,12小于16; 12<<1=24大于16,此时记录下之前3增长的倍数为4
//16-12=4,4大于3, 3<<1=6大于4, 所以这时不进位,倍数就等于1
//一直到1小于3,则退出循环; 结果为 3+1=4


#include <iostream>
#include <climits>

int divide(int dividend, int divisor);

int main(){
    int dividend = 7, divisor = -3;
    std::cout << divide(dividend, divisor) << std::endl;

    return 0;
}

//              分子,         分母
int divide(int dividend, int divisor)
{
    //因为int型最小的负数的绝对值比最大的正数大1,所以这是预防比如 -2147483648/-1 = 2147483648或溢出,所以规定这种情况答案为 INT_MAX = 2147483647
    if(divisor==0 ||(dividend==INT_MIN && divisor==-1)) return INT_MAX;    //防止除数为0;以及需要排除掉一种溢出的情况

    long up = abs(dividend), down = abs(divisor);
    long ans = 0;
    int sign = (dividend>0 ^ divisor>0) ? -1 : 1;       //注解见下 

    while(up >= down){
        long temp = down;
        long m = 1;
        while(temp<<1 <= div){
            temp = temp<<1;
            m = m<<1;
        }
        up -= temp;
        ans += m; 
    }

    return sign*ans;

}


//对81行的解释,使用了异或运算符
//81行就等价于以下几行

// int sign = 1;
// if((dividend>0 && divisor<0) || (dividend<0 && divisor>0)){
//     sign = -1;
// }