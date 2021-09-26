

//Leetcode第54题
//Spiral Matrix:顺时针打印矩阵

//思路:参考<剑指>面试题29


std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
{
    if(matrix.size() == 0) return {};

    int start = 0;
    int row = matrix.size(), col = matrix[0].size();

    std::vector<int> res;     
    res.reserve(col*row);   //为向量预分配一定的空间
    while(row>2*start && col>2*start){     //这个跳出循环条件是找规律得出的
        spOrder(matrix, res, row, col, start);
        start++;
    }

    return res;

}

void spOrder(std::vector<std::vector<int>> &matrix, std::vector<int> &res, int row, int col, int start){
    int endX = row-1-start;
    int endY = col-1-start;

    //从左到右打印第一行
    for(int i = start; i <= endY; i++){
        res.push_back(matrix[start][i]);
    }

    //从上到下打印第一列
    if(start < endX){
        for(int i = start+1; i <= endX; i++){
            res.push_back(matrix[i][endY]);
        }
    }

    //从右到左打印第二行
    if(start < endX && start < endY){
        for(int i = endY-1; i>=start; i--){
            res.push_back(matrix[endX][i]);
        }
    }

    //从下到上打印第二列
    if(start < endX-1 && start < endY){
        for(int i = endX-1; i >= start+1; i--){
            res.push_back(matrix[i][start]);
        }
    }


}


//方法二(最优解)
//思路:顺时针一圈一圈的遍历

std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
{
    std::vector<int> res;
    int m = matrix.size(), n = matrix[0].size();
    res.reserve(m*n);

    int up = 0, down = m - 1;
    int left = 0, right = n - 1;

    while(res.size() < m*n)
    {
        //从左往右                      //注意:这个res.size()<m*n一定要加,防止最后圆圈中只有一个数字被重复添加
        for(int j = left; j <= right && res.size() < m*n; j++) {
            res.push_back(matrix[up][j]);
        }

        //从上往下
        for(int i = up + 1; i <= down-1 && res.size() < m*n; i++) {
            res.push_back(matrix[i][right]);
        } 

        //从右往左
        for(int j = right; j >= left && res.size() < m*n; j--) {
            res.push_back(matrix[down][j]);
        }

        //从下往上
        for(int i = down-1; i > up && res.size() < m*n; i--) {
            res.push_back(matrix[i][left]);
        }

        left++;  right--;
        up++;   down--;
    }

    return res;
}

