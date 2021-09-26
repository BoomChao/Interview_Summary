

//Leetcode第51题
//N-Qeens:N皇后问题


#include <iostream>
#include <vector>

std::vector<std::vector<std::string>> solveNQeens(int n);
void solveNQeens(std::vector<std::vector<std::string>> &res, std::vector<std::string> &nQeens, int row, int &n);
bool isValid(std::vector<std::string> &nQeens, int row, int col, int &n);

int main(){
    std::vector<std::vector<std::string>> res = solveNQeens(4);

    // std::cout << res.size() << std::endl;
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            std::cout << res[i][j] << " " << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}


std::vector<std::vector<std::string>> solveNQeens(int n)
{
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> nQeens(n, std::string(n, '.'));    //这样初始化字符串容器很巧妙,后面string(n, char) 只能是单个字符 
    solveNQeens(res, nQeens, 0, n);

    return res;

}


void solveNQeens(std::vector<std::vector<std::string>> &res, std::vector<std::string> &nQeens, int row, int &n) {
    if(row == n) {
        res.push_back(nQeens);
        return ;
    }

    for(int col = 0; col != n; col++)
    {
        if(isValid(nQeens, row, col, n)) {
            nQeens[row][col] = 'Q';
            solveNQeens(res, nQeens, row+1, n);
            nQeens[row][col] = '.';
        }
    }

}

bool isValid(std::vector<std::string> &nQeens, int row, int col, int &n) {
    //检查所在的列是否有皇后
    for(int i = 0; i != row; i++) {
        if(nQeens[i][col] == 'Q') return false;
    }

    //检查45°方向是否有皇后         这里只需检查左边上45°方向上是否有皇后,因为分配皇后是逐行开始分配的,所以下面没到的行是一定没有皇后的,只需检查上面已经遍历过的行
    for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
        if(nQeens[i][j] == 'Q') return false;
    }

    //检查135°方向上是否有皇后       这里只需检查右边上135°方向上的是否有皇后,原因同上;   坐标原点可以理解为左上方
    for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
        if(nQeens[i][j] == 'Q') return false;
    }

    return true;
}



//解法二:思路很巧
//使用两个矩阵分别记录皇后在两条对角线上的位置

std::vector<std::vector<std::string>> solveNQeens(int n)
{
    std::vector<std::vector<std::string>> ans;
    if(n == 0) {
        return ans;
    }

    std::vector<std::string> board(n, std::string(n, '.'));
    std::vector<int> column(n, 0), ldiag(2*n-1, 0), rdiag(2*n-1, 0);    //ldiag代表的是从左上角到右下角的对角线,rdiag代表的是左下角到右上角的对角线

    dfs(ans, board, column, ldiag, rdiag, 0, n);
    
    return ans;
}

void dfs(std::vector<std::vector<std::string>> &ans, std::vector<std::string> &board, std::vector<int> &column, std::vector<int> &ldiag, std::vector<int> &rdiag, int row, int n)
{
    if(row == n) {
        ans.push_back(board);
        return ; 
    }

    for(int i = 0; i < n; i++)
    {
        if(column[i] || ldiag[n-row+i-1] || rdiag[row+i]) {
            continue;
        }

        //修改当前状态
        board[row][i] = 'Q';
        column[i] = ldiag[n-row+i-1] = rdiag[row+i] = 1;    //重点就是这里,需要找到当前位置与左右对角线的关系

        //递归子节点
        dfs(ans, board, column, ldiag, rdiag, row+1, n);

        //回改当前节点状态
        column[i] = ldiag[n-row+i-1] = rdiag[row+i] = 0;
    }

}

