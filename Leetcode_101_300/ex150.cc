

//Leetcode第150题:Evaluate Reverse Polish Notation
//计算逆波兰表达式


//解法一:
//思路:
//定义一个栈,遍历数组,如果是数字则存入栈,如果是运算符则将栈中两个元素出栈进行计算
//将计算后的结果重新入栈,最后栈中只剩一个数字,即为结果

//注意:如果使用isdigit函数来判断当前字符是否为数字,isdigit只能对单个字符''进行判断
//而tokens中元素是字符串"",如果利用string转char*函数c_str()或者data()转换后的是字符串,也不是单个字符,需要加上[0]

//atoi函数是C语言的函数,只能转化char*,如果想转化string需要将string转化成char*,利用c_str()函数或者data()函数
//或者直接利用C++里面的stoi()函数直接将string转化成int


int evalRPN(std::vector<std::string> &tokens)
{
    if(tokens.empty()) return 0;

    std::stack<int> sta;

    for(std::string str : tokens)
    {   
        //如果不是当前字符不是数字,也就是运算符,进行运算符元素
        //但是为了防止出现负数,比如"-1",所以这里要限制字符串长度为1才是运算符
        if(str.size() == 1 && !isdigit(str[0]))    
        {
            int secondNum = sta.top();
            sta.pop();
            int firstNum = sta.top();
            sta.pop();

            char c = str[0]; 
            switch(c){
                case '+' : sta.push(firstNum + secondNum); break;
                case '-' : sta.push(firstNum - secondNum); break;
                case '*' : sta.push(firstNum * secondNum); break;
                case '/' : sta.push(firstNum / secondNum); break;
                default  :  break;
            }
        }

        //是数字就直接入栈
        else
        {
            // sta.push(atoi(tokens[i].data()));
            sta.push(stoi(str));  //利用stoi()函数将string转化成int
        }

    }

    return sta.top();

}



//解法二:利用lambda表达式
//了解即可

int evalRPN(std::vector<std::string> &tokens)
{
    std::unordered_map<std::string, function<int, (int, int)>> map = {
        { "+", [](int a, int b){ return a + b; } },
        { "-", [](int a, int b){ return a - b; } },
        { '*', [](int a, int b){ return a * b; } },
        { '/', [](int a, int b){ return a / b; } }
    };

    std::stack<int> stack;
    for(std::string &str : tokens)
    {
        //是数字就入栈
        if(map.find(str) == map.end()) 
        {
            stack.push(stoi(str));
        }
        else 
        {
            int secondNum = stack.top();
            stack.pop();
            int firstNum = stack.top();
            stack.pop();
            stack.push(map[str](firstNum, secondNum));
        }
    }

    return stack.top();

}
