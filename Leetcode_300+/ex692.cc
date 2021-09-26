

//Leetcode第692题 : Top K Frequent Words
//找到出现频次最高的前k个单词

//思路:注意该题题目虽然和第347题相同,但是第347题没有要求元素要按照什么排列
//这一题要求元素要按照出现的频次高低进行排列,如果出现频次相同,就按照字典顺序排列


//方法一:使用优先队列,插入队列的元素要加上判断条件按照顺序来插入

struct Comp 
{
    //lhs = Left Hand Side    rhs = Right Hand Side 
    bool operator() (const std::pair<int, std::string> &lhs, const std::pair<int, std::string> &rhs) const {
        if(lhs.first != rhs.first) {
            return lhs.first < rhs.first;
        }

        return lhs.second > rhs.second;
    }

};

std::vector<std::string> topKFrequent(std::vector<std::string> &words, int k)
{
    if(words.empty() || k <= 0) return {};

    std::vector<std::string> res;

    std::unordered_map<std::string, int> mp;
    for(auto word:words) {
        mp[word]++;
    }

    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, Comp> pq;
    for(auto it:mp) {
        pq.emplace(it.second, it.first);
    }

    while(k-- && !pq.empty()) {
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;

}



//方法二:利用map和桶排序(推荐使用这种方法,很简洁)

std::vector<std::string> topKFrequent(std::vector<std::string> &words, int k)
{
    //注意:这里利用的不再是unordered_map, map有自动排序的功能
    std::map<std::string, int> mp;
    for(auto w:words) {
        mp[w]++;
    }

    std::vector<std::vector<std::string>> bucket(words.size());
    for(auto it:mp) {
        bucket[it.second].push_back(it.first);
    }

    std::vector<std::string> res;
    for(int i = bucket.size() - 1; k > 0 && i >= 0; i--)
    {
        if(bucket[i].empty()) {
            continue;
        }

        int n = std::min(k, int(bucket[i].size()));
        res.insert(res.end(), bucket[i].begin(), bucket[i].begin() + n);    //在容器尾部插入
        k -= n;
    }

    return res;

}
