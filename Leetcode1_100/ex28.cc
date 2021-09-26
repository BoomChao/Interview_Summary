

//Leetcode第28题 : Implement strStr()
//在给定的字符串找寻找子字符串,并返回其在给定的字符串中的下标 

//该题第二种解法很巧妙,必须掌握
//给定一个长字符串,再给定一个短字符串,要求找出这个短字符串的第一个字符在长字符串中的起始位置
//注:此题尤其要注意怎么注意needle为空的情况


#include <iostream>

using std::string;

int strStr(string haystack, string needle);

int main(){
    // string haystack = "aaaaa", needle = "bba";
    string haystack = "mississippi", needle = "sipp";
    std::cout << strStr(haystack, needle) << std::endl;

    return 0;
}

//方法一:利用字符串的substr函数
int strStr(string haystack, string needle)
{
    if(needle.size() == 0) return 0;    //needle字符串为空,返回0

    for(int i = 0; i < haystack.size(); i++){
        if(haystack[i] == needle[0]){
            if(haystack.substr(i, needle.size()) == needle) return i;
        }
    }

    return -1;

}


//上面的改进版本
int strStr(std::string haystack, std::string needle)
{
    int l1 = needle.size();
    int l = haystack.size();
    
    for(int i = 0; i <= l-l1; i++){
        string tmp = haystack.substr(i, l1);
        if(tmp == needle) return i;
    }

    return -1;
}




//方法二:很巧(需要看透)  双指针法
//分别从haystack和needle开始遍历    并且定义一个index记录haystack中与needle元素不同位置的下标的后一个元素
//1.如果i指向和j指向相同,则两指针同时后移;
//2.如果两个指针指向不相同,则将j重新指向needle首元素,将i指向上次遍历的下一个位置
//3.如果j遍历到了needle末尾,则返回index

int strStr(string haystack, string needle)
{
    if(needle.size() == 0) return 0;

    int j = 0, index = 0;
    for(int i = 0; i < haystack.size(); i++)
    {
        if(haystack[i] == needle[j]) { 
            j++;
        }
        else {
            j = 0;
            i = index++;
        }

        if(j == needle.size()) return index;
    }

    return -1;
}