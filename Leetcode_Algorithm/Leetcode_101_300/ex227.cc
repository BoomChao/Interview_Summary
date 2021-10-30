


//Leetcode第227题:Basic CalculatorII
//基本计算器II(包含加减乘除运算)


//思路:通过一个栈来实现
//这里括号中的部分通过递归来求

int calculate(std::string s)
{
    std::stack<int> sta;

    char sign = '+';
    int res = 0, num = 0;

    for(int i = 0; i < s.size(); i++)
    {
        if(isdigit(s[i])) {
            num = num*10 + s[i] - '0';      //注意:这里不要写成+=
        }

        //当前字符数字并且也不是空格,或者是最后一个字符
        if((!isdigit(s[i]) && !isspace(s[i])) || i == s.size()-1)
        {
            if(sign == '-') {
                sta.push(-num);
            }
            else if(sign == '+') {
                sta.push(num);
            }
            else {
                int top;
                if(sign == '*') {
                    top = sta.top() * num;
                }
                else if(sign == '/') {
                    top = sta.top() / num;
                }

                sta.pop();
                sta.push(top);
            }

            sign = s[i];
            num = 0;
        }

    } 

    while(!sta.empty())
    {
        res += sta.top();
        sta.pop();
    }

    return res;

}

