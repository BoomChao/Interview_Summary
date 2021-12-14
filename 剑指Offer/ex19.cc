

/*
    面试题18:正则表达式匹配
    //注意:只有模式里才有'.'和'*'符号; 而字符串中是没有这两个符号的
*/


//思路:重点在于模式中第二个字符就为'*'
//如果模式中第二个字符就是'*',有以下两种情况
//1.在模式上直接后移两个字符,相当于'*'和它前面的字符被忽略了
//2.如果字符串的第一个字符和模式的第一个字符相匹配,则将字符串后移一个元素
//  而在模式上有两种选择:(1).可以在模式上向后移动两个字符 (2).也可以保持模式不变
//  或者像1一样,直接忽略掉该'*',字符串也不向后移

//注意:上面的思路利用的是递归,在Leetcode第10题这种写法会提示超时
//改用动态规划会更加简洁


#include <iostream>

bool match(char *str, char *pattern);
bool matchCore(char *str, char *pattern);

int main(){
    char str[] = "aaa";
    char pattern[] = "a.a";
    std::cout << match(str, pattern) << std::endl;

    return 0;
}

bool match(char *str, char *pattern)
{
    if(str == nullptr || pattern == nullptr) return false;

    return matchCore(str, pattern);

}

bool matchCore(char *str, char *pattern)
{
    //如果字符串匹配到了模式末尾字符,则说明匹配成功
    if(*str == '\0' && *pattern == '\0') return true;

    //到了模式末尾却没到字符串末尾,则说明匹配失败(注意:这句话不能省)
    if(*str != '\0' && *pattern == '\0') return false;

    //如果模式首元素是就是'*'则肯定匹配失败,所以这里从模式第二个元素开始判断
    if(*(pattern + 1) == '*')
    {
        if(*pattern == *str || (*pattern == '.' && *str != '\0')) {
            return matchCore(str + 1, pattern + 2) ||
                   matchCore(str + 1, pattern) ||
                   matchCore(str, pattern + 2);
        }
        else 
        {   //如果'*'前面的字符都没有匹配成功,则后面的'*'只能表示前面的字符出现了0次,直接后移两位到'*'后面的字符
            return matchCore(str, pattern + 2);
        }

    }

    //第二个字符不是'*',且第一个字符匹配成功则字符串和模式都后移一位
    if(*str == *pattern || (*pattern == '.' && *str != '\0')) {
        return matchCore(str + 1, pattern + 1);
    }

    return false;   //其他情况返回false
}



//利用string的写法

bool match(std::string str, std::string pattern)
{
    //这个边界条件不能这么写,比如 str="", patten=".*"这也表示匹配成功
    // if(str.empty() || pattern.empty()) return false;

    return matchCore(str, 0, pattern, 0);
}


bool matchCore(std::string str, int i, std::string pattern, int j)
{
    if(i >= str.size() && j >= pattern.size()) return true;

    if(i < str.size() && j >= pattern.size()) return false;

    if(pattern[j+1] == '*')
    {
        if(str[i] == pattern[j] || (pattern[j] == '.' && i < str.size())) {
            return matchCore(str, i + 1, pattern, j + 2) ||
                   matchCore(str, i + 1, pattern, j) ||
                   matchCore(str, i, pattern, j + 2);
        }
        else
        {
            return matchCore(str, i, pattern, j + 2);
        }

    }

    if(str[i] == pattern[j] || (pattern[j] == '.' && i < str.size())) {
        return matchCore(str, i + 1, pattern, j + 1);
    }

    return false;
}
