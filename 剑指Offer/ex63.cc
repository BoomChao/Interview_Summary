

/*
    面试题53:股票的最大利润
    参考Leetcode第121题
*/

//思路:
//遍历到第i个数字时,与前面i-1个数字的最小值做差就能得到该价位卖出时的利润,将该利润与之前价位的最大利润比较
//遍历到数组末尾取最大利润值即可

int maxDiff(const int *numbers, unsigned int length)
{
    if(numbers == nullptr || length <= 1) return 0;

    int min = numbers[0];
    int maxDiff = numbers[1] - min;

    for(int i = 2; i < length; i++)
    {
        //保存前i-1数字的最小值
        if(numbers[i-1] < min) {
            min = numbers[i-1];
        }

        //当前利润与最大利润比较
        int curDiff = numbers[i] - min;
        if(curDiff > maxDiff) {
            maxDiff = curDiff;
        }

    }

    return maxDiff;

}


int maxProfit(std::vector<int> &prices)
{
    if(prices.size() <= 1) return 0;

    int minPrice = prices[0];
    int maxProfit = 0;

    for(int i = 1; i < prices.size(); i++) {
        minPrice = std::min(minPrice, prices[i]);
        maxProfit = std::max(maxProfit, prices[i] - minPrice);
    }

    return maxProfit;

}
