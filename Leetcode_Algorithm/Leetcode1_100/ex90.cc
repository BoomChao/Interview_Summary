

//Leetcode第90题
//Subsets II : 给出一个可能存在重复元素的数组,返回其所有组合,要求这些组合不能有重复的


//思路参考第78题
//需要注意题目没说这个数组是有序的,操作前先排序


#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> subsets(std::vector<int> &nums);
void dfs(std::vector<int> &nums, int pos);

std::vector<std::vector<int>> res;
std::vector<int> tmp;

int main(){
    std::vector<int> nums = {4,4,4,1,4};

    subsets(nums);

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;

}


std::vector<std::vector<int>> subsets(std::vector<int> &nums)
{
    sort(nums.begin(), nums.end());    //注意:没有说这个数组是一个有序数组,需要排序

    dfs(nums, 0);

    return res;

}


void dfs(std::vector<int> &nums, int pos){
    res.push_back(tmp);

    for(int i = pos; i < nums.size(); i++){
        if(i > pos && nums[i] == nums[i-1]) continue;
        tmp.push_back(nums[i]);
        dfs(nums, i+1);
        tmp.pop_back();
    }

}