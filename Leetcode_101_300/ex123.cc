

//Leetcode第123题: Best Time to Buy and Sell Stock III
//只允许买进卖出两次,求最大利润

//思路:
//对于{3,5,5,0,0,3,1,4}
//1.显然最大利润为(4-1)+(3-0),这也等于 4-(1-(3-0))
//2.其中0是第一次最小的买进价格buyOne,而(3-0)是第一次买进卖出的利润sellOne;
//  (1-(3-0))是第二次买进价格sellTwo,而4-(1-(3-0))就是第二次买进卖出的利润sellTwo,就是总利润

int maxProfit(std::vector<int> &prices)
{
    if(prices.size() <= 1) return 0;

    int buyOne = INT_MAX, sellOne = 0;
    int buyTwo = INT_MAX, sellTwo = 0;

    for(int price : prices) 
    {
        //第一次买进卖出
        buyOne = std::min(buyOne, price);   //买进价格越小,卖出价格就越高
        sellOne = std::max(sellOne, price - buyOne);

        //第二次买进卖出
        buyTwo = std::min(buyTwo, price - sellOne);
        sellTwo = std::max(sellTwo, price - buyTwo);
    }

    return sellTwo;

}


//上面的改编版,不使用INT_MAX
int maxProfit(std::vector<int> prices)
{
    if(prices.size() <= 1) return 0;

    int buyOne = prices[0], sellOne = 0;
    int buyTwo = prices[0], sellTwo = 0;

    for(int i = 1; i < prices.size(); i++) 
    {
        buyOne = std::min(buyOne, prices[i]);
        sellOne = std::max(sellOne, prices[i] - buyOne);

        buyTwo = std::min(buyTwo, prices[i] - sellOne);
        sellTwo = std::max(sellTwo, prices[i] - buyTwo);

    }

    return sellTwo;

}


