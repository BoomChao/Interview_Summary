//Leetcode第39题
//Combination Sum : 在数组中找到所有能累加成目标target的所有组合


//思路:深度优先搜索


#include <iostream>
#include <vector>

void dfs(std::vector<int> &candidates, int sum, int pos, int target);
std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target);

std::vector<std::vector<int>> res;
std::vector<int> path;

int main(){
    std::vector<int> candidates = {2,3,6,7};  int target = 7;
    // std::vector<int> candidates = {2,3,5};  int target = 8;
    combinationSum(candidates, target);

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}


std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target)
{
    dfs(candidates, 0, 0, target);
    
    return res;     //这里不写返回值会有段错误

}


//深度优先搜索
void dfs(std::vector<int> &candidates, int sum, int pos, int target)
{
    if(sum == target){
        res.push_back(path);
        return;
    }
    // else if(sum > target){   //这三行可不写,因为sum不可能大于target,下面的if语句中进入到该递归函数的条件就是sum<=target
    //     return;
    // }

    for(int i = pos; i < candidates.size(); i++){
        int val = candidates[i];
        if(sum+val <= target){
            path.push_back(val);
            dfs(candidates, sum+val, i ,target);
            path.pop_back();
        }
    }

}