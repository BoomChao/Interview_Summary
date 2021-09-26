


//Leetcode第772题 : Basic Calculator III
//基本计算器III(包含加减乘除和括号运算)


int calculate(std::string s)
{
    std::stack<int> sta;
 
    int res = 0;
    long num = 0;
    char sign = '+';

    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if(isdigit(c)) {
            num = num*10 + c - '0';
        }
        else if(c == '(') {
            int count = 0;
            int j = i;

            //找到'('所对应的')', 比如表达式为 2+(3*(2-1)),这里第一次找到的是i=2的左括号和末尾的右括号
            for(; i < s.size(); i++) {
                if(s[i] == '(') count++;
                if(s[i] == ')') count--;
                if(count == 0) break;       
            }

            num = calculate(s.substr(j+1, i-j-1));      //递归计算括号中的数值
        }

        if((!isdigit(c) && !isspace(c)) || i == s.size()-1)
        {
            if(sign == '+') {
                sta.push(num);
            }
            else if(sign == '-') {
                sta.push(-num);
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
            
            sign = c;
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
