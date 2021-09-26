//Leetcode 第59题
//Spiral Matrix II : 给定一个整数n,生成n阶的螺旋矩阵


//思路:按照之前顺时针输出矩阵的程序为例,将子函数中的取值操作改为赋值操作


#include <iostream>
#include <vector>

std::vector<std::vector<int>> generateMatrix(int n);
void spOrder(std::vector<std::vector<int>> &matrix, int row, int col, int start);


int main(){
    std::vector<std::vector<int>> ans = generateMatrix(3);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            std::cout << ans[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


std::vector<std::vector<int>> generateMatrix(int n)
{
    int col, row;
    row = col = n;
    int start = 0;
    std::vector<int> tmp(n, 0);
    std::vector<std::vector<int>> res(n, tmp);     

    while(row>2*start && col>2*start){
        spOrder(res, row, col, start);
        start++;
    }

    return res;

}

void spOrder(std::vector<std::vector<int>> &matrix, int row, int col, int start){
    int endX = row-1-start;
    int endY = col-1-start;

    static int count = 1;   //定义一个静态局部变量,这样下次调用该函数i的值就保持就上一次调用的值开始累加
    //从左到右对矩阵赋值
    for(int i = start; i <= endY; i++){
        matrix[start][i] = count++;
    }

    //从上到下对矩阵赋值
    if(start < endX){
        for(int i = start+1; i <= endX; i++){
            matrix[i][endY] = count++;
        }
    }

    //从右到左对矩阵赋值
    if(start < endX && start < endY){
        for(int i = endY-1; i>=start; i--){
            matrix[endX][i] = count++;
        }
    }

    //从下到上对矩阵赋值
    if(start < endX-1 && start < endY){
        for(int i = endX-1; i >= start+1; i--){
            matrix[i][start] = count++;
        }
    }


}