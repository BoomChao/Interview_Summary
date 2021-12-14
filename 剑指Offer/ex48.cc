

/*
    面试题48:最长不含重复字符的子字符串
    动态规划   
    参考Leetcode第3题,更加简洁,使用滑动窗口
*/

//注意:这种算法中不能输入空格,因为空格的ASCII码为13,小于字母a的ASCII码,
//所以下面的 position[str[i]-'a']这个下标为负数


#include <iostream>

int longestSubstringWithoutDuplication(const std::string &str);

int main(){

    std::string str = " ";

    std::cout << longestSubstringWithoutDuplication(str) << std::endl;

    return 0;
}

int longestSubstringWithoutDuplication(const std::string &str)
{
    int curLength = 0;
    int maxLength = 0;

    int *position = new int[26];
    for(int i = 0; i < 26; i++) {
        position[i] = -1;
    }

    for(int i = 0; i < str.size(); i++)
    {
        int preIndex = position[str[i]-'a'];

        if(preIndex < 0 || i-preIndex > curLength) 
        {
            ++curLength;
        }
        else 
        {
            if(curLength > maxLength) {
                maxLength = curLength;
            }

            curLength = i-preIndex;
        }

        position[str[i]-'a'] = i;
    }

    if(curLength > maxLength) {
        maxLength = curLength;
    }

    delete[] position;

    return maxLength;

}
