
/*
    第58题:翻转字符串
    //参考Leetcode第151题
*/


#include <iostream>
#include <cstring>

void reverse(char *pBegin, char *pEnd);
char *reverseSentence(char *pData);
char *leftRotateString(char *ptr, int n);


int main(){
    // char str[] = "";
    // char *p = reverseSentence(str);

    // std::cout << p << std::endl;

    char str[] = "abcdefg";
    char *p = leftRotateString(str, 2);

    std::cout << p << std::endl;

    return 0;
}

void reverse(char *pBegin, char *pEnd) 
{
    if(pBegin == nullptr || pEnd == nullptr){
        return;
    }

    while(pBegin < pEnd)
    {
        char tmp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = tmp;

        pBegin++;
        pEnd--;
    }

}


//翻转单词顺序

char *reverseSentence(char *pData)
{
    if(pData == nullptr) return nullptr;

    char *pBegin = pData;
    char *pEnd = pData;
    while(*pEnd != '\0'){
        pEnd++;
    }
    --pEnd;

    reverse(pBegin, pEnd);    //翻转整个句子

    pBegin = pEnd = pData;  //翻转每个单词
    while(*pBegin != '\0')
    {
        //去除翻转整个句子后首部的空格
        if(*pBegin == ' ') {   
            pBegin++;
            pEnd++;
        }
        else if(*pEnd == ' ' || *pEnd == '\0') {
            reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        }
        else {
            pEnd++;
        }

    }

    return pData;
}




//左旋转字符串

char *leftRotateString(char *ptr, int n)
{
    if(ptr == nullptr) return nullptr;

    int len = static_cast<int>(strlen(ptr));  //使用strlen需要包含头文件<string.h>但是C++将<string.h>头文件全部转换成为<cstring>
    if(len == 0 || n <= 0 || n >= len) return ptr;

    char *pFirstStart = ptr;
    char *pFirstEnd = ptr + n - 1;
    char *pSecondStart = ptr + n;
    char *pSecondEnd = ptr + len - 1;

    //翻转字符串的前n个字符
    reverse(pFirstStart, pFirstEnd);

    //翻转字符串的后面部分
    reverse(pSecondStart, pSecondEnd);

    //翻转整个字符串
    reverse(pFirstStart, pSecondEnd);

    return ptr;

}
