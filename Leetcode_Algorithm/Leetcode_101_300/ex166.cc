


//Leetcode第166题:分数到小数

#include <iostream>
#include <unordered_map>

std::string fractionToDecimal(int numerator, int denominator);


int main(){
    std::cout << fractionToDecimal(2 ,3) << std::endl;

    return 0;
}



std::string fractionToDecimal(int numerator, int denominator)
{
    long long numer = numerator;        //为了防止下面whle循环中的相乘会溢出,这里使用long long型
    long long denom = denominator;
    std::unordered_map<long long, int> map;
    std::string ans;

    if(numer * denom < 0) {
        ans = "-";
    }
    numer = abs(numer);
    denom = abs(denom);
    ans += std::to_string(numer / denom);
    numer %= denom;
    if(numer == 0) return ans;      //说明能整除,则直接返回ans
    ans += '.';

    while(numer)
    {
        if(map.count(numer))
        {
            ans.insert(map[numer], "(");    //注意:insert函数是在字符串中插入字符串,所以即使是插入单个字符,也要使用双引号 ""
            // ans.push_back(')');          //push_back和+都表示向字符串中添加元素,字符串中的每个元素是单个字符,所以插入的字符需要使用单引号 ''
            ans += ')';
            return ans;
        }

        map[numer] = ans.size();
        ans += '0' + numer * 10 / denom;    
        numer = numer * 10 % denom;
    }

    return ans;

}