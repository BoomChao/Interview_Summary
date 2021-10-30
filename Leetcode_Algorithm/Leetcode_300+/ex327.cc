

//Leetcode第327题:Count Range Sum 
//计算制定范围的数组区间的范围和

//思路:使用二叉树


#include <iostream>
#include <vector>
#include <set>

int countRangeSum(std::vector<int> &nums, int lower, int upper);


int main(){
    std::vector<int> nums = {-2,5,-1};
    int lower = -2, upper = 2;

    std::cout << countRangeSum(nums, lower, upper) << std::endl;

    return 0;
}

int countRangeSum(std::vector<int> &nums, int lower, int upper)
{
    int n = nums.size();
    long sum = 0;
    std::multiset<long> S;      //multiset的底层实现就是红黑树
    S.insert(0);
    int res = 0;

    for(int i = 0; i < n; i++)
    {
        sum += nums[i];
        res += distance(S.lower_bound(sum-upper), S.upper_bound(sum-lower));
        S.insert(sum);
    }

    return res;
}
