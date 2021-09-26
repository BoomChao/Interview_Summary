

//Leetcode第220题:Contains Duplicate III

//利用哈希
//时间复杂度为n*log(k)

bool containsNearbyAlmostDuplicate(std::vector<int> &nums, int k, int t)
{
    std::set<long> window;  //这里用long是因为下面涉及到nums[i]-t,如果nums[i]=-2147483647,t=247483647就会溢出

    for(int i = 0; i < nums.size(); i++)
    {
        if(i > k) {
            window.erase(nums[i-k-1]);  //使窗口中元素的下标差保持在k以内
        }

        //lower_bound返回的是数组中第一个大于等于该元素的下标
        //upper_bound返回的是数组中第一个大于该元素的下标
        auto pos = window.lower_bound(nums[i]-t);   //x-nums[i]>=-t  ==>  x>=nums[i]-t

        if(pos != window.end() && *pos-nums[i] <= t) {    //x-nums[i]<=t 
            return true;
        }

        window.insert(nums[i]);
    }

    return false;

}

