
//Leetcode第174题:Dungeon Game
//地牢游戏

//动态规划:
//注意这一题动态规划计算方向是从右下到左上

int calculateMinimumHP(std::vector<std::vector<int>> &dungeon)
{
    if(dungeon.empty()) return 0;

    int m = dungeon.size();
    int n = dungeon[0].size();
    std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, INT_MAX));
    dp[m-1][n] = 1;
    dp[m][n-1] = 1;

    for(int i = m-1; i >= 0; i--) 
    {
        for(int j = n-1; j >= 0; j--) 
        {
            int need = std::min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
            dp[i][j] = (need <= 0 ? 1 : need);
        }
    }

    return dp[0][0];
}
