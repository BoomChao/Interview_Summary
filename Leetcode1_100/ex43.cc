

//Leetcode第43题:Multiply String : 数字字符串相乘

//思路:
//参考<剑值>面试题17 :字符串是一种简单,有效的表示大数的方法
//注意这题的边界条件,如果输入的是 "00"*"00",则输出的结果为单个"0"


#include <iostream>

std::string multiply(std::string num1, std::string num2);

int main(){
    std::cout << multiply("123", "456") << std::endl;

    return 0;
}

std::string multiply(std::string num1, std::string num2)
{
    //对结果字符串预留的位数为这两个相乘的字符串的位数之和
    std::string res(num1.size() + num2.size(), '0');

    for(int i = num1.size()-1; i >= 0; i--)
    {
        for(int j = num2.size()-1; j >= 0; j--)
        {
            //若是乘积大于10,比如16,则将6置于本位,1进位到上一位

            int product = (num1[i]-'0')*(num2[j]-'0') + res[i+j+1]-'0';    //该位的乘积需要加上上一步的进位到该位的值
            res[i+j+1] = product%10 + '0';
            res[i+j] += product/10;     //进位的值需要累加,不能把原有位的值覆盖掉

        }

    }

    for(int i = 0; i < num1.size()+num2.size(); i++)
    {
        //去除掉首位多余的0
        if(res[i] != '0') {
            return res.substr(i);
        }
    }

    return "0";

}