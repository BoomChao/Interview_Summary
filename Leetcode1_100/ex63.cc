//Leetcode第63题
//Unique Path II : 在62题的基础上在某些点上加了障碍,求从起点到达终点的路径数


#include <iostream>
#include <vector>

int uniquePathsWithObstacles_1(std::vector<std::vector<int>> &obstacleGrid);

int main(){
    std::vector<std::vector<int>> obstacleGrid = {{0,0,0}, {0,1,0}, {0,0,0}};

    std::cout << uniquePathsWithObstacles_1(obstacleGrid) << std::endl;


    return 0;
}



//思路一:动态规划
//考虑三种情况:
//1.当前网格点有障碍,则到该点路径数为0
//2.当前网格点位于上边界,则该点路径数为等于该点左手边点的路径数
//3.当前网格点位于左边界,则该点路径数等于该点上方点的路径数
//4.其他情况,当前点的路径数 = 左手边的点的路径数+上方点的路径数之和

int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();    //行数
    int n = obstacleGrid[0].size();     //列数

    if(m == 0 || m > 100 || n > 100) return 0;

    std::vector<std::vector<int>> dp(m, std::vector<int>(n,0));     //如果觉得这样太长,直接 int dp[m][n];
    
    if(obstacleGrid[0][0] == 1) return 0;   //起始位置是否有障碍

    dp[0][0] = 1;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(obstacleGrid[i][j] == 1)  dp[i][j] = 0;
            else if(i == 0){
                if(j > 0) dp[i][j] = dp[i][j-1];
            }
            else if(j == 0){
                if(i > 0) dp[i][j] = dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n-1];


}



//在思路一的基础上最优化

int uniquePathsWithObstacles_1(std::vector<std::vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    if(m == 0 || m > 100 || n > 100) return 0;

    std::vector<int> dp(n);

    if(obstacleGrid[0][0] == 1) return 0;

    dp[0] = 1;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(obstacleGrid[i][j] == 1) dp[j] = 0;
            else if(j > 0) dp[j] = dp[j] + dp[j-1];
        }
    }

    
    return dp[n-1];

}