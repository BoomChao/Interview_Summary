


//Leetcode第151题 : Reverse Words in a String
//翻转字符串中的单词,翻转之后的单词用一个空格隔开


#include <iostream>

std::string reverseWords(std::string s);

int main(){
    std::string s =  "";
    std::cout << reverseWords(s) << std::endl;

    return 0;
}


//解法一:题目要求不能使用额外空间,这种解法使用了额外空间,但是很简洁
//使用尾指针

std::string reverseWords(std::string s)
{
    if(s.size() <= 1) return s;

    std::string res;

    for(int i = s.size()-1; i >= 0; i--)
    {
        if(s[i] == ' ') continue;
        
        int end = i;
        while(i >= 0 && s[i] != ' ') {
            i--;
        }
        res += s.substr(i + 1, end - i) + ' ';

    }

    //把最后一个单词后面的空格去掉
    res.pop_back();

    return res;
}


//解法二:不使用额外空间
//两种方法:1.先翻转单个单词再翻转整个句子
//2.先翻转整个句子再翻转单个单词

std::string reverseWords(std::string s)
{
    int n = s.size();
    if(n <= 1) return s;

    int i = 0, j = 0;
    while(i < n)
    {
        while(i < n && s[i] == ' ') i++;

        if(i < n && j > 0) s[j++] = ' ';

        while(i < n && s[i] != ' ') {
            s[j++] = s[i++];
        }

        reverse(s.begin() + start, s.begin() + j);
    }

    s.resize(j);

    reverse(s.begin(), s.end());

    return s;
}



