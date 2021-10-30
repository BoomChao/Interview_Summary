

//Leetcode第216题 : Combination Sum III
//在 1~9 之间找到能组成n的k个数,每个数只能使用一次

//思路:回溯


#include <iostream>
#include <vector>

std::vector<std::vector<int>> combinationSum3(int k, int n);
void combinationSum3Core(int target, int index, std::vector<int> &path, std::vector<std::vector<int>> &res, int k);

int main(){

    std::vector<std::vector<int>> ans = combinationSum3(3, 2);

    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            std::cout << ans[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

std::vector<std::vector<int>> combinationSum3(int k, int n)
{
    std::vector<std::vector<int>> res;
    std::vector<int> path;

    combinationSum3Core(n, 1, path, res, k);

    return res;

}


void combinationSum3Core(int target, int index, std::vector<int> &path, std::vector<std::vector<int>> &res, int k)
{
    //找到了等于n的k个数就返回
    if(target == 0 && path.size() == k) {
        res.push_back(path);
        return;
    }

    //比如现在target = 3, 但是path = {1,2,3,4} 后面path再添加元素也只可能会比k大,所以这种情况就就直接返回
    if(!path.empty() && target < path.back()) {
        return;
    }

    for(int i = index; i <= 9; i++)
    {
        path.push_back(i);
        combinationSum3Core(target-i, i+1, path, res, k);
        path.pop_back();
    }

}

