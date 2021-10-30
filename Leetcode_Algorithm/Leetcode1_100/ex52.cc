//Leetcode第52题
//N-Qeens II : 在51题N皇后问题的基础上输出可能的解的个数


#include <iostream>
#include <vector>

int totalNQeens(int n);
std::vector<std::vector<std::string>> solveNQeens(int n);
void solveNQeens(std::vector<std::vector<std::string>> &res, std::vector<std::string> &nQeens, int row, int &n);
bool isValid(std::vector<std::string> &nQeens, int row, int col, int &n);

int main(){

    std::cout << totalNQeens(8) << std::endl;

    return 0;
}

int totalNQeens(int n)
{
    std::vector<std::vector<std::string>> res = solveNQeens(8);

    return res.size();

}



std::vector<std::vector<std::string>> solveNQeens(int n){
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> nQeens(n, std::string(n, '.'));    //这样初始化字符串容器很巧妙,后面string(n, char) 只能是单个字符 
    solveNQeens(res, nQeens, 0, n);

    return res;

}


void solveNQeens(std::vector<std::vector<std::string>> &res, std::vector<std::string> &nQeens, int row, int &n){
    if(row == n){
        res.push_back(nQeens);
        return;
    }

    for(int col = 0; col != n; col++){
        if(isValid(nQeens, row, col, n)){
            nQeens[row][col] = 'Q';
            solveNQeens(res, nQeens, row+1, n);
            nQeens[row][col] = '.';
        }
    }

}

bool isValid(std::vector<std::string> &nQeens, int row, int col, int &n){
    //检查所在的列是否有皇后
    for(int i = 0; i != row; i++){
        if(nQeens[i][col] == 'Q') return false;
    }

    //检查45°方向是否有皇后         这里只需检查左下45°方向上是否有皇后,因为分配皇后是从第一列开始逐列往右移动分配的,当前位置的45°的右上那条线肯定不会有皇后
    for(int i = row-1, j = col-1; i>=0 && j>=0; i--, j--){
        if(nQeens[i][j] == 'Q') return false;
    }

    //检查135°方向上是否有皇后       这里只需检查左上135°方向上的是否有皇后,原因同上;   坐标原点可以理解为左下方
    for(int i = row-1, j = col+1; i>=0 && j<n; i--, j++){
        if(nQeens[i][j] == 'Q') return false;
    }

    return true;

}
