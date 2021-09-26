
//Leetcode第77题 : Combinations
//给出一个数n和k,求出所有1~n中的所有k个数的组合


//思路:深度优先
//解法一:递归

std::vector<std::vector<int>> combine(int n, int k)
{
    if(k <= 0 || n <= 0) return res;
    std::vector<int> tmp;
    dfs(n, k, 1, tmp);

    return res;

}

void dfs(int n, int k, int pos, std::vector<int> &tmp)
{
    if(tmp.size() == k){
        res.push_back(tmp);
        return;
    }

    for(int i = pos; i <= n; i++)
    {
        tmp.push_back(i);
        dfs(n, k, i+1, tmp);
        tmp.pop_back();
    }
}




//方法二:使用迭代

std::vector<std::vector<int>> combine(int n, int k)
{
    std::vector<std::vector<int>> res;
    int i = 0;
    std::vector<int> p(k, 0);
    while(i >= 0){
        p[i]++;
        if(p[i] > n) i--;
        else if(i == k-1) res.push_back(p);
        else{
            ++i;
            p[i] = p[i-1];
        }
    }

    return res;

}