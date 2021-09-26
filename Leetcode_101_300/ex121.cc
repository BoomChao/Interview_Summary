

//Leetcode第121题: Best Time to Buy and Sell Stock
//最合适的时间买进和卖出股票,只允许买进卖出一次

//思路:(<剑指>面试题63)
//1.遍历元素,纪律遍历到的最低价格min
//2.与当前价格比较得出利润,记录最大理论
//3.逐个遍历逐个记录最低价格和最大利润


#include <iostream>
#include <vector>
#include <climits>

int maxProfit(std::vector<int> &prices);

int main(){
    std::vector<int> prices = {7,1,5,3,6,4};

    std::cout << maxProfit(prices) << std::endl;

    return 0;
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