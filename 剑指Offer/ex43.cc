


/*
    面试题43:1~n整数中1出现的次数
*/

#include <iostream>
#include <cstring>

int numberOf1Between1AndN(unsigned int n);
int numberOf1(unsigned int n);

int numberOf1Between1AndN(int n);
int numberOf1(const char* strN);
int powerBase10(unsigned int n);


int main(){
    std::cout << numberOf1Between1AndN(21345) << std::endl;

    return 0;
}


//方法一:暴力破解
//时间复杂度为O(nlogn)

int numberOf1Between1AndN(unsigned int n)
{
    int number = 0;

    for(unsigned int i = 1; i <= n; i++) {
        number += numberOf1(i);
    }

    return number;

}


int numberOf1(unsigned int n)
{
    int number = 0;

    while(n)
    {
        if(n % 10 == 1) {
            number++;
        }
            
        n /= 10;
    }

    return number;

}



//第二种方法,利用数字规律
//时间复杂度为O(logn)

int numberOf1Between1AndN(int n)
{
    if(n <= 0) return 0;

    char strN[50];
    sprintf(strN, "%d", n);     //将数组转化成字符串,以防止溢出

    return numberOf1(strN);

}


int numberOf1(const char* strN)
{
    if(!strN || *strN < '0' || *strN > '9' || *strN == '\0') return 0;

    int first = *strN - '0';    //这是得到第一个字符
    unsigned int length = static_cast<unsigned int>(strlen(strN));

    if(length == 1 && first == 0) return 0;
    if(length == 1 && first > 0)  return 1;

    int numFirstDigit = 0;
    if(first > 1) {
        numFirstDigit = powerBase10(length-1);
    }
    else if(first == 1) {
        numFirstDigit = atoi(strN+1)+1;
    }

    int numOtherDigits = first*(length-1)*powerBase10(length-2);

    int numRecrusive = numberOf1(strN+1);

    return numFirstDigit + numOtherDigits + numRecrusive;

}


int powerBase10(unsigned int n)
{
    int result = 1;
    for(unsigned int i = 0; i < n; i++) {
        result *= 10;
    }

    return result;
}




//使用string 替代 char*

int countDigitOne(int n)
{
    if(n <= 0) return 0;

    std::string str = std::to_string(n);

    return countDigitOneCore(str);

}


int countDigitOneCore(const std::string &str)
{
    int first = str[0] - '0';
    unsigned int length = str.size();

    if(length == 1 && first == 0) {
        return 0;
    }

    if(length == 1 && first > 0) {
        return 1;
    }

    int numFirstDigit = 0;
    if(first > 1) {
        numFirstDigit = (int)pow(10, length-1);
    }
    else if(first == 1) {
        numFirstDigit = std::stoi(str.substr(1)) + 1;
    }

    int numOtherDigit = first*(length-1)*(int)pow(10, length-2);

    int numRecursive = countDigitOneCore(str.substr(1));    //如果前面不加const则这里会报错

    return numFirstDigit + numOtherDigit + numRecursive;

}