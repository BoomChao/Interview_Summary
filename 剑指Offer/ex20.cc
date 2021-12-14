

/*
    面试题20:表示数值的字符串
    弄清楚怎么表示一个正确的数值
*/


#include <iostream>

bool isNumeric(const char *str);
bool scanUnsignedInteger(const char **str);
bool scanInteger(const char **str);


int main(){
    char str[] = "";

    std::cout << isNumeric(str) << std::endl; 

    return 0;
}


bool isNumeric(const char *str)
{
    if(str == nullptr) return false;

    bool numeric = scanInteger(&str);

    if(*str == '.') {
        ++str;
        numeric = scanUnsignedInteger(&str) || numeric;
    }

    if(*str == 'e' || *str == 'E') {
        ++str;
        numeric = scanInteger(&str) && numeric;
    }

    return numeric && *str == '\0';

}


bool scanUnsignedInteger(const char **str)
{
    const char *before = *str;
    
    while(**str != '\0' && **str >= '0' && **str <= '9') {
        ++(*str);
    }

    return *str > before;

}


bool scanInteger(const char **str)
{
    if(**str == '+' || **str == '-') {
        ++(*str);
    }

    return scanUnsignedInteger(str);
}


//C++的解法

//匹配模式为 A[.[B]][e|EC]
//由于小数点前可能为空,如果为空,则小数点后一定要有数子 .B[e|Ec]
//[]代表可选项,可以没有,其中A和C都代表可能以'+'或者'-'开头的数字,而B不可能以符号开头

bool isNumber(std::string s)
{   
    if(s.empty()) return false;

    int i = 0;
    bool numeric = scanInteger(s, i);   //扫描A部分

    //扫描B部分
    if(s[i] == '.') {
        i++;
        numeric = scanUnsignedInteger(s, i) || numeric; //注意这里是或,小数点前面或者后面可能没有数字
    }

    //扫描C部分
    if(s[i] == 'E' || s[i] == 'e') {    
        i++;
        numeric = numeric && scanInteger(s, i);     //注意:这里是用与,因为e前面必须要求有数字
    }

    return numeric && (i == s.size());      //判断是否到达了字符串末尾
}

bool scanInteger(std::string s, int &i)
{
    if(i >= s.size()) return false;

    if(s[i] == '+' || s[i] == '-') i++;

    return scanUnsignedInteger(s, i);
}

bool scanUnsignedInteger(std::string s, int &i)
{
    if(i >= s.size()) return false;

    int before = i;

    while(i < s.size())
    {
        if(s[i] >= '0' && s[i] <= '9') i++;
        else break;
    }

    //s中存在无符号数时才返回
    return i > before;
}