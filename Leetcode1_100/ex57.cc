//Leetcode第57题
//Insert Interval : 56题的改编版,在给定的区间数组范围内插入间隙

//思路一:将新加入的区间放入原始区间数组中,再执行56题中的合并区间;
//就只是比56题多了一步

//思路二:看解析图,由于题目已经给定区间是有序的了,所以newInterval的区间只可能有四种情况
//情况(1):新区间的首元素小于前一区间的尾元素,新区间的尾元素大于后一区间的首元素
//情况(2):新区间的首元素小于前一区间的尾元素,新区间的尾元素小于后一区间的首元素
//情况(3):新区间的首元素大于前一区间的首元素,新区间的尾元素大于后一区间的首元素
//情况(4):新区间的首元素大于前一区间的首元素,新区间的尾元素小于后一区间的首元素

//所以解题步骤如下:
//1.先将与新区间没有交集的元素添加到结果res中去
//2.接下来是对上述四种情况的判断
//3.将剩余的区间添加到结果res中去


#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals);

std::vector<std::vector<int>> insert_2(std::vector<std::vector<int>> &intervals, std::vector<int> newInterval);

int main(){
    std::vector<std::vector<int>> intervals = {{1,5}};
    std::vector<int> newInterval = {2,7};

    std::vector<std::vector<int>> ans = insert_2(intervals, newInterval);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            std::cout << ans[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


//这是56题合并间隙的代码
std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
{
    if(intervals.size() <= 1) return intervals;

    sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> res;
    res.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); i++){
        if(res.back()[1] >= intervals[i][0]) res.back()[1] = std::max(res.back()[1], intervals[i][1]);
        else res.push_back(intervals[i]);
    }

    return res;

}



//方法一:
std::vector<std::vector<int>> insert_1(std::vector<std::vector<int>> &intervals, std::vector<int> newInterval)
{
    intervals.push_back(newInterval);
    if(intervals.size() <= 1) return intervals;

    sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> res;
    res.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); i++){
        if(res.back()[1] >= intervals[i][0])  res.back()[1] = std::max(res.back()[1], intervals[i][1]);
        else res.push_back(intervals[i]);
    }

    return res;

}



//方法二:
std::vector<std::vector<int>> insert_2(std::vector<std::vector<int>> &intervals, std::vector<int> newInterval)
{
    std::vector<std::vector<int>> res;
    int index = 0;

    while(index < intervals.size() && intervals[index][1] < newInterval[0]){
        res.push_back(intervals[index++]);
    }

    while(index < intervals.size() && intervals[index][0] <= newInterval[1]){
        newInterval[0] = std::min(intervals[index][0], newInterval[0]);
        newInterval[1] = std::max(intervals[index][1], newInterval[1]);
        index++;
    }
    res.push_back(newInterval);

    while(index < intervals.size()){
        res.push_back(intervals[index++]);
    }

    return res;

}

