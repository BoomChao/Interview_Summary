

//Leetcode第221题
//Maximal Square : 在给定矩阵中求最大的正方形的面积


//思路:动态规划
//1.定义一个与原矩阵维度相同的数组dp来记录每个位置能构成的最大正方形边长,dp[i][j]表示matrix[i][j]位置所能构成的最大正方形的边长
//2.如果matrix[i][j]为1,则当前位置dp[i][j]能构成的最大正方形边长就等于当前位置左边,左上角,上边的dp的最小值+1
//3.否则dp[i][j]就等于0
//4.将每处的位置构成的最大的正方形的边长与最大值比较即可


#include <iostream>
#include <vector>

int maximalSquare(std::vector<std::vector<char>> &matrix);

int main(){
    std::vector<std::vector<char>> matrix = {{'1','0','1','0','0'}, {'1','0','1','1','1'}, {'1','1','1','1','1'}, {'1','0','0','1','0'}};

    std::cout << maximalSquare(matrix) << std::endl;


    return 0;
}


int maximalSquare(std::vector<std::vector<char>> &matrix)
{
    if(matrix.empty()) return 0;
    
    int row = matrix.size();
    int col = matrix[0].size();
    int dp[row][col];
    int max = 0;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(i == 0 || j == 0 || matrix[i][j] == '0') dp[i][j] = matrix[i][j]-'0';   //首行首列构成的最大面积就是当前数的数值
            else{                                                                      //元素为0的位置构成的最大面积为0
                dp[i][j] = std::min(std::min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
            }
            if(dp[i][j] > max) max = dp[i][j];      //这个判定需要放在外面,以防矩阵只有一行 如 {{1,0,1}}
        }

    }

    return max*max;

}