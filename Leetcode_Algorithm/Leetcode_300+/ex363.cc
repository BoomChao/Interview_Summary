

//Leetcode第363题:Max Sum of Rectangle No Longer Than K
//找到小于等于k的最大的子矩阵的和

//思路:动态规划


int maxSumSubmatrix(std::vector<std::vector<int>> &matrix, int k)
{
    if(matrix.empty()) return 0;

    int row = matrix.size(), col = matrix[0].size();
    int res = INT_MIN;
    
    for(int l = 0; l < col; l++)
    {
        std::vector<int> sums(row, 0);
        for(int r = l; r < col; r++)        //注意:这是r=l,不是r=1
        {
            for(int i = 0; i < row; i++) {
                sums[i] += matrix[i][r];        //sums[i]代表的是第i行的元素的和
            }

            //找到不超过元素k的最大子数组的累加和
            std::set<int> accuSet;
            accuSet.insert(0);
            int curSum = 0, curMax = INT_MIN;
            for(int sum:sums) 
            {
                curSum += sum;
                std::set<int>::iterator it = accuSet.lower_bound(curSum - k);   //(*it) >= (curSum-k)
                if(it != accuSet.end()) {      
                    curMax = std::max(curMax, curSum - *it);    //则curSum-*it <= k
                }
                accuSet.insert(curSum);
            }

            res = std::max(res, curMax);
        }
    }

    return res;
}
