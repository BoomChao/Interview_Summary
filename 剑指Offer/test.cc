

#include <iostream>
#include <vector>

void deleteFitstFromSecond(char *pFirst, char *pSecond);
void deleteFitstFromSecond(std::string &first, std::string &second);
void test(std::string &str);

int main() {
    std::string str1 = "We are students", str2 = "aeiou";

    deleteFitstFromSecond(str1, str2);
    // test(str1);
    std::cout << str1 << std::endl;

    return 0;
}

void test(std::string &str)
{
    str[3] = '\0';
}


//使用C语言编写

void deleteFitstFromSecond(char *pFirst, char *pSecond)
{
    if(pFirst == nullptr || pSecond == nullptr) return;

    std::vector<int> count(26, 0);
    while(*pSecond != '\0') {
        count[*pSecond-'a']++;
        pSecond++;
    }

    int cur = 0;
    char *p = pFirst;   
    while(*p != '\0') {
        if(count[*p-'a']) {
            p++;
        }
        else {
            pFirst[cur++] = *p;
            p++;
        }
    }

    pFirst[cur] = '\0';

}


void deleteFitstFromSecond(std::string &first, std::string &second)
{
    if(first.empty() || second.empty()) return;

    std::vector<int> count(26, 0);
    for(const char &c : second) {
        count[c-'a']++;
    }

    int cur = 0;
    for(int i = 0; i < first.size(); i++)
    {
        if(count[first[i]-'a']) continue;

        first[cur++] = first[i];
    }

    // first[cur] = '\0';  //添加字符串结尾符号
    first = first.substr(0, cur);   //不要犯上面这种低级错误,string中'\0'不能作为string类字符串的结尾

}