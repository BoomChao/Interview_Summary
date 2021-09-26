//Leetcode第36题
//(Permutations:组合,序列):给出一个整数数组,返回其中所有可能元素的组合
//如:数组为[1,2,3]
//结果为: {1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,1,2}, {3,2,1}


//思路:典型的深度搜索(dfs问题)
//方法一:使用dfs(重点掌握)
//方法二:使用内置的C++函数(了解即可)


#include <iostream>
#include <vector>

std::vector<std::vector<int>> res;

void dfs(std::vector<int> &nums);
std::vector<std::vector<int>> permute(std::vector<int> &nums);

int main(){
    std::vector<int> nums = {1,2,3};
    permute(nums);

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}





//方法一:深度优先

std::vector<std::vector<int>> permute(std::vector<int> &nums)
{
    if(nums.size() == 0) return {{}};   //空数组直接返回空

    sort(nums.begin(), nums.end());

    dfs(nums, 0);

    return res;

}


void dfs(std::vector<int> &nums, int pos){
    if(pos == nums.size()){
        res.push_back(nums);
        return;
    }

    for(int i = pos; i < nums.size(); i++){
        std::swap(nums[i], nums[pos]);
        dfs(nums, pos+1);
        std::swap(nums[i], nums[pos]);
    }

}




//方法二:使用内置的C++函数

std::vector<std::vector<int>> permute(std::vector<int> &nums)
{
    std::vector<std::vector<int>> ans;
    sort(nums.begin(), num.end());
    do{
        ans.push_back(nums);

    }while(next_permutation(nums.begin(), nums.end()));

    return ans;

}
