

/*
    面试题38:字符串的全排列
*/

#include <iostream>

void permutationCore(char *pStr, char *pBegin)
{
    if(*pBegin == '\0')
    {
        std::cout << pStr << std::endl;
    }
    else
    {
        for(char *pCh = pBegin; *pCh != '\0'; pCh++)
        {
            char tmp = *pCh;
            *pCh = *pBegin;
            *pBegin = tmp;

            permutationCore(pStr, pBegin + 1);

            //之前交换完毕的要复原回来方便第二个字母做首字母的全排列
            tmp = *pCh;
            *pCh = *pBegin;
            *pBegin = tmp;
        }

    }

}

void permutation(char *pStr)
{
    if(pStr == nullptr)  return;

    permutationCore(pStr, pStr);

}

int main(){
    char str[] = "";

    permutation(str);

    return 0;
}




//C++写法,利用string

void permutation(std::string &str)
{
    if(str.empty()) return ;

    permutationCore(str, 0);


}

void permutationCore(std::string &str, int pos)
{
    if(pos == str.size()) {
        std::cout << str << std::endl;
    }

    for(int i = pos; i < str.size(); i++)
    {
        char temp = str[pos];
        str[pos] = str[i];
        str[i] = temp;

        permutationCore(str, pos+1);

        temp = str[pos];
        str[pos] = str[i];
        str[i] = temp;
    }

}

