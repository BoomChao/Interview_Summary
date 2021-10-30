//Leetcode第15题
//求出数组中可能等于给定的数的三个数的所有的组合


#include <iostream>
#include <algorithm>    //使用sort函数,需要包括该头文件
#include <vector>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums);

int main(){
    std::vector<int> nums = {-1, 0, 1, 2, -1, 4};
    std::vector<std::vector<int>> res;      //res就当成二维数组
    res = threeSum(nums);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < (res[i].size()); j++){
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}


//利用三个指针,i指向当前元素,l指向当前元素的后一个元素,r指向末尾元素;  一次遍历过程中将l往后移或者将r往前移
std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    sort(nums.begin(), nums.end());     //需要先将数组排序
    std::vector<std::vector<int>> res;

    for(int i = 0; i < nums.size(); i++){
        if(i > 0 && nums[i]==nums[i-1]) continue;   //剔除掉重复的起始数
        int l = i+1, r = nums.size()-1;
        while(l < r){
            if(nums[i] + nums[l] + nums[r] == 0){
                res.push_back(std::vector<int> {nums[i], nums[l], nums[r]});
                while(l < r && nums[l] == nums[l+1]) l++;   //比如这时找到了 -1 0 1, 假设1的下标为5,这一步是为了避免num[4]也等于5
                while(l < r && nums[r] == nums[r-1]) r--;   //                   , 假设0的下标为2,这一步是为了避免num[3]也等于2
                l++;
                r--;
            }
            else if(nums[i] + nums[l] + nums[r] < 0)  l++;
            else  r--;
        }

    }

    return res;

}