

//Leetcode第130题: Surrounded Region
//环绕区域


//思路:
//设置一个与board相同大小的矩阵flag,用来标识board,先将flag全部置为0
//注意到只有当边界存在'O'时,里面的区域才有可能不被置为'X',因此需要从边缘出发找到所有与'0'相连的区域并将flag置为1
//遍历board,将flag为0的区域全部置为'X'


#include <iostream>
#include <vector>

void solve(std::vector<std::vector<char>> &board);
void dfs(std::vector<std::vector<char>> &board, std::vector<std::vector<int>> &flag, int i, int j);

int main(){
    std::vector<std::vector<char>> board = {{'X','X','X','X'}, {'X','O','O','X'}, {'X','X','O','X'}, {'X','O','X','X'}};

    solve(board);

    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++)
        std::cout << board[i][j] << " ";
        std::cout << std::endl;
    }

    return 0;
}


void solve(std::vector<std::vector<char>> &board)
{
    if(board.empty() || board[0].empty()) return;

    std::vector<std::vector<int>> flag(board.size(), std::vector<int>(board[0].size(), 0));

    int rows = board.size();
    int cols = board[0].size();

    //第一行和最后一行
    for(int j = 0; j < cols; j++) 
    {
        //第一行
        if(board[0][j] == 'O') {
            dfs(board, flag, 0, j);    
        }

        //最后一行
        if(board[rows-1][j] == 'O') {
            dfs(board, flag, rows - 1, j);
        }

    }

    //第一列和最后一列
    //上面的遍历第一行和最后一行的过程中已经遍历过了第一列的第一个元素和最后一个元素
    //以及最最后一列的第一个元素和最后一个元素,所以这里i的范围为[1, rows-2];
    for(int i = 1; i < rows - 1; i++)
    {
        //第一列
        if(board[i][0] == 'O') {
            dfs(board, flag, i, 0);
        }

        //最后一列
        if(board[i][cols-1] == 'O') {
            dfs(board, flag, i, cols - 1);
        }

    }


    //填充
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(flag[i][j] == 0) {
                board[i][j] = 'X';
            }
        }
    }


}

void dfs(std::vector<std::vector<char>> &board, std::vector<std::vector<int>> &flag, int i, int j)
{
    if(i >= 0 && i < board.size() && j >= 0 && j < board[0].size()) 
    {
        //如果之前遍历过了发现是'O',已经将其标记为1 或者 当前字符为'X' 这两种情况直接返回
        if(flag[i][j] == 1 || board[i][j] == 'X') return;
        
        flag[i][j] = 1;
        dfs(board, flag, i + 1, j);     //上
        dfs(board, flag, i - 1, j);     //下
        dfs(board, flag, i, j - 1);     //左
        dfs(board, flag, i, j + 1);     //右    
    }

    return;

}