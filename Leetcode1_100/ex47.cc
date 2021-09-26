//Leetcode47题
//(Permutations II) 第46题的变种,要求在46题的基础上输出排列,但不能重复,即一个排列中同一个元素只能使用一次


//方法一:使用dfs

//方法二:使用C++内置函数



#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> res;

void dfs(std::vector<int>nums, int pos);
std::vector<std::vector<int>> permuteUnique_1(std::vector<int> &nums);
std::vector<std::vector<int>> permuteUnique_2(std::vector<int> &nums);


int main(){
    std::vector<int> nums = {1,1,2};

    permuteUnique(nums);

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}




//方法一:深度优先

std::vector<std::vector<int>> permuteUnique_1(std::vector<int> &nums)
{
    if(nums.empty()) return {{}};

    sort(nums.begin(), nums.end());

    dfs(nums, 0);

    return res;

}

//看清楚参数,这里是值传递,不是传递的引用
void dfs(std::vector<int> nums, int pos){
    if(pos == nums.size()){
        res.push_back(nums);
        return;
    }    

    for(int i = pos; i < nums.size(); i++){
        if(i > pos && nums[i] == nums[pos]) continue;   //这里不再是判断nums[i]是否等于nums[i-1]了
        std::swap(nums[pos], nums[i]);
        dfs(nums, pos+1);
        //比46题少一步,已经交换的元素,不能再交换回来,参看下面的例子
    }

}

//假设给出的数组为 {1,2,2}
//第一步:得到 {1,2,2}
//第二步:交换nums[0]和nums[1],得到 {2,1,2}
//第三步:交换nums[1]和nums[2],得到 {2,2,1}
//然后回到第二步:如果将数组还原成原来的 {1,2,2} 则下一步会得到 {2,2,1}就会重复,
//但是如果不还原,则理论上应该将nums[0]和nums[2]交换, 但是if语句就会预防(2,2)之间的没意义的交换





//方法二:使用内置的输出排列的函数next_permutation
std::vector<std::vector<int>> permuteUnique_2(std::vector<int> &nums)
{
    if(nums.empty()) return {{}};
    sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> ans;
    do{
        ans.push_back(nums);
    }while(next_permutation(nums.begin(), nums.end()));

    return ans;

}