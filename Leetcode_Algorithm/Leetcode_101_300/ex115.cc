

//Leetcode第115题 : Distinct Subsequences
//判断字符串s中有多少个子字符串等于字符串t

//思路:动态规划
//dp[i][j]表示字符串s的前i个字符组成的字符串子序列中,t的前j个字符组成的字符串出现的次数

//边界条件
//dp(0,0)=1.此时t和j都是空串,空串在空串中只匹配一次
//dp(i,0)=1,i>0,此时t为空串,而s不是空串,空串在s中只出现一次
//dp(0,j)=0,j>0,此时s为空串,而t不是空串,t在空串中不可能出现过

//状态方程
//当s[i]!=s[j],dp(i,j)=dp(i-1,j);例如"ABCD"的子序列中匹配"AB"的个数,与"ABC"中匹配"AB"的个数是相同的
//当s[i]=s[j]时,dp(i,j)=dp(i-1,j-1)+dp(i-1,j); 例如"ABCD"中匹配"ABC"的数量,除了其子序列匹配"ABC"中匹配"ABC"的数量,
//还要考虑"ABC"中匹配"AB"的数量; 即最后一个字符可能是前面匹配过的又重复了,也可能是现在才匹配的,需要考虑这两种情况


#include <iostream>

int numDistinct(std::string s, std::string t);

int main(){
    std::cout << numDistinct("babgbag", "bag") << std::endl;

    return 0;
}

int numDistinct(std::string s, std::string t)
{
    //两个字符串均为空,则也算匹配成功
    //两个字符串有一个为空.返回0
    //s的长度大于t的长度.则直接返回0
    if(s.empty() && t.empty()) return 1;
    if(s.empty() || t.empty()) return 0;
    if(s.size() < t.size()) return 0;

    //防止字符串太长,匹配的可行性太多,这里使用int可能会溢出
    long dp[s.size()+1][t.size()+1];

    for(int i = 0; i <= s.size(); i++) {
        dp[i][0] = 1;
    }

    for(int j = 1; j <= t.size(); j++) {
        dp[0][j] = 0;
    }

    for(int i = 1; i <= s.size(); i++)
    {
        for(int j = 1; j <= t.size(); j++)
        {
            dp[i][j] = dp[i-1][j];
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }

        }

    }

    return dp[s.size()][t.size()];

}