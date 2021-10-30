

//Leetcode第239题:Sliding Window Maximum
//滑动窗口的最大值

//思路:参考<剑指>面试题59


std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
{
    if(nums.size() < k || k == 0) return maxInWindows;

    std::vector<int> maxInWindows;
    std::deque<int> index;

    for(int i = 0; i < k; i++)
    {
        while(!index.empty() && nums[i] >= nums[index.back()]) {
            index.pop_back();
        }

        index.push_back(i);
    }

    for(int i = k; i < nums.size(); i++)
    {
        maxInWindows.push_back(nums[index.front()]);

        while(!index.empty() && nums[i] > nums[index.back()]) {
            index.pop_back();
        }

        if(!index.empty() && index.front() <= (i-k)) {
            index.pop_front();
        }

        index.push_back(i);
    }

    maxInWindows.push_back(nums[index.front()]);

    return maxInWindows;

}



//优化:可以将上面两个循环写到一个里面

std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
{
    std::vector<int> maxInWindows;

    if(nums.size() < k || k == 0) return maxInWindows;

    std::deque<int> index;

    for(int i = 0; i < nums.size(); i++)
    {
        while(!index.empty() && nums[i] > nums[index.back()]) {
            index.pop_back();
        }

        if(!index.empty() && index.front() <= (i-k)) {
            index.pop_front();
        }

        //入队列之前先检查一下队首的元素是否还位于滑动窗口中
        index.push_back(i);
        
        if(i >= k-1) {
            maxInWindows.push_back(nums[index.front()]);
        }
    }

    return maxInWindows;
}
