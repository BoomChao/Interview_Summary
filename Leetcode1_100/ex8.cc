

//Leetcode第8题 : String to Intrger
//从字符串中提取出整型数据,实现atoi函数

//参考<剑指>面试题67


#include <iostream>
#include <climits>

int myAtoi(string str);

int main(){
    std::string str = "+-12";
    std::cout << myAtoi(str) << std::endl;     

    return 0;
}



int myAtoi(std::string s)
{
    if(s.empty()) return 0;

    int index = 0;
    long long num = 0;
    bool minus = false;

    //去除掉字符串首部的空格
    while(index < s.size() && s[index] == ' ') {
        index++;
    }

    if(s[index] == '+' || s[index] == '-') {
        minus = (s[index] == '-') ? true : false;
        index++;
    }
    int flag = minus ? -1 : 1;

    while(index < s.size())
    {
        if(s[index] >= '0' && s[index] <= '9')
        {
            num = num*10 + flag*(s[index]-'0');

            //判断结果是否超过int型的表示范围
            if(!minus && num > INT_MAX) {
                return INT_MAX;
            }
            if(minus && num < INT_MIN) {
                return INT_MIN;
            }

            index++;
        }
        else {
            break;
        }

    }

    return (int)num;
}

//不使用long类型

int myAtoi(std::string s)
{
    if(s.empty()) return 0;

    while(s[i] == ' ') i++;

    bool minus = false;
    if(s[i] == '+') {
        i++;
    }
    else if(s[i] == '-') {
        minus = true;
        i++;
    }

    int num = 0;
    int flag = minus ? -1 : 1;
    bool isMinusMax = false, isPositiveMax = false;
    
    while(i < s.size())
    {
        if(!isdigit(s[i])) break;

        if(num > INT_MAX/10 || (num == INT_MAX/10 && s[i]-'0' > 7)) {
            isPositiveMax = true;
            break;
        }
        else if(num < INT_MIN/10 || (num == INT_MIN/10 && s[i]-'0' > 8)) {
            isMinusMax = true;
            break;
        }
        
        num = num*10 + (flag)*(s[i] - '0');
        i++;
    }

    if(isPositiveMax) return INT_MAX;
    else if(isMinusMax) return INT_MIN;

    return num;
}
