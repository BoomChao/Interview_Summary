

//Leetcode第373题:Find K Pairs with Smallest Sums
//找到和最小的k个数对

//思路:利用优先队列

std::vector<std::vector<int>> kSmallestPairs(std::vector<int> &nums1, std::vector<int> &nums2, int k)
{
    int m = nums1.size(), n = nums2.size();
    std::priority_queue<std::pair<int, std::pair<int,int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<std::pair<int, std::pair<int,int>>>> pq;

    std::vector<std::vector<int>> res;
    if(m == 0 || n == 0) return res;
    for(int i = 0; i < m; i++) {
        pq.push({{nums1[i]+nums2[0]}, {i,0}});
    }

    while(!pq.empty() && k-- > 0)
    {
        int val = pq.top().first;           //这个val表示优先队列pq的第一个std::pair<int, std::pair<int,int>> 中的第一个int
        int i = pq.top().second.first;      //这个i表示优先队列pq的第一个std::pair<int, std::pair<>int,int> 中的第二个pair的int,j表示第pair的第二个int
        int j = pq.top().second.second;     
        pq.pop();

        std::vector<int> v = {nums1[i], nums2[j]};
        res.push_back(v);
        if(j + 1 == n) continue;
        pq.push({{nums1[i]+nums2[j+1]}, {i, j+1}});

    }

    return res;
}
