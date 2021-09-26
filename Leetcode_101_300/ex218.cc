

//Leetcode第218题 : The Skyline Problem
//天际线问题


//思路:使用multiset


#include <iostream>
#include <vector>
#include <set>

std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>> &buildings);

int main(){
    std::vector<std::vector<int>> buildings = {{0,2,3}, {2,5,3}};

    std::vector<std::vector<int>> res = getSkyline(buildings);

    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++)
        {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}



std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>> &buildings)
{
    std::vector<std::vector<int>> ans;
    if(buildings.empty()) return ans;
    
    std::multiset<std::vector<int>> corner;
    std::multiset<int> height;                  //注意:set中元素的插入是有顺序的,是按照从小到大的顺序排列的
    height.insert(0);

    for(auto &bd : buildings) 
    {
        corner.insert({bd[0], -bd[2]});     //左端点高度用负号表示
        corner.insert({bd[1], bd[2]});      //右端点高度用正号表示
    }

    std::vector<int> pre(2,0);  //记录前一个拐角
    for(auto &cn : corner)
    {
        if(cn[1] < 0) {     
            height.insert(-cn[1]);  //如果是左端点则插入
        }
        else {
            height.erase(height.find(cn[1]));   //右端点就删除
        }

        int maxH = *height.rbegin();    //如果使用.end()返回的是最后一个元素的下一位置的迭代器
        if(maxH != pre[1])              //高度不相等说明遇到拐角
        {
            pre[0] = cn[0];
            pre[1] = maxH;
            ans.push_back(pre);
        } 
    }

    return ans;
}
