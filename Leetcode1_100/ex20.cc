

//Leetcode第20题 : Valid Parentheses
//确定是否是有效的括号组
//即给出有效的'['与它临近的必定要是']'


#include <iostream>
#include <stack>

bool isValid(string s);

int main(){
    string s = "{";
    std::cout << isValid(s) << std::endl;

    return 0;
}


bool isValid(std::string s)
{   
    if(s.size() <= 1) return false;
    
    std::stack<char> parent;

    for(const char &c : s)
    {
        switch(c){
            case '(':
            case '[':
            case '{': parent.push(c); break;            //下面这一行的判断是否为空一定要加,如果s="}",此时栈parent中并没有元素,这是一个空栈;这时.top()函数就会报错,
            case ')': if(parent.empty() || parent.top() != '(') return false; else parent.pop(); break;     //容器为空则empty()函数返回1
            case ']': if(parent.empty() || parent.top() != '[') return false; else parent.pop(); break;
            case '}': if(parent.empty() || parent.top() != '{') return false; else parent.pop(); break;
            default: break;     // 这一句加不加无所谓
        }
    }

    return parent.empty();  //防止最后一个字符是左括号
}

