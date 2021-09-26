


//Leetcode第301题:消去无效的括号,返回所有有效的组合


#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

std::vector<std::string> removeInvalidParentheses(std::string s);
bool isValid(std::string &s);



int main(){
    std::string s = "()())()";

    std::vector<std::string> res = removeInvalidParentheses(s);

    for(std::string str:res) {
        std::cout << str << std::endl;
    }

    return 0;
}


//使用BFS(广度优先搜索),这种解法效率太低
//拿一个例子跟着程序走一遍

std::vector<std::string> removeInvalidParentheses(std::string s)
{
    std::queue<std::string> q;
    std::unordered_set<std::string> ht;     //用来判断重复的字符串
    q.push(s);
    std::vector<std::string> res;

    while(!q.empty())
    {
        std::string ss = q.front();     
        q.pop();                    //这是弹出队首元素
        if(ht.count(ss)) continue;
        ht.insert(ss);

        if(isValid(ss)) 
        {
            res.push_back(ss);
        }
        else if(res.empty()) 
        {
            for(int i = 0; i < ss.size(); i++) 
            {
                if(ss[i] == ')' || ss[i] == '(') {
                    q.push(ss.substr(0, i) + ss.substr(i+1));
                }
            }
        }

    }

    return res;
}


bool isValid(std::string &s)        //这种解法不适合第20题,这种判断是否有效的解法只适合只有一种类型的括号
{
    int count = 0;
    
    for(auto c:s)
    {
        if(c == '(') count++;
        else if(c == ')') {
            if(count > 0) count--;
            else return false;
        }
    }

    return !count;
}
