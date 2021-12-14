

/*
    面试题14:减绳子 (Leetcode第343题)
    要求至少减一刀,也就至少要有两段绳子
*/


//动态规划

int maxProductAfterCutting_Solution1(int length)
{
    //如果输入的数值是这几个,直接就返回结果
    if(length < 2) return 0;
    if(length == 2) return 1;
    if(length == 3) return 2;

    //注意:由公式f(n) = max(f(i)*f(n-i)) 0<i<n, n>=4 , 其中product存储的就是f(i),即prodcut[i]=f(i)
    int *products = new int[length + 1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;    
    products[3] = 3;    

    for(int i = 4; i <= length; i++)
    {
        int max = 0;
        for(int j = 1; j <= i/2; j++)
        {
            int prod = products[j] * products[i-j];
            if(max < prod) {
                max = prod;
            }

            products[i] = max;
        }
    }

    int ans = products[length];

    delete[] products;

    return ans;
}


//C++解法
int integerBreak(int n)
{
    if(n <= 1) return 0;
    if(n == 2) return 1;
    if(n == 3) return 2;

    std::vector<int> dp(n+1, 0);

    //这里的dp[i]不是代表总长度长度为i的绳子能减出的最大长度
    //这里的dp[i]代表的是剪出长度为i的子绳子的最大长度,就是f(i)
    dp[1] = 1, dp[2] = 2, dp[3] = 3;

    for(int i = 4; i <= n; i++)
    {
        int maxVal = 0;
        for(int j = 2; j <= i/2; j++) {
            maxVal = std::max(maxVal, dp[j]*dp[i-j]);
        }
        dp[i] = maxVal;
    }

    return dp[n];
}


//贪婪算法

int maxProductAfterCutting_Solution2(int length)
{
    if(length < 2) return 0;
    if(length == 2) return 1;
    if(length == 3) return 2;

    //尽可能多的去减长度为3的绳子
    int timesOf3 = length/3;

    //当绳子剩下的长度为4的时候,不能再去减长度为3的绳子
    if(length - timesOf3*3 == 1) {
        timesOf3 -= 1;
    }

    int timesOf2 = (length - timesOf3*3) / 2;

    return (int)pow(3, timesOf3) * (int)pow(2, timesOf2);
}


//贪婪算法:求出最多的3即可
//当n>=5时,竟可能多的去减长度为3的绳子
//当n=4时,剪成长度为2的两根绳子,乘积还是4

int integerBreak(int n)
{
    if(n <= 1) return 0;
    if(n == 2) return 1;
    if(n == 3) return 2;

    int res = 1;
    while(n > 4)
    {
        res *= 3;
        n -= 3;
    }

    return res*n;
}