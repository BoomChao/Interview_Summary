
//Leetcode第36题
//valid SudoKu:判断是否是有效的数独


//思路:定义三个数组分别来表示行,列,以及子3x3矩阵是否有重复元素  (由于矩阵是从0开始计数的,故将数独中的元素都减去1)
//比如第一行一列元素为5,则将row数组的row[0][4]置为1, 表示4这个元素在第0行已经出现了 
//将col[0][4]置为1,表示4这个元素在第0列已经出现了
//方块的索引规则为 k=(i/3)*3+j/3,表示第k个方块,则block[0][4]置为1,表示第0方块已经存在数字4了


#include <iostream>
#include <iterator>

using std::string;

int main(){


    return 0;
}


bool isValidSudoku(std::vector<std::vector<char>>& board)
{
    int row[9][9] = {0}, col[9][9] = {0}, block[9][9] = {0};

    for(int i = 0; i < board.size(); i++){      
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] != '.'){
                int num = board[i][j]-'1', k = i/3*3+j/3;         //由于j的取值是从0到8,所以随着i的增加,k的取值是从0,1,2,3,4,5,6,7,8
                if(row[i][num] || col[i][num] || block[k][num]) return false;
                row[i][num] = col[i][num] = block[k][num] = 1
            }
        }
    }

    return true;

}