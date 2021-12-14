
/*
    面试题50:第一个只出现一次的字符
*/

#include <iostream>
#include <cstring>

char firstNotRepeatingChar(char *pString);

void deleteFitstFromSecond(char *pStrFirst, char *pStrSecond);
void deleteOneChar(char *str, char toBeDelete);

int main(){
    // char str[] = "abaccdef";
    // std::cout << firstNotRepeatingChar(str) << std::endl;

    char str1[] = "We are studnet";
    char str2[] = "t";
    deleteFitstFromSecond(str1, str2);
    std::cout << str1 << std::endl;

    return 0;
}


//题目一:在字符串中找出第一个只出现一次的字符

char firstNotRepeatingChar(char *pString)
{
    if(pString == nullptr) return '\0';  //'\0'是一个换行符


    const int tableSize = 256;
    unsigned int hashTable[tableSize];

    for(int i = 0; i < tableSize; i++){
        hashTable[i] = 0;
    }

    char *pHashKey = pString;
    while(*(pHashKey) != '\0'){
        hashTable[*(pHashKey++)]++;
    }

    pHashKey = pString;
    while(*(pHashKey) != '\0'){
        if(hashTable[*pHashKey] == 1){
            return *pHashKey;
        }
        pHashKey++;
    }

    return '\0';

}


//题目二:字符流中第一个只出现一次的字符

class CharStatistics
{
public:
    CharStatistics() : index(0) {
        for(int i = 0; i < 256; i++) {
            occurence[i] = -1;
        }
    }

    void Insert(char ch) {
        if(occurence[ch] == -1) {
            occurence[ch] = index;
        }
        else if(occurence[ch] >= 0) {
            occurence[ch] = -2;         //存在重复的字符
        }

        index++;
    }

    char FirstAppearingOnce() {
        char ch = '\0';
        int minIndex = INT_MAX;
        for(int i = 0; i < 256; i++) 
        {
            if(occurence[i] >= 0 && occurence[i] < minIndex) {      //这是按照字典序进行搜索的
                ch = (char)i;                                       //但是实际字符串中字符的顺序可能不是这样,比如"ba",a先检索,但是第一个只出现一次的字符是b
                minIndex = occurence[i];
            }
        }

        return ch;
    }


private:
    int occurence[256];
    int index;
    
};




//相关题目一:
//解法一:时间复杂度O(n)
//在字符串1中删除在字符串2中出现过的所有字符

void deleteFitstFromSecond(char *pStrFirst, char *pStrSecond)
{
    if(pStrFirst == nullptr || pStrSecond == nullptr ) return ;

    int tableSize = 256;
    int hashTable[tableSize] = {0};

    char *pHashKey = pStrSecond;
    while(*(pHashKey) != '\0')
    {
        hashTable[*(pHashKey++)]++;
    }

    while(*pStrFirst != '\0')
    {
        if(hashTable[*pStrFirst] > 0){
            deleteOneChar(pStrFirst, *pStrFirst);
        }
        pStrFirst++;
    }

}


//删除字符串中出现的第一个指定字符(注:不是删除全部), 如str="hello", toBeDelete='l',删除结果为 "helo";

void deleteOneChar(char *str, char toBeDelete){
    if(str == nullptr) return;

    int len = strlen(str);
    char *p = str;
    for(int i = 0; str[i] != '\0' && i < len; i++)   //将if改为while,则删除所有出现的指定字符,如str="hello", toBeDelete='l',删除结果为"heo"
    {
        if(str[i] == toBeDelete)
        {              
            int j = i;
            for(; str[j] != '\0' && j < len-1; j++) {
                str[j] = str[j+1];
            }
            str[j] = '\0';
        }
    }

}


//将上面改用C++的写法

void dedeleFirstFromSecond(std::string &strFirst, std::string &strSecond)
{
    std::set<char> mySet;
    for(char ch:strSecond) {
        mySet.insert(ch);
    }

    int len = strFirst.size();
    for(int i = 0; i < len && strFirst[i] != '\0'; i++)
    {
        while(mySet.find(strFirst[i]) != mySet.end()) {
            strFirst.erase(i, 1);
        }
    }

}




//使用C语言编写
//时间复杂度O(n)
//哈希表 + 双指针
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


//上面的C++写法
//哈希+双指针
void deleteFitstFromSecond(std::string &first, std::string &second)
{
    if(first.empty() || second.empty()) return;

    std::vector<int> count(128, 0);

    for(const int &n : second) {
        count[n]++;
    }

    int cur = 0;
    for(const int &c : first) {
        if(count[c] == 0) first[cur++] = c;
    }

    first = first.substr(0, cur);
}




//相关题目二:
//哈希+双指针

void deleteDuplicateChar(std::string &s)
{
    if(s.empty()) return;

    std::vector<int> count(256, 0);

    int cur = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(count[s[i]] == 0) {
            s[cur++] = s[i];
        }
        count[s[i]] = 1;
    }

    s = s.substr(0, cur);
}


//相关题目三:

bool isAnagrams(const std::string &s, const std::string &t)
{
    if(s.size() != t.size()) return false;

    std::vector<int> count(26, 0);

    for(int i = 0; i < s.size(); i++)
    {
        count[s[i]-'a']++;
        count[t[i]-'a']--;
    }

    for(int i = 0; i < 26; i++) {
        if(count[i]) return false;
    }

    return true;
}


//字符流中第一个只出现一次的数字

class CharStatistics
{
private:
    int index;
    std::vector<int> count;

public:
    CharStatistics() : index(0) {
        count = std::vector<int>(256, -1);
    }

    void insert(char ch)
    {
        if(count[ch] == -1) {   //代表该字符没有出现过
            count[ch] = index;  //将其在count数组中的值置为下标
        }
        else if(count[ch] >= 0) {
            count[ch] = -2;     //已经出现过将其置为-2,以后不用再管了
        }
        
        index++;
    }

    char firstAppearingOnce()
    {
        int minIndex = index;

        char ch = '\0';

        for(int i = 0; i < 256; i++)
        {
            if(count[i] >= 0 && minIndex > count[i]) {
                minIndex = count[i];
                ch = (char)i;
            }
        }

        return ch;
    }

};
