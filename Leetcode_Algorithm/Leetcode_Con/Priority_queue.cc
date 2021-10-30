
/*
    优先队列的使用
*/

//优先队列的实现(大顶堆)
class maxHeap {
private:
    std::vector<int> heap;  //数组实现堆
    int size;               //堆的实际元素大小

public:
    maxHeap() {
        heap.push_back(-1);
        size = 0;
    }

    //上浮
    void swim(int pos)
    {
        while(pos > 1 && heap[pos] > heap[pos/2]) {
            std::swap(heap[pos], heap[pos/2]);
            pos /= 2;
        }
    }

    //下沉调整成大顶堆
    void sink(int pos)
    {
        int tmp = heap[pos];

        for(int j = pos*2; j <= size; j *= 2)
        {
            if(j < size && heap[j+1] > heap[j]) j++;

            if(tmp > heap[j]) break;

            heap[pos] = heap[j];

            pos = j;
        }

        heap[pos] = tmp;
    }

    //插入的数字放在最后一位，然后上浮
    void push(int val)
    {
        heap.push_back(val);
        size++;
        swim(size);
    }

    //删除最大值:把最后一个数字挪到开头，然后开始下沉
    void pop()
    {
        std::swap(heap[1], heap[size]);
        heap.pop_back();
        size--;

        sink(1);        //这个一定需要在pop_back之后
    }

    int top() {
        return heap[1];
    }

    bool empty() {
        return size < 1;
    }

};



// 定义优先队列里面的元素排序规则

struct Node {
    int x;
    int len;
    Node(int m_x, int m_len) : x(m_x), len(m_len) {}

    bool operator<(const Node &demo) const {
        return len > demo.len;
    }
};

//方式一:直接在自定义类型里面定义好比较规则,默认是'<',不能使用'>'
std::priority_queue<Node> pq;

struct Cmp {
    bool operator()(const Node &o1, const Node &o2) const {
        return o1.len > o2.len;
    }
};

//方式二:在类外定义好仿函数后使用仿函数
std::priority_queue<Node, std::vector<Node>, Cmp> pq;


////////////////////////////////////////////
//
//      寻找数组中出现频次最高的(k个)元素
//      思路都是 哈希+优先队列
//
//      第347题: 找到数组中出现频次最高的k个元素
//      第692题: 找到数组中出现频次最高的k个单词
//      第451题: 按照字母出现的频次重排单词
//     第1636题: 按照元素出现频次重排元素
//     第1642题: 能到达的最大建筑物高度

//      第1384题 : 题目出的非常好
///////////////////////////////////////////


//Leetcode第347题:Top k问题
//思路:哈希map+优先队列 (题目出的非常好)

//下面这种方法的思路是频次在前,元素在后,这样就可以不用再重写优先队列里面元素的排列规则

std::vector<int> topKFrequent(std::vector<int> &nums, int k)
{
    std::priority_queue<std::pair<int,int>> pq;

    std::unordered_map<int,int> hash;

    for(const &n : nums) hash[n]++;
    
    std::vector<int> res;

    for(auto &item : hash) {
        pq.push({item.second, item.first});
        if(pq.size() > hash.size() - k) {       //这里是-k, 当遍历到的hash的元素个数还剩下size-k时就可以将堆顶元素加入到结果中
            res.push_back(pq.top().second);
            pq.pop();
        }
    }

    return res;
}


//Leetcode第692题:找到数组中出现频次最高的k个单词
//哈希+优先队列

//方法一:构建一个大顶堆(评论区有人用小顶堆也能做出来)
struct Cmp {
    bool operator()(const std::pair<std::string,int> &a, const std::pair<std::string,int> &b) {
        return a.second < b.second || (a.second == b.second && a.first > b.first);
    }
};

std::vector<std::string> topKFrequent(std::vector<std::string> &words, int k)
{
    //优先队列默认的排序方式是从大到小,即默认是按照">"的顺序排列的,现在这里的函数Cmp重载的是怎么定义这个'>'大于号
    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string,int>>, Cmp> pq;
    
    std::unordered_map<std::string, int> hash;

    for(const std::string &word : words) {
        hash[word]++;
    }

    for(auto &item : hash) pq.push(item);

    std::vector<std::string> res;

    for(int i = 0; i < k; i++) {
        res.push_back(pq.top().first);
        pq.pop();
    }

    return res;
}


//Leetcode第451题:按照字母出现频次重排单词

std::string frequencySort(std::string s)
{
    std::priority_queue<std::pair<int,char>> pq;    //优先队列里面的元素如果是pair,则默认会先按照pair的第一个元素从大到小排列，再按照pair的第二个元素从大到小排列

    std::unordered_map<char,int> hash;

    for(const char &c : s) hash[c]++;
    
    for(auto &item : hash) {
        pq.push({item.second, item.first});
    }

    std::string res;
    while(!pq.empty()) {
        res += std::string(pq.top().second, pq.top().first);
        pq.pop();
    }

    return res;
}


//第1636题:按照元素出现频次重排元素

struct Cmp {
    bool operator()(const std::pair<int,int> &a, const std::pair<int,int> &b) {
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    }
};

std::vector<int> frequencySort(std::vector<int> &nums)
{
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, Cmp> pq;

    std::unordered_map<int, int> hash;

    for(const int &n : nums) hash[n]++;
    
    for(auto &item : hash) {
        pq.push(item);
    }

    std::vector<int> res;
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        for(int i = 0; i < cur.second; i++) {
            res.push_back(cur.first);
        }
    }

    return res;
}


//Leetcode第1642题
//贪心的思想:最大高度差选择用梯子来爬,其他的高度差选择用砖头垫

int furthestBuilding(std::vector<int> &heights, int bricks, int ladders)
{
    std::priority_queue<int> pq;

    for(int i = 0; i < heights.size()-1; i++)
    {
        int diff = heights[i] - heights[i+1];
        if(diff < 0) {
            pq.push(diff);
        }

        if(pq.size() > ladders) {
            bricks += pq.top();
            pq.pop();
        }

        if(bricks < 0) return i;
    }

    //能够从这里返回就说明能到达数组末尾
    return heights.size() - 1;
}
