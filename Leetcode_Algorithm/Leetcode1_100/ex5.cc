

//Leetcode第5题 : Longest Paildromic Substring
//计算一个字符串中的最长的回文子字符串


#include <iostream>

std::string longestPalindrome(string s);

int main(){
    std::string str = "bananas";
    std::cout << longestPalindrome(str) << std::endl;
    
    return 0;
}




//思路(滑动窗口): 利用二重指针

std::string longestPaildrome(std::string s)
{
    if(s.size() <= 1) return s;
    
    int maxIndex = 0;
    int maxLen = 0;
    int i = 0;

    while(i < s.size())
    {
        int start = i;
        int end = i;

        //如果当前字符与下一个字符相等,则end继续往后移动,直至当前字符与下一个字符不等
        while(end + 1 < s.size() && s[end] == s[end+1]) end++;

        //下一次i就从下一个不相等的字符开始遍历
        i = end + 1;

        //从当前位置开始同时往左右搜索
        while(start-1 >= 0 && end+1 < s.size() && s[start-1] == s[end+1]) {
            start--;
            end++;
        }

        //判断是否为最大回文字符串
        int curLen = end - start + 1;
        if(curLen > maxLen) {
            maxIndex = start;
            maxLen = curLen;
        }

    }

    return s.substr(maxIndex, maxLen);

}