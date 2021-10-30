

//Leetcode第330题:Patching Array
//构成补丁数组需要添加的最小的数字个数

//贪婪算法
//思路:弄清楚背后的数字规律


int minPatches(std::vector<int> &nums, int n)
{
    long miss = 1, added = 0, i = 0;
    
    while(miss <= n)
    {
        if(i < nums.size() && nums[i] <= miss) {
            miss += nums[i++];
        }
        else {
            miss += miss;
            added++;
        }
    }

    return added;
}
