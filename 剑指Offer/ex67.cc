

/*
    面试题67:实现atoi函数
    参考Leetcode第8题,该题实现了atoi的所有功能
*/

//这个例题字符串开头和末尾不能输入空格
//但是实际的atoi函数中的字符串开头可以输入空格

#include <iostream>
#include <climits>

enum status {kvalid = 0, kInvalid};
int g_nStatus = kvalid;

int strToInt(const char *str);
long long strToIntCore(const char *digit, bool minus);

int main(){
    char str[] = "-123";
    std::cout << strToInt(str) << std::endl;

    return 0;
}

int strToInt(const char *str)
{
    g_nStatus = kInvalid;
    long long num = 0;

    if(str != nullptr && *str != '\0')
    {
        bool minus = false;
        if(*str == '+') {
            str++;
        }
        else if(*str == '-') {
            str++;
            minus = true;
        }

        if(*str != '\0') 
        {
            num = strToIntCore(str, minus);
        }

    }

    return (int)num;

}

long long strToIntCore(const char *digit, bool minus)
{
    long long num = 0;

    while(*digit != '\0')
    {
        if(*digit >= '0' && *digit <= '9')
        {
            int flag = minus ? -1 : 1;
            num = num*10 + flag*(*digit - '0');

            if((!minus && num > INT_MAX) || (minus && num < INT_MIN))
            {
                num = 0;
                break;
            }

            digit++;
        }
        else
        {
            num = 0;
            break;
        }

    }

    if(*digit == '\0') {
        g_nStatus = kvalid;
    }

    return num;

}


//C++的写法
//当输入的字符串为空时,显示报错并且返回0

int strToInt(std::string str)
{
    if(str.empty()) {
        std::cout << "Invalid Input!" << std::endl;
        return 0;
    }

    long long num = 0;
    int index = 0;
    bool minus = false;

    if(str[index] == '+' || str[index] == '-') {
        minus = (str[index] == '-') ? true : false;
        index++;
    }

    while(index < str.size())
    {
        if(str[index] >= '0' && str[index] <= '9')
        {
            int flag = minus ? -1 : 1;
            num = num*10 + flag*(str[index]- '0');

            if((!minus && num > INT_MAX) || (minus && num < INT_MIN)) {
                std::cout << "Invalid Input!" << std::endl;
                return 0;
            }

            index++;
        }
        else
        {
            std::cout << "Invalid Input!" << std::endl;
            return 0; 
        }

    }
    
    return (int)num;
}
