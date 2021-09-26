/*
    存的是旧解答
*/


//Leetcode第4题:两个排序数组的中位数
// 思路:参看知乎上面的解释
// 时间复杂度O(log(min(m,n)))

double findMedianSortedArrays(std::vector<int> &A, std::vector<int> &B)
{
    int m = A.size(), n = B.size();
    if(m > n) {
        return findMedianSortedArrays(B, A);
    }

    int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;  // 这里长度向上取整的目的是为了让(m+n)为奇数时,中位数出现在左半部分

    while(iMin <= iMax)
    {
        int i = (iMin + iMax) / 2;
        int j = halfLen - i;

        if(i < iMax && B[j-1] > A[i]) {     // 说明i太小了
            iMin = i + 1;
        }
        else if(i > iMin && A[i-1] > B[j]) {  // 说明i太大了
            iMax = i - 1;
        }
        else {                              // 说明i刚好满足
            int maxLeft = 0;
            if(i == 0) maxLeft = B[j-1];
            else if(j == 0) maxLeft = A[i-1];
            else maxLeft = std::max(A[i-1], B[j-1]);

            if((m + n)&1) return maxLeft;   // 和为奇数,则直接返回maxLeft

            int minRight = 0;
            if(i == m) minRight = B[j];
            else if(j == n) minRight = A[i];
            else minRight = std::min(B[j], A[i]);

            return (maxLeft + minRight) / 2.0;
        }
    }

    return 0.0;
}

//更好的解法：参看Youtube

double findMedianSortedArrays(std::vector<int> &A, std::vector<int> &B)
{
    if(A.size() > B.size()) return findMedianSortedArrays(B, A);

    int x = A.size(), y = B.size();

    int low = 0, high = x;

    while(low <= high)
    {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxLeftX = (partitionX == 0) ? INT_MIN : A[partitionX - 1];
        int minRightX = (partitionX == x) ? INT_MAX : A[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : A[partitionY - 1];
        int minRightY = (partitionY == y) ? INT_MAX : A[partitionY];


        if(maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if((x+y)%2 == 0) return (std::max(maxLeftX, maxLeftY) + std::min(minRightX, minRightY)) / 2.0;
            else return std::max(maxLeftX, maxLeftY);
        }
        else if(maxLeftX > minRightY) {
            high = partitionX - 1;
        }
        else {
            low = partitionX + 1;
        }
    }

    return -1;
}



//bigSai双向BFS问题

struct node {
    int x, y;
    std::string path;
    node(int m_x, int m_y, std::string m_path) {
        x = m_x;
        y = m_y;
        path = m_path;
    }
};


void func()
{
    int n = 3;
    std::vector<std::vector<char>> map = {{'A','B','A'}, {'B','B','B'}, {'A','B','A'}};

    std::set<std::string> mySet;    //存储最终结果

    std::queue<node> q1, q2;
    
    for(int i = 0; i < n; i++) 
    {
        // q1.clear(); q2.clear();          //q1存储右下,q2存储左上
        std::queue<node>().swap(q1);        //注:队列没有clear函数
        std::queue<node>().swap(q2);
        std::set<std::string> set1, set2;
        q1.push(node(i, n-1-i, "" + map[i][n-1-i]));
        q2.push(node(i, n-1-i, "" + map[i][n-1-i]));

        while(!q1.empty() && !q2.empty())
        {
            node tmp1 = q1.front(); q1.pop();
            node tmp2 = q2.front(); q2.pop();
            if(tmp1.x == n-1 && tmp1.y == n-1) {    //到达了终点(tmp1到达了终点则tmp2肯定也到达了终点,因为出发点是相同的)
                set1.insert(tmp1.path);
                set2.insert(tmp2.path);
            }
            else {                                  //BFS搜索
                if(tmp1.x < n-1) {  //可以向下
                    q1.push(node(tmp1.x + 1, tmp1.y, tmp1.path + map[tmp1.x+1][tmp1.y]));
                }
                if(tmp1.y < n-1) {  //可以向右
                    q1.push(node(tmp1.x, tmp1.y + 1, tmp1.path + map[tmp1.x][tmp1.y+1]));
                }
                if(tmp2.x > 0) {    //可以向上
                    q2.push(node(tmp2.x - 1, tmp2.y, tmp2.path + map[tmp2.x-1][tmp2.y]));
                }
                if(tmp2.y > 0) {    //可以向左
                    q2.push(node(tmp2.x, tmp2.y - 1, tmp2.path + map[tmp2.x][tmp2.y-1]));
                }
            }
        }

        for(std::string str : set1) {
            if(set2.count(str)) {
                mySet.insert(str);
            }
        }
    }

    std::cout << mySet.size() << std::endl;

}




//Youtube上的生成最短树的prim算法(这个程序有问题)

const int inf = INT_MAX;

struct edge {
    int src, des, weight;
    edge() {}
    edge(int s, int d, int w) : src(s), des(d), weight(w) {}
};

struct Cmp {
    bool operator()(const edge &a, const edge &b) {
        return a.weight > b.weight;
    }
};

std::vector<edge> primAlgorithm(std::vector<std::list<std::pair<int,int>>> graph, edge minEdge)
{
    std::vector<edge> spanningTree;
    std::priority_queue<edge, std::vector<edge>, Cmp> pq;

    while(spanningTree.size() != graph.size() - 1) 
    {
        spanningTree.push_back(minEdge);

        for(auto &item : graph[minEdge.src]) {
            pq.push(edge(minEdge.src, item.first, item.second));
        }

        for(auto &item : graph[minEdge.des]) {
            pq.push(edge(minEdge.des, item.first, item.second));
        }

        pq.pop();
        minEdge = pq.top();         
    }

    return spanningTree;
}


int main() {
    std::vector<std::list<std::pair<int,int>>> graph;
    
    int v = 6, e = 9;   //6个节点,9条边
    std::vector<std::vector<int>> nums = {{0,1,3}, {0,3,1}, {1,2,1}, {1,3,3}, {2,3,1}, {2,4,5}, {2,5,4}, {3,4,6}, {4,5,2}};

    graph.resize(v);
    edge minEdge;
    minEdge.weight = inf;

    for(auto &tmp : nums)
    {
        int src = tmp[0], des = tmp[1], weight = tmp[2];
        graph[src].push_back({des, weight});
        graph[des].push_back({src, weight});

        if(weight < minEdge.weight) {
            minEdge.src = src, minEdge.des = des, minEdge.weight = weight;
        }
    }

    // std::cout << minEdge.src << " " << minEdge.des << " " << minEdge.weight << std::endl;

    std::vector<edge> spanningTree = primAlgorithm(graph, minEdge);
    for(edge x : spanningTree) {
        std::cout << x.src << " " << x.des << " " << x.weight << std::endl;
    }

    return 0; 
}



//三数之和
std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    std::vector<std::vector<int>> res;
    if(nums.size() < 2) return res;

    sort(nums.begin(), nums.end());

    // 这里i的范围一定不能写对了,要不然下面left会造成溢出
    for(int i = 0; i < nums.size() - 2; i++)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue;

        int target = -nums[i];
        int left = i + 1, right = nums.size() - 1;
        while(left < right)
        {
            if(nums[left] + nums[right] == target) {
                res.push_back({i, left, right});
                while(left < right && nums[left] == nums[left+1]) left++;       //这一步相当于去除重复元素
                while(left < right && nums[right] == nums[right-1]) right--;
                left++;
                right--;
            }
            else if(nums[left] + nums[right] < target) {
                left++;
            }
            else if(nums[left] + nums[right] > target) {
                right--;
            }
        }
    }

    return res;
}


//另外一种写法


//memcpy的实现
void* Memcpy(void *des, const void *src, size_t size)
{
    char *pDes = NULL, *pdes = NULL;

    if(NULL == des || NULL == src) {
        return NULL;
    }
    
    if((src < dst) && (char*)src + size > (char*)dst) 
    {
        
        //如果存在内存重叠,则自后往前拷贝        //不能对void指针进行算法操作,所以这里需要转换成char*
        psrc = (char*)src + size - 1;       //char类型的所占的字节数恰好为1
        pdst = (char*)dst + size - 1;
        while(size--) { 
            *pdst-- = *psrc--;
        }
    }
    else 
    {   //不存在内存重叠就从前往后拷贝
        psrc = (char*)src;
        pdst = (char*)dst;
        while(size--) {
            *pdst++ = *psrc--;
        } 
    }

    return (void*)dst;
}



//第639题：在上一题的基础上引入了 '*'(可匹配任意字符,但必须是在 (1,26)之内)

//思路：这一题难点在于边界条件处理

// dp[i] = dp[i-1]*f(s[i]) + dp[i-2]*f(s[i-1..i])
// f(str)表示str的可能解码方式

//注意对'*'的处理，由于str只可能含一个或者两个字符
// 1. str = "*" return 9
// 2. str = "c" c='0' return 0, else return 1
// 3. str = "**" return 15
// 4. str = "*c" c<='6' return 2, else return 1
// 5. str = "c*" c='1' return 9, c = '2' return 6
// 6. str = "cc" '10' <= cc << '26' return 1 else return 0

const int N = 1e9 + 7;

int numDecodings(std::string s)
{
    int n = s.size();

    std::vector<long> dp(n + 1, 0);
    dp[0] = 1, dp[1] = help(s.substr(0, 1));

    for(int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i-1]*help(s.substr(i-1, 1))%N + dp[i-2]*help(s.substr(i-2, 2))%N) % N;
    }

    return dp[n];
}

int help(std::string str)
{
    if(str.size() == 1) {
        if(str[0] == '*') return 9;
        return str[0] == '0' ? 0 : 1;
    }

    if(str == "**") return 15;

    if(str[0] == '*') {
        return str[1] <= '6' ? 2 : 1;
    }

    if(str[1] == '*') {
        if(str[0] == '1') return 9;
        return str[0] == '2' ? 6 : 0;
    }

    return std::stoi(str) >= 10 && std::stoi(str) <= 26 ? 1 : 0;
}



//Leetcode第25题 : K个一组翻转链表

ListNode* reverseKGroup(ListNode *head, int k)
{
    ListNode *base = new ListNode(-1);
    base->next = head;

    ListNode *pre = base;

    while(head)
    {
        ListNode *tail = pre;
        for(int i = 0; i < k; i++) {
            tail = tail->next;
            if(tail == nullptr) return base->next;
        }

        ListNode *pNext = tail->next;

        auto pair = reverse(pre->next, tail);

        pre->next = pair.first;
        pair.second->next = pNext;

        pre = pair.second;
        head = pre->next;
    }

    return base->next;
}

//将[head,tail]之间的节点翻转
std::pair<ListNode*, ListNode*> reverse(ListNode *head, ListNode *tail)
{
    ListNode *prev = nullptr;
    ListNode *cur = head;

    //这种翻转方式要求tail一定不能为空
    while(prev != tail) {
        ListNode *pNext = cur->next;
        cur->next = prev;
        prev = cur;
        cur = pNext;
    }

    return {tail, head};
}


//Leetcode第414题: 找到数组中第三大的数
//思路二: 定义 first, second, thrid 分别代表第一大, 第二大, 第三大的元素
//         thrid < second < first
//遍历数组,对于元素 n
// 1.如果 n > first, 将second复制给thrid, first赋值给second, n赋值给first -> thrid = second, second = first, first = n
// 2.如果 n > second && n < first, 将second复制给thrid, n赋值给first  -> thrid = second, second = n
// 3.如果 n > thrid && n < second, 将n赋值给thrid   -> thrid = n


int thridMax(std::vector<int> &nums)
{
    //注意:这里赋初值不能使用INT_MIN, 因为如果数组中元素含有INT_MIN, 则无法判断是否对thrid做了修改
    long first = LONG_MIN, second = LONG_MIN, thrid = LONG_MIN;

    for(const int &n : nums)
    {
        if(n > first) {
            thrid = second;
            second = first;
            first = n;
        }
        else if(n < first && n > second) {  //注意:这里n<first一定要加,因为规定的是相同元素只能看做一个最大值
            thrid = second;
            second = n;
        }
        else if(n < second && n > thrid){
            thrid = n;
        }
    }

    return thrid == LONG_MIN ? first : thrid;
}


//Leetcode第209:长度最小的子数组
//以后滑动窗口全部写成上面的for循环的形式
int minSubArrayLen(int target, std::vector<int> &nums)
{
    int left = 0, right = 0;

    int sum = 0, minLen = INT_MAX;

    while(right < s.size())
    {
        sum += nums[right];

        while(sum >= target) {
            if(right - left + 1 < minLen) {
                minLen = right - left + 1;
            }
            sum -= nums[left++];
        }

        right++;
    }

    return minLen == INT_MAX ? 0 : minLen;
}



//Leetcode第399题 : Evalute Division
//题目出的非常好

struct Node {
    Node *parent;
    double value = 0.0;
    Node() : parent(this) {}
};

void unionNode(Node *node1, Node *node2, double num, std::unordered_map<std::string, Node*> &map)
{
    Node *parent1 = findParent(node1), *parent2 = findParent(node2);

    double ratio = node2->value * num / node1->value;

    for(auto it = map.begin(); it != map.end(); it++) {
        if(findParent(it->second) == parent1) {
            it->second->value *= ratio;
        }
    }

    parent1->parent = parent2;
}

Node* findParent(Node *node)
{
    if(node->parent == node) return node;

    node->parent = findParent(node->parent);

    return node->parent;
}

std::vector<double> calcEquation(std::vector<std::vector<std::string>> &equations, std::vector<double> &values, std::vector<std::vector<std::string>> &queries)
{
    std::unordered_map<std::string, Node*> map;
    
    std::vector<double> res;

    for(int i = 0; i < equations.size(); i++)
    {
        std::string s1 = equations[i][0], s2 = equations[i][1];

        //让s1做分子,s2做分母
        if(!map.count(s1) && !map.count(s2)) {
            map[s1] = new Node();
            map[s2] = new Node();
            map[s1]->value = values[i];
            map[s2]->value = 1;
            map[s1]->parent = map[s2];
        }
        else if(!map.count(s1)) {
            map[s1] = new Node();
            map[s1]->value = map[s2]->value * values[i];
            map[s1]->parent = map[s2];
        }
        else if(!map.count(s2)) {
            map[s2] = new Node();
            map[s2]->value = map[s1]->val / values[i];
            map[s2]->parent = map[s1];
        }
        else {
            unionNode(map[s1], map[s2], values[i], map);
        }
    }

    for(auto query : queries)
    {
        //如果查询的字符不存在或者  比如a/b, c/d, 现在要查询a/d,这就无法得到,所以要求查询的前后两个字符要有交集,就是判断其是否存在公共父亲
        if(!map.count(query[0]) || !map.count(query[1]) || findParent(map[query[0]]) != findParent(map[query[1]])) 
            res.push_back(-1);
        else
            res.push_back(map[query[0]]->value / map[query[1]]->value);
    }

    return res;
}





////////////////////////
//
//      字符串KMP匹配算法
//
////////////////////////


//计算prefix_table(前缀表)
void prfixTable(const std::string &str, std::vector<int> &next)
{
    next[0] = 0;
    int len = 0;

    int i = 1;
    while(i < str.size())
    {
        if(str[i] == str[len]) {
            len++;
            next[i] = len;
            i++;
        }
        else {
            if(len > 0) {
                len = next[len-1];
            } else {
                next[i] = len;
                i++;
            }
        }
    }

    //next数组从前往后移动一位,第一位赋-1
    // for(int i = 0; i < next.size()-2; i++) {
    //     next[i+1] = next[i];     //注意:这种从前往后复制是错误的
    // }

    for(int i = next.size()-2; i >= 0; i--) {
        next[i+1] = next[i];
    }
    next[0] = -1;

}

void KMP(const std::string &text, const std::string &pattern)
{
    int m = text.size(), n = pattern.size();

    std::vector<int> next(m, 0);

    //计算字符串的前缀表
    prfixTable(text, next);

    //text[i],  len(text) = m
    //patt[j],  len(patt) = n

    int i = 0, j = 0;
    while(i < m)
    {
        if(j == n-1 && text[i] == pattern[j]) {
            printf("Found pattern at %d\n", i - j);     //匹配起点为i-n+1 等价于 i-(n-1) 等价于 i-j
            
            j = next[j];    //接着往下寻找看看后面还有没有其他起点
        }

        if(text[i] == pattern[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];
            if(j == -1) {
                i++;
                j++;
            }
        }
    }
    
}


//Leetcode第103题:之字形层序遍历

//方法一:使用栈(较麻烦)
std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root)
{
    std::vector<std::vector<int>> res;
    if(root == nullptr) return res;

    std::stack<TreeNode*> level[2];
    std::vector<int> tmp;

    int current = 0, next = 1;
    level[current].push(root);

    while(!level[0].empty() || !level[1].empty())
    {
        TreeNode *pNode = level[current].top();
        level[current].pop();
        tmp.push_back(pNode->val);

        if(current == 0) {
            if(pNode->left) {
                level[next].push(pNode->left);
            }
            if(pNode->right) {
                level[next].push(pNode->right);
            }
        }
        else if(current == 1) {
            if(pNode->right) {
                level[next].push(pNode->right);
            }
            if(pNode->left) {
                level[next].push(pNode->left);
            }
        }

        if(level[current].empty())
        {
            res.push_back(tmp);
            tmp.clear();
            
            current = 1- current;
            next = 1 - next;
        }
    }

    return res;
}


//Leetcode第653题:两数之和(输入数组是一个BST)

//方法一:暴力搜索(每个节点都搜索,同样适用于不是BST的情形)
//哈希存储每个遍历过的节点
//递归遍历每个节点只需要遍历一次,所以时间复杂度为O(n)
//最差情况下的递归调用的深度为O(n),所以空间复杂度为O(n)

bool findTarget(TreeNode *root, int k)
{
    std::unordered_set<int> mySet;

    return dfs(root, mySet, k);
}

bool dfs(TreeNode *root, std::unordered_set<int> &mySet, int k)
{
    if(root == nullptr) return false;

    if(mySet.count(k - root->val)) {
        return true;
    }

    mySet.insert(root->val);

    return dfs(root->left, mySet, k) || dfs(root->right, mySet, k);
}




// Leetcode第416题:判断数组是否能切割成相等的两个子数组
// 0-1背包问题
// dp[i][j] 表示前i个数是否能组成j
// dp[i][j] = dp[i-1][j], j < n
//          = dp[i-1][j] || dp[i-1][j-n],  j>=n
//          dp[i-1][j] 代表第i个数不选,则判断前i-1个数是否能组成j;   
//          dp[i-1][j-n] 代表选择第i个数,则判断前i-1个数是否能组成j-n

// base case : i = 0, dp[0][j] = 0;  j = 0. dp[i][0] = 1

bool canPartition(std::vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if(sum&1) return  false;

    int target = sum >> 1;
    int n = nums.size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(target + 1, 0));
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    } 

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= target; j++) {
            if(j < nums[i-1]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
    }

    return dp[n][target];
}


//状态空间压缩
// dp[j] = dp[j], j < n
// dp[j] = dp[j-n], j >= n
// 是从右往左遍历

bool canPartition(std::vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if(sum&1) return  false;

    int target = sum >> 1;

    std::vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for(int i = 0; i < nums.size(); i++) {
        for(int j = target; j >= nums[i]; j--) {
            dp[j] = dp[j] || dp[j-nums[i]];
        }
    }

    return dp[target];
}


//Leetcode第340题: 至多包含k个不同字符的最长子串
//思路：哈希＋滑动窗口

int lengthOfLongestSubStringKDistinct(std::string s, int k)
{
    int left = 0, right = -1;

    int res = -1;
    std::unordered_map<char,int> hash;

    while(left < s.size())
    {
        //注意：这里判断一个元素是否存在maｐ中一定不能用hahs[s[right+1]].因为这样即使s[righ+1]不存在，map在判断完后会默认加入这个元素即hash[s[right+1]] = 0
        if(right + 1 < s.size() && (hash.size() < k || hash.count(s[right+1]))) 
        {
            hash[s[right+1]]++;

            right++;
        }
        else
        {
            if(hash.size() == k && res < (right - left + 1)) {
                res = right - left + 1;
                std::cout << res << std::endl;
            }

            hash[s[left]]--;
            if(hash[s[left]] == 0) {
                hash.erase(s[left]);
            }

            left++;
        }
    }

    return res;
}