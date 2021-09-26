//Leetcode第65题:
//Valid Number : 有效的十进制数

//思路:
//'e'和'.'最多只能出现一次
//'e'不能出现在最后的位置,'.'可以出现在最后的位置; 也就是说'2.'是合法的
//'e'和'.'之前必须要有数字
//如果出现过了'e', 则'.'就不能再出现了
//如果除去开头还有'+''-', 那么v必须出现在'e'之后的一位

//所以设计思路
//1.遍历数组先判断数字
//2.判断'e',(1)前面必须要有数字,(2)最多只能出现一次,(3)不能出现在末尾
//3.判断'.',(1)最多只能出现一次,(2)前面不能出现'e'
//4.其余情况全部返回false
//5.需要考虑遍历数组完成,则直接返回对num的判断; 如对 "." 可以遍历完数组,但是这个字符串没有数字,所以最后返回的是对数字的判断情况


#include <iostream>

bool isNumber(std::string s);

int main(){
    std::string s = "1. ";

    std::cout << isNumber(s) << std::endl;

    return 0;
}

bool isNumber(std::string s)
{
    int i = 0;
    int j = s.size()-1;
    
    while(s[i] == ' ') i++; 
    while(s[j] == ' ') j--;
    s = s.substr(i, j-i+1);     //除去字符串前后的空格

    i = 0;
    if(s.size() > 0 && (s[i]=='+' || s[i]=='-')) i++;   //除去字符串首部的'+-'

    bool exp = false, dot = false, num = false;

    for(; i < s.size(); i++){
        char c = s[i];
        if(c <= '9' && c >= '0'){
            num = true;             //代表数字已经出现
            continue;
        }
        else if(c == 'e'){
            if(!num || exp || i==s.size()-1) return false;    //'e'的前面必须要有数字,且'e'最多出现一次,且e不能出现在末尾
            exp = true;                                     //代表'e'已经出现
            if((s[i+1] == '-' || s[i+1] == '+') && i < s.size()-2) i++;     //注意这一步一定不能忘
        }
        else if(c == '.'){
            if(dot || exp) return false;  //'.'最多只能出现一次,且'.'前面不能出现'e'
            dot = true;                   //代表'.'已经出现
        }
        else return false;      //不是上述三种情况直接返回false

    }

    return num;

}