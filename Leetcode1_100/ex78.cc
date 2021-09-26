

//Leetcode第78题  
//Subsets : 求出数组的所有子集
//第77题的改编版本

//思路:深度优先搜索(dfs)


#include <iostream>
#include <vector>

std::vector<std::vector<int>> res;
std::vector<int> tmp;

std::vector<std::vector<int>> subsets(std::vector<int> &nums);
void dfs(std::vector<int>&nums, int pos);



int main(){
    std::vector<int> nums = {1,2,3};
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
    dfs(nums, 0);    

    return res;

}

void dfs(std::vector<int>&nums, int pos){
    res.push_back(tmp);                     //第一次调用该函数空集合就包含进去了; 附:STL中的容器都有一个默认构造函数,用于构造一个没有任何元素的空容器

    for(int i = pos; i < nums.size(); i++){
        tmp.push_back(nums[i]);
        dfs(nums, i+1);
        tmp.pop_back();
    }

}