

//Leetcode第64题
//Minimun Path Sum : 最短路径和


//思路:动态规划

//递归搜索
//1.如果每到最后一行也没到最后一列,则下一步的走法选择向右或者向下按照与当前值的和最小来选择
//2.如果到了最后一行,则只能向右走
//3.如果到了最后一列,则只能向下走


//这种方法会超时
int minPathSum(std::vector<std::vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();
    return dfs(0, 0, grid, rows, cols);

}


int dfs(int row, int col, std::vector<std::vector<int>> &grid, int m, int n){
    if(row == m-1 && col == n-1){
        return grid[row][col];
    }


    if(row < m-1 && col < n-1){
        return grid[row][col] + std::min(dfs(row, col+1, grid, m, n), dfs(row+1, col, grid, m, n));
    }

    if(row < m-1){
        return grid[row][col] + dfs(row+1, col, grid, m, n);
    }

    if(col < n-1){
        return grid[row][col] + dfs(row, col+1, grid, m, n);
    }

}



//思路:动态规划
//定义一个二维数组sum,sum[i][j]代表到(i,j)位置的最短路径
//1.首先考虑两种情况,对于第一行的所有元素,sum[0][j] = sum[j-1] + gird[0][j]     这就要求j>0,且sum数组的的第一个元素为grid[0][0]
//2.对于第一列的情况,sum[i][0] = sum[i-1][0] + grid[i][0], 得出第一列所有元素的路径
//3.其余情况下,sum[i][j]等于左手边的元素与上方元素的最小值 + grid[i][j]
//4.最终返回sum[m-1][n-1]即可

int minPathSum(std::vector<std::vector<int>> &grid)
{
    if(grid.empty()) return 0;

    int row = grid.size();
    int col = grid[0].size();
    std::vector<std::vector<int>> dp(row, std::vector<int>(col, 0));
    dp[0][0] = grid[0][0];

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(i > 0 && j > 0) dp[i][j] = grid[i][j] + std::min(dp[i-1][j], dp[i][j-1]);
            else if(i == 0 &&j > 0) dp[i][j] = grid[i][j] + dp[i][j-1];
            else if(i > 0 && j == 0) dp[i][j] = grid[i][j] + dp[i-1][j];
        }
        std::cout << std::endl;
    }

    return dp[row-1][col-1];
}


//对上面思路的简化(所需的额外空间减少为O(n))

int minPathSum_2(std::vector<std::vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    std::vector<int> cur(n, 0);
    cur[0] = grid[0][0];

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // 下面三个判断可以看出对i=0,j=0 我们不做任何判断
            if(i > 0 && j > 0) cur[j] = std::min(cur[j-1], cur[j]) + grid[i][j];
            else if(i == 0 && j > 0) cur[j] = cur[j-1] + grid[i][j];
            else if(i > 0 && j == 0) cur[j] = cur[j] + grid[i][j];
        }
    }

    return cur[n-1];
}



//更加一种简便的方法,直接在原来给定的数组上操作(这种方法会修改原数组,面试中需要询问面试官是否可以修改原数组)

int minPathSum_3(std::vector<std::vector<int>> &grid)
{
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(i != 0 && j != 0) grid[i][j] += std::min(grid[i-1][j], grid[i][j-1]);    //if语句中的判断条件也可以写成上面解法二的那种
            else if(i == 0 && j != 0) grid[i][j] += grid[i][j-1];                       //当然也可以写成这种
            else if(j == 0 && i != 0) grid[i][j] += grid[i-1][j];  
        }
    }

    return grid[grid.size()-1][grid[0].size()-1];

}