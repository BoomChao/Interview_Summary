

//Leetcode第238题:Product of Array Except Self
//计算数组中除去自身元素以外的所有元素的乘积

//不能使用除法,所以第一次遍历先乘以这个数之前元素的乘积
//第二次遍历再乘以这个数之后的元素的乘积

std::vector<int> productExceptSelf(std::vector<int> &nums)
{
    std::vector<int> res(nums.size(), 1);

    for(int i = 0; i < nums.size(); i++)
    {
        if(i == 0) {
            res[i] = 1;
        }
        else {
            res[i] = res[i-1]*nums[i-1];
        }
    }

    int prod = 1;
    for(int i = nums.size()-1; i >= 0; i--)
    {
        res[i] *= prod;
        prod *= nums[i];
    }

    return res;

}