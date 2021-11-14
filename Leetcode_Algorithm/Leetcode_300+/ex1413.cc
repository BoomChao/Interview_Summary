

//Leetcode第1413题：最小的值使得每步累加的和都不小于1,返回这个最小的初始值(>=1)

//思路：遍历记录下累加和的最小值即可

int minStartValue(std::vector<int> &nums)
{
    int sum = 0, min_sum = 0;

    for(const int &n : nums) {
        sum += n;
        min_sum = std::min(min_sum, sum);
    }

    return 1 - min_sum;
}

