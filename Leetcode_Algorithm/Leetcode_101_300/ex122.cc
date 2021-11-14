

//Leetcode第122题: Best Time to Buy and Sell Stock II
//可以买进卖出多次,计算最大利润

//思路:如果当天价格大于前一天价格,则将利润累加(当天价格-前一天价格),否则加上0


int maxProfit(std::vector<int> &prices)
{
    if(prices.size() <= 1) return 0;

    int profit = 0;
    for(int i = 0; i < prices.size()-1; i++) 
    {
        if(prices[i] < prices[i+1]) {
            profit += prices[i+1] - prices[i];
        }
    }

    return profit;
}


//Golang解答

func maxProfit(nums []int) int {
	var res int = 0

	for i := 1; i < len(nums); i++ {
		res += max(nums[i] - nums[i-1], 0)
	}
	
	return res
}

//Golang中不支持三目运算符(?:),也没有 int 类型的Max和Min函数
func max(a b, int) int {
	if a > b {
		return a
	} else {
		return b
	}
}