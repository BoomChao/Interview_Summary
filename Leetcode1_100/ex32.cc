//Leetcode第32题
//题目要求的是最长的有效的括号数
//如:像 "()(()" 这样输出的结果应为2,因为中间被 '(' 给隔断了

//思路:利用栈
//先预先定义一个只有一个元素(-1)的栈,接下来依次判断如果是'('则将其下标压入栈中
//,若判断为')'则先弹出栈顶元素,判断栈是否为空,如为空则将')'下标压入栈中,不为空则计算最大的完整的
//括号,ans = max(ans, i-.top())


#include <iostream>
#include <stack>

using std::string;

int longestValidParentheses_1(string s);
int longestValidParentheses_2(string s);

int main(){
    string s = "()(()";
    std::cout << longestValidParentheses_2(s) << std::endl;


    return 0;
}



//解法一
int longestValidParentheses_1(string s)
{
    int ans = 0;
    std::stack<int> res;
    res.push(-1);   //预先压入一个数是为了预防第一个字符就是')'
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            res.push(i);
        }else{
            res.pop();
            if(res.empty()){
                res.push(i);
            }else{
                ans = std::max(ans, i-res.top());
            }
        }

    }

    return ans;

}


//解法一的变种(更好理解)
int longestValidParentheses_2(string s)
{
    int ans = 0;
    std::stack<int> res;
    res.push(-1);
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            res.push(i);
            continue;
        }
        res.pop();
        if(res.empty()){
            res.push(i);
            continue;
        }

        ans = std::max(ans, i-res.top());
    }

    return ans;

}