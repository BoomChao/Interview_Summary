

//Leetcode第120题: Triangle
//数字三角形最小路径和

//思路:动态规划
//从底处向上求解,从倒数第二行开始,本行节点到最后一行的最小和等于该节点的数据加上下面左右两个数据中最小的一个
//不使用用额外空间,直接将最小路径和存储到原数组中去


#include <iostream>
#include <vector>

int minimumTotal(std::vector<std::vector<int>> &triangle);

int main(){
    std::vector<std::vector<int>> triangle = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};

    std::cout << minimumTotal(triangle) << std::endl;

    return 0;
}


int minimumTotal(std::vector<std::vector<int>> &triangle)
{
    if(triangle.empty()) return 0;

    for(int i = triangle.size()-2; i >= 0; i--)
    {
        for(int j = 0; j < triangle[i].size(); j++) {
            triangle[i][j] = std::min(triangle[i+1][j], triangle[i+1][j+1]) + triangle[i][j];
        }
    }

    return triangle[0][0];

}