//Leetcode第56题    
//Merge Intervals : 合并相差的距离

//思路:
//1.利用vector将二维数组排好序,则首先将数组中添加第一个区间
//2.接下来循环遍历到最后一个区间,如果当前结果中的之后一个区间的第二个元素大于当前位置的区间的第一个元素的值,
//则将结果中的最后一个区间的末尾值置为(末尾值和当前区间的末尾值的最大值)
//3.如果结果中的最后一个区间的末尾值小于当前区间的第一个元素的值,则将当前区间整个添加到结果中


//注意vector二维数组排序的结果:先将数组中第一个元素按顺序排列,如果是第一个元素相同,则按照第第二个元素排列
//如: 排序数组为 {{1,2}, {1,0}, {3,4}
//排序结果为: {{1,0}, {1,2}, {3,4}}



#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals);

int main(){
    std::vector<std::vector<int>> intervals = {{1,4}, {0,3}, {0,2}};

    std::vector<std::vector<int>> ans = merge(intervals);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            std::cout << ans[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

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