


//Leetcode第205题:Isomorphic Strings
//判断两个字符串是否为同型字符串

//使用哈希表

#include <iostream>

bool isIsomorphic(std::string s, std::string t);

int main(){
    std::cout << isIsomorphic("ab", "aa") << std::endl;

    return 0;
}

bool isIsomorphic(std::string s, std::string t)
{
    int m1[256] = {0};
    int m2[256] = {0};

    for(int i = 0; i < s.size(); i++)
    {
        if(m1[s[i]] != m2[t[i]]) return false;

        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;       //注意:这里不能写成 = i; 否则像这样s="ab", t="aa"或报错
    }

    return true;

}

