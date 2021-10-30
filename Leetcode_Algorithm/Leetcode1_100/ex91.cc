

//Leetcode第91题
//Decode Ways : 字符解码方式


//思路:动态规划(动态规划的要点就是找出其动态方程)
// 0出现在字符串开头,则肯定无法编码,直接返回0
// 如果0出现在字符串中间,但是无法和前面的字符串匹配,如30,40,这肯定也是无法编码的,直接返回0


//动态方程的建立
//1.首先确定dp[0]和dp[1]
//2.遍历剩下的字符串,分情况讨论
//(1)如果s[i] == '0',并且s[i-1]和s[i]能匹配成1-26之间的字母,则dp[i]=dp[i-2]
//   如果s[i-1]和s[i]匹配成1-26之间的字母,则直接返回0
//(2)如果s[i]!='0',并且s[i-1]和s[i]能匹配成1-26之间的字母,则dp[i]=dp[i-1]+d[i-2]
//   如果s[i-1]和s[i]不能匹配成1-26之间的字母,则dp[i]=dp[i-1]
//最终返回dp[s.size()-1]




#include <iostream>

int numDecodings(std::string s);
bool isMatach(char a, char b);

int main(){
    std::string s = "2030";

    std::cout << numDecodings(s) << std::endl;

    return 0;
}

int numDecodings(std::string s)
{
    int len = s.size();
    if(len == 0) return 0;      //空字符串或者首字符为0的字符串直接返回0
    if(s[0] == '0') return 0;
    if(len == 1) return 1;      //不为空,仅有一个字符,该字符不为0,则直接返回1

    int dp[len];
    dp[0] = 1;

    if(isMatach(s[0], s[1])){
        dp[1] = (s[1] == '0') ? 1 : 2;
    }
    else{
        dp[1] = (s[1] == '0') ? 0 : 1;
    }

    for(int i = 2; i < len; i++){
        if(s[i] == '0'){
            if(isMatach(s[i-1], s[i])) dp[i] = dp[i-2];
            else return 0;
        }
        else if(isMatach(s[i-1], s[i])) dp[i] = dp[i-1] + dp[i-2];
        else dp[i] = dp[i-1]; 

    }

    return dp[len-1];

}

//判断两个字符能否匹配成1-26之间的字母
bool isMatach(char a, char b){
    if(a == '0') return false;
    
    int tmp = (a-'0')*10 + b-'0';
    if(10 <= tmp && tmp <= 26) return true;
    else return false;

}


//解法二:更加简洁

int numDecodings(std::string s)
{
    if(s.empty()) return 0;

    int n = s.size();
    if(n == 0) return 0;
    int prev = s[0] - '0';
    if(prev == 0) return 0;
    if(n == 1) return 1;

    std::vector<int> dp(n + 1, 1);
    for(int i = 2; i <= n; i++)
    {
        int cur = s[i-1] - '0';
        if((prev == 0 || prev > 2) && cur == 0) return 0;
        if((prev > 0 && prev < 2) || prev == 2 && cur < 7)
        {
            if(cur != 0) {
                dp[i] = dp[i-1] + dp[i-2];
            }
            else {
                dp[i] = dp[i-2];
            }
        }
        else 
        {
            dp[i] = dp[i-1];
        }

        prev = cur;
    }

    return dp[n];
}