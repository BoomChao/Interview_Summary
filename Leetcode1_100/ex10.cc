

//Leetcode第10题 : Regular Expression Matching
//正则表达式匹配  思路可参考<剑指>面试题19


#include <iostream>
#include <vector>
using string = std::string;

bool isMatch(string s, string p);

int main(){
    string s ="aab", p = "c*a*b";       //健壮性可能有问题
    std::cout << isMatch(s, p) << std::endl;

    return 0;
}



//利用动态规划
//注意: '*'出现在模式的第一位是没有意义的,但是为了预防输入的在第一位,在if语句中加了一个 (j>1)条件

bool isMatch(std::string s, std::string p)
{
    int m = s.size();
    int n = p.size();

    std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
    dp[0][0] = true;    

    for(int i = 0; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(p[j-1] == '*') {
                dp[i][j] = (j > 1) && dp[i][j-2] || (i > 0 && dp[i-1][j] &&(s[i-1] == p[j-2] || p[j-2] == '.'));
            }
            else
            {
                dp[i][j] = (i > 0) && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
            }
        }
    }


    return dp[m][n];
}


//方法二:动态规划
bool isMatch(std::string s, std::string p)
{
    int m = s.size(), n = p.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++) {
        if(p[i-1] == '*') {
            dp[0][i] = dp[0][i-2];      //题目保证'*'前面一定有一个有效字符
        }
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(p[j-1] == '.') {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] != '*') {
                dp[i][j] = dp[i-1][j-1] && (p[j-1] == s[i-1]);
            }
            else if(p[j-2] != s[i-1] && p[j-2] != '.') {
                dp[i][j] = dp[i][j-2];
            }
            else {       //dp[i][j-1]代表忽略掉'*',dp[i][j-2]代表将'*'和前面的字符一起忽略,dp[i-1][j]代表字符串前进一位与当前字符比较
                dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i][j-2];
            }
        }
    }

    return dp[m][n];
}
