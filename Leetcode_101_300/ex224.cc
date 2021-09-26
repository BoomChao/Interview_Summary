

//Leetcode第224题:Basic Calculator
//基本计算器(只含正负操作符的运算)

//思路:利用栈(只使用一个栈)

int calculate(std::string s)
{
    std::stack<int> sta;

    int res = 0;
    int sign = 1;   //表示符号
    int n = s.size();

    for(int i = 0; i < n; i++)
    {
        char c = s[i];
        if(isdigit(c))
        {
            int cur = c - '0';
            while(i != n-1 && isdigit(s[i+1])) {    //下一个数也是数字
                ++i;
                int next = s[i] - '0';
                cur = 10*cur + next;
            }

            res += sign*cur;
        }

        else if(c == '+') {
            sign = 1;
        }
        else if(c == '-') {
            sign = -1;
        }

        else if(c == '(') 
        {
            sta.push(res);      //括号前面的数
            res = 0;
            sta.push(sign);     //括号前面的符号位
            sign = 1;
        }
        else if(c == ')')      //弹出栈中元素计算
        {
            int a = sta.top();  sta.pop();
            int b = sta.top();  sta.pop();
            
            res = b + a*res;
        }

        else {      //其余情况为空格
            continue;
        }

    }

    return res;

}



//方法二:使用递归

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

            for(; i < s.size(); i++) {
                if(s[i] == '(') count++;
                if(s[i] == ')') count--;
                if(count == 0) break;
            }

            num = calculate(s.substr(j+1, i-j-1));
        }

        if((!isdigit(c) && !isspace(c)) || i == s.size()-1)
        {
            if(sign == '+') {
                sta.push(num);
            }
            else if(sign == '-') {
                sta.push((-num));
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

