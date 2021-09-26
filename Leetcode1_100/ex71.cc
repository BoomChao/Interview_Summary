

//Leetcode第71题
//Simplify Path : 简化路径


//思路一:
//利用getline函数将字符串按照字符'/'分割
//1.如果子字符串为空或者为 "."则不做任何操作
//2.如果子字符串为 ".."并且容器不为空,则将容器尾元素删除; 
//如果子字符串为 ".."并且容器为空,则什么操作也不做
//3.其余情况则将子字符串个添加到容器中
//4.输出时加上 "/"并且判断是否为空,为空则输出 "/"即可



//思路二:
//真实面试中不一定能想到利用getline函数
//这时就将字符串分割存放进字符串容器中
//再和上面一样的思路将符合条件的字符串从数组中提取出来放入一个栈中
//再从栈中提取出元素



#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

std::string simplifyPath_1(std::string path);
std::string simplifyPath_2(std::string path);

int main(){
    std::string path = "/../";

    std::cout << simplifyPath_2(path) << std::endl;

    return 0;
}



std::string simplifyPath_1(std::string path)
{
    std::stringstream ss(path);
    std::string tmp, ans;
    std::vector<std::string> res;

    while(getline(ss, tmp, '/')){
        if(tmp == "." || tmp == "") continue;

        if(tmp == ".."){
            if(!res.empty()){
                res.pop_back();
            }
        }
        else{
            res.push_back(tmp);
        }
    }

    for(auto str:res){
        ans = ans + '/' + str;
    }

    return ans.empty() ? "/" : ans;     //因为像/../这种情况,最终得到的ans为空;所以需要判断是否为空


}


//上面版本的更简洁的版本
std::string simplifyPath_1(std::string path)
{
    std::vector<std::string> vec;
    std::string res, tmp;
    stringstream ss(path);

    while(getline(ss, tmp, '/')){
        if(tmp == "" || tmp == ".") continue;
        if(tmp == ".." && vec.size()) vec.pop_back();
        else if(tmp != "..") vec.push_back(tmp);    //注意:这里必须用else if 不能用else;
    }                                               //因为else包括两种情况, (tmp == ".." && vec.size()==0) 和 (tmp != "..");而第一种情况可以直接忽略

    for(auto s:vec) res += "/" + s;

    return res.empty() ? "/" : res;
}


std::string simplifyPath_2(std::string path)
{
    std::vector<std::string> vec;
    std::stack<std::string > st;
    std::string res;

    for(int i = 0; i < path.size();){
        std::string tmp = "";
        int j = i+1;
        while(j < path.size() && path[j]!='/') tmp += path[j++];
        i = j;
        vec.push_back(tmp);
    }

    for(auto str:vec){
        if(str == "" || str == ".") continue;

        if(str == ".."){
            if(!st.empty()) st.pop();
        }else{
            st.push(str);
        }
    }

    while(!st.empty()){
        res = "/" + st.top() + res;     //注意:这个顺序不要弄反了
        st.pop(); 
    }

    return res.empty() ? "/" : res;


}