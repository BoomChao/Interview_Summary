

//Leetcode第125题:判断一个字符串是否为回文字符串

//思路:利用首尾指针


//这是判断字符是否为有效字符是自定义函数来判断
//可以直接利用库函数,isalnum来判断该字符串是否为数字,字母(包含大小写),如果是返回非0,如果不是返回0
//toupper函数是将一个字符由大写转化为小写

bool isPalindrome(std::string s)
{
    for(int i = 0, j = s.size()-1; i < j; i++, j--)
    {
        while(!isValidChar(s[i]) && i < j) i++;    //首指针指向的不是有效字符,将首指针后移
        while(!isValidChar(s[j]) && i < j) j--;    //尾指针指向的不是有效字符,将尾指针前移

        //将字符统一转换成大写来比较
        if(toupper(s[i]) != toupper(s[j])) return false;    //如果首位指针指向的有效字符转换成大写后不相等则返回false
    }

    return true;

}



bool isValidChar(char c)
{
    if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
    else return false; 

}




//利用库函数isalnum和toupper函数更简洁的写法

bool isPalindrome(std::string s)
{
    for(int i = 0, j = s.size()-1; i < j; i++, j--)
    {
        while(!isalnum(s[i]) && i < j) i++;

        while(!isalnum(s[j]) && i < j) j--;

        if(toupper(s[i]) != toupper(s[j])) return false;

    }

    return true;

}
