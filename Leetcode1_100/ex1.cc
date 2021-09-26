

//Leetcode第一题:two Sum
//计算两数之和

//思路:利用hash

#include <iostream>
#include <map>
#include <vector>

std::vector<int> twoSum(std::vector<int> &nums, int target);

int main(){
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 18;
    std::vector<int> res = twoSum(nums, target);

    for(int i = 0; i < res.size(); i++) std::cout << res[i] << " ";
    std::cout << std::endl;

    return 0;
}


std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::unordered_map<int, int> hash;

    for(int i = 0; i < nums.size(); i++)
    {
        int numToFind = target - nums[i];
     
        if(hash.find(numToFind) != hash.end()) {
            return {hash[numToFind], i};
        } 

        hash[nums[i]] = i;
    }

    return {};

}

