

//Leetcode第72题 : Edit Distance 
//计算从一个字符串转化到另一个字符串需要的步骤

//思路:动态规划
//dp[i][j]代表word1的前i个字符到word2的前j个字符需要的转化次数


#include <iostream>

int minDistance(std::string word1, std::string word2);

int main(){

    std::cout << minDistance("horse", "ros") << std::endl;

    return 0;
}

int minDistance(std::string word1, std::string word2)
{
    int m = word1.size();
    int n = word2.size();
    int dp[m+1][n+1];

    //依据动态规划的初始条件来构建动态方程的首项
    //边界条件
    for(int i = 0; i <= m; i++){
        dp[i][0] = i;
    }

    for(int j = 0; j <= n; j++){
        dp[0][j] = j;
    }


    //建立动态方程
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(word1[i-1] == word2[j-1])    //注意:这里的下标是[i-1][j-1]不是[i][j]
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                //依据动态规划的函数关系建立动态方程
                dp[i][j] = std::min(std::min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            }

        }
    }

    return dp[m][n];
}


//上面方法的简化

int minDistance(std::string word1, std::string word2)
{
    int m = word1.size(), n = word2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0) {
                dp[i][j] = j;
            }
            else if(j == 0) {
                dp[i][j] = i;
            }
            else {
                dp[i][j] = std::min(dp[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1), std::min(dp[i-1][j] + 1, dp[i][j-1] + 1));
            }
        }
    }

    return dp[m][n];
}

