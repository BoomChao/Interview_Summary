
//面试题12 : 矩阵中的路径

//参考Leetcode第79题


bool hasPath(char* matrix, int rows, int cols, char *str)
{
    if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr) return false;

    // bool *visited = new bool[rows*cols];     //不需要额外定义一个数组
    // memset(visited, 0, rows*cols);

    int pathLength = 0;
    for(int row = 0; i < rows; i++){
        for(int col = 0; j < cols; j++){
            if(hasPathCore(matrix, rows, cols, row, col, str, pathLength)) return true;
        }
    }

    // delete[] visited;

    return false;

}


bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int &pathLength, bool* visited){
    if(str[pathLength] == '\0') return false;

    if(row < 0 || row > rows-1 || col < 0 || col > cols-1 || matrix[row*cols+col] != str[pathLength]) return false;   //越过了边界,直接返回false;

    char cur = matrix[row*cols+col];
    matrix[row*cols+col] = '*';
    bool search_next =   hasPathCore(matrix, rows, cols, row-1, col, pathLength+1)
                       ||hasPathCore(matrix, rows, cols, row, col+1, pathLength+1)
                       ||hasPathCore(matrix, rows, cols, row+1, col, pathLength+1)
                       ||hasPathCore(matrix, rows, cols, row, col-1, pathLength+1);
    matrix[row*cols+col] = cur;

    return search_next;

}