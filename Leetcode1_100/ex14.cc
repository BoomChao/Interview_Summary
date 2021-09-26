

//Leetcode第14题 : Longest Common Prefix
//寻找字符串的最长公共前缀


#include <iostream>
#include <vector>

using string = std::string;

string longestCommonPrefix(std::vector<string> &strs);

int main(){
    std::vector<string> str = {"flower", "flow", "float"};
    std::cout << longestCommonPrefix(str) << std::endl;


    return 0;
}


//从第一个字符串的第一个字符开始逐个与后面的字符串匹配

std::string longestCommonPrefix(std::vector<std::string> &strs)
{
    if(strs.empty()) return "";

    for(int i = 0; i < strs[0].size(); i++)
    {
        for(int j = 1; j < strs.size(); j++)
        {
            if(i >= strs[j].size() || strs[0][i] != strs[j][i]) {
                return i > 0 ? strs[0].substr(0, i) : "";
            }
        }

    }

    return strs[0];

}
