

//Leetcode第139题 : Word Break
//给定一个字符串,判断该字符串能否由指定的字典中的字符组成


#include <iostream>
#include <vector>
#include <unordered_set>

bool wordBreak(std::string s, std::vector<std::string> &wordDict);

int main(){
    std::string s = "leetcode";
    std::vector<std::string> wordDict = {"leet", "code"};

    std::cout << wordBreak(s, wordDict) << std::endl;

    return 0;
}

bool wordBreak(std::string s, std::vector<std::string> &wordDict)
{
    std::unordered_set<std::string> dict;
    int maxLen = 0;
    for(auto &str : wordDict) {
        dict.insert(str);
        maxLen = std::max(maxLen, (int)str.size());     //注意使用max函数,其中两个数据类型必须相同
    }

    int n = s.size();
    std::vector<bool> dp(n+1, false);
    dp[0] = true;

    for(int i = 1; i <= n; i++)
    {
        for(int j = i-1; j >= std::max(i-maxLen,0); j--)
        {
            if(dp[j] && dict.find(s.substr(j,i-j)) != dict.end()) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];

}


//解法二:利用动态规划

bool wordBreak(std::string s, std::vector<std::string> &wordDict)
{
    int n = s.size();
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(std::string &word : wordDict) 
        {
            int len = word.size();
            if(i >= len && s.substr(i - len, len) == word) {    //判断当前位置是否可以分割
                dp[i] = dp[i] || dp[i-len];
                // dp[i] = dp[i-len];       //不能写成这样
            }
        }
    }

    return dp[n];
}