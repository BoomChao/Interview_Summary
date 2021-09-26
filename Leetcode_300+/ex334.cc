

//Leetcode第334题:Increasing Triplet Subsequence
//判断数组是否存在三个递增的元素

//思路:这种方法很巧


bool increasingTriplet(std::vector<int> &nums)
{
    int x = INT_MAX, y = INT_MAX;

    for(int n:nums)
    {
        if(n <= x) {    
            x = n;      //找到第一个较小的数
        }
        else if(n <= y) {
            y = n;      //找到第二个较小的数
        }
        else {
            return true;    //存在第三个数比x和y都大,则查找成功,返回true
        }
    }

    return false;
}
