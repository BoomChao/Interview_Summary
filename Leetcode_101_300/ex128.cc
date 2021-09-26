

//Leetcode第128题 : Longest Consecutive Sequence
//最长的连续自子序列

//注意:如果序列为{1,1,2,3,3} 这样最长的子序列是{1,2,3},长度为3
//如果序列为{1,2,2,3},这样连续的最长子序列为{1,2,3},长度为3
//即出现的重复的数字不算


#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int longestConsecutive(std::vector<int> &nums);

int main(){
    std::vector<int> nums = {0,1,1,2};

    std::cout << longestConsecutive(nums) << std::endl;

    return 0;
}


//解法一:利用集合set(不推荐)

int longestConsecutive(std::vector<int> &nums)
{
    if(nums.empty()) return 0;

    std::set<int> numSet(nums.begin(), nums.end());

    int maxNum = 0;

    for(auto num : numSet)
    {
        if(!numSet.count(num-1))    //找到每个连续子序列的第一个值
        {
            int curNum = num;
            int curCount = 1;

            while(numSet.count(curNum+1)) {    //从第一个值向后计数
                curNum++;
                curCount++;
            }

            maxNum = std::max(maxNum, curCount);    //记录最大的序列数
        }

    }

    return maxNum;

}



//解法二:
//先排序,再用后一个数与前一个数做差,差等于1就继续往后判断下一个数是否也为连续数
//如果两数相等则继续往后判断下一个数是否为连续数
//否则求出最大值,继续遍历从下一个元素判断

int longestConsecutive(std::vector<int> &nums)
{
    if(nums.empty()) return 0;

    sort(nums.begin(), nums.end());

    int maxNum = 1, curCount = 1;
    for(int i = 0; i < nums.size()-1; i++)
    {
        if(nums[i+1] - nums[i] == 1) {
            curCount++;
        }
        else if(nums[i+1] == nums[i]) {
            continue;
        }
        else {
            maxNum = std::max(maxNum, curCount);
            curCount = 1;
        }

    }

    //如果是一个连续递增序列,则上述else语句就不会执行,所以这里需要取最大值
    return std::max(maxNum, curCount);   

}