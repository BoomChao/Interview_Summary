

//Leetcode第214题:Shortest Palindrome
//最短的回文字符串:补充字母使得给定的字符串成为最短的回文字符串


#include <iostream>
#include <algorithm>

std::string shortestPalindrome(std::string s);


int main() {
    std::cout << shortestPalindrome("aaaa") << std::endl;

    return 0;
}

std::string shortestPalindrome(std::string s)
{
    int len = s.size();
    if(len < 2) return s;

    int longest = 1;    //包括开头第一个字母的回文字符串的长度
    int start, end;
    
    int i = 0;              //下面这些代码和第5题<查找最长的回文字符串相同>,但是由于这里要求的是最长的包含第一个字符的回文字符串,所以只需遍历到(len/2)即可
    while(i <= len/2)
    {
        start = end = i;

        //碰到相同的字符则将尾指针后移
        while(end < len-1 && s[end] == s[end+1]) {
            end++;
        } 

        //下一次首尾指针的位置
        i = end + 1;

        //增到首尾指针区间判断回文字符
        while(start > 0 && end < len-1 && s[start-1] == s[end+1]) {
            start--;
            end++;
        }

        if(start == 0 && longest < (end-start+1)) {
            longest = end - start + 1;
        }

    }

    std::string remain = s.substr(longest, len-longest);
    reverse(remain.begin(), remain.end());

    return remain + s;

}

