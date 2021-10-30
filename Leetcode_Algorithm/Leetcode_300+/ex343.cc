

//Leetcode第343题:Integer Break
//将一个正整数拆成若干个整数使这些数乘积最大

//思路:尽可能多的拆分出3


int integerBreak(int n) 
{
    if(n == 2) return 1;
    if(n == 3) return 2;

    int res = 1;
    while(n > 4) {
        res *= n;
        n -= 3;
    }

    return res*n;
}
