

//Leetcode第217题:Contains Duplicate
//判断数组中是否包含重复的数组

//利用哈希

#include <iostream>
#include <vector>
#include <unordered_map>

bool containDuplicate(std::vector<int> &nums);


int main(){
    std::vector<int> nums = {1,2,3,1};
    std::cout << containDuplicate(nums) << std::endl;

    return 0;
}


//方法一:使用map
bool containDuplicate(std::vector<int> &nums)
{
    if(nums.empty()) return false;

    std::unordered_map<int, int> mp;

    for(auto &num:nums)
    {
        //存在重复的数
        if(mp.find(num) != mp.end()) {
            return true;
        }
        else {
            mp[num] = 1;
        }
    }

    return false;

}



//方法二:利用set
//集合(set)中的元素没有重复,并且默认按从小到大的顺序排列
bool containDuplicate(std::vector<int> &nums)
{
    return std::set<int>(nums.begin(), nums.end()).size() < nums.size();
}

