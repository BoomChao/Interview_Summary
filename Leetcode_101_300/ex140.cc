

//Leetcode第140题 : Word Break II
//给定一个字符串,将该字符串拆分成给定的字典的元素的组合;返回所有可能的组合


//思路:回溯


#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<std::string> res;
std::string tmp = "";

void dfs(std::string &s, std::string tmp, std::vector<std::vector<int>> &record, int m);
std::vector<std::string> wordBreak(std::string s, std::vector<std::string> &wordDict);

int main(){
    std::string s = "catsanddog";
    std::vector<std::string> wordDict = {"cat", "cats", "and", "sand", "dog"};

    std::vector<std::string> ans = wordBreak(s, wordDict);

    for(int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << std::endl;
    }

    return 0;
}





void dfs(std::string &s, std::string tmp, std::vector<std::vector<int>> &record, int m)
{
    if(m == s.size()) {
        res.push_back(std::string(tmp.begin(), tmp.end()-1));   //去掉最后的空格
        return ;
    }

    for(int i = 0; i < record[m].size(); i++)
    {
        if(record[m][i] == 1) {
            dfs(s, tmp + s.substr(m, i-m) + " ", record, i);
        }

    }

}


std::vector<std::string> wordBreak(std::string s, std::vector<std::string> &wordDict)
{
    std::unordered_set<std::string> wordSet;
    std::unordered_set<int> lenSet;

    for(auto &word : wordDict) {
        wordSet.insert(word);
        lenSet.insert((int)word.size());
    }

    std::vector<std::vector<int>> record(s.size()+1, std::vector<int>(s.size()+1, 0));    //用于记录可到达信息
    std::vector<int> dp(s.size()+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= s.size(); i++)
    {
        for(int j = i-1; j >= 0; j--)
        {
            if(dp[j] && wordSet.find(s.substr(j,i-j)) != wordSet.end()) {
                dp[i] = 1;
                record[j][i] = 1;   //记录j->i表示可以从j通过某个单词转移到i
            }
        }

    }

    if(dp.back() == 0) return res;  //末尾并不可达
    dfs(s, tmp, record, 0);         //dfs寻找路径

    return res;

}





//解法二
//注意:这一题一定要注意返回的字符数组中的字符串中最后一个单词后面是没有空格的

std::vector<std::string> wordBreak(std::string s, std::vector<std::string> &wordDict)
{
    std::map<std::string, std::vector<std::string>> hash;

    return dfs(s, wordDict, hash);
}

std::vector<std::string> dfs(std::string s, std::vector<std::string> &wordDict, std::map<std::string, std::vector<std::string>> &hash)
{
    if(hash.find(s) != hash.end()) {
        return hash[s];
    }

    std::vector<std::string> res;
    if(s.size() == 0) {         //s.size()==0就表示匹配到字符串s末尾了
        res.push_back("");
        return res;
    }

    for(std::string &word : wordDict)
    {
        if(s.size() >= word.size() && s.substr(0, word.size()) == word) 
        {
            std::vector<std::string> subString = dfs(s.substr(word.size()), wordDict, hash);

            for(std::string str : subString) {
                res.push_back(word + (str.empty() ? "" : " " + str));
            }
        }
    }

    return res;
}
