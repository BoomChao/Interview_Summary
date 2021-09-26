

//Leetcode第131题:Palindrome Partitioning
//回文数切割


//思路:深度优先
//对于字符串"aab",先判断a是否为回文字符,发现满足,则加入到par中,依次下去,第一次res中就加入了{"a","a","b"}
//接下来再次遍历,发现"aa"也满足,继续遍历,则res就加入了{"aa","b"}

std::vector<std::vector<std::string>> res;
std::vector<std::string> par;

std::vector<std::vector<std::string>> partition(std::string s)
{
    dfs(s, 0);

    return res;
}

int minCut(std::string s)
{
    dfs(s, 0);

    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }

}


void dfs(std::string &s, int start)
{
    if(start == s.size()) {
        res.push_back(par);
        return;
    }

    for(int i = start; i < s.size(); i++)
    {
        if(isPalindrome(s, start, i))
        {
            par.push_back(s.substr(start, i - start + 1));
            dfs(s, i + 1);
            par.pop_back();
        }

    }

}

bool isPalindrome(std::string str, int start, int end)
{
    while(start < end)
    {
        if(str[start++] != str[end--]) return false;
    }

    return true;

}