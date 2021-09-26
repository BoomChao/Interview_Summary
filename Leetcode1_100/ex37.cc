

//Leetcode第37题
//Sudoku Solver : 解数独


int row[9][9] = {0}, col[9][9] = {0}, block[9][9] = {0};
int solved = 0;

void solveSudoKu(std::vector<std::vector<char>> &board)
{
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == '.') continue;
            int k = (i/3)*3 + j/3;
            int num = board[i][j] - '1';
            row[i][num] = col[j][num] = block[k][num] = 1;
        }
    }

    recall(board, 0, 0);

}


void recall(std::vector<std::vector<char>> &board, int i, int j){
    if(i == 9){
        solved = 1;
        return;
    }

    if(board[i][j] != '.'){
        if(j < 8) recall(board, i, j+1);
        else recall(board, i+1, 0);
    }
    else {
        int k = (i/3)*3 + j/3;      //块索引

        for(int n = 1; n <= 9; n++){    //依次尝试填充
            if(!row[i][n-1] && !col[j][n-1] && !block[k][n-1]){
                board[i][j] = n + '0';
                row[i][n-1] = col[j][n-1] = block[k][n-1] = 1;

                if(j < 8) recall(board, i, j+1);
                else recall(board, i+1, 0);

                //没有解决就回溯,就不填这个值了
                if(!solved){
                    board[i][j] = '.';
                    row[i][n-1] = col[j][n-1] = block[k][n-1] = 0;
                }
            }
        }

    }

}