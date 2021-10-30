

//Leetcode第135题:Candy
//分糖果问题

//思路:贪心
//两次遍历

int candy(std::vector<int> &ratings)
{
    if(ratings.size() <= 1) return ratings.size();

    std::vector<int> num(ratings.size(), 1);
    for(int i = 1; i < ratings.size(); i++)
    {
        if(ratings[i] > ratings[i-1]) {
            num[i]++;
        }
    }

    for(int i = ratings.size()-1; i > 0; i--) 
    {
        if(ratings[i-1] > ratings[i]) {
            num[i-1] = std::max(num[i-1], num[i] + 1);
        }
    }

    //accumulate函数所在头文件为<numeric>
    return accumulate(num.begin(), num.end(), 0);
}
