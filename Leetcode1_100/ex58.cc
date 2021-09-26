//Leetcode第58题
//(Length of Last World) 寻找最后一个字符串并返回其长度

//思路:利用尾指针,如果尾指针指向的字符是空,则往前移;
//直到尾指针指向字符不为空时,开始计算长度,直到下一次所指字符又为空时停止计算


#include <iostream>
#include <algorithm>

using std::string;

int lengthOfLastWord(string s);

int main(){
    string s = "Hello Wrold ";
    std::cout << lengthOfLastWord(s) << std::endl;


    return 0;
}


int lengthOfLastWord(string s)
{
    int len = 0, tail = s.size()-1;
    while(tail>=0 && s[tail]==' ') tail--;
    while(tail>=0 && s[tail]!=' '){
        len++;
        tail--;
    }

    return len;

}