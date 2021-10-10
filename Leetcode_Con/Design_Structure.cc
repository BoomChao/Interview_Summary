
/*
*
*   自设计数据结构
*
*/


//Leetcode第146题 : 设计LRU缓存机制
//关键在于list的操作以及对splice方法的使用

class LRUCache()
{
public:
    LRUCache(int capacity) : size(capacity) {}

    int get(int key) {

        //注意 : 不能使用hash[key]来判断,因为如果key不存在则会默认插入key

        auto it = hash.find(key);       //这返回的是定义的无序unordered_map的迭代器,map中的元素是{key, value}, 所以it指向的第一个元素就是hash的第一个键值key, 第二个元素才是list的迭代器
        if(it == hash.end()) {
            return -1;          //未找到则返回-1
        }

        cache.splice(cache.begin(), cache, it->second);

        // return it->second->second;  
        // return cache.begin()->second;
        return cache.front().second;
    }

    void put(int key, int value) {
        auto it = hash.find(key);
        if(it != hash.end()) {
            it->second->second = value;     //如果key之前已经存在则重新赋值
            cache.splice(cache.begin(), cache, it->second);
            return ;
        }

        // cache.insert(cache.begin(), std::make_pair(key, value));    //将插入的元素放到list的首位
        // cache.push_front(std::make_pair(key, value));
        cache.push_front({key, value});     //这三种写法都可以
        hash[key] = cache.begin();          //更新hash

        if(cache.size() > size) {
            hash.erase(cache.back().first); //从哈希中删除该元素 (注意这个删除顺序)
            cache.pop_back();               //从list弹出末尾的元素
        }
    }

    
private:
    std::list<std::pair<int,int>> cache;        //pair的第一个数存储的是key,第二个数存储的是对应的value
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> hash;      //这里的map第一个数存储的是key值,第二个数存储的是(key,value)在list中的位置
    int size;                                                                   //map用来帮助快速判断cache里面是否拥有某个元素
};




//Leetcode第355 : 设计Twitter
//优先队列的使用

class Twitter
{
public:
    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        hash[userId].push_back({time++, tweetId});
    }

    std::vector<int> getNewsFeed(int userId) {
        std::priority_queue<std::pair<int,int>> maxHeap;        //使用优先队列,默认是最大堆

        for(auto it  = hash[userId].begin(); it != hash[userId].end(); it++) {
            maxHeap.push(*it);
        }

        for(auto iter1 = fo[userId].begin(); iter1 != fo[userId].end(); iter1++) {
            int user = *iter1;
            for(auto iter2 = hash[user].begin(); iter2 != hash[user].end(); iter2++) {
                maxHeap.push(*iter2);
            }
        }

        std::vector<int> res;
        while(!maxHeap.empty()) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
            if(res.size() == 10) break;
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            fo[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        fo[followerId].erase(followeeId);
    }

private:
    std::unordered_map<int, std::set<int>> fo;                  //记录自己follow了哪些明星
    std::unordered_map<int, std::vector<std::pair<int,int>>> hash;  //记录发的twitter
    long long time;

};



//Leetcode第295题:数据流中的中位数
//优先队列的使用

// 思路:定义两个队列
// minQue : 小(队头) -> 大
// maxQue : 大(队头) -> 小

//方法一: maxQue放在前面, minQue放在后面, minQue的最小值大于maxQue的最大值
//方法二: minQue放在前面, maxQue放在后面, maxQue的最大值小于minQue的最小值
//本质上还是一种方法，只不过两种比较形式

// 当元素比minQue队头元素大,则直接放入minQue队列
// 如果minQue队列元素比maxQue队列元素个数相差为2,则将多的元素移动到少的队列中去


class MedianFinder
{
public:
    MedianFinder() {}

    void addNum(int num) {
        
        //方法一:
        // if(maxQue.empty() || num < maxQue.top()) maxQue.push(num);
        // else minQue.push(num);

        //方法二:
        if(minQue.empty() || num > minQue.top()) minQue.push(num);
        else maxQue.push(num);

        if(maxQue.size() > (minQue.size() + 1)) {
            minQue.push(maxQue.top());
            maxQue.pop();
        }
        else if((maxQue.size() + 1) < minQue.size()) {
            maxQue.push(minQue.top());
            minQue.pop();
        }
    }

    double findMedian() {
        if(maxQue.size() == minQue.size()) {
            return maxQue.empty() ? 0 : (maxQue.top() + minQue.top()) / 2.0;
        }
        else {
            return (maxQue.size() > minQue.size()) ? maxQue.top() : minQue.top();
        }
    }


private:
    std::priority_queue<int> maxQue;    
    std::priority_queue<int, std::vector<int>, std::greater<int>> minQue;

};




//第232题: 队列的实现

//两栈实现一个队列

class MyQueue
{
public:
    std::stack<int> in, out;

    MyQueue() {}

    void push(int x) {
        in.push(x);
    }

    void pop() {
        in2out();
        int x = out.top()
        out.pop();
        return x;
    }

    int peek() {
        in2out();
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }

    void in2out() {
        if(out.empty())     //注意看清条件,当out为空时才需要添加元素到out,否则不需要
        {
            while(!in.empty()) {
                int x = in.top();
                in.pop();
                out.push(x);
            }
        }
    }

};


//Leetcode第622题: 用数组实现循环队列
//循环队列也叫环形队列

class MyCirCularQueue
{
private:
    std::vector<int> data;
    int head;
    int tail;
    bool reset;     //定义一个标志用来区分队列是满还是空,reset为真表示队列为空

public:
    MyCirCularQueue(int k) {
        data.resize(k);
        head = 0;
        tail = 0;
        reset = true;
    }

    bool enQueue(int value) {
        if(isFull()) return false;

        if(head == tail && reset) reset = false;
        data[tail] = value;
        tail = (tail + 1)%data.size();   //tail指向的是新插入元素的位置
        return true;
    }

    bool deQueue() {
        if(isEmpty()) return false;

        head = (head + 1)%data.size();
        if(head == tail && !reset) reset = true;
        return true;
    }

    int Front() {
        if(isEmpty()) return -1;
        return data[head];
    }

    int rear() {
        if(isEmpty()) return -1;
        int index = (tail + data.size() - 1)%data.size();
        return data[index];
    }

    bool isEmpty() {
        if(tail == head && reset) return true;
        return false;
    }

    bool isFull() {
        if(tail == head && !reset) return true;
        return false;
    }

};


//方法二:数组留一个位置代表队列满的情况

class MyCirCularQueue 
{
private:
    std::vector<int> nums;
    int size;
    int head, tail;

public:
    MyCircularQueue(int k) {
        size = k + 1;
        nuns.resize(size);
        head = tail = 0;
    }

    bool isEmpty()
    {
        if(head == tail) return true;
        return false;
    }

    bool isFull()
    {
        if((tail+1)%size == head) return true;
        return false;
    }

    bool enQueue(int value)
    {
        if(isFull()) return false;
        nums[tail] = value;
        tail = (tail + 1)%size;
        return true;
    }

    bool deQueue()
    {
        if(isEmpty()) return false;
        head = (head + 1)%size;
        return true;
    }

    int Front() {
        if(isFull()) return -1;
        return nums[head];
    }

    int Rear() {
        if(isFull()) return -1;
        int index = (tail-1 + size)%size;       //这里有坑(注意)
        return nums[index];
    }
};




/////////////////////////////////
//
//      字典树(将其想象成多叉树即可)
//      
//      第208题: 实现一个前缀树
//      第211题: 实现一个快速查询的数据结构
//      第212题: 判断给点集合中的单词是否在字符矩阵中
//      第745题: 实现前缀和后缀查询
//
/////////////////////////////////

//Leetcode第208题: 实现一个字典树
//美团2020校招系统开发方向最后一个大题,考察的就是字典树

class TrieNode 
{
public:
    TrieNode *childNode[26];    //26个英文字母
    bool isVal;                 //是否存在以某个字母结尾的完整单词

    TrieNode() : isVal(false) {
        for(int i = 0; i < 26; i++) {
            childNode[i] = nullptr;
        }

        //上面的循环也可以这样写
        memset(childNode, 0, sizeof(childNode));    //memset的第二个参数只能传int型,传NULL编译器会给出警告
    }

    ~TrieNode() {
        for(int i = 0; i < 26; i++) {
            if(childNode[i]) {
                delete childNode[i];        //注意不要写成 delete[] childNode, 这里的childNode是一个指针数组，不可以这么做
            }                               // 如果 TrieNode *childNode = new TrieNde[26], 才可以使用delete[]，这表明对指针指向的一组对象进行析构
        }
    }

};

class Trie
{
private:
    TrieNode *root;

public:
    Trie() : root(new TrieNode) { }

    //向字典树中插入一个单词
    void insert(std::string word)
    {
        TrieNode *tmp = root;
        for(const char &c : word){
            if(tmp->childNode[c-'a'] == nullptr) {
                tmp->childNode[c-'a'] = new TrieNode;
            }
            tmp = tmp->childNode[c-'a'];
        }

        tmp->isVal = true;
    }

    //判断字典树中是否存在一个单词
    bool search(std::string word)
    {
        TrieNode *tmp = root;
        for(const char &c : word){
            tmp = tmp->childNode[c-'a'];
            if(tmp == nullptr) return false;
        }
        
        return tmp->isVal;
    }

    //判断字典树中是否存在一个指定的前缀
    bool startsWith(std::string prefix)
    {
        TrieNode *tmp = root;
        for(const char &c : word){
            tmp = tmp->childNode[c-'a'];
            if(tmp == nullptr) return false;
        }

        return true;
    }

};

//Leetcode第211题 : 设计一个数据结构来实现单词添加和查询
//第一种方法,根据字符串的大小来使用哈希表映射

class WordDictory
{
    std::unordered_map<int, std::vector<std::string>> words;

    bool isEqual(std::string s, std::string t) {
        for(int i = 0; i < s.size(); i++) {
            if(t[i] == '.') continue;
            if(s[i] != t[i]) return false;
        }

        return true;
    }

public:
    WordDictory() {}

    void addWord(std::string word) {
        words[word.size()].push_back(word); 
    }

    bool search(std::string word) {
        for(auto c : words[word.size()]) {
            if(isEqual(s, word)) return true;
        }

        return false;
    }

};


//方法二:使用字典树(也叫前缀树)

//先定义字典树节点
class TrieNode 
{
public:
    TrieNode *childNode[26];
    bool is_word;

    TrieNode() : is_word(false) {
        //注意:memset是C语言的函数,只能用NULL,如果使用了nullptr则C语言识别不了
        memset(childNode, NULL, sizeof(childNode));
    }

    ~TrieNode() {
        for(int i = 0; i < 26; i++) {
            if(childNode[i]) {
                delete childNode[i];
            }
        }
    }

};

class WordDictory
{
private:
    TrieNode *root;

    bool searchWord(std::string word, TrieNode *node)
    {
        for(int i = 0; i < word.size(); i++)
        {
            if(word[i] != '.') {
                node = node->childNode[word[i]-'a'];
            }
            else {
                TrieNode *tmp = node;
                for(int j = 0; j < 26; j++) {
                    node = tmp->childNode[j];
                    if(searchWord(word.substr(i + 1), node));
                }
            }
        }

        return node && node->is_word;
    }

public:
    WordDictory(): root(new TrieNode) {}

    void addWord(std::string word) 
    {
        TrieNode *node = root;
        for(const char c : word) {
            if(node->childNode[c-'a'] == nullptr) {
                node->childNode[c-'a'] = new TrieNode;
            }
            
            node = node->childNode[c-'a'];
        }

        node->word = true;
    }

    bool search(std::string word) 
    {
        return searchWord(word, root);
    }

};



//第212题: 在字符矩阵中查找是否存在给定集合中的字符串
//思路: 构造一个字典树来方便搜索
//将字符串全部放到字典树中去,再在矩阵中DFS来与字典树中的元素判断是否匹配
//这一题是将需要查找的字符串全部放入到字典树，然后根据矩阵中的字符来寻找是否含有匹配的字符串

class TrieNode 
{
public:
    TrieNode *childNode[26];
    std::string word;

    TrieNode() {
        memset(childNode, NULL, sizeof(childNode));
    }

    ~TrideNode() {
        for(int i = 0; i < 26; i++) {
            if(childNode[i]) {
                delete childNode[i];
            }
        }
    }

};

TrieNode* buildTree(std::vector<std::string> words)
{
    TrieNode *root = new TrieNode;

    for(const std::string &word : words)
    {
        TrieNode *node = root;
        for(const char &c : word) {
            if(node->childNode[c-'a'] == nullptr) {
                node->childNode[c-'a'] = new TrieNode;
            }
            node = node->childNode[c-'a'];
        }

        node->word = word;
    }

    return root;
}

std::vector<std::string> findWords(std::vector<std::vector<char>> &board, std::vector<std::string> &words)
{
    std::vector<std::string> res;

    TrieNode *root = buildTree(words);

    //矩阵的每个字符都需要判断,从四个方向搜索看是否字典树上有满足要求的字符串
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            dfs(board, i, j, root, res);
        }
    }

    return res;
}

void dfs(std:vector<std::vector<char>> &board, int i, int j, TrieNode *root, std::vector<std::string> &res)
{
    int m = board.size(), n = board[0].size();

    //判断是否出界
    if(i < 0 || i >= m || j < 0 || j >= n) return;

    char c = board[i][j];
    if(c == '#' || root->childNode[c-'a'] == nullptr) return;

    root = root->childNode[c-'a'];      //字典树节点往下移动一个

    if(!(root->word.empty())) {
        res.push_back(root->word);
        root->word.clear();         //找到了就将其置空,防止重复遍历
        // return;                  //这里不能返回,因为可能存在前缀相同的字符串,比如 "helo"和 "hello",还要继续向下遍历
    }

    board[i][j] = '#';
    
    dfs(board, i, j + 1, root, res);
    dfs(board, i, j - 1, root, res);
    dfs(board, i + 1, j, root, res);
    dfs(board, i - 1, j, root, res);

    board[i][j] = c;    //回溯
}

//另外一种写法
void dfs(std:vector<std::vector<char>> &board, int i, int j, TrieNode *root, std::vector<std::string> &res)
{
    int m = board.size(), n = board[0].size();

    if(i >= 0 && i < m && j >= 0 && j < n)
    {
        char c = board[i][j];
        if(root->childNode[c-'a'] == nullptr) return;

        if(!(root->word.empty())) {
            res.push_back(root->word);
            root->word.clear();
        }

        board[i][j] = '#';  //注意这个放置的位置

        dfs(board, i, j + 1, root, res);
        dfs(board, i, j - 1, root, res);
        dfs(board, i + 1, j, root, res);
        dfs(board, i - 1, j, root, res);

        board[i][j] = c;
    }

} 


//Leetcode第745题 : 实现一个快速查询单词前缀和后缀的结构

//解法一：字典树思想(可能超时)

struct TrieNode 
{
    TrieNode *childNode[26];
    std::vector<int> wordIndex;     //存放单词的序号,即该字符有哪些单词有

    TrieNode() {
        memset(childNode, NULL, sizeof(childNode));
    }

    ~TrieNode() {
        for(int i = 0; i < 26; i++) {
            if(childNode[i]) {
                delete childNode[i];
            }
        }
    }

    void add(const std::string &word, int begin, int index) 
    {
        wordIndex.push_back(index);
        if(begin < word.size()) 
        {
            if(childNode[word[begin]-'a'] == nullptr) {
                childNode[word[begin]-'a'] = new TrieNode;
            }
            childNode[word[begin]-'a']->add(word, begin + 1, index);
        }
    }

    std::vector<int> find(const std::string &prefix, int begin)
    {
        if(begin == prefix.size()) {
            return wordIndex;
        }
        
        if(childNode[prefix[begin]-'a'] == nullptr) {
            return {};
        }
        else {
            return childNode[prefix[begin]-'a']->find(prefix, begin + 1);
        }

    }
};


class WordFilter
{
private:
    TrieNode *forwardTrie, *backwardTrie;

public:
    WordFilter(std::vector<std::string> &words)
    {
        forwardTrie = new TrieNode();
        backwardTrie = new TrieNode();

        for(int i = 0; i < words.size(); i++)
        {
            std::string word = words[i];
            forwardTrie->add(word, 0, i);
            
            reverse(word.begin(), word.end());
            backwardTrie->add(word, 0, i);
        }

    }

    int f(std::string prefix, std::string suffix)
    {
        std::vector<int> forwardMatch = forwardTrie->find(prefix, 0);

        reverse(suffix.begin(), suffix.end());
        std::vector<int> backwardMatch = backwardTrie->find(suffix, 0);

        //在上面的数组中从后往前搜索到相同的单词即可,因为题目要求找的是最大字符串下标
        auto fIter = forwardMatch.rbegin(), bIter = backwardMatch.rbegin();
        while(fIter != forwardMatch.rend() && bIter != backwardMatch.rend())
        {
            if(*fIter == *bIter) return *fIter;     //表示指向的是同一个单词,则返回单词的序号
            else if(*fIter > *bIter) fIter++;       //否则向前移动,注意:逆向迭代器向前移动是++
            else bIter++;   
        }

        return -1;
    }

};


//解法二:使用hash





/////////////////////
//
//  复杂数据结构的复制
//  133题: 图的深复制
//  138题: 链表的深复制
//
////////////////////

//Leetcode第133题:图的深复制
//哈希的思想

std::unordered_map<Node*, Node*> hash;

Node* cloneGraph(Node* node)
{
    if(node == nullptr) return node;

    if(hash.count(node)) return hash[node];

    hash[node] = new Node(node->val);

    for(auto &w : node->neighbors) {
        hash[node]->neighbors.push_back(cloneGraph[w]);
    }

    return hash[node];
}



//Leetcode第138题 : 链表的深复制
//方法一:使用哈希存储复制好的每个节点

Node* copyRandomList(Node* head)
{
    if(head == nullptr) return head;

    std::unordered_map<Node*, Node*> hash;

    Node *cur = head;
    while(cur) {
        hash[cur] = new Node(cur->val);
        cur = cur->next;
    }

    cur = head;
    while(cur)
    {
        if(cur->next) {
            hash[cur]->next = hash[cur->next];
        }
        if(cur->random) {
            hash[cur]->random = hash[cur->random];
        }
        cur = cur->next;
    }

    return hash[head];
}


//方法二:不使用额外的数据结构(题目出的非常好)
//分三步:
//1.复制每个节点,连接到原始节点后面
//2.为每个复制好的节点指派随机指针
//3.提取出复制好的节点形成一个新链表

Node* copyRandomList(Node *head)
{
    if(head == nullptr) return head;

    Node *cur = head;
    
    //复制每个节点
    while(cur) {
        Node *pNext = cur->next;
        cur->next = new Node(cur->val);
        cur->next->next = pNext;
        cur = pNext;
    }

    //指派随机指针
    cur = head;
    while(cur) {
        if(cur->random) {
            cur->next->random = cur->random->next;  //注意:这个if里面的判断条件不要忘了
        }
        cur = cur->next->next;                      //这是走两步
    }

    //提取出新的链表并且恢复原来的链表(本质上是奇偶链表提取 参考第328题)
    cur = head;
    Node *pCopy = head->next, *pCopyHead = pCopy;       //注意：一行语句如果带有 ","，则先指向前面的部分，再指向后面的部分；但是复制语句时从右往左执行

    //链表奇偶节点拆分(参考LC328题)
    while(pCopy && pCopy->next) {                       //这一题特殊,有效链表节点个数肯定是偶数个,所以while语句中内容可以只为 while(pCopy->next)
        cur = cur->next = pCopy->next;
        pCopy = pCopy->next = cur->next;
    }

    cur->next = nullptr;

    return pCopyHead;
}



////////////////////////////
//
//      线段树
//      Leetcode第307题 
//      Leetcode第303题

//      前缀和
//      第303题:一维数组的前缀和
//      第304题:二维数组的前缀和
//
////////////////////////////

struct SegmentTreeNode {
    int s, e, sum;                  // s代表start, e代表end, 代表此颗节点所代表的数组的[start, end], sum表示之间的和
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int m_s, int m_e) : s(m_s), e(m_e), sum(0), left(nullptr), right(nullptr) {}
};

class SegmentTree
{
private:
    SegmentTreeNode *root;
    
    SegmentTreeNode* buildTree(std::vector<int> &nums, int s, int e)
    {
        if(s > e) return nullptr;

        SegmentTreeNode *res = new SegmentTreeNode(s, e);
        if(s == e) res->sum = nums[s];
        else {
            int mid = s + ((e - s) >> 1);
            res->left = buildTree(nums, s, mid);
            res->right = buildTree(nums, mid + 1, e);
            res->sum = res->left->sum + res->right->sum;
        }

        return res;
    }

    void update(SegmentTreeNode *root, int index, int val)
    {
        if(root->s == root->e) root->sum = val;
        else {
            int mid = root->s + ((root->e - root->s) >> 1);
            if(index <= mid) update(root->left, index, val);
            else update(root->right, index, val);

            root->sum = root->left->sum + root->right->sum;     // 和也要更新
        }

    }

    int sumRange(SegmentTreeNode *root, int s, int e)
    {
        if(root->s == s && root->e == e) return root->sum;

        int mid = root->s + ((root->e - root->s) >> 1);

        if(e <= mid) return sumRange(root->left, s, e);
        else if(s >= mid + 1) return sumRange(root->right, s, e);
        else return sumRange(root->left, s, mid) + sumRange(root->right, mid + 1, e);
    }


public:
    SegmentTree(std::vector<int> &nums) {
        int n = nums.size();
        root = buildTree(nums, 0, n - 1);
    }

    void update(int i, int val) {
        update(root, i, val);       //函数重载
    }

    int sumRange(int i, int j) {
        return sumRange(root, i, j);
    }

};


//Leetcode第307题:

class NumArray
{
public:
    NumArray(std::vector<int> &nums) {
        st = new SegmentTree(nums);
    }

    void update(int i, int val) {
        st->update(i, val);
    }

    void sumRange(int i, int j) {
        return st->sumRange(i, j);
    }

private:
    SegmentTree *st;
};


//Leetcode第303题:
//可以使用前缀和或者线段树都可以

class NumArray 
{
public:
    NumArray(std::vector<int> &nums) {
        st = new SegmentTree(nums);
    }

    int sumRange(int left, int right) {
        return st->sumRange(left, right);
    }

private:
    SegmentTree *st;
};


// Leetcode第304题 : 二维数组的前缀和
// 集中将数组移动一个维度,这样不用讨论row或者col为0的情形
// sum[i+1][j+1] 表示数组i行第j列的累加和 sum(i, j) = sum[i+1][j+1]
// 则(row2,col2) 和 (row1,col1)围成的面积 = sum(row2, col2) - sum(row-1,col2) - sum(row2,col1-1) + sum(row1-1, col1-1)
// ans = sum[row2+1][col2+1] - sum[row1,col2+1] - sum[row2+1,col1] + sum[row1,col1]

// sum[i][j] = matrix[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1], 注意这里 i,j 是从0开始的


class NumMatrix {

std::vector<std::vector<int>> sum;

public:
    NumMatrix(std::vector<std::vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();

        sum = std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                sum[i][j] = matrix[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row1][col2+1] - sum[row2+1][col1] + sum[row1][col1];
    }

};