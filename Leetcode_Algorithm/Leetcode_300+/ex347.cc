

//Leetcode第347题 : Top K Frequent Element
//找到出现频次最高的前K个元素,结果元素的顺序可以是任何顺序(不一定出现频次高的元素就要放在前面)

//解法一:利用优先队列

std::vector<int> topKFrequent(std::vector<int> &nums, int k)
{
    if(nums.empty() || k <= 0) return {};

    std::vector<int> res;
    
    std::unordered_map<int, int> mp;
    for(int n:nums) {
        mp[n]++;
    }

    std::priority_queue<std::pair<int, int>> pq;        //利用优先队列
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        pq.push(std::make_pair(it->second, it->first));     //这个pair的第一个数是频率,第二个数是数字

        if(pq.size() > mp.size() - k) {        
            res.push_back(pq.top().second);
            pq.pop();                         //这个pop操作千万不要忘记了
        }
    }

    return res;
}



//解法二:利用桶排序

std::vector<int> topKFrequent(std::vector<int> &nums, int k)
{
    std::unordered_map<int,int> count;
    int maxCount = 0;
    for(int &num : nums) {
        maxCount = std::max(maxCount, ++count[num]);
    }

    std::vector<std::vector<int>> bucket(maxCount + 1);
    for(auto &p : count) {
        bucket[p.second].push_back(p.first);
    }

    std::vector<int> ans;
    for(int i = maxCount; i >= 0 && ans.size() < k; i--)
    {
        for(int &num : bucket[i]) 
        {
            ans.push_back(num);
            if(ans.size() == k) {
                break;              //这个break只是跳出内层循环,但是当内层循环内ans.size()==k时
            }                       //外层循环的判断条件ans.size()<k也就自动不满足了,外层循环也就跳出了
        }
    }

    return ans;
}

