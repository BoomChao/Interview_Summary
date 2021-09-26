


//Leetcode第93题
//Restore IP Addresses : 复原IP地址

//思路:深度优先


#include <iostream>
#include <vector>

std::vector<std::string> restoreAddresses(std::string s);
void dfs(std::string &s, int num, int pos, std::string path, std::vector<std::string> &res);


int main(){
    std::vector<std::string> ans = restoreAddresses("010010");

    // std::cout << ans.size() << std::endl;
    for(int i = 0; i < ans.size(); i++){
        std::cout << ans[i] << std::endl;
    }

    return 0;
}


std::vector<std::string> restoreAddresses(std::string s)
{
    std::vector<std::string> res;
    dfs(s, 0, 0, "", res);

    return res;

}

//第一种回溯

void dfs(std::string &s, int num, int pos, std::string path, std::vector<std::string> &res)
{
    //遍历完整个字符串,并且已经存在4个分段则递归结束
    if(pos == s.size() && num == 4){
        res.push_back(path.substr(0, path.size()-1));
        return;
    }

    //如果该段的字符数大于规定的最大数目,则直接退出
    if(s.size()-pos > 3*(4-num)) return;

    //该段只含有一个字符
    if(pos < s.size()){
        path += s.substr(pos, 1) + ".";
        dfs(s, num+1, pos+1, path, res);
        path = path.substr(0, path.size()-2);

    }

    //该段含有两个字符,并且第一个字符不是0
    if(pos < s.size()-1 && s[pos] != '0'){
        path += s.substr(pos, 2) + ".";
        dfs(s, num+1, pos+2, path, res);
        path = path.substr(0, path.size()-3);

    }

    //该段含有三个字符,第一个字符不为0,前三个字符小于等于255
    if(pos < s.size()-2 && s[pos] != '0' && s.substr(pos, 3) <= "255"){
        path += s.substr(pos, 3) + ".";
        dfs(s, num+1, pos+3, path, res);
        path = path.substr(0, path.size()-4);

    }

}


//第二种回溯

void dfs(std::string &s, int pos, int num, std::string path, std::vector<std::string> &res)
{
    if(num > 4) return;                 //这一句话一定要加,如果字符串的长度大于12位,那么划分的段数就会超过4段,这时就直接返回;
    if(pos == s.size() && num == 4){    //划分的段数刚好为4段时才添加入结果
        path.pop_back();            //这是为了去除掉末尾的'.'
        res.push_back(path);
        return;
    }

    //每个字段的字符数最少为1个,最多为3个;并且总的字符个数不能超过字符串s的总长度
    for(int i = 1; i <= 3 && pos + i <= s.size(); i++){
        std::string tmp = s.substr(pos, i);
        if(tmp[0] == '0' && i != 1) return;     //如果该段首字符为0但是该段总字符个数不止一个,就会出现比如 01.255.14.26 这种错误的IP地址,直接退出
        else if(stol(tmp) <= 255){              //IP地址要求每段的数字不能超过255
            dfs(s, pos + i, num + 1, path + tmp + ".", res);
        }

    }

}