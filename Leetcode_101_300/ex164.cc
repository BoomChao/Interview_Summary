



//Leetcode第164题:给出一个无序的数组,找出其排序后的最大间距

//思路:题目要求是线性的时间和空间,利用桶排序


#include <iostream>
#include <vector>
#include <climits>

int maximumGap(std::vector<int> &nums);
int mapTpBucket(long num, int len, int min, int max);


int main(){
    std::vector<int> nums = {1, 10};
    std::cout << maximumGap(nums) << std::endl;

    return 0;
}


int maximumGap(std::vector<int> &nums)
{
    if(nums.size() < 2) return 0;

    int len = nums.size();
    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    //找到最大值和最小值
    for(int i = 0; i < len; i++)
    {
        minVal = std::min(nums[i], minVal);
        maxVal = std::max(nums[i], maxVal);
    }

    //最小值和最大值相等则说说明数组中所有元素都相等,则间距为0
    if(maxVal == minVal) return 0;    

    //准备n+1个桶
    std::vector<int> hasNum(len+1, 0);   //数组中元素值为1就代表桶中有元素,为0就代表桶中没有元素
    std::vector<int> mins(len+1);        //每个桶中的最小值  比如:mins[1]代表的就是桶1的最小值
    std::vector<int> maxs(len+1);        //每个桶中的最大值

    //计算每个桶中的最小值和最大值
    for(int i = 0; i < len; i++)
    {
        int bid = mapTpBucket(nums[i], len, minVal, maxVal);
        mins[bid] = hasNum[bid] ? std::min(mins[bid], nums[i]) : nums[i];
        maxs[bid] = hasNum[bid] ? std::max(maxs[bid], nums[i]) : nums[i];
        hasNum[bid] = 1;
    }

    int res = 0;
    int preMax = maxs[0];         //第一个桶一定不为空,因为一定有一个最小值
    for(int i = 1; i <= len; i++)
    {
        //桶非空
        if(hasNum[i]) {
            res = std::max(res, mins[i] - preMax);
            preMax = maxs[i];
        }

    }

    return res;

}


//将num映射到相应的桶中

int mapTpBucket(long num, long len, long min, long max)
{
    return (int)((num - min)*len/(max - min));      //注意这里涉及到了相乘,如果使用int可能会溢出,使用long
}
