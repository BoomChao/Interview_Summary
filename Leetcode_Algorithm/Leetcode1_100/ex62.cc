//Leetcode第62题
//Unique Paths : 计算网格上A到B的路径有多少

//方法一:排列组合问题
//方法二:动态规划

#include <iostream>
#include <vector>

int uniquePaths_1(int m, int n);
int uniquePaths_2(int m, int n);


int main(){
    std::cout << uniquePaths_2(3 ,7) << std::endl;

    return 0;
}

//使用排列组合
int uniquePaths_1(int m, int n)
{
    if(m <= 0 || n <= 0) return 0;
    long long res = 1;              //这里不能使用int型,防止结果会溢出,最好使用long long型
    for(int i = n; i < m+n-1; i++){
        res = res*i/(i-n+1);
    }

    return res;

}



//动态规划:
//dp[i][j]代表到达位置(i,j)的路径数,显然到达(i,j)只能是从(i-1,j)往下走一步
//或者(i,j-1)往后走一步到达的

int uniquePaths_2(int m, int n)
{
    std::vector<std::vector<int>> dp(m, std::vector<int>(n,1));    //初始化

    for(int i = 1; i < m; i++){                 //注意:这里i和j的下标是从1开始的,因为dp数组的初始值默认就是全1,
        for(int j = 1; j < n; j++){             //i=0,时无论j为多少,dp[i][j]永远为1; 同理j=0时,无论i为多少,dp[i][j]也永远为1
            dp[i][j] = dp[i-1][j] + dp[i][j-1];     
        }
    }

    return dp[m-1][n-1];

}


//上面的代码是同时从行和列考虑的,可以只考虑列即可,将上面的dp[i]去掉
int uniquePaths_3(int m, int n)
{
    std::vector<int> dp(n, 1);

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            dp[j] += dp[j-1];
        }
    }

    return dp[n-1];

}

