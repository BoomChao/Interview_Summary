//Leetcode第12题


#include <iostream>
#include <vector>

using string = std::string;

string thousands(int number);
string hunderds(int number);
string tens(int number);
string units(int number);
string intToRoman(int num);  

int main(){
    std::cout << intToRoman(366) << std::endl;
  
    return 0;
}




//解法一
string intToRoman(int num)
{
    string res = "";
    std::vector<int> a = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::vector<string> b = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int n = a.size();

    for(int i = 0; i < n; i++){
        while(num >= a[i]){     //这一行主要是针对像3这样的III表示的形式
            res.append(b[i]);   //append()函数用来在字符串末尾追加字符; 等价于 res.append(b[i]) = res+=b[i];
            num -= a[i];
        }
    }    

    return res;

}



//解法二(虽然很长,但是时间复杂度为O(1))     具体面试中不推荐这种解法
string thousands(int number)
{
    return string(number, 'M');
}

string hunderds(int number)
{
    if(number == 0) return "";
    if(number == 9) return "CM";
    if(number == 4) return "CD";
    string res;
    if(number > 4) res.push_back('D');
    for(int i = number%5; i > 0; i--) res.push_back('C');
    
    return res;
    
}

string tens(int number)
{
    if(number == 0) return "";
    if(number == 9) return "XC";
    if(number == 4) return "XL";
    string res;
    if(number > 4) res.push_back('L');
    for(int i = number%5; i > 0; i--) res.push_back('X');

    return res;
}

string units(int number)
{
    if(number == 0) return "";
    if(number == 9) return "IX";
    if(number == 4) return "IV";
    string res;
    if(number > 4) res.push_back('V');
    for(int i = number%5; i > 0; i--) res.push_back('I');

    return res;
    
}


string intToRoman(int num)
{
    int unit = num%10;
    num /= 10;
    int ten = num%10;
    num /= 10;
    int hunderd = num%10;
    num /= 10;
    int thousand = num%10;

    string sunit = units(unit);
    string sten = tens(ten);
    string shundred = hunderds(hunderd);
    string sthousand = thousands(thousand);

    return sunit + sten + shundred + sthousand;

}