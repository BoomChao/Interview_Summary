

//Leetcode第209题 : Minimun Size Subarray Sum
//在给定的数组中寻找大于指定值的最小数组和

//思路:滑动窗口


int minSubArrayLen(int s, std::vector<int> &nums)
{
    if(nums.empty()) return 0;

    int result = nums.size() + 1;
    int start = 0, end = -1;
    int sum = 0;

    while(start < nums.size())
    {
        //还有剩余元素为考察并且窗口中的元素总和小于目标值s
        if(end + 1 < nums.size() && sum < s) {
            end++;
            sum += nums[end];
        }
        else {      //尝试缩小窗口
            sum -= nums[start];
            start++;
        }

        if(sum >= s) {
            result = std::min(result, end - start + 1);
        }
    }

    return result == nums.size() + 1 ? 0 : result;
}

