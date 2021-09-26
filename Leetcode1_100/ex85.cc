
//Leetcode第85题
//Maximal Rectangle : 在给定的二维矩阵中找到最大的矩形的面积


//思路:
//1.仿照84题的解法,将每一行都看做一个柱形图,寻找最大的柱形图的面积
//2.注意每一行的柱形图的长度的计算,当每列都是连续的1时才是累加.否则将该行的当前位置的柱体的高度置为0



#include <iostream>
#include <vector>
#include <stack>

int maximalRectangle(std::vector<std::vector<char>> &matrix);
int largestRectangle(std::vector<int> &heights);

int main(){
    std::vector<std::vector<char>> matrix = {{'1','0','1','0','0'}, {'1','0','1','1','1'}, {'1','1','1','1','1'}, {'1','0','0','1','0'}};

    std::cout << maximalRectangle(matrix) << std::endl;


    return 0;
}

int maximalRectangle(std::vector<std::vector<char>> &matrix)
{
    if(matrix.size() == 0) return 0;    //矩阵为空,直接返回

    int col = matrix[0].size();
    std::vector<int> height(col, 0);
    int max = 0;

    for(auto &row : matrix){
        for(int i = 0; i < col; i++){
            height[i] = (row[i] == '1') ? height[i]+1 : 0;    //注意这里当前行的每根柱高度height的求法
        }

        int res = largestRectangle(height);
        if(res > max) max = res;
    }

    return max;

}



int largestRectangle(std::vector<int> &heights)
{
    heights.push_back(0);   //注:在heights末尾添加一个0是为了让所有元素都出栈; 如 heights = {1}这种只有一个元素的情况,下面的循环会输出0
    int res = 0;

    std::stack<int> indexes;    //定义单调栈用来存放其下标
    for(int i = 0; i < heights.size(); i++){
        while(!indexes.empty() && heights[indexes.top()] > heights[i]){
            int h = heights[indexes.top()];
            indexes.pop();      //出栈
            int l = indexes.empty() ? -1 : indexes.top();
            res = std::max(res, h*(i-l-1));
        }

        indexes.push(i);
    }

    return res;

}