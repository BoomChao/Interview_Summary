//Leetcode第22题
//Generate Parentheses : 给定n个()符号,求出其所有能返回完整()号的组合

//如 n=2,则 结果为 (())  ()()


//思路:
//1.如果'('的数量小于n,则填入'('
//2.如果')'的数量小于')'的数量,则填入')'


#include <iostream>
#include <vector>

using string = std::string;
void dfs(std::vector<string> &res, string s, int left, int right);
std::vector<string> generateParentheses(int n);

int main(){
    std::vector<string> res;
    res = generateParentheses(3);
    std::cout << res.size() << std::endl;
    for(int i = 0; i < res.size(); i++) std::cout << res[i] << "  ";
    std::cout << std::endl;


    return 0;
}




std::vector<string> generateParentheses(int n)
{
    std::vector<string> res;
    int left = n;
    int right = n;
    dfs(res, "", left, right);

    return res;

}

void dfs(std::vector<string> &res, string s, int left, int right) 
{
    if(left == 0 && right == 0){
        res.push_back(s);
    }

    if(left > 0) dfs(res, s+"(", left-1, right);
    if(left < right) dfs(res, s+")", left, right-1);

}