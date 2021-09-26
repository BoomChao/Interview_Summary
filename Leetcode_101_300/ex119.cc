

//Leetcode第119题:Pascal's Triangle II
//返回帕斯卡三角形制定的行


//思路:
//由于这里rowIndex下标是从0开始的,所以构建帕斯卡三角形需要构建rowIndex+1行


std::vector<int> getRow(int rowIndex)
{
    std::vector<std::vector<int>> res(rowIndex + 1);

    for(int i = 0; i < rowIndex + 1; i++)
    {
        res[i].resize(i + 1);
        res[i][0] = res[i][i] = 1;

        for(int j = 1; j < i; j++) {
            res[i][j] = res[i-1][j-1] + res[i-1][j];
        }

    }

    return res[rowIndex];

}