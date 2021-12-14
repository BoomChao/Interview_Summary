

/*
    面试题42:连续子数组的最大和
    同Leetcode第53题
*/

//思路:动态规划


#include <iostream>

int findGreatSumOfSubarray(int *pData, int length);

int main(){
    int data[] = {1,-2,3,10,-4,7,2,-5};
    int n = sizeof(data)/sizeof(data[0]);

    std::cout << findGreatSumOfSubarray(data, n) << std::endl;

    return 0;
}

int findGreatSumOfSubarray(int *pData, int length)
{
    if(pData == nullptr || length <= 0) {
        return -1;
    }

    int dp[length];
    dp[0] = pData[0];

    int res = dp[0];

    for(int i = 1; i < length; i++)
    {
        if(dp[i-1] < 0) {
            dp[i] = pData[i];
        }
        else {
            dp[i] = dp[i-1] + pData[i];
        }

        res = std::max(res, dp[i]);
    }

    return res;
}



//Leetcode第53题,可看成是对上面动态规划的优化,不需要一个数组来存储每个值
//时间复杂度O(n), 空间复杂度O(1)

int findGreatSumOfSubarray(std::vector<int> &nums)
{
    int res = INT_MIN;
    int sum = 0;

    for(int n:num)
    {
        sum += n;
        if(n > sum) {
            sum = n;
        }

        res = std::max(res, sum);
    }

    return sum;
}