//Leetcode第40题
//第39题的变种,39题要求找出所有组合,一个元素可以使用多次
//该题要求数组每个元素只能使用一次


#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::vector<int>> res;
std::vector<int> path;

std::vector<std::vector<int>> combinationSum2(std::vector<int>&candidates, int target);
void dfs(std::vector<int> &candidates, int sum, int pos, int target);

int main(){
    std::vector<int> candidates = {10,1,2,7,6,1,5};    int target = 8;
    combinationSum2(candidates, target);

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}


std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());    //先要进行排序
    dfs(candidates, 0, 0, target);

    return res;

}


void dfs(std::vector<int> &candidates, int sum, int pos, int target){
    if(sum == target){
        res.push_back(path);
        return;
    }else if(sum > target){
        return;
    }

    for(int i = pos; i < candidates.size(); i++){
            int val = candidates[i];
            if(val + sum <= target){
                if(i > pos && candidates[i] == candidates[i-1]) continue;   //这是关键.与39题的差别主要在这一步; 其作用是判断同一层的连续两个相邻节点不能相同
                path.push_back(val);                                    
                dfs(candidates, sum+val, i+1, target);     //下一次遍历就从当前元素的下一个元素开始
                path.pop_back();
        }
    }

}
