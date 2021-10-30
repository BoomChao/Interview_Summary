


//Leetcode第152题:数组中连续元素的最大乘积


#include <iostream>
#include <climits>
#include <vector>

int maxProduct(std::vector<int> &nums);

int main(){
    std::vector<int> nums = {2,3,-2,1};
    std::cout << maxProduct(nums) << std::endl;

    return 0;
}

int maxProduct(std::vector<int> &nums)
{
    if(nums.empty()) return 0;

    int res = INT_MIN;
    int maxProd = 1;
    int minProd = 1;

    for(int n:nums)
    {
        if(n < 0) {
            std::swap(maxProd, minProd);
        }
            maxProd = std::max(maxProd*n, n);
            minProd = std::min(minProd*n, n);

            res = std::max(res, maxProd);
    }

    return res;

}
