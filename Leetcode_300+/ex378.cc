

// Leetcode第378题:Kth Smallest Element int a Sorted Matrix
// 在矩阵中找到较小的第k个数

// 思路:二分查找


int kSmallest(std::vector<std::vector<int>> &matrix, int k)
{
    if(matrix.empty()) return -1;

    int n = matrix.size();
    int left = matrix[0][0], right = matrix[n-1][n-1];

    while(left < right)
    {
        int mid = left + ((right-left)>>1);
        int count = 0;
        for(int i = 0; i < n; i++) {
            int num = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            count += num;
        }     

        if(count < k) {       // 当前数量比k小,则向右扩大范围,增大mid的值
            left = mid + 1;
        }
        else {              // 当前数量比k大或者等于k,则向左缩小范围,尝试找到满足条件的最小的数值
            right = mid;
        }
    }

    return left;
}

