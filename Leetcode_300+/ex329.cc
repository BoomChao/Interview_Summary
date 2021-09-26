

//Leetcode第329题:Longest Increasing Path in a Matrix
//计算矩阵中最长的递增路径

//思路:回溯


#include <iostream>
#include <vector>

int rows;
int cols;
std::vector<std::vector<int>> f;

int dfs(std::vector<std::vector<int>> &M, int r, int c)
{
    //f[r][c]记录的是从M[r][c]出发能到达的最长路径长度
    if(f[r][c] > 0) return f[r][c];     //如果之前已经计算过了就直接返回

    int res = 1;
    if(r-1 >= 0 && M[r-1][c] > M[r][c]) res = std::max(res, 1 + dfs(M, r-1, c));    //上
    if(c+1 < cols && M[r][c+1] > M[r][c]) res = std::max(res, 1 + dfs(M, r, c+1));  //右
    if(r+1 < rows && M[r+1][c] > M[r][c]) res = std::max(res, 1 + dfs(M, r+1, c));  //下
    if(c-1 >= 0 && M[r][c-1] > M[r][c]) res = std::max(res, 1 + dfs(M, r, c-1));    //左

    f[r][c] = res;

    return f[r][c];
}


int longestIncreasingPath(std::vector<std::vector<int>> &matrix)
{
    if(matrix.empty()) return 0;
    
    rows = matrix.size();
    cols = matrix[0].size();
    f = std::vector<std::vector<int>> (rows, std::vector<int>(cols, 0));

    int result = 0;
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            result = std::max(result, dfs(matrix, r, c));
        }
    }

    return result;
}


int main(){
    std::vector<std::vector<int>> matrix = {{9,9,4}, {6,6,8}, {2,1,1}};
    std::cout << longestIncreasingPath(matrix) << std::endl;

    return 0;
}
