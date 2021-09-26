

//Leetcode第53题
//(Maximum Subarray) 返回给定的子数组元素的最大和

//思路:动态规划
//动态规划方程为:dp[0]=num[0]
//之后遍历数组,dp[i] = num[i]+(dp[i-1]>0 ? dp[i-1] : 0);


#include <iostream>
#include <vector>

int maxArray(std::vector<int> &nums);

int main(){
    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    std::cout << maxArray(nums) << std::endl;


    return 0;
}

int maxArray(std::vector<int> &nums)
{
    int n = nums.size();
    int *dp = new int[n];
    dp[0] = nums[0];
    int res = dp[0];

    for(int i = 1; i < n; i++){
        dp[i] = nums[i] + (dp[i-1]>0 ? dp[i-1] : 0);
        res = std::max(dp[i],res); 
    }

    return res;

}


//上面的改进版  (思想仍然是动态规划,只不过不需要额外的一个数组)
int maxArray(std::vector<int> &nums)
{
    int res = INT_MIN;  //这是为了预防只有一个元素,如nums={-2147483647}
    int sum = 0;

    for(auto n:nums){
        sum += n;
        if(n > sum){
            sum = n;
        }
        res = std::max(res, sum);
    }

    return res;

}