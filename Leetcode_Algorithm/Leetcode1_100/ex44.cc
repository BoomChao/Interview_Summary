

//Leetcode第44题
//Wildcard Matching : 通配符的匹配

//思路:
//(1).先遍历s和p,如果i和j指向的元素相同或者j指向'?',则i,j都往后移
//(2).如果i,j指向不同,但是j指向的是'*',则记录当前'*'的位置和当前i的位置,将j继续往后移
//(3).如果i,j指向不同,但是j也没有指向'*',则需要回过头看'*',将j移动到'*'后一位,
//    i移动到之前匹配'*'号时标记的i的位置i_index,一直将i++,之后就是重复上述三步
//(4).其他情况全部返回false



#include <iostream>

bool isMatch(std::string s, std::string p);

int main(){
    std::string s = "adceb", p = "*a*b";
    // std::string s = "acdcb", p = "a*c?b";

    std::cout << isMatch(s, p) << std::endl; 


    return 0;
}


bool isMatch(std::string s, std::string p)
{
    int i = 0, j = 0;
    int star = -1;
    int i_index = 0;

    while(i < s.size()){
        if(j < p.size() && (p[j]=='?' || p[j]==s[i])){
            i++;
            j++;
        }
        else if(j < p.size() && p[j]=='*'){
            star = j++;
            i_index = i;
        }
        else if(star != -1){
            j = star+1;
            i_index++;
            i = i_index;
        }
        else return false;

    }

    while(j < p.size() && p[j] == '*') j++;

    return j == p.size();


}


//利用动态规划
bool isMatch(std::string s, std::string p)
{
    std::vector<std::vector<bool>> dp(s.size()+1, std::vector<bool>(p.size()+1, false));
    dp[0][0] = true;

    //确定第一行
    for(int i = 1; i <= p.size(); i++) {
        if(p[i-1] == '*') {
            dp[0][i] = dp[0][i-1];
        }

    }

    for(int i = 1; i <= s.size(); i++)
    {
        for(int j = 1; j <= p.size(); j++)
        {
            if(p[j-1] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            else {
                dp[i][j] = (s[i-1] == p[j-1] || p[j-1] == '?') && dp[i-1][j-1];
            }
            
        }

    }

    return dp[s.size()][p.size()];

}