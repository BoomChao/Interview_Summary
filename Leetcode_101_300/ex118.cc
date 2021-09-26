

//第118题:Pascal's Triangle
//构建帕斯卡三角形

//思路:
//找出递推规律即可

std::vector<std::vector<int>> gererate(int numRows)
{
    std::vector<std::vector<int>> res(numRows);

    for(int i = 0; i < numRows; i++)
    {
        res[i].resize(i + 1);
        res[i][0] = res[i][i] = 1;

        for(int j = 1; j < i; j++) {
            res[i][j] = res[i-1][j-1] + res[i-1][j];
        }

    }

    return res;

}