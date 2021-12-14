


/*
    面试题47:礼物的最大价值
    典型的动态规划
*/


#include <iostream>
#include <cmath>

int getMaxValue_solution1(const int *values, int rows, int cols);
int getMaxValue_solution2(const int *values, int rows, int cols);


int main(){
    int values[] = {1,10,3,8, 12,2,9,6, 5,7,4,11, 3,7,16,5};

    std::cout << getMaxValue_solution1(values, 4, 4) << std::endl;
    std::cout << getMaxValue_solution2(values, 4, 4) << std::endl;

    return 0;
}



int getMaxValue_solution1(const int *values, int rows, int cols)
{
    if(values == nullptr || rows <= 0 || cols <= 0) return 0;

    int **maxValues = new int*[rows];
    for(int i = 0; i < rows; i++) {
        maxValues[i] = new int[cols];
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            int left = 0;
            int up = 0;
            if(i > 0) up = maxValues[i-1][j];
            if(j > 0) left = maxValues[i][j-1];

            maxValues[i][j] = std::max(left, up) + values[i*cols+j];
        }
    }

    int maxValue = maxValues[rows-1][cols-1];

    for(int i = 0; i < rows; i++) {
        delete[] maxValues[i];
    }

    delete[] maxValues;

    return maxValue;

}



//对上面解法的优化

int getMaxValue_solution2(const int *values, int rows, int cols)
{
    if(values == nullptr || rows <= 0 || cols <= 0) return 0;

    int *maxValues = new int[cols];

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            int left = 0;
            int up = 0;
            if(i > 0) up = maxValues[j];
            if(j > 0) left = maxValues[j-1];

            maxValues[j] = std::max(left, up) + values[i*cols+j];
        }
    }

    int maxValue = maxValues[cols-1];

    delete[] maxValues;

    return maxValue;
}


//太过复杂(下面解法更好)

//版本一:dp数组等于原来的数组维数

int maxValue(std::vector<std::vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

    dp[0][0] = grid[0][0];

    for(int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    for(int i = 1; i < m; i++) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    } 

    return dp[m-1][n-1];
}


//版本二:
//从这里可以看成,如果将dp数组移动一位,则是为了更好的处理边界条件,这样更加方便
//如果不移动dp数组,则边界条件(也就是动态规划的base更好处理),否则不是不能做,处理base case就会像上面版本一一样麻烦

int maxValue(std::vector<std::vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for(int i = 1; i <= m ;i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
        }
    }

    return dp[m][n];
}


//版本三:压缩空间

int maxValue(std::vector<std::vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    std::vector<int> dp(n + 1, 0);

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            dp[j] = std::max(dp[j], dp[j-1]) + grid[i-1][j-1];
        }
    }

    return dp[n];
}

