

//Leetcode第97题 : Interleaving String
//给定三个字符串,判断s3是否由s1和s2交错组成

//注意:比如s1="aabcc", s2="dbbca", s3="aadbbbaccc"
//s1和s2不能交错组成s3,因为s1和s2中的字符必须是连续的,也就是说对s1,必须"aab"先使用,"bcc"再使用

//思路:动态规划
//dp(i,j)表示s1的前i个字符串与s2的前j个字符串能否交错组成s3的前i+j个字符串

#include <iostream>

bool isInterleave(std::string s1, std::string s2, std::string s3);

int main(){
    std::cout << isInterleave("aabcc", "dbbca", "aadbbcbcac") << std::endl;
    // std::cout << isInterleave("aabcc", "dbbca", "aadbbbaccc") << std::endl;

    return 0;
}



bool isInterleave(std::string s1, std::string s2, std::string s3)
{
    if(s1.size() + s2.size() != s3.size()) return false;

    bool dp[s1.size()+1][s2.size()+1];

    //确定边界条件
    dp[0][0] = true;
    for(int i = 1; i <= s1.size(); i++) {
        dp[i][0] = (dp[i-1][0] && s1[i-1] == s3[i-1]);
    }

    for(int j = 1; j <= s2.size(); j++) {
        dp[0][j] = (dp[0][j-1] && s2[j-1] == s3[j-1]);
    }

    //动态方程
    for(int i = 1; i <= s1.size(); i++)
    {
        for(int j = 1; j <= s2.size(); j++)
        {
            dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
        }

    }

    return dp[s1.size()][s2.size()];

}


//将上面的确定边界条件可以放在下面的循环中,这样更加简洁
//代码如下

bool isInterleave(std::string s1, std::string s2, std::string s3)
{
    if(s1.size() + s2.size() != s3.size()) return false;

    int dp[s1.size()+1][s2.size()+1];

    for(int i = 0; i <= s1.size(); i++)
    {
        for(int j = 0; j <= s2.size(); j++)
        {
            if(i == 0 && j == 0) dp[i][j] = true;
            
            else if(i == 0) dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            
            else if(j == 0) dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]);    //这三个if都是用于确定边界条件

            else dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);   //这是动态方程

        }

    }

    return dp[s1.size()][s2.size()];    

}
