
/*
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <sstream>


int main() {
    std::string str;
    getline(std::cin, str);

    std::istringstream in(str);
    std::string out;
    std::vector<std::string> strs;
    while(in >> out) {
        strs.push_back(out);
    }

    std::stack<std::string> sta;
    for(int i = 0; i < strs.size(); i++)
    {
        std::string strCur = strs[i];
        if(strCur == "true" || strCur == "false") 
        {
            if(sta.empty()) {
                sta.push(strCur);
            }
            else {
                std::string strTop = sta.top();
                if(sta.top() == "true" || sta.top() == "false") {
                    std::cout << "error";
                    return 0;
                }
                else {
                    if(strTop == "or") {
                        sta.push(strCur);
                    }
                    else if(strTop == "and") {
                        sta.pop();
                        std::string strPre = sta.top();
                        sta.pop();
                        if(strPre == "false" || strCur == "false") {
                            sta.push("false");
                        }
                    }
                } 
            }
        }
        else    //当前值为"and" 或者 "or"时
        {
            if(sta.empty()) {
                std::cout << "error" << std::endl;
                return 0;
            }
            else {
                std::string strTop = sta.top();
                if(strTop == "and" || strTop == "or") {
                    std::cout << "error" << std::endl;
                    return 0;
                }
                
                sta.push(strCur);
            }
        }
    }

    //判断栈中元素是否之和为true还是false
    //判断最后一个入栈的字符串是否为有效字符
    if(!sta.empty() && (sta.top() == "and" || sta.top() == "or")) {
        std::cout << "error" << std::endl;
        return 0;
    } 

    //现在栈中只有true和false以及or了,只有存在一个true则这个表达式就是true
    while(!sta.empty())
    {
        std::string strCur = sta.top();
        sta.pop();
        if(strCur == "true") {
            std::cout << "true" << std::endl;
            return 0;
        }

        if(sta.empty()) {
            std::cout << "false" << std::endl;
            return 0;
        }
    }

    return 0;
}



/*
//时间复杂度O(n^2)
int subarraySum(std::vector<int> &nums, int k)
{
    int n = nums.size();
    std::vector<int> preSum(n + 1, 0);
    int ans = 0;

    for(int i = 1; i <= n; i++) {
        preSum[i] = preSum[i-1] + nums[i-1];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            if(preSum[i] - preSum[j] == k) {
                ans++;
            }
        }
    }
    
    return ans;
}



//优化,使用哈希表,记录该前缀和出现的次数
//时间复杂度O(n)
int subarraySum(std::vector<int> &nums, int k)
{
    int count = 0, preSum = 0;
    std::unordered_map<int, int> hash;
    hash[0] = 1;

    for(const int &num : nums) {
        preSum += num;
        count += hash[preSum-k];
        hash[preSum]++;
    }

    return count;
}
 */
/*

#include <iostream>
#include <climits>
#include <queue>
#include <sstream>

int countPrimes(int n);
int minCut(std::string s);

int main() {
    // std::string s = "aab";
    // std::cout << minCut(s) << std::endl;
    std::string str = "hello";

    std::istringstream in(str);
    std::string out;
    while(in) {
        in >> out;
        std::cout << out << std::endl;
    }
 

    return 0;
}

//埃式筛法
/*

//切割成回文串的最小次数

int minCut(std::string s)
{
    if(s.empty()) return 0;

    int res = 0;
    int len = s.size();
    std::vector<int> dp(len + 1);   //dp[i]表示str[i..len-1]的最小切割次数
    dp[len] = -1;

    std::vector<std::vector<int>> valid(len, std::vector<int>(len, 0));
    for(int i = len - 1; i >= 0; i--) 
    {
        dp[i] = INT_MAX;
        for(int j = i; j < len; j++) 
        {
            if(s[i] == s[j] && (j-i < 2 || valid[i+1][j-1])) {
                valid[i][j] = 1;
                dp[i] = std::min(dp[i], dp[j+1] + 1);
            }
        }
    }

    return dp[0];
}


ListNode *sortList(ListNode *head)
{
    if(head == nullptr) return head;

    ListNode *dummy = new ListNode(-1);
    dummy->next = head;

    ListNode *pCur = head;
    ListNode *pNex = head->next;
    ListNode *pTmp = head;

    while(pNex)
    {
        while(pCur->val <= pNex->val) {
            if(pNex == nullptr) {
                return dummy->next;
            }
            pCur = pCur->next;
            pNex = pNex->next;
            continue;   
        }

        //找到新元素的插入位置
        pTmp = dummy;   
        while(pTmp->next->val <= pNex->val) {
            pTmp = pTmp->next;
        }

        pCur->next = pNex->next;
        pNex->next = pTmp->next;
        pTmp->next = pNex;

        pNex = pCur->next;
    }

    return dummy->next;
}

int trap(std::vector<int> &height)
{
    if(height.size() <= 2) return 0;

    std::stack<int> sta;
    int res = 0;

    int i = 0;
    while(i < height.size())
    {
        if(sta.empty() || height[i] <= height[sta.top()]) {
            sta.push(i++);
        }
        else 
        {
            int midIndex = sta.top();
            sta.pop();

            if(!sta.empty()) {
                int minHeight = std::min(height[i], height[sta.top()]) 
                res += (i - sta.top() - 1) * (minHeight - height[midIndex]);
            }
        }
    }

    return res;
}
*/
/*

//Leetcode第84题 : 直方图的最大矩形面积
//思路:单调栈

int largestRectangleArea(std::vector<int> &height)
{
    int res = 0;
    if(height.empty()) return res;

    std::stack<int> index;
    height.push_back(0);        //末尾加一个0是为了防止数组都是递增的

    for(int i = 0; i < height.size(); i++)
    {
        while(!index.empty() && height[i] < height[index.top()])
        {
            int curHeight = height[index.top()];
            index.pop();
            int left = index.empty() ? -1 : index.top();
            res = max(res, curHeight*(i - left - 1));
        }

        index.push(i);
    }

    return res;
}


//Leetcode第85题 : 0和1组成的最大的矩形面积

int maximalRectangle(std::vector<std::vector<char>> &matrix)
{
    if(matrix.empty()) return 0;
    
    int col = matrix[0].size();
    std:vector<int> height(col, 0);
    int res = 0;

    for(auto row : matrix)
    {
        for(int i = 0; i < col; i++) {
            height[i] = (row[i] == '1') ? height[i] + 1 : 0;
        }

        res = std::max(res, largestRectangleArea(height));  //调用上面的计算直方图的面积函数
    }

    return res;
}


int trap(std::vector<int> &height)
{
    if(height.size() <= 2) return 0;

    int res = 0;
    std::stack<int> index;

    for(int i = 0; i < height.size(); i++)
    {
        if(index.empty() || height[i] <= height[index.top()]) {
            index.push(i);
            continue;
        }

        while(!index.empty() && height[i] > height[index.top()]) {
            int midIndex = index.top();
            index.pop();

            if(!index.empty()) {
                int minHeight = std::min(height[i], height[index.top()]);
                res += (i - sta.top() - 1) * (minHeight - height[midIndex]);
            }
        }
        index.push(i);
    }

    return res;
}


//第232题: 队列的实现

//方法一:两栈实现一个队列

class MyQueue
{
public:
    std::stack<int> in, out;

    MyQueue() {

    }

    void push() {
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
        if(out.empty()) 
        {
            while(!in.empty()) {
                int x = in.top();
                in.pop();
                out.push(x);
            }
        }
    }

};


//方法二:用数组实现队列




//Leetcode第225题 : 用队列实现栈

*/
/*
#include <iostream>
#include <vector>
#include <cmath>

//大话数据结构P117

class MyQueue
{
public:
    int *nums;
    int size;
    int front;
    int rear;

    MyQueue(int size = 0) {
        nums = new int[size+1];
        this->size = size + 1;
        this->front = 0;
        this->rear = 0;
    }

    void push(int x) {
        //判断队列是否已满
        if((this->rear + 1)%size == this->front) return;

        nums[rear] = x;
        rear = (rear + 1)%size;
    }

    void pop() {
        if(this->front == this->rear) return;   //队列为空

        //front指针向后移动一位置
        this->front = (this->front + 1)%size;
    }

    int peek() {
        int x = nums[front];
        this->front = (this->front + 1)%size;

        return x;
    } 

    int m_size() {
        return size - 1;
    }

};

int dfs(int n);
int dfs(int n, int &num);

int count = 0;

int main() {

    int num = 0;
    // std::cout << dfs(220) << std::endl;
    dfs(28, num);
    std::cout << num << std::endl;

    return 0;
}

//思路:比它要么变成9,要么不变
//变成9就要向上一位借位

//找到最大的乘积
int dfs(int n)
{
    if(n == 0) return 1;
    if(n < 10) return n;

    return std::max(dfs(n/10-1)*9, dfs(n/10)*(n%10));
}


std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
{
    std::deque<int> dq;
    std::vector<int> ans;

    for(int i = 0; i < nums.size(); i++) 
    {
        if(!dq.empty() && dq.front() == i-k) {
            dq.pop_front();
        }

        while(!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if(i >= k-1) ans.push_back(nums[dq.front()]);
    }

    return ans;
}

std::vector<int> dailyTemperatures(std::vector<int> &T)
{
    if(T.empty()) return {};

    std::vector<int> res(T.size(), 0);
    std::stack<int> index;

    for(int i = 0; i < T.size(); i++)
    {
        while(!index.empty() && T[i] > T[index.top()]) {
            int tmpIndex = index.top();
            res[tmpIndex] = i - tmpIndex;
        }

        index.push(i);
    }

    return res;
}
*/
/*
#include <iostream>
#include <vector>
#include <list>

std::vector<int> findDuplicate(std::vector<int> &nums);
std::vector<int> countPrime(int n);

int main() {
    std::list<int> list1, list2;
    for(int i = 1; i <= 4; i++) {
        list1.push_back(i);
        list2.push_back(i + 10);
    }

    list1.splice(list1.begin(), list2, list2.begin());

    for(auto it:list1) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    
    for(auto it : list2) {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    return 0;
}


std::vector<int> findDuplicate(std::vector<int> &nums)
{
    std::vector<int> res;

    for(int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;
        if(nums[index] < 0) {
            res.push_back(nums[i]);
            continue;                  //这个continue加不加都可
        }

        nums[index] = -nums[index];
    }

    return res;
}

std::vector<int> countPrime(int n)
{
    std::vector<int> prime(n + 1, 1);

    for(int i = 2; i*i <= n; i++) 
    {
        if(prime[i]) {
            for(int j = i*i; j <= n; j+=i) {
                if(prime[j]) {
                    prime[j] = 0;
                }
            }
        }
    }

    std::vector<int> res;
    for(int i = 2; i <= n; i++) {
        if(prime[i]) {
            res.push_back(i);
        }
    }

    return res;
}
*/

/*
#include <iostream>
#include <vector>
#include <climits>

int maxProfit(std::vector<int> &prices);

const int N = 10;
int dp[N];

int main() {
    // std::vector<int> prices = {1,2,3,4,5};
    // std::cout << maxProfit(prices) << std::endl;
    // std::vector<std::vector<int>> (3, )
    std::vector<std::vector<std::vector<int>>> dp(3, std::vector<std::vector<int>>(3, std::vector<int>(3, 0)));

    std::vector<std::vector<int>>
    

    return 0;
}

int maxProfit(std::vector<int> &prices)
{
    int n = prices.size();
    int dp[n][3][2] = {0};

    for(int i = 0; i < n; i++)
    {
        for(int k = 1; k <= 2; k++)
        {
            if(i == 0) {
                dp[i][k][0] = 0;
                dp[i][k][1] = -prices[i];
            }
            else {
                dp[i][k][0] = std::max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
                dp[i][k][1] = std::max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
            }
        }
    }

    return dp[n-1][2][0];
}

int maxProfit(std::vector<int> &prices)
{
    int n = prices.size();
    int dp[n][3][2] = {0};
    std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(3, std::vector<int>(2, 0)));

    for(int i = 0; i < n; i++)
    {
        for(int k = 2; k > 0; k--)
        {
            if(i == 0) {
                dp[i][k][0] = 0;
                dp[i][k][1] = -prices[i];
            }
            else {
                dp[i][k][0] = std::max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
                dp[i][k][1] = std::max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
            }
        }
    }

    return dp[n-1][k][0];
}


//第212题: 在字符矩阵中查找是否存在给定集合中的字符串
//思路 : 构造一个字典树来方便搜索

class TrieNode 
{
public:
    TreeNode *childNode[26];
    std::string word;

    TrieNode() {
        memset(childNode, NULL, sizeof(childNode));
    }

};

TrieNode* buildTree(std::vector<std::string> words)
{
    TrieNode *root= new TrieNode;

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

    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            dfs(board, i, j, root, res);
        }
    }

    return res;
}

void dfs(std:vector<std::vector<char>> &board, int i, int j, TrieNode *root, std::vector<std::string> &res)
{
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;

    char c = board[i][j];
    if(c == '#' || root->childNode[c-'a'] == nullptr) return;

    root = root->childNode[c-'a'];

    if(!(root->word.empty())) {
        res.push_back(root->word);
        root->word.clear();         //找到了就将其置空,防止重复遍历
        // return;                  //这里不能返回,因为可能存在前缀相同的字符串,比如 "helo"和 "hello"
    }

    board[i][j] = '#';
    
    dfs(board, i, j + 1, root, res);
    dfs(board, i, j - 1, root, res);
    dfs(board, i + 1, j, root, res);
    dfs(board, i - 1, j, root, res);

    board[i][j] = c;
}

*/
/*
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {1,2,3,4};
    int res = 0;

    while(nums.size() > 1)
    {
        sort(nums.begin(), nums.end());
        nums[1] += nums[0];
        res += nums[1];
        nums.erase(nums.begin());
    }

    std::cout << res << std::endl;

    return 0;
}


//1.任意合并
//贪心的思想,每次找最小的两个数据合并就行

int stoneCombineCost(std::vector<int> nums)
{
    int res = 0;

    while(nums.size() > 1)
    {
        sort(nums.begin(), nums.end());
        nums[1] += nums[0];
        res += nums[1];
        nums.erase(nums.begin());
    }

    return res;
}

//2.只能合并相邻的两个石头
//dp[i][j]表示第i到第j堆石子合并的最优值,sum[i][j]表示从第i堆到第j堆石子的花费
// dp[i][j] = 0, i==j
// dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum(i,j))   //枚举[i,j]之间的所有的k

int stoneCombineCost(std::vector<int> nums)
{
    int n = nums.size();

    std::vector<std::vector<int>> dp(n, std::vector<int>(n, INT_MAX));

    std::vector<int> sum(n, 0);
    sum[0] = nums[0];
    for(int i = 1; i < n; i++) {
        sum[i] = sum[i-1] + nums[i];
    }

    for(int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    for(int len = 1; len < n; len++) {    //j表示长度
        for(int i = 0; i < n && i+j < n; i++) {
            int j = i + len;    //j用i加上长度来确定
            int tmp = sum[j] - (i > 0 ? sum[i-1] : 0);  //获取[i,j]之间的总和
            for(int k = i; k < j; k++) {
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k+1][j] + tmp);
            }
        }
    }
    
    return dp[0][n-1];
}


//思路:最小的满足要求的子数组和为数组中单个元素的最大值,最大的满足要求的子数组的和为数组元素总和
//在这个范围内寻找满足条件m的最小的值

int splitArray(std::vector<int> &nums, int m)
{
    int maxVal = 0;
    long sum = 0;
    for(const int &n : nums) {
        maxVal = std::max(maxVal, n);
        sum += n;
    }

    long left = maxVal, rightt = sum;

    while(left <= rightt)
    {
        long mid = left + ((rightt-left) >> 1);
        if(isValid(nums, m, mid)) {
            rightt = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return left;
}

bool isValid(std::vector<int> &nums, int n, int target)
{
    int count = 1;      //注意count的初始值为1,因为至少肯定需要一个子数组
    long total = 0;

    for(const int &num : nums) 
    {
        total += num;
        if(total > target) {    //大于目标值则肯定还需要一个子数组
            total = num;
            count++;
            if(count > n) {
                return false;
            }
        }
    }

    return true;
}

bool isValid(std::string s)
{
    if(s.empty()) return false;

    std::stack<char> sta;

    for(const char &c : s)
    {
        switch(c) {
            case '{':
            case '[':
            case '(': sta.push(c); break;
            case '}': if(sta.empty() || sta.top() != '{') return false; else sta.pop(); break;
            case ']': if(sta.empty() || sta.top() != '[') return false; else sta.pop(); break;
            case ')': if(sta.empty() || sta.top() != '(') return false; else sta.top(); break;
        }
    }

    return sta.empty();
}


std::vector<std::vector<int>> levelOrder(TreeNode *root)
{
    std::vector<std::vector<int>> res;
    if(root == nullptr) return res;

    std::queue<TreeNode*> que;
    que.push(root);

    while(!que.empty())
    {
        int n = que.size();
        std::vector<int> tmp;

        for(int i = 0; i < n; i++) 
        {
            TreeNode *pNode = que.front();
            que.pop();
            tmp.push_back(pNode->val);

            if(pNode->left) {
                que.push(pNode->left);
            }

            if(pNode->rightt) {
                que.push(pNode->rightt);
            }
        }

        res.push_back(tmp);
    }

    return res;
}


int deepestLeaveSum(TreeNode *root)
{
    if(root == nullptr) return 0;

    std::queue<TreeNode*> que;
    que.push(root);
    int res = 0;

    while(!que.empty())
    {
        int n = que.size();
        res = 0;
        for(int i = 0; i < n; i++) 
        {
            TreeNode *pNode = que.front();
            que.pop();

            res += pNode->val;

            if(pNode->left) {
                que.push(pNode->left);
            }

            if(pNode->rightt) {
                que.push(pNode->rightt);
            }
        }
    }

    return res;
}


std::vector<int> preorderTraversal(TreeNode *root)
{
    std::vector<int> res;
    if(root == nullptr) return res;

    std::stack<TreeNode*> sta;
    sta.push(root);

    while(!sta.empty())
    {
        TreeNode *pNode = sta.top();
        sta.pop();

        res.push_back(pNode->val);

        if(pNode->left) {
            sta.push(pNode->left);
        }

        if(pNode->rightt) {
            sta.push(pNode->rightt);
        }
    }

    reverse(res.begin(), res.end());

    return res;
}

std::vector<int> inorderTraversal(TreeNode *root)
{
    std::vector<int> res;
    if(root == nullptr) return res;

    std::stack<TreeNode*> sta;

    TreeNode *pNode = root;

    while(!sta.empty() || pNode)
    {
        while(pNode) {
            sta.push(pNode);
            pNode = pNode->left;
        }

        pNode = sta.top();
        sta.pop();
        res.push_back(pNode->val);

        if(pNode->rightt) {
            pNode = pNode->rightt;
        }
    }

    return res;
}


//注意:是k个最大的元素
int findKthLargest(std::vector<int> &nums, int k)
{
    if(k < 0 || k > nums.size()) return -1;

    int index = partition(nums, 0, nums.size() - 1);

    k = nums.size() - k;

    while(index != k)
    {
        if(index < k) {
            index = partition(nums, index + 1, nums.size() - 1);
        }
        else {
            index = partition(nums, 0, index - 1);
        }
    }
    
    return nums[index];
}


int partition(std::vector<int> &nums, int left, int rightt)
{
    int pivot = nums[left];

    while(left < rightt)
    {
        while(left < rightt && nums[rightt] >= pivot) rightt--;
        std::swap(nums[left], nums[rightt]);

        while(left < rightt && nums[left] <= pivot) left++;
        std::swap(nums[left], nums[rightt]);
    }

    return left;
}

//使用双端队列来模拟一个滑动窗口
//队列的首部始终是窗口内的最大值

std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
{
    std::deque<int> dq;
    std::vector<int> ans;

    for(int i = 0; i < nums.size(); i++)
    {
        //入队检查1:判断队首元素是否还应该在窗口中
        if(!dq.empty() && i-dq.front() == k) {
            dq.pop_front();
        }

        //入队检查2:判断当前元素是否大于队列中元素,如果大于就将队列中元素出队列
        while(!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        //入队列(这时经过上两步就能保证这时的队列队收元素就是窗口内的最大值)
        dq.push_back(i);

        if(i >= k-1) ans.push_back(nums[dq.front()]);
    }

    return ans;
}

bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
{
    int m = matirx.size(), n = matirx[0].size();

    int i = 0, j = n-1;

    while(i < m && j >= 0)
    {
        if(target > matirx[i][j]) i++;
        else if(target < matirx[i][j]) j--;
        else if(target == matirx[i][j]) return true;
    }

    return false;
}

bool isAnagrams(std::string s, std::string t)
{
    if(s.size() != t.size()) return false;

    std::vector<int> count(26, 0);

    for(int i = 0; i < s.size(); i++) {
        count[s[i]-'a']++;
        count[t[i]-'a']--;
    }

    for(int i = 0; i < 26; i++) {
        if(count[i]) return false;
    }

    return true;
}

*/

/*
#include <iostream>
#include <vector>
#include <cmath>

bool find24(std::vector<double> nums);

double epison = pow(10.0, -5);

std::vector<char> operations = {'+', '-', '*', '/'};

bool judgePoint24(std::vector<int> &nums)
{
    std::vector<double> numbers;
    for(const int &n : nums) {
        numbers.push_back(n*1.0);
    }

    return find24(numbers);
}

bool find24(std::vector<double> nums)
{
    if(nums.size() == 1) {
        return fabs(nums[0] - 24) < epison;
    }

    for(int i = 0; i < nums.size(); i++) 
    {
        for(int j = 0; j < nums.size(); j++)    //每次比较两个数
        {
            if(i == j) continue;

            std::vector<double> res;
            for(int k = 0; k < nums.size(); k++) {
                if(k != i && k != j) res.push_back(nums[k]);    //将其余的数放到新数组中用于递归
            }

            for(char &op : operations)
            {
                if((op == '+' || op == '*') && i > j) continue;    //这这种运算符满足交换律
                if(op == '/' && (nums[j] < epison)) continue;      //除数不能为0

                switch(op) {
                    case '+' : res.push_back(nums[i] + nums[j]); break;
                    case '-' : res.push_back(nums[i] - nums[j]); break;
                    case '*' : res.push_back(nums[i] * nums[j]); break;
                    case '/' : res.push_back(nums[i] / nums[j]); break;
                }

                if(find24(res)) return true;
                res.pop_back();     //这里一定要弹出
            }
        }
    }

    return false;
}



int main() {
    std::vector<int> nums = {1,2,1,2};

    std::cout << judgePoint24(nums) << std::endl;

    return 0;
}

std::vector<int> findDuplicate(std::vector<int> &nums)
{
    std::vector<int> res;

    for(int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i) - 1;
        if(nums[index] < 0) {
            res.push_back(abs(nums[i]));
            continue;
        }

        nums[index] *= -1;
    }

    return res;
}

std::vector<int> findDisappearedNumbers(std::vector<int> &nums)
{
    std::vector<int> res;

    for(int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;
        if(nums[index] > 0) {
            nums[index] *= -1;
        }
    }

    for(int i = 0; i < nums.size(); i++) {
        if(nums[index] > 0) {
            res.push_back(i + 1);
        }
    }

    return res;
}


void wiggleSort(std::vector<int> &nums)
{
    int tmp = nums;
    sort(tmp.begin(), tmp.end());

    int i = n/2, j = tmp.size() - 1;
    for(int k = 0; k < nums.size(); k++)
    {
        if(k & 1) {
            nums[k] = nums[j--];
        }
        else {
            nums[k] = nums[i--];
        }
    }

}


ListNode* oddEvenList(ListNode *head)
{
    if(head == nullptr) return head;

    ListNode *l1 = new ListNode(-1);
    ListNode *l2 = new ListNode(-1);

    ListNode *l1Head = l1, *l2Head = l2;

    int n = 1;
    while(head)
    {
        if(n&1) {
            l1->next = head;
            l1 = l1->next;
        }
        else {
            l2->next = head;
            l2 = l2->next;
        }
        
        head = head->next;
        n++;
    }

    l2->next = nullptr;
    
    l1->next = l2Head->next;

    return l1Head->next;
}


ListNode* oddEvenList(ListNode *head)
{
    if(head == nullptr) return head;

    ListNode *pOdd = head;
    ListNode *pEven = head, pEvenHead= pEven;

    while(pEven && pEven->next)
    {
        pOdd = pOdd->next = pEven->next;
        pEven = pEven->next = pOdd->next;
    }

    pOdd->next = pEvenHead;

    return head;
}


//Leetcode第214题:在字符串首部添加字符计算构成的完整的最短回文串的长度

//思路:计算包含首字符的最长回文串,之后将剩下的字符串翻转加在字符串首部即是最短的回文串

std::string shortestPalindrome(std::string s)
{
    int n = s.size();
    if(n < 2) return s;

    int longestLen = 0;     //最长回文串的长度
    int startIndex = 0;     //最长回文串的左边界下标

    int i = 0;      //包括首字符的最长回文串的下标
    while(i <= n/2)
    {
        int start, end;
        start = end = i;

        while(end + 1 < n && s[end] == s[end+1]) end++;

        i = end + 1;

        while(start - 1 >= 0 && end + 1 < n && s[start-1] == s[end+1]) {
            start--;
            end++;
        }

        //必须包含start = 0才行
        if(start == 0 && longestLen < end-start+1) {
            longestLen = end - start + 1;
            startIndex = start;
        }
    }

    std::string remain = s.substr(startIndex + longestLen);

    reverse(remain.begin(), remain.end());

    return remain + s;
}


std::string removeDuplicates(std::string S)
{
    std::string str;
    for(const char &c : S) {
        if(!str.empty() && str.back() == c) str.pop_back();
        else str.push_back(c);
    }

    return res;
}

std::string removeDuplicates(std::string s, int k)
{
    std::vector<std::pair<int, char>> strs;

    for(int i = 0; i < s.size(); i++)
    {
        if(strs.empty() || strs.back().second != s[i]) {
            strs.push_back({1, s[i]});
        }
        else if(++strs.back().first == k) {
            strs.pop_back();
        }
    }

    std::string res;
    for(int i = 0; i < strs.size(); i++) {
        res += std::string(strs[i].first, strs[i].second);
    }

    return res;
}

*/

/*
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>

// std::vector<int> topKFrequent(std::vector<int> &nums, int k);

// struct Cmp
// {
//     bool operator()(const std::pair<int,int> &a, const std::pair<int,int> &b) {
//         return a.second > b.second;
//     }

// };


struct Test
{
    int x;
    Test(int n) : x(n) {}
    // bool operator<(const Test &demo) const {
    //     return x < demo.x;
    // }

};

struct Cmp {
    bool operator()(const Test &a, const Test &b) {
        return a.x < b.x;
    }
};

int main() {
    std::priority_queue<Test, std::vector<Test>, Cmp> pq;
    pq.push(Test(1));
    pq.push(Test(2));
    pq.push(Test(3));

    while(!pq.empty()) {
        std::cout << pq.top().x << std::endl;
        pq.pop();
    }


    // std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, Cmp> pq;
    // std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;

    // pq.push({1,2});
    // pq.push({2,3});
    // pq.push({3,4});

    // while(!pq.empty()) {
    //     std::cout << pq.top().second << std::endl;
    //     pq.pop();
    // }

    // std::priority_queue<int, std::vector<int>,  std::greater<int>> pq;

    // pq.push(1);
    // pq.push(2);
    // pq.push(3);

    // while(!pq.empty()) {
    //     std::cout << pq.top() << std::endl;
    //     pq.pop();
    // }

    // std::vector<int> nums = {1,1,1,2,2,3};
    // int k = 2;

    // std::vector<int> res = topKFrequent(nums, k);

    // for(int n : res) {
    //     std::cout << n << std::endl;
    // }

    return 0;
}

std::vector<int> topKFrequent(std::vector<int> &nums, int k)
{
    std::unordered_map<int,int> hash;

    for(const int &n : nums) {
        hash[n]++;
    }

    std::vector<int> res;
    std::priority_queue<std::pair<int,int>> pq;

    for(auto it = hash.begin(); it != hash.end(); it++) 
    {
        pq.push(std::make_pair(it->second, it->first));
        if(pq.size() > hash.size() - k) {       //注意:这里是 > 
            res.push_back(pq.top().second);
            pq.pop();
        }
    }

    return res;
}


struct Cmp
{
    bool operator()(const std::pair<std::string,int> &a, const std::pair<std::string,int> &b) {
        if(a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second;
    }
};

std::vector<std::string> topKFrequent(std::vector<std::string> &words, int k)
{
    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string,int>>, Cmp> pq;
    std::unordered_map<std::string, int> hash;

    for(const std::string word : words) {
        hash[word]++;
    }

    for(auto it = hash.begin(); it != hash.end(); it++) {
        pq.push(std::make_pair(it->first, it->second));
    }

    std::vector<std::string> res;

    for(int i = 0; i < k; i++) {
        res.push_back(pq.top().first);
        pq.pop();
    }

    return res;
}


//Leetcode第378题:杨氏矩阵中第k小的元素
//二分查找寻找左边界

int kthSmallest(std::vector<std::vector<int>> &matrix, int k)
{
    if(matrix.empty()) return -1;

    int n = matrix.size();
    int left = matrix[0][0], rightt = matrix[n-1][n-1];

    while(left <= rightt)
    {
        int mid = left + ((rightt-left) >> 1);
        int count == 0;
        for(int i = 0; i < n; i++) {
            int num = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            count += num;
        }

        if(count < k) {
            left = mid + 1;     //向右扩大边界
        }
        else if(count >= k) {
            rightt = mid - 1;    //向左缩小边界
        }

    }
    
    return left;
}
*/

/*
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

/*
std::vector<std::vector<int>> res;
void dfs(std::vector<int> &nums, std::vector<int> &path, int target, int pos);

std::vector<std::vector<int>> combinationSum(std::vector<int> &nums, int target)
{
    std::vector<int> path;

    dfs(nums, path, target, 0);

    return res;
}


void dfs(std::vector<int> &nums, std::vector<int> &path, int target, int pos)
{
    if(target == 0) {
        res.push_back(path);
        return;
    }
    if(target < 0) return;

    for(int i = pos; i < nums.size(); i++) {
        path.push_back(nums[i]);
        dfs(nums, path, target - nums[i], i);      //如果传递的是引用,后面要加一个pop_back()
        path.pop_back();
    }

} 

*/

// std::vector<std::vector<int>> res;void dfs(int k, int target, std::vector<int> &path, int pos);


// std::vector<std::vector<int>> combinationSum3(int k, int n)
// {
//     std::vector<int> path;

//     dfs(k, n, path, 1);

//     return res;
// }

// void dfs(int k, int target, std::vector<int> &path, int pos)
// {
//     if(target == 0 && path.size() == k) {
//         res.push_back(path);
//         return;
//     }

//     if(target < 0) return;

//     for(int i = pos; i <= 9; i++)
//     {
//         path.push_back(i);
//         dfs(k, target-i, path, i+1);
//         path.pop_back();
//     }     

// }
/*
std::unordered_map<int,int> hash;

int combinationSum4(std::vector<int> &nums, int target)
{
    if(target < 0) return 0;

    if(target == 0) return 1;

    if(hash.count(target)) {        //注意:这里用hash[target]最后一个例子过不了
        return hash[target];
    }

    int count = 0;
    for(int i = 0; i < nums.size(); i++) {
        count += combinationSum4(nums, target-nums[i]);
    }

    hash[target] = count;

    return count;
}



int main() {
    // std::vector<int> nums = {1,2,3};
    // int target = 4;

    // std::cout << combinationSum4(nums, target) << std::endl;

    std::vector<int> nums = {1,2,3};

    for(const int &n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}


/*
int threeSumCloset(std::vector<int> &nums, int target)
{
    int diff = INT_MAX;

    if(nums.size() < 3) return diff;

    for(int i = 0; i < nums.size()-2 && diff; i++)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue;

        int left = i + 1, rightt = nums.size() - 1;

        while(left < rightt)
        {
            int sum = nums[i] + nums[left] + nums[rightt];

            if(abs(diff) > abs(sum-target)) {
                diff = sum - target;
                if(diff == 0) break;
            }

            if(sum < target) {
                left++;
            }
            else if(sum > target) {
                rightt--;
            }
        }
    }

    return diff + target;
}

std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    std::vector<std::vector<int>> res;
    if(nums.size() < 2) return res;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size() - 2; i++)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue;

        int target = -nums[i];
        int left = i+1, rightt = nums.size() - 1;
        while(left < rightt)
        {
            if(nums[left] + nums[rightt] == target) {
                res.push_back({nums[i], nums[left], nums[rightt]});
                while(left < rightt && nums[left] == nums[left+1]) left++;       //这一步相当于去除重复元素
                while(left < rightt && nums[rightt] == nums[rightt-1]) rightt--;
                left++;
                rightt--;
            }
            else if(nums[left] + nums[rightt] < target) {
                left++;
            }
            else if(nums[left] + nums[rightt] > target) {
                rightt--;
            }
        }
    }

    return res;
}


/*
int numSubmatrixSumTarget(std::vector<std::vector<int>> &matrix, int target)
{
    int m = matrix.size(), n = matrix[0].size();
    for(int i = 0; i < m; i++) {
        for(int j = 1; j < n; j++) {
            matrix[i][j] += matrix[i][j-1];     ///对每一行,计算前缀和
        }
    }

    std::unordered_map<int,int> hash;

    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            hash = {{0,1}};         //每次计算其他列时这个hash表要重新清零
            int cur = 0;
            for(int k = 0; k < m; k++) {
                cur += matrix[k][j] - (i > 0 ? matrix[k][i-1] : 0);     //计算列范围[i,j]之间的和  k表示行的范围
                res += hash[cur-target];                               
                hash[cur]++;
            }
        }
    }

    return res;
}


int pivotIndex(std::vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);

    int leftSum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(leftSum = sum - nums[i] - leftSum) {
            return i;
        }
        leftSum += nums[i];
    }

    return -1;
}
*/

/*
std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>> &people)
{
    sort(people.begin(), people.end(), [](std::vector<int> a, std::vector<int> b) {
        return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]); 
    });

    std::vector<std::vector<int>> res;

    for(auto &vec : people) {
        res.insert(res.begin() + vec[1], vec);
    } 

    return res;
}

*/

/*
std::string convertToBase7(int n)
{
    std::string res;

    while(n) {
        res = ('A' + (n-1)%26) + res;
        n = (n-1) / 26;
    }

    return res;
}


int trap(std::vector<int> &height)
{
    std::stack<int> sta;
    int res = 0;

    for(int i = 0; i < height.size(); i++) 
    {
        while(!sta.empty() && height[i] >= height[sta.top()]) {
            int mid = sta.top();
            sta.pop();
            if(!sta.empty()) {
                int hei = std::min(height[i], height[sta.top()]) - height[mid];
                int wide = i - sta.top() - 1;
                res += hei*wide;
            }
        }

        sta.push(i);
    }

    return res;
}


std:::vector<int> dailyTemperatures(std::vector<int> &T)
{
    std::stack<int> sta;
    std::vector<int> res(T.size(), 0);

    for(int i = 0; i < T.size(); i++)
    {
        while(!sta.empty() && T[i] > T[sta.top()])) {
            res[sta.top()] = i - sta.top();
            sta.pop();
        }

        sta.push(i); 
    }

    return res;
}

std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2)
{
    //对nums2建立一个哈希,mp[n1]=n2,代表nums2数组中第一个比n1大的元素为n2
    //依次判断nums1中的元素在哈希表中的value,如果存在就说明第一个最大的元素就是hash[nums1]

    std::stack<int> sta;
    std::unordered_map<int,int> hash;
    for(const int &n : nums2) 
    {
        while(!sta.empty() && n > sta.top()) {
            mp[sta.top()] = n;
            sta.pop();
        }

        sta.push(n);
    }

    std::vector<int> res(nums1.size(), -1);
    for(int i = 0; i < nums1.size(); i++) {
        if(mp.count(nums1[i])) {
            res[i] = mp[nums1[i]];
        }
    }

    return res;
}

std::vector<int> nextGreaterElement(std::vector<int> &nums)
{
    int n = nums.size();
    std::stack<int> sta;
    std::vector<int> res(n, -1);


    for(int i = 0; i < 2*n; i++)
    {
        while(!sta.empty() && nums[i%n] > nums[sta.top()]) {
            res[sta.top()] = nums[i%n];
            sta.pop();
        }

        sta.push(i%n);
    }

    return res;
}


//Leetcode第556题:

//思路:转化成字符串

int nextGreaterElement(int n)
{
    std::string str = std::to_string(n);
    int n = str.size();
    if(n <= 1) return -1;

    //从末尾开始找到第一个比后一个字符小的字符
    int i = nums.size()-2;
    while(i >= 0 && nums[i] > nums[i+1]) {
        i--;
    }

    if(i == 0) return -1;   //数字是递减的,不存在比该数字大的数

    //从后开始找到第一个比i位置大的数
    int j = nums.size() - 1;
    while(j >= 0 && nums[j] <= nums[i]) {
        j--;
    }

    //将i之后的字符串逆序
    reverse(str.begin() + i + 1, str.end());

    return std::stoi(str);
}

*/



/*
int findKthLargest(std::vector<int> &nums, int k)
{
    int n = nums.size();
    int left = 0, rightt = nums.size() - 1;

    int index;
    while(left <= rightt)
    {
        index = partition(nums, left, rightt);

        if(index < (n-k)) {
            left = index + 1;
        }
        else if(index > (n-k)) {
            rightt = index - 1;
        }
        else if(index == (n-k)) {
            break;
        }
    }

    return nums[index];
}

int partition(std::vector<int> &nums, int left, int rightt)
{
    int pivot = nums[left];

    while(left < rightt)
    {
        while(left < rightt && nums[rightt] >= pivot) rightt--;
        std::swap(nums[left], nums[rightt]);

        while(left < rightt && nums[left] <= pivot) left++;
        std::swap(nums[left], nums[rightt]);
    }

    return left;
}

//切割成回文串的最小次数

int minCut(std::string s)
{
    if(s.empty()) return 0;
    int n = s.size();

    //isPalind[i][j]代表字符串str[i..j]是否是回文串
    std::vector<std::vector<int>> isPalind(n, std::vector<int>(n, 0));
    std::vector<int> dp(n, n-1);

    for(int i = n-1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            if(s[i] == s[j] && (j-i < 2 || isPalind[i+1][j-1])) {
                isPalind[i][j] = 1;
                if(j == n-1) {      //j能够遍历到j=n-1 就表明[i,n-1]整个就是一个回文串,不需要分割
                    dp[i] = 0;      
                }
                else {
                    dp[i] = std::min(dp[i], dp[j+1] + 1);
                }
            }
        }
    }

    return dp[0];
}


int longestPalindromeSubseq(std::string s)
{
    if(s.empty()) return 0;

    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for(int i = n-1; i >= 0; i--) {
        for(int j = i+1; j < n; j++) {
            if(s[i] == s[j]) {
                dp[i][j] = dp[i+1][j-1] + 2;
            }
            else {
                dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }

    return dp[0][n-1];
}

//O(n)时间,O(n)空间
Node* copyRandomList(Node *head)
{
    if(head == nullptr) return head;

    Node *cur = head;
    std::unordered_map<Node*, Node*> hash;
    while(cur)
    {
        Node *copy = new Node(cur->val);
        hash[cur] = copy;
        cur = cur->next;
    }

    cur = head;
    while(cur)
    {
        hash[cur]->next = hash[cur->next];
        hash[cur]->random = hash[cur->random];
        cur = cur->next;
    }

    return hash[head];
}

//不使用哈希表
Node* copyRandomList(Node *head)
{
    if(head == nullptr) return head;

    //复制每个链表
    Node *cur = head;
    while(cur)
    {
        Node *pNext = cur->next;
        cur->next = new Node(cur->val);
        cur->next->next = pNext;
        cur = pNext;
    }

    //复制随机指针
    cur = head;
    while(cur)
    {
        if(cur->random != nullptr) {
            cur->next->random = cur->random->next;
        }
        cur = cur->next->next;
    }

    //提取出偶数编号的节点
    cur = head;
    Node *copyHead = head->next;
    Node *copy = copyHead;

    while(copy->next) {
        cur->next = cur->next->next;
        cur = cur->next;

        copy->next = copy->next->next;
        copy = copy->next;
    }

    cur->next = nullptr;

    return copyHead;
}

*/

/*
std::string validIpAddress(std::string IP)
{
    return isValidIPV4(IP) ? "IPV4" : (isValidIPV6(IP) ? "IPV6" : "Neither");
}

std::vector<std::string> split(std::string IP, char c)
{
    std::vector<std::string> strs;
    std::istringstream in(IP);
    std::string str;
    while(geline(in, str, c)) {
        strs.push_back(str);
    }

    return strs;
}

bool isValidIPV4(std::string IP)
{
    if(count(IP.begin(), IP.end(), '.') != 3) return false;

    std::vector<std::string> strs = split(IP, '.');
    if(strs.size() != 4) return false;

    for(std::string &str : strs)
    {
        if(str.empty() || str.size() > 3 || (str.size() > 1 && str[0] == '0')) return false;

        for(char &c : str) {
            if(!isdigit(c)) return false;
        }

        if(std::stoi(str) > 255) return false;
    }

    return true;
}

bool isValidIPV6(std::string IP)
{
    if(count(IP.begin(), IP.end(), ':') != 7) return false;

    std::vector<std::string> strs = split(IP, ':');
    if(strs.size() != 8) return false;

    for(std::string &str : strs) 
    {
        if(str.empty() || str.size() > 4) return false;

        for(char &c : str) {
            if(!isalnum(c)) return false;
            
            if(isalnum(c) && toupper(c) > 'F') return false;
        }
    }

    return true;
}
*/

/*
std::string minWondow(std::string s, std::string t)
{
    std::vector<int> tFreq(256, 0);
    for(const char c : t) {
        tFreq[c]++;
    }

    int startIndex = -1, maxLen = s.size() + 1;
    int windowSameCount = 0;
    std::vector<int> windowFreq(256, 0);

    int left = 0, rightt = -1;
    while(left < s.size())
    {
        if(rightt + 1 < s.size() && windowSameCount < t.size()))
        {
            windowFreq[s[rightt+1]]++;

            if(windowFreq[s[rightt+1]] <= tFreq[s[rightt+1]]) windowSameCount++;

            rightt++;
        }
        else
        {
            if(windowSameCount == t.size() && maxLen > (rightt-left+1)) {
                maxLen = rightt - left + 1;
                startIndex = left;
            } 

            windowFreq[s[left]]--;
            if(windowFreq[s[left]] < windowFreq[s[left]]) windowSameCount--;

            left++;
        }
    }

    return startIndex == -1 ? "" : s.substr(startIndex, maxLen);
}
*/
/*
int lengthOfLongestSubstringKDistinct(std::string s, int k)
{
    int left = 0, rightt = -1;

    int res = -1;
    std::unordered_map<char,int> hash;

    while(left < s.size())
    {
        if(rightt + 1 < s.size() && (hash.size() < k || hash.count(s[rightt+1])))
        {
            // std::cout << s[rightt+1] << std::endl;

            hash[s[rightt+1]]++;

            rightt++;

            // std::cout << rightt << std::endl;
        }
        else
        {
            // std::cout << hash.size() << std::endl;
            if(hash.size() == k && res < (rightt - left + 1)) {
                res = rightt - left + 1;
                std::cout << res << std::endl;
            }

            hash[s[left]]--;
            if(hash[s[left]] == 0) {
                hash.erase(s[left]);
            }

            left++;
        }
    }

    // while(left < s.size())
    // {
    //     if(rightt + 1 < s.size())
    //     {
    //         hash[s[rightt+1]]++;

    //         rightt++;
    //     }



    // }



    return res;
}
*/




/*
std::string removeDuplicates(std::string s, int k)
{
    std::vector<std::pair<char,int>> res;

    for(const char &c : s)
    {
        if(res.empty() || res.back().first != c) {
            res.push_back({c, 1});
        }
        else if(++res.back().second == k) {
            res.pop_back();
        }
    }

    std::string ans;
    for(auto &p : res) {
        ans += std::string(p.second, p.first);
    }

    return ans;
}

/*
int lengthOfLongestSubstring(std::string s)
{
    std::vector<int> count(128, -1);
    int start = -1;
    int res = 0;

    for(int i = 0; i < s.size(); i++)
    {
        if(count[s[i]] > start) {
            start = count[s[i]];
        }

        res = std::max(res, i - start);
        count[s[i]] = i;
    }
    
    return res;
}


int minSubArrayLen(int target, std::vector<int> &nums)
{
    int left = 0, rightt = -1;
    int res = nums.size() + 1;
    int sum = 0;

    while(left < nums.size())
    {
        if(rightt + 1 < nums.size() && sum < target) {
            sum += nums[rightt+1];
            rightt++;
        }
        else {
            if(sum >= target && res > (rightt - left + 1)) {
                res = rightt - left + 1;
            }

            sum -= nums[left];
            left++;
        }
    }

    return res == nums.size() + 1 ? 0 : res;
}


std::vector<int> findAnagrams(std::string s, std::string p)
{
    std::vector<int> pFreq(256, 0), sFreq(256, 0);
    std::vector<int> res;
    if(s.size() < p.size()) return res;

    for(int i = 0; i < p.size(); i++) {
        sFreq[s[i]]++;
        pFreq[p[i]]++;
    }

    if(sFreq == pFreq) {
        res.push_back(0);
    }

    for(int i = p.size(); i < s.size(); i++)
    {
        sFreq[s[i-p.size()]]--;
        sFreq[s[i]]++;

        if(sFreq == pFreq) {
            res.push_back(i - p.size() + 1);
        }
    }

    return res;
}


std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
{
    std::deque<int> dq;
    std::vector<int> res;

    for(int i = 0; i < nums.size(); i++)
    {
        if(!dq.empty() && dp.front() == i-k) dp.pop_front();

        while(!dp.empty() && nums[i] > nums[dp.back()]) {
            dp.pop_back();
        }
        dp.push_back(i);

        if(i >= k-1) res.push_back(nums[dq.front()]);
    }

    return res;
}

std::string removeDuplicate(std::string S)
{
    std::string res;
    for(const char &c : S)
    {
        if(!res.empty() && res.back() == c) {
            res.pop_back();
        }
        else {
            res.push_back(c);
        }
    }

    return res;
}
*/

//哈希表先记录下每个字符出现的次数
//遍历字符串,如果当前字符没有被访问并且小于之前添加的前一个字符,并且前一个字符再之后还会出现
//则将前一个字符出队,访问位置为0,加入当前字符

/*
std::string removeDuplicateLetters(std::string s)
{
    std::vector<int> count(128, 0);
    std::vector<int> visited(128, 0);

    std::string res;

    for(const char &c : s) {
        count[c]++;
    }

    for(const char &c : s)
    {
        count[c]--;

        if(visited[c]) continue;

        while(!res.empty() && c < res.back() && count[res.back()]) {
            visited[res.back()] = 0;
            res.pop_back();
        }

        res += c;

        visited[c] = 1;
    }

    return res;
}


int maxProfit(std::vector<int> &prices)
{
    int n = price.size();
    std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(3, std::vector<int>(2, 0)));

    for(int i = 0; i < n; i++)
    {
        for(int k = 2; k >= 1; k--)
        {
            if(i == 0) {
                dp[i][k][0] = 0;
                dp[i][k][1] = -prices[i];
                continue;
            }

            dp[i][k][0] = std::max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
            dp[i][k][1] = std::max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);

        }
    }

    return dp[n-1][2][0];
}


TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root == nullptr) return root;

    if(root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    }

    if(root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->rightt, p, q);
    }

    return root;
}


TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root == nullptr || root == p || root == q) return root;

    TreeNode *pLeft = lowestCommonAncestor(root->left, p, q);

    TreeNode *prightt = lowestCommonAncestor(root->rightt, p, q);

    if(pLeft && prightt) return root;

    return pLeft ? pLeft : prightt;    
}


TreeNode* invertTree(TreeNode *root)
{
    if(root == nullptr) return root;

    std::swap(root->left, root->rightt);

    invertTree(root->left);
    invertTree(root->rightt);

    return root;
}


//利用前序遍历

TreeNode *invertTree(TreeNode *root)
{
    if(root == nullptr) return root;

    std::stack<TreeNode*> sta;
    sta.push(root);

    while(!sta.empty())
    {
        TreeNode *pNode = sta.top();
        sta.pop();

        TreeNode *tmp = pNode->left;
        pNode->left = pNode->rightt;
        pNode->rightt = tmp;

        if(pNode->left) {
            sta.push(pNode->left);
        }

        if(pNode->rightt) {
            sta.push(pNode->rightt);
        }
    }

    return root;
}


//遍历的时候标记层号,vector里面的元素个数和二叉树的层数是相同的

std::vector<int> righttSideView(TreeNode *root)
{
    std::vector<int> res;

    dfs(root, 0, res);

    return res;
}

void dfs(TreeNode *root, int level, std::vector<int> &res)
{
    if(res.size() <= level) {
        res.push_back(root->val);
    }

    dfs(root->left, level + 1, res);
    dfs(root->rightt, left + 1, res);

}

std::vector<std::vector<int>> res;

std::vector<std::vector<int>> subsets(std::vector<int> &nums)
{
    std::vector<int> path;

    dfs(nums, 0, path);

    return res;
}

void dfs(std::vector<int> &nums, int pos, std::vector<int> &path)
{
    res.push_back(path);

    for(int i = pos; i < nums.size(); i++) {
        path.push_back(nums[i]);
        dfs(nums, i + 1, path);
        path.pop_back();
    }

}


std::vector<std::vector<int>> res;

std::vector<std::vector<int>> combine(int n, int k)
{
    std::vector<int> path;

    dfs(n, k, 1, path);

    return res;
}

void dfs(int n, int k, int pos, std::vector<int> &path)
{
    if(path.size() == k) {
        res.push_back(path);
        return;
    }

    for(int i = pos; i <= n; i++) {
        path.push_back(i);
        dfs(n, k, i + 1, path);
        path.pop_back();
    }

}


std::vector<std::vector<int>> res;

std::vector<std::vector<int>> permute(std::vector<int> &nums)
{
    dfs(nums, 0);

    return res;
}

void dfs(std::vector<int> &nums, int pos)
{
    if(pos == nums.size()) {
        res.push_back(nums);
        return;
    }

    for(int i = pos; i < nums.size(); i++) {
        std::swap(nums[pos], nums[i]);
        dfs(nums, i+1);
        std::swap(nums[pos], nums[i]);
    }

}


std::vector<std::vector<int>> permute(std::vector<int> &nums)
{
    std::vector<int> path;

    dfs(nums, path);

    return res;
}

void dfs(std::vector<int> &nums, std::vector<int> &path)
{
    if(nums.size() == path.size()) {
        res.push_back(path);
        return;
    }

    for(int i = 0; i < nums.size(); i++)
    {
        if(find(nums.begin(), nums.end(), nums[i]) == nums.end()) continue;

        path.push_back(nums[i]);
        dfs(nums, path);
        path.pop_back();
    }

}
*/


/*
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <cmath>

void dfs(std::vector<int> &nums, int pos);

std::vector<std::vector<int>> res;

std::vector<std::vector<int>> permutation(std::vector<int> &nums)
{
    dfs(nums, 0);

    return res;
}

void dfs(std::vector<int> &nums, int pos)
{
    if(pos == nums.size()) {
        res.push_back(nums);
        return;
    }

    std::unordered_set<int> mySet;

    for(int i = pos; i < nums.size(); i++) 
    {
        if(mySet.count(nums[i])) continue;  //表示以该元素开头的元素只能有一个
        mySet.insert(nums[i]);
    
        std::swap(nums[i], nums[pos]);
        dfs(nums, pos + 1);
        std::swap(nums[i], nums[pos]);
    }

}

int main() {
    double n = exp(3);

    double ans = log(n);

    std::cout << ans << std::endl;

    return 0;
}


//两个排序数组的并集中寻找第k小的数
//时间复杂度O(k)

int findkThSmallest(std::vector<int> &nums1, std::vector<int> &nums2, int k)
{
    int offset1 = 0, offset2 = 0;
    int n1 = nums1.size(), n2 = nums2.size();

    if(k > n1 + n2) return -1;

    while(1)
    {
        if(offset1 < n1) {
            while(offset2 == n2 || nums1[offset1] <= nums2[offset2]) {
                offset1++;
                if(offset1 + offset2 == k) return nums1[offset1];
            }
        }

        if(offset2 < n2) {
            while(offset1 == n1 || nums1[offset1] >= nums2[offset2]) {
                offset2++;
                if(offset1 + offset2 == k) return nums2[offset2];
            }
        }
    }
 
}

//贪心的思想:最大高度差选择用梯子来爬,其他的高度差选择用砖头垫

int furthestBuilding(std::vector<int> &heights, int bricks, int ladders)
{
    std::priority_queue<int> pq;

    for(int i = 0; i < heights.size()-1; i++)
    {
        int diff = heights[i+1] - heights[i];
        if(diff < 0) {
            pq.push(diff);
        }

        if(pq.size() > ladders) {
            bricks += pq.top();
            pq.pop();
        }

        if(bricks < 0) return i;
    }

    return heights.size() - 1;
}


int maxProduct(std::vector<std::string> &words)
{
    int n = words.size();
    std::vector<int> mask(n, 0);

    int res = 0;

    for(int i = 0; i < n; i++)
    {
        for(const char &c : words[i]) {
            mask |= (1 << (c-'a'));
        }

        for(int j = 0; j < i; j++) {
            if((mask[j] & mask[i]) == 0) {
                res = std::max(res, (int)(words[i].size() * words[j].size()));
            }
        }
    }

    return res;
}


class LRUCache
{
private:
    std::list<std::pair<int,int>> cache;
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> hash;
    int size;

public:
    LRUCache(int capacity) : size(capacity) {}

    int get(int key)
    {
        auto it = hash.find(key);
        if(it == hash.end()) {
            return -1;
        }

        cache.splice(cache.begin(), cache, it->second);

        return cache.front().second;
    }

    void put(int key, int value)
    {
        auto it = hash.find(key);
        if(it != hash.end()) {
            hash[key].second = value;
            cache.splice(cache.begin(), cache, it->second);
            return;
        }

        cache.push_front({key, value});
        hash[key] = cache.begin();

        if(cache.size() > size) {
            cache.erase(cache.back().first);
            cache.pop_back();
        }
    }

};


int lengthOfLIS(std::vector<int> &nums)
{
    int n = nums.size();

    std::vector<int> dp(n, 1);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    int res = 0;
    for(int &n : dp) {
        res = std::max(res, n);
    } 

    return res;
}


int lengthOfLIS(std::vector<int> &nums)
{
    std::vector<int> res;

    for(int &n : num) {
        if(res.empty() || res.back() < n) {
            res.push_back(n);
        }
        else {
            auto it = lower_bound(res.begin(), res.end(), n);
            *it = n;
        }
    }

    return res.size();
}


int maxEnvelops(std::vector<std::vector<int>> &envelops)
{
    sort(envelops.begin(), envelops.end(), [](std::vector<int> &a, std::vector<int> &b){
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });

    std::vector<int> nums;
    for(const auto &p : envelops) {
        nums.push_back(p[1]);
    }

    return lengthOfLIS(nums);
}
*/


/*
struct TrieNode 
{
    TrieNode *childNode[26];
    std::vector<int> wordIndex;     //存放单词的序号

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
            if(childNode[c-word[begin]] == nullptr) {
                childNode[c-word[begin]] = new TrieNode;
            }
            childNode[c-word[begin]]->add(word, begin + 1, index);
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
        forwardTrie = new TrieNode;
        backwardTrie = new TrieNode;

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

        //在上面的数组中从后往前搜索到相同的单词即可
        auto fIter = forwardMatch.rbegin(), bIter = backwardMatch.rbegin();
        while(fIter != forwardMatch.rend() && bIter != forwardMatch.rend())
        {
            if(*fIter == *bIter) return *fIter;     //表示指向的是同一个单词,则返回单词的序号
            else if(*fIter > *bIter) fIter++;       //否则向前移动,注意:逆向迭代器向前移动是++
            else bIter++;   
        }

        return -1;
    }

};






/*
TrideNode* buildTree(std::vector<int> &words)
{
    TrideNode *forwardTree = new TrideNode;
    TrideNode *backwardTree = new TrideNode;

    TrideNode *nodeForward = forwardTree;
    TrideNode *nodeBackward = backwardTree;

    for(int i = 0; i < words.size(); i++)
    {
        std::string word = words[i];
        for(char &c : word) {
            if(nodeForward[c-'a'] == nullptr) {
                nodeForward[c-'a'] = new TrideNode;
            }
            nodeForward = nodeForward[c-'a'];
        }

        reverse(word.begin(), word.end());
        for(char &c : word) {
            if(nodeBackward[c-'a'] == nullptr) {
                nodeBackward[c-'a'] = new TrideNode;
            }
            nodeBackward = nodeBackward[c-'a'];
        }
    }

}
*/
/*
int maxSubArray(std::vector<int> &nums)
{
    if(nums.size() == 1) return nums[0];
    
    std::vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];

    for(int i = 1; i < nums.size(); i++) {
        dp[i] = std::max(dp[i-1] + nums[i], nums[i]);
    }

    int res = INT_MAX;
    for(const int &n : dp) {
        res = std::max(res, n);
    }

    return res;
}

int maxSubArray(std::vector<int> &nums)
{
    int sum = 0;
    int res = INT_MIN;

    for(const int &n : nums) {
        sum += n;
        sum = std::max(sum, n);
        res = std::max(res, sum);
    }

    return res;
}



struct TrieNode {
    TrieNode *childNode[26];
    bool isVal;

    TrieNode() : isVal(false) {
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


class Trie
{
private:
    TrieNode *root;

public:
    Trie(): root(new TrieNode) {

    }

    void insert(std::string word) 
    {
        TrieNode *node = root;
        for(const char &c : word) {
            if(node->childNode[c-'a'] == nullptr) {
                node->childNode[c-'a'] = new TrieNode;
            }        
            node = node->childNode[c-'a'];
        }
        node->isVal = true;
    }

    bool search(std::string word)
    {
        TrieNode *node = root;
        for(const char &c : word) {
            if(node->childNode[c-'a'] == nullptr) {
                return false;
            }
            node = node->childNode[c-'a'];
        }

        return node->isVal;
    }

    bool startsWith(std::string prefix)
    {
        TrieNode *node = root;
        for(const char &c : prefix) {
            if(node->childNode[c-'a'] == nullptr) {
                return false;
            }
            node = node->childNode[c-'a'];
        }

        return true;
    }

};


struct TrieNode {
    TrieNode *childNode[26];
    bool isVal;

    TrieNode() : isVal(false) {
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


class WordDictionary
{
private:
    TrieNode *root;

    bool search(const char* str, TrieNode *node) {
        for(int i = 0; str[i] != '/0' && node; i++) {
            if(str[i] == '.') {
                for(int i = 0; j < 26; j++) {
                    node = node->childNode[j];
                    if(search(str + i + 1, node)) return true;  //下一次直接递归
                }
            }
            else {
                node = node->childNode[str[i]-'a'];
            }
        }

        return node && node->isVal;
    }

public:
    WordDictionary() : root(new TrieNode) {

    }

    void addWord(std::string word) {
        TrieNode *node = root;
        for(const char &c : word) {
            if(node->childNode[c-'a'] == nullptr) {
                node->childNode[c-'a'] = new TrieNode;
            }
            node = node->childNode[c-'a'];
        }
        node->isVal = true;
    }

    bool search(std::string word) {
        TrieNode *node = root;
        return search(word.c_str(), node);
    }

};
*/



/*
class WordDictionary
{
private:
    std::unordered_map<int, std::vector<std::string>> hash;

    bool isMatch(const std::string &word, const std::string &pattern) {
        if(word.empty() || pattern.empty()) return false;

        for(int i = 0; i < word.size(); i++) {
            if(word[i] == '.') continue;
            if(word[i] != pattern[i]) return false;
        }
        
        return true;
    }


public:
    WordDictionary() {

    }

    void addWord(std::string word) {
        hash[word.size()].push_back(word);
    }

    bool search(std::string word) {
        if(word.empty()) return false;

        for(const std::string &str : hash[word.size()]) {
            if(isMatch(word, str)) {
                return true;
            }
        }

        return false;
    }

};

bool exist(std::vector<std::vector<char>> &board, std::string word)
{
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(findWord(board, i, j, word, 0)) return true;
        }
    }

    return false;
}

bool findWord(std::vector<std::vector<char>> &board, int i, int j, const std::string &word, int pos)
{
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[pos]) return false;

    if(pos == word.size() - 1) return true;

    board[i][j] = '#';
    bool res = findWord(board, i, j + 1, word, pos + 1) || findWord(board, i, j - 1, word, pos + 1) ||
               findWord(board, i + 1, j, word, pos + 1) || findWord(board, i - 1, j, word, pos + 1);

    board[i][j] = word[pos];

    return res;
}


struct TrieNode {
    TrieNode *childNode[26];
    std::string word;

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

};


TrieNode *buildTree(std::vector<std::string> &words)
{
    TrieNode *root = new TrieNode;

    for(const &word : words) {
        TrideNode *node = root;
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

std::vector<std::string> res;

std::vector<std::string> findWords(std::vector<std::vector<char>> &board, std::vector<std::string> &words)
{
    TrieNode *root = buildTree(words);

    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            dfs(board, i, j, root);
        }
    }

    return res;
}

void dfs(std::vector<std::vector<char>> &board, int i, int j, TrideNode *root)
{
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;

    char c = board[i][j];
    if(c == '#' || root->childNode[c-'a'] == nullptr) return;

    root = root->childNode[c-'a'];

    if(!(root->word.empty())) {
        res.push_back(root->word);
        root->word.clear();
    }

    board[i][j] = '#';

    dfs(board, i, j + 1, root);
    dfs(board, i, j - 1, root);
    dfs(board, i + 1, j, root);
    dfs(board, i - 1, j, root);

    board[i][j] = c;

}
*/


/*
#include <iostream>
#include <vector>
#include <algorithm>

int longesetCommonSubsequence(std::string text1, std::string text2);
std::string longestCommonSubstring(std::string s, std::string t);

int main() {
    std::string text1 = "abcdef", text2 = "def";

    // longesetCommonSubsequence(text1, text2);
    std::cout << longestCommonSubstring(text1, text2) << std::endl;

    return 0;
}

int longesetCommonSubsequence(std::string text1, std::string text2)
{
    int m = text1.size(), n = text2.size();
    std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    //倒推结果
    std::string res;
    for(int i = m, j = n; dp[i][j] >= 1;)
    {
        if(text1[i-1] == text2[j-1]) {
            res += text1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] >= dp[i][j-1]) i--;  //说明当前dp[i][j]是从dp[i-1][j]推导出来的,反推应该减少i
        else j--;                               //同理这说明dp[i][j]是从dp[i][j-1]推导出来的,反推应该减少j
    }

    reverse(res.begin(), res.end());

    std::cout << res << std::endl;

    return dp[m][n];
}


std::string longestCommonSubstring(std::string s, std::string t)
{
    if(s.empty() || t.empty()) return "";

    int m = s.size(), n = t.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    
    int maxLen = 0, startIndex = 0;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if(dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    startIndex = i - dp[i][j];
                }
            }
            else {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    for(int i = 0; i < dp.size(); i++) {
        for(int j = 0; j < dp[i].size(); j++) {
            std::cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return maxLen == 0 ? "" : s.substr(startIndex, maxLen);
}


int change(int amount, std::vector<int> &coins)
{
    int n = coins.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(amount + 1, 0));
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= amount; j++) {
            if(j < coins[i-1]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            }
        }
    }

    return dp[n][amount];
}


int change(int amount, std::vector<int> &coins)
{
    int n = coins.size();
    std::vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= amount; j++) {
            if(j >= coins[i]) {
                dp[j] = dp[j] + dp[j-coins[i]];
            }
        }
    }

    return dp[amount];
}

int coinChange(std::vector<int> &coins, int amount)
{
    int n = coins.size();
    std::vector<int> dp(amount+1, amount+1);
    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= amount; j++) {
            if(j >= coins[i]) {
                dp[j] = std::min(dp[j], dp[j-coins[i]] + 1);
            }
        }
    }

    return dp[amount];
}

int coinChange(std::vector<int> &nums, int amount)
{
    int n = coins.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(amount + 1, amount + 1));

    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= amount; j++) {
            if(j < coins[i-1]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = std::min(dp[i-1][j], dp[i][j-nums[i-1]] + 1);
            }
        }
    }

    return dp[n][amount] == amount + 1 ? -1 : dp[n][amount];
}

int findDuplicate(std::vector<int> &nums)
{
    for(int i = 0; i < nums.size(); i++) {
        int index = abs(nums[i]) - 1;
        if(nums[index] < 0) return nums[i];
        else nums[index] *= (-1);
    }

    return -1;
}

//Leetcode第55题

bool canJump(std::vector<int> &nums)
{
    int maxPos = 0;
    for(int i = 0; i < nums.size()-1; i++) 
    {
        if(nums[i] == 0 && maxPos <= i) return false;   //当当前位置元素为0且最大位置不超过当前元素时则一定不能跳过去
        maxPos = std::max(maxPos, i + nums[i]);
    }

    return true;
}

//Leetcode第45题 : Jump Game II

int jump(std::vector<int> &nums)
{
    int end = 0, maxPos = 0;    //记录到达的终点和能到达的最远位置
    int steps = 0;

    for(int i = 0; i < nums.size() - 1; i++) 
    {
        maxPos = std::max(maxPos, i + nums[i]);
        if(i == end) {                          //到达了终点,则重新更新终点且步数加1
            end = maxPos;
            steps++;
        }
    }
    
    return steps;
}


//Leetcode第1306题: Jump Game III
//DFS

std::unordered_set<int> mySet;

bool canReach(std::vector<int> &arr, int start)
{
    //向集合set中插入元素返回一个pair
    //pair::second是一个bool值,如果插入成功,则返回true,否则返回false
    //pair::first被设置成指向新插入元素的迭代器或者指向等值的已经存在的元素的迭代器

    if(start >= 0 && start < arr.size() && mySet.insert(start).second) {
        return arr[start] == 0 || canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
    }

    return false;
}

int jump(std::vector<int> &nums)
{
    int end = 0, maxPos = 0;
    int steps = 0;

    for(int i = 0; i < nums.size() - 1; i++) 
    {
        maxPos = std::max(maxPos, i + nums[i]);
        if(i == end) {
            steps++;
            end = maxPos;
        }
    }

    return steps;
}

bool isMatch(std::string s, std::string p)
{
    int m = s.size(), n = p.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for(int j = 1; j <= n; j++) {
        if(p[j-1] == '*') {
            dp[0][j] = dp[0][j-2];
        }
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == p[j-1] || p[j-1] == '.') {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] == '*') {
                if(s[i-1] != p[j-2] || p[j-2] != '.') {
                    dp[i][j] = dp[i][j-2];
                }
                else {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i-1][j-2];
                }
            }
        }
    }

    return dp[m][n];
}


bool isMatch(std::string s, std::string p)
{
    int m = s.size(), n = p.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for(int j = 1; j <= n; j++) {
        if(p[j-1] == '*') {
            dp[0][j] = dp[0][j-1];
        }
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == p[j-1] || p[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] == '*'){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
    }

    return dp[m][n];
}

*/
/*

#include <iostream>
#include <vector>
#include <sstream>

int main() {
    // std::string str = "hello world I am a student!";
    // std::istringstream in(str);
    // std::string out;

    // std::vector<std::string> res1, res2;

    // while(in >> out) {
    //     res1.push_back(out);
    // }

    // for(const auto &str : res1) {
    //     std::cout << str << " ";
    // }
    // std::cout << std::endl;

    // while(getline(in, out, ' ')) {
    //     res2.push_back(out);
    // }
    // for(const auto &str : res2) {
    //     std::cout << str << " ";
    // }
    // std::cout << std::endl;

    // std::vector<std::vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    // std::vector<int> sum(3);

    // for(int i = 0; i < 3; i++) {
    //     for(int j = 0; j < 3; j++) {
    //         sum[j] += nums[i][j];
    //     }
    // }

    // for(const int &n : sum) {
    //     std::cout << n << " ";
    // }
    // std::cout << std::endl;

    return 0;
}


TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root == nullptr) return root;

    if(root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    }
    else if(root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->rightt, p, q);
    }

    return root;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root == nullptr || root == p || root == q) return root;

    TreeNode *pLeft = lowestCommonAncestor(root->left, p, q);
    TreeNode *prightt = lowestCommonAncestor(root->rightt, p, q);

    if(pLeft && prightt) return root;

    return pLeft ? pLeft : prightt;
}


//Leetcode第105题: 重建二叉树->依据前序和中序遍历

TreeNode* buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
{
    std::unordered_map<int,int> inorderPos;
    for(int i = 0; i < inorder.size(); i++) {
        inorderPos[inorder[i]] = i;
    }

    return buildTreeCore(preorder, 0, preorder.size() - 1, 0, inorderPos);
}

TreeNode* buildTreeCore(std::vector<int> &preorder, int startProrder, int endPreorder, int startInorder, std::unordered_map<int,int> &inorderPos)
{
    if(startProrder > endPreorder) return nullptr;

    int rootIndex = inorderPos[preorder[startProrder]];

    TreeNode *root = new TreeNode(preorder[startProrder]);

    int leftLen = rootIndex - startInorder;

    root->left = buildTreeCore(preorder, startProrder + 1, startProrder + leftLen, startInorder, inorderPos);

    root->rightt = buildTreeCore(preorder, startProrder + leftLen + 1, rootIndex + 1, inorderPos);

    return root;
}



//Leetcode第106题: 重建二叉树->依据中序和后序遍历

TreeNode* buildTree(std::vector<int> &inorder, std::vector<int> &postorder)
{
    std::unordered_map<int,int> inorderPos;
    for(int i = 0; i < inorder.size(); i++) {
        inorderPos[inorder[i]] = i;
    }

    return buildTreeCore(postorder, 0, postorder.size() - 1, 0, inorderPos);
}

TreeNode* buildTreeCore(std::vector<int> &postorder, int startPostorder, int endPostorder, int startInorder, std::unordered_map<int,int> &inorderPos)
{
    if(startPostorder > endPostorder) return nullptr;

    int rootIndex = inorderPos[postorder[endPostorder]];

    TreeNode *root = new TreeNode(postorder[endPostorder]);

    int leftLen = rootIndex - startInorder;

    root->left = buildTreeCore(postorder, startPostorder, startPostorder + leftLen - 1, startInorder, inorderPos);

    root->rightt = buildTreeCore(postorder, startPostorder + leftLen, endPostorder - 1, rootIndex + 1, inorderPos);

    return root;
}

TreeNode* sortedArrayToBST(std::vector<int> &nums)
{
    //找到终点后二分,前半部分为左子树,后半部分为右子树
    return dfs(nums, 0, nums.size() - 1);
}

TreeNode* dfs(std::vector<int> &nums, int left, int rightt)
{
    if(left > rightt) return nullptr;

    int mid = left + ((rightt-left) >> 1);

    TreeNode *root = new TreeNode(nums[mid]);

    root->left = dfs(nums, left, mid - 1);
    root->rightt = dfs(nums, mid + 1, rightt);

    return root;
}

TreeNode* sortedListToBST(ListNode *head)
{
    if(head == nullptr) return nullptr;    //这里不能return head,因为head是链表节点,这里需要返回树节点

    return sortedListToBST(head, nullptr);
}

TreeNode* sortedListToBST(ListNode *head, ListNode *tail)
{
    if(head == tail) return nullptr;

    ListNode *mid = head, *fast = head;
    while(fast != tail && fast->next != tail) {
        mid = mid->next;
        fast = fast->next->next;
    }

    TreeNode *root = new TreeNode(mid->val);

    root->left = sortedListToBST(head, mid);
    root->rightt = sortedListToBST(mid->next, tail);

    return root;
}


int subarraySum(std::vector<int> &nums, int k)
{
    int n = nums.size();
    std::vector<int> preSum(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        preSum[i] = preSum[i-1] + nums[i-1];
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(preSum[j+1] - preSum[i] == k) {
                count++;
            }
        }
    }

    return count;
}

int subarraySum(std::vector<int> &nums, int k)
{
    std::unordered_map<int, int> hash;
    hash[0] = 1;

    int preSum = 0;
    int count = 0;
    for(const int &n : nums) {
        preSum += n;
        count += hash[preSum-k];
        hash[preSum]++;
    }
    
    return count;
}

int numSubarrayWithSum(std::vector<int> &A, int S)
{
    std::unordered_map<int,int> hash;
    hash[0] = 1;

    int preSum = 0;
    int count = 0;
    for(const int &n : A) {
        preSum += n;
        count += hash[preSum-S];
        hash[preSum]++;
    }

    return count;
}


int numberOfSubarrays(std::vector<int> &nums, int k)
{
    std::unordered_map<int, int> hash;
    hash[0] = 1;

    int oddNum = 0;
    int count = 0;
    for(const int &n : nums) {
        if(n&1) oddNum++;
        // if(oddNum >= k) {
            count += hash[oddNum-k];
        // }
        hash[oddNum]++;
    }

    return count;
}
*/

/*
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <set>

const int max = 66666;

void dijkstra();
void initMap(std::vector<std::vector<int>> &map);
void floyed();
void func();

class A 
{
public:
    A(int a) {}
    A(const A &a) {}

};

void insertSort(std::vector<int> &nums);
std::string longestPalindromeSubseq(std::string s);
std::string longestPalindrome(std::string s);

int main() {
    std::string s = "aba";

    std::cout << longestPalindrome(s) << std::endl;

    return 0;
}


void insertSort(std::vector<int> &nums)
{
    for(int i = 1; i < nums.size(); i++) 
    {
        if(nums[i] < nums[i-1]) {
            int tmp = nums[i];
            int j = i - 1;
            for(; j >= 0 && nums[j] > tmp; j--) {
                nums[j+1] = nums[j];
            }
            nums[j+1] = tmp;
        }
    }

}


int lengthOfLongestSubstring(std::string s)
{
    std::vector<int> dict(256, -1);
    int start = -1;
    int res = 0;

    for(int i = 0; i < s.size(); i++) 
    {
        if(dict[s[i]] > start) {
            start = dict[s[i]];
        } 
        dict[s[i]] = i;
        res = std::max(res, i-start);    
    }

    return res;
}

std::string longestPalindromeSubseq(std::string s)
{
    int i = 0;
    int maxLen = 0, startIndex = 0;  

    while(i < s.size())
    {
        int start, end;
        start = end = i;
        
        while(end + 1 < s.size() && s[end+1] == s[end]) end++;

        i = end + 1;
        
        while(start - 1 >= 0 && end + 1 < s.size() && s[start-1] == s[end+1]) {
            start--;
            end++;
        }

        if(maxLen < end-start+1) {
            maxLen = end - start + 1;
            startIndex = start;
        }
    }

    return s.substr(startIndex, maxLen);
}


std::string longestPalindrome(std::string s)
{
    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    int maxLen = 0, start = 0;

    for(int j = 0; j < n; j++) {
        for(int i = 0; i < j; i++) {
            if((s[i] == s[j] && (j-i+1 <= 2 || dp[i+1][j-1])) ) {
                dp[i][j] = 1;
            }
            if(dp[i][j] == 1 && maxLen < (j-i+1)) {
                maxLen = j - i + 1;
                start = i;
            }
        }
    }

    return s.substr(start, maxLen);
}

std::string longestPalindrome(std::string s)
{
    std::string res;

    for(int i = 0; i < s.size(); i++)
    {
        std::string s1 = palindrome(s, i, i);
        std::string s2 = palindrome(s, i, i + 1);

        res = res.size() > s1.size() ? res : s1;
        res = res.size() > s2.size() ? res : s2;
    }

    return res;
}


std::string palindrome(std::string s, int i, int j)
{
    if(i < 0 || j >= s.size()) return "";

    while(i >= 0 && j < s.size() && s[i] == s[j]) {
        i--;
        j++;
    }

    return s.substr(i + 1, j - i - 1);
}


std::string shortestPalindrome(std::string s)
{
    int maxLen = 0, startIndex = 0;
    int next = 0;

    int i = 0;
    while(i < s.size())
    {
        int start, end;
        start = end = i;

        while(end + 1 < s.size() && s[end] == s[end+1]) end++;
        i = end + 1;

        while(start - 1 >= 0 && end + 1 < s.size() && s[start-1] == s[end+1]) {
            start--;
            end++;
        }

        if(start == 0 && maxLen < end - start + 1) {
            maxLen = end - start + 1;
            startIndex = start;
            next = startIndex + maxLen;
        }
    }

    std::string remain = s.substr(next);
    reverse(remain.begin(), remain.end());

    return remain + s;
}

int longestPalindromeSubseq(std::string s)
{
    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n,0));
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for(int i = n-1; i >= 0; i--) {
        for(int j = i + 1; j < n; j++) {
            if(s[i] == s[j]) {
                dp[i][j] = dp[i+1][j-1] + 2;
            }
            else {
                dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }

    return dp[0][n-1];
}


int longestCommonSubstring(std::string s)
{
    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    int startIndex = 0;
    int maxLen = 1;

    for(int i = n-1; i >= 0; i--) {
        for(int j = i + 1; j < n; j++) {
            if(s[i] == s[j] && (j-i+1 <= 2 || dp[i+1][j-1])) {
                dp[i][j] = 1;
            }
            if(dp[i][j] == 1 && maxLen < j-i+1) {
                startIndex = i;
                maxLen = j - i + 1;
            }
        }
    }

    return s.substr(startIndex, maxLen);
}

/*
//dijkstra算法 <参考bigSai>的文章

struct node {
    int x;          //节点编号
    int len;     //长度
    node(int m_x, int m_len) {
        x = m_x;
        len = m_len;
    }
};

struct Cmp {
    bool operator()(const node &o1, const node &o2) {
        return o1.len > o2.len;
    }
};

void dijkstra()
{
    std::vector<std::vector<int>> map(6, std::vector<int>(6, 0));  //用map来记录权值
    initMap(map);   //初始化map

    std::vector<int> isVisited(6, 0);           //判断这个点是否已经确定
    std::vector<int> distance(6, INT_MAX);      //记录源节点到其他每个节点的距离

    std::priority_queue<node, std::vector<node>, Cmp> pq;
    distance[0] = 0;        //从0这个点开始
    pq.push(node(0,0));
    int count = 0;          //计算执行了几次dijstra算法
    
    /*
    for(int i = 0; i < map.size(); i++) {
        for(int j = 0; j < map[i].size(); j++) {
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
    */
/*
    while(!pq.empty())
    {
        node tmp = pq.top(); pq.pop();
        int index = tmp.x;      //节点编号
        int len = tmp.len;      //节点长度
        isVisited[index] = 1;   //抛出的点已经确定
        count++;

        for(int i = 0; i < map[index].size(); i++)
        {
            if(map[index][i] > 0 && !isVisited[i]) {
                node newNode = node(i, len + map[index][i]);
                if(distance[i] > newNode.len) {             //只有0这个点distance是0,其他点的初始距离都是无穷大
                    distance[i] = newNode.len;
                    pq.push(newNode);
                }
            }
            std::cout << distance[i] << std::endl;
        }
    }

    for(int i = 0; i < 6; i++) {
        std::cout << distance[i] << " ";
    } 
    std::cout << std::endl;

}

void initMap(std::vector<std::vector<int>> &map)
{
    map[0][1] = 2;  map[0][2] = 3;  map[0][3] = 6;
    map[1][0] = 2;  map[1][4] = 4;  map[1][5] = 6;
    map[2][0] = 3;  map[2][3] = 2;
    map[3][0] = 6;  map[3][2] = 2;  map[3][4] = 1;  map[3][5] = 3;
    map[4][1] = 4;  map[4][3] = 1;
    map[5][1] = 6;  map[5][3] = 3; 

}


void floyed()
{
    std::vector<std::vector<int>> distance = {
    {0, 2, 3, 6, max, max},
    {2, 0, max, max,4,6},
    {3, max,0,2, max,max},
    {6, max,2,0,1,3},
    {max,4,max,1,0,max},
    {max,6,max,3,max,0}};

    for(int k = 0; k < 6; k++) 
    {
        for(int i = 0; i < 6; i++) {
            for(int j = 0 j < 6; j++) {     //这里得从0开始,不能从i+1开始,因为否则左下的元素不能更改
                distance[i][j] = std::min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            std::cout << distance[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
*//*

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
            if(tmp1.x == n-1 && tmp1.y == n-1) {    //到达了终点
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
*/

/*
#include <iostream>
#include <vector>

void dfs(int index, std::vector<int> &row, std::vector<int> &col, std::vector<int> &leftDiag, std::vector<int> &righttDiag, std::vector<std::string> &map, int n);

std::vector<std::vector<std::string>> res;

std::vector<std::vector<std::string>> solveQueens(int n)
{
    std::vector<int> row(n, 0), col(n, 0);
    std::vector<int> leftDiag(2*n-1, 0), righttDiag(2*n-1, 0);
    //leftDiag代表左斜对角线(从左上->右下),righttDiag代表右斜对角线(从右上->左下)

    std::vector<std::string> map(n, std::string(n, '.'));

    dfs(0, row, col, leftDiag, righttDiag, map, n);

    return res;
}

void dfs(int index, std::vector<int> &row, std::vector<int> &col, std::vector<int> &leftDiag, std::vector<int> &righttDiag, std::vector<std::string> &map, int n)
{
    if(index == n) {
        res.push_back(map);
        return;
    }

    for(int j = 0; j < n; j++)
    {
        if(!row[index] && !col[j] && !leftDiag[index + j] && !righttDiag[index + n-1 - j]) {
            row[index] = 1;
            col[j] = 1;
            leftDiag[index+j] = 1;
            righttDiag[index+n-1-j] = 1;
            map[index][j] = 'Q';        //放一个皇后
            dfs(index + 1, row, col, leftDiag, righttDiag, map, n);

            //复原
            row[index] = 0;
            col[j] = 0;
            leftDiag[index+j] = 0;
            righttDiag[index+n-1-j] = 0;
            map[index][j] = '.';     
        }
    }

}



int main() {
    solveQueens(4);

    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            std::cout << res[i][j] << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}


bool isValidSudoku(std::vector<std::vector<char>> &board)
{
    std::vector<std::vector<int>> row(9, std::vector<int>(9, 0)), col(9, std::vector<int>(9, 0)), block(9, std::vector<int>(9, 0));

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++) 
        {
            if(board[i][j] != '.') {
                int n = board[i][j] - '1';
                int k = (i/3)*3 + j/3;
                if(row[i][n] || col[j][n] || block[k][n]) return false;
                row[i][n] = col[j][n] = block[k][n] = 1;
            }
        }
    }

    return true;
}

//如果这样在外部定义vector编译器会报错,因为无法区分这是成员变量声明还是成员函数定义
std::vector<std::vector<int>> row(9, std::vector<int>(9, 0)), col(9, std::vector<int>(9, 0)), block(9, std::vector<int>(9, 0));

void solveSudoKu(std::vector<std::vector<char>> &board)
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] != '.') {
                int n = board[i][j] - '1';
                int k = (i/3)*3 + j/3;      //注意运算符优先级
                row[i][n] = row[j][n] = block[k][n] = 1;
            }
        }
    }

    dfs(board, 0, 0);
}

bool dfs(std::vector<std::vector<char>> &board, int i, int j)
{
    if(i == 9) return true;

    if(j == 9) {
        return dfs(board, i + 1, j);
    }

    if(board[i][j] != '.') 
    {
        return dfs(board, i, j+1);
    }
    else 
    {
        for(int n = 0; n < 9; n++) 
        {
            int k = i/3*3 + j/3;
            if(row[i][n] || col[j][n] || block[k][n]) continue;

            board[i][j] = (char)(n + '1');              //这里不强制转换也会隐身转换,但最好还是强转一下
            row[i][n] = col[j][n] = block[k][n] = 1;

            //找到一个可行解就立即返回
            if(dfs(board, i, j+1)) return true;
            
            //复原
            board[i][j] = '.';
            row[i][n] = col[j][n] = block[k][n] = 0;
        }
    }

}


std::vector<int> findDisappearedNumbers(std::vector<int> &nums)
{
    for(int i = 0; i < nums.size(); i++) {
        int index = abs(nums[i]) - 1;
        if(nums[index] > 0) {
            nums[index] *= (-1);
        }
    }

    std::vector<int> res;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > 0) {
            res.push_back(i + 1);
        }
    }

    return res;
}


bool checkValidstring(std::string s)
{
    int leftMax, leftMin;
    leftMin = leftMax = 0;

    for(const char &c : s)
    {
        if(c == '(') {
            leftMax++;
            leftMin++;
        }
        else if(c == ')') {
            if(leftMax <= 0) return false;
            leftMax--;
            if(leftMin > 0) leftMin--;
        }
        else if(c == '*') {
            if(leftMin > 0) leftMin--;
            leftMax++;
        }
    }

    return leftMin == 0;
}


std::vector<int> dailyTemperatures(std::vector<int> &T)
{
    std::stack<int> sta;
    std::vector<int> res(T.size(), 0);

    for(int i = 0; i < T.size(); i++)
    {
        while(!sta.empty() && T[i] > T[sta.top()]) {
            res[sta.top()] = i - sta.top();  sta.pop();
        }

        sta.push(i);
    }

    return res;
}


int maximalRectangle(std::vector<std::vector<char>> &matirx)
{
    int res = 0;
    if(matirx.empty()) return res;
    std::vector<int> height(matirx[0].size(), 0);

    for(int i = 0; i < matirx.size(); i++)
    {
        for(int j = 0; j < matirx[0].size(); j++) {
            if(matirx[i][j] == '0') {
                height[j] = 0;
            }
            else {
                height[j] += 1;
            }
        }
        int area = largestRectangleArea(height);
        res = std::max(res, area);
    }

    return res;
}


int largestRectangleArea(std::vector<int> &heights)
{
    std::stack<int> sta;
    int res;
    heights.push_back(0);   //防止元素都是递增的

    for(int i = 0; i < heights.size(); i++)
    {
        while(!sta.empty() && heights[i] < heights[sta.top()]) {
            int curHeight = heights[sta.top()];  sta.pop();
            int left = sta.empty() ? -1 : sta.top();
            res = std::max(res, curHeight * (i - left - 1));
        }

        sta.push(i);
    }

    return res;
}

ListNode* mergeKLists(std::vector<ListNode*> &lists)
{
    int len = lists.size();

    while(len > 1)
    {
        for(int i = 0; i < len/2; i++) {
            mergeTwoLists(lists[0], lists[len-i-1]);
        }

        len = (len + 1) >> 1;
    }

    return lists.front();
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if(l1 == nullptr) return l2;
    else if(l2 == nullptr) return l1;

    if(l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } 
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }

}

ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *base = new ListNode(-1);
    ListNode *head = base;

    while(l1 && l2) 
    {
        if(l1->val < l2->val) {
            head->next = l1;
            l1 = l1->next;
        }
        else {
            head->next = l2;
            l2 = l2->next;
        }

        head = head->next;
    }

    return base->next;
}


struct Cmp {
    bool operator()(const ListNode *l1, const ListNode *l2) {
        return l1->val > l2->val;
    }
};

ListNode* mergeTwoLists(std::vector<ListNode*> &lists)
{
    std::priority_queue<ListNode*, std::vector<ListNode*>, Cmp> pq;

    for(auto it : lists) {
        pq.push(it);
    }

    ListNode *base = new ListNode(-1);
    ListNode *head = base;

    while(!pq.empty())
    {
        ListNode *pNode = pq.top();   pq.pop();
        base->next = pNode;
        base = base->next;

        if(pNode->next) {
            pq.push(pNode->next);
        }
    }

    return base->next;
}


std::vector<std::string> res;

std::vector<std::string> generateParenthesis(int n)
{
    std::string path;

    dfs(n, n, path);

    return res;
}

void dfs(int left, int rightt, std::string &path)
{
    //左边括号剩余的比右边多,或者左右边括号只要存在一个用完了
    if(left > rightt) return;
    if(left < 0 || rightt < 0) return;

    if(left == 0 && rightt == 0) {
        res.push_back(path);
        return ;
    }

    //放一个左括号
    path.push_back('(');
    dfs(left - 1, rightt, path);
    path.pop_back();

    //放一个右括号
    path.push_back(')');
    dfs(left, rightt - 1, path);
    path.pop_back();
}


int longestValidParentheses(std::string s)
{
    std::vector<int> wind;
    wind.push_back(-1);

    int res = 0;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(') {
            wind.push_back(i);
        }
        else {
            wind.pop_back();
            if(wind.empty()) {
                wind.push_back(i);
            }
            res = std::max(res, i - wind.back());
        }
    }

    return res;
}
*/


/*
#include <iostream>
#include <vector>

std::vector<std::string> res;
std::vector<std::string> removeInvalidParentheses(std::string s);
void dfs(int left, int rightt, std::string s, int pos);
bool isValid(std::string &s);

int main() {
    std::string s = "()((()";

    removeInvalidParentheses(s);

    for(int i = 0; i < res.size(); i++) {
        std::cout << res[i] << std::endl;
    }

    return 0;
}

std::vector<std::string> removeInvalidParentheses(std::string s)
{
    int left = 0, rightt = 0;
    for(const char &c : s) {
        if(c == '(') left++;
        else if(c == ')'){
            if(left > 0) left--;
            else rightt++;
        }
    }

    dfs(left, rightt, s, 0);

    return res;
}

void dfs(int left, int rightt, std::string s, int pos)
{
    if(left == 0 && rightt == 0) {
        if(isValid(s)) {
            res.push_back(s);
        }
        return ;
    }

    //每个位置尝试删除
    for(int i = pos; i < s.size(); i++)
    {
        if(i > pos && s[i] == s[i-1]) continue;

        if(s[i] == '(' || s[i] == ')')
        {
            std::string cur = s.substr(0, i) + s.substr(i + 1);

            if(s[i] == '(' && left > 0) {
                dfs(left - 1, rightt, cur, i);
            }
            else if(s[i] == ')' && rightt > 0) {
                dfs(left, rightt - 1, cur, i);
            }
        }
    }

}

bool isValid(std::string &s)
{
    int left = 0;
    
    for(const char &c : s) 
    {
        if(c == '(') left++;
        else if(c == ')') left--;

        if(left < 0) return false;
    }

    return left == 0;
}

//1.找到最大的i,nums[i] < nums[i+1]
//2.找到最大的j,j>i,并且nums[j] > num[i]
//3.交换nums[i],nums[j]
//4.将nums[i]之后的元素逆序

void nextPermutation(std::vector<int> &nums)
{
    if(nums.size() < 2) return;

    int n = nums.size();
    for(int i = n-2; i >= 0; i--) {
        if(nums[i] < nums[i+1]) break;
    }

    if(i < 0) {
        reverse(nums.begin(), nums.end());
        return;
    }

    for(int j = n-1; j > i; j--) {
        if(nums[j] > nums[i]) break;
    }

    std::swap(nums[i], nums[j]);

    reverse(nums.begin() + i + 1, nums.end());
}

std::vector<std::string> ambigousCoordinates(std::string s)
{
    std::vector<std::string> res;

    int n = s.size();
    for(int i = 1; i < n - 2; i++) 
    {
        std::vector<std::string> A = f(s.substr(1, i)), B = f(s.substr(i + 1, n - 2 -i));

        for(auto &a : A) {
            for(auto &b : B) {
                res.push_back("(" + a + "," + b + ")");
            }
        }
    }

    return res;
}

std::vector<std::string> f(const std::string &str)
{
    //对str的取值,只可能有以下几种
    //1.str = "" return ""
    //2.str = "0" return "0"
    //3.str = "0xxx" return "0.xxx"
    //4.str = "0xxx0" return ""
    //5.str = "xxx0" return s
    //6.str = "xxx", 依次插入'.'即可

    std::vector<std::string> res;

    int n = str.size();
    if(n == 0 || (n > 1 && str[0] == '0' && str[n-1] == '0')) return res;   //1,4情况
    if(n == 1 || str[n-1] == '0') return {str};                           //2,5情况
    if(n > 1 && str[0] == '0') return {"0." + s.substr(1)};               //3情况

    res = {str};
    for(int i = 1; i < n; i++) {
        res.push_back(str.substr(0, i) + "." + str.substr(i));
    }

    return res;
}


int longestSubstring(std::string s, int k)
{
    if(s.empty()) return 0;

    std::vector<int> count(26, 0);
    for(const char &c : s) {
        count[c-'a']++;
    }

    int i = 0;
    while(i < s.size() && count[s[i]-'a'] >= k) i++;
    if(i == s.size()) return s.size();

    int leftLen = longestSubstring(s.substr(0, i), k);
    
    //跳过中间不满足条件的字符串
    while(i < s.size() && count[s[i]-'a'] < k) i++;
    if(i == s.size()) return leftLen;

    int righttLen = longestSubstring(s.substr(i), k);

    return std::max(leftLen, righttLen);    
}

*/
/*
#include <iostream>
#include <vector>

int longestSulbstring(std::string s, int k);

int main() {
    // std::string str = "aaabb";
    // int k = 3;
    std::vector<int> nums = {1,2,3};
    nums.resize(3, 0);

    for(const int &n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // std::cout << longestSulbstring(str, k) << std::endl;

    return 0;
}

int longestSulbstring(std::string s, int k)
{
    int len = 0;

    //维持一个滑动窗口,比如i=3,k=5,找到一个最大的窗口只包含三个唯一字符,并且每个字符出现至少5次
    for(int i = 1; i <= 2; i++)
    {
        std::vector<int> count(26, 0);
        int begin = 0, end = 0, uniqueChar = 0;
        while(end < s.size())
        {
            bool valid = true;
            if(count[s[end++]-'a']++ == 0) uniqueChar++;

            //只需要i个uniqueChar
            while(uniqueChar > i) {
                if(count[s[begin++]-'a']-- == 1) uniqueChar--;
            }

            //如果窗口中存在字符出现次数 >0 && <k 则该窗口内的字符串无效
            for(int j = 0; j < 26; j++) {
                if(count[j] > 0 && count[j] < k) valid = false;
            }

            // if(valid) len = std::max(len, end - begin);
            if(valid) {
                len = std::max(len, end - begin);
                std::cout << begin << " " << end << std::endl;
            }
        }

    }

    return len;
}

int minSubArrayLen(int target, std::vector<int> &nums)
{
    int left = 0, rightt = -1;
    int minLen = nums.size();
    int sum = 0;

    while(rightt < nums.size())
    {
        if(rightt+1 < nums.size() && sum < target) {
            rightt++;
            sum += nums[rightt];
        }
        else {
            sum -= nums[left];
            left++;
        }

        if(sum >= target && minLen > (rightt-left+1)) {
            minLen = rightt - left - 1;
        }
    }

    return minLen;
}


void flattern(TreeNode *root)
{
    if(root == nullptr) return;

    flattern(root->left);
    flattern(root->rightt);

    TreeNode *pNode = root->rightt;
    root->rightt = root->left;
    root->left = nullptr;

    //找到最右端的节点接上左边节点
    while(root->rightt) {
        root = root->rightt;
    }

    root->rightt = pNode;
}

Node* flattern(Node *head)
{
    if(head == nullptr) return head;

    Node *pNode = head;
    while(pNode)
    {
        //不存在子孩子
        if(pNode->child == nullptr) {
            pNode = pNode->next;
            continue;
        }   

        //存在子孩子,找到子孩子的尾节点连接到当前节点的下一个节点
        //将下一个节点的pre指针指向尾节点(如果下一个节点存在)
        //将当前节点的子孩子置空
        Node *pTemp = pNode->child;
        while(pTemp->next) {
            pTemp = pTemp->next;
        }
        pTemp->next = pNode->next;
        if(pNode->next != nullptr) {
            pNode->next->pre = pTemp;
        }

        pNode->next = pNode->child;
        pNode->child->prev = pNode;
        pNode->child = nullptr;
    }

    return head;
}


bool isValidBST(TreeNode *root)
{
    TreeNode *prev = nullptr;

    return isValidBSTCore(root, prev);
}

bool isValidBSTCore(TreeNode *root, TreeNode *&pre)
{
    if(root == nullptr) return true;

    if(!isValidBSTCore(root->left)) return false;

    if(pre && pre->val >= root->val) return false;

    pre = root;

    return isValidBSTCore(root->rightt, pre);
}


bool isValidBST(TreeNode *root)
{
    return isValidBSTCore(root, nullptr, nullptr);
}

bool isValidBSTCore(TreeNode *root, TreeNode *min, TreeNode *max)
{
    if(root == nullptr) return true;

    if(min && root->val <= min->val) return false;
    if(max && root->val >= max->val) return false;

    return isValidBSTCore(root->left, min, root) && isValidBSTCore(root->rightt, root, max);
}

int res = INT_MAX;

int getMinimumDifference(TreeNode *root)
{
    TreeNode *prev = nullptr;

    getMinimumDifferenceCore(root, prev);
}

void getMincore(TreeNode *root, TreeNode *&prev)
{
    if(root == nullptr) return ;

    getMincore(root->left, prev);

    if(prev && root->val-prev->val < res) {
        res = root->val - prev->val;
    }

    prev = root;

    getMincore(root->rightt, prev);
}


std::vector<int> res;
int maxFreq = 0, curFreq = 0;

std::vector<int> findMode(TreeNode *root)
{
    TreeNode *prev = nullptr;

    inorderTraversal(root, prev);

    return res;
}

void inorderTraversal(TreeNode *root, TreeNode *&prev)
{
    if(root == nullptr) return ;

    inorderTraversal(root->left, prev);

    if(prev && root->val == prev->val) {
        curFreq++;
    } else {
        curFreq = 1;
    }

    if(curFreq > maxFreq) {
        res.clear();
        maxFreq = curFreq;
        res.push_back(root->val);
    }
    else if(curFreq == maxFreq) {
        res.push_back(root->val);
    }

    prev = root;

    inorderTraversal(root->rightt, prev);
}

int res;

int kthSmallest(TreeNode *root, int k)
{
    kthSmallestCore(root, k);

    return res;
}

void kthSmallestCore(TreeNode *root, int &k)
{
    if(root == nullptr) return;

    kthSmallestCore(root->left, k);

    if(--k == 0) {
        res = root->val;
        return;
    }

    kthSmallestCore(root->rightt, k);
}

TreeNode* insertIntoBST(TreeNode *root, int val)
{
    if(root == nullptr) return (new TreeNode(val));

    if(root->val < val) {
        root->rightt = insertIntoBST(root->rightt, val);
    }
    else {
        root->left = insertIntoBST(root->left, val);
    }

    return root;
}


TreeNode* insertIntoBST(TreeNode *root, int val)
{
    if(root == nullptr) return (new TreeNode(val));

    TreeNode *tmp = root;

    dfs(tmp, val);

    return root;
}

void dfs(TreeNode *&root, int val)
{
    if(root == nullptr) {
        root = new TreeNode(val);
        return;
    }

    if(root->val < val) {
        dfs(root->rightt, val);
    }
    else {
        dfs(root->left, val);
    }
}


TreeNode* deleteNode(TreeNode *root, int key)
{
    if(root == nullptr) return root;

    if(root->val == key) 
    {
        if(root->left == nullptr) return root->rightt;
        else if(root->rightt == nullptr) return root->left;

        TreeNode *pNode = getMinNode(root->rightt);
        root->val = pNode->val;
        root->rightt = deleteNode(root->rightt, pNode->val);
    }
    else if(root->val < key) {
        root->rightt = deleteNode(root->rightt, key);
    }
    else if(root->val > key) {
        root->left = deleteNode(root->left, key);
    }

    return root;
}

TreeNode* getMinNode(TreeNode *root)
{
    while(root->left) {
        root = root->left;
    }

    return root;
}


TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root == nullptr) return root;

    if(root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    }
    else if(root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->rightt, p, q);
    }

    return root;
}

TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root == nullptr || root == p || root == q) return root;

    TreeNode *pLeft = lowestCommonAncestor(root->left, p, q);
    TreeNode *prightt = lowestCommonAncestor(root->rightt, p, q);

    if(pLeft && prightt) {
        return root;
    }

    return pLeft ? pLeft : prightt;
}

//计算普通二叉树的节点个数
//时间复杂度O(n)
int countNodes(TreeNode *root)
{
    if(root == nullptr) return 0;
    
    return 1 + countNodes(root->left) + countNodes(root->rightt);
}


//计算满二叉树的节点个数
//时间复杂度O(logn)
int countNodes(TreeNode *root)
{
    int hei = 0;
    while(root) {
        hei++;
        root = root->left;
    }

    return (int)pow(2, hei) - 1;
}

//计算完全二叉树的节点个数
//时间复杂度O(logn*logn)

int countNodes(TreeNode *root)
{
    int leftHei = 0, righttHei = 0;

    while(root) {
        leftHei++;
        root = root->left;
    }

    while(root) {
        righttHei++;
        root = root->rightt;
    }

    //是完全二叉树
    if(leftHei == righttHei) {
        return (int)pow(2, leftHei) - 1;
    }

    //不是完全二叉树

    return 1 + countNodes(root->left) + countNodes(root->rightt);
}

std::vector<int> res;

bool pathSum(TreeNode *root, int targetSum)
{
    bool flag = dfs(root, targetSum);

    for(const int &n : res) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return flag;
}

bool dfs(TreeNode *root, int targetSum)
{
    if(root == nullptr) {
        res.pop_back();
        return false;
    };
    
    res.push_back(root->val);

    if(root->val == targetSum && root->left == nullptr && root->rightt == nullptr) return true;

    return pathSum(root->left, targetSum - root->val) || pathSum(root->rightt, targetSum - root->val);
}

std::vector<std::vector<int>> res;

std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum)
{
    std::vector<int> path;

    pathSumCore(root, targetSum, path);

    return res;
}

void pathSumCore(TreeNode *root, int targetSum, std::vector<int> &path)
{
    if(root == nullptr) return;

    res.push_back(root->val);

    if(root->val == targetSum && root->left == nullptr && root->rightt == nullptr) {
        res.push_back(path);
    }

    pathSumCore(root->left, targetSum-root->val, path);
    pathSumCore(root->rightt, targetSum-root->val, path);

    path.pop_back();
}


int pathSum(TreeNode *root, int sum)
{
    if(root == nullptr) return 0;

    return pathSumStartWithRoot(root) + pathSum(root->left, sum) + pathSum(root->rightt, sum);
}

int pathSumStartWithRoot(TreeNode *root, int sum)
{
    if(root == nullptr) return 0;

    int count = (root->val == sum) ? 1 : 0;

    count += pathSumStartWithRoot(root->left, sum - root->val);
    count += pathSumStartWithRoot(root->rightt, sum - root->val);

    return count;
}

std::vector<std::string> res;

std::vector<std::string> binaryTreePaths(TreeNode *root)
{
    std::string path;

    dfs(root, path);
    
    return res;
}

void dfs(TreeNode *root, std::string path)
{
    if(root == nullptr) return;

    if(root->left == nullptr && root->rightt == nullptr) {
        path += std::to_string(root->val);
        res.push_back(path);
    }

    dfs(root->left, path + std::to_string(root->val) + "->");
    dfs(root->rightt, path + std::to_string(root->val) + "->");

}


int res = INT_MIN;

int maxPathSum(TreeNode *root)
{
    maxPathSumCore(root);
    
    return res;
}

int maxPathSumCore(TreeNode *root)
{
    if(root == nullptr) return 0;

    int leftMax = std::max(0, maxPathSumCore(root->left));
    int righttMax = std::max(0, maxPathSumCore(root->rightt));

    res = std::max(res, root->val + leftMax + righttMax);

    return std::max(root->val, root->val + std::max(leftMax, rightMax));
}

std::vector<std::string> res;

std::vector<std::string> restoreIpAddresses(std::string s)
{
    std::string path;

    dfs(s, 0, 0, path);

    return res;
}

void dfs(std::string s, int count, int pos, std::string path)
{
    if(count > 4) return;

    if(count == 4 && pos == s.size()) {
        path.pop_back();
        res.push_back(path);
        return;
    }

    for(int i = 1; i <= 3 && pos + i <= s.size(); i++)
    {
        std::string str = s.substr(pos, i);
        if(str[0] == '0' && i != 1) return;
        else if(std::stoi(str) <= 255) {
            dfs(s, count + 1, pos + i, path + str + ".");
        }
    }

}

*/
/*
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

bool isIPV4(std::string IP);
bool isIPV6(std::string IP);
std::string validIpAddress(std::string IP);
std::vector<std::string> split(std::string str, char c);

int main() {
    // std::cout << validIpAddress("2001:0db8:85a3:0:0:8A2E:0370:7334") << std::endl;
    std::string str = "....";

    std::stringstream in(str);
    std::string out;

    while(getline(in, out, '.')) {
        std::cout << out;
    }

    return 0;
}

std::string validIpAddress(std::string IP)
{
    return isIPV4(IP) ? "IPv4" : (isIPV6(IP) ? "IPv6" : "Neither");
}

bool isIPV4(std::string IP)
{
    if(count(IP.begin(), IP.end(), '.') != 3) return false;

    std::string str;
    std::stringstream in(IP);

    std::vector<std::string> strs = split(IP, '.');
    if(strs.size() != 4) return false;

    for(auto str : strs)
    {
        if(str.empty()) return false;
        
        else if(str.size() > 3) return false;
        
        else if(str[0] == '0' && str.size() != 1) return false;

        for(const char &c : str) {
            if(!isdigit(c)) return false;
        }

        if(std::stoi(str) > 255) return false;
    }
    
    return true;
}


bool isIPV6(std::string IP)
{
    if(count(IP.begin(), IP.end(), ':') != 7) return false;

    std::stringstream in(IP);
    std::string str;

    std::vector<std::string> strs = split(IP, ':');
    if(strs.size() != 8) return false;

    for(auto str : strs)
    {
        if(str.empty()) return false;
        else if(str.size() > 4) return false;

        for(const char &c : str) {
            if(!((toupper(c) >= 'A' && toupper(c) <= 'F') || isdigit(c))) {
                return false;
            }
        } 
    }

    return true;
}

std::vector<std::string> split(std::string str, char c)
{
    std::stringstream in(str);
    std::string out;

    std::vector<std::string> res;

    while(getline(in, out, c)) {
        res.push_back(out);
    }

    return res;
}

int numIslands(std::vector<std::vector<char>> &grid)
{
    int count = 0;

    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == '1') {
                count++;
                dfs(grid, i, j);
            }
        }
    }

    return count;
}

void dfs(std::vector<std::vector<char>> &grid, int i, int j)
{
    int m = grid.size(), n = grid[0].size();

    if(i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == '1') 
    {
        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i , j + 1);
        dfs(grid, i, j - 1);
        
    }

}


std::vector<int> direction = {-1, 0, 1, 0, -1};

std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>> heights)
{
    std::vector<std::vector<int>> res;
    if(heights.empty() || heights[0].empty()) return res;

    int m = heights.size(), n = heights[0].size();
    std::vector<std::vector<int>> can_reach_p(m, std::vector<int>(n, 0)), can_reach_a(m, std::vector<int>(n, 0));

    for(int i = 0; i < m; i++) {
        dfs(heights, can_reach_p, i, 0);
        dfs(heights, can_reach_a, i, n-1);
    }

    for(int i = 0; i < n; i++) {
        dfs(heights, can_reach_p, 0, i);
        dfs(heights, can_reach_a, m-1, i);
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(can_reach_p[i][j] && can_reach_a[i][j]) {
                res.push_back({i, j});
            }
        }
    }

    return res;
}

void dfs(std::vector<std::vector<int>> heights, std::vector<std::vector<int>> &can_reach, int i, int j)
{
    int m = heights.size(), n = heights[0].size();

    if(can_reach(i, j)) return;
    
    can_reach[i][j] = 1;

    for(int k = 0; k < direction.size() - 1; k++) 
    {
        int x = i + direction[k], y = direction[k+1];
        if(x >= 0 && x < m && y >= 0 && y < n && heights[x][y] >= heights[i][j]) {
            dfs(heights, can_reach, x, y);
        }
    }    

}

std::vector<int> direction = {-1, 0, 1, 0, -1};

int longestIncreasingPath(std::vector<std::vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();

    std::vector<std::vector<int>> cache(m, std::vector<int>(n, 0));

    int res = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            dfs(matrix, cache, i, j);
            res = std::max(res, cache[i][j]);
        }
    }

    return res;
}

int dfs(std::vector<std::vector<int>> &matrix, std::vector<std::vector<int>> &cache, int i, int j)
{
    int m = matrix.size(), n = matrix[0].size();

    if(cache[i][j]) return cache[i][j];

    int len = 1;    //不能设置成0

    for(int k = 0; k < direction.size() - 1; k++) 
    {
        int x = i + direction[k], y = j + direction[k+1];
        if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
            len = std::max(len, 1 + dfs(matrix, cache, x, y));
        }
    }

    cache[i][j] = len;

    return len;
}
*/

/*
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

std::string longestCommonSubstring(std::string s, std::string t);
int myAtoi(std::string s);
int minMoves(std::vector<int> &nums);
void func(int *ptr);

int main() {
    // // std::vector<int> nums = {1,10,2,9};

    // // std::cout << minMoves(nums) << std::endl;
    // double num = 2.366;

    // // std::cout << ceil(log2(num)) << std::endl;

    // printf("%.2f\n", num);

    int *num = new int(2);

    std::cout << &num << std::endl;
    std::cout << num << std::endl;
    std::cout << *num << std::endl;

    func(num);
    std::cout << num << std::endl;

    return 0;
}

void func(int *ptr)
{
    if(ptr != nullptr) {
        std::cout << &(ptr) << std::endl;
        std::cout << ptr << std::endl;
        std::cout << *ptr << std::endl;
        ptr = nullptr;
    }
}

/*
std::string longestCommonSubstring(std::string s, std::string t)
{
    if(s.empty() || t.empty()) return "";

    int m = s.size(), n = t.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    int maxLen = 0, startIndex = 0;

    for(int i = 1; i <= m; i++) 
    {
        for(int j = 1; j <= n; j++) 
        {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if(maxLen < dp[i][j]) {
                    maxLen = dp[i][j];
                    startIndex = i - maxLen;
                }
            }
        }
    }

    return maxLen == 0 ? "" : s.substr(startIndex, maxLen);

    std::string res;
    for(int i = m, j = n; dp[i][j] >= 1;)
    {
        if(s[i-1] == t[j-1]) {
            res += s[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else j--;
    }

    reverse(res.begin(), res.end());

    return res;
}


int myAtoi(std::string s)
{
    if(s.empty()) return 0;

    int i = 0;
    int res = 0;
    bool minus = false;

    while(s[i] == ' ') i++;
    if(i == s.size()) return res;

    if(s[i] == '+') {
        i++;
    }
    else if(s[i] == '-') {
        minus = true;
        i++;
    }

    int flag = minus ? -1 : 1;
    while(i < s.size())
    {
        if(!isdigit(s[i])) break;

        if(res > INT_MAX/10 || (res == INT_MAX/10 && s[i]-'0' > 7)) {
            return INT_MAX;
        }
        else if(res < INT_MIN/10 || (res == INT_MIN/10 && s[i]-'0' > 8)) {
            return INT_MIN;
        }

        res = res*10 + (flag)*(s[i]-'0');
        i++;
    }

    return res;
}


int lengthOfLIS(std::vector<int> &nums)
{
    std::vector<int> dp(nums.size(), 1);

    int res = 1;

    for(int i = 0; i < nums.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        res = std::max(res, dp[i]);
    }

    return res;
}

int minMoves(std::vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int n = nums.size();

    int avg;
    if(n&1) {
        avg = nums[n>>1];
    }
    else {
        avg = (nums[n>>1] + nums[(n>>1)-1])/2;
    }

    int res = 0;
    for(int i = 0; i < nums.size(); i++) {
        res += abs(nums[i] - avg);
    }

    return res;
}

int minMoves(std::vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int i = 0, j = nums.size()-1;
    int res = 0;

    while(i < j) {
        res += nums[j--] - nums[i++];
    }

    return res;
}
*/

/*
void reorderList(ListNode *head)
{
    if(head == nullptr) return;

    ListNode *fast = head, *slow = head;
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *head2 = slow->next;
    slow->next = nullptr;

    head2 = reverse(head2);

    ListNode *head1 = head;

    //head1必须要求比head2要长
    mergeList(head1, head2);

}

ListNode *reverse(ListNode *head)
{
    ListNode *prev = nullptr;

    while(head) {
        ListNode *pNext = head->next;
        head->next = prev;
        prev = head;
        head = pNext;
    }

    return prev;
}

//之字形合并链表
void mergeList(ListNode *head1, ListNode *head2)
{
    while(head1 && head2)
    {
        ListNode *next1 = head1->next, next2 = head2->next;
        
        head1->next = head2;
        head1 = next1;
        head2->next = head1;
        head2 = next2;
    }

}


ListNode *detectCycle(ListNode *head)
{
    if(head == nullptr) return head;

    ListNode *fast = head, slow = head;

    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast) {
            ListNode *pNode = head;
            while(pNode != slow) {
                pNode = pNode->next;
                slow = slow->next;
            }
            return pNode;
        }
    }

    return nullptr;
}
*/

/*

std::vector<std::string> res;
bool isValid(const std::string &s);

std::vector<std::string> removeInvalidParentheses(std::string s);
void dfs(std::string s, int left, int rightt, int pos);

int main() {
    std::string s = ")(f";

    removeInvalidParentheses(s);

    for(auto &str : res) {
        std::cout << str << std::endl;
    }

    return 0;
}


std::vector<std::string> removeInvalidParentheses(std::string s)
{
    //先确定需要删除多少个左右括号
    int left = 0, rightt = 0;
    for(const char &c : s) {
        if(c == '(') left++;
        else if(c == ')') {
            if(left == 0) rightt++;
            else left--;
        }
    }

    // std::cout << left << " " << rightt << std::endl;

    std::string path;
    dfs(s, left, rightt, 0);

    return res;
}

void dfs(std::string s, int left, int rightt, int pos)
{
    if(left == 0 && rightt == 0) {
        if(isValid(s)) {
            res.push_back(s);
        }
        return;
    }

    if(left < 0 || rightt < 0) return;

    for(int i = pos; i < s.size(); i++)
    {
        if(i > pos && s[i] == s[i-1]) continue;

        std::string newStr = s.substr(0, i) + s.substr(i + 1);
        if(s[i] == '(') {
            dfs(newStr, left-1, rightt, i);
        }
        else if(s[i] == ')') {
            dfs(newStr, left, rightt-1, i);
        }
    }

}

bool isValid(const std::string &s)
{
    int count = 0;
    for(const char &c : s)
    {
        if(c == '(') count++;
        else if(c == ')') {
            if(count == 0) return false;
            count--;
        }
    }

    return count == 0;
}

std::vector<int> direction = {-1, 0, 1, 0, -1};

int islandPerimeter(std::vector<std::vector<int>> &grid)
{
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == 1) {
                return dfs(grid[i][j], i, j);
            }
        }
    }

    return 0;
}

int dfs(std::vector<std::vector<int>> &grid, int i, int j)
{
    int m = grid.size(), n = grid[0].size();

    grid[i][j] = 0;

    int count = 0;

    for(int k = 0; k < direction.size()-1; k++) 
    {
        int x = i + direction[k], y = j + direction[k+1];
        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) count++;
        else {
            count += dfs(grid, x, y);
        }
    }

    return count;
}

std::vector<int> direction = {-1,0,1,0,-1};

int maxAreaOfLands(std::vector<std::vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) {
                res = std::max(res, dfs(grid, i, j));
            }
        }
    }

    return res;
}

int dfs(std::vector<std::vector<int>> &grid, int i, int j)
{
    int m = grid.size(), n = grid[0].size();

    grid[i][j] = 0;

    int count = 1;
    for(int k = 0; k < direction.size() - 1; k++)
    {
        int x = i + direction[k], y = j + direction[k+1];
        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) continue;
        else {
            count += dfs(grid, x, y);
        } 
    }

    return count;
}


std::vector<std::vector<int>> res;

std::vector<std::vector<int>> levelOrder(TreeNode *root)
{
    if(root == nullptr) return res;

    dfs(root);

    return res;
}

void dfs(TreeNode *root)
{
    if(root == nullptr) return;

    dfs(root->left);

    res.push_back(root->val);

    dfs(root->rightt);
}


std::vector<std::vector<int>> levelOrder(TreeNode *root)
{
    std::vector<std::vector<int>> res;

    if(root == nullptr) return res;

    std::queue<TreeNode*> que;

    que.push(root);

    while(!que.empty())
    {
        std::vector<int> tmp;
        int n = que.size();
        for(int i = 0; i < n; i++) {
            TreeNode *pNode = que.front(); que.pop();
            tmp.push_back(pNode->val);
            if(pNode->left) que.push(pNode->left);
            if(pNode->rightt) que.push(pNode->rightt);
        }

        res.push_back(tmp);
    }

    return res;
}

//方法一:依然按照层序遍历的方式,只不过当遍历到偶数层时将其结果翻转下即可

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root)
{
    std::vector<std::vector<int>> res;

    if(root == nullptr) return res;

    std::queue<TreeNode*> que;
    que.push(root);

    int curLevel = 0;

    while(!que.empty())
    {
        int n = que.size();
        std::vector<int> tmp(n);
        for(int i = 0; i < n; i++)
        {
            TreeNode *pNode = que.front();  que.pop();
            if(curLevel == 1) {         //遍历到偶数层时倒着插就行
                tmp[n-1-i] = pNode->val;
            }
            else {
                tmp[i] = pNode->val;
            }

            if(pNode->left) que.push(pNode->left);
            if(pNode->rightt) que.push(pNode->rightt);
        }

        res.push_back(tmp);

        curLevel = 1 - curLevel;
    }

    return res;
}


int minSubArrayLen(int target, std::vector<int> &nums)
{
    int minLen = 0;

    int i = 0, j = 0;
    int sum = 0;

    while(i < nums.size())
    {
        if(j < nums.size() && sum < target) {
            sum += nums[j++];
        }
        else {
            sum -= nums[i++];
        }

        if(sum >= target) {
            minLen = std::min(minLen, j - i);
        }
    }

    return minLen;
}

int minSubArrayLen(int target, std::vector<int> &nums)
{
    int sum = 0;
    int i = 0;
    int minLen = INT_MAX;

    for(int j = 0; j < nums.size(); j++)
    {
        sum += nums[j];

        if(sum < target) continue;

        while(sum >= target) {
            minLen = std::min(minLen, j - i + 1);
            sum -= nums[i++];
        }
    }

    return minLen == INT_MAX ? 0 : minLen;
}


int maxProfit(std::vector<int> &prices)
{
    if(prices.size() <= 1) return 0;

    int minPrices = prices[0];
    int maxProfit = 0;

    for(int i = 1; i < prices.size(); i++)
    {
        maxProfit = std::max(maxProfit, prices[i] - minPrices);

        minPrices = std::min(minPrices, prices[i]);
    }

    return maxProfit;
}


std::vector<int> direction = {-1, 0, 1, 0, -1};

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>> &image, int sr, int sc, int newColor)
{
    int m = image.size(), n = image[0].size();

    int srcColor = image[sr][sc];

    if(srcColor == newColor) return image;  //新颜色和原来颜色相同就不需要替换

    dfs(image, sr, sc, srcColor, newColor);

    return image;
}

void dfs(std::vector<std::vector<int>> &image, int i, int j, int srcColor, int newColor)
{
    int m = image.size(), n = image[0].size();

    image[i][j] = newColor;

    for(int k = 0; k < direction.size() - 1; k++) 
    {
        int x = i + direction[k], y = j + direction[k+1];
        if(x >= 0 && x < m && y >= 0 && y < n && image[x][y] == srcColor) {
            dfs(image, x, y, srcColor, newColor);
        }
    }

}

void dfs(std::vector<std::vector<int>> &image, int i, int j, int srcColor, int newColor)
{
    int m = image.size(), n = image[0].size();

    if(i >= 0 && i < m && j >= 0 && j < n && image[i][j] == srcColor)
    {
        image[i][j] = newColor;

        dfs(image, i, j + 1, srcColor, newColor);
        dfs(image, i, j - 1, srcColor, newColor);
        dfs(image, i + 1, j, srcColor, newColor);
        dfs(image, i - 1, j, srcColor, newColor);
    }

}


int count = 0;

int countArranges(int n)
{
    std::vector<int> visited(n + 1, 0);

    dfs(n, 1, visited);

    return count;
}

void dfs(int n, int pos, std::vector<int> &visited)
{
    if(pos > n) {
        count++;
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i] && (pos%i == 0 || i%pos == 0)) {
            visited[i] = 1;
            dfs(n, pos + 1, visited);
            visited[i] = 0;
        }
    }
}

std::vector<int> direction = {-1, 0, 1, 0, -1};

int longestIncreasingPath(std::vector<std::vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();

    std::vector<std::vector<int>> cache(m, std::vector<int>(n, 0));

    int res = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            res = std::max(res, dfs(matrix, i, j, cache));
        }
    }

    return res;
}

int dfs(std::vector<std::vector<int>> &matrix, int i, int j, std::vector<std::vector<int>> &cache)
{
    if(cache[i][j]) return cache[i][j];

    int maxLen = 1;

    for(int k = 0; k < direction.size() - 1; k++)
    {
        int x = i + direction[k], y = j + direction[k+1];
        if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] < matrix[i][j]) {
            // maxLen += dfs(matrix, x, y, cache);
            maxLen = std::max(maxLen, 1 + dfs(matrix, x, y, cache));
        }
    }

    cache[i][j] = maxLen;

    return maxLen;
}


int kthSmallest(std::vector<std::vector<int>> &matrix, int k)
{
    int n = matrix.size();

    int left = matrix[0][0], rightt = matrix[n-1][n-1];

    while(left <= rightt)
    {
        int mid = left + ((rightt-left) >> 1);

        int count = 0;
        for(int i = 0; i < n; i++) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if(count >= k) {
            rightt = mid - 1;
        }
        else if(count < k) {
            left = mid + 1;
        }
    }

    return left;
}

int subarraySum(std::vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;

    for(int i = 0; i < n; i++) 
    {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += nums[i];
            if(sum == k) {
                count++;
            }
        }
    }

    return count;
}

//利用前缀和

int subarraySum(std::vector<int> &nums, int k)
{
    int n = nums.size();

    std::vector<int> preSum(n+1, 0);
    for(int i = 0; i < n; i++) {
        preSum[i+1] = preSum[i] + nums[i];
    }

    int count = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            if(preSum[i] - preSum[j] == k) {
                count++;
            } 
        }
    }

    return count;
}
*/

/*
std::vector<std::vector<int>> subarraySum(std::vector<int> &nums, int k);

class Test 
{
public:    
    Test() {}

private:
    std::vector<int> nums {std::vector<int>(5, 0)};

};

int main() {
    std::vector<int> nums = {0,0};
    int k = 0;

    std::vector<std::vector<int>> res = subarraySum(nums, k);

    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            std::cout << res[i][j] <<  " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

/*
std::vector<std::vector<int>> subarraySum(std::vector<int> &nums, int k)
{
    std::vector<std::vector<int>> res;

    std::unordered_map<int,std::vector<int>> hash;
    // hash[0] = 1;

    int sum = 0;
    
    for(int i = 0; i < nums.size(); i++) 
    {
        sum += nums[i];
        if(sum - k == 0) {
            std::vector<int> tmp;
            for(int j = 0; j <= i; j++) {
                tmp.push_back(j);
            }
            res.push_back(tmp);
            hash[sum].push_back(i);
        }
        else if(hash.count(sum - k)) {
            for(auto n : hash[sum-k]) {
                std::vector<int> tmp;
                for(int j = n+1; j <= i; j++) {
                    tmp.push_back(j);
                }
                res.push_back(tmp);
            }
        }
        hash[sum].push_back(i);
    }

    return res;
}
*/
/*
std::vector<std::vector<int>> subarraySum(std::vector<int> &nums, int k)
{
    std::vector<std::vector<int>> res;

    std::unordered_map<int,std::vector<int>> hash;

    int sum = 0;

    std::vector<int> index;

    for(int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        int diff = sum - k;

        if(hash.count(diff)) 
        {
            for(int n : hash[diff]) {
                index.clear();
                for(int j = n + 1; j <= i; j++) {
                    index.push_back(j);
                }
            }

            res.push_back(index);
        }

        if(diff == 0) {
            index.clear();
            for(int j = 0; j <= i; j++) {
                index.push_back(j);;
            }
            res.push_back(index);
        }

        hash[sum].push_back(i);
    }

    return res;
}

int numberOfSubarrays(std::vector<int> &nums, int k)
{
    int count = 0, oddNum = 0;
    std::unordered_map<int,int> hash;
    hash[0] = 1;

    for(int &n : nums) 
    {
        oddNum += (n & 1);
        count += hash[oddNum-k];
        hash[oddNum]++;
    }

    return count;
}

int numSubmatrixSumTarget(std::vector<std::vector<int>> &matrix, int target)
{
    int m = matrix.size(), n = matrix[0].size();

    for(int i = 0; i < m; i++) {
        for(int j = 1; j < n; j++) {
            matrix[i][j] += matrix[i][j-1];
        }
    }

    std::unordered_map<int,int> hash;

    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++)  
        {
            hash = {{0,1}};
            int cur = 0;
            for(int k = 0; k < m; k++) {
                cur += matrix[k][j] - (i > 0 ? matrix[k][i-1] : 0);
                count += hash[cur-target];
                hash[cur]++;
            }
        }
    }

    return count;
}

//删除链表的指定节点

ListNode* deleteNode(ListNode *head, ListNode *pDelete)
{
    if(head == nullptr) return head;
    if(head == pDelete) return head->next;

    ListNode *prev = head, *pNext = head->next;

    while(pNext && pNext != pDelete)
    {
        prev = pNext;
        pNext = pNext->next;
    }

    if(pNext == nullptr) return head;   //没有要删除的pDelete

    prev->next = prev->next->next;

    return head;
}

ListNode* deleteDuplicates(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *cur = head;

    while(cur && cur->next)
    {
        if(cur->val == cur->next->val) {
            cur->next = cur->next->next;
        }
        else {
            cur = cur->next;
        }
    }

    return head;
}


ListNode* deleteDuplicates(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *base = new ListNode(-1);
    base->next = head;

    ListNode *cur = base;
    while(cur->next && cur->next->next)
    {
        /*
        int value = cur->next->val;
        if(cur->next->next->val == value)
        {
            ListNode *pNext = cur->next;
            while(pNext && pNext->val == value) {
                pNext = pNext->next;
            }
            
            cur->next = pNext;
        }
        
        if(cur->next->val == cur->next->next->val) {

        }
        else {
            cur = cur->next;
        }
    }

    return base->next;
}

ListNode* deleteDuplicates(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *cur = head;
    while(cur && cur->next)
    {
        if(cur->val == cur->next->val) {
            cur = cur->next->next;
        }
        else {
            cur = cur->next;
        }
    }

    return head;
}

ListNode* reverseKGroup(ListNode *head, int k)
{
    ListNode *base = new ListNode(-1);
    base->next = head;

    ListNode *pNode = base;
    while(pNode)
    {
        ListNode *lastGroup = pNode;

        int i = 0;
        for(; i < k; i++) {
            // if(pNode == nullptr) break;      //这表示当前节点不为空,但是下一个节点可能为空
            pNode = pNode->next;
            if(pNode == nullptr) break;         //易错:这表示移动后的下一个节点不能为空
        }

        if(i == k)
        {
            ListNode *nextGroup = pNode->next;

            ListNode *reverseList = reverse(lastGroup->next, nextGroup);    //易错:这是lastGroup->next
           
            pNode = lastGroup->next;
            lastGroup->next = reverseList;
            pNode->next = nextGroup;
        }
    }

    return base->next;
}

ListNode* reverse(ListNode *head, ListNode *tail)
{
    ListNode *prev = nullptr;

    while(head && head != tail)
    {
        ListNode *pNode = head->next;
        head->next = prev;
        prev = head;
        head = pNode;
    }

    return prev;
}


void reorderList(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return ;

    //切分链表
    ListNode *slow = head, *fast = head;
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *headTwo = slow->next;

    slow->next = nullptr;

    ListNode *headOne = head;

    headTwo = reverse(headTwo);

    mergeTwoLists(headOne, headTwo);

}

ListNode *reverse(ListNode *head)
{
    ListNode *prev = nullptr;

    while(head) {
        ListNode *pNode = head->next;
        head->next = prev;
        prev = head;
        head = pNode;
    }

    return prev;
}

void mergeTwoLists(ListNode *l1, ListNode *l2)
{
    while(l1 && l2)
    {
        ListNode *next1 = l1->next;
        ListNode *next2 = l2->next;

        l1->next = l2;
        l1 = next1;
        l2->next = l1;
        l2 = next2;
    }

}


bool isValidBST(TreeNode *root)
{
    TreeNode *prev = nullptr;

    return dfs(root, prev);
}

bool dfs(TreeNode *root, TreeNode * &prev)
{
    if(root == nullptr) return true;

    if(!dfs(root->left, prev)) return false;

    if(prev && root->val <= prev->val) return false;

    prev = root;

    return dfs(root->rightt, prev);
}


std::vector<std::vector<int>> res;

std::vector<std::vector<int>> subsets(std::vector<int> &nums)
{
    std::vector<int> path;

    dfs(nums, 0, path);

    return res;
}

void dfs(std::vector<int> &nums, int pos, std::vector<int> &path)
{
    res.push_back(path);

    for(int i = pos; i < nums.size(); i++)
    {
        res.push_back(nums[i]);
        dfs(nums, i + 1, path);
        path.pop_back();
    }

}

TreeNode* insertIntoBST(TreeNode *root, int value)
{
    if(root == nullptr) root = new TreeNode(val);   //这样对指针赋值递归完成后传不出去,这块空间就释放了

    if(root->val < value) {
        insertIntoBST(root->rightt, value);
    }
    else if(root->val > value) {
        insertIntoBST(root->left, value);
    }

    return root;
}

// TreeNode* insertIntoBST(TreeNode *root, int value)
// {
//     TreeNode *tmp = root;

//     dfs(tmp, value);

//     return root;
// }

// void dfs(TreeNode *&root, int value)
// {
//     if(root == nullptr) root = new TreeNode(value);

//     if(root->val < value) {
//         dfs(root->rightt, value);
//     }
//     else {
//         dfs(root->left, value);
//     }

// }

TreeNode *insertIntoBST(TreeNode *root, int value)
{
    if(root == nullptr) return new TreeNode(value);

    if(root->val < value) {
        root->rightt = insertIntoBST(root->rightt, value);
    }
    else {
        root->left = insertIntoBST(root->left, value);
    }

    return root;
}


TreeNode* deleteNode(TreeNode *root, int key)
{
    if(root == nullptr) return root;

    if(root->val == key)
    {
        if(root->left == nullptr) return root->rightt;
        else if(root->rightt == nullptr) return root->left;

        TreeNode *minNode = getMinNode(root->left, key);
        root->val = minNode->val;

        root->left = deleteNode(root->left, minNode->val);
    }
    else if(root->val < key)
    {
        root->rightt = deleteNode(root->rightt, key);
    }
    else if(root->val > key)
    {
        root->left = deleteNode(root->left, key);
    }

    return root;
}

TreeNode *getMinNode(TreeNode *root, int key)
{
    while(root->rightt) {
        root = root->rightt;
    }

    return root;
}


int res = INT_MIN;

int maxPathSum(TreeNode *root)
{
    dfs(root);

    return res;
}

int dfs(TreeNode *root)
{
    if(root == nullptr) return 0;

    int leftMax = std::max(0, dfs(root->left));
    int righttMax = std::max(0, dfs(root->rightt));

    res = std::max(res, root->val + leftMax + righttMax);

    return std::max(root->val, root->val + std::max(leftMax, righttMax));
}


int res = INT_MIN;

int diameterOFBinaryTree(TreeNode *root)
{
    dfs(root);

    return res - 2;
}

int dfs(TreeNode *root)
{
    if(root == nullptr) return 0;

    int leftMax = 1 + dfs(root->left);
    int righttMax = 1 + dfs(root->rightt);

    res = std::max(res, leftMax + rightMax);

    return std::max(leftMax, rightMax);
}

int diameterOFBinary(TreeNode *root)
{
    dfs(root);

    return res;
}

int dfs(TreeNode *root)
{
    if(root == nullptr) return 0;

    int leftMax = dfs(root->left), rightMax = dfs(root->right);

    res = std::max(res, leftMax + rightMax);

    return std::max(leftMax, rightMax) + 1;
}

std::vector<std::vector<int>> res;

std::vector<std::vector<int>> combine(int n, int k)
{
    std::vector<int> path;

    dfs(n, k, 1, path);

    return res;
}

void dfs(int n, int k, int pos, std::vector<int> &path)
{
    if(path.size() == k) {
        res.push_back(path);
        return;
    }

    for(int i = pos; i <= n; i++)
    {
        path.push_back(i);
        dfs(n, k, i +1, path);
        path.pop_back();
    }

}

std::vector<std::vector<int>> res;

std::vector<std::vector<int>> permutation(std::vector<int> &nums)
{
    dfs(nums, 0);

    return res;
}

void dfs(std::vector<int> &nums, int pos)
{
    if(pos == nums.size()) {
        res.push_back(nums);
        return;
    }

    for(int i = pos; i < nums.size(); i++)
    {
        std::swap(nums[i], nums[pos]);
        dfs(nums, pos + 1);
        std::swap(nums[i], nums[pos]);
    }

}

int maxValue(std::vector<std::vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

    dp[0][0] = grid[0][0];

    for(int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    for(int i = 1; i < m; i++) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    } 

    return dp[m-1][n-1];
}

int maxValue(std::vector<std::vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for(int i = 1; i <= m ;i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
        }
    }

    return dp[m][n];
}

int maxValue(std::vector<std::vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    std::vector<int> dp(n + 1, 0);

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            dp[j] = std::max(dp[j], dp[j-1]) + grid[i-1][j-1];
        }
    }

    return dp[n];
}

int longestSubstring(std::string str, int k)
{
    if(str.empty() || str.size() < k) return 0;

    std::unordered_map<char,int> hash;
    for(const char &c : str) {
        hash[c]++;
    }

    int i = 0;
    while(i < str.size() && hash[str[i]] >= k) i++;
    if(i == str.size()) return str.size();

    int left = longestSubstring(str.substr(0, i), k);

    while(i < str.size() && hash[str[i]] < k) i++;

    if(i == str.size()) return left;

    int rightt = longestSubstring(str.substr(i), k);

    return std::max(left, rightt);
}

int minSubArrayLen(int target, std::vector<int> &nums)
{
    int sum = 0, minLen = INT_MAX;
    int j = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        while(sum >= target) {
            minLen = std::min(minLen, i - j + 1);
            sum -= nums[j++];
        }
    }

    return minLen == INT_MAX ? 0 : minLen;
}


int longestSubstring(std::string s, int k)
{
    int maxLen = 0;

    //表示窗口中有几个不同字符
    for(int i = 1; i <= 26; i++)
    {
        std::vector<int> count(26,0);   //统计每个字符出现的频率

        int begin = 0, end = 0, uniqueChar = 0;
        while(end < s.size())
        {
            bool valid = true;
            if(count[s[end++]-'a']++ == 0) uniqueChar++;

            while(i < uniqueChar) {
                if(count[s[begin++]-'a']-- == 1) uniqueChar--;
            }

            for(int i = 0; i < 26; i++) {
                if(count[i] > 0 && count[i] < k) valid = false;
            }

            if(valid) maxLen = std::max(maxLen, end - begin);
        }
    }

    return maxLen;
}


std::vector<int> findAnagrams(std::string s, std::string p)
{
    std::vector<int> res;
    if(s.size() < p.size()) return res;

    //先统计p中字符出现的次数
    std::vector<int> pFreq(26, 0), count(26, 0);
    for(int i = 0; i < p.size(); i++) {
        pFreq[p[i]-'a']++;
        count[s[i]-'a']++;
    }    

    if(count == pFreq) res.push_back(0);

    for(int i = p.size(); i < s.size(); i++)
    {
        count[s[i]-'a']++;
        count[s[i-p.size()]-'a']--;

        if(count == pFreq) res.push_back(i - p.size() + 1);
    }

    return res;
}

std::vector<int> findAnagrams(std::string s, std::string p)
{
    std::vector<int> res;
    if(s.size() < p.size()) return res;

    //先统计p中字符出现的次数
    std::vector<int> pFreq(26, 0), count(26, 0);

    for(const char &c : p) {
        pFreq[c-'a']++;
    }

    for(int i = 0; i < s.size(); i++)
    {
        count[s[i]-'a']++;

        // if(i == p.size() - 1) {
        //     if(count == pFreq) res.push_back(0);
        //     continue;
        // }

        if(i - p.size() >= 0) {
            count[s[i-p.size()]-'a']--;
        }

        if(count == pFreq) res.push_back(i - p.size() + 1);
    }

    return res;
}

*/
/*


struct Node {
    int x;  
    int length;
    Node(int x, int length) {
        this->x = x;
        this->length = length;
    }
}

struct Cmp {
    bool operator()(Node node1, Node node2) {
        return node1.length > node2.length;
    }
};


int main() {
    std::vector<std::vector<int>> map(6, std::vector<int>(6, 0));

    initMap(map);

    std::vector<int> isVisited(6, 0);
    std::vector<int> len(6, INT_MAX);

    // std::priority_queue<Node> pq;
    std::priority_queue<Node, std::vector<Node>, Cmp> pq;
    len[0] = 0;
    pq.push(Node(0,0));

    while(!pq.empty())
    {
        Node t1 = pq.top(); pq.pop();
        int index = t1.x;
        int length = t1.length;
        isVisited[index] = 1;

        for(int i = 0; i < map[index].size(); i++)
        {
            if(map[index][i] > 0 && !isVisited[i]) 
            {
                Node node = Node(i, length + map[index][i]);
                if(len[i] > node.length) {                  //找到到第i点最近的路径
                    len[i] = node.length;
                    pq.push(node);
                }
            }
        }
    }



    return 0;
}

void initMap(std::vector<std::vector<int>> &map)
{
    map[0][1] = map[1][0] = 2;  map[0][2] = map[2][0] = 3;  map[0][3] = map[3][0] = 6;
    map[1][4] = map[4][1] = 4;  map[1][5] = map[5][1] = 6;
    map[2][3] = map[3][2] = 2;
    map[3][4] = map[4][3] = 1;  map[3][5] = map[5][3] = 3;
}


//用number来表示数字,sign来表示符号(对number应该进行什么操作)
//遇到'+'或者'-'号就将number加入到result中,并重新设置

int calculate(std::string s)
{
    int number = 0;
    int sign = 1;
    int result = 0;
    std::stack<int> sta;

    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if(isdigit(c)) {
            number = number*10 + (c - '0');
        }
        else if(c == '+') {
            result += sign*number;
            sign = 1;
            number = 0;
        }
        else if(c == '-') {
            result += sign*number;
            sign = -1;
            number = 0;
        }
        else if(c == '(') {
            sta.push(result);
            sta.push(sign);
            result = 0;
            sign = 1;
        }
        else if(c == ')') {
            result += number*sign;
            number = 0;
            result *= sta.top();    sta.pop();
            result += sta.top();    sta.pop();
        }
    }

    if(number != 0) result += sign*number;

    return result;
}

int candy(std::vector<int> &ratings)
{
    int n = ratings.size();

    std::vector<int> res(n, 1);

    for(int i = 1; i < n; i++) {
        if(ratings[i] > ratings[i-1]) {
            res[i] = res[i-1] + 1;
        }
    }

    for(int i = n-2; i >= 0; i--) {
        if(ratings[i] > ratings[i+1]) {
            // if(res[i] <= res[i+1]) {
                // res[i] = res[i+1] + 1;
            // }
            res[i] = std::max(res[i], res[i+1] + 1);
        }
    }

    return accumulate(res.begin(), res.end(), 0);
}


Node* copyRandomList(Node *head)
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

Node* copyRandomList(Node *head)
{
    if(head == nullptr) return head;

    Node *cur = head;
    while(cur) {
        Node *pNext = cur->next;
        Node *newNode = new Node(cur->val);
        cur->next = newNode;
        newNode->next = pNext;
        cur = pNext;
    }

    //复制随机指针
    cur = head;
    while(cur)
    {
        if(cur->random) {
            cur->next->random = cur->random->next;
        }
        cur = cur->next->next;
    }

    //提取出偶数节点,还原原来的链表节点
    Node *pCopyHead = head->next;
    Node *pCopy = pCopyHead;
    cur = head;

    while(pCopy && pCopy->next) {
        cur = cur->next = pCopy->next;
        pCopy = pCopy->next = cur->next;
    }

    cur->next = nullptr;

    return pCopyHead;
}

ListNode* oddEvenList(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *pOdd = head, pEvenHead = head->next;
    ListNode *pEven = pEvenHead;
    
    while(pEven && pEven->next)
    {
        pOdd = pOdd->next = pEven->next;
        pEven = pEven->next = pOdd->next;
    }

    pOdd->next = pEvenHead;

    return head;
}

int findDuplicate(std::vector<int> &nums)
{
    int start = 1, end = nums.size() - 1;
    
    while(start <= end)
    {
        int mid = start + ((end-start) >> 1);
        int count = countRange(nums, start, mid);

        if(start == end) {
            return start;
        }
        else if(count > (mid - start + 1)) {
            end = mid;
        }
        else {
            start = mid + 1;
        }
    }

    return -1;
}

int countRange(std::vector<int> &nums, int start, int end)
{
    int count = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] >= start && nums[i] <= end) count++;
    }

    return count;
}


int findDuplicate(std::vector<int> &nums)
{
    for(int i = 0; i < nums.size(); i++) {
        int index = abs(nums[i]);
        if(nums[index] < 0) {
            return abas(nums[i]);
        }
        else nums[index] *= (-1);
    }

    return -1;
}


int findDuplicate(std::vector<int> &nums)
{
    int left = 1, rightt = nums.size() - 1;

    while(left <= right)
    {
        int mid = left + ((right-left) >> 1);
        int count;
        for(const int &n : nums) {
            if(mid >= n) count++;
        }

        if(count <= mid) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }    

    return left;
}
*/

/*
int findDuplicate(std::vector<int> &nums);

int main() {
    std::vector<int> nums = {1,3,4,2,2};

    std::cout << findDuplicate(nums) << std::endl;

    return 0;
}

// int findDuplicate(std::vector<int> &nums)
// {
//     int left = 1, rightt = nums.size() - 1;

//     while(left < rightt)
//     {
//         int mid = left + ((rightt-left) >> 1);
//         int count = 0;
//         for(const int &n : nums) {
//             if(mid >= n) count++;
//         }

//         if(count <= mid) {
//             left = mid + 1;
//         }
//         else {
//             rightt = mid;
//         }
//     }    

//     return left;
// }


std::vector<int> findDuplicate(std::vector<int> &nums)
{
    std::vector<int> res;

    for(int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;
        if(nums[index] < 0) {
            res.push_back(abs(nums[i]));
        }
        else {
            nums[index] *= (-1);
        }
    }

    return res;
}

std::vector<int> findDisappearedNumbers(std::vector<int> &nums)
{
    std::vector<int> res;

    for(int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;
        if(nums[index] > 0) {
            nums[index] *= (-1);
        }
    }

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > 0) {
            res.push_back(i + 1);
        }
    }

    return res;
}

std::vector<int> searchReange(std::vector<int> &nums, int target)
{
    int first = leftBound(nums, target);
    int second = rightBound(nums, target);

    return {first, second};
}

int leftBound(std::vector<int> &nums, int target)
{
    int left = 0, rightt = nums.size() - 1;

    while(left <= right)
    {
        int mid = left + ((right-left) >> 1);

        if(nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if(left >= nums.size() || nums[left] != target) return -1;

    return left;
}

int rightBound(std::vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while(left <= right)
    {
        int mid = left + ((right-left) >> 1);

        if(nums[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    if(right < 0 || nums[right] != target) return -1;

    return right;
}


std::vector<int> searchReange(std::vector<int> &nums, int target)
{
    int first;
    auto itFirst = lower_bound(nums.begin(), nums.end(), target);
    if(itFirst == nums.end() || *itFirst != target) first = -1;
    else first = itFirst - nums.begin();

    int second;
    auto itSecond = upper_bound(nums.begin(), nums.end(), target);
    if(itSecond == nums.begin()) second = -1;   //数组元素都大于target
    else if(*(--itSecond) != target) second = -1;   //数组元素都小于targett或者数组中元素不存在target
    else {
        second = itSecond - nums.begin();
    }

    return {first, second};
}

int search(std::vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while(left <= right)
    {
        int mid = left + ((right-left) >> 1);

        if(nums[mid] == target)  {
            return true;
        }
        else if(nums[mid] < nums[right]) {
            if(nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        else if(nums[mid] > nums[right]) {
            if(nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        else if(nums[mid] == nums[right]) {
            right--;
        }
    }

    return false;
}

int findMin(std::vector<int> &nums)
{
    int left = 0, right = nums.size();

    while(left < right)
    {
        int mid = left + ((right-left) >> 1);

        if(nums[mid] > nums[right]) {
            left = mid + 1;
        }
        else if(nums[mid] < nums[right]) {
            right = mid;
        }
        else if(nums[mid] == nums[right]) {
            right--;
        }
    }

    return left;
}


std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
{
    std::deque<int> dq;
    std::vector<int> res;

    for(int i = 0; i < nums.size(); i++)
    {
        if(dp.front() == i-k) {
            dp.pop_front();
        }

        while(!dq.empty() && nums[i] > nums[dp.back()]) {
            dp.pop_back();
        }

        dq.push_back(i);

        if(i >= k-1) {
            res.push_back(nums[dp.front()]);
        }
    }

    return res;
}


int maxProduct(std::vector<std::string> &words)
{
    std::vector<int> len(words.size(), 0);

    for(int i = 0; i < words.size(); i++) {
        for(const char &c : words[i]) {
            len[i] |= (1 << (c - 'a'));
        }
    }

    int res = 0;
    for(int i = 0; i < len.size(); i++) {
        for(int j = i + 1; j < len.size(); j++) {
            if((len[i]&len[j]) == 0) {
                res = std::max(res, (int)(words[i].size()*words[j].size()));
            }
        }
    }

    return res;
}


bool repeatedSubstringPattern(std::string s)
{
    if(s.size() == 1) return false;

    std::string str = s + s;

    str.pop_back();
    str.erase(0, 1);

    if(std.find(s) != std::string::npos) {
        return true;
    }
    
    return false;
}


bool wordBreak(std::string s, std::vector<std::string> &wordDict)
{
    int m = wordDict.size(), n = s.size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for(int i = 0; i < m; i++) {
        for(int j = 1; j <= n; j++) {
            int len = wordDict[i].size();
            if(j >= len && s.substr(j-len, len) == wordDict[i]) {
                dp[i][j] = dp[i][j-len];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[m-1][n];
}


int numSquare(int n)
{
    std::vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j*j <= i; j++) {
            dp[i] = std::min(dp[i], dp[i-j*j] + 1);
        }
    }

    return dp[n];
}

int numDecodings(std::string s)
{
    if(s.empty()) return 0;

    if(s[0] == '0') return 0;

    int n = s.size();
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1, dp[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        int first = std::stoi(s.substr(i-1, 1));
        int second = std::stoi(s.substr(i-2, 2));

        if(first > 0 && first <= 9) dp[i] += dp[i-1];
        if(second >= 10 && second <= 26) dp[i] += dp[i-2];
    }

    return dp[n];
}

//dp[i]表示当前位置是否可分割
//则dp[i] = dp[i-len], if s[i-len,i]==word

bool wordBreak(std::string s, std::vector<std::string> &wordDict)
{
    int n = s.size();
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < wordDict.size(); j++) {
            int len = wordDict[j].size();
            if(i >= len && s.substr(i-len, len) == wordDict[j]) {
                dp[i] = dp[i] || dp[i-len];
            }
        }
    }

    return dp[n];
}
*/



/*
std::unordered_map<std::string, std::vector<std::string>> hash;

std::vector<std::string> dfs(std::string s, std::vector<std::string> &wordDict);
std::vector<std::string> wordBreak(std::string s, std::vector<std::string> &wordDict);

int main() {
    // std::string s = "catsanddog";
    // std::vector<std::string> wordDict = {"cat","cats","and","sand","dog"};

    // std::vector<std::string> res = wordBreak(s, wordDict);

    // for(const auto &str : res) {
    //     std::cout << str << std::endl;
    // }

    std::string str;
    str += "";
    str += "";
    if(str.empty()) {
        std::cout << "Empty!" << std::endl;
    }

    return 0;
}



std::vector<std::string> wordBreak(std::string s, std::vector<std::string> &wordDict)
{
    return dfs(s, wordDict);
}

std::vector<std::string> dfs(std::string s, std::vector<std::string> &wordDict)
{
    if(hash.count(s)) {
        return hash[s];
    }

    std::vector<std::string> res;
    if(s.empty()) {
        res.push_back("");  //表示结尾  ""代表空字符串
        return res;
    }

    for(const std::string &word : wordDict)
    {
        int len = word.size();

        if(len <= s.size() && s.substr(0,len) == word) 
        {
            std::vector<std::string> subStr = dfs(s.substr(len), wordDict);
            
            for(std::string &str : subStr) {
                res.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
    }

    hash[s] = res;

    return res;
}

*/

/*
class A 
{
public: 
    int a;
};

class B : virtual public A
{
public:
    // int b;

};

class C : virtual public A
{
public:
    // int c;
};

class D : public B, public C
{
public:
    // int d;
};



/*
class Sub
{
public:
    void print() { std::cout << "Sub print!" << std::endl; }
};

class Child : public Base, public Sub
{
public:
    // void print() { std::cout << "Child" }

};
*/



/*
class Base
{
public:
    void print() { std::cout << "Base print!" << std::endl; }
    Base(){ std::cout << "Constructor" << std::endl; }
};

class Mid1 : virtual public Base
{
public:

};

class Mid2 : virtual public Base
{
public:

};

class Child : public Mid1, public Mid2
{
public:

};

int main() {
    // Child d;
    // d.print();

    std::cout << sizeof(A) << std::endl;
    std::cout << sizeof(B) << std::endl;
    std::cout << sizeof(C) << std::endl;
    std::cout << sizeof(D) << std::endl;

    return 0;
}

int findDuplicate(std::vector<int> &nums)
{
    int left = 1, right = nums.size() - 1;

    while(left < right)
    {
        int mid = left + ((right-left) >> 1);
        int count = 0;
        for(const int &n : nums) {
            if(mid >= n) count++;
        }

        if(count <= mid) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return left;
}

std::vector<int> findErrorNums(std::vector<int> &nums)
{
    std::vector<int> res;

    //找到重复的数字
    for(int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;
        if(nums[index] < 0) {
            res.push_back(abs(nums[i]));
        }
        else {
            nums[index] *= (-1);
        }
    }

    //找到缺失的数字
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > 0) {
            res.push_back(i + 1);
        }
    }

    return res;
}


//方法一:两和相减

int misssingNumber(std::vector<int> &nums)
{
    int n = nums.size();

    int total = (0+n)*(n+1)/2;

    int sum = accumulate(nums.begin(), nums.end(), 0);

    return total - sum;
}

//方法二:位运算

int misssingNumber(std::vector<int> &nums)
{
    int n = nums.size();

    int res = n;

    for(int i = 0; i < n; i++) {
        res ^= i^nums[i];
    }

    return res;
}



// dp[i][j]表示s[0..i]和p[0..j]是否匹配成功

//1. s[i]=s[j] || p[j]='.' dp[i][j] = dp[i-1][j-1]
//2. p[j] = '*'
//   (1). s[i]!=p[j-1] && p[j-1]!='.', 这时只能将p的'*'和它前面的单个字符忽略 dp[i][j] = dp[i][j-2]
//   (2). 

bool isMatch(std::string s, std::string p)
{
    int m = s.size(), n = p.size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for(int j = 1; j <= n; j++) {
        if(p[j-1] == '*') {
            dp[0][j] = dp[0][j-2];
        }
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == p[j-1] || p[j-1] == '.') {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] == '*') {
                if(s[i-1] != p[j-2] && p[j-2] != '.') {
                    dp[i][j] = dp[i][j-2];
                }
                else {
                    dp[i][j] = dp[i][j-1] || dp[i][j-2] || dp[i-1][j];
                }
            }
        }
    }

    return dp[m][n];
}


// dp[i][j]
// s[i] == p[j] || p[j] == '?'  dp[i][j] = dp[i-1][j-1]
// p[j] = '*'   dp[i][j] = dp[i-1][j] || dp[i][j-1]

bool isMatch(std::string s, std::string p)
{
    int m = s.size(), n = p.size();

    std::vector<int> dp(m + 1, std::vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for(int j = 1; j <= n; j++) {
        if(p[j-1] == '*') {
            dp[0][j] = dp[0][j-1];
        }
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == p[j-1] || p[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
    }

    return dp[m][n];
}


std::vector<std::vector<int>> res;

std::vector<std::vector<int>> pathSum(TreeNode *root, int target)
{
    std::vector<int> path;

    dfs(root, target, path);

    return res;
}

void dfs(TreeNode *root, int target, std::vector<int> &path)
{
    if(root == nullptr) return;

    path.push_back(root->val);

    if(target == root->val && root->left == nullptr && root->right == nullptr) {
        res.push_back(path);
    }

    dfs(root->left, target - root->val, path);
    dfs(root->right, target - root->val, path);

    path.pop_back();
}


int pathSum(TreeNode *root, int target)
{
    if(root == nullptr) return 0;

    return startWithRoot(root, target) + pathSum(root->left, target) + pathSum(root->right, target);
}

int startWithRoot(TreeNode *root, int target)
{
    if(root == nullptr) return 0;

    int count = root->val == target ? 1 : 0;

    count += startWithRoot(root->left, target - root->val);
    count += startWithRoot(root->right, target - root->val);

    return count;
}

// int getSum(int a, int b)
// {
//     int sum = a^b;
//     int carry = ((a&b) << 1);

//     while(carry)
//     {
//         a = sum;
//         b = carry;
//         sum = a^b;
//         carry = ((a&b) << 1);
//     }

//     return sum;
// }
*/

/*
int getSum(int a, int b) ;
std::string toHex(int num);

int main() {
    std::cout << toHex(-1) << std::endl;

    return 0;
}

int getSum(int a, int b) 
{
    return b ? getSum(a^b, (a&b)<<1) : a;
}

// int getSum(int a, int b) 
// {
//     while(b) {
//         int sum = a^b;
//         b = (a&b)<<1;
//         a = sum;
//     }

//     return a;
// }

std::string convertToBase7(int num)
{
    if(num == 0) return "0";

    bool minus = false;

    if(num < 0) {
        minus = true;
        num = -num;
    }

    std::string res;

    while(num) {
        res = std::to_string(num%7) + res;
        num = num/7;
    }

    return minus ? "-" + res : res;
}


std::string toHex(int num)
{
    if(num == 0) return "0";

    std::string str = "0123456789abcdef";

    std::string res;

    int count = 0;

    while(num && count++ < 8)
    {
        res = str[num & 0xf] + res;

        num >>= 4;
    }

    return res;
}

std::string convertToTitle(int n)
{
    std::string res;

    while(n) {
        res = (char)((n-1)%26 + 'A') + res;
        n = (n-1)/26;
    }

    return res;
}

int titleToNumber(std::string num)
{
    int res = 0;

    for(const char &c : num) {
        res = res*26 + (c - 'A' + 1);
    }

    return res;
}

int majorityElement(std::vector<int> &nums)
{
    int times = 1;
    int val = nums[0];

    for(int i = 1; i < nums.size(); i++) 
    {
        if(nums[i] == val) {
            times++;
        }
        else {
            times--;
        }

        if(times == 0) {
            val = nums[i];
            times = 1;
        }
    }

    return val;
}


std::vector<int> preorderTraversal(TreeNode *root)
{
    std::vector<int> res;

    if(root == nullptr) return res;

    std::stack<TreeNode*> sta;
    sta.push(root);

    while(!sta.empty())
    {
        TreeNode *pNode = sta.top();    sta.pop();
        res.push_back(pNode->val);

        if(pNode->right) {
            sta.push(pNode->right);
        }

        if(pNode->left) {
            sta.push(pNode->left);
        }
    } 

    return res;
}

std::vector<int> postorderTraversal(TreeNode *root)
{
    std::vector<int> res;

    if(root == nullptr) return res;

    std::stack<TreeNode*> sta;
    sta.push(root);

    while(!sta.empty())
    {
        TreeNode *pNode = sta.top();    sta.pop();
        res.push_back(pNode->val);

        if(pNode->left) {
            sta.push(pNode->left);
        }

        if(pNode->right) {
            sta.push(pNode->right);
        }
    }

    reverse(res.begin(), res.end());

    return res;
}

std::vector<int> inorderTraversal(TreeNode *root)
{
    std::vector<int> res;

    if(root == nullptr) return res;

    std::stack<TreeNode*> sta;
    TreeNode *pNode = root;

    while(!sta.empty() || pNode)
    {
        while(pNode) {
            sta.push(pNode);
            pNode = pNode->left;
        }

        pNode = sta.top();  sta.pop();
        res.push_back(pNode->val);

        pNode = pNode->right;
    }

    return res;
}

std::vector<int> direction = {-1, 0, 1, 0, -1};

int maxAreaOfLand(std::vector<std::vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    int res = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1)
                res = std::max(res, dfs(grid, i, j));
        }
    }

    return res;
}

int dfs(std::vector<std::vector<int>> &grid, int i, int j)
{
    int m = grid.size(), n = grid[0].size();

    int count = 1;

    grid[i][j] = 0;

    for(int k = 0; k < direction.size() - 1; k++) {
        int x = i + direction[k], y = j + direction[k+1];
        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
            count += dfs(grid, x, y);
        }
    }

    return count;
}


int dfs(std::vector<std::vector<int>> &grid, int i, int j)
{
    if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1)
    {
        grid[i][j] = 0;

        return 1 + dfs(grid, i, j+1) + dfs(grid, i, j-1) + dfs(grid, i-1, j) + dfs(grid, i+1, j);
    }

    return 0;
}


bool canFinsh(int n, std::vector<std::vector<int>> &prere)
{
    std::vector<std::vector<int>> graph(n); //临接矩阵
    std::vector<int> degree(n);     //记录各个节点的度

    std::queue<int> que;
    for(int i = 0; i < n; i++) {
        if(degree[i] == 0) dq.push(i);
    }

    int count = 0;
    while(!que.empty())
    {
        count++;
        int num = que.front();   que.pop();

        for(const int &n : graph[num]) {
            if(--degree[n] == 0) que.push(n);
        }
    }

    return count == n;
}
*/
/*
std::string reverseWords(std::string s);
void deleteFitstFromSecond(std::string &first, std::string &second);
void deleteDuplicates(std::string &s);



/*
std::string reverseWords(std::string s)
{
    std::stringstream in(s);
    std::string out;
    std::vector<std::string> strs;
    
    while(getline(in, out, ' ')) {
        if(out.empty()) continue;
        strs.push_back(out);
    }

    reverse(strs.begin(), strs.end());

    std::string res;
    for(int i = 0; i < strs.size(); i++) {
        res += strs[i] + " ";
    }

    res.pop_back();

    return res;
}

bool increasingTriplet(std::vector<int> &nums)
{
    std::vector<int> res;

    for(const int &n : nums) {
        if(res.empty() || n > res.back()) {
            res.push_back(n);
        } 
        else {
            auto it = lower_bound(res.begin(), res.end(), n);
            *it = n;
        }

        if(res.size() == 3) return true;
    }

    return false;
}

int findLengthOfLCIS(std::vector<int> &nums)
{
    int count = 1;

    int res = 1;

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] > nums[i-1]) count++;
        else count = 1;

        res = std::max(res, count);
    }

    return res;
}

int findLengthOfLCIS(std::vector<int> &nums)
{
    std::vector<int> dp(nums.size(), 1);

    int res = 1;

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] > nums[i-1]) dp[i] = dp[i-1] + 1;

        res = std::max(res, dp[i]);        
    }

    return res;
}
*/
/*
void deleteFitstFromSecond(std::string &first, std::string &second)
{
    if(first.empty() || second.empty()) return;

    std::vector<int> count(128, 0);

    for(const int &n : second) {
        count[n]++;
    }

    int cur = 0;
    for(const int &c : first) {
        if(count[c] == 0) first[cur++] = c;
    }

    first = first.substr(0, cur);
}

void deleteDuplicates(std::string &s)
{
    if(s.empty()) return;

    std::vector<int> count(128, 0);

    int cur = 0;
    for(const char &c : s) {
        if(count[c] == 0) s[cur++] = c;
        count[c] = 1;
    }

    s = s.substr(0, cur);
}

bool isAnagrams(std::string s, std::string p)
{
    if(s.size() != p.size()) return false;

    std::vector<int> count(26, 0);

    for(int i = 0; i < p.size(); i++)
    {
        count[s[i]-'a']++;
        count[p[i]-'a']--;
    }

    for(int i = 0; i < 26; i++) {
        if(count[i]) return false;
    }

    return true;
}

int firstUniqChar(std::string s)
{
    if(s.empty()) return -1;

    std::vector<int> count(26, 0);

    for(const char &c : s) {
        count[c-'a']++;
    }

    for(int i = 0; i < s.size(); i++) {
        if(count[s[i]-'a'] == 1) return i;
    }

    return -1;
}

class CharStatistics
{
private:
    int index;
    std::vector<int> count;

public:
    CharStatistics() : index(0) {
        count = std::vector<int>(256, -1);
    }

    void insert(char ch)
    {
        if(count[ch] == -1) {   //代表该字符没有出现过
            count[ch] = index;  //将其在count数组中的值置为下标
        }
        else if(count[ch] >= 0) {
            count[ch] = -2;     //已经出现过将其置为-2,以后不用再管了
        }
        
        index++;
    }

    char firstAppearingOnce()
    {
        int minIndex = index;

        char ch = '\0';

        for(int i = 0; i < 256; i++)
        {
            if(count[i] >= 0 && minIndex > count[i]) {
                minIndex = count[i];
                ch = (char)i;
            }
        }

        return ch;
    }

};

bool isInterleave(std::string s1, std::string s2, std::string s3);

int main() {
    std::string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";

    isInterleave(s1, s2, s3);

    return 0;
}

bool isInterleave(std::string s1, std::string s2, std::string s3)
{
    if(s1.size() + s2.size() != s3.size()) return false;

    int m = s1.size(), n = s2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 && j == 0) {
                dp[i][j] = 1;
            }
            else if(i == 0) {
                dp[i][j] = dp[i][j-1] && (s2[j-1] == s3[i+j-1]);
            }
            else if(j == 0) {
                dp[i][j] = dp[i-1][j] && (s1[i-1] == s3[i+j-1]);
            }
            else {
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
    }

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            std::cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }


    return dp[m][n];
}

//Leetcode第97题:判断交错字符串

//思路 : dp[i][j] 代表s1前i个字符和s2的前j个字符是否能交错组成字符串s3[0..i+j-1]
//注意 : i>=1, j>=1
// 如果 s1[i-1]==s3[i+j-1], 则dp[i][j] = dp[i-1][j]
// 如果 s2[j-1]==s3[i+j-1], 则dp[i][j] = dp[i][j-1]
//base case 为i=0, 或者j=0; i=0代表s1为空,j=0代表s2为空

bool isInterleave(std::string s1, std::string s2, std::string s3)
{
    if(s1.size() + s2.size() != s3.size()) return false;

    int m = s1.size(), n = s2.size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 && j == 0) {
                dp[i][j] = 1;
            }
            else if(i == 0) {
                dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1];
            }
            else if(j == 0) {
                dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1];
            }
            else {
                dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[i+j-1]) || ( dp[i-1][j] && s1[i-1] == s3[i+j-1]);
            }
        }
    }

    return dp[m][n];
}


std::unordered_map<std::string, int> hash;

bool wordBreak(std::string s, std::vector<std::string> &wordDict)
{
    std::unordered_set<std::string> mySet(wordDict.begin(), wordDict.end());

    return dfs(s, wordDict, mySet);
}

bool dfs(std::string s, std::vector<std::string> &wordDict, std::unordered_set<std::string> &mySet)
{
    if(hash.count(s)) return hash[s];

    if(s.empty()) return true;

    for(int i = 0; i < wordDict.size(); i++)
    {
        int len = wordDict[i].size();
        if(s.size() >= len && mySet.count(s.substr(0, len)) && dfs(s.substr(len), wordDict, mySet)) {
            hash[s] = 1;
            return true;
        }
    }

    hash[s] = 0;
    return false;
}





std::vector<int> direction = {-1, 0, 1, 0, -1};

bool exist(std::vector<std::vector<char>> &board, std::string word)
{
    if(board.empty()) return false;

    int m = board.size(), n = board[0].size();

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == word[0] && dfs(board, i, j, word, 0)) {
                return true;
            }
        }
    }

    return false;
}

bool dfs(std::vector<std::vector<char>> &board, int i, int j, std::string &word, int pos)
{
    int m = board.size(), n = board[0].size();

    if(pos == word.size() - 1) return true;

    char c = board[i][j];
    board[i][j] = '#';

    bool find = false;

    for(int k = 0; k < direction.size() - 1; k++) {
        int x = i + direction[k], y = j + direction[k+1];
        if(x >= 0 && x < m && y >= 0 && y < n && board[x][y] == word[pos+1]) {
            find = find || dfs(board, x, y, word, pos + 1);     //只要存在其中一条路径就行
        }
    }

    board[i][j] = c;

    return find;
}


bool exist(std::vector<std::vector<char>> &board, std::string word)
{
    if(board.empty()) return false;

    int m = board.size(), n = board[0].size();

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(find(board, i, j, word, 0)) return true;
        }
    }

    return false;
}

bool find(std::vector<std::vector<char>> &board, int i, int j, std::string &word, int pos)
{
    int m = board.size(), n = board[0].size();

    if(i >= 0 && i < m && j >= 0 && j < n && board[i][j] == word[pos])
    {
        if(pos == word.size() - 1) return true;

        board[i][j] = '#';

        bool res = find(board, i, j + 1, word, pos + 1) || find(board, i, j - 1, word, pos + 1)
                || find(board, i - 1, j, word, pos + 1) || find(board, i + 1, j, word, pos + 1);

        board[i][j] = word[pos];

        return res;
    }

    return false;
}


//根据前序和中序遍历重建二叉树

TreeNode* buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
{
    std::unordered_map<int,int> inorderPos;
    for(int i = 0; i < inorder.size(); i++) {
        inorderPos[inorder[i]] = i;
    }

    return buildTreeCore(preorder, 0, preorder.size() - 1, 0, inorderPos);
}

// 传入startInorder是为了计算左右子树的长度

TreeNode *buildTreeCore(std::vector<int> &preorder, int startProrder, int endPreorder, int startInorder, std::unordered_map<int,int> &inorderPos)
{
    if(startProrder > endPreorder) return nullptr;

    int rootIndex = inorderPos[preorder[startProrder]];

    TreeNode *root = new TreeNode(preorder[startProrder]);

    int leftLen = rootIndex - startInorder;

    root->left = buildTreeCore(preorder, startProrder + 1, startProrder + leftLen, startInorder, inorderPos);

    root->right = buildTreeCore(preorder, startProrder + leftLen + 1, endPreorder, rootIndex + 1, inorderPos);

    return root;
}

//根据后序和中序遍历重建二叉树

TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder)
{
    std::unordered_map<int,int> inorderPos;
    for(int i = 0; i < inorder.size(); i++) {
        inorderPos[inorder[i]] = i;
    }
    
    return buildTreeCore(postorder, 0, postorder.size() - 1, 0, inorderPos);
}

TreeNode* buildTreeCore(std::vector<int> &postorder, int startPostorder, int endPostorder, int startInorder, std::unordered_map<int,int> &inorderPos)
{
    if(startPostorder > endPostorder) return nullptr;

    int rootIndex = inorderPos[postorder[endPostorder]];

    int leftLen = rootIndex - startInorder;

    TreeNode *root = new TreeNode(postorder[endPostorder]);

    root->left = buildTreeCore(postorder, startPostorder, startPostorder + leftLen - 1, startInorder, inorderPos);

    root->right = buildTreeCore(postorder, startPostorder + leftLen, endPostorder - 1, rootIndex + 1, inorderPos);

    return root;
}




void initMap(std::vector<std::vector<int>> &map)
{
    map[0][1] = 2;  map[0][2] = 3;  map[0][3] = 6;
    map[1][0] = 2;  map[1][4] = 4;  map[1][5] = 6;
    map[2][0] = 3;  map[2][3] = 2;
    map[3][0] = 6;  map[3][2] = 2;  map[3][4] = 1;  map[3][5] = 3;
    map[4][1] = 4;  map[4][3] = 1;
    map[5][1] = 6;  map[5][3] = 3; 
}



struct Node {
    int x;
    int len;
    Node(int m_x, int m_len) {
        x = m_x;
        len = m_len;
    }
};

struct Cmp {
    bool operator()(const Node &o1, const Node &o2) {
        return o1.len > o2.len;
    }
};

void Dijkstra()
{
    std::vector<std::vector<int>> map(6, std::vector<int>(6, 0));
    initMap(map);

    std::vector<int> isVisited(6, 0);
    std::vector<int> distance(6, INT_MAX);

    std::priority_queue<Node, std::vector<Node>, Cmp> pq;
    distance[0] = 0;
    pq.push(Node(0, 0));
    
    while(!pq.empty())
    {
        Node tmp = pq.top();  pq.pop();
        int index = tmp.x;
        int len = tmp.len;
        isVisited[index] = 1;

        for(int i = 0; i < map[index].size(); i++)
        {
            if(map[index][i] > 0 && !isVisited[i]) {
                Node newNode = Node(i, len + map[index][i]);
                if(distance[i] > newNode.len) {
                    distance[i] = newNode.len;
                    pq.push(newNode);
                }
            }
        }
    }

    for(int i = 0; i < distance.size(); i++) {
        std::cout << distance[i] << " ";
    }
    std::cout << std::endl;

}




const int max = 6666;

void floyed()
{
    std::vector<std::vector<int>> distance = {
    {0, 2, 3, 6, max, max},
    {2, 0, max, max,4,6},
    {3, max,0,2, max,max},
    {6, max,2,0,1,3},
    {max,4,max,1,0,max},
    {max,6,max,3,max,0}};

    for(int k = 0; k < 6; k++) 
    {
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 6; j++) {
                distance[i][j] = std::min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            std::cout << distance[i][j] <<  " ";
        }
        std::cout << std::endl;
    }

}
TreeNode* invertTree(TreeNode *root)
{
    if(root == nullptr) return root;

    std::stack<TreeNode*> sta;
    sta.push(root);

    while(!sta.empty())
    {
        TreeNode *pNode = sta.top();  sta.pop();

        TreeNode *tmp = pNode->left;
        pNode->left = pNode->right;
        pNode->right = tmp;

        if(pNode->left) {
            sta.push(pNode->left);
        }

        if(pNode->right) {
            sta.push(pNode->right);
        }
    }

    return root;
}


int main() {
    floyed();

    return 0;
}


TreeNode* invertTree(TreeNode *root)
{
    if(root == nullptr) return nullptr;

    TreeNode *tmp = root->left; //->就相当于解引用操作
    root->left = root->right;
    root->right = tmp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}


std::vector<int> righttSideView(TreeNode *root)
{
    std::vector<int> res;

    if(root == nullptr) return res;

    dfs(root, res, 1);

    return res;
}

void dfs(TreeNode *root, std::vector<int> &res, int level)
{
    if(root == nullptr) return;

    if(res.size() < level) {
        res.push_back(root->val);
    }

    dfs(root->right, res, level + 1);
    dfs(root->left, res, level + 1);

}


std::vector<int> righttSideView(TreeNode *root)
{
    std::vector<int> res;

    if(root == nullptr) return res;

    std::queue<TreeNode*> que;
    que.push(root);

    while(!que.empty())
    {
        int n = que.size();
        
        for(int i = 0; i < n; i++) 
        {
            TreeNode *pNode = que.front();  que.pop();
            if(pNode->left) {
                que.push(pNode->left);
            } 
            if(pNode->right) {
                que.push(pNode->right);
            }

            if(i == n-1) res.push_back(pNode->val);
        }
    }

    return res;
}


int maxProfit(std::vector<int> &prices)
{
    int n = prices.size();

    std::vector<std::vector<int>> dp(n, std::vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];

    for(int i = 1; i < n; i++) 
    {
        dp[i][0] = std::max(dp[i-1][1] + prices[i] - fee, dp[i-1][0]);
        dp[i][1] = std::max(dp[i-1][0] - prices[i], dp[i-1][1]);
    }

    return dp[n-1][0];
}

int maxProfit(std::vector<int> &prices)
{
    int n = prices.size();
    if(n < 2) return 0;

    std::vector<std::vector<int>> dp(n, std::vector<int>(2, 0));
    dp[0][0] = 0, dp[0][1] = -prices[0];
    dp[1][0] = std::max(0, prices[1] - prices[0]);
    dp[1][1] = std::max(-prices[0], -prices[1]);

    for(int i = 2; i < n; i++)
    {
        dp[i][0] = std::max(dp[i-1][0], dp[i-1][1] + prices[i]);
        dp[i][1] = std::max(dp[i-1][1], dp[i-2][0] - prices[i]);
    }

    return dp[n-1][0];
}

*/


/*
int maxProfit(std::vector<int> &prices)
{
    int n = prices.size();

    std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>> (3, std::vector<int>(2, 0)));
    for(int k = 1; k <= 2; k++) {
        dp[0][k][1] = -price[k];
    }

    for(int i = 1; i < n; i++) 
    {
        for(int k = 1; k <= 2; k++) 
        {
            dp[i][k][0] = std::max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
            dp[i][k][1] = std::max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
        }
    }

    return dp[n-1][2][0];
}

int maxProfit(std::vector<int> &prices, int max_k)
{
    int n = prices.size();

    if(k >= n/2) {
        return maxProfitUnlimit(prices);
    }

    std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>> (max_k + 1, std::vector<int>(2, 0)));

    for(int k = 0; k <= max_k; k++) {
        if(k == 0) dp[0][k][1] = INT_MIN;
        else dp[0][k][1] = -prices[0];
    }

    for(int i = 1; i < n; i++)
    {
        for(int k = 1; k <= max_k; k++)
        {
            dp[i][k][0] = std::max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
            dp[i][k][1] = std::max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);        
        }
    }

    return dp[n-1][max_k][0];
}

int maxProfitUnlimit(std::vector<int> &nums)
{
    int sum = 0;

    for(int i = 1; i < nums.size(); i++) {
        sum += std::max(nums[i] - nums[i-1]);
    }

    return sum;
}



std::vector<std::string> next(const std::string &str);

int openLock(std::vector<std::string> &deadends, std::string target)
{
    std::unordered_set<std::string> deadSet(deadends.begin(), deadends.end());

    std::unordered_set<std::string> isVisited;

    std::string start = "0000";

    if(deadSet.count(start)) return -1;

    std::queue<std::string> que;
    
    que.push(start);
    isVisited.insert(start);

    int res = 0;

    while(!que.empty())
    {
        int size = que.size();

        for(int i = 0; i < size; i++)
        {
            std::string cur = que.front();  que.pop();

            if(cur == target) return res;

            std::vector<std::string> nextstrings = next(cur);

            for(auto str : nextstrings) 
            {
                if(deadSet.count(str)) continue;

                if(isVisited.count(str)) continue;

                if(str == target) return ++res;

                que.push(str);
                isVisited.insert(str);
            }
        }

        res++;
    }

    return -1;
}


std::vector<std::string> next(const std::string &str)
{
    std::vector<std::string> res;

    for(int i = 0; i < 4; i++)
    {
        std::string tmp = str;

        tmp[i] = (str[i] - '0' + 1)%10 + '0';
        res.push_back(tmp);

        tmp[i] = (str[i] - '0' - 1 + 10)%10 + '0';
        res.push_back(tmp);
    }

    return res;
}


int main() {
    std::vector<std::string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    std::string target = "0202";

    std::cout << openLock(deadends, target) << std::endl;

    return 0;
}


//改进:双向BFS

int openLock(std::vector<std::string> deadends, std::string target)
{
    std::unordered_set<std::string> deadSet(deadends.begin(), deadends.end());
    std::unordered_set<std::string> q1, q2, pass, visited;

    std::string start = "0000";

    if(deadSet.count(start) || deadSet.count(target)) return -1;
    if(start == target) return 0;       //下面这种初始情况没有判断,这里需要先判断这种初始情况

    visited.insert(start);
    q1.insert(start), q2.insert(target);

    int res = 0;

    while(!q1.empty() && !q2.empty())
    {
        if(q1.size() > q2.size()) std::swap(q1, q2);
        pass.clear();

        for(auto str : q1) 
        {
            std::vector<std::string> nextstrings = next(str);

            for(auto &s : nextstrings) {
                if(q2.count(s)) return ++res;
                if(visited.count(s)) continue;
                if(deadSet.count(s)) continue;

                pass.insert(s);
                visited.insert(s);
            }
        }

        std::swap(q1, pass);
        res++;
    }

    return -1;
}




class UF
{
private:
    int count;
    std::vector<int> parent, size;

public:
    UF(int n) {
        count = n;

        parent.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        //size表示每个节点的重量
        size = std::vector<int> (n, 1);
    }

    int findNode(int x) 
    {
        while(parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }

        return x;
    }

    void unionNode(int p, int q)
    {
        int rootP = findNode(p);
        int rootQ = findNode(q);

        if(size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }

        count--;
    }

    bool connected(int p, int q)
    {
        int rootP = findNode(p);
        int rootQ = findNode(q);

        return rootP == rootQ;
    }

    int countNum() {
        return count;
    }

};

int findCircleNum(std::vector<std::vector<int>> &isConnected)
{
    int n = isConnected.size();

    UF uf(n);

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(isConnected[i][j]) {
                uf.unionNode(i, j);
            }
        }
    }

    return uf.countNum();
}


int main() {
    // std::vector<std::vector<int>> nums = {{1,0,0}, {0,1,0}, {0,0,1}};

    // int n = nums.size();

    // UF uf(n);

    // for(int i = 0; i < n; i++) {
    //     for(int j = i + 1; j < n; j++) {
    //         if(nums[i][j]) uf.unionNode(i, j);
    //     }
    // }

    // std::cout << uf.countNum() << std::endl;


    double n = 1/3.0;

    std::cout << 1/n << std::endl;

    return 0;
}


struct Node {
    Node *parent;
    double value = 0.0;
    Node() : parent(nullptr) {}
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
        if(!map.count(query[0]) || !map.count(query[1]) || findParent(map[query[0]]) != findParent(map[query[1]])) 
            res.push_back(-1);
        else
            res.push_back(map[query[0]]->value / map[query[1]]->value);
    }

    return res;
}

int lengthOfLongestSubstring(std::string s)
{
    std::vector<int> count(128, -1);

    int start = -1;
    int res = 1;

    for(int i = 0; i < s.size(); i++)
    {
        if(count[s[i]] > start) {
            start = count[s[i]];
        }

        res = std::max(res, i - start);
        count[s[i]] = i;
    }

    return res;
}

std::string longestPalindrome(std::string s)
{
    int startIndex = 0, maxLen = 0;

    for(int i = 0; i < s.size(); i++)
    {
        int start, end;
        start = end = i;

        while(end + 1 < s.size()  && s[end+1] == s[i]) end++;

        while(start - 1 >= 0 && end + 1 < s.size() && s[start-1] == s[end+1]) {
            start--;
            end++;
        }

        int curLen = end - start + 1;

        if(maxLen < curLen) {
            startIndex = start;
            maxLen = curLen;
        }
    }

    return s.substr(startIndex, maxLen);
}


int maxArea(std::vector<int> &height)
{
    if(height.size() < 2) return 0;

    int res = 0;

    for(int i = 0, j = height.size() - 1; i < j;)
    {
        int wide = j - i;
        if(height[i] < height[j]) {
            res = std::max(res, wide*height[j]);
            i++;
        }
        else {
            res = std::max(res, wide*height[i]);
            j--;
        }
    }

    return res;
}

int maxArea(std::vector<int> &height)
{
    if(height.size() < 2) return 0;

    int left = 0, right = height.size() - 1;

    int res = 0;

    while(left < right)
    {
        int wide = right - left;
        int hei = height[left] < height[right] ? height[left++] : height[right--];
        res = std::max(res, hei*wide);
    }

    return res;
}

bool isUgly(int n)
{
    if(n <= 0) return false;

    while(n%2 == 0) {
        n /= 2;
    }
    while(n%3 == 0) {
        n /= 3;
    }
    while(n%5 == 0) {
        n /= 5;
    }

    return n == 1 ? true : false;
}



int nthUglyNumber(int n);

int main() {
    nthUglyNumber(10);

    return 0;
}

int nthUglyNumber(int n)
{
    std::vector<int> res(1, 1);
    res[0] = 1;

    int i, j, k;
    i = j = k = 0;

    while(res.size() < n)
    {
        int num = std::min(std::min(res[i]*2, res[j]*3), res[k]*5);
        res.push_back(num);

        if(res.back() == res[i]*2) i++;
        else if(res.back() == res[j]*3) j++;
        else if(res.back() == res[k]*5) k++;

    }

    return res.back();
}

int nthSuperUglyNumber(int n, std::vector<int> &primes)
{
    std::vector<int> res(1, 1);

    std::vector<int> count(primes.size(), 0);

    while(res.size() < n)
    {
        int num = INT_MAX;
        for(int i = 0; i < primes.size(); i++) {
            num = std::min(num, primes[count[i]]*primes[i]);
        }

        res.push_back(num);

        for(int i = 0; i < primes.size(); i++) {
            if(res.back() == primes[i]*count[i]) {
                count[i]++;
            }
        }
    }

    return res.back();
}


int nthUglyNumber(int n)
{
    std::vector<int> res(n);
    res[0] = 1;

    int i, j, k;
    i = j = k = 0;

    for(int u = 1; u < n; u++)
    {
        int num = (std::min(res[i]*2), std::min(res[j]*3, res[k]*5));

        res[u] = num;

        if(res[u] == res[i]*2) i++;
        if(res[u] == res[j]*3) j++;
        if(res[u] == res[k]*5) k++;
    }

    return res[n-1];
}


struct Node {
    Node *parent;
    double value = 0.0;
    Node() : parent(this) {}
};

Node* findParent(Node *node)
{
    if(node->parent == node) return node;

    node->parent = findParent(node->parent);

    return node->parent;
}


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
            map[s2]->value = map[s1]->value / values[i];
            map[s2]->parent = map[s1];
        }
        else {
            unionNode(map[s1], map[s2], values[i], map);
        }
    }

    for(auto query : queries)
    {
        //如果查询的字符不存在或者查询的字符之间没有换算关系  比如a/b, c/d, 现在要查询a/d,这就无法得到,所以要求查询的前后两个字符要有交集,就是判断其是否存在公共父亲
        if(!map.count(query[0]) || !map.count(query[1]) || findParent(map[query[0]]) != findParent(map[query[1]])) 
            res.push_back(-1.0);
        else
            res.push_back(map[query[0]]->value / map[query[1]]->value);
    }

    return res;
}


const int n = 100;
int num[n];

int main() {
    std::vector<std::vector<std::string>> equations = {{"a", "b"}, {"b", "c"}};
    std::vector<double> values = {2.0, 3.0};
    std::vector<std::vector<std::string>> queries = {{"a","c"}, {"b","a"}, {"a","e"}};

    std::vector<double> res = calcEquation(equations, values, queries);

    for(const auto &n : res) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}


class MyQueue
{
    std::stack<int> in, out;

    void int2out() {
        if(out.empty()) {
            while(!in.empty()) 
            {
                int n = in.top();   in.pop();
                out.push(n);
            }
        }
    }

public:
    MyQueue() {

    }

    void push(int x) {
        in.push(x);
    }

    int pop() {
        in2out();
        int n = out.top();  out.pop();
        return n;
    }

    int peek() {
        in2out();
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }

};


const int N = (int)pow(10,9) + 7;

int maxPerformance(int n, std::vector<int> &speed, std::vector<int> &efficiency, int k)
{
    std::vector<std::pair<int,int>> team;

    for(int i = 0; i < n; i++) {
        team.push_back({efficiency[i], speed[i]});
    }

    sort(team.begin(), team.end(), [](std::pair<int,int> &do1, std::pair<int,int> &do2) {
        return do1.first > do2.first || do1.second > do2.second;
    });

    std::priority_queue<int> pq;

    long res = 0, sum = 0;

    for(const auto &item : team)
    {
        pq.push(item.second);

        sum += item.second;

        int eff = item.first, sum += item.second;

        if(pq.size() > k) {
            sum -= pq.top();
            pq.pop();
        }

        res = std::max(res, sum*eff);
    }

    return res % N;
}



int main() {
    std::vector<int> speed = {2,10,3,1,5,8}, efficiency = {5,4,3,9,7,2};

    std::vector<std::pair<int,int>> team;

    for(int i = 0; i < speed.size(); i++) {
        team.push_back({efficiency[i], speed[i]});
    }

    // sort(team.rbegin(), team.rend());
    // sort(team.begin(), team.end(), [](std::pair<int,int> &do1, std::pair<int,int> &do2) {
    //     return do1.first > do2.first || (do1.first == do2.first && do1.second > do2.second);
    // });

    for(int i = 0; i < 6; i++) {
        std::cout << team[i].first <<  " ";
    }
    std::cout << std::endl;

    for(int i = 0; i < 6; i++) {
        std::cout << team[i].second <<  " ";
    }
    std::cout << std::endl;

    return 0;
}

int calculateMinimumHP(std::vector<std::vector<int>> &dungeon)
{
    int m = dungeon.size(), n = dungeon[0].size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    dp[m-1][n] = dp[m][n-1] = 1;

    for(int i = m-1; i >= 0; i--) {
        for(int j = n-1; j >= 0; j--) {
            int right = std::max(dp[i][j+1] - dungeon[i][j], 1);
            int down = std::max(dp[i+1][j] - dungeon[i][j], 1);
            dp[i][j] = std::min(right, down);
        }
    }

    return dp[m-1][n-1];
}


int uniquePaths(int m, int n)
{
    int res = 1;

    for(int i = 1; i <= m-1; i++) {
        res = res * (m + n - 2 - i + 1) / i;
    }

    return res;
}

int uniquePaths(int m, int n)
{
    std::vector<int> dp(n, 1);

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            dp[j] = dp[j] + dp[j-1];
        }
    }

    return dp[n-1];
}

// dp[i][j] = dp[i-1][j] + dp[i][j-1], if nums[i][j] != 0
//          = 0, if nums[i][j] = 0

// base case : i = 0, j = 0

int uniquePaths(std::vector<std::vector<int>> &nums)
{
    int m = nums.size(), n = nums[0].size();
    if(m == 0 || n == 0) return 0;

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    if(nums[0][0] == 1) return 0;
    dp[0][0] = 1;

    for(int j = 1; j < n; j++) {
        if(nums[0][j] == 0) dp[0][j] = dp[0][j-1];
        else dp[0][j] = 0;
    }

    for(int i = 1; i < m; i++) {
        if(nums[i][0] == 0) dp[i][0] = dp[i-1][0];
        else dp[i][0] = 0;
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(nums[i][j] == 0) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            else dp[i][j] = 0;
        }
    }

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));
    dp[0][0] = 1;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(nums[i][j] == 1) dp[i][j] = 0;
            else if(i > 0 && j > 0) dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n-1];


    return dp[m-1][n-1];


    std::vector<int> dp(n, 0);
    if(nums[0][0] = 1) return 0;
    dp[0] = 1;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(nums[i][j] == 0) {
                dp[j] += dp[j-1];
            }
            else dp[j] = 0;
        }
    }
    
    return dp[n-1];
}


int uniquePaths(std::vector<std::vector<int>> &nums)
{
    int m = nums.size(), n = nums[0].size();

    if(m == 0 || n == 0) return 0;

    std::vector<int> dp(n, 0);
    dp[0] = 1;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(nums[i][j] == 1) dp[j] = 0;
            else if(j > 0) {
                dp[j] += dp[j-1];
            }
        }
    }

    return dp[n-1];
}


// dp[i][j] = dp[i-1][j] + dp[i-1][j], if nums[i][j] == 0
// dp[i][j] = 0, if nums[i][j] == 1
// base case : i = 0, j = 0

int uniquePaths(std::vector<std::vector<int>> &nums)
{
    int m = nums.size(), n = nums[0].size();
    if(m == 0 || nums[0][0] == 1) return 0;

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(nums[i][j] == 1) dp[i][j] = 0;
            else if(i == 0 && j == 0) dp[i][j] = 1;
            else if(i == 0 && j > 0) dp[i][j] = dp[i][j-1];
            else if(j == 0 && i > 0) dp[i][j] = dp[i-1][j];
            else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    return dp[m-1][n-1];
}


//方法一:时间复杂度为O(nlogn)
int longestConsecutive(std::vector<int> &nums)
{
    //这个插入红黑树的过程的时间复杂度为O(nlogn)
    std::set<int> mySet(nums.begin(), nums.end());

    int res = 0;

    for(const auto &x : mySet)
    {
        if(!mySet.count(x-1)) {
            int y = x + 1;
            while(mySet.count(y)) y++;
            res = std::max(res, y - x);
        }
    }

    return res;
}

//方法二:时间复杂度为O(n)
int longestConsecutive(std::vector<int> &nums)
{
    std::unordered_set<int> mySet(nums.begin(), nums.end());

    int res = 0;

    for(const int &n : mySet)
    {
        int x = n-1, y = n + 1;

        while(mySet.count(x)) mySet.erase(x--);
        while(mySet.count(y)) mySet.erase(y++);

        res = std::max(res, y - x - 1);
    }

    return res;
}

int findNumbersOFLIS(std::vector<int> &nums)
{
    int n = nums.size();
    std::vector<int> len(n, 1), count(n, 1);

    int maxLen = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i])
            {
                if(len[j] + 1 > len[i]) {
                    len[i] = len[j] + 1;
                    count[i] = count[j];
                }
                else if(len[j] + 1 == len[i]) {
                    count[i] += count[j];
                }
            }
        }
        maxLen = std::max(maxLen, len[i]);
    }

    int res = 0;
    for(int i = 0; i < n; i++) {
        if(len[i] == maxLen) res += count[i];
    }

    return res;
}



struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int m_val) : val(m_val), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode *p, TreeNode *q);

int main() {
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);  p->right = new TreeNode(3);

    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(2);  q->right = new TreeNode(3);

    std::cout << isSameTree(p, q) << std::endl;

    return 0;
}

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if(p == nullptr || q == nullptr) return p == q;

    if(p->val != q->val) return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

std::vector<int> res;

std::vector<int> preorder(Node *root)
{
    dfs(root);

    return res;
}

void dfs(Node *root)
{
    if(root == nullptr) return ;

    res.push_back(root->val);

    for(Node* node : root->children) {
        dfs(node);
    }
}

std::vector<std::vector<int>> levelOrder(Node *root)
{
    std::vector<std::vector<int>> res;

    if(root == nullptr) return res;

    std::queue<Node*> que;
    que.push(root);

    while(!que.empty())
    {
        int n = que.size();
        std::vector<int> tmp;
        for(int i = 0; i < n; i++) 
        {
            Node *pNode = que.front();    que.pop();
            tmp.push_back(pNode->val);

            for(Node *newNode : pNode->children) {
                que.push(newNode);
            }
        }

        res.push_back(tmp);
    }

    return res;
}

bool isPalindrome(int x)
{
    if(x < 0) return false;
    if(x == 0) return true;
    if(x%10 == 0) return false;

    int num = 0;
    int tmp = x;
    while(x) {
        if(num > INT_MAX/10 || (num == INT_MAX/10 && x%10 > 7)) return false;
        num = num*10 + x%10;
        x = x/10;
    }

    return num == tmp;
}


int intToRoman(std::string num)
{
    std::unordered_map<char, int> hash = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};

    int res = 0;
    for(int i = 0; i < num.size(); i++) {
        if(i+1 < num.size() && hash[num[i]] < hash[num[i+1]]) {
            res += hash[num[i+1]] - hash[num[i]];
            i++;
        }
        else res += hash[num[i]];
    }

    return res;
}


std::string intToRoman(int num)
{
    std::vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::vector<std::string> num = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    std::string res;
    for(int i = 0; i < values.size(); i++)
    {
        while(num >= values[i]) {
            res += num[i];
            num -= values[i];
        }
    }

    return res;
}


std::string longestCommonSubstring(std::vector<std::string> &strs)
{
    if(strs.empty()) return "";

    for(int i = 0; i < strs[0].size(); i++) {
        for(int j = 1; j < strs.size(); j++) {
            if(i >= strs[j].size() || strs[0][i] != strs[j][i]) {
                return strs[0].substr(0, i);
            }
        }
    }

    return strs[0];
}


int trap(std::vector<int> &height)
{
    if(height.empty()) return 0;

    std::stack<int> index;
    int res = 0;

    for(int i = 0; i < height.size(); i++)
    {
        while(!index.empty() && height[i] >= height[index.top()]) {
            int hei = height[index.top()];  index.pop();
            if(!index.empty()) {
                int minHeiDiff= std::min(height[i], height[index.top()]) - hei;
                res = std::max(res, hei * (i - index.top() - 1));
            }
        }

        index.push(i);
    }

    return res;
}


std::vector<int> dailyTemperatures(std::vector<int> &T)
{
    std::vector<int> res(T.size(), 0);
    
    std::stack<int> sta;

    for(int i = 0; i < T.size(); i++)
    {
        while(!sta.empty() && T[i] > T[sta.top()]) {
            res[sta.top()] = i - sta.top();
            sta.pop();
        }

        sta.push(i);
    }

    return res;
}


std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2)
{
    std::stack<int> sta;
    std::unordered_map<int,int> hash;

    for(int i = 0; i < nums2.size(); i++) 
    {
        while(!sta.empty() && nums2[i] > sta.top()) {
            hash[sta.top()] = nums2[i];
            sta.pop();
        }

        sta.push(nums2[i]);
    }

    std::vector<int> res;
    for(int i = 0; i < nums1.size(); i++) {
        if(hash.count(nums1[i])) res.push_back(hash[nums1[i]]);
    }

    return res;
}

std::vector<int> nextGreaterElement(std::vector<int> &nums)
{
    if(nums.empty()) return {};

    std::stack<int> index;

    int n = nums.size();

    std::vector<int> res(n, -1);

    for(int i = 0; i < n*2; i++)
    {
        while(!index.empty() && nums[i%n] > nums[index.top()]) {
            res[index.top()] = nums[i%n];
            index.pop();
        }

        index.push(i%n);
    }

    return res;
}

int nextGreaterElement(int n)
{
    std::string str = std::to_string(n);

    if(str.size() <= 1) return -1;

    int i = str.size() - 2;
    while(i >= 0 && str[i] >= str[i+1]) {
        i--;
    }

    if(i == -1) return -1;

    int j = str.size() - 1;
    while(j > i && str[j] <= str[i]) {
        j--;
    }

    std::swap(str[i], str[j]);

    reverse(str.begin() + i + 1, str.end());

    return std::stoi(str);
}


void nextPermutation(std::vector<int> &nums)
{
    if(nums.size() <= 1) return;

    int i = nums.size() - 2;
    while(i >= 0 && nums[i] >= nums[i+1]) {
        i--;
    }

    if(i == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    int j = nums.size() - 1;
    while(j > i && nums[j] <= nums[i]) {
        j--;
    }

    std::swap(nums[i], nums[j]);

    reverse(nums.begin() + i + 1, nums.end());
}

bool isMatch(std::string s, std::string p)
{
    int m = s.size(), n = p.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    dp[0][0] = 1;
    for(int j = 1; j <= n; j++) {
        if(p[j-1] == '*') dp[0][j] = dp[0][j-2];
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(p[j-1] == '.' || s[i-1] == p[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] == '*')
            {
                if(s[i-1] != p[j-2] && p[j-2] != '.') {
                    dp[i][j] = dp[i][j-2];
                } 
                else {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i][j-2];
                }
            }
        }
    }

    return dp[m][n];
}

// dp[i] = std::min(dp[i-1] + nums[i-1], dp[i-2] + nums[i-2])

// dp[0] = 0, dp[1] = 0


int minCostClimibingStaris(std::vector<int> &cost)
{
    int n = cost.size();
    std::vector<int> dp(n + 1, 0);

    for(int i = 2; i <= n; i++) {
        dp[i] = std::min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
    }

    return dp[n];
}

int minCostClimibingStaris(std::vector<int> &cost)
{
    int n = cost.size();

    int first = 0, second = 0;
    int cur = 0;
    for(int i = 2; i <= n; i++) {
        cur = std::min(first + nums[i-2], second + nums[i-2]);
        first = second;
        cur = second;
    }

    return cur;
}

// dp[i] = dp[i-1], if i 不在计划里
// dp[i] = {dp[i-1] + cost[0], dp[i-7] + cost[1], dp[i-30] + cost[2]}

int mincostTickets(std::vector<int> &days, std::vector<int> &costs)
{
    std::unordered_set<int> mySet(days.begin(), days.end());

    std::vector<int> dp(366, 0);

    for(int i = 1; i <= 365; i++)
    {
        if(!mySet.count(i)) dp[i] = dp[i-1];
        else {
            dp[i] = std::min(std::min(dp[i-1] + cost[0], dp[std::max(i-7, 0)] + cost[1]), dp[std::max(i-30, 0)] + cost[2]);
        }
    }

    return dp[365];
}

// dp[i] = min{dp[i- coin{0...n}] + 1}

int coinChange(std::vector<int> &coins, int amount)
{
    int n = coins.size();

    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for(int i = 1; i <= amount; i++) {
        for(const int &coin : coins) {
            if(i >= coin) dp[i] = std::min(dp[[i]] ,dp[i-coin] + 1);
        }
    }

    return dp[amount] == amount + 1 ? -1 : dp[amount];
}

std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    std::vector<std::vector<int>> res;
    if(nums.size() < 3) return res;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size() - 2; i++)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        
        int target = -nums[i];
        
        int left = i + 1, right = nums.size() - 1;

        std::vector<int> tmp;
        while(left < right)
        {
            if(nums[left] + nums[right] == target) {
                tmp.push_back({i, left, right});
                while(left + 1 < nums.size() && nums[left] == nums[left+1]) left++;
                while(right - 1 >= 0 && nums[right] == nums[right-1]) right--;
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

int threeSumCloset(std::vector<int> &nums, int target)
{
    int res = INT_MAX;
    int diff = INT_MAX;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue;

        int left = i + 1, right = nums.size() - 1;

        while(left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if(abs(sum - target) < diff) {
                diff = abs(sum - target);
                res = sum;
                if(diff == 0) return res;
            }

            if(sum < target) {
                left++;
            }
            else if(sum > target) {
                right--;
            }
        }
    }

    return res;
}


std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    std::vector<std::vector<int>> res;
    if(nums.size() < 3) return res;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size() - 2; i++)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue;
                
        int left = i + 1, right = nums.size() - 1;

        while(left < right)
        {
            int curSum = nums[i] + nums[left] + nums[right];

            if(curSum == 0) {
                res.push_back({nums[i], nums[left], nums[right]});
                while(left + 1 < nums.size() && nums[left] == nums[left+1]) left++;
                while(right - 1 >= 0 && nums[right] == nums[right-1]) right--;
                left++;
                right--;
            }
            else if(curSum < 0) {
                left++;
            }
            else if(curSum > 0) {
                right--;
            }
        }
    }

    return res;
}

std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
{
    std::vector<std::vector<int>> res;
    if(nums.size() < 4) return res;

    int n = nums.size();
    sort(nums.begin(), nums.end());

    for(int i = 0; i < n-3; i++)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue;

        int min4Sum = nums[i] + nums[i+1] + nums[i+2] + nums[i+3];
        int max4Sum = nums[i] + nums[n-1] + nums[n-2] + nums[n-3];

        if(min4Sum > target) break;     //后面元素都是递增的,当前元素的最小和都大于target, 则后面的元素和肯定也都大于taregt
        if(max4Sum < target) continue;  //    

        for(int j = i+1; j < n - 2; j++) 
        {
            if(j > i+1 && nums[j] == nums[j-1]) continue;
            int min4Sum = nums[i] + nums[j] + nums[j+1] + nums[j+2];
            if(min4Sum > target) break;

            int max4Sum = nums[i] + nums[j] + nums[n-1] + nums[n-2];
            if(max4Sum < target) continue;
            int left = j + 1, right = n - 1;
            while(left < right)
            {
                int curSum = nums[i] + nums[j] + nums[left] + nums[right];

                if(curSum == target) {
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while(left + 1 < n && nums[left] == nums[left + 1]) left++;
                    while(right - 1 >= 0 && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
                else if(curSum < target) {
                    left++;
                }
                else if(curSum > target) {
                    right--;
                }
            } 
        }
    }

    return res;
}

std::unordered_set<int> mySet;

bool findTarget(TreeNode *root, int k)
{
    if(root == nullptr) return false;

    if(mySet.count(k - root->val)) return true;

    mySet.insert(root->val);

    return dfs(root->left, k) || dfs(root->right, k);
}


bool findTarget(TreeNode *root, int k)
{
    return dfs(root, root, k);
}

bool dfs(TreeNode *root, TreeNode *cur, int k)
{
    if(cur == nullptr) return false;

    return search(root, cur, k - cur->val) || dfs(root, cur->left, k) || dfs(root, cur->right, k);
}

bool search(TreeNode *root, TreeNode *cur, int value)
{
    if(root == nullptr) return false;

    return (root->val == value) && (root != cur)
          || (root->val < value && search(root->right, cur, value))
          || (root->val > value && search(root->left, cur, value));

}


std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    for(int i = 0; i < nums.size() - 1; i++)
    {
        int left = i + 1, right = nums.size() - 1;

        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);

            int sum = nums[i] + nums[mid];

            if(sum == target) {
                return {i + 1, mid + 1};
            }
            else if(sum < target) {
                left = mid + 1;
            }
            else if(sum > target) {
                right = mid - 1;
            }
        }
    }

    return {};
}

TreeNode* buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
{
    std::unordered_map<int, int> inorderPos;

    for(int i = 0; i < inorder.size(); i++) {
        inorderPos[inorder[i]] = i;
    }

    return dfs(preorder, 0, preorder.size() - 1, 0, inorderPos);
}

TreeNode *dfs(std::vector<int> &preorder, int startProrder, int endPreorder, int startInorder, std::unordered_map<int,int> &inorderPos)
{
    if(startProrder > endPreorder) return nullptr;

    TreeNode *root = new TreeNode(preorder[startProrder]);

    int rootIndex = inorderPos[preorder[startProrder]];

    int leftLen = rootIndex - startInorder;

    root->left = dfs(preorder, startProrder + 1, startProrder + leftLen, startInorder, inorderPos);

    root->right = dfs(preorder, startProrder + leftLen + 1, endPreorder, rootIndex + 1, inorderPos);

    return root;
}

TreeNode* buildTree(std::vector<int> &inorder, std::vector<int> &postorder)
{
    std::unordered_map<int,int> inorderPos;

    for(int i = 0; i < inorder.size(); i++) {
        inorderPos[inorder[i]] = i;
    }

    return dfs(postorder, 0, postorder.size() - 1, 0, inorderPos);
}

TreeNode* dfs(std::vector<int> &postorder, int startPostorder, int endPostorder, int startInorder, std::unordered_map<int,int> &inorderPos)
{
    if(startPostorder > endPostorder) return nullptr;

    TreeNode *root = new TreeNode(postorder[endPostorder]);

    int rootIndex = inorderPos[postorder[endPostorder]];

    int leftLen = rootIndex - startInorder;

    root->left = dfs(postorder, startPostorder, startPostorder + leftLen - 1, startInorder, inorderPos);

    root->right = dfs(postorder, startPostorder + leftLen, endPostorder - 1, rootIndex + 1, inorderPos);

    return root;
}// dp[i][j] 表示 s[i..j]是否为回文串
// dp[i][j] = dp[i+1][j-1] && s[i]==s[j]
// base case : i = j, dp[i][j] = 1;
//             j = i + 1, dp[i][j] = (s[i] == s[j]);

int countSubstrings(std::string s)
{
    int n = s.size();

    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    int res = 0;

    for(int i = n-1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            if(i == j) dp[i][j] = 1;
            else if(j == i+1) dp[i][j] = (s[i] == s[j]);
            else {
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
            }

            dp[i][j] = (s[i] == s[j]) && (j-i < 2 || dp[i+1][j-1]);

            if(dp[i][j]) res++;
        }
    }

    return res;
}




int countSubstrings(std::string s);
int extendSubstrings(std::string s, int i, int j);

int main() {
    // std::string s = "bbbb";
    // std::cout << countSubstrings(s) << std::endl;

    std::vector<int> nums;

    nums.push_back(1);
    std::cout << nums.capacity() << std::endl;

    nums.push_back(1);
    std::cout << nums.capacity() << std::endl;

    nums.push_back(1);
    std::cout << nums.capacity() << std::endl;
    
    nums.push_back(1);
    std::cout << nums.capacity() << std::endl;

    nums.push_back(1);
    std::cout << nums.capacity() << std::endl;

    return 0;
}

int countSubstrings(std::string s)
{
    int count = 0;
    for(int i = 0; i < s.size(); i++)
    {
        count += extendSubstrings(s, i, i + 1);
    }

    return count;
}

int extendSubstrings(std::string s, int i, int j)
{
    int n = s.size();

    int count = 0;
    while(i >= 0 && j < s.size() && s[i] == s[j])
    {
        i--;
        j++;
        count++;

        if((i >= 0 && s[i] == s[i+1]) || (j < n && s[j-1] == s[j])) break;
    }

    return count;
}

int longestValidParentheses(std::string s)
{
    std::vector<int> res;
    res.push_back(-1);

    int maxLen = 0

    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        if(c == '(') {
            res.push_back(i);
        }
        else if(c == ')') {
            res.pop_back();
            if(res.empty()) res.push_back(i);

            maxLen = std::max(maxLen, i - res.back());
        }
    }

    return maxLen;
}


std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
{
    std::deque<int> dq;
    std::vector<int> res;

    for(int i = 0; i < nums.size(); i++)
    {
        if(!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        while(!dq.empty() && nums[i] > nums[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if(i >= k-1) res.push_back(nums[dq.front()]);
    }

    return res;
}


bool canJump(std::vector<int> &nums)
{
    int maxPos = 0;

    for(int i = 0; i < nums.size() - 1; i++)
    {
        if(maxPos <= i && nums[i] == 0) return false;
        maxPos = std::max(maxPos, i + nums[i]);
    }

    return true;
}

int jump(std::vector<int> &nums)
{
    int end = 0, maxPos = 0;
    int steps = 0;

    for(int i = 0; i < nums.size() - 1; i++)
    {
        maxPos = std::max(maxPos, i + nums[i]);

        if(i == end) {
            end = maxPos;
            steps++;
        }
    }

    return steps;
}

std::set<int> visited;

bool canReach(std::vector<int> &arr, int start)
{
    if(start < 0 || start >= arr.size() || visited.count(start)) return false;

    visited.insert(start);

    if(arr[start] == 0) return true;

    return canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
}


bool canReach(std::vector<int> &arr, int start)
{
    if(start >= 0 && start < arr.size() && !visited.count(start))
    {
        if(arr[start] == 0) return true;

        visited.insert(start);

        return canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
    }

    return false;
}

bool canReach(std::vector<int> &arr, int start)
{
    if(start >= 0 && start < arr.size() && visited.insert(start).second) {
        return arr[start] == 0 || canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
    }

    return false;
}


int minJumps(std::vector<int> &arr)
{
    int n = arr.size();

    std::unordered_map<int, std::vector<int>> indicesOfValue;
    std::vector<int> visited(n, 0);

    for(int i = 0; i < arr.size(); i++) {
        indicesOfValue[arr[i]].push_back(i);
    }

    std::queue<int> que;
    que.push_back(0);
    visited[0] = 1;

    int steps = 0;

    while(!que.empty())
    {
        int size = que.size();

        for(int i = 0; i < size; i++)
        {
            int index = que.front(); que.pop();
            if(index == n - 1) return steps;

            std::vector<int> &next = indicesOfValue[arr[index]];
            next.push_back(i - 1);  next.push_back(i + 1);

            for(const int &j : next) {
                if(j >= 0 && j < n && !visited[j]) {
                    que.push(j);
                    visited[j] = 1;
                }
            }

            next.clear();
        }

        steps++;
    }

    return 0;
}


int minJumps(std::vector<int> &arr)
{
    int n = arr.size();

    std::unordered_map<int, std::vector<int>> indicesOfValue;
    for(int i = 0; i < n; i++) {
        indicesOfValue[arr[i]].push_back(i);
    }

    std::vector<int> visited(n, 0);
    std::queue<int> que;

    que.push(0);
    visited[0] = 1;

    int steps = 0;

    while(!que.empty())
    {
        for(int size = que.size(); size > 0; size--) 
        {
            int i = que.front();    que.pop();
            if(i == n - 1) return steps;

            std::vector<int> &next = indicesOfValue[arr[i]];
            next.push_back(i - 1);  next.push_back(i + 1);

            for(int &j : next) {
                if(j >= 0 && j < n && !visited[j]) {
                    que.push(j);
                    visited[j] = 1;
                }
            }

            next.clear();
        }

        steps++;
    }

    return steps;
}


//Leetcode第1340题 : Jump Game V
//思路:回溯

int dp[10001];

int maxJumps(std::vector<int> arr, int d)
{
    memset(dp, sizeof(dp), 0);

    int res = 1;

    for(int i = 0; i < arr.size(); i++) {
        res = std::max(res, dfs(arr, i, d));
    }

    return res;
}

int dfs(std::vector<int> &arr, int i, int d)
{
    int res = 1;

    if(dp[i]) return dp[i];

    //往右边搜索
    for(int j = i + 1; j <= std::min(i + d, (int)arr.size() - 1) && arr[j] < arr[i]; j++) {
        res = std::max(res, 1 + dfs(arr, j, d));
    }

    //往左边搜索
    for(int j = i - 1; j >= std::max(0, i - d) && arr[j] < arr[i]; j--) {
        res = std::max(res, 1 + dfs(arr, j, d));
    }

    dp[i] = res;

    return res;
}

std::vector<int> direction = {-1, 0, 1, 0, -1};

int numIslands(std::vector<std::vector<char>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    int island = 0;

    for(int i = 0; i < m; i++) 
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == '1')
            {
                island++;
                grid[i][j] = '0';

                std::queue<std::pair<int,int>> que;
                que.push({i,j});

                while(!que.empty())
                {
                    std::pair<int,int> p = que.front();  que.pop();

                    for(int i = 0; i < direction.size() - 1; i++) {
                        int r = p.first + direction[i], c = p.second + direction[i+1];
                        if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                            grid[r][c] = '0';
                            que.push({r, c});
                        }
                    }
                }
            }
        }
    }

    return island;
}


ListNode* removeNthFromEnd(ListNode *head, int n)
{
    ListNode *base = new ListNode(-1);
    base->next = head;

    ListNode *fast = base, *slow = base;

    for(int i = 0; i < n; i++) {
        fast = fast->next;
    }

    while(fast && fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return base->next;
}

ListNode* removeNthFromEnd(ListNode *head, int n)
{
    ListNode *fast = head, *slow = head;

    for(int i = 0; i < n; i++) {
        fast = fast->next;
    }

    if(fast == nullptr) return head->next;

    while(fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;

    return head;
}

ListNode* deleteDuplicate(ListNode *head)
{
    ListNode *cur = head;

    while(cur && cur->next)
    {
        if(cur->val == cur->next->val) {
            cur->next = cur->next->next;
        }
        else {
            cur = cur->next;
        }
    }

    return head;
}

ListNode* deleteDuplicate(ListNode *head)
{
    ListNode *base = new ListNode(-1);

    ListNode *cur = base;

    while(cur->next && cur->next->next)
    {
        int value = cur->next->val;
        if(cur->next->next->val == value) {
            ListNode *pNext = cur->next;
            while(pNext && pNext->val == value) {
                pNext = pNext->next;
            }
            cur->next = pNext;
        }
        else {
            cur = cur->next;
        }
    }

    return base->next;
}

ListNode* mergeKLists(std::vector<ListNode*> &lists)
{
    int len = lists.size();

    while(len > 1)
    {
        for(int i = 0; i < len/2; i++) {
            lists[i] = mergeTwoLists(lists[i], lists[len-1-i]);
        }

        len = ((len + 1) >> 1);
    }

    return lists.front();
}

ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if(l1 == nullptr) return l2;
    else if(l2 == nullptr) return l1;

    if(l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }

}


ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *head = new ListNode(-1);
    ListNode *base = head;

    while(l1 && l2)
    {
        if(l1->val < l2->val) {
            base->next = l1;
            l1 = l1->next;
        }
        else{
            base->next = l2;
            l2 = l2->next;
        }

        base = base->next;
    }

    if(l1) base->next = l1;
    else if(l2) base->next = l2;

    return head->next;
}

struct Cmp {
    bool operator()(const ListNode *node1, const ListNode *node2) {
        return node1->val > node2->val;
    }
};

ListNode* mergeKLists(std::vector<ListNode*> &lists)
{
    std::priority_queue<ListNode*, std::vector<ListNode*>, Cmp> pq;

    for(int i = 0; i < lists.size(); i++) {
        if(lists[i])            //注意:这里一定要判断,空的节点不能加入到队列中
            pq.push(lists[i]);
    }

    ListNode *base = new ListNode(-1);
    ListNode *cur = base;

    while(!pq.empty())
    {
        ListNode *pNode = pq.top(); pq.pop();
        cur->next = pNode;
        cur = cur->next;
        if(pNode->next) {
            pq.push(pNode->next);
        }
    }

    return base->next;
}


ListNode* reverseKGroup(ListNode *head, int k)
{
    ListNode *base = new ListNode(-1);
    base->next = head;

    ListNode *pNode = base;

    while(pNode)
    {
        ListNode *lastGroup = pNode;

        int i = 0;
        for(; i < k; i++) {
            pNode = pNode->next;
            if(pNode == nullptr) break;
        }

        if(i == k)
        {
            ListNode *nextGroup = pNode->next;

            ListNode *reverseList = reverse(lastGroup->next, nextGroup);
            
            pNode = lastGroup->next;
            lastGroup->next = reverseList;
            pNode->next = nextGroup;
        }
    }

    return base->next;
}

ListNode* reverse(ListNode *head, ListNode *tail)
{
    ListNode *prev = nullptr;

    while(head != tail) {
        ListNode *pNext = head->next;
        head->next = prev;
        prev = head;
        head = pNext;
    }

    return prev;
}


class MyCalendar
{
public:
    MyCalendar() { }

    bool book(int start, int end) {
        for(const auto &item : res) {
            if(std::max(item.first, start) < std::min(item.second, end)) return false;
        }

        res.push_back({start, end});
        return true;
    }


private:
    std::vector<std::pair<int,int>> res;

};

class MyCalendar
{
public:
    MyCalendar() {}

    bool book(int start, int end)
    {
        auto next = books.lower_bound(start, end);

        if(next != books.end() && next->first < end) return false;
        if(next != books.begin() && (--next)->second > start)  return false;

        books.insert({start, end});

        return true;
    }

private:
    std::set<std::pair<int,int>> books;
};

double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
{
    int m = nums1.size(), n = nums2.size();
    bool isEven = !((m+n)&1);
    int midIndex = (m + n)/2;

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    double res = 0;

    int i = 0, j = 0;
    while(i < m || j < n)
    {
        if(i < m && j < n && nums1[i] < nums2[j]) {
            pq.push(nums1[i++]);
        }
        else if(i < m && j < n && nums1[i] > nums2[j]) {
            pq.push(nums2[j++]);
        }
        else if(i == m) {
            pq.push(nums2[j++]);
        }
        else if(j == n) {
            pq.push(nums1[i++]);
        }

        if(isEven) {
            if(pq.size() == midIndex -1) {
                res += pq.top();
            }
            if(pq.size() == midIndex) {
                res += pq.top();
                break;
            }
        }
        else {
            if(pq.size() == midIndex) {
                res += pq.top();
                break;
            }
        }
    }

    return isEven ? res/2.0 ? res;
}


// dp[i] = std::max(dp[i-1], dp[i-2] + nums[i])
// base i = 0, i = 1
// dp[0] = nums[0], dp[1] = std::max(nums[0], nums[1])
int robCore(std::vector<int> &nums, int left, int right);

int rob(std::vector<int> &nums)
{
    if(nums.empty()) return 0;
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return std::max(nums[0], nums[1]);

    return std::max(robCore(nums, 0, nums.size() - 2), robCore(nums, 1, nums.size() - 1));
}

int robCore(std::vector<int> &nums, int left, int right)
{
    int n = right - left + 1;

    std::vector<int> dp(n+1, 0);
    dp[0] = nums[left], dp[1] = std::max(nums[left], nums[left+1]);

    for(int i = 2; i <= n; i++) {
        dp[i] = std::max(dp[i-1], dp[i-2] + nums[left+i]);
    }

    return dp[n];
}

int main() {
    std::vector<int> nums = {2,3,2};

    std::cout << rob(nums) << std::endl;

    return 0;
}

bool areAlmostEqual(std::string s1, std::string s2)
{
    std::vector<int> count;

    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] != s2[i]) count.push_back(i);

        if(count.size() > 2) return false;
    }

    if(s.empty()) return true;
    else if(count.size() == 2 && s1[count[0]] == s2[count[1]] && s1[count[1]] == s2[count[0]]) return true;

    return false;
}


class LRUCache
{
public:
    LRUCache(int capacity) :size(capacity) {

    }

    int get(int key)
    {
        auto it = hash.find(key);
        if(it == hash.end()) return -1;

        cache.splice(cache.begin(), cache, it->second);
        hash[key] = cache.begin();

        return cache.front().second;
    }

    void put(int key, int value)
    {
        auto it = hash.find(key);
        if(it != hash.end()) {
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
            hash[key] = cache.begin();
            return;
        }

        cache.push_front({key, value});
        hash[key] = cache.begin();

        if(cache.size() > size) {
            hash.erase(cache.back().first);
            cache.pop_back();
        }

    }


private:
    std::list<std::pair<int,int>> cache;
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> hash;
    int size;

};


int main() {
    LRUCache LRU(3);

    LRU.put(1, 1);
    LRU.put(2, 2);
    std::cout << LRU.get(1) << std::endl;

    return 0;
}

class MedianFinder
{
public:
    MedianFinder() {

    }

    void addNum(int num) {
        if(minQue.empty() || num > minQue.top()) {
            minQue.push(num);
        }
        else {
            maxQue.push(num);
        }

        if(minQue.size() > maxQue.size() + 1) {
            maxQue.push(minQue.top());
            minQue.pop();
        }
        else if(maxQue.size() > minQue.size() + 1) {
            minQue.push(maxQue.top());
            maxQue.pop();
        }

    }

    double findMedian() {
        int m = minQue.size(), n = maxQue.size();
        if(m == n) return (minQue.top() + maxQue.top())/2.0;
        
        if(m == n + 1) return minQue.top();
        
        return maxQue.top();
    }

private:
    std::priority_queue<int> maxQue;    //最大队
    std::priority_queue<int, std::vector<int>, std::greater<int>> minQue;   //最小队

};

bool hasCycle(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return false;

    ListNode *fast = head, *slow = head;

    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow) return true;
    }

    return false;
}

ListNode *detectCycle(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return nullptr;

    ListNode *fast = head, *slow = head;

    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow) {
            ListNode *pNode = head;
            while(pNode != slow) {
                slow = slow->next;
                pNode = pNode->next;
            }
            return pNode;
        }
    }

    return nullptr;
}

int minDepth(TreeNode *root)
{
    if(root == nullptr) return 0;

    if(root->left == nullptr) return 1 + minDepth(root->right);
    else if(root->right == nullptr) return 1 + minDepth(root->left);

    return 1 + std::min(minDepth(root->left), minDepth(root->right));
}


int minDepth(TreeNode *root)
{
    if(root == nullptr) return 0;

    std::queue<TreeNode*> que;
    que.push(root);

    int depth = 1;

    while(!que.empty())
    {
        int size = que.size();
        for(int i = 0; i < size; i++)
        {
            TreeNode *pNode = que.front();  que.pop();
            // if(pNode->left == nullptr && pNode->right == nullptr) return depth;

            if(pNode->left) que.push(pNode->left);
            if(pNode->right) que.push(pNode->right);
        } 

        depth++;
    }

    return depth;
}

int maxDepth(TreeNode *root)
{
    if(root == nullptr) return 0;
    
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}


int dp[1001][1001] = {0};

int dfs(std::vector<int> &s, int i, int j, int sum)
{
    if(i == j) return 0;

    return dp[i][j] ? dp[i][j] : dp[i][j] = std::max(sum - s[i] - dfs(s, i + 1, j, sum - s[i]), sum - s[j] - dfs(s, i, j-1, sum - s[j]));
}

int stoneGameVII(std::vector<int> &s) {
    return dfs(s, 0, s.size() - 1, accumulate(s.begin(), s.end(), 0));
}

int thridMax(std::vector<int> &nums)
{
    // std::priority_queue<int> pq;
    // std::set<int> mySet;
    
    // for(int i = 0; i < nums.size(); i++) {
    //     pq.push(nums[i]);
    //     if(pq.size() > 3) {
    //         pq.pop();
    //     }
    // }
    std::set<int> mySet;

    for(int &n : nums) {
        mySet.insert(n);
        if(mySet.size() > 3) mySet.erase(mySet.begin());
    }

    return mySet.size() == 3 ? &mySet.begin() : mySet.*rbegin();      
}

int thridMax(std::vector<int> &nums)
{
    int first = INT_MIN, second = INT_MIN, thrid = INT_MIN;

    for(int &n : nums)
    {
        if(n > first) {
            thrid = second;
            second = first;
            first = n;
        }
        else if(n < first && n > second) {
            thrid = second;
            second = n;
        }
        else if(n > thrid && n < second) {
            thrid = n;
        }
    }

    return thrid == INT_MIN ? first : thrid;
}

int longestPalindrome(std::string s)
{
    std::unordered_set<char> mySet;

    int count = 0;

    for(const char &c : s) {
        if(mySet.count(c)) {
            mySet.erase(c);
            count++;
        }
        else {
            mySet.insert(c);
        }
    }

    if(!mySet.empty()) return count*2 + 1;
    return 2*count;
}

int longestCommonSubsequence(std::string text1, std::string text2)
{
    int m = text1.size(), n = text2.size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
        }
    }

    std::string res;
    for(int i = m, j = n; i >= 0 && j >= 0 && ;)
    {
        if(s[i] == t[j]) {
            i--;
            j--;
            res += s[i];
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }

    reverse(res.begin(), res.end());

    std::cout << res << std::endl;

    return dp[m][n];
}

bool isPalindrome(int x)
{
    if(x == 0) return true;
    if(x < 0 || x < 10 || x%10 == 0) return false;

    int ans = 0;
    int tmp = x;

    while(x) {
        if(ans > INT_MAX/10 || x%10 > 7) return false;
        ans = ans*10 + x%10;
        x /= 10;
    }

    return ans == tmp;
}

//思路: 对二叉树的插入或者删除操作会改变树的结构,所以这里递归返回的不能是空,而是返回实际节点

//1.要删除的节点是叶子节点(没有左右子树), 直接返回nullptr(此时root->right = nullptr && root->left == nullptr) (将情况1合并到情况2或者3中都行)
//2.要删除的节点只有右子树,没有左子树, 直接返回 root->right
//3.要删除的节点只有左子树,没有右子树, 直接返回 root->left
//4.要删除的节点既有左子树和右子树, 找到左子树的最大值或者右子树的最大节点, 比如找到左子树的最大值, 将root->val替换掉, 之后删除左子树的最大节点

TreeNode* deleteNode(TreeNode *root, int key)
{
    if(root == nullptr) return root;

    if(root->val == key)
    {
        if(root->left == nullptr) return root->right;
        else if(root->right == nullptr) return root->left;

        TreeNode *pNode = findMaxNode(root->left);
        root->val = pNode->val;
        root->left = deleteNode(root->left, pNode->val);
    } 
    else if(root->val < key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        root->left = deleteNode(root->left, key);
    }

    return root;
}

TreeNode* findMaxNode(TreeNode *root)
{
    while(root->right) {
        root = root->right;
    }

    return root;
}

TreeNode* insertIntoBST(TreeNode *root, int val)
{
    if(root == nullptr) return (new TreeNode(val));

    if(root->val < val) {
        root->right = insertIntoBST(root->right, val);
    }
    else {
        root->left = insertIntoBST(root->left, val);
    }

    return root;
}


// dp[t]代表加油t次能到达的最远距离
// if dp[t] >= s[i][0], dp[t+1] = dp[t] + s[i][1], t为0到n(n为加油站的总个数)
// 之后遍历dp数组,找到第一个 >=target 的t即可


int minRefuelStops(int target, int startFuel, std::vector<std::vector<int>> &stations)
{
    int dp[501] = {startFuel};

    for(int i = 0; i < stations.size(); i++) {
        for(int j = i; j >= 0 && dp[j] >= stations[i][0]; j--) {
            dp[j+1] = std::max(dp[j+1], dp[j] + stations[i][1]);
        }
    }

    for(int t = 0; t <= stations.size(); t++) {
        std::cout << dp[t] << " ";
        // if(dp[t] >= target) return t;
    }
    std::cout << std::endl;

    return -1;
}

int main() {
    std::vector<std::vector<int>> stations = {{10,60}, {20,30}, {30,30}, {60,40}};
    int target = 100, startFuel = 10;

    minRefuelStops(target, startFuel, stations);
    
    return 0;
}

// Leetcode第61题:旋转链表
// 1.将链表首尾相连
// 2.pre指针移动(len-k-1)步
// 3.返回pre指针的下一个指针,将pre->next置为空

ListNode* rotateRight(ListNode *head, int k)
{
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *tail = head;
    int len = 1;
    while(tail->next) {
        tail = tail->next;
        len++;
    }

    k %= len;
    if(k == 0) return head;  //判断移动长度是否为链表的整数倍

    tail->next = head;      //将链表首尾连接

    ListNode *pre = head;
    for(int i = 0; i < len-k-1; i++) {
        pre = pre->next;
    } 

    ListNode *res = pre->next;
    pre->next = nullptr;

    return res;
}

int findKthLargest(std::vector<int> &nums, int k)
{
    // 维护一个小顶堆
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for(const int &n : nums)
    {
        pq.push(n);
        if(pq.size() > k) pq.pop();
    }

    return pq.top();
}

//快排
int findKthLargest(std::vector<int> &nums, int k)
{
    int left = 0, right = nums.size() - 1;

    k = nums.size() - k;

    while(left <= right)
    {
        int mid = partition(nums, left, right);
        if(mid < k) {
            left = mid + 1;
        }
        else if(mid > k) {
            right = mid - 1;
        }
        else return nums[k];
    }

    return -1;
}

int partition(std::vector<int> &nums, int left, int right)
{
    int pivot = nums[left];

    while(left < right)
    {
        while(left < right && nums[right] >= pivot) right--;
        std::swap(nums[left], nums[right]);

        while(left < right && nums[left] <= pivot) left++;
        std::swap(nums[left], nums[right]);
    }

    return left;
}


ListNode* sortList(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *fast = head, *slow = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode *head2 = slow->next;
    slow->next = nullptr;

    // ListNode *newHead = mergeTwoLists(head, head2);

    // return newHead;
    return mergeTwoLists(sortList(head), sortList(head2));
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if(l1 == nullptr) return l2;
    else if(l2 == nullptr) return l1;

    if(l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

int findKthLargest(std::vector<int> &nums, int k)
{
    if(k > nums.size()) return -1;

    std::priority_queue<int> pq(nums.begin(), nums.end());

    for(int i = 0; i < k-1; i++) {
        pq.pop();
    }

    return pq.top();
}

std::vector<int> topKFrequent(std::vector<int> &nums, int k)
{
    std::priority_queue<std::pair<int,int>> pq;

    std::unordered_map<int,int> hash;
    for(const int &n : nums) {
        hash[n]++;
    }

    for(auto &item : hash) {
        pq.push({item.second, item.first});
    }

    std::vector<int> res;
    while(k-- > 0) {
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;
}


struct Cmp {
    bool operator()(const std::pair<int,int> &demo1, const std::pair<int,int> &demo2) {
        return demo1.second < demo2.second;
    }
};


std::vector<int> topKFrequent(std::vector<int> &nums, int k)
{
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, Cmp> pq;

    std::unordered_map<int,int> hash;
    for(const int &n : nums) {
        hash[n]++;
    }

    for(auto &item : hash) {
        pq.push({item.first, item.second});
    }

    std::vector<int> res;
    while(k-- > 0) {
        res.push_back(pq.top().first);  pq.pop();
    }

    return res;
}

int furthestBuilding(std::vector<int> &height, int bricks, int ladders)
{
    std::priority_queue<int> pq;

    for(int i = 0; i < height.size() - 1; i++)
    {
        int diff = nums[i] - nums[i+1];
        if(diff < 0) {
            pq.push(diff);
        }

        if(pq.size() > ladders) {
            bricks += pq.top();
            pq.pop();
        }

        if(bricks < 0) return i;
    }

    return height.size() - 1;
}

int kthSmallest(std::vector<std::vector<int>> &matrix, int k)
{
    int n = matrix.size();

    int left = matrix[0][0], right = matrix[n-1][n-1];

    while(left <= right)
    {
        int mid = left + ((right-left) >> 1);

        int count = 0;
        for(int i = 0; i < n; i++) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if(count < k) {
            left = mid + 1;
        }
        else if(count >= k) {
            right = mid - 1;
        }
    }

    return left;
}


std::vector<std::vector<std::string>> res;

std::vector<std::vector<std::string>> partition(std::string s)
{
    std::vector<std::string> par;

    dfs(s, 0, par);

    return res;
}

void dfs(const std::string &s, int pos, std::vector<std::string> &par)
{
    if(pos == s.size()) {
        res.push_back(par);
        return;
    }

    for(int i = pos; i < s.size(); i++) {
        if(isPalindrome(s, pos, i)) {
            par.push_back(s.substr(pos, i-pos+1));
            dfs(s, i + 1, par);
            par.pop_back();
        }
    }

}    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         std::cout << dp[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // return {};

bool isPalindrome(std::string s, int left, int right)
{
    while(left < right) {
        if(s[left++] != s[right--]) return false;
    }

    return true;
}



std::vector<std::vector<std::string>> partition(std::string s);

std::vector<std::vector<std::string>> res;

int main() {
    std::string s = "aab";

    partition(s);

    return 0;
}


// 1.先判断[i..j]能够组成回文串
// dp[i][j] = 1. if s[i]=s[j] && (dp[i+1][j-1] = 1 || j-i <=2)
// 从下往上判断

std::vector<std::vector<std::string>> partition(std::string s)
{
    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for(int i = n -1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            if(s[i] == s[j] && (j - i <= 2 || dp[i+1][j-1])) {
                dp[i][j] = 1;
            }
        }
    }

    std::vector<std::string> path;

    dfs(path, dp, s, 0);

    return res;
}

void dfs(std::vector<std::string> &path, std::vector<std::vector<int>> &dp, const std::string &s, int pos)
{
    if(pos == s.size()) {
        res.push_back(path);
        return;
    }

    for(int i = pos; i < s.size(); i++) {
        if(dp[pos][i]) {
            path.push_back(s.substr(pos, i - pos + 1));
            dfs(path, dp, s, i + 1);
            path.pop_back();
        }
    }

}

int minCut(std::string s)
{
    int n = s.size();
    if(n <= 1) return 0;

    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    std::vector<int> minCut(n, n-1);

    for(int i = n-1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            if(s[i] == s[j] && (j-i <= 2 || dp[i+1][j-1])) 
            {
                dp[i][j] = 1;

                if(j == n-1) {
                    minCut[i] = 0;
                }
                else {
                    minCut[i] = std::min(minCut[i], minCut[j] + 1);
                }
            }
        }
    }

    return minCut[0];
}

// dp[i][j]表示s[i..j]的最长回文子序列
// dp[i][j] = dp[i+1][j-1] + 2, if s[i] = s[j]
// dp[i][j] = max(dp[i+1][j], dp[i][j-1]), else

// base case : j-i < 2

int longestPalindromeSubseq(std::string s)
{
    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for(int i = n-1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            if(s[i] == s[j]) 
            {
                if(j - i < 1) dp[i][j] = 1;
                else if(j - i < 2) dp[i][j] = 2;
                else dp[i][j] = dp[i+1][j-1] + 2;
            }
            else 
            {
                dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }

    return dp[0][n-1];
}

int countSubstrings(std::string s)
{
    int count = 0;

    for(int i = 0; i < s.size(); i++) {
        count += isPalindrome(s, i, i);
        count += isPalindrome(s, i, i + 1);
    }

    return count;
}


int isPalindrome(std::string s, int left, int right)
{
    int count = 0;

    while(left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
        count++;
    }

    return count;
}



int countSubstrings(std::string s)
{
    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    int count = 0;

    for(int i = n-1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            if(s[i] == s[j] && (j-i < 2 || dp[i+1][j-1])) {
                dp[i][j] = 1;
                count ++;
            }
        }
    }

    return count;
}

std::string longestPalindrome(std::string s)
{
    int maxLen = 0, startIndex = 0;

    int i = 0;

    while(i < s.size())
    {
        int start = i, end = i;
        while(end + 1 < s.size() && s[end] == s[end+1]) end++;
        i = end + 1;

        while(start - 1 >= 0 && end + 1 < s.size() && s[start-1] == s[end+1]) {
            start--;
            end++;
        }

        if(maxLen < end - start + 1) {
            maxLen = end - start + 1;
            startIndex = start;
        }
    }

    return s.substr(startIndex, maxLen);
}


int longestPalindrome(std::string s)
{
    std::unordered_set<char> mySet;

    int count = 0;

    for(const char &c : s) {
        if(mySet.count(c)) {
            mySet.erase(c);
            count++;
        }
        else
            mySet.insert(c);
    }

    return mySet.empty() ? count*2 : count*2 + 1;
}


bool canPartitionKSubsets(std::vector<int> &nums, int k)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if(sum%k != 0) return false;

    int target = sum/k;

    sort(nums.rbegin(), nums.rend());

    for(const int &n : nums) {
        if(n > target) return false;
    }

    std::vector<int> subSum(k, 0);

    return dfs(nums, subSum, 0, target, k);
}

bool dfs(std::vector<int> &nums, std::vector<int> &subSum, int pos, int target, int k)
{
    if(pos == nums.size()) {
        int value = subSum[0];
        for(int i = 1; i < k; i++) {
            if(value != subSum[i]) return false;
        }
        return true;
    }

    for(int i = 0; i < k; i++) 
    {
        if(subSum[i] + nums[pos] > target) continue;
        subSum[i] += nums[pos];
        if(dfs(nums, subSum, pos + 1, target, k)) return true;
        subSum[i] -= nums[pos];
    }

    return false;     //加不加都可,Leetcode不加会判定函数没有返回值
}


int main() {
    std::string s = "AkleBiCeilD";

    // int cur = 0;
    // for(int i = 0; i < s.size(); i++) {
    //     if(s[i] >= 'a' && s[i] <= 'z') std::swap(s[cur++], s[i]);
    // }



    for(int i = 0; i < s.size(); i++) {
        if(i+1 < s.size() && islower(s[i+1])) {
            int tmp = s[i+1];
            int j = i;
            for(; j >= 0 && isupper(s[j]); j--) {
                s[j+1] = s[j];
            }
            s[j+1] = tmp;
        }
    }

    std::cout << s << std::endl;

    return 0;
}

void moveZeros(std::vector<int> &nums)
{
    int cur = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i])
            std::swap(nums[cur++], nums[i]);
    }
}

bool isSubsequence(std::string s, std::string t)
{
    int i = 0, j = 0;
    for(; j < t.size(); j++) {
        if(s[i] == t[j]) i++;
    }

    return i == s.size();
}

std::vector<int> sortArrayByParity(std::vector<int> &A)
{
    for(int i = 0, j = 0; j < A.size(); j++) {
        if((A[j]&1) != 0) {
            std::swap(A[i++], A[j]);
        }
    }

    return A;
}

std::string reverseVowels(std::string s)
{
    int i = 0, j = s.size() - 1;

    while(i < j)
    {
        while(i < j && !isVowel(s[i])) i++;
        while(i < j && !isVowel(s[j])) j--;

        if(i < j) std::swap(s[i++], s[j--]);
    }

    return s;
}

bool isVowel(char c)
{
    char ch = toupper(c);

    return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}


std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2)
{
    std::unordered_set<int> mySet(nums1.begin(), nums1.end());

    std::vector<int> res;

    for(const int &n : nums2) {
        if(mySet.count(n)) {
            res.push_back(n);
            mySet.erase(n);
        }
    }

    return res;
}

//



void reverseWords(std::string &s)
{
    int left = 0, right = 0;
    while(right < s.size())
    {
        if(s[right] == ' ') {
            reverse(s.begin() + left, s.begin() + right);
            left = right + 1;
        }
        right++;
    }

    reverse(s.begin() + left, s.begin() + right);

    reverse(s.begin(), s.end());
}


int main() {
    std::string str =  "I am a studentn !";

    reverseWords(str);

    std::cout << str << std::endl;

    return 0;
}

std::vector<std::string> res;

std::vector<std::string> generateParenthesis(int n)
{
    int left = n, right = n;

    std::string path;
    dfs(path, left, right);

    return res;
}

void dfs(std::string &path, int left, int right)
{
    //左括号剩的比右括号多
    if(left > right) return;
    if(left < 0 || right < 0) return;

    if(left == 0 && right == 0) {
        res.push_back(path);
        return;
    }

    if(left < 0 || right < 0) return ;

    path.push_back('(');
    dfs(path, left - 1, right);
    path.pop_back();

    path.push_back(')');
    dfs(path, left, right - 1);
    path.pop_back();
}

bool isValid(std::string &path)
{
    int left = 0, right = 0;
    for(const char &c: path) {
        if(c == '(') left++;
        else if(c == ')') {
            if(left == 0) return false;
            else left--;
        }
    }

    return true;
}

// 1.遍历字符串, c = '(', 将 leftMin和leftMax都++
// 2.c = ')', leftMin--, leftMax--, 如果leftMax小于0则返回false
// 3.c = '*', 如果'*'匹配'('则leftMax++, 如果'*'匹配')'则leftMin--


bool checkValidstring(std::string s)
{
    int leftMin = 0, leftMax = 0;

    for(const char &c : s)
    {
        if(c == '(') {
            leftMin++;
            leftMax++;
        }
        else if(c == ')') {
            leftMin--;
            leftMax--;

            if(leftMax < 0) return false;
            leftMin = std::max(0, leftMin);
        }
        else if(c == '*') {
            leftMax++;
            leftMin--;
            leftMin = std::max(0, leftMin);
        }
    }

    return leftMin == 0;
}

int longestConsecutive(std::vector<int> &nums)
{
    std::unordered_set<int> mySet(nums.begin(), nums.end());

    int res = 0;

    for(const int &n : mySet) 
    {
        int x = n - 1, y = n + 1;
        while(mySet.count(x)) mySet.erase(x--);
        while(mySet.count(y)) mySet.erase(y--);

        res = std::max(res, y - x - 1);
    }   
    
    return res;
}

// first < second , 初始值设定为 INT_MIN
// n >= second, first = second, second = n
// n >= first , first = n
// 

// fist < second, 设定初值为INT_MAX
// n < first, second = n
// n < first, first = n;
// else return true;

bool increasingTriplet(std::vector<int> &nums)
{
    int x = INT_MAX, y = INT_MAX;

    for(const int &n : nums)
    {
        if(n <= x) {
            x = n;
        }
        else if(x < n && n <= y) {
            y = n;
        }
        else if(x > y) return true;
    }
    
    return false;
}

int main() {
    std::string str;

    getline(std::cin, str);

    std::stringstream in(str);
    std::string out;
    std::vector<std::string> strs;

    while(getline(in, out)) {
        strs.push_back(out);
    }

    std::cout << std::endl;

    for(auto str : strs) {
        std::cout << str << std::endl;
    }

    return 0;
}

// 判断是否为有效的IP地址:
// 方法一: 切分后一个一个比较

std::string validIpAddress(std::string IP)
{
    return isIPv4(IP) ? "IPv4" ? (isIPV6(IP) ? "IPv6" : "Neither");
}

bool isIPv4(const std::string &IP)
{
    if(count(IP.begin(), IP.end() '.') != 3) return false;

    std::vector<std::string> strs = spilt(IP, '.');

    if(strs.size() != 4) return false;

    for(const auto &str : strs) 
    {
        if(str.size() > 3) return false;

        if(str.size() != 1 && str[0] == '0') return false;

        for(const char &c : str) {
            if(!isdigit(c)) return false;
        }

        if(std::stol(str) > 255) return false;
    }

    return true;
}

bool isIPV6(const std::string &IP)
{
    if(find(IP.begin(), IP.end(), ':') != 7) return false;

    std::vector<std::string> strs = spilt(IP, ':');
    if(strs.size() != 8) return false;

    for(const auto &str : strs)
    {
        if(str.size() > 4) return false;
        
        for(const char &c : str) {
            if(!isdigit(c) && toupper(c) < 'A' && toupper(c) > 'F') return false;
        }
    }

    return true;
}


std::vector<std::string> spilt(std::string IP, char c)
{
    std::stringstream in(IP);
    std::string out;

    std::vector<std::string> res;

    while(getline(in, out, c)) {
        if(!out.empty()) {
            res.push_back(out);
        }
    }

    return res;
}


// 方法二:使用正则表达式

std::string validIpAddress(std::string IP)
{
    regex ipv4("((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])\\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])");
    regex ipv6("((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]{1,4})");

    if(regex_match(IP, ipv4)) {
        return "IPv4";
    }
    else if(regex_match(IP, ipv6)) {
        return "Ipv6";
    }
    
    return "Neither";
}

int rob(std::vector<int> &nums)
{
    if(nums.size() == 1) return nums[0];

    int first = nums[0], second = std::max(nums[0], nums[1]);
    int cur = second;

    for(int i = 2; i < nums.size(); i++) {
        cur = std::max(second, first + nums[i]);
        first = second;
        second = cur;
    }

    return cur;
}

int rob(std::vector<int> &nums)
{
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return std::max(nums[0], nums[1]);

    return std::max(robCore(nums, 0, nums.size() - 2), robCore(nums, 1, nums.size() - 1));
}

int robCore(std::vector<int> &nums, int left, int right)
{
    if(left == right) return nums[0];

    int first = nums[left], second = nums[left + 1];
    int cur = second;

    for(int i = left + 2; i <= right; i++) {
        cur = first + second;
        first = second;
        second = cur;
    }

    return cur;
}


std::unordered_map<TreeNode*, int> hash;

int rob(TreeNode *root)
{
    if(root == nullptr) return 0;

    if(hash.count(root)) return hash[root];

    int money1 = root->val;

    if(root->left) {
        money1 += rob(root->left->left) + rob(root->left->right);
    }
    if(root->right) {
        money1 += rob(root->right->left) + rob(root->right->right);
    }

    int money2 = rob(root->left) + rob(root->right);

    hash[root] = std::max(money1, money2);
    
    return std::max(money1, money2);
}

// Leetcode第72题:最小编辑距离
// dp[i][i]代表s[0..i]完全匹配t[0..j]部分需要修改几次(这个修改可以是插入,删除,替换)

// dp[i][j] = dp[i-1]][j-1], if s[i] = t[j]

// dp[i][j] = dp[i][j-1] + 1,   1.在s中插入一个字符,则新插入的字符就和s[j]匹配了,所以结果就等于s[i]和t[j-1]匹配的结果
//            dp[i-1][j] + 1,   2.删除s中第i个字符,则结果就等于s[i-1]和t[j]匹配的结果
//            dp[i-1][j-1]+1  3.将s的第i个字符替换成t的第j个字符,则s[i]和t[j]就匹配了,结果就等于s[i-1]和t[j-1]匹配的结果
// 则dp[i][j]的结果就是上面三次尝试操作的最小操作数

//  base case 就是i=0, j=0

int minDistance(std::string word1, std::string word2)
{
    int m = word1.size(), n = word2.size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for(int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }

    for(int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = std::min(dp[i][j-1], std::min(dp[i-1][j], dp[i-1][j-1])) + 1;
            }
        }
    }

    return dp[m][n];
}


struct Node {
    int x;
    int len;
    Node(int m_x, int m_len) {
        x = m_x;
        len = m_len;
    }
};

struct Cmp {
    bool operator()(const Node &o1, const Node &o2) {
        return o1.len > o2.len;
    }
};


void initMap(std::vector<std::vector<int>> &map)
{
    map = std::vector<std::vector<int>>(6, std::vector<int>(6, 0));
    // map[0] = {1,2,3};
    // map[1] = {4};
    // map[2] = {4,5};
    // map[4] = {5};
    map[0][1] = 4, map[0][2] = 5, map[0][3] = 8;
    map[1][4] = 4;
    map[2][4] = 5, map[2][5] = 3;
    map[4][5] = 4;
}


void dijkstra()
{
    // std::vector<std::vector<int>> map(6, std::vector<int>(6, 0));
    std::vector<std::vector<int>> map;
    initMap(map);

    std::vector<int> isVisited(6, 0);
    std::vector<int> distance(6, INT_MAX);

    std::priority_queue<Node, std::vector<Node>, Cmp> pq;
    distance[0] = 0;
    pq.push(Node(0, 0));

    while(!pq.empty())
    {
        Node tmp = pq.top();    pq.pop();
        int index = tmp.x;
        int len = tmp.len;
        isVisited[index] = 1;

        for(int i = 0; i < map[index].size(); i++) 
        {
            if(map[index][i] > 0 && !isVisited[i]) {
                Node newNode = Node(i, len + map[index][i]);
                if(distance[i] > newNode.len) {
                    distance[i] = newNode.len;
                    pq.push(newNode);
                }
            }
        }
    }

    for(int i = 0; i < 6; i++) {
        std::cout << distance[i] << " ";
    }
    std::cout << std::endl;

}



int main() {
    dijkstra();

    return 0;
}


std::string shortestPalindrome(std::string s)
{
    int maxLen = 0;

    int i = 0;

    while(i <= s.size()/2)
    {
        int start = i, end = i;

        while(end + 1 < s.size() && s[end+1] == s[end]) end++;

        i = end + 1;

        while(start - 1 >= 0 && end + 1 < s.size() && s[start-1] == s[end+1]) {
            start--;
            end++;
        }

        if(maxLen < end - start + 1 && start == 0) {
            maxLen = end - start + 1;
        }
    }

    std::string remain = s.substr(maxLen);

    reverse(remain.begin(), remain.end());

    return reamin + s;
}


// dp[i][j] 表示前i个数是否能组成j
// dp[i][j] = dp[i-1][j], 将第i个数不算入
// dp[i][j] = dp[i-1][j-n], 将第i个数算入
// 则 dp[i][j] = dp[i-1][j] || dp[i-1][j-n], 只要其中一个能满足就行
// base case dp[0][0] = 1

// 状态空间压缩成一维, 则 dp[j] = dp[j] || dp[j-n], 注意j要逆序遍历
// base case dp[0] = 1

bool canPartition(std::vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum & 1) return false;

    int target = sum >> 1;

    int n = nums.size();
    // std::vector<std::vector<int>> dp(n + 1, std::vector<int>(target + 1, 0));
    std::vector<int> dp(target + 1, 0);
    // for(int i = 0; i <= n; i++) {
    //     dp[i][0] = 1;
    // }
    dp[0] = 1;

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= target; j++) {
    //         if(j < nums[i-1]) {
    //             dp[i][j] = dp[i-1][j];
    //         }
    //         else {
    //             dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
    //         }
    //     }
    // }

    for(int i = 1; i <= n; i++) {
        for(int j = target; j >= nums[i-1]; j--) {
            dp[j] = dp[j] || dp[j-nums[i-1]];
        }
    }

    return dp[target];

    // return dp[n][target];
}


//Leetcode第322题 : 钱币找零
//无穷背包问题

// dp[i][j]表示钱数为j时从前i种硬币中换出的最少硬币数
// dp[i][j] = dp[i-1][j],  不换
// dp[i][j] = dp[i][j-n] + 1,  换       
// dp[i][j] 就取这者最小值
// base case i = 0(表示硬币种数为0), dp[0][0] = 0,  dp[0][j] = inf(表示不可能) 
//           j = 0(表示兑换的钱数为0), dp[i][0] = 0

int coinChange(std::vector<int> &coins, int amount)
{
    int n = coins.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(amount + 1, amount + 1));

   for(int i = 0; i <= n; i++) {
       dp[i][0] = 0;
   }

   for(int i = 1; i <= n; i++) {
       for(int j = 1; j <= amount; j++) {
           if(j < coins[i-1]) {
               dp[i][j] = dp[i-1][j];
           }
           else {
               dp[i][j] = std::min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
           }
       }
   }

    return dp[n][amount] == amount + 1 ? -1 : dp[n][amount];
}


int coinChange(std::vector<int> &coins, int amount)
{
    int n = coins.size();

    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= amount; j++) {
            if(j >= coins[i-1]) {
                dp[j] = std::max(dp[j], dp[j-coins[i-1]] + 1);
            }
        }
    }

    return dp[amount] == amount + 1 ? -1 : dp[amount];
}

// dp[i][j]表示前i种硬币凑成j的方法数
// dp[i][j] = dp[i-1][j],  不拼
//          = dp[i-1][j] + dp[i][j-n], 拼

// base case i = 0, dp[0][0] = 1, dp[0][j] = 0;
//           j = 0, dp[i][0] = 1

int change(int amount, std::vector<int> &coins)
{
    int n = coins.size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(amount + 1, 0));

    for(int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= amount; j++) {
            if(j < coins[i-1]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            }
        }
    }

    return dp[n][amount];
}


// 状态压缩

int change(int amount, std::vector<int> &coins)
{
    int n = coins.size();

    std::vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = coins[i-1]; j <= amount; j++) {
            dp[j] += dp[j-coins[i-1]];
        }
    }

    return dp[amount];
}

int thridMax(std::vector<int> &nums)
{
    long thrid = LONG_MIN, second = LONG_MIN, first = LONG_MIN;

    for(const int &n : nums)
    {
        if(n > first) {
            thrid = second;
            second = first;
            first = n;
        }
        else if(n < first && n > second) {
            thrid = second;
            second = n;
        }
        else if(n < second && n > thrid) {
            thrid = n;
        }
    }

    return thrid == LONG_MIN ? first : thrid;
}

// x < y
// n <= x, x = n
// n > x 且 n <= y, y = n
// 其他情况返回true

bool increasingTriplet(std::vector<int> &nums)
{
    int x = INT_MAX, y = INT_MAX;

    for(const int &n : nums)
    {
        if(n <= x) {
            x = n;
        }
        else if(n <= y) {
            y = n;
        }
        else return true;
    }

    return false;
}


// x < y < z
//3. n >= x, x = n
//2. n >= y, x = y, y = n
//1. n >= z, x = y, y = z, z = n

int thridMax(std::vector<int> &nums)
{
    long x, y, z;
    x = y = z = LONG_MIN;

    for(const int &n : nums)
    {
        if(n > z) {     //全部都不能使用=号,是为了相等的元素过滤掉
            x = y;
            y = z;
            z = n;
        }
        else if(n < z && n > y) {
            x = y;
            y = n;
        }
        else if(n < y && n > x) {
            x = n;
        }
    }

    return x == LONG_MIN ? z : x;
}


std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2)
{
    std::unordered_set<int> mySet(nums1.begin(), nums1.end());

    std::vector<int> res;

    for(const int &n : nums2) {
        if(mySet.count(n)) {
            res.push_back(n);
            mySet.erase(n);
        }
    }

    return res;
}


std::vector<int> intersection(std::vector<int> &nums1, int &nums2) 
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    erase(unique(nums1.begin(), nums1.end()), nums1.end());
    erase(unique(nums2.begin(), nums2.end()), nums2.end());

    int i = 0, j = 0;

    std::vector<int> res;
    std::unordered_set<int> mySet;

    while(i < num1.size() && j < nums2.size())
    {
        if(nums1[i] < nums2[j]) {
            i++;
        }
        else if(nums1[i] > nums2[j]) {
            j++;
        }
        else {
            mySet.push(nums[i]);
            i++;
            j++;
        }
    }

    for(const int &n : mySet) {
        res.push_back(n);
    }

    return res;
}

std::vector<int> intersection(std::vector<int> &nums1, int &nums2) 
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    erase(unique(nums1.begin(), nums1.end()), nums1.end());
    erase(unique(nums2.begin(), nums2.end()), nums2.end());

    int i = 0, j = 0;

    std::vector<int> res;

    while(i < num1.size() && j < nums2.size())
    {
        if(nums1[i] < nums2[j]) {
            i++;
        }
        else if(nums1[i] > nums2[j]) {
            j++;
        }
        else {
            mySet.push(nums[i]);
            i++;
            j++;
        }
    }

    return res;
}


std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2)
{
    std::unordered_set<int> mySet;

    sort(nums1.begin(), nums1.end());

    for(const int &n : nums2) {
        if(findNum(n, nums1)) {
            mySet.insert(n);
        }
    }

    std::vector<int> res;

    for(const int &n : mySet) {
        res.push_back(n);
    }

    return res;
}


bool findNum(int target, const std::vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
    
    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);

        if(nums[mid] < target) {
            left = mid + 1;
        }
        else if(nums[mid] > target) {
            right = mid - 1;
        }
        else return true;
    }

    return false;
}


std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2)
{
    // std::unordered_set<int> mySet(nums1.begin(), nums1.end());
    std::unordered_map<int> hash;
    for(const int &n : nums1) {
        hash[n]++;
    }

    std::vector<int> res;

    for(const int &n : nums2) {
        if(--hash[n] >= 0) {
            res.push_back(n);
        }
    }

    return res;
}

std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2)
{
    sort(num1.begin(), nums1.end());
    sort(num2.begin(), nums2.end());

    int i = 0, j = 0;
    std::vector<int> res;

    while(i < nums1.size() && j < num2.size())
    {
        if(nums1[i] < nums2[j]) i++;
        else if(num1[i] > nums2[j]) j++;
        else {
            res.push_back(num1[i]);
            i++;
            j++;
        }
    }

    return res;
}

int mySqrt(int x)
{
    int left = 0, right = (int)sqrt(x);

    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);

        if(mid == x/mid) {
            return mid;
        }
        else if(mid < x/mid) {
            left = mid + 1;
        }
        else if(mid > x/mid) {
            right = mid - 1;
        }
    }

    return right;
}


int mySqrt(int n)
{
    long x = n;

    while(x*x > n) {
        x = (x + n/x)/2;
    }

    return x;
}


std::vector<int> searchReange(std::vector<int> &nums, int target)
{
    return {leftBound(nums,target), rightBound(nums, target)};
}

int leftBound(std::vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);

        if(nums[mid] < target) {
            left = mid + 1;
        }
        else if(nums[mid] >= target) {
            right = mid - 1;
        }
    }

    if(left == nums.size() || nums[left] != target) return -1;

    return left;  
}


int rightBound(std::vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);

        if(nums[mid] <= target) {
            left = mid + 1;
        }
        else if(nums[mid] > target) {
            right = mid - 1;
        }
    }

    if(right == -1 || nums[right] != target) return -1;

    return right;
}


bool isValidBST(TreeNode *root)
{
    if(root == nullptr) return true;

    TreeNode *prev = nullptr;

    return dfs(root, prev);
}

bool dfs(TreeNode *root, TreeNode * &prev)
{
    if(root == nullptr) return true;

    if(!dfs(root->left, prev)) return false;

    if(prev && root->val <= prev->val) return false;

    prev = root;

    return dfs(root->right, prev);
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *curA = headA, *curB = headB;

    while(curA != curB)
    {
        curA = curA ? curA->next : headB;
        curB = curB ? curB->next : headA;
    }

    return curA;
}


TreeNode* buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
{
    std::unordered_map<int,int> inorderPos;
    for(int i = 0; i < inorder.size(); i++) {
        inorderPos[inorder[i]] = i;
    }

    return buildTreeCore(preorder, 0, preorder.size() - 1, 0, inorderPos);
}


TreeNode* buildTreeCore(std::vector<int> &preorder, int startProrder, int endPreorder, int startInorder, std::unordered_map<int,int> &inorderPos)
{
    if(startProrder > endPreorder) return nullptr;

    TreeNode *root = new TreeNode(preorder[startProrder]);

    int rootIndex = inorderPos[preorder[startProrder]];

    int leftLen = rootIndex - startInorder;

    root->left = buildTreeCore(preorder, startProrder + 1, startProrder + leftLen, startInorder, inorderPos);

    root->right = buildTreeCore(preorder, startProrder + leftLen + 1, endPreorder, rootIndex + 1, inorderPos);

    return root;
}

TreeNode* buildTree(std::vector<int> &postorder, std::vector<int> &inorder)
{
    std::unordered_map<int,int> inorderPos;

    for(int i = 0; i < inorder.size(); i++) {
        inorderPos[inorder[i]] = i;
    }

    return buildTreeCore(postorder, 0, postorder.size() - 1, 0, inorderPos);
} 

TreeNode* buildTreeCore(std::vector<int> &postorder, int startPostorder, int endPostorder, int startInorder, std::unordered_map<int,int> &inorderPos)
{
    if(startPostorder > endPostorder) return nullptr;

    TreeNode *root = new TreeNode(postorder[endPostorder]);

    int rootIndex = inorderPos[postorder[endPostorder]];

    int leftLen = rootIndex - startInorder;

    root->left = buildTreeCore(postorder, startPostorder, startPostorder + leftLen - 1, startInorder, inorderPos);

    root->right = buildTreeCore(postorder, startPostorder + leftLen, endPostorder - 1, rootIndex + 1, inorderPos);

    return root;
}


TreeNode* insertIntoBST(TreeNode *root, int val)
{
    if(root == nullptr) return new TreeNode(val);

    if(root->val < val) {
        root->right = insertIntoBST(root->right, val);
    }
    else {
        root->left = insertIntoBST(root->left, val);
    }

    return root;
}

// 1.删除的节点没有左子树,直接返回右子树
// 2.删除的节点没有右子树,直接返回左子树
// 3.删除的节点既有左子树又有右子树,找到左子树的最大值(或者右子树的最小值)替换当前节点,删除拿来替换的节点

TreeNode* deleteNode(TreeNode *root, int key)
{
    if(root == nullptr) return root;

    if(root->val == key) {
        if(root->left == nullptr) {
            return root->right;
        }
        else if(root->right == nullptr) {
            return root->left;
        }
        else {
            TreeNode *minNode = getMinNode(root->left);
            root->val = minNode->val;
            root->left = deleteNode(root->left, minNode-val);
        }
    }
    else if(root->val < key) {
        root->right = deleteNode(root->right, key);
    }
    else if(root->val > key) {
        root->left = deleteNode(root->left, key);
    }

    return root;
}

TreeNode *getMinNode(TreeNode *root)
{
    while(root->right) {
        root = root->right;
    }

    return root;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if(root == nullptr) return root;

    if(root->val == key) {
        if(root->left == nullptr) return root->right;
        else if(root->right == nullptr) return root->left;

        TreeNode *rightSmall = root->right;
        while(rightSmall->left) {
            rightSmall = rightSmall->left;
        }
        rightSmall->left = root->left;
        return root->right;
    }
    else if(root->val < key) {
        root->right = deleteNode(root->right, key);
    }
    else if(root->val > key) {
        root->left = deleteNode(root->left, key);
    }

    return root;
}

bool canFinsh(int n, std::vector<std::vector<int>> &prere)
{
    std::vector<std::vector<int>> graph(n);
    std::vector<int> degree(n);

    for(int i = 0; i < prere.size(); i++) {
        graph[prere[i][1]].push_back(prere[i][0]);
        degree[prere[i][0]]++;
    }

    std::vector<int> ans;

    for(int i = 0; i < n; i++) {
        if(degree[i] == 0) ans.push_back(i);
    }
  

    for(int i = 0; i < ans.size(); i++)
    {
        for(const int &n : graph[ans[i]]) {
            if(--degree[n] == 0) {
                ans.push_back(n);
            }
        }
    }

    return ans.size() == n;
}

bool canFinsh(int n, std::vector<std::vector<int>> &prere)
{
    std::vector<std::vector<int>> graph(n);
    std::vector<int> degree(n);

    for(auto &e : prere) {
        graph[e[1]].push_back(e[0]);
        e[0]++;
    }

    std::queue<int> que;
    for(int i = 0; i < n; i++) {
        if(degree[i] == 0) que.push(i);
    }

    int count = 0;
    while(!que.empty())
    {
        int n = que.front();    que.pop();
        count++;

        for(int i = 0; i < graph[n].size(); i++) {
            if(--degree[graph[n][i]]) {
                que.push(graph[n][i]);
            }
        }
    }

    return count == n;
}

// 1.确定'0'在各个位置能够移动的方向
// 2.将所有方向得到的可能结果加入到队列中(用hash去重)
// 3.弹出队首元素,判断是否等于目标,再重复2,3两个过程

int slidingPuzzle(std::vector<std::vector<int>> &board)
{
    std::string start, target;
    
    target = "123450";

    for(int i = 0; i < board.size(); i++) {
        std::string tmp;
        for(const int &n : board[i]) {
            tmp += std::to_string(n);
        }
        start += tmp;
    }

    std::vector<std::vector<int>> dir = {{1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}};

    std::queue<std::string> que;
    std::unordered_set<std::string> visited;

    que.push(start);
    visited.insert(start);

    int steps = 0;

    while(!que.empty())
    {
        for(int i = que.size(); i > 0; i--)
        {
            std::string tmp = que.top();  que.pop();

            if(tmp == target) return steps;

            int zero = tmp.find('0');

            for(const int &n : dir[zero]) {
                std::string newStr = swap(tmp, n, zero);
                if(visited.count(newStr)) continue;

                que.push(newStr);
                visited.insert(newStr);
            }
        }
        
        steps++;
    }

    return -1;
}

std::string swap(std::string str, int i, int j) 
{
    std::swap(str[i], str[j]);
    return str;
}


// 集中将数组移动一个维度
// sum[i+1][j+1] 表示第i行第i列的累加和 sum(i, j) = sum[i+1][j+1]
// 则(row2,col2) 和 (row1,col1)围成的面积 = sum(row2, col2) - sum(row-1,col2) - sum(row2,col1-1) + sum(row1-1, col1-1)
// ans = sum[row2+1][col2+1] - sum[row1,col2+1] - sum[row2+1,col1] + sum[row1,col1]

// sum[i][j] = matrix[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1], 注意这里 i,j 是从0开始的


class NumMatrix
{

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

int subarraySum(std::vector<int> &nums, int k)
{
    int preSum = 0;
    std::unordered_map<int,int> hash;
    hash[0] = 1;

    int count = 0;

    for(const int &n : nums) {
        preSum += n;
        count += hash[preSum - k];
        hash[preSum]++;
    }

    return count;
}

int numberOfSubarrays(std::vector<int> &nums, int k)
{
    std::unordered_map<int,int> hash;
    hash[0] = 1;

    int count = 0;
    int oddNum = 0;

    for(const int &n : nums) {
        if(n&1) oddNum++;
        count += hash[oddNum-k];
        hash[oddNum]++;
    }

    return count;
}

int numSubmatrixSumTarget(std::vector<std::vector<int>> &matrix, int target)
{
    int m = matrix.size(), n = matrix[0].size();
    for(int i = 0; i < m; i++) {
        for(int j = 1; j < n; j++) {
            matrix[i][j] += matrix[i][j-1];
        }
    }

    int count = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::unordered_map<int,int> hash = {{0,1}};
            int cur = 0;
            for(int k = 0; k < m; k++) {
                cur += matrix[k][j] - (i > 0 ? matrix[k][i-1] : 0);
                count += hash[cur - target];
                hash[cur]++;
            }
        }
    }

    return count;
}

int subarraysDivByK(std::vector<int > &A, int k)
{
    std::unordered_map<int,int> hash;
    hash[0] = 1;

    int count = 0;
    int preSum = 0;

    for(const int &n : A) {
        preSum += n;
        int key = (preSum%k + k)%k;
        count += hash[key];
        hash[key]++;
    }

    return count;
}

bool checkSubarraySum(std::vector<int> &nums, int k)
{
    std::unordered_map<int,int> hash;
    hash[0] = -1;

    int preSum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        preSum += nums[i];
        int key = (k == 0 ? preSum : preSum%k);
        
        if(hash.count(key)) {
            if(i - hash[key] >= 2) {
                return true;
            }
            else continue;
        }

        hash[key] = i;
    }

    return false;
}

int lengthOfLongestSubstring(std::string s)
{
    std::vector<int> count(128, -1);
    int start = -1;
    int res = 0;

    for(int i = 0; i < s.size(); i++) {
        if(count[s[i]] > start) {
            start = count[s[i]];
        }
        res = std::max(res, i - start);
        count[s[i]] = i;
    }

    return res;
}


std::vector<std::vector<int>> res;

std::vector<std::vector<int>> subsets(std::vector<int> &nums)
{
    std::vector<int> path;

    dfs(nums, path, 0);

    return res;
}

void dfs(std::vector<int> &nums, std::vector<int> &path, int pos)
{
    res.push_back(path);

    for(int i = 0; i < nums.size(); i++) {
        path.push_back(nums[i]);
        dfs(nums, path, i + 1);
        path.pop_back();
    }

}

std::vector<std::vector<int>> res;

std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    std::vector<int> path;

    dfs(nums, path, 0);

    return res;
}

void dfs(std::vector<int> &nums, std::vector<int> &path, int pos)
{
    res.push_back(path);

    for(int i = pos; i < nums.size(); i++) {
        if(i > pos && nums[i] == nums[i-1]) continue;
        path.push_back(nums[i]);
        dfs(nums, path, i + 1);
        path.pop_back();
    }

}

std::vector<std::vector<int>> res;

std::vector<std::vector<int>> combine(int n, int k)
{
    std::vector<int> path;

    dfs(n, k, 1, path);

    return res;
}

void dfs(int n, int k, int pos, std::vector<int> &path)
{
    if(path.size() == k) {
        res.push_back(path);
        return;
    }

    for(int i = pos; i <= n; i++) {
        path.push_back(i);
        dfs(n, k, i + 1, path);
        path.pop_back();
    }

}

std::vector<std::vector<int>> res;

std::vector<std::vector<int>> permute(std::vector<int> &nums)
{
    dfs(nums, 0);

    return res;
}

void dfs(std::vector<int> &nums, int pos)
{
    if(pos == nums.size()) {
        res.push_back(nums);
        return;
    }

    for(int i = pos; i < nums.size(); i++) {
        std::swap(nums[i], nums[pos]);
        dfs(nums, pos + 1);
        std::swap(nums[i], nums[pos]);
    }

}


void dfs(std::vector<int> &nums, std::vector<int> &path)
{
    if(path.size() == nums.size()) {
        res.push_back(path);
        return;
    }

    for(int i = 0; i < nums.size(); i++) {
        if(find(path.begin(), path.end(), nums[i]) == path.end()) continue;
        path.push_back(nums[i]);
        dfs(nums, path);
        path.pop_back();
    }

}



std::vector<std::vector<int>> res;

void dfs(std::vector<int> nums, int pos);

int lastRemaining(unsigned int n, unsigned int m);

std::vector<std::vector<int>> permute(std::vector<int> &nums)
{
    dfs(nums, 0);

    return res;
}

void dfs(std::vector<int> nums, int pos)
{
    if(pos == nums.size()) {
        res.push_back(nums);
        return;
    }

    for(int i = pos; i < nums.size(); i++) {
        if(i > pos && nums[i] == nums[pos]) continue;
        std::swap(nums[i], nums[pos]);
        dfs(nums, pos + 1);
        // std::swap(nums[i], nums[pos]);
    }

}

int main() {
    unsigned int n = 5, m = 3;

    std::cout << lastRemaining(n, m) << std::endl;

    return 0;
}
/*
int lastRemaining(unsigned int n, unsigned int m)
{
    if(n < 1 || m < 1) return -1;

    unsigned int i = 0;
    std::list<int> numbers;
    for(int i = 0; i < n; i++) {
        numbers.push_back(i);
    }

    std::list<int>::iterator current = numbers.begin();

    while(numbers.size() > 1)
    {
        for(int i = 1; i < m; i++) {
            current++;
            if(current == numbers.end()) current = numbers.begin();
        }

        std::list<int>::iterator next = ++current;
        if(next == numbers.end()) {
            next = numbers.begin();
        }

        --current;
        numbers.erase(current);
        current = next;
    }

    return *current;
}

int lastRemaining(unsigned int n, unsigned int m)
{
    int last = 0;
    for(int i = 2; i <= n; i++) {
        last = (last + m)%i;
    }
    
    return last;
}


ListNode* reverseBetween(ListNode *head, int left, int right)
{
    ListNode *base = new ListNode(-1);
    back->next = head;

    ListNode *first = base, *last = base;

    for(int i = 0; i < right; i++) {
        last = last->next;
    }

    ListNode *lastGroup = last->next;
    last->next = nullptr;

    for(int i = 0; i < left - 1; i++) {
        first = first->next;
    }

    ListNode *fristGroup = first;

    ListNode *reverseList = reverse(first->next);

    ListNode *pNode = fistGroup->next;
    fristGroup->next = reverseList;
    pNode->next = lastGroup;

    return base->next;
}

ListNode *reverse(ListNode *head)
{
    ListNode *prev = nullptr;

    while(head) {
        ListNode *pNext = head->next;
        head->next = prev;
        prev = head;
        head = pNext;
    }

    return prev;
}

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    ListNode *base = new ListNode(-1);
    base->next = head;

    ListNode *first = base, *second = base;

    ListNode *cur = base;

    for(int i = 1; i <= right; i++) {   
        cur = cur->next;
        if(i == left - 1) {
            first = cur;
        }
    }

    second = cur->next;

    ListNode *reverseList = reverse(first->next, second);

    ListNode *pNode = first->next;
    first->next = reverseList;
    pNode->next = second;

    return base->next;
}

ListNode *reverse(ListNode *head, ListNode *tail)
{
    ListNode *prev = nullptr;

    while(head && head != tail) {
        ListNode *pNext = head->next;
        head->next = prev;
        prev = head;
        head = pNext;
    }

    return prev;
}

std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    std::vector<std::vector<int>> res;

    int n = nums.size();

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n-2; i++)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue;

        int target = -nums[i];

        int left = i + 1, right = nums.size() - 1;

        while(left < right)
        {
            if(nums[left] + nums[right] == target) {
                res.push_back({i, left, right});
                while(left < right && nums[left] == nums[left + 1]) left++;
                while(left < right && nums[right] == nums[right -1 ]) right--;
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

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *base = new ListNode(-1);
    base->next = head;

    ListNode *pNode = base;

    while(pNode)
    {
        ListNode *prev = pNode;

        for(int i = 0; i < k; i++) {
            pNode = pNode->next;
            if(pNode == nullptr) return base->next;
        }

        ListNode pNext = pNode->next;

        ListNode *reverseList(prev->next, pNext);

        pNode = prev->next;
        prev->next = reverseList;
        pNode->next = pNext;
    }

    return base->next;
}

ListNode* reverse(ListNode *head, ListNode *tail)
{
    ListNode *prev = nullptr;

    while(head && head != tail)
    {
        ListNode *pNode = head->next;
        head->next = prev;
        prev = head;
        head = pNode;
    }

    return prev;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if(head == nullptr) return nullptr;

    ListNode *base = new ListNode(-1);
    base->next = head;

    ListNode *fast = base, *slow = base;

    for(int i = 0; i < n; i++) {
        fast = fast->next;
        if(fast == nullptr) return nullptr;
    }

    while(fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return base->next;
}


struct Cmp {
    bool operator()(const Node *o1, const Node *o2) {
        return o1.val > o2.val;
    }
};

ListNode* mergeKLists(std::vector<ListNode*> &lists)
{
    std::priority_queue<Node*, std::vector<Node*>, Cmp> pq;

    for(auto & it : lists) {
        pq.push(it);
    }

    ListNode *head = new list(-1);
    ListNode *base = head;

    while(!pq.empty())
    {
        ListNode *pNode = pq.top(); pq.pop();
        base->next = pNode;
        base = base->next;

        if(pNode->next) {
            pq.push(pNode->next);
        } 
    }

    return head->next;
}


ListNode* rotateRight(ListNode *head, int k)
{
    if(head == nullptr) return nullptr;

    int len = 1;
    ListNode *cur = head;
    while(cur->next) {
        len++;
        cur = cur->next;
    }

    cur->next = head;       //首尾相连形成环

    cur = head;
    k = k%len;
    for(int i = 0; i < len-k-1; i++) {
        cur = cur->next;
    }

    ListNode *res = cur->next;
    cur->next = nullptr;        //打破环

    return res;
}

int maxProfit(std::vector<int> &prices)
{
    int profit = INT_MIN;
    int minPrices = INT_MAX;

    for(const int &n : prices) {
        minPrices = std::min(n, minPrices);
        profit = std::max(profit, n - minPrices);
    }

    return profit;
}


int maxProfit(std::vector<int> &prices)
{
    int n = prices.size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = INT_MIN;

    for(int i = 1; i <= n; i++) {
        dp[i][0] = std::max(dp[i-1][0], dp[i-1][1] + prices[i-1]);
        dp[i][1] = std::max(dp[i-1][1], dp[i-1][0] - prices[i-1]);
    }

    return dp[n][0];
}

int maxProfit(std::vector<int> &prices)
{
    int n = prices.size();

    int first = 0, second = INT_MIN;

    for(int i = 1; i <= n; i++) {
        int tmp = first;
        first = std::max(first, second + prices[i-1]);
        second = std::max(second, tmp - prices[i-1]);
    }

    return first;
}


int maxProfit(std::vector<int> &prices);

int main() {
    std::vector<int> prices = {1,2,3,4,5};

    std::cout << maxProfit(prices) << std::endl;

    return 0;
}

int maxProfit(std::vector<int> &prices)
{
    int n = prices.size();

    int dp[n+1][3][2] = {0};
    // memset(dp, 0, sizeof(dp));

    for(int i = 0; i <= n; i++) {
        for(int k = 0; k <= 2; k++) {
            if(i == 0) {
                dp[i][k][1] = INT_MIN;
                continue;
            }
            else if(k == 0) {
                dp[i][k][1] = INT_MIN;
                continue;
            }
            dp[i][k][0] = std::max(dp[i-1][k][0], dp[i-1][k][1] + prices[i-1]);
            dp[i][k][1] = std::max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i-1]);
        }
    }

    return dp[n][2][0];
}


int maxProfit(std::vector<int> &prices, int max_k)
{
    int n = preices.size();
    if(k >= n) {
        return maxProfitUnlimit(prices);
    }

    int dp[n+1][max_k+1][2] = {0};

    for(int i = 0; i <= n; i++) {
        for(int k = 0; k <= max_k; k++) {
            if(i == 0) {
                dp[i][k][1] = INT_MIN;
                continue;
            }
            else if(k == 0) {
                dp[i][k][1] = INT_MIN;
                continue;
            }
            dp[i][k][0] = std::max(dp[i-1][k][0], dp[i-1][k][1] + prices[i-1]);
            dp[i][k][1] = std::max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i-1]);
        }
    }

    return dp[n][max_k][0];
}


int maxProfitUnlimit(const std::vector<int> &prices)
{
    int sum = 0;
    for(int i = 1; i < prices.size(); i++) {
        if(prices[i] > prices[i-1]) {
            sum += prices[i] - prices[i-1];
        }
    }

    return sum;
}

int rand10() {
    int res = INT_MAX;

    while(res > 40) {
        res = 7*(rand7()-1) + rand7();
    }

    return res%10 + 1;
}


int openLock(std::vector<std::string> &deadends, std::string target)
{
    std::unordered_set<std::string> deadSet(deadends.begin(), deadends.end());

    std::unordered_set<std::string> visited;

    std::string start = "0000";

    if(deadSet.count(start)) return -1;

    std::queue<std::string> que;

    que.push(start);
    visited.insert(start);

    int res = 0;

    while(!que.empty())
    {
        for(int size = que.size(); size > 0; size--)
        {
            std::string tmp = que.front();    que.pop();

            if(tmp == target) return res;

            std::vector<std::string> next = rotate(tmp);

            for(const auto &str : next) {
                if(deadSet.count(str)) continue;
                if(visited.count(str)) continue;

                que.push(str);
                visited.insert(str);
            }
        }

        res++;
    }

    return -1;
}


std::vector<std::string> rotate(const std::string &str)
{
    std::vector<std::string> res;

    int n = str.size();

    for(int i = 0; i < 4; i++) 
    {
        std::string tmp = str;

        tmp[i] = (str[i] - '0' + 1)%n + '0';
        res.push_back(tmp);

        tmp[i] = (str[i] - '0' - 1 + n)%n + '0';
        res.push_back(tmp);
    }

    return res;
}


int openLock(std::vector<std::string> &deadends, std::string target)
{
    std::unordered_set<std::string> deadSet(deadends.begin(), deadends.end());
    std::unordered_set<std::string> visited;

    std::unordered_set<std::string> q1, q2, pass;

    std::string start = "0000";

    if(deadSet.count(start) || deadSet.count(target)) return -1;

    q1.insert(start);
    q2.insert(target);

    int res = 0;

    while(!q1.empty() && !q2.empty())
    {
        if(q1.size() > q2.size()) std::swap(q1, q2);
        pass.clear();

        for(auto &cur : q1) 
        {
            for(auto &str : rotate(cur)) {
                if(deadSet.count(str)) continue;
                if(visited.count(str)) continue;

                if(q2.count(str)) return ++res;

                visited.insert(str);
                pass.insert(str);
            }
        }

        q1 = pass;
        res++;
    }    

    return -1;
}

int search(std::vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);

        if(nums[mid] == target) return mid;
        
        //左边数组是有序的
        else if(nums[mid] >= nums[right]) {     //注意:这个等于号放在哪一侧都行,因为存在可能数组中不存在目标,则最后left和righ会肯定指向同一个元素,不加上这个'='就是死循环
            if(nums[left] <= target && target < nums[mid]) right = mid - 1; //目标可能在左边
            else left = mid + 1;
        } 

        //右边数组是有序的
        else if(nums[mid] < nums[right]) {
            if(target > nums[mid] && target <= nums[righ]) left = mid + 1; //目标可能在右边
            else right = mid - 1;
        }
    }
    
    return -1;
}


std::vector<int> searchReange(std::vector<int> &nums, int target)
{
    return {leftBound(nums, target), rightBound(nums, target)};
}

int leftBound(std::vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);

        if(nums[mid] < target) left = mid + 1;
        else if(nums[mid] >= target) right = mid - 1;
    }

    if(left == nums.size() || nums[left] != target) return -1;

    return left;
}


int rightBound(std::vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);

        if(nums[mid] <= target) left = mid + 1;
        else if(nums[mid] > target) right = mid - 1;
    }

    // return right == -1 ? -1 : right;
    if(right == -1 || nums[right] != target) return -1;

    return right;
}

TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root == nullptr || root == p || root == q) return root;

    TreeNode *pLeft = lowestCommonAncestor(root->left, p, q);

    TreeNode *pRight = lowestCommonAncestor(root->right, p, q);

    if(pLeft && pRight) return root;

    return pLeft ? pLeft : pRight;
}

TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root == nullptr) return root;

    if(p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);

    if(p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);

    return root;
}


std::vector<int> res;

std::vector<int> inorderTraversal(TreeNode *root)
{
    dfs(root);

    return res;
}

void dfs(TreeNode *root)
{
    if(root == nullptr) return;

    dfs(root->left);

    res.push_back(root->val);

    dfs(root->right);
}

std::vector<int> inorderTraversal(TreeNode *root)
{
    std::vector<int> res;
    if(root == nullptr) return res;

    std::stack<TreeNode*> sta;
    TreeNode *pNode = root;

    while(!sta.empty() || pNode)
    {
        while(pNode) {
            sta.push(pNode);
            pNode = pNode->left;
        }

        pNode = sta.top();  sta.pop();
        res.push_back(pNode->val);

        pNode = pNode->right;
    }

    return res;
}

std::vector<int> preorderTraversal(TreeNode *root)
{
    std::vector<int> res;
    if(root == nullptr) return res;

    std::stack<TreeNode*> sta;
    sta.push(root);

    while(!sta.empty())
    {
        TreeNode *pNode = sta.top();  sta.pop();
        res.push_back(pNode->val);

        if(pNode->right) {
            sta.push(pNode->right);
        }

        if(pNode->left) {
            sta.push(pNode->left);
        }
    }

    return res;
}


std::vector<int> postorderTraversal(TreeNode *root)
{
    std::vector<int> res;
    if(root == nullptr) return res;

    std::stack<TreeNode*> sta;
    sta.push(root);

    while(!sta.empty())
    {
        TreeNode *pNode = sta.top();    sta.pop();
        res.push_back(pNode->val);
        
        if(pNode->left) {
            sta.push(pNode->left);
        }

        if(pNode->right) {
            sta.push(pNode->right);
        }
    }

    reverse(res.begin(), res.end());
    
    return res;
}

// 假设当前根节点为i,则左子树节点集合为[1..i-1],右子树节点集合为[i+1..n]
// 另gererate(start,end)表示当前值的集合为[start,end]返回序列为[start,end]的二叉搜索树
// generate(start,i-1)生成所有的左子树集合,gererate(i+1,end)生成所有的右子树集合
// 从左右子树中各取一个子树拼接到根节点上即可

std::vector<TreeNode*> gererate(int n)
{
    if(n == 0) return {};

    return gererate(1, n);
}

std::vector<TreeNode*> gererate(int start, int end)
{
    if(start > end) return {nullptr};

    std::vector<TreeNode*> res;

    for(int i = start; i <= end; i++)
    {
        auto leftSet = generate(start, i - 1);
        auto rightSet = generate(i + 1, end);

        TreeNode *root = new TreeNode(i);

        for(auto &left : leftSet) {
            root->left = left;
            for(auto &right : rightSet) {
                root->right = right;
            }
            res.push_back(root);
        }
    }

    return res;
}

int numTrees(int n)
{
    std::vector<int> G(n + 1, 0);
    G[0] = G[1] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            G[i] += G[j-1]*G[i-j];
        }
    }

    return G[n];
}

bool isValidBST(TreeNode *root)
{
    if(root == nullptr) return false;

    TreeNode *prev = nullptr;
    return dfs(root, prev);
}

bool dfs(TreeNode *root, TreeNode *&prev)
{
    if(root == nullptr) return true;

    if(!dfs(root->left, prev)) return false;

    if(prev && prev->val >= root->val) return false;

    prev = root;
    
    return dfs(root->right, prev);
}


bool bfs(std::vector<int> &source, std::vector<int> &target);

// std::queue<std::pair<int,int>> que;
// std::set<std::pair<int,int>> visited;
std::set<std::pair<int,int>> blockedSet;
std::vector<int> dir = {-1, 0, 1, 0, -1};
int maxblocks;

bool isEscapedPossible(std::vector<std::vector<int>> blocked, std::vector<int> &source, std::vector<int> &target)
{
    if(blocked.empty()) return true;

    for(int i = 0; i < blocked.size(); i++) {
        blockedSet.insert({blocked[i][0], blocked[i][1]});
    }

    int n = blocked.size();
    maxblocks = n*(n-1)/2;

    return bfs(source, target) && bfs(target, source);
}

bool bfs(std::vector<int> &source, std::vector<int> &target)
{
    std::queue<std::pair<int,int>> que;
    std::set<std::pair<int,int>> visited;

    que.push({source[0], source[1]});
    visited.insert({source[0], source[1]});

    int steps = 0;

    while(!que.empty())
    {
        for(int size = que.size(); size > 0; size--)
        {
            auto cur = que.front(); que.pop();

            if((cur.first == target[0] && cur.second == target[1]) || steps > maxblocks) return true;

            for(int i = 0; i < dir.size() - 1; i++) {
                int x = cur.first + dir[i], y = cur.second + dir[i+1];
                std::pair<int,int> next = {x, y};
                if(x >= 0 && x < 10e6 && y >= 0 && y < 10e6 && !visited.count(next) && !blockedSet.count(next)) {
                    que.push(next);
                    visited.insert(next);
                }
            }
            steps++;
        }
    }

    return false;
}



int main() {
    std::vector<std::vector<int>> blocked = {{0,3}, {1,0}};
    std::vector<int> soruce = {0,0}, target = {0,2};

    std::cout << isEscapedPossible(blocked, soruce, target) << std::endl;

    return 0;
}



std::vector<int> searchReange(std::vector<int> &nums, int target)
{
    auto item = equal_range(nums.begin(), nums.end(), target);

    if(item.first == nums.end()) {
        return {-1, -1};
    }

    return {(int)(item.first - nums.begin()), (int)((--item.second) - nums.begin())};
}


int main() {
    std::vector<int> nums = {1,1,2};

    auto ivec =  searchReange(nums, 1);

    std::cout << ivec[0] << " " << ivec[1] << std::endl;

    return 0;
} 

bool isValidBST(TreeNode *root)
{
    return isValidBSTCore(root, nullptr, nullptr);
}

bool isValidBSTCore(TreeNode *root, TreeNode *min, TreeNode *max)
{
    if(root == nullptr) return true;

    if(min && root->val <= min->val) return false;
    if(max && root->val >= max->val) return false;

    return isValidBSTCore(root->left, min, root) && isValidBSTCore(root->right, root, max);
}

bool isValidBST(TreeNode *root)
{
    if(root == nullptr) return true;

    std::stack<TreeNode*> sta;
    TreeNode *pNode = root;

    TreeNode *prev = nullptr;

    while(!sta.empty() || pNode)
    {
        while(pNode) {
            sta.push(pNode);
            pNode = pNode->left;
        }

        pNode = sta.top(); sta.pop();

        if(prev && prev->val >= pNode->val) return false;

        prev = pNode;

        pNode = pNode->right;
    }

    return true;
}

TreeNode* invertTree(TreeNode *root)
{
    if(root == nullptr) return root;

    std::swap(root->left, root->right);

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int m_val) : val(m_val) , left(nullptr) , right(nullptr) {}
};


int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    std::cout << root->left->val << " " << root->right->val << std::endl;

    // std::swap(root->left, root->right);
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    std::cout << root->left->val << " " << root->right->val << std::endl;

    return 0;
}

std::vector<int> rightSideView(TreeNode *root)
{
    std::vector<int> res;

    if(root == nullptr) return res;

    dfs(root, 1, res);

    return res;
}


void dfs(TreeNode *root, int depth, std::vector<int> &res)
{
    if(root == nullptr) return;

    if(res.size() < depth) res.push_back(root->val);

    dfs(root->right, depth + 1, res);

    dfs(root->left, depth + 1, res);

}


void bfs(TreeNode *root, std::vector<int> &res)
{
    if(root == nullptr) return ;

    std::queue<TreeNode*> que;
    que.push(root);

    while(!que.empty())
    {
        for(int size = que.size(); size > 0; size--)
        {
            TreeNode *pNode = que.front();  que.pop();
            
            if(size == 1) res.push_back(pNode->val);

            if(pNode->left) que.push(pNode->left);
            if(pNode->right) que.push(pNode->right);
        }
    }

}

int maxDistance = INT_MIN;

int maxPathSum(TreeNode *root)
{
    if(root == nullptr) return 0;

    dfs(root);

    return maxDistance;
}

int dfs(TreeNode *root)
{
    if(root == nullptr) return 0;

    int maxLeft = std::max(0, dfs(root->left));
    int maxRight = std::max(0, dfs(root->right));

    maxDistance = std::max(maxDistance, root->val + maxLeft + maxRight);

    return root->val + std::max(maxLeft, maxRight);
}

int maxDistance = INT_MIN;

int diameterOFBinaryTree(TreeNode *root)
{
    if(root == nullptr) return 0;

    dfs(root);

    return maxDistance;
}

int dfs(TreeNode *root)
{
    if(root == nullptr) return 0;

    int maxLeft = dfs(root->left), maxRight = dfs(root->right);

    maxDistance = std::max(maxDistance, 1 + maxLeft + maxRight);

    return 1 + std::max(maxLeft, maxRight);
}

std::vector<std::string> res;

std::vector<std::string> binaryTreePaths(TreeNode *root)
{
    if(root == nullptr) return res;

    dfs(root, "");

    return res;
}

void dfs(TreeNode *root, std::string path)
{
    if(root == nullptr) return;

    if(root->left == nullptr && root->right == nullptr) {
        path += std::to_string(root->val);
        res.push_back(path);
        return;
    }

    path += std::to_string(root->val) + "->";

    dfs(root->left, path);
    dfs(root->right, path);

}


int dfs(int m, int n, int k, int i, int j, std::vector<std::vector<std::vector<int>>> &dp);


int mod = 1e9 + 7;

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    std::vector<std::vector<std::vector<int>>> dp(maxMove + 1, std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, -1)));

    dp[maxMove][startRow][startColumn] = dfs(m, n, maxMove, startRow, startColumn, dp);

    return dp[maxMove][startRow][startColumn];
}

int dfs(int m, int n, int k, int i, int j, std::vector<std::vector<std::vector<int>>> &dp)
{
    if(i < 0 || i >= m || j < 0 || j >= n) return 1;

    if(k == 0) return 0;

    if(dp[k][i][j] != -1) return dp[k][i][j]%mod;

    int tmp = 0;
        tmp = (tmp + dfs(m, n, k - 1, i + 1, j, dp)) % mod;
        tmp = (tmp + dfs(m, n, k - 1, i - 1, j, dp)) % mod;
        tmp = (tmp + dfs(m, n, k - 1, i, j + 1, dp)) % mod;
        tmp = (tmp + dfs(m, n, k - 1, i, j - 1, dp)) % mod;

    dp[k][i][j] = tmp;

    return dp[k][i][j];
}



int main() {
    int m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1;

    std::cout << findPaths(m, n, maxMove, startRow, startColumn) << std::endl;

    return 0;
}

// dp[i] = dp[i] || dp[i-len], len为单词的长度

bool wordBreak(std::string s, std::vector<std::string> &wordDict)
{
    std::vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= s.size(); i++) {
        for(const auto &word : wordDict) {
            int len = word.size();
            if(i >= len && s.substr(i-len, len) == word) {
                dp[i] = dp[i] || dp[i-len];
            }
        }
    }

    return dp[s.size()];
}

// dp[i][j]代表前i个字符和前j个字符否组成字符串s[0..i+j-1]
// i>=1, j>=1
// s1[i-1] == s3[i+j-1], dp[i][j] = dp[i-1][j]
// s2[j-1] == s3[i+j-1], dp[i][j] = dp[i][j-1]

// base case i = 0, j = 0
// i = 0, j = 0, dp[0][0] = 1
// i = 0, dp[0][j] = dp[0][j-1] && s2[j-1] == s3[i+j-1]

bool isInterleave(std::string s1, std::string s2, std::string s3)
{
    int m = s1.size(), n = s2.size();
    if(m + n != s3.size()) return false;

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 && j == 0) dp[i][j] = 1;
            else if(i == 0) dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1];
            else if(j == 0) dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1];
            else {
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
    }

    return dp[m][n];
}


//BFS搜索,将两个单词看成一个图

bool isInterleave(std::string s1, std::string s2, std::string s3)
{
    int m = s1.size(), n = s2.size();
    if(m + n != s3.size()) return false;

    std::vector<std::vector<int>> visited(m + 1, std::vector<int>(n + 1, 0));
    std::queue<std::pair<int,int>> que;
    que.push({0, 0});
    // visited[0][0] = 1;   //这一行千万不能加

    while(!que.empty())
    {
        auto p = que.front();   que.pop();
        if(p.first == m && p.second == n) return true;

        if(visited[p.first][p.second]) continue;

        if(p.first < m && s1[p.first] == s3[p.first+p.second]) {
            que.push({p.first + 1, p.second});
        }

        if(p.second < n && s2[p.second] == s3[p.first+p.second]) {
            que.push({p.first, p.second + 1});
        }

        visited[p.first][p.second] = 1;
    }

    return false;
}


ListNode* sortList(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *fast = head, *slow = head;
    while(fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode *mid = slow->next;
    slow->next = nullptr;

    return mergerList(sortList(head), sortList(mid));
}

ListNode* mergeList(ListNode *l1, ListNode *l2)
{
    ListNode *head = new ListNode(-1);
    ListNode *base = head;

    while(l1 && l2) 
    {
        if(l1->val < l2->val) {
            base->next = l1->next;
            l1 = l1->next;
        } 
        else {
            base->next = l2->next;
            l2 = l2->next;
        }
        base = base->next;
    }

    if(l1) base->next = l2;
    if(l2) base->next = l1;

    return head->next;
}

bool isUgly(int num)
{
    if(num <= 0) return false;

    while(num%2 == 0) num /= 2;
    while(num%3 == 0) num /= 3;
    while(num%5 == 0) num /= 5;

    return num == 1;
}

int nthUglyNumber(int n)
{
    std::vector<int> res;
    res.push_back(1);
    int i = 0, j = 0, k = 0;

    while(res.size() < n)
    {
        res.push_back(std::min(res[i]*2, std::min(res[j]*3, res[k]*5)));

        if(res.back() == res[i]*2) i++;
        if(res.back() == res[j]*3) j++;
        if(res.back() == res[k]*5) k++;
    }

    return res.back();
}

bool isHappy(int n)
{
    std::set<int> mySet;
    mySet.insert(n);

    while(n != 1)
    {
        int sum = 0;
        while(n) {
            sum += (int)pow(n%10, 2);
            n /= 10;
        }
        n = sum;

        if(mySet.count(n)) return false;

        mySet.insert(n);
    }

    return true;
}

int thridMax(std::vector<int> &nums)
{
    long x, y, z;
    x = y = z = LONG_MIN;

    for(const int &n : nums)
    {
        if(n > z) {
            x = y;
            y = z;
            z = n;
        }
        else if(n > y && n < z) {
            x = y;
            y = n;
        }
        else if(n > x && n < y) {
            x = n;
        }
    }

    return x == LONG_MIN ? z : x;
}


int getSum(int a, int b)
{
    int sum, carry;

    do {
        sum = a^b;
        carry = (a&b)<<1;
        a = sum;
        b = carry;
    } while(b != 0);

    return sum;
}

int findMaxConsectiveOnes(std::vector<int> &nums);

int main() {
    // std::string str = "HeL__loWorLd_";
    
    // std::cout << str << std::endl;

    // std::stringstream in(str);
    // std::string out;
    // std::vector<std::string> strs;

    // int prev = 0;
    // int i = 0;
    // for(; i < str.size(); i++) {
    //     if(isupper(str[i])) {
    //         str[i] = tolower(str[i]);
    //         if(prev != i)
    //             strs.push_back(str.substr(prev, i - prev));
    //         prev = i;
    //     }
    // }
    // strs.push_back(str.substr(prev, i - prev));

    // for(const auto &str : strs) {
    //     std::cout << str << std::endl;
    // }

    // std::string line = "this@ is@ a test string";

    // std::string str = "123456789";

    // std::string tmp = "hello";
    
    // str = str.replace(1, 7, tmp);

    // std::cout << str << std::endl;

    // std::string str = "ABC";
    // std::string des = "ab";

    // str.replace(1, 1, des);

    // std::cout << str << std::endl;

    std::vector<int> nums = {1,1,1,0,1,0,1,1};

    std::cout << findMaxConsectiveOnes(nums) << std::endl;

    return 0;
}

std::string removeDuplicateLetters(std::string s)
{
    std::string res;
    std::vector<int> count(128, 0), visited(128, 0);

    for(const char &c : s) {
        count[c]++;
    }

    for(const char &c : s)
    {
        --count[c];
        if(visited[c]) continue;

        while(!res.empty() && c < res.back() && count[res.back()]) {
            visited[res.back()] = 0;
            res.pop_back();
        }

        res.push_back(c);
    }

    return res;
}


//Leetcode第487题：最多翻转一个0

int findMaxConsectiveOnes(std::vector<int> &nums)
{
    int left = 0, right = 0;
    int maxLen = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 1) right++;
        else if(nums[i] == 0) {
            left = right + 1;
            right = 0;
        } 

        maxLen = std::max(maxLen, left + right);
    }
    
    return maxLen;
}


void moveZeros(std::vector<int> &nums)
{
    int i = 0;

    for(int j = 0; j < nums.size(); j++) {
        if(nums[j]) std::swap(nums[i++], nums[j]);
    }

}


bool isSubsequence(std::string s, std::string t)
{
    if(s.size() > t.size()) return false;

    int i = 0;

    for(int j = 0; j < t.size(); j++) {
        if(s[i] == t[j]) i++;
    }

    return i == s.size();
}

std::vector<int> sortArrayByParity(std::vector<int> &A)
{
    int i = 0;

    for(int j = 0; j < A.size(); j++) {
        if((A[j]&1) == 0) std::swap(A[i++], A[j]);
    }

    return A;
}

std::vector<int> sortArrayByParity(std::vector<int> &A)
{
    if(A.size() == 1) return A;

    for(int i = 0; i < A.size() - 1; i++)
    {
        while(i >= 0 && (A[i]&1) == 1 && (A[i+1]&1) == 0) {
            std::swap(A[i], A[i+1]);
            i--;
        }
    }

    return A;
}

std::vector<int> sortArrayByParity(std::vector<int> &A)
{
    int i = 0, j = A.size() - 1;

    while(i < j)
    {
        //找到左边第一个奇数
        while(i < j && (A[i]&1) == 0) i++;

        //找到右边第一个偶数
        while(i < j && (A[j]&1) == 1) j--;

        if(i < j) {
            std::swap(A[i], A[j]);
            i++;    j--;
        }
    }

    return A;
}


int findMaxConsectiveOnes(std::vector<int> &nums)
{
    int count = 0;
    int maxLen = 0;

    for(const int &n : nums) {
        if(n == 1) maxLen = std::max(maxLen, ++count);
        else count = 0;
    }

    return maxLen;
}

int longestOnes(std::vector<int> &nums, int k)
{
    int count = 0, maxLen = 0;

    for(int i = 0, j = 0; j < nums.size(); j++)
    {
        if(nums[j] == 0) count++;

        while(count > k) {
            if(nums[i] == 0) count--;
            i++;
        }

        maxLen = std::max(maxLen, j - i + 1);
    }

    return maxLen;
}

TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root == nullptr || root == p || root == q) return root;

    TreeNode *pLeft = lowestCommonAncestor(root->left, p, q);

    TreeNode *pRight = lowestCommonAncestor(root->right, p, q);

    if(pLeft && pRight) return root;

    return pLeft ? pLeft : pRight;
}



int pathSum(TreeNode *root, int target)
{
    if(root == nullptr) return 0;

    return dfs(root, target) + pathSum(root->left, target) + pathSum(root->right, target);
}

int dfs(TreeNode *root, int target)
{
    if(root == nullptr) return 0;

    int count = (root->val == target ? 1 : 0);

    return count += dfs(root->left, target - root->val) + dfs(root->right, target - root->val);
}

int maxDistance = 0;

int diameterOFBinaryTree(TreeNode *root)
{
    dfs(root);

    return maxDistance;
}

int dfs(TreeNode *root)
{
    if(root == nullptr) return 0;

    int leftLen = dfs(root->left);
    int rightLen = dfs(root->right);

    maxDistance = std::max(maxDistance, leftLen + rightLen);

    return 1 + std::max(leftLen, rightLen);
}

bool isValidBST(TreeNode *root)
{
    return isValidBSTCore(root, nullptr, nullptr);
}

bool isValidBSTCore(TreeNode *root, TreeNode *min, TreeNode *max)
{
    if(root == nullptr) return true;

    if(min && root->val <= min->val) return false;
    if(max && root->val >= max->val) return false;

    return isValidBSTCore(root->left, min, root) && isValidBSTCore(root->right, root, max);
}




double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
{
    if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

    int m = nums1.size(), n = nums2.size();

    int left = 0, right = m;

    while(left <= right)
    {
        int i = (left + right) / 2;
        int j = (m + n + 1) / 2 - i;

        int maxLeftX = (i == 0 ? INT_MIN : nums1[i-1]);
        int minRightX = (i == m ? INT_MAX : nums1[i]);

        int maxLeftY = (j == 0 ? INT_MIN : nums2[j-1]);
        int minRightY = (j == n ? INT_MAX : nums2[j]);

        if(maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if((m+n)%2 == 0) return (std::max(maxLeftX, maxLeftY) + std::min(minRightX, minRightY)) / 2.0;
            else return std::max(maxLeftX, maxLeftY);
        }
        else if(maxLeftX > minRightY) {
            right = i - 1;
        }
        else {
            left = i + 1;
        }
    }

    return -1;
}

int main() {
    std::vector<int> nums1 = {1,2}, nums2 = {3,4};

    std::cout << findMedianSortedArrays(nums1, nums2) << std::endl;

    return 0;
}


bool exist(std::vector<std::vector<char>> &board, std::string word)
{
    int m = board.size(), n = board.size();
    if(m == 0 || n == 0) return false;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == word[0]) {
                if(dfs(board, i, j, word, 0)) return true;
            }
        }
    }

    return false;
}

bool dfs(std::vector<std::vector<char>> &board, int i, int j, std::string &word, int pos)
{
    if(pos == word.size()) return true;

    int m = board.size(), n = board[0].size();

    if(i < 0 || i >= m || j < 0 || j >= m || word[pos] != board[i][j]) return false;

    char c = word[pos];
    word[pos] = '#';

    bool find =  dfs(board, i + 1, j, word, pos + 1) ||  dfs(board, i - 1, j, word, pos + 1)
                ||dfs(board, i, j - 1, word, pos + 1) || dfs(board, i, j + 1, word, pos + 1);

    word[pos] = c;

    return find;
}

bool exist(std::vector<std::vector<char>> &board, std::string word)
{    
    int m = board.size(), n = board[0].size();
    if(m == 0 || n == 0 || word.empty()) return false;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == word[0] && dfs(board, i, j, word, 0)) {
                return true;
            }
        }
    }

    return false;
}

std::vector<int> dir = {-1, 0, 1, 0, -1};

bool dfs(std::vector<std::vector<char>> &board, int i, int j, std::string &word, int pos)
{
    int m = board.size(), n = board[0].size();

    if(pos == word.size() -1 ) return true;

    board[i][j] = '#';

    bool find = false;

    for(int k = 0; k < dir.size() - 1; k++) 
    {
        int x = i + dir[k], y = j + dir[k+1];

        if(x >= 0 && x < m && y >= 0 && y < n && board[x][y] == word[pos+1]) {
            find = find || dfs(board, x, y, word, pos + 1);
        }
    }

    board[x][y] = word[pos];

    return find;
}


int longestIncreasingPath(std::vector<std::vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    if(m == 0 || n == 0) return 0;

    std::vector<std::vector<int>> memcache(m, std::vector<int>(n, 0));

    int maxLen = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            maxLen = std::max(maxLen, find(matrix, i, j, memcache));
        }
    }

    return maxLen;
}

std::vector<int> dir = {-1, 0, 1, 0, -1};

int find(std::vector<std::vector<int>> &matrix, int i, int j, std::vector<std::vector<int>> &memcache)
{
    int m = matrix.size(), n = matrix[0].size();

    if(memcache[i][j]) return memcache[i][j];

    int maxLen = 1;

    for(int k = 0; k < dir.size() - 1; k++) 
    {
        int x = i + dir[k], y = j + dir[k+1];
        if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] < matrix[i][j]) {
            maxLen = std::max(maxLen, 1 + find(matrix, x, y));
        }
    }

    memcache[i][j] = maxLen;

    return maxLen;
}



struct Node {
    int x;
    int len;
    Node(int m_x, int m_len) : x(m_x), len(m_len) {} 

    bool operator<(const Node &demo) const {
        return len > demo.len;
    }

};

// struct Cmp {
//     bool operator()(const Node &a, const Node &b) {
//         return a.len > b.len;
//     }
// };

// bool compare(const Node &a, const Node &b) {
//     return a.len > b.len;
// }

int main() {
    std::vector<Node> nums;
    nums.push_back(Node(2,1));
    nums.push_back(Node(1,3));
    
    sort(nums.begin(), nums.end());

    for(auto &demo : nums) {
        std::cout << demo.len << std::endl;
    }


    return 0;
}


void dfs(std::vector<int> &nums, int pos);

std::vector<std::vector<int>> res;

std::vector<std::vector<int>> permute(std::vector<int> &nums)
{
    dfs(nums, 0);

    return res;
}

void dfs(std::vector<int> &nums, int pos)
{
    if(pos == nums.size()) res.push_back(nums);

    for(int i = pos; i < nums.size(); i++) 
    {
        std::swap(nums[pos], nums[i]);
        dfs(nums, pos + 1);
        std::swap(nums[pos], nums[i]);
    }

}


int main() {
    std::vector<int> nums = {1,2,3};

    permute(nums);

    for(int i = 0; i < res.size(); i++) {
        for(int &n : res[i]) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

std::string shortestPalindrome(std::string s)
{
    int i = 0;

    int maxLen = 0;

    while(i <= s.size()/2)
    {
        int start = i, end = i;
        while(end + 1 < s.size() && s[end] == s[end+1]) end++;
        i = end + 1;

        while(start - 1 >= 0 && end + 1 < s.size() && s[start-1] == s[end+1]) {
            start--;
            end++;
        }

        if(start == 0) {
            maxLen = std::max(maxLen, end - start + 1);
        }
    }

    std::string remain = s.substr(maxLen);
    reverse(remain.begin(), remain.end());

    return reamin + s;
}


//Leetcode第1312题：将字符串组成回文串的最少插入操作

//思路：1.判断原来的字符串有多少个回文字符，将总字符数减去回文字符数即为结果
//     2.利用两个字符串的最长公共子序列来判断原来字符串的回文字符个数


int minInsertions(std::string s)
{
    int n = s.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

    std::string s1 = s;
    reverse(s1.begin(), s1.end());

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == s1[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return n - dp[n][n];
}

TreeNode *pFirst = nullptr, *pSecond = nullptr;

void recoverTree(TreeNode *root)
{
    TreeNode *prev = nullptr;
    
    dfs(root, prev);

    if(pFirst && pSecond) std::swap(pFirst->val, pSecond->val);
}

void dfs(TreeNode *root, TreeNode * &prev)
{
    if(root == nullptr) return;

    dfs(root->left, prev);

    if(prev && prev->val >= root->val) {
        if(pFirst == nullptr) pFirst = prev;
        pSecond = root;
    }

    prev = root;

    dfs(root->right, prev);
}

std::vector<std::vector<std::string>> res;

std::vector<std::vector<std::string>> solveQueens(int n)
{
    std::vector<int> row(n, 0), col(n, 0), leftDiag(2*n-1, 0), rightDiag(2*n-1, 0);

    std::vector<std::string> map(n, std::string(n, '.'));

    dfs(map, 0, row, col, leftDiag, rightDiag);

    return res;
}

void dfs(std::vector<std::string> &map, int index, std::vector<int> &row, std::vector<int> &col, std::vector<int> &leftDiag, std::vector<int> &rightDiag, int n)
{
    if(index == n) {
        res.push_back(map);
        return;
    }

    for(int j = 0; j < n; j++)
    {
        if(!row[index] && ! col[j] && !leftDiag[index + j] && !rightDiag[index + (n-1) - j])
        {
            map[index][j] = 'Q';
            row[index] = col[j] = leftDiag[index+j] = rightDiag[index + (n-1) -j] = 1;

            dfs(map, index + 1, row, col, leftDiag, rightDiag, n);

            map[index][j] = '.';
            row[index] = col[j] = leftDiag[index+j] = rightDiag[index + (n-1) -j] = 0;
        }
    }

}

// sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i-1][j-1]
// sum[row2][col2] - sum[row2][col-1] - sum[row1-1][col2] + sum[row1-1][col1-1]

std::vector<std::vector<int>> sum;

NumMatrix(std::vector<std::vector<int>> &matirx)
{
    int m = matirx.size(), n = matirx[0].size();

    sum = std::vector<std::vector<int>> (m + 1, std::vector<int>(n + 1, 0));

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i-1][j-1];
        }
    }

}


int sumRegion(int row1, int col1, int row2, int col2)
{
    return sum[row2+1][col2+1] - sum[row2+1][col1] - sum[row1][col2+1] + sum[row1][col1];
}

/*

// dp[i][j] = dp[i-1][j] , j < nums[i]
// dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i]] + val[i]), j >= nums[i]

int maxProfit(std::vector<int> &wt, std::vector<int> &val, int count)
{
    int n = wt.size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(count + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= count; j++) {
            if(j < wt[i-1]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-wt[i-1]] + val[i-1]);
            }
        }
    }

    int res = dp[n][count];

    //返回选中的单元数
    std::vector<int> select;
    int i = n, j = count;
    while(i > 0 && j > 0)
    {
        if(dp[i][j] == dp[i-1][j]) i--;    //表示第i个物品肯定没选中
        else {
            select.push_back(wt[i-1]);
            j -= wt[i-1];               //减去第i个物品的体积之后将i减1，表示剔除掉第i个物品
            i--;
        }   
    }

    for(const int &n : select) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return res;
}


int maxProfit(std::vector<int> &wt, std::vector<int> &val, int count)
{
    int n = wt.size();
    std::vector<int> dp(count + 1, 0);

    for(int i = 0; i < n; i++) {
        for(int j = count; j >= wt[i]; j--) {
            dp[j] = std::max(dp[j], dp[j-wt[i]] + val[i]);
        }
    }   

    return dp[count];
}


int main() {
    // std::vector<int> wt = {1,3,4,5}, val = {1,4,5,7};
    // int count = 7;

    // std::cout << maxProfit(wt, val, count) << std::endl;

    // int i = 0;
    // const int &ci = i;

    // auto b = ci;
    // b = 100;

    // std::cout << ci << std::endl;

    // const int i = 10;
    // int * const p = new int(10);
    // int *p = &i;
    // auto a = i;

    // a = 100;

    int *const p = new int(10);
    int n = 100;

    auto ptr = p;

    p = &n;

    // std::cout << *ptr << std::endl;

    // auto a = i;
    // a = 10;

    // int b = 100;
    // p = &b;

    // auto b = p;
    // b = &i;

    return 0;
}




std::vector<int> findClosestElements(std::vector<int> &arr, int k, int x)
{
    std::vector<int> res;

    auto pos = lower_bound(arr.begin(), arr.end(), x);

    if(pos == arr.begin()) {
        for(int i = 0; i < k; i++) {
            res.push_back(arr[i]);
        }
    }
    else if(pos == arr.end())
    {
        for(int i = arr.size()-1; i >= arr.size()-k; i--) {
            res.push_back(arr[i]);
        }
    }
    else 
    {
        int i, j;
        int count = 0;

        if(*pos == x) {
            res.push_back(*pos);     
            k--
            i = pos - arr.begin() - 1;
            j = pos - arr.begin() + 1;       
        }
        else { 
            i = pos - arr.begin() - 1;
            j = i + 1;
        }


        while(i >= 0 && j < arr.size() && k > 0)
        {
            if(abs(arr[i] - x) <= abs(arr[j] - x)) {
                res.push_back(arr[i--]);
            }
            else {
                res.push_back(arr[j++]);
            }
            k--;
        }   

        while(k > 0 && i >= 0) {
            res.push_back(arr[i--]);
            k--;
        }

        while(k > 0 && j < arr.size()) {
            res.push_back(arr[j++]);
            k--;
        }
    }

    sort(res.begin(), res.end());

    return res;
}


int main() {
    std::vector<int> nums = {0,0,1,2,3,3,4,7,7,8};
    int k = 3, x = 5;

    std::vector<int> res = findClosestElements(nums, k, x);

    for(const int &n : res) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    return 0;
}


//Leetcode第628题：在有序数组中寻找最接近x的k个数字

//解法一：
//双指针法：时间复杂度O(n)

std::vector<int> findClosestElements(std::vector<int> &arr, int k, int x)
{
    int left = 0, right = arr.size() - 1;

    while(right - left >= k)
    {
        //缩小范围
        if(abs(arr[left] - x) > abs(arr[right] - x)) {  //说明此时right离x更近，向右移动left
            left++;
        }
        else right--;
    }

    std::vector<int> res;
    for(int i = left; i <= right; i++) {
        res.push_back(arr[i]);
    }

    return res;
}

//解法二：二分查找
// [0, n-k]之内查找
// 1. x - A[mid] < A[mid+k] - x;    右边界左移         
// ------x----A[mid]---------A[mid+k]----
// 2. x - A[mid] < A[mid+k] - x;    右边界左移
// ---A[mid]----x---------A[mid+k]------
// 3. x - A[mid] > A[mid+k] - x;    左边界右移
// ---A[mid]---------x----A[mid+k]------
// 4. x - A[mid] > A[mid+k] - x;    左边界右移
// ---A[mid]--------------A[mid+k]--x---


std::vector<int> findClosestElements(std::vector<int> &nums, int k, int x)
{
    int left = 0, right = nums.size() - k;

    while(left < right)
    {
        int mid = left + ((right - left) >> 1);

        if(x - nums[mid] > nums[mid+k] - x) {
            left = mid + 1;
        }
        else right = mid;
    }

    return std::vector<int>(nums.begin() + left, nums.begin() + left + k);
}


//Leetcode第134题：找到起始出发的加油站

//思路:如果A不能到达B,则A与B之间的所有加油站出发都不能到达B，所以我们将起点重置为B即可

int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost)
{
    int total = 0;
    int start = 0;
    int tank = 0;
    for(int i = 0; i < gas.size(); i++) 
    {
        int consume = gas[i] - cost[i];
        tank += consume;
        total += consume;
        if(tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }

    //total小于0表示任何起点出发都不能到达
    return total < 0 ? -1 : start;
}



int maxSubarrySumNoMoreThanK(std::vector<int> &nums, int k);

int maxSumSubmatrix(std::vector<std::vector<int>> &matrix, int k)
{
    if(matrix.empty()) return 0;

    int row = matrix.size(), col = matrix[0].size();
    int res = INT_MIN;

    for(int left = 0; left < col; left++)
    {
        std::vector<int> sums(row, 0);
        for(int right = left; right < col; right++)
        {
            for(int i = 0; i < row; i++) {
                sums[i] += matrix[i][right];
            }

            //在sums中找到最大的子数组和
            res = std::max(res, maxSubarrySumNoMoreThanK(sums, k));
        }
    }

    return res;
}


int maxSubarrySumNoMoreThanK(std::vector<int> &nums, int k)
{
    std::set<int> mySet;
    mySet.insert(0);

    int res = INT_MIN, sum = 0;

    for(const int &n : nums) 
    {
        sum += n;;
        auto it = mySet.lower_bound(sum - k);
        if(it != mySet.end()) res = std::max(res, sum - *it);
        mySet.insert(sum);
    }

    return res;
}


int main() {
    // std::vector<std::vector<int>> nums = {{1,0,1}, {0,-2,3}};
    int k = 2;

    std::vector<int> nums = {1,1};

    std::cout << maxSubarrySumNoMoreThanK(nums, k) << std::endl;

    return 0;
}



void dfs(std::string &s, int count, int pos, std::string path);

std::vector<std::string> res;

std::vector<std::string> restoreIpAddresses(std::string s)
{
    dfs(s, 0, 0, "");

    return res;
}

void dfs(std::string &s, int count, int pos, std::string path)
{
    if(count == 4 && pos == s.size()) {
        path.pop_back();
        res.push_back(path);
        return;
    }

    for(int i = 1; i <= 3 && i + pos <= s.size(); i++)
    {
        std::string tmp = s.substr(pos, i);
        if(i != 1 && tmp[0] == '0') return;     //该字符串不合法

        if(std::stoi(s.substr(pos, i)) <= 255) {
            dfs(s, count + 1, pos + i, path + tmp + ".");
        }
    }

}


int main() {
    std::string s = "25525511135";

    // std::vector<std::string> res = restoreIpAddresses(s);
    restoreIpAddresses(s);

    for(auto &str : res) {
        std::cout << str << " ";
    }
    std::cout << std::endl;


    return 0;
}


std::vector<std::string> res;

std::vector<std::string> removeInvalidParentheses(std::string s)
{
    int left = 0, right = 0;
    for(const char &c : s) {
        if(c == '(') {
            left++;
        }
        else if(c == ')') {
            if(left == 0) right++;
            else left--; 
        }
    }

    dfs(s, left, right, 0);

    return res;
}


void dfs(std::string s, int left, int right, int pos)
{
    if(left < 0 || right < 0) return false;     //减枝

    if(left == 0 && right == 0) {
        if(isValid(s)) {
            res.push_back(s);
            return;
        }
    }

    for(int i = pos; i < s.size(); i++)
    {
        if(i > pos && s[i] == s[i-1]) continue;     // 比如 "((())", 前面连续的"((("只需要删除第一个就行，不需要三个都尝试删除下

        if(s[i] == '(') {
            dfs(s.substr(0, i) + s.substr(i + 1), left - 1, right, i);  //注意：这里的i不能进位，因为删除后i恰好指向下一个新的字符了
        }
        else if(s[i] == ')') {
            dfs(s.substr(0, i) + s.substr(i + 1), left, right - 1, i);
        }
    }

}

bool isValid(const std::string &s)
{
    int left = 0;

    for(const char &c : s) {
        if(c == '(') left++;
        else if(c == ')') {
            if(left == 0) return false;
            else left--;
        }
    }

    return left == 0;
}


int trap(std::vector<int> &height)
{
    int res = 0;
    std::stack<int> sta;

    for(int i = 0; i < height.size(); i++)
    {
        while(!sta.empty() && height[i] > height[sta.top()]) {
            int midIndex = sta.top();   sta.pop();

            if(!sta.empty()) {
                int hei = std::min(height[i], height[sta.top()]) - height[minIndex];
                int wide = i - sta.top() - 1;
                res += hei * wide;
            }
        }

        sta.push(i);
    }

    return res;
}

std::vector<int> dailyTemperatures(std::vector<int> &T)
{
    std::stack<int> sta;

    std::vector<int> res(T.size(), 0);

    for(int i = 0; i < T.size(); i++)
    {
        while(!sta.empty() && T[i] > T[sta.top()]) {
            res[sta.top()] = i - sta.top();
            sta.pop();
        }

        sta.push(i);
    }

    return res;
}

int longestValidParentheses(std::string s)
{
    int res = 0;
    std::stack<int> sta;
    sta.push(-1);

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(') {
            sta.push(i);
        }
        else {
            sta.pop_back();

            if(sta.empty()) {
                sta.push(i);
            }

            res = std::max(res, i - sta.top());
        }
    }

    return res;
}

int coinChange(std::vector<int> &coins, int amount)
{
    int n = coins.size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(amount + 1, amount + 1));

    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= amount; j++) {
            if(j < coins[i-1]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = std::min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
        }
    }
    
    return dp[n][amount] == amount + 1 ? -1 : dp[n][amount];
}


int coinChange(std::vector<int> &coins, int amount)
{
    int n = coins.size();

    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for(int i = 0; i < coins.size(); i++) {
        for(int j = 1; j <= amount; j++) {
            if(j >= coins[i]) dp[j] = std::min(dp[j], dp[j-coins[i]] + 1);
        }
    }

    return dp[amount] == amount + 1 ? -1 : dp[amount];
}


const int N = 1e9 + 7;

int countVowelPermutation(int n)
{
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(6, 0));

    for(int i = 1; i <= 5; i++) {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++)
    {
        dp[i][1] = (dp[i-1][2] + dp[i-1][3] + dp[i-1][5]) % N;
        dp[i][2] = (dp[i-1][1] + dp[i-1][3]) % N;;
        dp[i][3] = (dp[i-1][2] + dp[i-1][4]) % N;
        dp[i][4] = (dp[i-1][3]) % N;
        dp[i][5] = (dp[i-1][3] + dp[i-1][4]) % N;
    }

    return accumulate(dp[n].begin(), dp[n].end(), 0) % N;
}

int main() {
    int n = 158;

    std::cout << countVowelPermutation(n) << std::endl;

    return 0;
}


int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList)
{
    std::unordered_set<std::string> mySet(wordList.begin(), wordList.end());
    std::queue<std::string> que;

    if(!mySet.count(endWord)) return 0;

    que.push(beginWord);
    int steps = 1;

    while(!que.empty())
    {
        for(int size = que.size(); size > 0; size--)
        {
            std::string cur = que.front(); que.pop();
            if(cur == endWord) return steps;

            //将出队列的元素从集合中剔除出去,因为该元素已经判断过了
            dict.erase(cur);

            for(int j = 0; j < cur.size(); j++)
            {
                char c = cur[j];
                for(int k = 0; k < 26; k++) {
                    cur[j] = 'a' + k;
                    if(mySet.count(cur)) que.push(cur);  //改变的字符在集合中就将其加入到队列中                  
                }
                cur[j] = c;     //恢复回来判断下一个字符
            }
        }

        steps++;
    }

    return 0;
}


//双向BFS搜索

int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList)
{
    std::unordered_set<std::string> beginSet, endSet;

    //这个一定要判断，下面没有判断这个特殊例子
    if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;

    int steps = 1;
    std::unordered_set<std::string> visited;

    beginSet.insert(beginWord);
    endSet.insert(endWord);

    while(!beginSet.empty() && !endSet.empty())
    {
        //注意：让begin集合始终为元素少的集合，这样可以加快搜索
        if(beginSet.size() > endSet.size()) {
            std::swap(beginSet, endSet);
        }

        std::unordered_set<std::string> tmp;

        for(auto &cur : beginSet)
        {
            std::string word = cur;                 //集合中的元素是const类型的，不允许修改
            for(int j = 0; j < word.size(); j++) 
            {
                char c = word[j];
                for(int k = 0; k < 26; k++) {
                    word[j] = 'a' + k;

                    if(endSet.count(word)) return steps + 1;

                    //如果这个新单词没有被遍历过并且属于原来的单词集合，则加入到tmp中
                    if(!visited.count(word) && find(wordList.begin(), wordList.end(), word) != wordList.end()) {
                        tmp.insert(word);
                        visited.insert(word);
                    }
                }
                word[j] = cur;
            }
        }

        beginSet = tmp;     //将开始集合赋值为新的集合
        steps++;
    }

    return 0;
}
//1.链表首尾相连接
//2.pre移动(len-k-1)
//3.返回pre->next,并将pre->next置空

ListNode* rotateRight(ListNode *head, int k)
{
    if(head == nullptr || head->next == nullptr || k == 0) return head;

    ListNode *pre = head, *tail = head;
    int len = 1;
    while(tail->next) {
        len++;
        tail = tail->next;
    }

    tail->next = head;

    k %= len;

    for(int i = 0; i < len - k - 1; i++) {
        pre = pre->next;
    }

    ListNode *res = pre->next;
    pre->next = nullptr;

    return res;
}


int compareVersion(std::string version1, std::string version2)
{
    std::stringstream in1(version1);
    std::stringstream in2(version2);

    std::string out;
    
    std::vector<std::string> nums1;
    std::vector<std::string> nums2;

    while(getline(in1, out, '.')) {
        nums1.push_back(std:stoi(out));
    }

    while(getline(in2, out, '.')) {
        nums2.push_back(std::stoi(out));
    }

    int i = 0, j = 0;
    while(i < nums1.size() && j < nums2.size())
    {
        if(nums1[i] > nums2[j]) return 1;
        else if(nums1[i] < nums2[j]) return -1;
        i++;
        j++;
    }

    if(i == nums1.size() && j == nums2.size()) return 0;
    else if(i == nums1.size()) return 1;

    return -1;
}

ListNode* partition(ListNode *head, int x)
{
    ListNode *l1 = new ListNode (-1);
    ListNode *l2 = new ListNode (-1);
    ListNode *l1Head = l1;
    ListNode *l2Head = l2;

    while(head)
    {
        if(head->val < x) {
            l1->next = head;
            l1 = l1->next;
        }
        else {
            l2->next = head;
            l2 = l2->next;
        }
        head = head->next;
    }

    l1->next = l2Head->next;
    l2->next = nullptr;

    return l1Head->next;
}

struct Cmp {
    bool operator()(const ListNode *demo1, const ListNode *demo2) {
        return demo1->val > demo2->val;
    }
};


ListNode *mergeKList(std::vector<ListNode*> lists)
{
    std::priority_queue<ListNode*, std::vector<ListNode*>, Cmp> pq;

    for(auto &node : lists) {
        if(node) pq.push(node);
    }

    ListNode *head = new ListNode(-1);
    ListNode *base = head;

    while(!pq.empty())
    {
        ListNode *pNode = pq.top(); pq.pop();
        base->next = pNode;
        base = base->next;

        if(pNode->next) pq.push(pNode->next);
    }

    return head->next;
}

ListNode* reverseKGroup(ListNode *head, int k)
{
    if(head == nullptr || head->next == nullptr || k <= 0) return head;

    ListNode* base = new ListNode(-1);
    base->next = head;

    ListNode *pNode = base;

    while(pNode)
    {
        ListNode *prev = pNode;

        int i = 0;
        for(; i < k; i++) {
            pNode = pNode->next;
            if(pNode == nullptr) break;
        }

        if(i == k) {
            ListNode *tail = pNode->next;

            ListNode *reverseList = reverse(prev->next, tail);

            pNode = prev->next;
            prev->next = reverseList;
            pNode->next = tail;
        }
    }

    return base->next;
}

ListNode *reverseList(ListNode *head, ListNode *tail)
{
    ListNode *prev = nullptr;

    while(head != tail)
    {
        ListNode *pNext = head->next;
        head->next = prev;
        prev = head;
        head = pNext;
    }

    return prev;
}

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if(head == nullptr || head->next == nullptr || left == right) return head;

    ListNode *base = new ListNode(-1);
    base->next = head;
    ListNode *cur = base;

    ListNode *prev = nullptr, *tail = nullptr;

    for(int i = 0; i <= right; i++)
    {
        if(i == left-1) prev = cur;
        if(i == right) tail = cur->next;

        cur = cur->next;
    }

    ListNode *reverseList = reverse(prev->next, tail);

    ListNode *pNode = prev->next;
    prev->next = reverseList;
    pNode->next = tail;

    return base->next;
}


double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
{
    int m = nums1.size(), n = nums2.size();
    if(m > n) return findMedianSortedArrays(nums2, nums1);

    int left = 0, right = m;
    while(left <= right)
    {
        int i = (left + right) / 2;
        int j = (m + n + 1)/2 - i;

        int maxLeftX = (i == 0 ? INT_MIN ? nums1[i-1]);
        int minRightX = (i == m ? INT_MAX ? nums1[i]);

        int maxLeftY = (j == 0 ? INT_MIN ? nums2[j-1]);
        int minRightY = (j == n ? INT_MAX ? nums2[j]);

        if(maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if((m+n)%2 == 0) return (std::max(maxLeftX, maxLeftY) + std::min(minRightX, minRightY)) / 2.0;
            else return std::max(maxLeftX, maxLeftY);
        }
        else if(maxLeftX > minRightY) {
            right = i -1;
        }
        else if(maxLeftY > minRightX) {
            left = i + 1;
        }
    }

    return -1;
}


int row[9][9];
int col[9][9];
int block[9][9];

void solveSudoKu(std::vector<std::vector<char>> &board)
{
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(block, 0, sizeof(block));

    //标记已经存在数字的行和列以及块
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(board[i][j] != '.') {
                int n = board[i][j] - '1';
                int k = (i/3)*3 + j/3;
                row[i][n] = col[j][n] = block[k][n] = 1;
            }
        }
    }

    //从第一行开始搜索
    dfs(board, 0, 0);

}

bool dfs(std::vector<std::vector<char>> &board, int i, int j)
{
    if(i == 9) return true;
    else if(j == 9) {
        return dfs(board, i + 1, 0);
    }
    
    if(board[i][j] != '.') {
        return dfs(board, i, j + 1);
    }

    for(int n = 0; n < 9; n++)
    {
        int k = (i/3)*3 + j/3;
        if(!row[i][n] && !col[j][n] && !block[k][n]) 
        {
            board[i][j] = n + '1';
            row[i][n] = col[j][n] = block[k][n] = 1;
            
            if(dfs(board, i, j + 1)) return true; 

            board[i][j] = '.';
            row[i][n] = col[j][n] = block[k][n] = 0;
        }
    }

    return false;
}

int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList)
{
    std::unordered_set<std::string> mySet(wordList.begin(), wordList.end());

    if(!mySet.count(endWord)) return 0;

    int steps = 0;
    std::queue<std::string> que;
    que.push(beginWord);

    while(!que.empty())
    {
        for(int size = que.size(); size > 0; size--)
        {
            auto word = que.front(); que.pop();

            if(word == endWord) return steps;

            //逐个尝试改变单词每个字符
            for(int i = 0; i < word.size(); i++)
            {
                char c = word[i];
                for(int k = 0; k < 26; k++) {
                    word[i] = k + 'a';
                    if(mySet.count(word)) {
                        que.push(word);
                        mySet.erase(word);
                    }
                }
                word[i] = c;    //改变回来继续判断下一个单词
            }
        }
        
        steps++;
    }

    return 0;
}


int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList)
{
    std::unordered_set<std::string> beginSet, endSet, visited, wordSet(wordList.begin(), wordList.end());

    int steps = 1;

    if(!wordSet.count(endWord)) return 0;

    beginSet.insert(beginWord);
    endSet.insert(endWord);

    while(!beginSet.empty() && !endSet.empty())
    {
        if(beginSet.size() > endSet.size()) {
            std::swap(beginSet, endSet);
        }

        std::unordered_set<std::string> tmp;
        for(auto &cur : beginSet) 
        {
            std::string word = cur;
            for(int i = 0; i < word.size(); i++)
            {
                char c = word[i];
                for(int k = 0; k < 26; k++) 
                {
                    word[i] = k + 'a';
                    if(endSet.count(word)) return steps + 1;
                    if(!visited.count(word) && wordSet.count(word)) {
                        tmp.insert(word);
                        visited.insert(word);
                    }
                }
                word[i] = c;
            }
        }

        beginSet = tmp;
        steps++;
    }

    return 0;
}


bool isValid(std::string s)
{
    if(s.empty()) return true;

    std::stack<char> sta;

    for(const char &c : s)
    {
        switch (c) {
            case '(' :
            case '[' :
            case '{' : sta.push(c); break;
            case ')' : if(sta.empty() || sta.top() != '(') return false; sta.pop(); break;
            case ']' : if(sta.empty() || sta.top() != '[') return false; sta.pop(); break;
            case '}' : if(sta.empty() || sta.top() != '{') return false; sta.pop(); break;
        }
    }

    return sta.empty();
}

std::vector<std::string> res;

std::vector<std::string> generate(int n)
{
    std::string path;

    dfs(n, n, path);

    return res;
}

void dfs(int left, int right, std::string &path)
{
    if(left > right) return;

    if(left == 0 && right == 0) {
        res.push_back(path);
        return;
    }

    if(left < 0 || right < 0) return;

    path.push_back('(');
    dfs(left - 1, right, path);
    path.pop_back();

    path.push_back(')');
    dfs(left, right - 1, path);
    path.pop_back();

}

std::vector<std::string> res;

std::vector<std::string> removeInvalidParentheses(std::string s)
{
    int left = 0, right = 0;
    for(const char &c : s) {
        if(c == '(') left++;
        else if(c == ')') {
            if(left == 0) right++;
            else left--;
        }
    }

    dfs(s, left, right, 0);

    return res;
}

void dfs(std::string s, int left, int right, int pos)
{
    if(left == 0 && right == 0) {
        if(isValid(s)) {
            res.push_back(s);
            return;
        }
    }

    for(int i = pos; i < s.size(); i++)
    {
        if(i > pos && s[i] == s[i-1]) continue;

        if(s[i] == '(') {
            dfs(s.substr(0, i) + s.substr(i + 1), left - 1, right, i);
        }
        else if(s[i] == ')') {
            dfs(s.substr(0, i) + s.substr(i + 1), left, right - 1, i);
        }
    }

}


bool isValid(std::string &s)
{
    int left = 0;
    for(const char &c : s) {
        if(c == '(') left++;
        else if(c == ')') {
            if(left == 0) return false;
            left--;
        }
    }

    return left == 0;
}

int longestValidParentheses(std::string s)
{
    if(s.empty()) return 0;

    int res = 0;
    std::stack<int> sta;
    sta.push(-1);

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(') sta.push(i);
        else {
            sta.pop();

            if(sta.empty()) sta.push(i);

            res = std::max(res, i - sta.top());
        }
    }

    return res;
}



std::vector<int> computePrefix(std::string pattern);

int strStr(std::string haystack, std::string needle)
{
    if(needle.empty()) return 0;

    int m = haystack.size(), n = needle.size();

    std::vector<int> prefix = computePrefix(needle);

    for(int i = 0, k = 0; i < m; i++)
    {
        while(k > 0 && needle[k] != haystack[i]) {
            k = prefix[k-1];
        }

        if(haystack[i] == needle[k]) k++;

        if(k == n) return i - n + 1;
    }

    return -1;
}

std::vector<int> computePrefix(std::string pattern)
{
    int n = pattern.size();
    std::vector<int> prefix(n, 0);

    for(int i = 1, k = 0; i < n; i++)
    {
        while(k > 0 && pattern[k] != pattern[i]) {
            k = prefix[k-1];
        }

        if(pattern[i] == pattern[k]) {
            prefix[i] = ++k;
        }
        else {
            prefix[i] = k;
        }
    }

    return prefix;
}


int main() {
    // std::string pattern = "bb", str = "hello";

    // std::cout << strStr(str, pattern) << std::endl;

    // std::cout << regex_match("123", regex("a*")) << std::endl;

    std::cout << regex_match("aaaAAA", std::regex("a*")) << std::endl;

    return 0;
}

std::string validIpAddress(std::string IP)
{
    regex IPV4("((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])\\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])");
    regex IPV6("(([0-9a-fA-F]{1,4})\\:){7}([0-9a-fA-F]{1,4})");

    if(regex_match(IP, IPV4)) {
        return "IPv4";
    }
    else if(regex_match(IP, IPV6)) {
        return "IPv6";
    }

    return "Neither";
}

std::list<std::pair<int,int>> cache;
std::unordered_map<int, std::list<std::pair<int,int>>::iterator> hash;
int size;

LRUCache(int capacity) {
    size = capacity;
}

int get(int key)
{
    auto it = hash[key];
    if(it == hash.end()) return -1;

    cache.splice(cache.begin(), cache, it->second);

    return it->second->second;
}

void put(int key, int value)
{
    auto it = hash[key];
    if(it != hash.end()) {
        it->second->second = value;
        cache.splice(cache.begin(), it, it->second);
        return;
    }

    cache.push_front({key, value});
    hash[key] = cache.begin();

    if(cache.size() > size) {
        hash.erase(cache.back().first);
        cache.pop_back();
    }

}

std::stack<int> in, out;

MyQueue() {

}

void push(int x)  {
    in.push(x);
}

int pop() {
    in2out();
    int n = out.top();
    out.pop();
    return n;
}

int peek() {
    in2out();
    return out.top();
}

bool empty() {
    return in.empty() && out.empty();
}

void in2out()
{
    if(out.empty())
    {
        while(!in.empty()) {
            out.push(in.top());
            in.pop();
        }
    }
}



int calculate(std::string s);

int main() {
    std::string str = "((3*2)-1)*2";

    std::cout << calculate(str) << std::endl;

    return 0;
}



int calculate(std::string s)
{
    int num = 0;
    char sign = '+';
    int pre = 0;

    std::stack<int> sta;

    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        if(isdigit(c)) {
            num = num*10 + (c - '0');
        }

        //遇到括号则递归计算,注意需要找到对应的括号与之匹配的括号，不能直接找下一个')'
        if(c == '(') {
            int count = 1;
            int j = i + 1;
            while(j < s.size()) 
            {
                if(s[j] == ')') {
                    count--;
                    if(count == 0) break;
                }
                else if(s[j] == '(') count++;
                j++;
            }

            num = calculate(s.substr(i + 1, j - i - 1));
            i = j;  //将i指向j,注意不能指向j+1,防止')'就是最后一个字符
        }
        
        if((!isspace(c) && !isdigit(c)) || i == s.size() - 1) 
        {
            switch(sign) {
                case '+' : sta.push(num);  break;
                case '-' : sta.push(-num); break;
                case '*' : pre = sta.top(); sta.pop(); sta.push(pre * num); break;   //要理解，遇到符号是将前一个数入栈，并更改当前符号
                case '/' : pre = sta.top(); sta.pop(); sta.push(pre / num); break;
            }   

            sign = c;
            num = 0;
        }
    }

    int res = 0;
    while(!sta.empty()) {
        res += sta.top();
        sta.pop();
    }

    return res;
}

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>> &image, int sr, int sc, int newColor)
{
    if(image[sr][sc] == newColor) return image;

    dfs(image, sr, sc, newColor, image[sr][sc]);

    return image;
}

void dfs(std::vector<std::vector<int>> &image, int sr, int sc, int newColor, int oldColor)
{
    int m = image.size(), n = image[0].size();

    if(sr >= 0 && sr < m && sc >= 0 && sc < n && image[sr][sc] == oldColor)
    {
        image[sr][sc] = newColor;

        dfs(image, sr, sc + 1, newColor, oldColor);
        dfs(image, sr, sc - 1, newColor, oldColor);
        dfs(image, sr + 1, sc, newColor, oldColor);
        dfs(image, sr - 1, sc, newColor, oldColor);
    }

}

std::vector<int> dir = {-1, 0, 1, 0, -1};

void dfs(std::vector<std::vector<int>> &image, int i, int j, int newColor, int oldColor)
{
    int m = image.size(), n = image[0].size();

    image[i][j] = newColor;

    for(int k = 0; k < dir.size() - 1; k++) {
        int px = i + dir[k], py = j + dir[k+1];
        if(px >= 0 && px < m && py >= 0 && py < n && image[px][py] == oldColor) {
            dfs(image, px, py, newColor, oldColor);
        }
    }

}


//Leetcode第490题：判断小球是否能够滚到终点(注意：只有碰到墙壁才能停下来)
int shorestDistance(std::vector<std::vector<int>> &maze, std::vector<int> &start, std::vector<int> &dest);

std::vector<int> dir = {-1, 0, 1, 0, -1};

bool hasPath(std::vector<std::vector<int>> &maze, std::vector<int> &start, std::vector<int> &dest)
{
    int m = maze.size(), n = maze[0].size();

    std::vector<std::vector<int>> visited(m, std::vector<int>(n, 0));

    std::queue<std::pair<int,int>> que;

    que.push({start[0], start[1]});
    visited[start[0]][start[1]] = 1;

    while(!que.empty())
    {
        auto cur = que.front(); que.pop();
        int x = cur.first, y = cur.second;

        if(x == dest[0] && y == dest[1]) return true;

        for(int i = 0; i < dir.size() - 1; i++)
        {
            //一直滚到到边界
            while(x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0) {
                x += dir[i], y += dir[i+1];
            }

            //将边界加入到队列中            
            x -= dir[i], y -= dir[i+1];

            if(!visited[x][y]) {
                que.push({x, y});
                visited[x][y] = 1;
            }
        }
    }

    return false;
}


int main() {
    std::vector<std::vector<int>> maze = {{0,0,1,0,0}, {0,0,0,0,0}, {0,0,0,1,0}, {1,1,0,1,1}, {0,0,0,0,0}};
    std::vector<int> start = {0,4}, dest = {4,4};

    std::cout << shorestDistance(maze, start, dest) << std::endl;

    return 0;
}


//Leetcode第505题：到达迷宫终点的最短距离
// 额外定义一个数组用来记录到达边界的距离

int shorestDistance(std::vector<std::vector<int>> &maze, std::vector<int> &start, std::vector<int> &dest)
{
    int m = maze.size(), n = maze[0].size();

    std::vector<std::vector<int>> distance(m, std::vector<int>(n, 0));

    std::vector<std::vector<int>> visited(m, std::vector<int>(n, 0));
    std::queue<std::pair<int,int>> que;

    que.push({start[0], start[1]});
    visited[start[0]][start[1]] = 1;

    while(!que.empty())
    {
        auto cur = que.front(); que.pop();
        int x = cur.first, y = cur.second;

        if(x == dest[0] && y == dest[1]) return distance[x][y];

        for(int i = 0; i < dir.size() - 1; i++)
        {
            int steps = 0;
            int px = x, py = y;

            //没遇到墙壁就持续滚直到遇到墙壁
            while(px >= 0 && px < m && py >= 0 && py < n && maze[px][py] == 0) {
                px += dir[i], py += dir[i+1];
                steps++;
            }            

            //将边界加入到队列中
            px -= dir[i], py -= dir[i+1], steps--;

            if(!visited[px][py]) {
                que.push({px, py});
                visited[px][py] = 1;
                distance[px][py] = distance[x][y] + steps;  //计算从上一位置滚到此边界的距离
            }
        }
    }

    return -1;
}

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [](const std::vector<int> &a, const std::vector<int> &b){
        return a[0] < b[0];
    });

    std::vector<std::vector<int>> res;
    res.push_back(intervals.front());

    for(int i = 1; i < intervals.size(); i++)
    {
        if(intervals[i][0] < res.back()[1]) {
            res.back()[1] = std::max(rea.back()[1], intervals[i][1]);
        }
        else {
            res.push_back(intervals[i]);
        }
    }

    return res;
}



class maxHeap
{
private:
    std::vector<int> heap;

public:
    maxHeap() {
        heap.push_back(-1);
    }

    int top() {
        return heap[1];
    }

    //插入的数字放在最后一位，然后上浮
    void push(int k) 
    {
        heap.push_back(k);
        swim(heap.size() - 1);  
    }

    //删除最大值:把最后一个数字挪到开头，然后开始下沉
    void pop()
    {
        heap[1] = heap.back();
        heap.pop_back();
        sink(1);
    }

    //上浮
    void swim(int pos)
    {
        while(pos > 1 && heap[pos/2] < heap[pos]) {
            std::swap(heap[pos/2], heap[pos]);
            pos /= 2;
        }
    }

    //下沉
    void sink(int pos)
    {
        int N = heap.size() - 1;  //vector第一个元素不能算进去

        while(2*pos <= N) 
        {
            int i = 2*pos;
            if(i < N && heap[i+1] > heap[i]) i++;
            if(heap[pos] > heap[i]) break;
            std::swap(heap[pos], heap[i]);
            pos = i;
        }
    }

};

int main() {
    // std::vector<int> nums1 = {0,0,0,0,0,0,1,0,0,0}, nums2 = {0,0,0,0,0,0,0,1,0,0};
    // std::vector<int> nums1 = {0,0,0,0,0,0,1,0,0,0}, nums2 = {0,0,0,0,0,0,0,1,0,0};
    // std::cout << findLength(nums1, nums2) << std::endl;

    // maxHeap heap;

    // heap.push(1);
    // heap.push(5);
    // heap.push(9);

    // std::cout << heap.top() << std::endl;   heap.pop();
    // std::cout << heap.top() << std::endl;   heap.pop();
    // std::cout << heap.top() << std::endl;   heap.pop();
    int *p = nullptr;

    if(!p)
        std::cout << p << std::endl;

    return 0;
}


bool hasPathSum(TreeNode *root, int target)
{
    if(root == nullptr) return false;

    if(root->val == target && !root->left && !root->right) return true;

    return hasPathSum(root->left, target - root->val) || hasPathSum(root->right, target - root->val);
}

std::vector<std::vector<int>> res;

std::vector<std::vector<int>> pathSum(TreeNode *root, int target)
{
    std::vector<int> path;

    dfs(root, target, path);

    return res;
}

void dfs(TreeNode *root, int target, std::vector<int> path)
{
    if(root == nullptr) return;

    path.push_back(root->val);

    if(root->val == target && !root->left && !root->right) {
        res.push_back(path);
        return;
    }

    dfs(root->left, target - root->val, path);
    dfs(root->right, target - root->val, path);

}


int pathSum(TreeNode *root, int target)
{
    if(root == nullptr) return 0;

    return dfs(root, target) + pathSum(root->left, target) + pathSum(root->right);
}

int dfs(TreeNode *root, int target)
{
    if(root == nullptr) return 0;

    int count = 0;
    if(root->val == target) count++;

    return count + dfs(root->left, target - root->val) + dfs(root->right, target - root->val);
}

int maxSum = 0;

int maxPathSum(TreeNode *root)
{
    dfs(root);

    return maxSum;
}

int dfs(TreeNode *root)
{
    if(root == nullptr) return 0;

    int maxLeft = std::max(0, dfs(root->left));
    int maxRight = std::max(0, dfs(root->right));

    maxSum = std::max(maxSum, root->val + maxLeft + maxRight);

    return root->val + std::max(maxLeft, maxRight);
}

int maxVal = 0;

int diameterOfBinaryTree(TreeNode *root)
{
    dfs(root);
    
    return maxVal;
}

int dfs(TreeNode *root)
{
    if(root == nullptr) return 0;

    int left = dfs(root->left);
    int right = dfs(root->right);

    maxVal = std::max(maxVal, left + right);

    return 1 + std::max(left, right); 
}

// dp[i] = std::max(dp[i], dp[j]+1), j(0, i-1), nums[i] > nums[j]

int lengthOfLIS(std::vector<int> &nums)
{
    std::vector<int> dp(nums.size(), 1);
    int maxLen = 1;

    for(int i = 0; i < nums.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
            maxLen = std::max(maxLen, dp[i]);
        }
    }

    return maxLen;
}

int lengthOfLIS(std::vector<int> &nums)
{
    std::vector<int> res;

    for(const int &n : nums) {
        if(res.empty() || n > res.back()) res.push_back(n);
        else {
            auto it = lower_bound(res.begin(), res.end(), n);
            *it = n;
        }
    }

    return res.size();
}


class UF
{
private:
    std::vector<int> parent;
    std::vector<int> size;
    int count;

public:
    UF(int n) 
    {
        parent.resize(n);
        size.resize(n);

        count = n;
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findNode(int x) 
    {
        while(parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }

        return x;
    }

    void unionNode(int p, int q)
    {
        int rootP = findNode(p);
        int rootQ = findNode(q);

        if(size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        else {
            parent[rootP] == rootQ;
            size[rootQ] += size[rootP];
        }

        count--;    //联通分量减1
    }

    bool connected(int p, int q) {
        return findNode(p) == findNode(q);
    }

    int countNum() {
        return count;
    }

};

int findCircleNum(std::vector<std::vector<int>> &isConnected)
{
    int n = isConnected.size();

    UF uf(n);

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            uf.unionNode(i, j);
        }
    }

    return uf.countNum();
}

class UF
{
private:
    std::vector<int> size;
    std::vector<int> parent;

public:
    UF(int n) {
        size.resize(n);
        parent.resize(n);

        for(int i = 0; i < n; i++) {
            size[i] = 1;
            parent[i] = i;
        }
    }

    //时间复杂度为O(1)
    bool unionNode(int p, int q)
    {
        int rootP = findNode(p);
        int rootQ = findNode(q);

        if(rootP == rootQ) return false;

        if(size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }

        return true;
    }
    
    //时间复杂度为O(1)
    int findNode(int x) 
    {
        while(x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        
        return x;
    }

};

std::vector<int> findRedundantConnection(std::vector<std::vector<int>> &edges)
{
    int n = edges.size();

    UF uf(n);

    for(auto edge : edges)
    {
        if(!uf.unionNode(edge[0], edge[1])) return edge;
    }

    return {};
}


std::string minWindow(std::string s, std::string t)
{
    std::vector<int> map(128, 0);

    for(const char &c : t) {
        map[c]++;
    }

    int count = 0;
    int left = 0, right = 0;
    std::vector<int> window(128, 0);

    int startIndex = 0, minLen = INT_MAX;

    while(right < s.size())
    {
        if(++window[s[right]] <= map[s[right]]) {
            count++;
        }

        //窗口中的字符包含了了t的所有字符
        while(count == t.size()) {
            if(right - left + 1 < minLen) {     //由于上面right++了,所以这里是right-left
                startIndex = left;
                minLen = right - left + 1;
            }

            //移动左窗口
            if(--window[s[left]] < map[s[left]]) {
                count--;
            }
            left++;
        }

        right++;
    }

    return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
}

int minSubArrayLen(int target, std::vector<int> &nums);

int main() {
    std::vector<int> nums = {2,3,1,2,4,3};
    int target = 7;

    std::cout << minSubArrayLen(target, nums) << std::endl;

    return 0;
}

int minSubArrayLen(int target, std::vector<int> &nums)
{
    int left = 0, right = 0;

    int sum = 0, minLen = INT_MAX;

    while(right < nums.size())
    {
        sum += nums[right];

        std::cout << sum << std::endl;

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

int lengthOfLongestSubstring(std::string s)
{
    std::vector<int> mp(128, -1);

    int start = -1, res = 0;

    for(int i = 0; i < s.size(); i++) {
        if(mp[s[i]] > start) {
            start = mp[s[i]];
        }
        mp[s[i]] = i;
        res = std::max(res, i - start);
    }

    return res;
}

int minSubArrayLen(int target, std::vector<int> &nums)
{
    int n = nums.size();

    int minLen = n + 1, sum = 0;
    int left = 0;

    for(int i = 0; i < n; i++) 
    {
        sum += nums[i];

        while(sum >= target) {
            minLen = std::min(minLen, i - left + 1);
            sum -= nums[left++];
        }
    }

    return minLen == n + 1 ? 0 : minLen;
}

std::string minWindow(std::string s, std::string t)
{
    std::vector<int> mp(128, 0);
    for(const char &c : t) {
        mp[c]++;
    }

    std::vector<int> window(128, 0);
    int count = 0;
    int left = 0;
    int minLen = INT_MAX, startIndex = 0;

    for(int right = 0; right < s.size(); right++)
    {
        if(++window[s[right]] <= mp[s[right]]) {
            count++;
        }

        while(count == t.size())
        {
            if(minLen > right - left + 1) {
                startIndex = left;
                minLen = right - left + 1;
            }

            if(--window[s[left]] < mp[s[left]]) count--;

            left++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
}




std::vector<int> findAnagrams(std::string s, std::string p)
{
    if(s.size() < p.size()) return {};

    std::vector<int> freqP(26, 0);
    for(const char &c : p) {
        freqP[c-'a']++;
    }


/*
    for(int i = 0; i < p.size(); i++) {
        window[s[i]-'a']++;
    }

    std::vector<int> res;

    if(window == freqP) res.push_back(0);


    std::vector<int> window(26, 0);

    int left = 0;
    std::vector<int> res;

    for(int right = 0; right < s.size(); right++)
    {
        window[s[right]-'a']++;

        if(right - left + 1 == p.size()) 
        {
            if(window == freqP) res.push_back(left);
            window[s[left++]-'a']--;
        }
    }

    return res;
}


int main() {
    std::string s = "abab", t = "ab";

    for(auto &n : findAnagrams(s, t)) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}

int longestOnes(std::vector<int> &nums, int k)
{
    int count = 0, maxLen = 0;

    int left = 0;

    for(int right = 0; right < nums.size(); right++)
    {
        if(nums[right] == 0) count++;

        while(count > k) {
            if(nums[left++] == 0) count--;
        }

        maxLen = std::max(maxLen, right - left + 1);
    }

    return maxLen;
}

int longestSubstring(std::string s, int k)
{
    if(s.empty() || s.size() < k) return 0;

    std::vector<int> count(26, 0);
    for(const char &c : s) {
        count[c-'a']++;
    }

    int mid = 0;
    while(mid < s.size() && count[s[mid]-'a'] >= k) mid++;
    if(mid == s.size()) return s.size();
    int left = longestSubstring(s.substr(0, mid), k);

    while(mid < s.size() && count[s[mid-'a'] < k) mid++;
    if(mid == s.size()) return left;
    int right = longestSubstring(s.substr(mid), k);

    return std::max(left, right);
}



int longestSubstring(std::string s, int k)
{
    if(s.empty() || s.size() < k) return 0;

    int maxLen = 0;

    //让每次窗口中的唯一字符出现n个,n由1增加到26逐个判断最长长度 (这样时间复杂度控制为O(26*n),近似与O(n))
    for(int n = 1; n <= 26; n++)
    {
        std::vector<int> count(26, 0);
        int left = 0, uniqueChar = 0;

        for(int right = 0; right < s.size(); right++)
        {
            if(count[s[right]-'a']++ == 0) uniqueChar++;

            //出现的唯一字符大于n个,则向右移动左窗口
            while(uniqueChar > n) {
                if(count[s[left++]-'a']-- == 1) uniqueChar--;
            }

            //经过上一步骤窗口中的不同字符个数肯定 <= n, 我们只需关心不同字符个数等于n的情况
            if(uniqueChar == n) {
                bool valid = true;
                // 判断这n个不同字符是否每个的出现次数都 >= k
                // 如果count[i]为0就代表该字符未出现过, 如果count[i] > 0 并且 count[i] < k,说明出现次数不满足 >=k 条件
                for(int j = 0; j < 26; j++) {
                    if(count[j] > 0 && count[j] < k) valid = false;
                }
                if(valid) maxLen = std::max(maxLen, right - left + 1);
            }
        }
    }

    return maxLen;
}


int main() {
    std::string s = "aaabb";
    int k = 3;

    longestSubstring(s, k);

    // std::cout << longestSubstring(s, k) << std::endl;

    return 0;
}


std::priority_queue<int, std::vector<int>, std::greater<int>> minQue;
std::priority_queue<int> maxQue;

MedianFinder() {

}

void addNum(int num)
{
    if(maxQue.empty() || num < maxQue.top()) maxQue.push(num);
    else minQue.push(num);

    // if(minQue.empty() || num > minQue.top()) minQue.push(num);
    // else maxQue.push(num);

    // if(minQue.size() > maxQue.size() + 1) {
    //     maxQue.push(minQue.top());
    //     minQue.pop();
    // }
    // else if(maxQue.size() > minQue.size() + 1) {
    //     minQue.push(maxQue.top());
    //     maxQue.pop();
    // }



}

double findMedian() {
    if(minQue.size() == maxQue.size()) {
        return (minQue.top() + maxQue.top()) / 2.0;
    }

    return minQue.size() > maxQue.size() ? minQue.top() : maxQue.top();
}
>

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


//Leetcode第162题 : 找到 Peak Element(数组并非为有序)

// 二分查找思想
// 如果 nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1] 说明找到 mid, 直接返回
// 否则 nums[mid]必定小于 nums[mid-1] 和 nums[mid+1] 其中一个
// 如果 nums[mid] < nums[mid+1], 说明 Peak 在右边, left = mid + 1
// 如果 nums[mid] < nums[mid-1], 说明 Peak 在左边， right = mid - 1

// base case : 当数组顺序或者逆序时，上述情况就不适用, 只要数组中存在Peak时按照上述思路就肯定能找到对应元素

//时间复杂度O(logn)

int findPeakElement(std::vector<int> &nums)
{
    int n = nums.size();

    if(n == 1) return 0;

    //这两种情况就处理了数组单调增和单调减的情况
    if(nums[0] > nums[1]) return 0;
    else if(nums[n-1] > nums[n-2]) return n - 1;

    int left = 1, right = n - 2;

    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);

        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
        else if(nums[mid] < nums[mid+1]) left = mid + 1;
        else if(nums[mid] < nums[mid-1]) right = mid - 1;
    }

    return -1;
}


//线性查找, 找到第一个 nums[i] > nums[i+1]即可
//时间复杂度 O(n)

int findPeakElement(std::vector<int> &nums)
{
    int n = nums.size();
    
    if(n == 1) return 0;

    for(int i = 0; i < n-1; i++) {
        if(nums[i] > nums[i+1]) return i;
    }

    return -1;
}


// Leetcode第852题 : 山脉数组查找最大值

int peakIndexInMountainArray(std::vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;

    while(left < right)
    {
        int mid = left + ((right - left) >> 1);
        
        if(nums[mid] < nums[mid+1]) left = mid + 1;
        else right = mid;

    }

    return left;
}


//Leetcode第1095题 : 山脉数组查找给定值
//思路 : 
// 1.找到Peak Element元素,按照该元素将数组分成两部分进行二分查找
// 2.先查找左边部分,再查找右边部分(因为题目要求最小的下标)

int findMountainArray(int target, MountainArray &mountainArr)
{
    int left = 0, right = mountainArr.length() - 1;

    while(left < right)
    {
        int mid = left + ((right - left) >> 1);

        if(mountainArr.get(mid) < mountainArr.get(mid+1)) left = mid + 1;
        else right = mid;
    }

    int peakIndex = left;

    left = 0, right = mountainArr.length() - 1;

    int index = findMountainArrayLeft(target, mountainArr, left, peakIndex);

    if(index != -1) return index;

    return findMountainArrayRight(target, mountainArr, peakIndex + 1, right);
}

int findMountainArrayLeft(int target, MountainArray &mountainArr, int left, int right)
{
    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);

        if(mountainArr.get(mid) == target) return mid;
        else if(mountainArr.get(mid) < target) left = mid + 1;
        else if(mountainArr.get(mid) > target) right = mid - 1;
    }

    return -1;
}

int findMountainArrayRight(int target, MountainArray &mountainArr, int left, int right)
{
    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);

        if(mountainArr.get(mid) == target) return mid;
        else if(mountainArr.get(mid) < target) right = mid - 1;
        else if(mountainArr.get(mid) > target) left = mid + 1;
    }

    return -1;
}

double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
{
    int m = nums1.size(), n = nums2.size();

    if(m > n) return findMedianSortedArrays(nums2, nums1);

    int left = 0, right = m;

    while(left <= right)
    {
        int i = left + ((right - left) >> 1);
        int j = (m + n + 1)/2 - i;

        int maxLeftX = i == 0 ? INT_MIN : nums1[i-1];
        int minRightX = i == m ? INT_MAX : nums1[i];

        int maxLeftY = j == 0 ? INT_MIN : nums2[j-1];
        int minRightY = j == n ? INT_MAX : nums2[j];

        if(maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if((m+n)&1) return std::max(maxLeftX, maxLeftY);
            else return (std::max(maxLeftX, maxLeftY) + std::min(minRightX, minRightY)) / 2.0;
        }
        else if(maxLeftX > minRightY) {
            right = i - 1;
        }
        else if(maxLeftY > minRightX) {
            left = i + 1;
        }
    }

    return -1;
}


int mySqrt(int x)
{
    int left = 0, right = x;

    while(left <= right)
    {
        int mid = left + ((right-left) >> 1);

        if(mid == x/mid) return mid;
        else if(mid < x/mid) left = mid + 1;
        else if(mid > x/mid) right = mid - 1;
    }

    return left;
}

int findMin(std::vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;

    while(left <= right)
    {
        if(left == right) return left;

        int mid = left + ((right - left) >> 1);

        if(nums[mid] < nums[right]) right = mid - 1;
        else if(nums[mid] > nums[right]) left = mid + 1;
        else if(nums[mid] == nums[right]) right--
    }

    return left;
}


//Leetcode第875题 : Koko吃香蕉问题

//二分查找
//1.首先明确边界,每次吃的最大值肯定就是数组的最大元素,最小值就是1, 则left = 1, right = max
//2.在[left,right]上找到能够满足在h小时内吃完的最小数即可

int minEatingSpeed(std::vector<int> &piles, int h)
{
    int left = 1, right = 1;
    for(const int &n : piles) {
        right = std::max(right, n);
    }

    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);

        if(canFinsh(piles, h, mid)) {
            right = mid - 1;
        }
        else left = mid + 1;
    }

    return left;
}

bool canFinsh(std::vector<int> &nums, int h, int speed)
{
    int times = 0;

    for(const int &n : nums) {
        time += timeOf(n, speed);
    }

    return time <= h;
}

int timeOf(int n, int speed)
{
    return (n/speed) + (n%speed ? 1 : 0);
}


bool canFinsh(int num, std::vector<std::vector<int>> &prere)
{
    std::vector<std::vector<int>> graph(num);
    std::vector<int> indegree(num);

    for(auto &e : prere)
    {
        graph[e[1]].push_back(e[0]);
        indegree[e[0]]++;
    }

    std::queue<int> que;
    int visited = 0;

    for(int i = 0; i < num; i++) {
        if(indegree[i] == 0) {
            que.push(i);
        }
    }

    while(!que.empty())
    {
        visited++;
        auto cur = que.front(); que.pop();
        for(const int &n : graph[cur])
        {
            if(--indegree[n] == 0) {
                que.push(n);
            }
        }
    }

    return visited == num;
}

std::vector<int> findMinHieghtTrees(int n, std::vector<std::vector<int>> &edges)
{
    if(n == 1) return {0};

    std::vector<std::vector<int>> graph(n);
    std::vector<int> degree(n);

    for(auto &e : edges) 
    {
        graph[e[0]].push_back(e[1]);
        degree[e[1]]++;

        graph[e[1]].push_back(e[0]);
        degree[e[0]]++;
    }

    std::queue<int> que;
    for(int i = 0; i < n; i++) {
        if(degree[i] == 1) que.push(i);
    }

    std::vector<int> res;

    while(!que.empty())
    {
        res.clear();
        for(int size = que.size(); size > 0; size--)
        {
            int cur = que.front(); que.pop();
            res.push_back(cur);

            for(const int &n : graph[cur]) {
                if(--degree[n] == 1) que.push(n);
            }
        }
    }

    return res;
}

int triangleNumber(std::vector<int> &nums);

int main() {
    // std::string str = "ABC";

    // int i = 0;
    // if(str[i] < str[i++]) {
    //     std::cout << "dasd" << std::endl;
    // }

    std::vector<int> nums = {4,2,3,4};

    std::cout << triangleNumber(nums) << std::endl;

    return 0;
}

int triangleNumber(std::vector<int> &nums)
{
    if(nums.size() < 3) return 0;

    sort(nums.begin(), nums.end());

    int count = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        for(int left = i + 1; left < nums.size(); left++)
        {
            for(int right = nums.size() - 1; right > left; right--)
            {
                if(nums[i] + nums[left] > nums[right]) {
                    count += right - left;
                    break;
                }

            }
        }
    }

    return count;
}

int triangleNumber(std::vector<int> &nums)
{
    if(nums.size() < 3) return 0;

    sort(nums.begin(), nums.end());

    int count = 0;

    for(int i = nums.size() - 1; i > 1; i--)
    {
        int left = 0, right = i - 1;

        while(left < right)
        {
            if(nums[left] + nums[right] > nums[i]) {
                count += right - left;
                right--;
            }
            else left++;
        }
    }

    return count;
}

/*
int calculate(std::string s)
{
    char sign = '+';
    int num = 0, pre = 0;
    std::stack<int> sta;

    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        if(isdigit(c)) num = num*10 + (c-'0');

        if((!isspace(c) && !isdigit(c)) || i == s.size() - 1)
        {
            switch(sign) {
                case '+' : sta.push(num); break;
                case '-' : sta.push(-num); break;
                case '*' : pre = sta.top(); sta.pop(); sta.push(pre*num); break;
                case '/' : pre = sta.top(); sta.pop(); sta.push(pre/num); break;
            }

            sign = c;
            num = 0;
        }
    }

    int res = 0;
    while(!sta.empty()) {
        res += sta.top();
        res.pop();
    }

    return res;
}


int calculate(std::string s)
{
    std::stack<int> sta;
    int num = 0;

    char sign = '+';

    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        if(isdigit(c)) num = num*10 + (c-'0');

        else if(c == '(') {
            int count = 0;
            int j = i;
            for(; j < s.size(); j++) {
                if(s[j] == '(') count++;
                else if(s[j] == ')') count--;
                if(count == 0) break;
            }
            num = calculate(s.substr(i + 1, j - i - 1));
            std::cout << num << std::endl;
            i = j;
        }

        if((!isspace(c) && !isdigit(c) && c != '(') || i == s.size() - 1)
        {
            switch(sign) {
                case '+' : sta.push(num); break;
                case '-' : sta.push(-num); break;
            }

            num = 0;
            sign = c;
        }
    }

    int res = 0;
    while(!sta.empty()) {
        res += sta.top();
        sta.pop();
    }

    return res;
}

int main() {
    std::string str = "(1+1)";

    std::cout << calculate(str) << std::endl;

    return 0;
}

bool checkSubarraySum(std::vector<int> &nums, int k)
{
    std::unordered_map<int,int> hash;
    hash[0] = -1;

    int preSum = 0;

    for(int i = 0; i < nums.size(); i++) 
    {
        preSum += nums[i];
        int key = k == 0 ? preSum : preSum%k;

        if(hash.count(key)) {
            if(i - hash[key] >= 2) return true;
            else continue;
        }        

        hash[key] = i;
    }

    return false;
}

int subarraySum(std::vector<int> &nums, int k)
{
    std::unordered_map<int,int> hash;
    hash[0] = 1;

    int preSum = 0;
    int count = 0;

    for(int i = 0; i < nums.size(); i++) 
    {
        preSum += nums[i];
        count += hash[preSum-k];
        hash[preSum]++;
    }

    return count;
}

int numberOfSubarrays(std::vector<int> &nums, int k)
{
    std::unordered_map<int,int> hash;
    hash[0] = 1;

    int oddNum = 0, count = 0;

    for(const int &n : nums)
    {
        if(n&1) oddNum++;
        count += hash[oddNum-k];
        hash[oddNum]++;
    }

    return count;
}

int numSubmatrixSumTarget(std::vector<std::vector<int>> &matirx, int target)
{
    //计算每一行的前缀和
    int m = matirx.size(), n = matirx[0].size();
    for(int i = 0; i < m; i++) {
        for(int j = 1; j < n; j++) {
            matirx[i][j] += matirx[i][j-1];
        }
    }

    int count = 0;

    //计算(i,j)列之间的前缀和
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            std::unordered_map<int,int> hash;
            hash[0] = 1;
            int preSum = 0;
            for(int k = 0; k < m; k++)
            {
                preSum += matirx[k][j] - (i > 0 ? matirx[k][i-1] : 0);
                count += hash[preSum-target];
                hash[preSum]++;
            }
        }
    }

    return count;
}

bool checkSubarraySum(std::vector<int> &nums, int k)
{
    std::unordered_map<int,int> hash;
    hash[0] = -1;

    int preSum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        preSum += nums[i];
        int key = (k == 0) ? preSum : preSum%k;
        
        if(hash.count(key)) {
            if(i - hash[key] >= 2) return true;
            else continue;      //已经存在key就不需要再更新，我们让hahs中保存取余后得到的数值的最小下标值
        }

        hash[key] = i;
    }

}

std::vector<int> dir = {-1,0,1,0,-1};

bool exist(std::vector<std::vector<char>> &board, std::string word)
{
    int m = board.size(), n = board[0].size();

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == word[0] && dfs(board, i, j, word, 0)) return true;
        }
    }

    return false;
}

bool dfs(std::vector<std::vector<char>> &board, int i, int j, std::string &word, int pos)
{
    int m = board.size(), n = board[0].size();

    if(pos == word.size()-1) return true;

    board[i][j] = '#';

    bool find = false;

    for(int k = 0; k < dir.size() - 1; k++) {
        int x = i + dir[k], y = j + dir[k+1];
        if(x >= 0 && x < m && y >= 0 && y < n && board[x][y] == word[pos+1]) {
            find |= dfs(board, x, y, word, pos + 1);
        }
    }

    board[i][j] = word[pos];

    return find;
}

bool dfs(std::vector<std::vector<char>> &board, int i, int j, std::string &word, int pos)
{
    int m = board.size(), n = board[0].size();

    if(pos == word.size() - 1) return true;

    int find = false;

    if(i >= 0 && i < m && j >=0 && j < n && board[i][j] == word[pos])
    {
        board[i][j] = '#';

        find = find || dfs(board, i, j+1, word, pos + 1) || dfs(board, i, j-1, word, pos + 1) || dfs(board, i-1, j, word, pos + 1) || dfs(board, i+1, j, word, pos + 1);

        board[i][j] = word[pos];
    }

    return find;
}

std::vector<std::vector<int>> memcache;

int longestIncreasingPath(std::vector<std::vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();

    memcache = std::vector<std::vector<int>>(m, std::vector<int>(n, -1));

    int maxLen = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            maxLen = std::max(maxLen, dfs(matrix, i, j));
        }
    }

    return maxLen;
}

int dfs(std::vector<std::vector<int>> &matrix, int i, int j)
{
    int m = matrix.size(), n = matrix[0].size();

    if(memcache[i][j] != -1) return memcache[i][j];

    int len = 0;

    for(int k = 0; k < dir.size() - 1; k++)
    {
        int x = i + dir[k], y = j + dir[k+1];
        if(x >= 0 && x < m && y >= 0 && y < n && matrix[i][j] > matrix[x][y]) {
            len = std::max(len, 1 + dfs(matrix, x, y));
        }
    }

    count[m][n] = len;

    return len;
}



std::vector<std::vector<int>> cache;

int longestIncreasingPath(std::vector<std::vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();

    cache = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));

    int maxLen = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            maxLen = std::max(maxLen, dfs(matrix, i, j));
        }
    }

    return maxLen;
}

int dfs(std::vector<std::vector<int>> &matrix, int i, int j)
{
    int m = matrix.size(), n = matrix[0].size();

    if(cache[i][j]) return cache[i][j];

    int len = 0;

    for(int k = 0; k < dir.size() - 1; k++) {
        int x = i + dir[k], j = dir[k+1];
        if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] < matrix[i][j]) {
            len = std::max(len, 1 + dfs(matrix, x, y));
        }
    }

    cache[i][j] = len;

    return len;
}


struct TrieNode {
    TrieNode *childNode[26];
    bool isVal;

    TrieNode(): isVal(false) {
        for(int i = 0; i < 26; i++) {
            childNode[i] = nullptr;
        }
    }

    ~TrieNode() {
        delete[] childNode;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie() : root(new TrieNode()) {}

    void insert(std::string word)
    {
        TrieNode *cur = root;
        for(const char &c : word)
        {
            if(cur->childNode[c-'a'] == nullptr) {
                cur->childNode[c-'a'] = new TrieNode();
            }
            cur = cur->childNode[c-'a'];
        }

        cur->isVal = true;
    }

    bool search(std::string word)
    {
        TrieNode *cur = root;
        for(const char &c : word)
        {
            if(cur->childNode[c-'a'] == nullptr) {
                return false;
            }
            cur = cur->childNode[c-'a'];
        }

        return cur->isVal;
    }

    bool startsWith(std::string prefix)
    {
        TrieNode *cur = root;
        for(const char &c : prefix)
        {
            if(cur->childNode[c-'a'] == nullptr) {
                return false;
            }
            cur = cur->childNode[c-'a'];
        }

        return true;
    }
};
c>
#include <regex>

struct TrieNode {
    TrieNode *childNode[26];
    bool isVal;

    TrieNode(): isVal(false) {
        for(int i = 0; i < 26; i++) {
            childNode[i] = nullptr;
        }
    }

    ~TrieNode() {
        delete[] childNode;
        // for(int i = 0; i < 26; i++) {
        //     delete childNode[i];
        // }
    }
};


int main() {
    // TrieNode 

    return 0;
}

struct TrieNode {
    TrieNode *childNode[26];
    bool is_word;

    TrieNode() : is_word(false) {
        memset(childNode, NULL, sizeof(childNode));
    }

    ~TrieNode() {
        for(int i = 0; i < 26; i++) {
            delete childNode[i];
        }
    }
};


class WordDictionary
{
    TrieNode *root;

public:
    WordDictionary():root(new TrieNode()) {}

    void addWord(std::string word)
    {
        TrieNode *tmp = root;
        for(const char &c : word)
        {
            if(tmp->childNode[c-'a'] == nullptr) {
                tmp->childNode[c-'a'] = new TrieNode();
            }
            tmp = tmp->childNode;
        }

        tmp->is_word = true;
    }

    bool search(std::string word)
    {
        return searchWord(word, root);
    }

    bool searchWord(std::string word, TrieNode *node)
    {
        for(int i = 0; i < word.size() && node; i++)
        {
            if(word[i] != '.') {
                node = node->childNode[word[i]-'a'];
            }
            else {
                TrieNode *tmp = node;
                for(int j = 0; j < 26; j++) {
                    node = tmp->childNode[j];       //当前节点的子节点一个个尝试
                    if(search(word.substr(i + 1), node)) return true;
                }
            }
        }

        return node && node->is_word;
    }

};


int diffNumberOfArr(std::vector<int> &nums)
{
    //先找到最大值

}

Node* copyRandomList(Node* head)
{
    std::unordered_map<Node*, Node*> map;

    Node *cur = head;

    while(cur) {
        map[cur] = new Node(cur->val);
        cur = cur->next;
    }

    // cur = head;
    // while(cur) {
    //     map[cur]->next = map[cur->next];
    //     cur = cur->next;
    // }

    // cur = head;
    // while(cur) {
    //     if(cur->random) map[cur->random] = map[cur]->random;
    //     cur = cur->next;
    // }

    cur = head;
    while(cur) 
    {
        if(cur->next) {
            map[cur]->next = map[cur->next];
        }

        if(cur->random) {
            map[cur]->random = map[cur->random];
        }
    }

    return map[head];
}

Node* copyRandomList(Node *head)
{
    Node *cur = head;

    while(cur)
    {
        Node *pNext = cur->next;
        Node *pNode = new Node(cur->val);
        cur->next = pNode;
        pNode->next = pNext;
        cur = pNex;
    }

    //指派随机指针
    cur = head;
    while(cur)
    {
        if(cur->random) {
            cur->next->random = cur->random->next;
        }
        cur = cur->next->next;
    }

    //奇偶节点拆分
    Node *pCopyHead = head->next;
    Node *pCopy = pCopyHead;
    cur = head;

    while(pCopy)
    {
        cur = cur->next = pCopy->next;
        pCopy = pCopy->next = cur->next;
    }
    cur->next = nullptr;

    return pCopyHead;
}

int countPrimes(int n)
{
    std::vector<int> primes(n, 1);

    int count = n - 2;

    for(int i = 2; i*i < n; i++) {
        if(primes[i]) {
            for(int j = i*i; j < n; j += i) {
                if(primes[j]) {
                    primes[j] = 0;
                    count--;
                }
            }
        }
    }

    return count;
}



// void fun(int *p1, int *p2, int *t)
// {
//     t = (int*)malloc(sizeof(int));
//     *t = *p1 + (*p2++);
//     std::cout << *t << std::endl;
// }

// class Point
// {
// public:
//     Point(int x = 0, int y = 0);

// };

// Point::Point(int x = 0, int y = 0) {

// }

struct stu {
    int len;
    short a;
    char c;
};


int main()
{
    // int a[2] = {1,2};
    // int b[2] = {10,20};

    // int *t = a;
    // fun(a, b, t);

    // std::cout << *t << std::endl;

    // Point p;

    std::cout << sizeof(stu) << std::endl;

    return 0;
}




struct TrieNode {
    TrieNode *childNode[26];
    std::string word;

    TrieNode() {
        for(int i = 0; i < 26; i++) {
            childNode[i] = nullptr;
        }
    }

    ~TrieNode() {
        for(int i = 0; i < 26; i++) {
            if(childNode[i]) delete childNode[i];
        }
    }
};

TrieNode *buildTree(std::vector<std::string> &words)
{
    TrieNode *root = new TrieNode();

    for(auto &word : words)
    {
        TrieNode *node = root;
        for(const char &c : word) {
            if(node->childNode[c-'a'] == nullptr) {
                node->childNode[c-'a'] = new TrieNode();
            }
            node = node->childNode[c-'a'];
        }

        node->word = word;
    }

    return root;
}

std::vector<std::string> res;

std::vector<std::string> findWords(std::vector<std::vector<char>> &board, std::vector<std::string> &words)
{
    int m = board.size(), n = board[0].size();

    TrieNode *root = buildTree(words);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            dfs(board, i, j, root);
        }
    }

    return res;
}

void dfs(std::vector<std::vector<char>> &board, int i, int j, TrieNode *root)
{
    int m = board.size(), n = board[0].size();

    if(i >= 0 && i < m && j >= 0 && j < n && board[i][j] != '#')
    {
        char c = board[i][j];
        
        if(root->childNode[c-'a'] == nullptr) return;

        root = root->childNode[c-'a'];

        if(!(root->word.empty())) {
            res.push_back(root->word);
            root->word.clear();
        }

        board[i][j] = '#';

        dfs(board, i + 1, j, root);
        dfs(board, i - 1, j, root);
        dfs(board, i, j + 1, root);
        dfs(board, i, j - 1, root);
        
        board[i][j] = '#';
    }

    return ;
}




int main() {


    return 0;
}


struct TrieNode {
    TrieNode *childNode[26];
    std::vector<int> wordIndex;

    TrieNode() {
        for(int i = 0; i < 26; i++) {
            childNode[i] = nullptr;
        }
    }

    ~TrieNode() {
        for(int i = 0; i < 26; i++) {
            if(childNode[i]) delete childNode[i];
        }
    }

    void add(const std::string &word, int begin, int index)
    {
        wordIndex.push_back(index);

        if(begin < word.size())
        {
            if(childNode[word[begin]-'a'] == nullptr) {
                childNode[word[begin]-'a'] = new TrieNode();
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
            return childNode[prefix[begin]-'a'].find(prefix, begin + 1);
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
        std::vector<int> backwardMatch = backwardTrie->finf(suffix, 0);

        auto fIter = forwardMatch.rbegin(), bIter = backwardMatch.rend();
        word(fIter != forwardMatch.rend() && bIter != backwardMatch.rend())
        {
            if(*fIter == *bIter) return *fIter;
            else if(*fIter > *bIter) fIter++;
            else bIter++;
        }

        return -1;
    }

};



struct Node {
    int id;
    int dist;
    Node(int m_id, int m_dist) {
        id = m_id;
        dist = m_dist;
    }

    bool operator<(const Node &demo) const {
        return dist > demo.dist;
    }
};

void initMap(std::vector<std::vector<int>> &map)
{
    map[0][1] = 2;  map[0][2] = 3;  map[0][3] = 6;
    map[1][0] = 2;  map[1][4] = 4;  map[1][5] = 6;
    map[2][0] = 3;  map[2][3] = 2;
    map[3][0] = 6;  map[3][2] = 2;  map[3][4] = 1;  map[3][5] = 3;
    map[4][1] = 4;  map[4][3] = 1;
    map[5][1] = 6;  map[5][3] = 3; 
}

void Dijkstra()
{
    std::vector<std::vector<int>> map(6, std::vector<int>(6, 0));  //用map来记录权值
    initMap(map);   //初始化map

    std::vector<int> visited(6, 0);
    std::vector<int> distance(6, INT_MAX);

    std::priority_queue<Node>pq;
    pq.push(Node(0, 0));
    distance[0] = 0;

    while(!pq.empty())
    {
        Node tmp = pq.top(); pq.pop();
        int index = tmp.id;
        int len = tmp.dist;
        visited[index] = 1;

        for(int i = 0; i < map[index].size(); i++)
        {
            if(map[index][i] > 0 && !visited[i]) {
                Node newNode = Node(i, len + map[index][i]);
                if(distance[i] > newNode.dist) {
                    distance[i] = newNode.dist;
                    pq.push(newNode);
                }
            }
        }
    }
    
    for(int i = 0; i < 6; i++) {
        std::cout << distance[i] << " ";
    } 
    std::cout << std::endl;

}

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    // Dijkstra();
    std::cout << gcd(40, 8) << std::endl;

    return 0;
}

std::string convertToBase7(int num)
{
    bool negative = num < 0;
    if(negative) num = -num;

    std::string res;
    while(num) {
        res += std::to_string(num%7);
        num /= 7;
    }

    return negative ? "-"+res ? res;
}

int firstMissingPositive(std::vector<int> &nums)
{
    int n = nums.size();
    for(int i = 0; i < n; i++)
    {
        while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]) {
            std::swap(nums[i], nums[nums[i]-1]);
        }
    }

    for(int i = 0; i < n; i++) {
        if(nums[i] != i + 1) {
            return i + 1;
        }
    }

    return i + 1;
}

ListNode *partition(ListNode *head, int x)
{
    ListNode *l1 = new ListNode(-1);
    ListNode *l2 = new ListNode(-1);
    ListNode *l1Head = l1, l2Head = l2;

    while(head)
    {
        if(head->val < x) {
            l1->next = head;
            l1 = l1->next;
        }
        else {
            l2->next = head;
            l2 = l2->next;
        }

        head = head->next;
    }

    l1->next = l2Head->next;
    l2->next = nullptr;     //这个千万不要忘了

    return l1Head->next;
}

struct msg {
    char sex;
    std::string name;
    msg(char m_sex, std::string m_name) : sex(m_sex), name(m_name) {
        std::cout << "构造函数" << std::endl;
    }
    msg(const msg &demo) {
        sex = demo.sex;
        name = demo.name;
        std::cout << "拷贝构造" << std::endl;
    }
};

int misssingNumber(std::vector<int> &nums);

int main() {
    // std::vector<msg> message;
    // // message.emplace_back('m', "Jie");
    // // message.emplace(message.begin(), 'm', "Zhu");
    // msg msg1('m', "Jie");
    // message.push_back(msg1);

    // std::deque<int> dq;
    // dq.push_front(1);
    // dq.push_back(2);
    // dq.push_back(3);
    // dq.push_back(4);

    // std::cout << dq[3] << std::endl;

    // std::vector<std::string> vec;
    // vec.push_back("do");

    // std::cout << vec.front() << std::endl;

    std::vector<int> nums = {3,0,1};
    std::cout << misssingNumber(nums) << std::endl;


    return 0;
}

int misssingNumber(std::vector<int> &nums)
{
    int n = nums.size();

    for(int i = 0; i < n; i++)
    {
        while(nums[i] != i && nums[i] < n) std::swap(nums[i], nums[nums[i]]);
    }

    for(int i = 0; i < n; i++) {
        if(nums[i] != i) return i;
    }

    return n;
}

int misssingNumber(std::vector<int> &nums)
{
    int n = nums.size();

    int res = n;
    for(int i = 0; i < n; i++) {
        res ^= i^nums[i];
    }
    
    return res;
}

int misssingNumber(std::vector<int> &nums)
{
    int n = nums.size();

    int total = n*(n+1)/2;

    int sum = accumulate(nums.begin(), nums.end(), 0);

    return total - sum;
}

//交换的思想
int findDuplicate(std::vector<int> &nums)
{
    int n = nums.size();

    for(int i = 0; i < n; i++)
    {
        while(nums[i] != nums[nums[i]-1]) std::swap(nums[i], nums[nums[i]-1]);
        if(nums[i] != i + 1) return i + 1;
    }

    return -1;
}

//标记的思想
int findDuplicate(std::vector<int> &nums)
{
    for(int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;
        if(nums[index] > 0) nums[index] = -nums[index];
        else return abs(nums[i]);                       //注：这是nums[i],不是nums[index]
    }

    return -1;
}

int findDuplicate(std::vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;

    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);

        int count = 0;
        for(const int &n : nums) {
            if(n <= mid) count++;
        }

        if(count <= mid) left = mid + 1;
        else right = mid;
    }

    return right;
}

int findDuplicate(std::vector<int> &nums)
{
    int slow = nums[0], fast = nums[nums[0]];

    while(slow != fast)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    int finder = 0;
    while(nums[finder] != nums[slow])
    {
        finder = nums[finder];
        slow = nums[slow];
    }

    return nums[finder];
}

std::vector<int> findDuplicate(std::vector<int> &nums)
{
    std::vector<int> res;

    for(int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;
        if(nums[index] > 0) {
            nums[index] = -nums[index];
        }
        else res.push_back(abs(nums[i]));
    }

    return res;
}

std::vector<int> findDisappearedNumbers(std::vector<int> &nums)
{
    std::vector<int> res;

    for(int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;
        if(nums[index] > 0) {
            nums[index] = -nums[index];
        }
        else res.push_back(i + 1);
    }

    return res;
}

int firstMissingPositive(std::vector<int> &nums)
{
    int n = nums.size();

    for(int i = 0; i < n; i++)
    {
        while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]) {
            std::swap(nums[i], nums[nums[i]-1]);
        }
    }

    for(int i = 0; i < n; i++) {
        if(nums[i] != i + 1) return i + 1;
    }

    return n + 1;
}

std::vector<int> findErrorNums(std::vector<int> &nums)
{
    std::vector<int> res(2);
    int sum = accumulate(nums.begin(), nums.end(), 0);

    for(int i = 0; i < nums.size(); i++) 
    {
        int index = abs(nums[i]) - 1;
        if(nums[index] > 0) nums[index] = -nums[index];
        else {
            res[0] = abs(nums[i]);
            break;
        }
    }

    res[1] = n*(1+n)/2 - (sum - res[0]);

    return res;
}

std::vector<int> findErrorNums(std::vector<int> &nums)
{
    for(int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;
        if(nums[index] > 0) {
            nums[index] = -nums[index];
        }
        else res.push_back(abs(nums[index]));
    }

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > 0) res.push_back(i + 1);
    }

    return res;
}




std::string pushDominoes(std::string domineos)
{
    int n = domineos.size();

    int left = 0;

    for(int right = 0; right < n; right++)
    {
        if(domineos[right] == 'L') {
            for(int j = left; j < right; j++) {
                domineos[j] = 'L';
            }
            left = right + 1;
        }
        else if(domineos[right] == 'R') {
            left = right + 1;
            right = right + 1;

            while(right < n && (domineos[right] == 'R' || domineos[right] == '.')) right++;

            // std::cout << right << std::endl;

            if(right == n) {
                for(int j = left; j < right; j++) {
                    domineos[j] = 'R';
                }
                left = right + 1;
            }
            else if(domineos[right] == 'L') {
                while(left < n && domineos[left] == 'R') left++;
                int i = left, j = right - 1;
                while(i < n && i < j) {
                    domineos[i++] = 'R';
                    domineos[j++] = 'L';
                }
                left = right + 1;
            }
        }
    }

    return domineos;
}



int main() {
    // std::string str;
    // getline(std::cin, str);
    // std::cout << str << std::endl;

    // stringstream in(str);
    // std::string
    // while(getline(in, out, ' ')) {
        
    // }
    // int N;
    // std::cin >> N;
    // getchar();

    // std::vector<std::vector<int>> res;
    // std::string str;

    // while(getline(std::cin, str))
    // {
    //     std::vector<int> tmp;
    //     std::stringstream in(str);
    //     std::string out;
    //     while(getline(in, out, ' ')) {
    //         tmp.push_back(std::stoi(out));
    //     }
    //     res.push_back(tmp);
    // }

    // for(auto &vec : res) {
    //     for(auto &n : vec) {
    //         std::cout << n << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // std::vector<std::vector<int>> res;

    // getchar();
    // char s;
    // int a, b, c;

    // while(getchar() == '[') {
    //     scanf("%d %c %d %c %d %c %c", &a, &s, &b, &s, &c, &s, &s);
    //     res.push_back({a, b, c});
    // }

    // for(auto &num : res) {
    //     for(int &n : num) {
    //         std::cout << n << " ";
    //     }
    //     std::cout << std::endl;
    // }

    std::vector<int> res;

    std::string str1, str2;
    getline(std::cin, str1);
    getline(std::cin, str2);

    std::vector<int> nums1;
    std::stringstream in1(str1);
    std::string out;
    while(getline(in1, out, ',')) {
        nums1.push_back(std::stoi(out));
    }

    std::vector<std::string> strs;
    std::stringstream in2(str2);
    while(getline(in2, out, ';')) {
        strs.push_back(out);
    }

    std::vector<std::vector<int>> ans;
    for(const std::string str : strs)
    {
        std::vector<int> tmp;
        std::stringstream in(str);
        while(getline(in, out, ',')) {
            tmp.push_back(std::stoi(out));
        }
        ans.push_back(tmp);
    }

    for(auto &num : ans) {
        for(int &n : num) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


bool hasPath(TreeNode *root, int target)
{
    if(root == nullptr) return false;

    if(root->val == target && !root->left && !root->right) return true;

    return hasPath(root->left, target - root->val) || hasPath(root->right, target - root->val);
}

std::vector<std::vector<int>> res;

std::vector<std::vector<int>> pathSum(TreeNode *root, int target)
{
    std::vector<int> path;

    dfs(root, target, path);

    return res;
}

void dfs(TreeNode *root, int target, std::vector<int> &path)
{
    if(root == nullptr) return;

    path.push_back(root->val);

    if(root->val == target && !root->left && !root->right) {
        res.push_back(path);
    }

    dfs(root->left, target - root->val, path);
    dfs(root->right, target - root->val, path);

    path.pop_back();
}


int pathSum(TreeNode *root, int target)
{
    if(root == nullptr) return 0;

    return dfs(root, target) + pathSum(root->left, target) + pathSum(root->right, target);
}

int dfs(TreeNode *root, int target)
{
    if(root == nullptr) return 0;

    int count = root->val == target ? 1 : 0;

    count += dfs(root->left, target - root->val) + dfs(root->right, target - root->val);

    return count;
}

int maxSum = INT_MIN;

int maxPathSum(TreeNode *root)
{
    dfs(root);

    return maxSum;
}

int dfs(TreeNode *root)
{
    if(root == nullptr) return 0;

    int leftMax = std::max(0, dfs(root->left));
    int rightMax = std::max(0, dfs(root->right));

    maxSum = std::max(maxSum, root->val + leftMax + rightMax);

    return root->val + std::max(leftMax, rightMax);
}

int res = INT_MIN;

int diameterOFBinaryTree(TreeNode *root)
{
    if(root == nullptr) return 0;

    dfs(root);

    return res;
}

int dfs(TreeNode *root)
{
    if(root == nullptr) return 0;

    int maxLeft = dfs(root->left);
    int maxRight = dfs(root->right);

    res = std::max(res, maxLeft + maxRight);

    return 1 + std::max(maxLeft, maxRight);
}

std::vector<std::string> res;

std::vector<std::string> binaryTreePaths(TreeNode *root)
{
    if(root == nullptr) return res;

    dfs(root, "");

    return res;
}

void dfs(TreeNode *root, std::string path)
{
    if(root == nullptr) return;

    if(root->left == nullptr && root->right == nullptr) {
        path += std::to_string(root->val);
        res.push_back(path);
        return;
    }

    path += std::to_string(root->val) + "->";

    dfs(root->left, path);
    dfs(root->right, path);

}

TreeNode *pFirst = nullptr, *pSecond = nullptr;

void recoverTree(TreeNode *root)
{
    TreeNode *prev = nullptr;
    dfs(root, prev);

    if(pFirst && pSecond) std::swap(pFirst->val, pSecond->val);
}

void dfs(TreeNode *root, TreeNode * &prev)
{
    if(root == nullptr) return;

    dfs(root->left, prev);

    if(prev && prev->val > root->val) {
        if(pFirst == nullptr) pFirst = prev;
        pSecond = root;
    }

    prev = root;

    dfs(root->right, prev);
}



int maxProfit(std::vector<int> cut, std::vector<int> prices, int len);

std::vector<int> res;

int main() {
    std::vector<int> cut = {1,2,3,4}, prices = {2,5,7,8};
    int len = 5;

    maxProfit(cut, prices, len);
    // std::cout << maxProfit(cut, prices, len) << std::endl;

    for(const int &n : res) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}

// dp[i][j]
// if cut[i] > j  dp[i][j] = dp[i-1][j]
// if cut[i] <= j dp[i][j] = max(dp[i-1][j], dp[i][j-cut[i]] + prices[i])

int maxProfit(std::vector<int> cut, std::vector<int> prices, int len)
{
    int n = cut.size();

    std::vector<std::vector<int>> dp(n, std::vector<int>(len + 1, 0));

    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= len; j++) {
            if(j < cut[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = std::max(dp[i-1][j], dp[i][j-cut[i]] + prices[i]);
        }
    }

    int i = n-1, j = len;
    while(dp[i][j] > 0)
    {
        if(i > 0 && dp[i][j] == dp[i-1][j]) i--;
        else {
            std::cout << i << " " << j << std::endl;
            res.push_back(cut[i]);
            j -= cut[i];
        }
    }

    reverse(res.begin(), res.end());


    return dp[n-1][len];


    // std::vector<int> dp(len + 1, 0);
    
    // for(int i = 0; i < n; i++) {
    //     for(int j = 1; j <= len; j++) {
    //         if(j >= cut[i]) dp[j] = std::max(dp[j], dp[j-cut[i]] + prices[i]);
    //     }
    // }

    // return dp[len];
}



struct Node {
    int point;
    int len;
    Node(int m_point, int m_len) : point(m_point), len(m_len) {}

    bool operator<(const Node &demo) const {
        return len > demo.len;
    }
};

const int N = 101;
std::vector<std::vector<Node>> graph(N);
std::vector<int> dist(N, INT_MAX);
std::priority_queue<Node> pq;

void dijkstra();


int main() {
    int a,b,c;
    char s;
    getchar();
    while(getchar() == '[') {
        scanf("%d%c%d%c%d%c%c", &a,&s,&b,&s,&c,&s,&s);
        graph[a].push_back(Node(b,c));
    }

    int n, k;
    std::cin >> n >> k;

    dist[k] = 0;
    pq.push(Node(k, 0));
    
    dijkstra();

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = std::max(ans, dist[i]);
    }

    if(ans == INT_MAX) ans = -1;

    std::cout << ans << std::endl;

    return 0;
}

void dijkstra()
{
    // while(!pq.empty())
    // {
    //     auto cur = pq.top(); pq.pop();
    //     int m_point = cur.point, m_len = cur.len;

    //     for(int i = 0; i < graph[m_point].size(); i++) {
    //         Node newNode = Node(graph[m_point][i].point, m_len + graph[m_point][i].len);
    //         if(newNode.len < dist[newNode.point]) {
    //             dist[newNode.point] = newNode.len;
    //             pq.push(newNode);
    //         }
    //     }
    // }

    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        int m_point = cur.point, m_len = cur.len;

        for(int i = 0; i < graph[m_point].size(); i++) {
            if(dist[graph[m_point][i].point] > m_len + graph[m_point][i].len) {
                dist[graph[m_point][i].point] = m_len + graph[m_point][i].len;
                pq.push(Node(graph[m_point][i].point, dist[graph[m_point][i].point]));
            }
        }
    }

}



int partitionDisjoin(std::vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;

    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);
        int leftMax = findMax(nums, 0, mid);
        int rightMin = findMax(nums, mid + 1, right);
        if(leftMax <= rightMin) return mid + 1;

        if(leftMax > rightMin) {
            left = mid;
        }
    }

    return -1;
}

int findMax(std::vector<int> &nums, int left, int right)
{
    int maxVal = nums[left];

    for(int i = left + 1; i <= right; i++) {
        maxVal = std::max(maxVal, nums[i]);
    }

    return maxVal;
}

int findMin(std::vector<int> &nums, int left, int right)
{
    int minVal = nums[left];

    for(int i = left + 1; i <= right; i++) {
        minVal = std::min(minVal, nums[i]);
    }

    return minVal;
}


int main() {

    return 0;
}

int partitionDisjoin(std::vector<int> &nums)
{
    int localMax = nums[0], partitionIdx = 0;
    int max = localMax;

    for(int i = 1; i < nums.size(); i++) 
    {
        if(localMax > nums[i]) {    //因为要求左边元素全部小于右边元素，现在左边元素大于右边元素，所以切割位置右移
            localMax = max;
            partitionIdx = i;
        }
        else max = std::max(max, nums[i]);  //记录下最大元素，防止下次local>nums[i]时更新localMax的值
    }

    return partitionIdx + 1;
}



struct Node {
    int x, y, k, step;
    node(int m_x, int m_y, int m_k, int m_step) {
        x = m_x;
        y = m_y;
        k = m_k;
        step = m_step;
    }
};

int visited[105][105][1024];

std::vector<int> dir = {-1,0,1,0,-1};

int main() {
    int M, N;
    std::cin >> M >> N;
    std::vector<std::vector<char>> map(M, std::vector<char>(N));
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> map[i][j];
        }
    }

    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(map[i][j] == '2') {
                visited[i][j][0] = 1;
                std::cout << bfs(map, i, j) << std::endl;
                return 0;
            }
        }
    }

    return 0;
}

int bfs(std::vector<std::vector<char>> &map, int x, int y)
{
    int m = map.size(), n = map[0].size();

    std::queue<Node> que;
    que.push(Node(x, y, 0, 0));

    while(!que.empty())
    {
        auto cur = que.front(); que.pop();
        if(map[cur.x][cur.y] == '3') return cur.step;

        for(int i = 0; i < dir.size() - 1; i++) 
        {
            int mx = x + dir[i], my = y + dir[i+1];

            if(mx >= 0 && mx < m && my >= 0 && my < n && map[mx][my] != '0')
            {
                int key = tmp.k;
                if('a' < map[mx][my] < 'z') key |= (map[mx][my] - 'a');
                if('A' < map[mx][my] < 'Z' && (key & (1 << (map[mx][my]-'A'))) == 0) continue;
                
                if(!visited[mx][my][key]) {
                    visitedp[mx][my][key] = 1;
                    que.push(Node(mx, my, key, cur.step + 1));
                }
            }
        }
    }

    return 0;
}

>
#include <map>

class string
{
private:
    char *str;       //指向字符串的指针
    unsigned int len;  //字符串中的的实际字符长度(不包含结尾的'\0')

public:
    string(const char *s = NULL)  //这里给出了默认值就可以实现空对象, 如 string str;
    {
        if(s == NULL) {       
            str = new char[1];
            *str = '\0';
            len = 0;
        }
        else {
            len = strlen(s);
            str = new char[len + 1];
            strcpy(str, s);        //字符串复制函数(会将结尾符一起复制)
        }
        std::cout << "构造" << std::endl;
    }

    //拷贝构造(深拷贝)
    string(const string &demo) 
    {
        len = demo.len;
        str = new char[len + 1];
        strcpy(str, demo.str);
        std::cout << "拷贝构造" << std::endl;
    }

    //注意：以后一切赋值运算符全部返回引用,防止产生临时对象调用拷贝构造
    string& operator=(const string &demo)
    {
        //检查自赋值,这里是拿地址比较,因为对象的地址是唯一的,而值可能相同
        if(this == &demo) return *this;

        delete[] str;

        len = demo.len;
        str = new char[len + 1];
        strcpy(str, demo.str);

        return *this;   //返回本对象的引用
    }

    //'+'运算符返回一个新的对象，但是原来的对象不能析构掉
    string operator+(const string &demo) {
        string mstr;
        mstr = new char[strlen(str) + strlen(demo.str) + 1];
        sprintf(mstr.str, "%s%s", str, demo.str);
        return mstr;
    }

    ~string() {
        delete[] str;
    }

    void print() {
        std::cout << str << std::endl;
    }

};

string fun(string s1, string s2) {
    // string tmp = s1 + s2;
    // return tmp;
    return s1 + s2;
}

class Test 
{
public:
    Test() {
        std::cout << "构造" << std::endl;
    }

    Test(const Test &demo) {
        std::cout << "拷贝构造" << std::endl;
    }

    Test& operator=(const Test &demo) {
        std::cout << "赋值" << std::endl;
    }

};

Test fun() {
    Test a;
    return a;
}


int main() {
    // string s1 = "hello", s2 = "world";

    // fun(s1, s2);

    // Test a;

    // Test b = fun();
    fun();

    return 0;
}

int calculate(std::string s)
{
    std::stack<int> sta;
    char sign = '+';
    int num = 0;

    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if(isdigit(c)) {
            num = num*10 + (c - '0');
        }

        if((!isspace(c) && !isdigit(c)) || i == s.size() - 1)
        {
            switch (sign) {
                case '+' : sta.push(num); break;
                case '-' : sta.push(-num); break;
                case '*' : int tmp = sta.top(); sta.pop(); sta.push(tmp*num); break; 
                case '/' : int tmp = sta.top(); sta.pop(); sta.push(tmp/num); break;
            }

            num = 0;
            sign = c;
        }
    }

    int res = 0;
    while(!sta.empty()) {
        res += sta.top();
        sta.pop();
    }

    return res;
}



int calculate(std::string s)
{
    std::stack<int> sta;
    char sign = '+';
    int num = 0;

    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        if(isdigit(c)) {
            num = num*10 + (c-'0');
        }
        else if(c == '(') {
            int count = 0;
            int j = i;
            for(; j < s.size(); j++) {
                if(s[i] == '(') count++;
                else if(s[i] == ')') count--;
                if(count == 0) break;
            }
            num = calculate(s.substr(i + 1, j - i - 1));
            i = j;
        }

        if((!isspace(c) && !isdigit(c)) || i == s.size() - 1)
        {
            switch (sign) {
                case '+' : sta.push(num); break;
                case '-' : sta.push(-num); break;
            }

            num = 0;
            sign = c;
        }
    }

    int res = 0;
    while(!sta.empty()) {
        res += sta.top();
        sta.pop();
    }

    return res;
}


int main() {
    std::string str = "(7)-(0)+(4)";

    std::cout << calculate(str) << std::endl;

    return 0;
}

int calculate(std::string s)
{
    std::stack<int> sta;
    int num = 0;
    char sign = '+';

    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        if(isdigit(c)) {
            num = num*10 + (c-'0');
        }
        else if(c == '(') {
            int count = 0;
            int j = i;
            for(; j < s.size(); j++) {
                if(s[j] == '(') count++;
                else if(s[j] == ')') count--;
                if(count == 0) break;
            }
            num = calculate(s.substr(i + 1, j - i - 1));
            i = j;
        }

        if((!isspace(c) && !isdigit(c)) || i == s.size() - 1)
        {
            switch(sign) {
                case '+' : sta.push(num); break;
                case '-' : sta.push(-num); break;
            }

            sign = c;
            num = 0;
        }
    }

    int res = 0;
    while(!sta.empty()) {
        res += sta.top();
        sta.pop();
    }

    return res;
}

std::vector<int> row, col, leftDiag, rightDiag;

std::vector<std::vector<std::string>> res;

std::vector<std::vector<std::string>> solveQueens(int n)
{
    row = col = std::vector<int>(n, 0);
    leftDiag = rightDiag = std::vector<int>(2*n-1, 0);

    std::vector<std::string> map(n, std::string(n, '.'));

    dfs(map, n, 0);

    return res;    
}

void dfs(std::vector<std::string> &map, int n, int i)
{
    if(i == n) {
        res.push_back(map);
        return;
    }

    for(int j = 0; j < n; j++)
    {
        if(!row[i] && !col[j] && !leftDiag[i+j] && !rightDiag[i+(n-1)-j])
        {
            row[i] = col[j] = leftDiag[i+j] = rightDiag[i+(n-1)-j] = 1;
            map[i][j] = 'Q';

            dfs(map, n, i + 1);
            
            row[i] = col[j] = leftDiag[i+j] = rightDiag[i+(n-1)-j] = 0;
            map[i][j] = '.';
        }
    }

}


//row[i][j]的意思代表第i行是否存在数字j, col[i][j]代表第i列是否存在数字j, block[i][j]代表第i块是否存在数字j
//依据(i,j)计算block, k = (i/3)*3 + (j/3)

int row[9][9], col[9][9], block[9][9];

void solveSudoKu(std::vector<std::vector<char>> &board)
{
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(block, 0, sizeof(block));

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            int k = (i/3)*3 + (j/3);
            if(board[i][j] != '.') {
                int n = board[i][j] - '1';
                row[i][n] = col[j][n] = block[k][n] = 1;
            }
        }
    }

    dfs(board, 0, 0);

}

bool dfs(std::vector<std::vector<char>> &board, int i, int j)
{
    if(i == 9) return true;  

    if(j == 9) {
        return dfs(board, i + 1, 0);
    }

    if(board[i][j] != '.') {
        return dfs(board, i, j + 1);
    }

    for(int n = 0; n < 9; n++)
    {
        int k = (i/3)*3 + (j/3);
        
        if(!row[i][n] && !col[j][n] && !block[k][n])
        {
            row[i][n] = col[j][n] = block[k][n] = 1;
            board[i][j] = n + '1';

            if(dfs(board, i, j+1)) return true;

            row[i][n] = col[j][n] = block[k][n] = 0;
            board[i][j] = '.';
        }   
    }

}

int peakIndexInMountainArray(std::vector<int> &arr)
{
    int left = 0, right = arr.size() - 1;

    while(left < right)
    {
        int mid = left + ((right - left) >> 1);
        if(arr[mid] < arr[mid+1]) left = mid + 1;
        else right = mid;
    }

    return left;
}

int findInMountainArray(int target, MountainArray &mountainArr)
{
    //先找到山峰元素下标
    int left = 0, right = mountainArr.length() - 1;

    while(left < right)
    {
        int mid = left + ((right - left) >> 1);
        if(mountainArr.get(mid) < mountainArr.get(mid+1)) left = mid + 1;
        else right = mid;
    }

    int midIndex = left;
    left = 0, right = mountainArr.length() - 1;

    int first = findNumInArrFirst(mountainArr, 0, midIndex, target);
    if(first != -1) return first;

    return findNumInArrSecond(mountainArr, midIndex + 1, right, target);     
}

int findNumInArrFirst(MountainArray &mountainArr, int left, int right, int target)
{
    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if(mountainArr.get(mid) == target) return mid;
        else if(mountainArr.get(mid) < target) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}

int findNumInArrSecond(MountainArray &mountainArr, int left, int right, int target)
{
    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if(mountainArr.get(mid) == target) return mid;
        else if(mountainArr.get(mid) < target) right = mid - 1;
        else  left = mid + 1;
    }

    return -1;
}

int minEatingSpeed(std::vector<int> &piles, int h)
{
    int maxVal = -1;
    for(const int &n : piles) {
        maxVal = std::max(maxVal, n);
    }

    int left = 1, right = maxVal;

    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if(canFinish(piles, mid, h)) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return left;
}

bool canFinish(std::vector<int> &piles, int speed, int h)
{
    int time = 0;
    for(const int &n : piles) {
        time += n/speed + (n%speed ? 1 : 0);
    }

    return time <= h;
}

int shipWithinDays(std::vector<int> &weights, int D)
{
    int maxVal = 0, sum = 0;
    for(const int &n : weights) {
        maxVal = std::max(maxVal, n);
        sum += n;
    }

    int left = maxVal, right = sum;

    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if(canFinish(weights, mid, D)) {
            right = mid - 1;
        }
        else left = mid + 1;
    }

    return left;
}

bool canFinish(std::vector<int> &weights, int speed, int D)
{
    int i = 0;
    for(int day = 0; day < D; day++)
    {
        int maxCap = speed;
        while(maxCap -= weights[i] >= 0) {
            i++;
            if(i == weights.size()) return true;
        }
    }

    return false;
}


int spiltArray(std::vector<int> &nums, int m)
{
    int maxVal = 0, sum = 0;
    for(const int &n : nums) {
        maxVal = std::max(maxVal, n);
        sum += n;
    }

    int left = maxVal, right = sum;

    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if(valid(nums, mid, m)) {
            right = mid - 1;
        }
        else left = mid + 1;
    }

    return left;
}

bool valid(std::vector<int> &nums, int target, int m)
{
    int sum = 0;
    int count = 1;

    for(const int &n : nums) {
        sum += n;
        if(sum > target) {
            sum = n;
            count++;
            if(count > m) return false;
        }
    }

    return true;
}

double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
{
    if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

    int m = nums1.size(), n = nums2.size();

    int left = 0, right = m;

    while(left <= right)
    {
        int i = (left + right) / 2;
        int j = (m + n + 1) / 2 - i;

        int maxLeftX = i == 0 ? INT_MIN : nums1[i-1];
        int minRightX = i == m ? INT_MAX : nums1[i];

        int maxLeftY = j == 0 ? INT_MIN : nums2[j-1];
        int minRightY = j == n ? INT_MAX : nums2[j];

        if(maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if((m+n)&1) return std::max(maxLeftX, maxLeftY);
            else return (std::max(maxLeftX, maxLeftY) + std::min(minRightX + minRightY)) / 2.0;
        }
        else if(maxLeftX > minRightY) {
            right = i - 1;
        }
        else left = i + 1;
    }

    return -1;
}


int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList)
{
    std::unordered_set<std::string> mySet(wordList.begin(), wordList.end());

    if(!mySet.count(endWord)) return 0;

    std::queue<std::string> que;
    que.push(beginWord);
    mySet.erase(beginWord);

    int steps = 1;

    while(!pq.empty())
    {
        for(int size = que.size(); size > 0; size--)
        {
            auto word = que.front(); que.pop();
            if(word == endWord) return steps;

            for(const char &c : word)
            {
                char ch = c;
                for(int k = 0; k < 26; k++) {
                    c = k + 'a';
                    if(mySet.count(word)) {
                        que.push(word);
                        mySet.erase(word);
                    }
                }
                c = ch;
            }

            for(int i = 0; i < word.size(); i++)
            {
                char c = word[i];
                for(int k = 0; k < 26; k++) {
                    word[i] = k + 'a';
                    if(mySet.count(word)) {
                        que.push(word);
                        mySet.erase(word);
                    }
                }
                word[i] = c;
            }
        }

        steps++;
    }

    return 0;
}


/*
int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList)
{
    std::unordered_set<std::string> beginSet, endSet;
    std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());

    if(!wordSet.count(endWord)) return 0;

    beginSet.insert(beginWord);
    endSet.insert(endWord);
    wordSet.erase(beginWord);
    wordSet.erase(endWord);

    int steps = 1;

    while(!beginSet.empty() && !endSet.empty())
    {
        if(beginSet.size() > endSet.size()) {
            std::swap(beginSet, endSet);
        }

        std::unordered_set<std::string> tmp;
        for(auto &cur : beginSet)
        {
            std::string word = cur;
            for(char &c : word)
            {
                char ch = c;
                for(int k = 0; k < 26; k++) {
                    c = k + 'a';
                    
                    if(endSet.count(word)) return steps + 1;
                    if(wordSet.count(word)) {
                        tmp.insert(word);
                        wordSet.erase(word);
                    }
                }
                c = ch;
            }
        }

        beginSet = tmp;
        steps++;
    }

    return 0;
}
void dfs(std::string src, std::string des, std::unordered_map<std::string, std::vector<std::string>> &map,std::vector<std::string> &path, std::vector<std::vector<std::string>> &ans);
std::vector<std::vector<std::string>> findLadders(std::string beginWord, std::string endWord, std::vector<std::string> &wordList);


int main() {
    std::vector<std::string> wordList = {"hot","dot","dog","lot","log","cog"};
    std::string beginWord = "hit", endWord = "cog";

    // std::cout << ladderLength(beginWord, endWord, wordList) << std::endl;

    auto res = findLadders(beginWord, endWord, wordList);

    for(auto &num : res) {
        for(auto &n : num) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

std::vector<std::vector<std::string>> findLadders(std::string beginWord, std::string endWord, std::vector<std::string> &wordList)
{
    std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());

    if(!wordSet.count(endWord)) return {};

    std::queue<std::string> que;
    que.push(beginWord);
    // que.push(endWord);
    wordSet.erase(beginWord);
    // wordSet.erase(endWord);

    std::unordered_map<std::string, std::vector<std::string>> map;

    bool find = false;

    while(!que.empty())
    {
        std::vector<std::string> tmp;
        for(int size = que.size(); size > 0; size--)
        {
            auto cur = que.front(); que.pop();
            std::string word = cur;

            if(word == endWord) {
                find = true;
                break;
            }

            for(char &c : word) 
            {
                char ch = c;

                for(int k = 0; k < 26; k++) {
                    c = k + 'a';
                    if(wordSet.count(word)) {
                        std::cout << cur << " " << word << std::endl;
                        map[cur].push_back(word);
                        que.push(word);
                        // wordSet.erase(word);
                        tmp.push_back(word);
                    }
                }
                c = ch;

            }
        }

        for(auto &str : tmp) {
            wordSet.erase(str);
        }

        if(find) break;
    }

    // for(auto &item : map) {
    //     std::cout << item.first << "    "; 
    //     for(auto &str: item.second) {
    //         std::cout << str << " ";
    //     }
    //     std::cout << std::endl;
    // }

    std::vector<std::vector<std::string>> ans;
    std::vector<std::string> path = {beginWord};

    if(find) {
        dfs(beginWord, endWord, map, path, ans);
    }

    return ans;
}

void dfs(std::string src, std::string des, std::unordered_map<std::string, std::vector<std::string>> &map,std::vector<std::string> &path, std::vector<std::vector<std::string>> &ans)
{
    if(src == des) {
        // std::cout << "hello" << std::endl; 
        ans.push_back(path);
        return;
    }

    for(auto &s : map[src]) {
        path.push_back(s);
        dfs(s, des, map, path, ans);
        path.pop_back();
    }

}

std::vector<std::vector<std::string>> findLadders(std::string beginWord, std::string endWord, std::vector<std::string> &wordList)
{
    std::vector<std::vector<std::string>> ans;
    std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
    
    if(!wordSet.count(endWord)) return ans;

    wordSet.erase(beginWord);
    wordSet.erase(endWord);
    
    std::unordered_set<std::string> beginSet = {beginWord}, endSet = {endWord};

    std::unordered_map<std::string, std::vector<std::string>> next;

    bool reversed = false, found = false;

    while(!beginSet.empty() && !endSet.empty())
    {
        //始终让beginSet中的元素最少
        if(beginSet.size() > endSet.size()) {
            std::swap(beginSet, endSet);
            reversed = !reversed;           //注意这里交换后要逆序
        }

        std::unordered_set<std::string> tmp;

        for(auto &cur : beginSet)
        {
            std::string word = cur;
            
            for(char &c : word) {
                char ch = c;
                for(int k = 0; k < 26; k++) {
                    c = k + 'a';
                    if(endSet.count(word)) {
                        reversed ? next[word].push_back(cur) : next[cur].push_back(word);
                        found = true;
                    }
                    if(wordSet.count(word)) {
                        reversed ? next[word].push_back(cur) : next[cur].push_back(word);
                        tmp.insert(word);
                    }
                }
                c = ch;
            }
        }

        if(found) break;

        //将遍历过的字符全部从原有给定集合中删除
        for(auto &w : tmp) {
            wordSet.erase(w);
        }

        beginSet = tmp;
    }

    if(found) {
        std::vector<std::string> path = {beginWord};
        dfs(beginWord, endWord, next, path, ans);
    }

    return ans;
}

void dfs(std::string src, std::string des, std::unordered_map<std::string, std::vector<std::string>> &next, std::vector<std::string> &path, std::vector<std::vector<std::string>> &ans)
{
    if(src == des) {
        ans.push_back(path);
        return;
    }

    for(const auto &s : next[src]) {
        path.push_back(s);
        dfs(s, des, next, path, ans);
        path.pop_back();
    }

}


class Temp
{
private:
    static unsigned int n;
    static unsigned int sum;

public:
    Temp() {
        ++n;
        sum += n;
    }

    static void reset() {
        n = 0;
        sum = 0;
    }
    static int getSum() {
        return sum;
    }

};

unsigned int Temp::n = 0;
unsigned int Temp::sum = 0;

unsigned int solution1(unsigned int n)
{
    Temp::reset();

    Temp *a = new Temp[n];
    delete[] a;

    a = nullptr;

    return Temp::getSum();
}


class A;
A* array[2];

class A {
public:
    virtual unsigned int sum(unsigned int n) {
        return 0;
    }
};

class B : public A {
public:
    unsigned int sum(unsigned int n) {
        return array[!!n]->sum(n-1) + n;
    }
};

unsigned int solution2(unsigned int n) 
{
    A a;
    B b;
    array[0] = &a;
    array[1] = &b;

    int value = array[1]->sum(n);

    return value;
}

typedef unsigned int (*fun)(unsigned int);

unsigned int solution3_Terminator(unsigned int n) 
{
    return 0;
}

unsigned int solution3(unsigned int n) {
    static fun f[2] = {solution3_Terminator, solution3};
    return n + f[!!n](n-1);
}

template<unsigned int n> struct sum_solution4
{
    enum value { N = sum_solution4<n-1>::N + n };
};

template<> struct sum_solution4<1> {
    enum value { N = 1 };
};

enum Weekday {sun=7, mon, tue, wed, thu, fri, sat};


typedef struct {
    int value;
}data;


int main() {
    // std::cout << solution1(100) << std::endl;
    // std::cout << solution3(100) << std::endl;
    // std::cout << sum_solution4<100>::N << std::endl;

    data num;
    num.value = 3;

    printf("%d\n", num.value);

    // enum Weekday workday;
    // workday = mon;

    // printf("%d\n", workday);


    return 0;
}

std::string removeDuplicate(std::string s)
{
    std::string res;

    for(const char &c : s) {
        if(res.empty() || c != res.back()) res.push_back(c);
        else res.pop_back();        
    }

    return res;
}

std::string removeDuplicate(std::string s, int k)
{
    std::vector<std::pair<char,int>> vec;

    for(const char &c : s)
    {
        if(vec.empty() || c != vec.back().first) {
            vec.push_back({c, 1});
        }
        else if(++vec.back().second == k) {
            vec.pop_back();
        }
    } 

    std::string res;
    for(auto &e : vec) {
        res += std::string(e.second, e.first);
    }

    return res;
}

std::string removeDuplicateLetters(std::string s)
{
    std::vector<int> count(128,0), visited(128, 0);

    std::string res;

    for(const char &c : s) {
        count[c]++;
    }

    for(const char &c : s)
    {
        count[c]--;

        if(visited[c]) continue;

        while(!res.empty() && c < res.back() && count[res.back()]) {
            visited[res.back()] = 0;
            res.pop_back();
        }

        res += c;
        visited[c] = 1; 
    }

    return res;
}


//双指针解法

std::string compressstring(std::string s)
{
    if(s.empty()) return "";

    std::string res;
    int left = 0;

    for(int right = 0; right < s.size(); right++)
    {
        if(s[right] == s[left]) continue;
        else {
            res += s[left] + std::to_string(right - left);
            left = right;
        }
    }

    res += s[left] + std::to_string(s.size() - left);
    std::cout << res << std::endl;

    //判断压缩后的字符串是否大于原来字符串,如果大于就直接返回原字符串,如 "abc"压缩后为 "a1b1c1"大于压缩前的字符串
    return res.size() >= s.size() ? s : res;
}

int main() {
    std::string str = "aaabc";

    std::cout << compressstring(str) << std::endl;

    return 0;
}

std::string decodestring(std::string s)
{
    int i = 0;
    return dfs(s, i);
}

std::string dfs(const std::string &s, int &i)
{
    std::string res;

    while(i < s.size() && s[i] != ']') 
    {
        if(!isdigit(s[i++])) {
            res += s[i];
        }
        else {
            int n = 0;
            while(i < s.size() && isdigit(s[i])) {
                n = n*10 + (s[i++]-'0');
            }

            i++;    //跳过 '[',否则上面的if语句中的res会包含'['这个字符
            std::string tmp = dfs(s, i);
            i++;    //跳过 ']'

            while(n--) {
                res += tmp;
            }
        }
    }

    return res;
}


int main() {
    // std::map<char,int> mapX = {{'a',1}, {'b',2},{'c',3}};

    // for(auto &item : mapX) {
    //     if(item.second == 1) mapX.erase(item.first);
    // }

    // std::string str(0, 'a');
    // std::cout << str << std::endl;

    std::string str;

    std::cout << std::stol(str) << std::endl;


    return 0;
}

TreeNode *sortedArrayToBST(std::vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;

    return dfs(nums, left, right);
}

TreeNode *dfs(std::vector<int> &nums, int left, int right)
{
    if(left > right) return nullptr;

    int mid = left + ((right - left) >> 1);
    
    TreeNode *root = new TreeNode(nums[mid]);

    root->left = dfs(nums, left, mid - 1;);
    root->right = dfs(nums, mid + 1, right);

    return root;
}

void flattern(TreeNode *root)
{
    if(root == nullptr) return;

    flattern(root->left);
    flattern(root->right);

    TreeNode *pNode = root->right;
    root->right = root->left;
    root->left = nullptr;

    while(root->right) {
        root = root->right;
    }

    root->right = pNode;
}

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    for(int i = 0; i < nums.size(); i++)
    {
        if(i && nums[i] == nums[i-1]) continue;

        int left = i + 1, right = nums.size() - 1;

        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);

            int sum = nums[i] + nums[mid];
            if(sum == target) {
                return {i + 1, mid + 1};
            }
            else if(sum < target) {
                left = mid  + 1;
            }
            else if(sum > target) {
                right = mid - 1;
            }
        }
    }

    return {};
}


std::vector<int> findClosestElements(std::vector<int> &arr, int k, int x)
{
    int left = 0, right = arr.size() - 1;

    while(right - left >= k)
    {
        if(abs(arr[left]-x) > abs(arr[right]-x)) left++;
        else right--;
    }

    std::vector<int> res;
    for(int i = left; i <= right; i++) {
        res.push_back(arr[i]);
    }

    return res;
}


// 解法二： 二分查找 + 滑动窗口
// [0, n-k]之内查找，之后比较 A[mid] 和 A[mid+k]与 x 的差距

//          A[mid]     A[mid+k]
// 1.  x                           此时右边界左移  x - A[mid] < A[mid+k] - x
// 2.             x                此时右边界左移  x - A[mid] < A[mid+k] - x
// 3.                 x            此时左边界右移  x - A[mid] > A[mid+k] - x
// 4.                          x   此时左边界右移  x - A[mid] > A[mid+k] - x


std::vector<int> findClosestElements(std::vector<int> &arr, int k, int x)
{
    int left = 0, right = arr.size() - k;

    while(left < right)
    {
        int mid = left + ((right - left) >> 1);
        if(x - arr[mid] > arr[mid+k] - x) {
            left = mid + 1;
        }
        else right = mid;
    }

    return std::vector<int>(arr.begin() + left, arr.begin() + left + k);
}

bool isPalindrome(int x) 
{
    if(x < 0) return false;
    if(x == 0) return true;

    int res = 0, tmp = x;

    while(x) {
        if(res > INT_MAX/10 || (res == INT_MAX/10 && x%10 > 7)) return false;
        res = res*10 + x%10;
        x /= 10;
    }

    return res == tmp;
}

std::vector<std::vector<std::string>> res;

std::vector<std::vector<std::string>> partition(std::string s)
{
    std::vector<std::string> par;

    dfs(s, 0, par);
    
    return res;
}

void dfs(const std::string &s, int pos, std::vector<std::string> &par)
{
    if(pos == s.size()) {
        res.push_back(par);
        return;
    }

    for(int i = pos; i < s.size(); i++) {
        if(isPalindrome(s, pos, i)) {
            par.push(s.substr(pos, i - pos + 1));
            dfs(s, i + 1, par);
            par.pop_back();
        }
    }

}

bool isPalindrome(const std::string &s, int left, int right)
{
    while(left < right) {
        if(s[left++] != s[right--]) return false;
    }
    
    return true;
}


std::vector<std::vector<std::string>> res;

std::vector<std::vector<std::string>> partition(std::string s)
{
    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for(int i = n-1; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(s[i] == s[j] && (j-i <= 2 || dp[i+1][j-1])) {
                dp[i][j] = 1;
            }
        }        
    }

    std::vector<std::string> path;

    dfs(s, 0, dp, path);

    return res;
}

void dfs(const std::string &s, int pos, const std::vector<std::vector<int>> &dp, std::vector<std::string> &path)
{
    if(pos == s.size()) {
        res.push_back(path);
        return;
    }

    for(int i = pos; i < s.size(); i++)
    {
        if(dp[pos][i]) {
            path.push_back(s.substr(s, pos, i - pos + 1));
            dfs(s, i + 1, dp, path);
            path.pop_back();
        }
    }
}

int minCut(std::string s)
{
    int n = s.size();

    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    std::vector<int> minCut(n, n-1);

    for(int i = n-1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            if(s[i] == s[j] && (j-i <= 2 || dp[i+1][j-1]))
            {
                dp[i][j] = 1;

                if(j == n-1) {
                    minCut[i] = 0;
                }
                else {
                    minCut[i] = std::min(minCut[i], minCut[j+1] + 1);
                }
            }
        }
    }

    return minCut[0];
}

// dp[i][j] = dp[i+1][j-1] + 2, if s[i] == s[j]
// dp[i][j] = max(dp[i+1][j], dp[i][j-1]), else 

// base case: j - i < 2
// 只需处理 j=i的情况， j-i=1 的情况我们默认让dp[i][j](i>j) 全部赋值为0

int longestPalindrome(std::string s)
{
    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for(int i = n - 1; i >= 0; i--) {
        for(int j = i + 1; j < n; j++) {
            if(s[i] == s[j]) {
                dp[i][j] = dp[i+1][j-1] + 2;
            }
            else dp[i][j] = std::min(dp[i+1][j], dp[i][j-1]);
        }
    }

    return dp[0][n-1];
}

int longestPalindrome(std::string s)
{
    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for(int i = n-1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            if(s[i] == s[j]) {
                if(i == j) dp[i][j] = 1;
                else dp[i][j] = dp[i+1][j-1] + 2;
            }
            else dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
        }
    }

    return dp[0][n-1];
}

int countSubstrings(std::string s)
{
    int count = 0;

    for(int i = 0; i < s.size(); i++) {
        count += extendSubstrings(s, i, i);
        count += extendSubstrings(s, i, i + 1);
    }

    return count;
}

int extendSubstrings(std::string &s, int left, int right)
{
    int count = 0;

    while(left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
        count++;
    }

    return count;
}

int countSubstrings(std::string s)
{
    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    int count = 0;

    for(int i = n-1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            if(s[i] == s[j] && (j-i <= 2 || dp[i+1][j-1])) {
                dp[i][j] = 1;
                count++;
            }
        }
    }

    return count;
}


ListNode* removeNthFromEnd(ListNode *head, int n)
{
    ListNode *base = new ListNode(-1);
    base->next = head;

    ListNode *slow = base, *fast = base;

    for(int i = 0; i < n; i++) {
        fast = fast->next;
        if(fast == nullptr) return head;
    }

    while(fast && fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return base->next;
}

ListNode* deleteDuplicate(ListNode *head)
{
    if(head == nullptr) return head;

    ListNode *cur = head;

    while(cur && cur->next) 
    {
        if(cur->val == cur->next->val) {
            cur->next = cur->next->next;
        }
        else {
            cur = cur->next;
        }
    }

    return head;
}

struct Cmp {
    bool operator()(const ListNode *l1, const ListNode *l2) {
        return l1->val > l2->val;
    }
};


ListNode* mergeKLists(std::vector<ListNode*> &lists)
{
    std::priority_queue<ListNode*, std::vector<ListNode*>, Cmp> pq;

    for(auto &list : lists) {
        if(list) pq.push(list);
    }

    ListNode *base = new ListNode(-1);
    ListNode *cur = base;

    while(!pq.empty())
    {
        ListNode *pNode = pq.top(); pq.pop();
        cur->next = pNode;
        cur = cur->next;

        if(pNode->next) {
            pq.push(pNode->next);
        }
    }

    return base->next;
}

ListNode* mergeKLists(std::vector<ListNode*> &lists)
{
    int len = lists.size();

    for(int i = 0; i < len/2; i++) {
        lists[i] = mergeTwoLists(lists[i], lists[len-1-i]);
        len = (len + 1) >> 1;
    }

    return lists.front();
}

ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) 
{
    if(l1 == nullptr) return l2;
    else if(l2 == nullptr) return l1;

    if(l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }

    return nullptr;
}


ListNode *detectCycle(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *slow = head, *fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            ListNode *pNode = head;
            while(slow != pNode) {
                slow = slow->next;
                pNode = pNode->next;
            }
            return pNode;
        }
    }

    return nullptr;
}

std::vector<int> preorderTraversal(TreeNode *root)
{
    std::vector<int> res;

    if(root == nullptr) return res;

    std::stack<TreeNode*> sta;
    sta.push(root);

    while(!sta.empty())
    {
        TreeNode *pNode = sta.top(); sta.pop();
        res.push_back(pNode->val);

        if(pNode->right) {
            sta.push(pNode->right);
        }
        if(pNode->left) {
            sta.push(pNode->left);
        }
    }

    return res;
}

std::vector<int> preorderTraversal(TreeNode *root)
{
    std::vector<int> res;

    if(root == nullptr) return res;

    std::stack<TreeNode*> sta;
    sta.push(root);

    while(!sta.empty())
    {
        TreeNode *pNode = sta.top(); sta.pop();
        res.push_back(pNode->val);

        if(pNode->left) {
            sta.push(pNode->left);
        }
        if(pNode->right) {
            sta.push(pNode->right);
        }
    }

    reverse(res.begin(), res.end());

    return res;
}

std::vector<int> inorderTraversal(TreeNode *root)
{
    std::vector<int> res;
    if(root == nullptr) return res;

    std::stack<TreeNode*> sta;
    TreeNode *pNode = root;

    while(!sta.empty() || pNode)
    {
        while(pNode) {
            sta.push(pNode);
            pNode = pNode->left;
        }

        pNode = sta.top(); sta.pop();
        res.push_back(pNode->val);

        pNode = pNode->right;
    }

    return res;
}

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root)
{
    std::vector<std::vector<int>> res;
    if(root == nullptr) return res;

    std::queue<TreeNode*> que;
    que.push(root);

    int flag = 0;

    while(!que.empty())
    {
        std::vector<int> tmp;
        for(int size = que.size(); size >= 0; size--)
        {
            TreeNode *pNode = que.front(); que.pop();
            tmp.push_back(pNode->val);

            if(pNode->left) que.push(pNode->left);
            if(pNode->right) que.push(pNode->right);
        }

        if(flag) {
            reverse(tmp.begin(), tmp.end());
        }
        res.push_back(tmp);

        flag = 1 - flag;
    }

    return res;
}

TreeNode* buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
{
    std::unordered_map<int,int> inorderPos;
    for(int i = 0; i < inorder.size(); i++) {
        inorderPos[inorder[i]] = i;
    }

    return buildTreeCore(preorder, 0, preorder.size() - 1, 0, inorderPos);
}

TreeNode* buildTreeCore(const std::vector<int> &preorder, int startProrder, int endPreorder, int startInorder, const std::unordered_map<int,int> &inorderPos)
{
    if(startProrder > endPreorder) {
        return nullptr;
    }

    int rootIndex = inorderPos[preorder[startProrder]];

    int leftLen = rootIndex - startInorder;

    TreeNode *root = new TreeNode(preorder[startProrder]);

    root->left = buildTreeCore(preorder, startProrder + 1, startProrder + leftLen, startIndex, inorderPos);

    root->right = buildTreeCore(preorder + leftLen + 1, endPreorder, rootIndex + 1, inorderPos);

    return root;
}


TreeNode* buildTree(std::vector<int> &inorder, std::vector<int> &postorder)
{
    std::unordered_map<int,int> inorderPos;
    for(int i = 0; i < inorder.size(); i++) {
        inorderPos[inorder[i]] = i;
    }

    return buildTreeCore(postorder, 0, postorder.size() - 1, 0, inorderPos);
}

TreeNode* buildTreeCore(std::vector<int> &postorder, int startPostorder, int endPostorder, int startInorder, std::unordered_map<int,int> &inorderPos)
{
    if(startPostorder > endPostorder) return nullptr;

    int rootIndex = inorderPos[postorder[endPostorder]];

    int leftLen = rootIndex - startInorder;

    TreeNode *root = new TreeNode(postorder[endPostorder]);

    root->left = buildTreeCore(postorder, startPostorder, startPostorder + leftLen - 1, startInorder, inorderPos);

    root->right = buildTreeCore(postorder, startPostorder + leftLen, endPostorder-1, rootIndex + 1, inorderPos);

    return root;
}

class LRUCache
{
    std::list<std::pair<int,int>> cache;
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> hash;
    int size;

public:
    LRUCache(int capacity) : size(capacity) {}

    int get(int key)
    {
        auto it = hash.find(key);
        if(it == hash.end()) return -1;

        cache.splice(cache.begin(), it, it->second);

        return cache.front().second;
    }

    void put(int key, int value)
    {
        auto it = hash.find(key);
        if(it == hash.end()) {
            cache.push_front({key, value});
            hash[key] = cache.begin();
            if(cache.size() > size) {
                hash.erase(cache.back().first);
                cache.pop_back();
            }
        }

        it->second->second = value;
        cache.splice(cache.begin(), it, it->second);
    }

};


int findNum(std::vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);
        
        if(nums[mid] <= target) {
            left = mid + 1;
        }
        else if(nums[mid] > target) {
            right = mid - 1;
        }
    }

    return right;
}

std::string longestPalindrome(std::string s)
{
    if(s.empty()) return s;

    int maxLen = 0, startIndex = 0;

    int i = 0;
    while(i < s.size())
    {
        int start = i, end = i;

        while(end + 1 < s.size() && s[end] == s[end+1]) end++;

        i = end + 1;

        while(start-1 >= 0 && end+1 < s.size() && s[start-1] == s[end+1]) {
            start--;
            end++;
        }

        if(end - start + 1 > maxLen) {
            maxLen = end - start + 1;
            startIndex = start;
        }
    }

    return s.substr(startIndex, maxLen);
}

int maxSubArrayCircular(std::vector<int> &nums)
{
    int maxSum = 0, finMaxSum = 0;
    int minSum = 0, finMinSum = 0;

    for(const int &n : nums)
    {
        maxSum += n;
        maxSum = std::max(n, maxSum);
        finMaxSum = std::max(finMaxSum, maxSum);

        minSum += n;
        minSum = std::min(minSum, n);
        finMinSum = std::min(finMinSum, minSum);
    }

    int total = accumulate(nums.begin(), nums.end(), 0);

    if(finMinSum == total) return finMaxSum;

    return std::max(finMaxSum, total - finMinSum);
}




int main() {
    std::unordered_set<int> mySet = {1,2,3};

    for(const int &n : mySet) {
        std::cout << n << std::endl;
    }

    return 0;
}


class UF
{
    std::vector<int> size;  //记录每一颗树的重量
    std::vector<int> parent;

public:
    UF(int n)
    {
        size.resize(n);
        parent.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    void findNode(int x)
    {
        while(parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }

        return x;
    }

    

};


std::map<int,int> parent;

std::map<int,std::vector<int>> mp;

int findNode(int x)
{
    while(parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }

    return x;
}

void unionNode(int x, int y)
{
    if(!parent.count(x)) {
        parent[x] = x;
    }
    if(!parent.count(y)) {
        parent[y] = y;
    }

    int m_x = findNode(x);
    int m_y = findNode(y);

    parent[m_y] = m_x;
}

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &arr)
{
    std::vector<std::vector<int>> res;
 
    for(auto &nums : arr)
    {
        if(nums.size() == 1) mp[nums[0]].push_back(nums[0]);
        else {
            for(int i = 1; i < nums.size(); i++)
            {
                unionNode(nums[0], nums[i]);
            }
        }
    }

    for(auto &item : parent) {
        mp[findNode(item.first)].push_back(item.first);
    }

    for(auto item : mp) {
        res.push_back(item.second);
    }

    return res;
}


int main()
{
    std::vector<std::vector<int>> arr = {{1,2,3}, {3,5,4}, {8,6}, {3,6}, {7,222}, {7,32}}; 
    // std::vector<std::vector<int>> arr = {{8,6},{3,6}}; 



    std::vector<std::vector<int>> res = merge(arr);
    // std::cout << parent[6] << std::endl;

    for(auto &nums : res) {
        for(auto &n : nums) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


std::string shortestPalindrome(std::string s)
{
    int maxLen = 0;

    for(int i = 0; i < s.size()/2; i++)
    {
        int start = i, end = i;
        while(end + 1 < s.size() && s[end] == s[end+1]) end++;
        i = end;

        while(start-1 >= 0 && end + 1 < s.size() && s[start-1] == s[end+1]) {
            start--;
            end++;
        }

        if(start == 0) {
            maxLen = std::max(maxLen, end - start + 1);
        }
    }

    std::string remain = s.substr(maxLen);
    reverse(remain.begin(), reamin.end());

    return reamin + s;
}

int longestPalindrome(std::string s)
{
    std::unordered_set<char> mySet;
    int count = 0;

    for(char &c : s)
    {
        if(mySet.count(c)) {
            count++;
            mySet.erase(c);
        }
        else mySet.insert(c);
    }

    return mySet.empty() ? 2*count : 2*count + 1;
}

int minInsertions(std::string s)
{
    int n = s.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
    
    std::string str = s;
    reverse(str.begin(), str.end());

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == str[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return n - dp[n][n];
}


//Leetcode第336题: 字符串回文对数

// 1.如果s1空字符串,则对任何回文字符串s2,(s1+s2),(s2+s1)都是回文串
// 2.如果s2是s1的逆序字符串,则(s1+s2)和(s2+s1)都是回文串
// 3.如果s1[0:cut]是回文串,并且存在s2是s1[cut+1:]的逆字符串,则s2+s1是回文串
// 4.如果s1[cut+1:]是回文串,并且存在s2是s1[0:cut]的逆字符串,则s1+s2是回文串

std::vector<std::vector<int>> palindromePairs(std::vector<std::string> &words)
{
    std::unordered_map<std::string, int> mp;    //字符串对应的下标
    std::vector<std::vector<int>> res;

    for(int i = 0; i < words.size(); i++) {
        auto key = words[i];
        reverse(key.begin(), key.end());
        mp[key] = i;
    }

    //先处理空字符串情况
    if(mp.count(""))
    {
        for(int i = 0; i < words.size(); i++) {
            if(mp[words[i]] == i) continue;
            if(isPalindrome(words[i])) res.push_back({mp[""], i});
        }
    }

    for(int i = 0; i < words.size(); i++)
    {
        for(int j = 0; j < words[i].size(); j++)    //如何是空字符串,size=0,不会进入到这个循环中
        {
            std::string left = words[i].substr(0,j);
            std::string right = words[i].substr(j);

            // j = 0就对应第二种情况

            //对应情况4
            if(mp.count(left) && isPalindrome(right) && mp[left] != i) {
                res.push_back({i, mp[left]});
            }

            //对应情况3
            if(mp.count(right) && isPalindrome(left) && mp[right] != i) {
                res.push_back({mp[right], i});
            }
        }
    }

    return res;
}


bool isPalindrome(const std::string &s)
{
    int i = 0, j = s.size() - 1;

    while(i < j) {
        if(s[i++] != s[j--]) return false;
    }

    return true;
}

//Leetcode第680题: 判断字符串只删除一个字符能否组成回文串

// 思路: 双指针直接遍历,发现第一个不相同的字符略过,之后再继续遍历再有不相同则直接返回false

bool validPalindrome(std::string s)
{
    int left = 0, right = s.size() - 1;

    while(left < right)
    {
        if(s[left] != s[right])
        {
            int i1 = left + 1, j1 = right;        //考虑两种情况,需要略过左侧字符还是右侧字符
            int i2 = left, j2 = right - 1;

            while(i1 < j1 && s[i1] == s[j1]) { i1++; j1--; }
            while(i2 < j2 && s[i2] == s[j2]) { i2++; j2--; }

            return i1 >= j1 || i2 >= j2;    //有一种情况满足即可
        }
        left++;
        right--;
    }

    return true;
}


//dp[i] = max(dp[i-1], dp[i-2] + nums[i])
//dp[0] = 0, dp[1] = nums[0]

int rob(std::vector<int> &nums)
{
    int n = nums.size();
    std::vector<int> dp(n + 1, 0);
    dp[1] = nums[0];

    for(int i = 2; i <= n; i++) {
        dp[i] = std::max(dp[i-1], dp[i-2] + nums[i-1]);
    }

    return dp[n];
}

int rob(std::vector<int> &nums)
{
    int n = nums.size();

    int first = 0, second = nums[0];
    int cur = second;

    for(int i = 1; i < nums.size(); i++) {
        cur = std::max(second, nums[i] + first);
        first = second;
        second = cur;
    }

    return cur;
}


int rob(std::vector<int> &nums)
{
    if(nums.size() == 1) return nums[0];

    return std::max(robCore(nums, 0, nums.size() - 2), robCore(nums, 1, nums.size() - 1));
}

int robCore(std::vector<int> &nums, int left, int right)
{
    int first = 0, second = nums[left];
    int cur = second;

    for(int i = left + 1; i <= right; i++) {
        cur = std::max(second, first + nums[i]);
        first = second;
        second = cur;
    }

    return cur;
}

std::unordered_map<TreeNode*, int> map;

int rob(TreeNode *root)
{
    if(root == nullptr) return 0;

    if(map.count(root)) return map[root];

    //偷根节点
    int money1 = root->val;
    if(root->left) money1 += rob(root->left->left) + rob(root->left->right);
    if(root->right) money1 += rob(root->right->left) + rob(root->right->right);

    //不偷根节点
    int money2 = rob(root->left) + rob(root->right);

    map[root] = std::max(money1, money2);

    return map[root];
}

std::vector<int> findDuplicate(std::vector<int> &nums)
{
    std::vector<int> res;

    for(int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;
        if(nums[index] > 0) nums[index] = -nums[index];
        else res.push_back(abs(nums[i]));
    }

    return res;
}

//二分查找

// count(mid) <= mid, 说明重复元素在右侧 left = mid + 1, 且mid不是重复元素
// count(mid) > mid, 说明重复元素在左侧, right = mid, mid有可能是重复元素



int findDuplicate(std::vector<int> &nums)
{
    int left = 1, right = nums.size() - 1;

    while(left < right)
    {
        int mid = left + ((right - left) >> 1);
        int count = 0;
        for(const int &n : nums) {
            if(n <= mid) count++;
        }

        if(count <= mid) left = mid + 1;
        else right = mid;
    }

    return left;
}

int findDuplicate(std::vector<int> &nums)
{
    int slow = nums[0], fast = nums[nums[0]];

    while(slow != fast)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    int finder = 0;
    while(nums[finder] != nums[slow]) {
        finder = nums[finder];
        slow = nums[slow];
    }

    return nums[finder];
}



#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <sstream>
#include <queue>
#include <unordered_set>
#include <list>
#include <iterator>
#include <cstring>
#include <set>
#include <map>
#include <numeric>
#include <stack>

struct vector {
    int X;
    int Y;
};

class Character
{
    std::string name;
    vector position;

public:
    Character() {
        this->position = new vector();
    }

};


/*
class Point {
public:
    void initPoint(float x = 0, float y = 0) {
        this->x = x;
        this->y = y;
    }
    
    void move(float offX, float offY) {
        x += offX;
        y += offY;
    }
    
    float getX() const { return x; }
    float getY() const { return y; }

private:
    float x, y;
};

class Rectangle : private Point {
public:
    void initRectangle(float x, float y, float w, float h) {
        initPoint(x, y);
        this->w = w;
        this->h = h;
    }

    float getH() const { return h; }
    float getW() const { return w; }

private:
    float w, h;
};

class Base {
public:
    Base() {}
    Base(int m_val) : val(m_val) {}
    int val;
};

class Derived : public Base {
public:
    Derived(int m_val) :val(m_val) {
        // val = m_val;
    }
};

/*

class Base1 {
public:
    void display() const { std::cout << "Base1" << std::endl; }
};

class Base2 : public Base1 {
public:
    void display() const { std::cout << "Base2" << std::endl; }
};

class Derived : public Base2 {
public:
    void display() const { std::cout << "Derived" << std::endl; }
};


int main() {

    Derived d(2);

    // Base1 b1;
    // Base2 b2;
    // Derived d;

    // Base1 *ptr = &d;

    // ptr->display();

    // Rectangle rec;
    // rec.initRectangle(1,2,3,4);
    // std::cout << rec.getX() << std::endl;

    // Derived d(2);
    // std::cout << d.val << std::endl;

    return 0;
}


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


int maxProfit(std::vector<int> &prices)
{
    int minPrice = INT_MAX, maxProfit = INT_MIN;

    for(const int &n : prices) {
        minPrice = std::min(n, minPrice);
        maxProfit = std::max(maxProfit, n - minPrice);
    }

    return maxProfit;
}

int maxProfit(std::vector<int> &prices)
{
    int n = prices.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2,0));

    dp[0][0] = 0;
    dp[0][1] = INT_MIN;

    for(int i = 1; i <= n; i++) {
        dp[i][0] = std::max(dp[i-1][0], dp[i-1][1] + prices[i-1] - fee);
        dp[i][1] = std::max(dp[i-1][1], dp[i-1][0] - prices[i-1]);
    }

    return dp[n][0];
}


int maxProfit(std::vector<int> &prices)
{
    int n = prices.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2,0));

    int first = 0, second = INT_MIN;

    for(int i = 1; i <= n; i++) {
        int tmp = first;
        first = std::max(first, second + prices[i-1]);
        second = std::max(second, tmp - prices[i-1]);
    }

    return first;
}

int maxProfit(std::vector<int> &prices)
{
    int n = prices.size();

    int dp[n+1][3][2] = {0};

    for(int i = 1; i <= n; i++)
    {
        for(int k = 0; k <= 2; k++)
        {
            if(i == 0 || k == 0) {
                dp[i][k][1] = INT_MIN;
                continue;
            }
            dp[i][k][0] = std::max(dp[i-1][k][0], dp[i-1][k][1] + prices[i-1]);
            dp[i][k][1] = std::max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i-1]);
        }
    }

    return dp[n][2][0];
}

int compress(std::vector<char> &chars)
{
    if(chars.empty()) return 0;

    std::string res;
    int left = 0;

    for(int right = 0; right < chars.size(); right++)
    {
        if(chars[right] == chars[left]) continue;
        else {
            res += chars[left] + std::to_string(right - left);
            left = right;
        }
    }

    res += chars[left] + std::to_string(right - left);

    return res.size() > chars.size() ? chars.size() : res.size();
}

int compress(std::vector<char> &chars)
{
    if(chars.empty()) return 0;

    int left = 0;

    for(int right = 0; right < chars.size();)
    {
        chars[left] = chars[right];     //这个一定不要忘记了
        int count = 0;
        while(right < chars.size() && chars[right] == chars[left]) {
            count++;
            right++;
        }
        
        if(count != 1) {
            std::string str = std::to_string(count);
            for(char &c : str) {
                chars[++left] = c;
            }
            left++;
        }
        else if(count == 1) left++;
    }

    return left;
}

int subarraySum(std::vector<int> &nums, int k)
{
    std::unordered_map<int,int> hash;
    hash[0] = 1;

    int sum = 0, count = 0;

    for(const int &n : nums) {
        sum += n;
        count += hash[sum-k];
        hash[sum]++;
    }

    return count;
}


ListNode* partition(ListNode *head, int x)
{
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *l1 = new ListNode(-1);
    ListNode *l2 = new ListNode(-2);
    ListNode *head1 = l1, *head2 = l2;

    while(head) 
    {
        if(head->val < x) {
            l1->next = head;
            l1 = l1->next;
        }
        else {
            l2->next = head;
            l2 = l2->next;
        }

        head = head->next;
    }

    l1->next = head2->next;
    l2->next = nullptr;
    
    return head1;
}


ListNode *reverseBetween(ListNode *head, int left, int right)
{
    ListNode *base = new ListNode(-1);
    base->next = head;

    ListNode *cur = base;

    ListNode *prev = nullptr, *tail = nullptr;

    for(int i = 0; i < right; i++) {
        if(i == left - 1) prev = cur;
        cur = cur->next;
    }

    tail = cur->next;

    ListNode *reverseList = reverse(prev->next, tail);

    ListNode *pNode = prev->next;
    prev->next = reverseList;
    pNode->next = tail;

    return base->next;
}

ListNode *reverse(ListNode *head, ListNode *tail)
{
    ListNode *prev = nullptr;

    while(head && head != tail) {
        ListNode *pNext = head->next;
        head->next = prev;
        prev = head;
        head = pNext;
    }

    return prev;
}



int fun1(int i) {
    return i <= 1 ? 1 : fun1(i-1) + fun1(i-3);
}

int fun2(unsigned int i) {
    return ((i >> 4) | 2021) | (((i<<4)|831)>>4);
}

int main() {
    int n = fun2(fun1(101))%4;
    std::cout << n << std::endl;

    return 0;

}

ListNode* deleteDuplicates(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *base = new ListNode(-1);
    base->next = head;

    ListNode *cur = base;

    while(cur->next && cur->next->next)
    {
        if(cur->next->val == cur->next->next->val) {
            int value = cur->next->val;
            ListNode *pNode = cur->next;
            while(pNode && pNode->val == value) {
                pNode = pNode->next;
            }
            cur->next = pNode;
        }
        else {
            cur = cur->next;
        }
    }

    return base->next;
}



//思路:
//1.计算出所有1围成的面积,将所围区域上的所有点标上记号
//2.之后遍历找到为0的位置,将该位置的上下左右四个方向的面积相加即可求出最大值



int dfs(std::vector<std::vector<int>> &grid, int i, int j, int index);

std::vector<int> dir = {-1, 0, 1, 0, -1};

int largestIsland(std::vector<std::vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    std::unordered_map<int,int> area;   //标号及其对应的最大面积
    int index = 2, res = 0;             //标号从2开始

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) {
                area[index] = dfs(grid, i, j, index);
                res = std::max(res, area[index++]);     //单个最大面积(可能所有的图形都没有连接)
            }
        }
    }

    //遍历所有的0元素判断其连接的最大面积
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 0) 
            {
                std::unordered_set<int> seen;   //防止落在其中一个区域的正中央
                int cur = 1;
                for(int k = 0; k < dir.size() - 1; k++) {
                    int x = i + dir[k], y = j + dir[k+1];
                    if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 1 && !seen.count(grid[x][y])) {
                        seen.insert(grid[x][y]);
                        cur += area[grid[x][y]];
                    }
                }
                res = std::max(res, cur);
            }
        }
    }

    return res;
}


int dfs(std::vector<std::vector<int>> &grid, int i, int j, int index)
{
    int m = grid.size(), n = grid[0].size();

    grid[i][j] = index;

    int area = 1;

    for(int k = 0; k < dir.size() - 1; k++) {
        int x = i + dir[k], y = j + dir[k+1];
        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
            area += dfs(grid, x, y, index);
        }
    }

    return area;
}

int main() {
    std::vector<std::vector<int>> grid = {{1,0},{0,1}};

    std::cout << largestIsland(grid) << std::endl;

    return 0;
}


std::vector<std::vector<int>> cache;

std::vector<int> dir = {-1,0,1,0,-1};

int longestIncreasingPath(std::vector<std::vector<int>> &matrix)
{
    int m = matirx.size(), n = matirx[0].size();

    cache = std::vector<std::vector>(m, std::vector<int>(n));

    int res = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            res = std::max(res, dfs(matrix, i, j));
        }
    }

    return res;
}

int dfs(std::vector<std::vector<int>> &matrix, int i, int j)
{
    int m = matirx.size(), n = matirx[0].size();

    if(cache[i][j]) return cache[i][j];

    int ans = 1;

    for(int k = 0; k < dir.size() - 1; k++) {
        int x = i + dir[k], y = j + dir[k+1];
        if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] < matrix[i][j]) {
            ans = std::max(ans, 1 + dfs(matrix, x, y));
        }
    }

    cache[i][j] = ans;

    return ans;
}

std::vector<std::vector<int>> res;

std::vector<std::vector<int>> permute(std::vector<int> &nums)
{
    dfs(nums, 0);

    return res;   
}

void dfs(std::vector<int> &nums, int pos)
{
    if(pos == nums.size()) {
        res.push_back(nums);
        return;
    }

    for(int i = pos; i < nums.size(); i++) {
        std::swap(nums[i], nums[pos]);
        dfs(nums, pos + 1);
        std::swap(nums[i], nums[pos]);
    }

}


ListNode *reverseList(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return head;

    return dfs(head, nullptr);
}

ListNode* dfs(ListNode *head, ListNode *prev)
{
    if(head == nullptr) return prev;

    ListNode *pNext = head->next;

    head->next = prev;

    return dfs(pNext, head);
}


std::vector<int> dir = {-1,0,1,0,-1};

std::vector<std::vector<int>> cache;

int dfs(std::vector<std::vector<int>> &mat, int i, int j);

std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();

    cache = std::vector<std::vector<int>>(m, std::vector<int>(n));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == 1) {
                mat[i][j] = dfs(mat, i, j);
            }
        }
    }

    return mat;
}

int dfs(std::vector<std::vector<int>> &mat, int i, int j)
{
    int m = mat.size(), n = mat[0].size();

    if(mat[i][j] == 0) return 0;

    if(cache[i][j]) return cache[i][j];

    int ans = INT_MAX;

    for(int k = 0; k < dir.size() - 1; k++) {
        int x = i + dir[k], y = j + dir[k+1];
        if(x >= 0 && x < m && y >= 0 && y < n) {
            ans = std::min(ans, 1 + dfs(mat, x, y));
        }
    }

    cache[i][j] = ans;

    return ans;
}


int main() {
    std::vector<std::vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};

    updateMatrix(mat);

    for(auto &nums : mat) {
        for(auto &n : nums) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


//Leetcode第542题: 01 Matrix

//方法一:
//BFS搜索,将所有的'0'加入到队列中,之后判断0到其周边元素的距离
//1.新的距离大于已有距离时不用更新
//2.将所有不是0的点距离全部写成INF

std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();

    std::queue<std::pair<int,int>> que;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matirx[i][j] == 0) {
                que.push({i,j});
            }
            else matrix[i][j] = INT_MAX;        //否则中间被1包围的节点改变不了
        }
    }

    std::vector<int> dir = {-1,0,1,0,-1};

    while(!que.empty())
    {
        auto cur = que.front(); que.pop();
        for(int k = 0; k < dir.size() - 1; k++){
            int x = cur.first + dir[k], y = cur.second + dir[k+1];
            if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[cur.first][cur.second] + 1) {
                que.push({x,y});
                matrix[x][y] = matrix[cur.first][cur.second] + 1
            }
        }
    }

    return mat;
}


//方法二:动态规划

std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, m*n));  //这里写成INF下面相加会溢出

    //从左上到右下
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == 0) dp[i][j] = 0;
            else {
                if(j > 0) dp[i][j] = std::min(dp[i][j], dp[i][j-1] + 1);    // -->
                if(i > 0) dp[i][j] = std::min(dp[i][j], dp[i-1][j] + 1);    //  |
            }                                                               
        }
    }

    //从右下到左上 dp[0][0] 位置在这里被计算
    for(int i = m-1; i >= 0; i--) {
        for(int j = n -1; j >= 0; j--) {
            if(mat[i][j]) {
                if(j < n-1) dp[i][j] = std::min(dp[i][j], dp[i][j+1] + 1);
                if(i < m-1) dp[i][j] = std::min(dp[i][j], dp[i+1][j] + 1);
            }
        }
    }

    return dp;
}



int slidingPuzzle(std::vector<std::vector<int>> &board)
{
    int m = board.size(), n = board[0].size();

    std::string target = "123450";

    std::string start = "";
    for(auto &nums : board) {
        for(auto &n : nums) {
            start += std::to_string(n);
        }
    }

    std::vector<std::vector<int>> dir = {{1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}};

    std::unordered_set<std::string> visited;
    std::queue<std::string> que;
    que.push(start);
    visited.insert(start);

    int steps = 0;

    while(!que.empty())
    {
        for(int size = que.size(); size > 0; size--)
        {
            auto cur = que.front(); que.pop();

            if(cur == target) return steps;

            int index = cur.find('0');

            for(int &n : dir[index]) 
            {
                std::swap(cur[index], cur[n]);
                if(!visited.count(cur)) {
                    que.push(visited);
                    visited.insert(cur);
                }
                std::swap(cur[index], cur[n]);
            }
        }
        
        steps++;
    }

    return -1;
}


int main() {


    return 0;
}


std::vector<int> ans;
std::vector<std::vector<int>> res;

void dfs(int num, std::vector<std::vector<int>> &graph, std::vector<int> &indegree, std::vector<int> &visited);

std::vector<std::vector<int>> topologySort(int num, std::vector<std::vector<int>> &prere)    
{
    std::vector<std::vector<int>> graph(num + 1);
    std::vector<int> indegree(num + 1);

    for(auto &e : prere) {
        graph[e[0]].push_back(e[1]);
        indegree[e[1]]++;
    }

    std::vector<int> visited(num + 1, 0);

    dfs(num, graph, indegree, visited);

    return res;
}


void dfs(int num, std::vector<std::vector<int>> &graph, std::vector<int> &indegree, std::vector<int> &visited)
{
    if(ans.size() == num) {
        res.push_back(ans);
        return;
    }

    for(int i = 1; i <= num; i++)
    {
        if(!visited[i] && indegree[i] == 0)
        {
            ans.push_back(i);
            visited[i] = 1;
            for(const int &n : graph[i]) {
                indegree[n]--;
            }

            dfs(num, graph, indegree, visited);

            ans.pop_back();
            visited[i] = 0;
            for(const int &n : graph[i]) {
                indegree[n]++;
            }
        }
    }

}

int main() {
    std::vector<std::vector<int>> prere = {{1,2},{1,3},{2,4},{2,5},{3,4},{3,5},{4,6},{5,6}};

    topologySort(6, prere);

    for(auto &nums: res) {
        for(auto &n : nums) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}

int thridMax(std::vector<int> &nums)
{
    std::set<int> mySet;

    for(const int &n : nums) {
        mySet.insert(n);
        if(mySet.size() > 3) mySet.erase(mySet.begin());
    }

    return mySet.size() == 3 ? *mySet.begin() : *mySet.rbegin();
}

//
// x < y < z  -INF
// z < n, x = y, y = z, z = n
// y < n < z, x = y, y = n
// x < n < y, x = n

int thridMax(std::vector<int> &nums)
{
    int x, y, z;
    x = y = z = LONG_MIN;

    for(int &n : nums) {
        if(n > z) {
            x = y;
            y = z;
            z = n;
        }
        else if(y < n < z) {
            x = y;
            y = n;
        }
        else if(x < n < y) {
            x = n;
        }
    }

    return x == LONG_MIN ? z : x;
}


std::vector<int> findClosestElements(std::vector<int> &arr, int k, int x)
{
    int left = 0, right = arr.size() - k;

    while(left < right)
    {
        int mid = left + ((right - left) >> 1);
        if(x - arr[mid] > arr[mid+k] - x) {
            left = mid + 1;
        }
        else right = mid;
    }

    return std::vector<int>(arr.begin() + left, arr.begin() + left + k);
}

int firstMissingPositive(std::vector<int> &nums)
{
    for(int i = 0; i < nums.size(); i++)
    {
        while(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1]) {
            swap(nums[i], nums[nums[i]-1]);
        }
    }

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != i + 1) return i+1;
    }

    return nums.size() + 1;
}

bool hasPathSum(TreeNode *root, int target)
{
    if(root == nullptr) return false;

    if(root->left == nullptr && root->right == nullptr && root->val == target) return true;

    return hasPathSum(root->left, target - root->val) || hasPathSum(root->right, target - root->val);
}


std::vector<std::vector<int>> res;

std::vector<std::vector<int>> pathSum(TreeNode *root, int tartet)
{
    if(root == nullptr) return res;

    std::vector<int> path;
    dfs(root, target, path);

    return res;
}

void dfs(TreeNode *root, int target, std::vector<int> &path)
{
    if(root == nullptr) return;

    path.push_back(root->val);

    if(root->left == nullptr && root->right == nullptr && root->val == target) {
        res.push_back(path);
    }

    dfs(root->left, target - root->val, path);
    dfs(root->right, target - root->val, path);

    path.pop_back();
}


int pathSum(TreeNode *root, int target)
{
    if(root == nullptr) return 0;

    return dfs(root, target) + pathSum(root->left, target) + pathSum(root->right, target);
}

int dfs(TreeNode *root, int target)
{
    if(root == nullptr) return 0;

    int count = root->val == target ? 1 : 0;

    return count + dfs(root->left, target - root->val) + dfs(root->right, target - root->val);
}

int maxLen = 0;

int longestUnivaluePath(TreeNode *root)
{
    if(root == nullptr) return 0;

    dfs(root);

    return maxLen;
}


int dfs(TreeNode *root)
{
    if(root == nullptr) return 0;

    int left = dfs(root->left);
    int right = dfs(root->right);

    int leftLen = (root->left && root->val == root->left->val) ? left + 1 : 0;
    int rightLen = (root->right && root->val == root->right->val) ? right + 1 : 0;

    maxLen = std::max(maxLen, leftLen + rightLen);

    return std::max(leftLen, rightLen);
}


std::vector<std::string> res;

std::vector<std::string> binaryTreePaths(TreeNode *root)
{
    if(root == nullptr) return res;

    dfs(root, "");

    return res;
}

void dfs(TreeNode *root, std::string path)
{
    if(root == nullptr) return;

    if(root->left == nullptr && root->right == nullptr) {
        path += std::to_string(root->val);
        res.push_back(path);
    }

    dfs(root->left, path + to_string(root->val) + "->" );
    dfs(root->right, path + to_string(root->val) + "->" );

}


std::vector<int> res;

std::vector<int> numSameConsecDiff(int n, int k)
{
    for(int i = 1; i < 10; i++) {
        dfs(i, 1, n, k);
    }

    return res;
}

void dfs(int prev, int pos, int n, int k)
{
    if(pos == n) {
        res.push_back(prev);
        return;
    }

    int num = prev%10 + k;
    if(num < 10) {
        dfs(prev*10 + num, pos + 1, n, k);
    }

    num = prev%10 - k;
    if(k && num >= 0) {
        dfs(prev*10 + num, pos + 1, n, k);
    }

}


std::vector<int> numSameConsecDiff(int n, int k)
{
    std::vector<int> cur = {1,2,3,4,5,6,7,8,9};

    for(int i = 2; i <= n; i++)
    {
        std::vector<int> tmp;
        for(const int &x : cur) {
            int y = x%10;
            if(y + k < 10) {
                tmp.push_back(x*10 + y+k;)
            }
            if(k && y - k >= 0) {
                tmp.push_back(x*10 + y - k);
            }
        }
        cur = tmp;
    }

    return cur;
}



int main() {
    int n = 2, k = 0;

    numSameConsecDiff(n, k);

    for(const int &n : res) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}

int maxSum = INT_MIN;

int maxPathSum(TreeNode *root)
{
    if(root == nullptr) return 0;

    dfs(root);

    return maxSum;
}

int dfs(TreeNode *root)
{
    if(root == nullptr) return 0;

    int leftLen = std::max(0, dfs(root->left));
    int rightLen = std::max(0, dfs(root->right));

    maxSum = std::max(maxSum, root->val + leftLen + rightLen);

    return std::max(leftLen, rightLen) + root->val;
}


int res = INT_MIN;

int diameterOFBinaryTree(TreeNode *root)
{
    if(root == nullptr) return 0;

    dfs(root);

    return res;
}

int dfs(TreeNode *root)
{
    if(root == nullptr) return 0;

    int leftLen = dfs(root->left);
    int rightLen = dfs(root->right);

    res = std::max(res, leftLen + rightLen);

    return std::max(leftLen, rightLen) + 1;
}

// dp[i][j]代表s的前i个字符和t前j个字符是否能组成s3的前(i+j)个字符
// dp[i][j] = dp[i-1][j] && s[i] == s3[i+j]
// dp[i][j] = dp[i][j-1] && t[j] == s3[i+j]

//                                 dp[0][0] = 1
// base case i = 0, 代表s为空字符串, dp[0][j] = dp[0][j-1] && t[j] = s3[i+j-1]
//           j = 0, 代表t为空字符串, dp[i][0] = dp[i-1][0] && s[i] = s3[i+j-1]


bool isInterleave(std::string s1, std::string s2, std::string s3)
{
    if(s1.size() + s2.size() != s3.size()) return false;

    int m = s1.size(), n = s2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 && j == 0) dp[i][j] = 1;
            else if(i == 0) dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1];
            else if(j == 0) dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1];
            else dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
        }
    }

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            std::cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return dp[m][n];
}


int main() {
    std::string s1 = "a", s2 = "b", s3 = "ab";

    isInterleave(s1, s2, s3);

    return 0;
}


bool wordBreak(std::string s, std::vector<std::string> &wordDict)
{
    int n = s.size();
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        for(auto &word : wordDict) {
            int len = word.size();
            if(i >= len && s.substr(i-len,len) == word) dp[i] |= dp[i-len];
        }
    }

    return dp[n];
}


std::unordered_map<std::string, int> mp;

bool wordBreak(std::string s, std::vector<std::string> &wordDict)
{
    std::unordered_set<std::string> mySet(wordDict.begin(), wordDict.end());

    return dfs(s, wordDict, mySet);
}

bool dfs(std::string s, std::vector<std::string> &wordDict, std::unordered_set<std::string> &mySet)
{
    if(mp.count(s)) return mp[s];

    if(s.empty()) return true;

    for(auto &word : wordDict)
    {
        int len = word.size();
        if(s.size() >= len && mySet.count(s.substr(0, len)) && dfs(s.substr(len), wordDict, mySet)) {
            mp[s] = 1;
            return true;
        }
    }

    mp[s] = 0;

    return false;
}


// dp[i][j] 代表字符串s[0..i]和字符串t[0...j]之间匹配的次数

// dp[i][j] = dp[i-1][j-1], if s[i-1] == t[j-1]
// dp[i][j] = dp[i][j-1] + 1, 插入
// dp[i][j] = dp[i-1][j] + 1, 删除
// dp[i][j] = dp[i-1][j-1]+1, 替换 

int minDistance(std::string s, std::string t)
{
    int m = s.size(), n = t.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for(int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for(int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    for(int i = 1; i<= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
            else {
                dp[i][j] = std::min(std::min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            }
        }
    }

    return dp[m][n];
}

// dp[i][j] 表示s[0...i]与p[0...j]这部分是否匹配
// dp[i][j] = dp[i-1][j-1], if s[i]=p[j] || p[j]='.'

// if p[j] = '*'
// dp[i][j] = dp[i][j-2],  if s[i] != p[j-1] && p[j-1]!='.'
//                         else
//          = dp[i][j-1],  |忽略掉'*'
//          = dp[i-1][j],  |匹配成功
//          = dp[i][j-2],  |前面字符和'*'都忽略


bool isMatch(std::string s, std::string p)
{
    int m = s.size(), n = p.size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for(int j = 1; j <= n; j++) {
        if(p[j-1] == '*') dp[0][j] = dp[0][j-2];
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++)
        {
            if(s[i-1] == p[j-1] || p[j-1] == '.') {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] == '*') {
                if(s[i-1] != p[j-2] && p[j-2] != '.') {
                    dp[i][j] = dp[i][j-2];
                }
                else {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i][j-2];
                }
            }
        }
    }

    return dp[m][n];
}

// dp[i][j] = dp[i-1][j-1], if s[i] = p[j] || p[j] = '.'
//          = dp[i-1][j] || dp[i][j-1], else if p[j] = '*'
//            dp[i-1][j]表示'*'匹配多次
//            dp[i][j-1]表示忽略'*'

bool isMatch(std::string s, std::string p)
{
    int m = s.size(), n = p.size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for(int j = 1; j <= n; j++) {
        if(p[j-1] == '*') dp[0][j] = dp[0][j-1];
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == p[j-1] || p[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
    }

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            std::cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }


    return dp[m][n];
}

int main() {
    std::string s = "abceb", p = "*a*b";

    std::cout << isMatch(s, p) << std::endl;

    return 0;
}

bool canJump(std::vector<int> &nums)
{
    int maxPos = 0;

    for(int i = 0; i < nums.size() - 1; i++) {
        maxPos = std::max(maxPos, i + nums[i]);
        if(maxPos <= i) return false;
    }

    return true;
}


int Jump(std::vector<int> &nums)
{
    int maxPos = 0;
    int end = 0;
    int steps = 0;

    for(int i = 0; i < nums.size() - 1; i++) {
        maxPos = std::max(maxPos, i + nums[i]);
        if(end == i) {
            end = maxPos;
            steps++;
        }
    }

    return steps;
}

// std::unordered_map<int,int> hash;
std::unordered_set<int> visited;

bool canReach(std::vector<int> &arr, int start)
{
    return dfs(arr, start);
}

bool dfs(std::vector<int> &arr, int start)
{
    if(start < 0 || start >= arr.size()) return false;

    if(visited.count(start)) return false;

    if(arr[start] == 0) return true;

    visited.insert(start);

    return dfs(arr, start + arr[start]) || dfs(arr, start - arr[start]);
}


std::vector<int> searchReange(std::vector<int> &nums, int target)
{
    return {findLeftBound(nums, target), findRightBound(nums, target)};
}

int findLeftBound(std::vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);

        if(nums[mid] < target) {
            left = mid + 1;
        }
        else if(nums[mid] >= target) {
            right = mid - 1;
        }
    }

    if(left == nums.size() || nums[left] != target) return -1;
 
    return left;
}

int findRightBound(std::vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);

        if(nums[mid] <= target) {
            left = mid + 1;
        }
        else if(nums[mid] > target) {
            right = mid - 1;
        }
    }

    if(right == -1 || nums[right] != target) return -1;

    return right;
}


std::vector<int> res;

std::vector<int> rightSideView(TreeNode *root)
{
    dfs(root, 1);

    return res;
}

void dfs(TreeNode *root, int level)
{
    if(root == nullptr) return;

    if(res.size() < level) {
        res.push_back(root->val);
    }

    dfs(root->right, level + 1);
    dfs(root->left, level + 1);
}

TreeNode *invertTree(TreeNode *root)
{
    if(root == nullptr) return root;

    std::swap(root->left, root->right);

    invertTree(root->left);
    invertTree(root->right);

    return root;
}


TreeNode* invertTree(TreeNode *root)
{
    if(root == nullptr) return root;

    std::stack<TreeNode*> sta;
    sta.push(root);

    while(!sta.empty())
    {
        TreeNode *pNode = sta.top(); sta.pop();
        std::swap(pNode->left, pNode->right);

        if(pNode->right) {
            sta.push(pNode->right);
        }

        if(pNode->left) {
            sta.push(pNode->left);
        }
    }

    return root;
}

std::vector<int> rightView(TreeNode *root)
{
    std::vector<int> res;

    if(root == nullptr) return res;

    std::queue<TreeNode> que;
    que.push(root);

    while(!que.empty())
    {
        for(int size = que.size(); size > 0; size--)
        {
            auto pNode = que.front(); que.pop();
            
            if(size == 1) res.push_back(pNode->val);

            if(pNode->left) que.push(pNode->left);
            if(pNode->right) que.push(pNode->right);
        }
    }

    return res;
}

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int m_val) : val(m_val) , left(nullptr), right(nullptr) {}
};


TreeNode* buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
{
    // std::unordered_map<int,int> inorderPos;
    // for(int i = 0; i < inorde.size(); i++) {
    //     inorderPos[inorder[i]] = i;
    // }

    return dfs(preorder, 0, preorder.size() - 1, 0, inorderPos);
}

TreeNode *dfs(std::vector<int> &preorder, int startPreorder, int endPreorder, int startInorder)
{
    if(startPreorder > endPreorder) return nullptr;

    TreeNode *root = new TreeNode(preorder[startPreorder]);

    int rootIndex = 0;
    for(int i = 0; i < inorder.size(); i++) {
        if(inorder[i] == preorder[startPreorder]) {
            rootIndex = i;
            break;
        }
    }
    // int rootIndex = inorderPos[preorder[startPreorder]];
    int leftLen = rootIndex - startInorder;

    root->left = dfs(preorder, startPreorder + 1, startPreorder + leftLen, startInorder);
    root->right = dfs(preorder, startPreorder + leftLen + 1, endPreorder, rootIndex + 1);

    return root;
}

TreeNode* buildTree(std::vector<int> &inorder, std::vector<int> &postorder)
{
    std::unordered_map<int,int> inorderPos;
    for(int i = 0; i < inorder.size(); i++) {
        inorderPos[inorder[i]] = i;
    }

    return dfs(postorder, 0, postorder.size() - 1, 0, inorderPos);
}

TreeNode *dfs(std::vector<int> &postorder, int startPostorder, int endPostorder, int startInorder, std::unordered_map<int,int> &inorderPos)
{
    if(startPostorder > endPostorder) return nullptr;

    TreeNode *root = new TreeNode(postorder[endPostorder]);

    int rootIndex = inorderPos[postorder[endPostorder]];
    int leftLen = rootIndex - startInorder;

    root->left = dfs(postorder, startPostorder, startPostorder + leftLen - 1, startInorder, inorderPos);
    root->right = dfs(postorder, postorder + leftLen, endPostorder - 1, rootIndex + 1, inorderPos);

    return root;
}


bool increasingTriplet(std::vector<int> &nums)
{
    int x = INT_MAX, y = INT_MAX;

    for(const int &n : nums)
    {
        if(n <= x) {
            x = n;
        }
        else if(n <= y) {
            y = n;
        }
        else return true;
    }

    return false;
}

int thridMax(std::vector<int> &nums)
{
    std::set<int> mySet;

    for(const int &n : nums) {
        mySet.insert(n);
        if(mySet.size() > 3) mySet.erase(mySet.begin());
    }

    return mySet.size() == 3 ? *mySet.begin() : *mySet.rbegin();
}

// x < y < z,  初始化成 INT_MIN
// n > z, x = y, y = z, z = n;
// y < n < z, x = y, y = n
// x < n < y, x = n

int thridMax(std::vector<int> &nums)
{
    long x, y, z;
    x = y = z = LONG_MIN;

    for(const int &n : nums)
    {
        if(n > z) {
            x = y;
            y = z;
            z = n;
        }
        else if(y < n && n < z) {
            x = y;
            y = n;
        }
        else if(x < n && n < y) {
            x = n;
        }
    }

    return x == LONG_MIN ? z : x;
}

int findMaxConsectiveOnes(std::vector<int> &nums)
{
    int res = 0;

    for(int left = 0; left < nums.size(); left++)
    {
        if(nums[left] == 1) {
            int right = left;
            while(right < nums.size() && nums[right] == 1) {
                right++;
            }
            res = std::max(res, right - left);
            left = right;
        }
    }

    return res;
}

int findMaxConsectiveOnes(std::vector<int> &nums)
{
    int res = 0, count = 0;

    for(const int &n : nums) {
        if(n == 1) {
            count++;
            res = std::max(res, count);
        }
        else count = 0;
    }

    return res;
}

int longestOnes(std::vector<int> &nums, int k)
{
    int left = 0, count = 0;
    int res = 0;

    for(int right = 0; right < nums.size(); right++)
    {
        if(nums[right] == 0) count++;

        while(count > k) {
            if(nums[left] == 0) count--;
            left++;
        }

        res = std::max(res, right - left + 1);
    }

    return res;
}


class maxHeap
{
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

    int top() 
    {
        return heap[1];
    }

};

int main() {
    maxHeap heap;
    heap.push(1);
    heap.push(2);
    heap.push(10);
    // heap.push(0);

    std::cout << heap.top() << std::endl;   heap.pop();
    std::cout << heap.top() << std::endl;   heap.pop();
    std::cout << heap.top() << std::endl;   heap.pop();



    return 0;
}


double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
{
    if(num1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int m = nums1.size(), n = nums2.size();

    int left = 0, right = m;

    while(left <= right)
    {
        int i = left  + ((right - left ) >> 1);
        int j = (m+n+1)/2 - i;

        int maxLeftX = (i == 0 ? INT_MIN : nums1[i-1]);
        int minRightX = (i == m ? INT_MAX : nums1[i]);

        int maxLeftY = (j == 0 ? INT_MIN : nums2[j-1]);
        int minRightY = (j == n ? INT_MAX : nums2[j]);

        if(maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if((m+n)&1) return std::max(maxLeftX, maxLeftY);
            else return (std::max(maxLeftX, maxLeftY) + std::min(minRightX, minRightY)) / 2.0;
        }
        else if(maxLeftX > minRightY) {
            i = right - 1;
        }
        else {
            j = left + 1;
        }
    }

    return -1;
}


bool isMatch(std::string s, std::string p)
{
    int m = s.size(), n = p.size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for(int j = 2; j <= n; j++) {
        if(p[j-1] == '*') dp[0][j] = dp[0][j-2];
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s[i-1] == p[j-1] || p[j-1] == '.') {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] == '*') {
                if(s[i-1] != p[j-2] && p[j-2] != '.') {
                    dp[i][j] = dp[i][j-2];
                }
                else {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i][j-2];
                }
            }
        }
    }

    return dp[m][n];
}

std::string validIpAddress(std::string IP)
{
    return isIPV4(IP) ? "IPv4" : (isIPV6(IP) ? "IPv6" : "Neither");
}


bool isIPV4(std::string str)
{
    if(count(str.begin(), str.end(), '.') != 3) return false;

    std::stringstream in(str);
    std::string out;

    std::vector<std::string> strs;

    while(getline(in, out, '.')) {
        if(out.empty()) continue;
        if(out.size() > 3) return false;
        strs.push_back(out);
    }

    if(strs.size() != 4) return false;

    for(int i = 0; i < strs.size(); i++)
    {
        auto s = strs[i];

        int tmp = 0;
        for(const char &c : s) {
            if(!isdigit(c)) return false;
            if(s.size() != 1 && s[0] == '0') return false;
            tmp = tmp*10 + (c - '0');
            if(tmp > 255) return false;
        }
    }

    return true;
}


bool isIPV6(std::string str)
{
    if(count(str.begin(), str.end(), ':') != 7) return false;

    std::stringstream in(str);
    std::string out;

    std::vector<std::string> strs;

    while(getline(in, out, ':')) {
        if(out.empty()) continue;
        if(out.size() > 4) return false;
        strs.push_back(out);
    }

    if(strs.size() != 8) return false;

    for(int i = 0; i < strs.size(); i++)
    {
        auto s = strs[i];

        for(const char &c : s) {
            if(!(isdigit(c) || (toupper(c) >= 'A' && toupper(c) <= 'F'))) return false;
        }
    }

    return true;
}

std::string validIpAddress(std::string IP)
{
    regex ipv4("((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9][0-9])\\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9][0-9])");
    regex ipv6("((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]){1,4})");

    if(regex_match(IP, ipv4)) {
        return "IPv4";
    }
    else if(regex_match(IP, ipv6)) {
        return "IPv6";
    }

    return "Neither";
}


std::string reverseWords(std::string str);

int main() {
    // std::cout << regex_match("123", regex("\\d")) << std::endl;
    std::string str = "he llo world";

    std::cout << reverseWords(str) << std::endl;

    return 0;
}

std::string reverseWords(std::string str)
{
    int left = 0;

    for(int right = 0; right < str.size(); right++)
    {
        if(str[right] == ' ') {
            reverse(str.begin() + left, str.begin() + right);
            left = right + 1;
        }
    }

    reverse(str.begin() + left, str.end());

    reverse(str.begin(), str.end());

    return str;
}



class A {};

class B : virtual public A {};

class C : virtual public A{};

class D : public C, public B {};

void memalloc(char **p, int size)
{
    *p = (char*)malloc(size);
}


int main() {
    // std::cout << sizeof(D) << std::endl;
    // int data[1+2];

    char *str = NULL;
    memalloc(&str, 1024);

    strcpy(str, "hello world");
    printf(str);

    return 0;
}



int getMaximumGold(std::vector<std::vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    int maxVal = 0;

    std::vector<std::vector<int>> visited(m, std::vector<int>(n, 0));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            maxVal = std::max(maxVal, dfs(grid, i, j, visited));
        }
    }
    
    return maxVal;
}

int dfs(std::vector<std::vector<int>> &grid, int i, int j, std::vector<std::vector<int>> &visited)
{
    int m = grid.size(), n = grid[0].size();

    int value = grid[i][j];
    visited[i][j] = 1;

    for(int k = 0; k < dir.size() - 1; k++) {
        int x = i + dir[k], y = j + dir[k+1];
        if(x >= 0 && x < m  && y >= 0 && y < n && grid[x][y] && !visited[x][y]) {
            value = std::max(value, grid[i][j] + dfs(grid, x, y, visited));
        }
    }

    visited[i][j] = 0;  //一定要记得回溯
    
    return value;
}

bool canPartitionKSubsets(std::vector<int> &nums, int k)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if(sum % k != 0) return false;

    int target = sum/k;

    sort(nums.rbegin(), nums.rend());

    for(const int &n : nums) {
        if(n > target) return false;
    }

    std::vector<int> subSum(k, 0);

    return dfs(nums, subSum, target, 0, k);
}

bool dfs(std::vector<int> &nums, std::vector<int> &subSum, int target, int pos, int k)
{
    if(pos == nums.size())
    {
        int val = subSum[0];
        for(int i = 1; i < subSum.size(); i++) {
            if(val != subSum[i]) return false;
        }
        return true;
    }

    for(int i = 0; i < k; i++) 
    {
        if(subSum[i] + nums[pos] > target) continue;
        subSum[i] += nums[pos];
        if(dfs(nums, subSum, target, pos + 1, k)) return true;
        subSum -= nums[pos];
    }

    return false;
}


bool canPartition(std::vector<int> &nums)
{
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if(sum&1) return false;

    int target = sum/2;

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(target + 1));
    for(int i = 0; i <= n; i++) dp[i][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= target; j++) {
            if(j >= nums[i-1])
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            else 
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][target];
}

bool canPartition(std::vector<int> &nums)
{
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if(sum&1) return false;

    int target = sum/2;

    std::vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = target; j >= nums[i-1]; j--) {
            dp[j] = dp[j] || dp[j-target];
        }
    }
    
    return dp[target];
}


int main() {
    std::vector<int> nums = {1,5,10,6};

    canPartition(nums);


    return 0;
}

bool makeSquare(std::vector<int> &nums)
{
    int maxVal = 0, sum = 0;
    for(const int &n : nums) {
        maxVal = std::max(maxVal, n);
        sum += n;
    }

    int target = sum/4;

    if(sum%4 || maxVal > target) return false;

    sort(nums.rbegin(), nums.rend());       //把大数放在前面优先过滤掉不可能的组合

    std::vector<int> subSum(4, 0);

    return dfs(nums, subSum, 0, target);
}

bool dfs(std::vector<int> &nums, std::vector<int> &subSum, int pos, int target)
{
    if(pos == nums.size())
    {
        for(const int &n : subSum) {
            if(n != target) return false;
        }
        return true;
    }

    for(int i = 0; i < 4; i++) 
    {
        if(subSum[i] + nums[pos] > target) continue;
        subSum[i] += nums[pos];
        if(dfs(nums, subSum, pos + 1, target)) return true;
        subSum[i] -= nums[pos];
    }

    return false;
}

// dp[i] = min(dp[i], dp[i-j*j] + 1);

int numSquare(int n)
{
    std::vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 0; i <= n; i++) {
        for(int j = 1; j*j <= i; j++) {
            dp[i] = std::min(dp[i], dp[i-j*j] + 1);
        }
    }

    return dp[n];
}


int maxSubarrySumNoMoreThanK(std::vector<int> &nums, int k)
{
    int n = nums.size();

    int res = INT_MIN;
    int left = 0;
    int sum = 0;

    for(int right = 0; right < n; right++)
    {
        sum += nums[right];

        while(sum > k) {
            sum -= nums[left++];
        }

        // res = std::max(res, sum);
        if(sum <= k) res = std::max(res, sum);
    }

    return res;
}

int main() {
    std::vector<int> nums = {4};
    int k = 0;

    std::cout << maxSubarrySumNoMoreThanK(nums, k) << std::endl;

    return 0;
}


int maxSubarrySumNoMoreThanK(std::vector<int> &nums, int k)
{
    std::set<int> mySet;
    mySet.insert(0);

    int res = INT_MIN, sum = 0;
    
    for(const int &n : nums) {
        sum += n;
        auto it = mySet.lower_bound(sum - k);
        if(it != mySet.end()) res = std::max(res, sum - *it);
        mySet.insert(sum);
    }

    return res;
}

int maxSumSubmatrix(std::vector<std::vector<int>> &matrix, int k)
{
    int m = matrix.size(), n = matrix[0].size();

    int res = INT_MIN;

    for(int left = 0; left < n; left++) {
        for(int right = left; right < n; right++)
        {
            std::vector<int> sum(m, 0);
            for(int i = 0; i < m; i++) {
                sum[i] += matrix[i][right];
            }

            res = std::max(res, maxSubarrySumNoMoreThanK(sum, k));
        }
    }

    return res;
}

int subarraySum(std::vector<int> &nums, int k)
{
    std::unordered_map<int,int> mp;
    mp[0] = 1;

    int sum = 0, count = 0;

    for(const int &n : nums) {
        sum += n;
        count += mp[sum-k];
        mp[sum]++;
    }

    return count;
}

int shortestSubarray(std::vector<int> &nums, int k)
{
    int res = INT_MAX;

    int sum = 0, left = 0;
    
    for(int right = 0; right < nums.size(); right++)
    {
        sum += nums[right];

        while(sum >= k && left < nums.size()) {
            res = min(res, right - left + 1);
            sum -= nums[left++];
        }
    }

    return res;
}


//将数组的和及其下标全部放入优先队列
//时间复杂度O(nlogn)
//空间复杂度O(n)

int shortestSubarray(std::vector<int> &nums, int k)
{
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;

    pq.push({0, -1});

    int res = INT_MAX, sum = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        while(!pq.empty() && sum - pq.top().first >= k) {
            res = std::min(res, i - pq.top().second);
            pq.pop();
        }

        pq.push({sum, i});
    }

    return res == INT_MAX ? -1 : res;
}


// dp[i][j] 表示正方形右下角坐标为(i,j)的包含1的方形图形边长

// dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;    if nums[i][j] = 1;
// dp[i][j] = 0;


int maximalSquare(std::vector<std::vector<char>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

    int res = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || j == 0 || matrix[i][j] == '0') dp[i][j] = matrix[i][j] - '0';
            else {
                dp[i][j] = std::min(dp[i-1][j-1], std::min(dp[i-1][j], dp[i][j-1])) + 1;
            }
            res = std::max(res, dp[i][j]);
        }
    }

    return res*res;
}


class UF
{
private:
    std::vector<int> size, parent;
    int count;

public:
    UF(int n) 
    {
        size.resize(n, 1);
        
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        
        count = n;
    }

    void unionNode(int p, int q)
    {
        int rootP = findNode(p);
        int rootQ = findNode(q);

        if(rootP == rootQ) return;

        if(size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }

        count--;
    }

    int findNode(int x)
    {
        while(parent[parent[x]] != x) {
            x = parent[parent[x]];
        }

        return x;
    }

    int countNum() {
        return count;
    }
};


int findCircleNum(std::vector<std::vector<int>> &isConnected)
{
    int m = isConnected.size(), n = isConnected[0].size();
   
    UF uf;

    for(int i = 0; i < m; i++) {
        for(int j = i; j < n; j++) {
            if(isConnected[i][j]) uf.unionNode(i, j);
        }
    }

    return uf.countNum();
}


std::vector<int> findOrder(int n, std::vector<std::vector<int>> &pre)
{
    std::vector<std::vector<int>> graph(n);
    std::vector<int> degree(n);

    for(auto &num : pre) {
        graph[num[1]].push_back(num[0]);
        degree[num[0]]++;
    }

    std::queue<int> que;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) que.push_back(i);
    }

    std::vector<int> res;

    while(!que.empty())
    {
        auto cur = que.front(); que.pop();
        res.push_back(cur);

        for(const int &n : graph[cur]) {
            if(--degree[n] == 0) {
                que.push_back(n);
            }
        }
    }

    return res.size() == n ? res : {};
}


std::vector<int> findOrder(int n, std::vector<std::vector<int>> &pre)
{
    std::vector<std::vector<int>> graph(n);

    for(auto &num : pre) {
        graph[num[1]].push_back(num[0]);
    }

    std::vector<int> visited(n);

}

bool hasCycle(std::vector<std::vector<int>> &graph, std::vector<int> &done, std::vector<int> &todo, int node)
{
    if(visited[node]) return true;

    visited[node] = 1;

    for(int &v : graph[node]) {
        if(hasCycle(graph, visited, v)) return true;
    }

    visited[node] = 0;

    return false;
}

std::vector<int> findMinHieghtTrees(int n, std::vector<std::vector<int>> &edges)
{
    std::vector<std::vector<int>> graph(n);
    std::vector<int> degree(n);

    for(auto &edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
        degree[edge[0]]++;
        degree[edge[1]]++;
    }

    std::queue<int> que;
    for(int i = 0; i < n; i++) {
        if(degree[i] == 1) que.push(i);
    }

    std::vector<int> res;

    while(!que.empty())
    {
        res.clear();
        for(int size = que.size(); size > 0; size--)
        {
            auto cur = que.front(); que.pop();
            res.push_back(cur);
            for(const int &n : graph[cur]) {
                if(--degree[n] == 1) que.push(n);
            }
        }
    }

    return res;
}

int openLock(std::vector<std::string> &deadends, std::string target)
{
    std::unordered_set<std::string> deadSet(deadends.begin(), deadends.end());

    if(deadSet.count(target)) return -1;

    std::string start = "0000";

    std::queue<std::string> que;
    std::unordered_set<std::string> visited;
    visited.insert(start);

    int steps = 0;

    while(!que.empty())
    {
        for(int size = que.size(); size > 0; size--)
        {
            auto cur = que.front(); que.pop();
            if(cur == target) return steps;

            std::vector<std::string> strs = next(cur);

            for(auto &str : strs) {
                if(deadSet.count(str)) continue;
                if(visited.count(str)) continue;

                que.push(str);
                visited.insert(str);
            }
        }

        steps++;
    }

    return -1;
}

std::vector<std::string> next(const std::string &str)
{
    std::vector<std::string> res;

    for(int i = 0; i < str.size(); i++)
    {
        std::string tmp = str;

        tmp[i] = (str[i]-'0'+1)%10 + '0';
        res.push_back(tmp);

        tmp[i] = (str[i]-'0'-1+10)%10 + '0';
        res.push_back(tmp);
    }

    return res;
}

int openLock(std::vector<std::string> &deadends, std::string target)
{
    std::unordered_set<std::string> deadSet(deadends.begin(), deadends.end());

    std::string start = "0000";
    if(deadSet.count(start) || deadSet.count(target)) return -1;
    if(start == target) return 0;

    std::unordered_set<std::string> begin, end, visited;

    begin.insert(start);
    end.insert(target);
    visited.insert(start);

    int steps = 0;

    while(!begin.empty() && !end.empty())
    {
        if(begin.size() > end.size()) {
            std::swap(begin, end);
        }

        std::unordered_set<std::string> tmp;

        for(auto &s : begin) {
            for(auto &str : next(s)) {
                if(deadSet.count(str)) continue;
                if(visited.count(str)) continue;

                if(end.count(str)) return ++steps;

                tmp.insert(str);
                visited.insert(str);
            }
        }

        begin = tmp;
        steps++;
    }

    return -1;
}

std::vector<int> dir = {-1,0,1,0,-1};

int getMaximumGold(std::vector<std::vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    std::vector<std::vector<int>> visited(m, std::vector<int>(n, 0));

    int res = INT_MAX;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            res = std::max(res, dfs(grid, i, j, visited));
        }
    }

    return res;
}

int dfs(std::vector<std::vector<int>> &grid, int i, int j, std::vector<std::vector<int>> visited)
{
    int m = grid.size(), n = grid[0].size();

    visited[i][j] = 1;

    int ans = grid[i][j];

    for(int k = 0; k < dir.size()-1; k++) {
        int x = i + dir[k], y = j + dir[k+1];
        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] && !visited[x][y]) {
            ans = std::max(ans, grid[i][j] + dfs(grid, x, y, visited));
        }
    }   

    visited[i][j] = 0;

    return ans;
}


std::string intToRoman(int num)
{
    std::vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
    std::vector<std::string> strs = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    std::string res;
    for(int i = 0; i < values.size(); i++) {
        while(num >= values[i]) {
            num -= values[i];
            res += strs[i];
        }
    }

    return res;
}

int myAtoi(std::string s)
{
    if(s.empty()) return 0;

    int res = 0;

    bool minus = false;

    int i = 0;
    while(isspace(s[i])) i++;

    if(s[i] == '-') {
        minus = true;
        i++;
    }
    else if(s[i] == '+') {
        i++;
    }

    int flag = minus ? -1 : 1;

    for(; i < s.size(); i++)
    {
        if(!isdigit(s[i])) break;
        
        if(res > INT_MAX/10 || (res == INT_MAX/10 && (s[i]-'0') > 7)) {
            return INT_MAX;
        }
        else if(res < INT_MIN/10 || (res == INT_MIN/10 && (s[i]-'0') > 8)) {
            return INT_MIN;
        }

        res = res*10 + flag*(s[i]-'0');
    }

    return res;
}

int largestRectangleArea(std::vector<int> &heights)
{
    std::stack<int> sta;
    heights.push_back(0);

    int res = 0;

    for(int i = 0; i < heights.size(); i++)
    {
        while(!sta.empty() && heights[i] < heights[sta.top()]) {
            int curHei = heights[sta.top()];
            sta.pop();
            int left = sta.empty() ? -1 : sta.top();
            res = std::max(res, curHei*(i - left - 1));
        }

        sta.push(i);
    }

    return res;
}

int maximalRectangle(std::vector<std::vector<char>> &matrix)
{
    if(matrix.empty()) return 0;

    int m = matrix.size(), n = matrix[0].size();
    if(m == 0 || n == 0) return 0;

    std::vector<int> height(n);

    int re = 0;

    for(auto &row : matrix) {
        for(int i = 0; i < n; i++) {
            height[i] = (row[i] == '1') ? height[i] + 1 : 0;
        }
        res = largestRectangleArea(height);
    }

    return res;
}

std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2)
{
    std::unordered_map<int,int> mp;
    std::stack<int> sta;

    for(const int &n : nums2) {
        while(!sta.empty() && n > sta.top()) {
            mp[sta.top()] = n;
            sta.pop();
        }

        sta.push(n);
    }

    std::vector<int> res;
    for(const int &n : nums1) {
        if(mp.count(n)) res.push_back(mp[n]);
        else res.push_back(-1);
    }

    return res;
}

std::vector<int> nextGreaterElement(std::vector<int> &nums)
{
    int n = nums.size();
    std::stack<int> sta;

    std::vector<int> res(n, -1);

    for(int i = 0; i < 2*n; i++) 
    {
        while(!sta.empty() && nums[i%n] > nums[sta.top()]) {
            res[sta.top()] = nums[i%n];
            sta.pop();
        }

        sta.push(i%n);
    }

    return res;
}

void nextPermutation(std::vector<int> &nums)
{
    int n = nums.size();

    int i = n-2;
    for(; i >= 0; i--) {
        if(nums[i] < nums[i+1]) break;
    }

    if(i < 0) {
        reverse(nums.begin(), nums.end());
        return nums;
    }

    int j = n-1;
    for(; j >= 0; j--) {
        if(nums[j] > nums[i]) break;
    }

    std::swap(nums[i], nums[j]);

    reverse(nums.begin() + i + 1, nums.end());

    return nums;
}

int nextGreaterElement(int n)
{
    std::string str = std::to_string(n);

    int i = str.size() - 2;
    for(; i >= 0; i--) {
        if(str[i] < str[i+1]) break;
    }

    if(i < 0) return -1;

    int j = str.size() - 1;
    for(; j >= 0; j--) {
        if(nums[j] > nums[i]) break;
    }

    std::swap(str[i], str[j]);

    reverse(str.begin() + i + 1, str.end());

    if(std::stol(str) > INT_MAX) return -1;
    
    return std::stol(str);
}



void dfs(std::string &digits, std::vector<std::string> &strs, int pos, std::string &path);

std::vector<std::string> res;

std::vector<std::string> letterCombination(std::string digits)
{
    if(digits.empty()) return res;

    std::vector<std::string> strs = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    std::string path;
    dfs(digits, strs, 0, path);

    return res;
}

void dfs(std::string &digits, std::vector<std::string> &strs, int pos, std::string &path)
{
    if(pos == digits.size()) {
        res.push_back(path);
        return;
    }

    for(const char &c : strs[digits[pos] - '0']) {
        path.push_back(c);
        dfs(digits, strs, pos + 1, path);
        path.pop_back();
    }    

}

int main() {
    letterCombination("23");

    for(auto &str : res) {
        std::cout << str << std::endl;
    }

    return 0;
}

ListNode* sortList(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *fast = head, *slow = head;
    while(fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode *mid = slow->next;
    slow->next = nullptr;

    return mergeList(sort(head), sort(mid));
}

ListNode *mergeList(ListNode *l1, ListNode *l2)
{
    if(l1 == nullptr) return l2;
    else if(l2 == nullptr) return l1;

    if(l1->val < l2->val) {
        l1->next = mergeList(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeList(l1, l2->next);
        return l2;
    }

    return nullptr;
}


void dfs(std::vector<std::vector<int>> &graph, std::vector<int> &degree, int num, std::vector<int> &path, std::vector<int> &visited);

std::vector<std::vector<int>> res;

std::vector<std::vector<int>> topologySort(int num, std::vector<std::vector<int>> &prere)
{
    std::vector<std::vector<int>> graph(num + 1);
    std::vector<int> degree(num + 1);

    //建立临接表
    for(auto &e : prere) {
        graph[e[0]].push_back(e[1]);
        degree[e[1]]++;
    }

    std::vector<int> visited(num + 1, 0);
    std::vector<int> path;

    dfs(graph, degree, num, path, visited);

    return res;
}

void dfs(std::vector<std::vector<int>> &graph, std::vector<int> &degree, int num, std::vector<int> &path, std::vector<int> &visited)
{
    if(path.size() == num) {
        res.push_back(path);
        return;
    }

    for(int i = 1; i <= num; i++)
    {
        if(degree[i] == 0 && !visited[i]) 
        {
            path.push_back(i);
            visited[i] = 1;
            for(const int &n : graph[i]) {
                --degree[n];
            }

            dfs(graph, degree, num, path, visited);

            path.pop_back();
            visited[i] = 0;
            for(const int &n : graph[i]) {
                ++degree[n];
            }
        }
    }

}


int main() {
    int num = 6;
    std::vector<std::vector<int>> prepre = {{1,2}, {1,3}, {2,4}, {2,5}, {3,4}, {3,5}, {4,6}, {5,6}};

    topologySort(num, prepre);

    for(auto &nums : res) {
        for(const int &n : nums) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

std::vector<std::string> res;

std::vector<std::string> generateParenthesis(int n)
{
    dfs(n, n, path);

    return res;
}

void dfs(int left, int right, std::string &path)
{
    if(left < 0 || right < 0) return;

    if(left > right) return;

    if(left == 0 && right == 0) {
        res.push_back(path);
        return;
    }

    path.push_back('(');
    dfs(left - 1, right, path);
    path.pop_back();

    path.push_back(')');
    dfs(left, right - 1, path);
    path.pop_back();

}

// 只需要关注'('的数量, (min, max)为'('的数量范围
// 1.c='(', min++, max++;
// 2.c=')', min--, max--;  if max < 0, false
// 3.c='*', 如果'*'匹配'(', 则max++, 如果匹配')', min--
// 4.判断最终 min==0

bool checkValidString(std::string s)
{
    int leftMax, leftMin;
    leftMin = leftMax = 0;

    for(const char &c : s)
    {
        if(c == '(') {
            leftMin++;
            leftMax++;
        }
        else if(c == ')') {
            leftMin--;
            leftMax--;
            if(leftMin < 0) leftMin = 0;
            if(leftMax < 0) return false;
        }
        else if(c == '*') {
            leftMin--;
            leftMax++;
            if(leftMin < 0) leftMin = 0;
        }
    }

    return leftMin == 0;
}

bool validPalindrome(std::string s)
{
    int left = 0, right = s.size() - 1;

    while(left < right)
    {
        if(s[left] == s[right]) {
            left++;
            right--;
        }
        else {
            int i1 = left, j1 = right - 1;
            int i2 = left + 1, j2 = right;
            while(i1 < j1 && s[i1] == s[j1]) i1++, j1--;
            while(i2 < j2 && s[i2] == s[j2]) i2++, j2--;

            return i1 >= j1 || i2 >= j2;
        }
    }

    return true;
}


ListNode *oddEvenList(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *pOdd = head, *pEven = head->next;

    ListNode *Head = pEven;

    while(pEven && pEven->next) {
        pOdd = pOdd->next = pEven->next;
        pEven = pEven->next = pOdd->next;
    }

    // pEven->next = nullptr;
    pOdd->next = Head;

    return head;
}


ListNode* rotateRight(ListNode *head, int k)
{
    if(head == nullptr || head->next == nullptr || k == 0) return head;

    ListNode *pNode = head;
    int len = 1;
    while(pNode->next) {
        pNode = pNode->next;
        len++;
    }

    pNode->next = head;

    k %= len;

    for(int i = 0; i < (len-k); i++) {
        pNode = pNode->next;
    }

    ListNode *res = pNode->next;

    pNode->next = nullptr;

    return res;
}


bool isPalindrome(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return true;

    ListNode *slow = head, *fast = head;

    while(fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode *mid = slow->next;
    ListNode *pNode = reverse(mid);

    while(head && pNode) {
        if(head->val != pNode->val) return false;
        head = head->next;
        pNode = pNode->next;
    }

    return true;
}

ListNode *reverse(ListNode *head)
{
    ListNode *prev = nullptr;

    while(head) {
        ListNode *pNode = head->next;
        head->next = prev;
        prev = head;
        head = pNode;
    }

    return prev;
}

ListNode *isPalindrome(ListNode *head)
{
    ListNode *prev = nullptr, *fast = head, *slow = head;

    while(fast && fast->next) {
        fast = fast->next->next;

        ListNode *pNode = slow->next;
        slow->next = prev;
        prev = slow;
        slow = pNode;
    }

    if(fast) slow = slow->next;

    while(prev && slow) {
        if(prev->val != slow->val) return fasle;
        prev = prev->next;
        slow = slow->next;
    }

    return true;
}

ListNode* reverseKGroup(ListNode *head, int k)
{
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *base = new ListNode(-1);
    base->next = head;

    ListNode *pNode = base;

    while(pNode)
    {
        ListNode *prev = pNode;
        int i = 0;
        for(; i < k; i++) {
            pNode = pNode->next;
            if(pNode == nullptr) break;
        }

        if(i == k)
        {
            ListNode *tail = pNode->next;

            ListNode *reverseList = reverse(prev->next, tail);
            pNode = prev->next;
            prev->next = reverseList;
            pNode->next = tail;
        }
    }

    return base->next;
}

std::unordered_set<int> visited;

bool canReach(std::vector<int> &arr, int start)
{
    if(start >= 0 && start < arr.size() && visited.insert(start).second) {
        return arr[start] == 0 || canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
    }

    return false;
}



int minJumps(std::vector<int> &arr)
{
    int n = arr.size();

    std::unordered_map<int,std::vector<int>> indicesOfVal;

    for(int i = 0; i < arr.size(); i++) {
        indicesOfVal[arr[i]].push_back(i);
    }

    std::vector<int> visited(n, 0);
    std::queue<int> que;
    que.push(0);
    visited[0] = 1;

    int steps = 0;

    while(!que.empty())
    {
        for(int size = que.size(); size > 0; size--)
        {
            auto cur = que.front(); que.pop();

            if(cur == n - 1) return steps;

            auto &next = indicesOfVal[arr[cur]];

            next.push_back(cur + 1);   next.push_back(cur - 1);

            for(const int &n : next) {
                if(n >= 0 && n < arr.size() && !visited[n]) {
                    que.push(n);
                    visited[n] = 1;
                }
            }

            next.clear();
        }

        steps++;
    }

    return steps;
}


int dp[1001];

int maxJumps(std::vector<int> &arr, int k)
{
    memset(dp, 0, sizeof(dp));

    int res = 1;
    for(int i = 0; i < arr.size(); i++) {
        res = std::max(res, dfs(arr, i, d));
    }

    return res;
}

int dfs(std::vector<int> &arr, int i, int d)
{
    if(dp[i]) return dp[i];

    int res = 1;

    //向右边
    for(int j = i + 1; j <= std::min(i + d, (int)arr.size()-1) && arr[j] < arr[i]; j++) {
        res = std::max(res, 1 + dfs(arr, j, d);
    }

    //向左边
    for(int j = i-1; j >= std::max(i - d, 0) && arr[j] < arr[i]; j--) {
        res = std::max(res, 1 + dfs(arr, j, d));
    }

    dp[i] = res;

    return res;
}

//动态规划思路:
// dp[i]代表第i个位置所得的分数
// dp[i] = max(dp[i-1], dp[i-2],..., dp[i-k]) + nums[i]

int maxResult(std::vector<int> &nums, int k)
{
    int n = nums.size();
    std::vector<int> dp(n, INT_MIN);
    dp[0] = nums[0];

    for(int i = 1; i < n; i++) {
        for(int j = std::min(0, i-k); j < i; j++) {
            dp[i] = std::max(dp[i], dp[j] + nums[i]);
        }
    }

    return dp[n-1];
}


int maxResult(std::vector<int> &nums, int k)
{
    int n = nums.size();
    std::vector<int> dp(n, INT_MIN);
    dp[0] = nums[0];

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= k && i + j < nums.size(); j++) {
            dp[i+j] = std::max(dp[i+j], dp[i] + nums[i+j]);
            if(nums[i+j] > 0) break;
        }
    }

    return dp.back();
}

int maxResult(std::vector<int> &nums, int k)
{
    std::deque<int> dq;
    dq.push_back(0);

    for(int i = 1; i < nums.size(); i++)
    {
        if(dq.front() + k < i) {
            dq.pop_front();
        }

        nums[i] += nums[dq.front()];

        while(!dq.empty() && nums[i] > nums[dq.back()]) {
            dp.pop_back();
        }

        dq.push_back(i);
    }

    return nums[dp.back()];
}


int lastRemaining(unsigned int n, unsigned int m)
{
    std::list<int> nums;

    for(int i = 0; i < n; i++) {
        nums.push_back(i);
    }

    std::list<int>::iterator cur = nums.begin();

    while(nums.size() > 1)
    {
        for(int i = 0; i < m-1; i++) {
            cur++;
            if(cur == nums.end()) cur = nums.begin();
        }

        std::list<int>::iterator next = ++cur;
        if(next == nums.end()) next = nums.begin();
        --cur;

        nums.erase(cur);
        cur = next;
    }

    return *cur;
}


struct ListNode {
    int data;
    ListNode *next;
    ListNode(int m_val) : data(m_val), next(nullptr) {}
};

int lastRemaining(unsigned int n, unsigned int m)
{
    ListNode *head = new ListNode(0);

    ListNode *cur = head;

    for(int i = 1; i < n; i++) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }

    cur->next = head;       //首尾相连构成循环链表

    int len = n;
    cur = head;

    while(len != 1)
    {
        for(int i = 0; i < m-2; i++) {  //这里只需要移动m-2步就可以了
            cur = cur->next;    
        }

        ListNode *tmp = cur->next;

        cur->next = cur->next->next;

        delete tmp;     //注意这个需要放在这里,否则上面的cur->next报段溢出

        len--;
    }

    return cur->data;
}



int main() {
    std::cout << lastRemaining(5, 3) << std::endl;

    return 0;
}



double epison = pow(10.0, -5);

std::vector<char> operator = {'+', '-', '*', '/'};

bool judgePoint24(std::vector<int> &nums)
{
    std::vector<double> numbers;

    for(const int &n : nums) {
        numbers.push_back(n*1.0);
    }

    return find24(numbers);
}

bool find24(std::vector<double> &nums)
{
    if(nums.size() == 1) {
        return fabs(nums[0] - 24) < epison;
    }
    
    for(int i = 0; i < nums.size(); i++) {
        for(int j = 0; j < nums.size(); j++)
        {
            if(i == j) continue;

            std::vector<double> res;
            for(int k = 0; k < nums.size(); k++) {
                if(k != i && k != j) res.push_back(nums[i]);
            }

            for(char &op : operator) 
            {
                if((op == '+' || op == '*') && i > j) continue;
                if(op == '/' && nums[j] < epison) continue;

                switch(op) {
                    case '+' : res.push_back(nums[i] + nums[j]); break;
                    case '-' : res.push_back(nums[i] - nums[j]); break;
                    case '*' : res.push_back(nums[i] * nums[j]); break;
                    case '/' : res.push_back(nums[i] / nums[j]); break;
                }

                if(find24(res)) return true;
                res.pop_back();     //回溯
            }
        }
    }

    return false;
}

int lengthOfLongestSubString(std::string s)
{
    std::vector<int> count(128, -1);
    int start = -1;
    int res = 1;

    for(int i = 0; i < s.size(); i++) {
        if(count[s[i]] > -1) {
            start = count[s[i]];
        }
        res = std::max(res, i - start);
        count[s[i]] = i;
    }

    return res;
}

bool isIsomorphic(std::string s, std::string t)
{
    if(s.size() != t.size()) return false;

    std::vector<int> mp1(256), mp2(256);

    for(int i = 0; i < s.size(); i++) {
        if(mp[s[i]] != mp[t[i]]) return false;
        mp[s[i]] = mp[t[i]] = i;
    }

    return true;
}


int minSubArrayLen(int target, std::vector<int> &nums)
{
    int sum = 0;
    int left = 0;
    int minLen = INT_MAX;

    for(int right = 0; right < nums.size(); right++)
    {
        sum += nums[right];

        while(sum >= target) {
            minLen = std::min(minLen right - left + 1);
            sum -= nums[left++];
        }
    }

    return minLen == INT_MAX ? 0 : minLen;
}


int shortestSubarray(std::vector<int> &nums, int k)
{
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;

    int sum = 0, minLen = INT_MAX;

    pq.push({0, -1});

    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        while(!pq.empty() && sum - pq.top().first >= k) {
            minLen = std::min(minLen, i - pq.top().second);
            pq.pop();
        }

        pq.push({sum, i});
    }

    return minLen == INT_MAX ? -1 : minLen;
}



//解法二:利用双端队列

int shortestSubarray(std::vector<int> &nums, int k)
{
    int n = nums.size(), res = n + 1;
    std::deque<int> dq;

    for(int i = 0; i < n; i++) 
    {
        if(i > 0) nums[i] += nums[i-1];
        
        if(nums[i] >= k) res = std::min(res, i + 1);

        while(!dq.empty() && nums[i] - nums[dq.front()] >= k) {
            res = std::min(res, i - dq.front());
            dq.pop_front();
        } 

        while(!dq.empty() && nums[i] <= nums[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    return res == n+1 ? -1 : res;
}


std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
{
    std::vector<int> res;
    std::deque<int> dq;

    for(int i = 0; i < nums.size(); i++)
    {
        if(!dp.empty() && i - dq.front() >= k) dq.pop_front();
        
        while(!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();

        dq.push_back(i);

        if(i >= k-1) res.push_back(nums[dq.front()]);
    }

    return res;
}


std::string minWindow(std::string s, std::string t)
{
    //先统计t中字符出现次数
    std::vector<int> tFreq(26, 0);
    for(const char &c : t) {
        tFreq[c-'a']++;
    }

    //滑动窗口
    std::vector<int> window;
    int count = 0;              //窗口中与字符串t相同的字符个数
    int left = 0;
    int minLen = INT_MAX, startIndex = 0;

    for(int right = 0; right < s.size(); right++)
    {
        char c = s[right];
        if(++window[c-'a'] <= tFreq[c-'a']) count++;

        while(count == t.size())
        {
            if(minLen < right - left + 1) {
                minLen = right - left + 1;
                startIndex = left;
            }

            if(--window[s[left]-'a'] < tFreq[s[left]-'a']) count--;
            left++;
        }
    }

    if(minLen == INT_MAX) return "";

    return s.substr(startIndex, minLen);
}



std::vector<int> findAnagrams(std::string s, std::string p)
{
    std::vector<int> mp(26. 0);
    for(const char &c : p) {
        mp[c-'a']++;
    }

    std::vector<int> res;

    std::vector<int> window(26, 0);
    
    for(int i = 0; i < s.size(); i++) 
    {
        window[s[i]-'a']++;

        if(i >= p.size()) window[s[i-p.size()]-'a']--;

        if(window == mp) res.push_back(i - (p.size()-1));
    }

    return res;
}




std::vector<int> computePrefix(std::string pattern);

int main() {
    std::string str = "issip";

    std::vector<int> res = computePrefix(str);

    for(const int &n : res) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}

std::vector<int> computePrefix(std::string pattern)
{
    int n = pattern.size();
    std::vector<int> prefix(n, 0);

    for(int i = 1, k = 0; i < n; i++)
    {
        while(k > 0 && pattern[k] != pattern[i]) {
            k = prefix[k-1];
        }

        if(pattern[i] == pattern[k]) {
            prefix[i] = ++k;
        }
        else {
            prefix[i] = k;
        }
    }

    return prefix;
}

int KMP(std::string str, std::string pattern)
{
    int m = str.size(), n = pattern.size();

    std::vector<int> prefix = computePrefix(pattern);

    for(int i = 0, k = 0; i < m; i++)
    {
        while(k > 0 && pattern[k] != str[i]) {
            k = prefix[k-1];
        }

        if(str[i] == pattern[k]) k++;

        if(k == n) return i - m + 1;
    }

    return -1;
}

int maxSubArray(std::vector<int> &nums)
{
    int sum = 0, ans = INT_MIN;

    for(const int &n : nums) {
        sum += n;
        sum = std::max(sum, n);
        ans = std::max(ans, sum);
    }

    return ans;
}

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root)
{
    std::vector<std::vector<int>> res;

    if(!root) return res;

    std::queue<TreeNode*> que;
    que.push(root);

    int flag = 0;

    while(!que.empty())
    {
        std::vector<int> tmp;
        for(int size = que.size(); size > 0; size--)
        {
            auto cur = que.front(); que.pop();
            tmp.push_back(cur->val);
            
            if(cur->left) que.push(cur->left);
            if(cur->right) que.push(cur->right);
        }

        if(flag) reverse(tmp.begin(), tmp.end());

        res.push_back(tmp);

        flag = 1 - flag;
    }

    return res;
}


int singleNoDuplicate(std::vector<int> &nums)
{
    int res = 0;
    for(const int &n : nums) {
        res ^= n;
    }

    return res;
}

int singleNoDuplicate(std::vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;

    while(left < right)
    {
        int mid = left + ((right - left) >> 1);
        if(mid & 1) {
            if(nums[mid] == nums[mid-1]) left = mid + 1;
            else right = mid;
        }
        else {
            if(nums[mid] == nums[mid+1]) left = mid + 2;
            else right = mid;
        }
    }

    return nums[left];
}


int misssingNumber(std::vector<int> &nums)
{
    int n = nums.size();

    int total = (n+1)*n/2;

    int sum = accumulate(nums.begin(), nums.end(), 0);

    return total - sum;
}

int misssingNumber(std::vector<int> &nums)
{
    int res = nums.size();

    for(int i = 0; i < nums.size(); i++) {
        res ^= (i^nums[i]);
    }

    return res;
}

int misssingNumber(std::vector<int> &nums)
{
    int n = nums.size();

    for(int i = 0; i < n; i++)
    {
        while(nums[i] < n && nums[i] != i) std::swap(nums[i], nums[nums[i]]);
    }

    for(int i = 0; i < n; i++) {
        if(nums[i] != i) return i;
    }

    return n;
}

int findDuplicate(std::vector<int> &nums)
{
    int n = nums.size();

    for(int i = 0; i < n; i++) 
    {
        int index = abs(nums[i]) - 1;
        if(nums[index] > 0) nums[index] *= (-1);
        else {
            return abs(nums[i]);
        }
    }

    return -1;
}

int findDuplicate(std::vector<int> &nums)
{
    int slow = nums[0], fast = nums[nums[0]];

    while(slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    int finder = 0;
    while(nums[finder] != nums[slow]) {
        find = nums[finder];
        slow = nums[slow];
    }

    return nums[finder];
}


std::vector<int> findDuplicate(std::vector<int> &nums)
{
    std::vector<int> res;

    for(int i = 0; i < nums.size(); i++) {
        int index = abs(nums[i]) - 1;
        if(nums[index] > 0) nums[index] *= (-1);
        else {
            res.push_back(abs(nums[i]));
        }
    }

    return res;
}

std::vector<int> findDisappearedNumbers(std::vector<int> &nums)
{
    std::vector<int> res;

    for(int i = 0; i < nums.size(); i++) {
        int index = abs(nums[i]) - 1;
        if(nums[index] > 0) nums[index] *= (-1);
    }

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > 0) res.push_back(i + 1);
    }

    return res;
}

std::vector<int> findDisappearedNumbers(std::vector<int> &nums)
{
    std::vector<int> res;

    for(int i = 0; i < nums.size(); i++)
    {
        while(nums[i] != (i+1)) std::swap(nums[i], nums[nums[i]-1]);
    }

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != i + 1) res.push_back(i+1);
    }

    return res;
}

int firstMissingPositive(std::vector<int> &nums)
{
    int n = nums.size();

    for(int i = 0; i < nums.size(); i++) 
    {
        while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]) std::swap(nums[i], nums[nums[i]-1]);
    }

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != i + 1) return i+1;
    }

    return n + 1;
}

void setZeros(std::vector<std::vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();

    int col0 = 1;

    for(int i = 0; i < m; i++) {
        if(matrix[i][0] == 0) col0 = 0;
        for(int j = 1; j < n; j++) {
            if(matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
        }
    }

    for(int i = m-1; i >= 0; i--) {
        for(int j = n-1; j >= 1; j--) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
        }
        if(col0 == 0) matrix[i][0] = 0;
    }

}


// Leetcode第546题: 消箱子游戏
// dp[i][j][k]表示区间[i,j]之间的最大和,且(0,i)之间有k个数和nums[i]相同
// 所求结果为 dp[0][n-1][0]
// 1.如果移除nums[i], 则dp[k][j][k] = (1+k)*(1+k) + dp[i+1][j][0]
// 2.如果(i,j)之间存在某个数nums[m]=nums[i], 则考虑将[i+1,m-1]部分移除,再考虑剩下的[m][j][k+1]部分. k+1是现在nums[i]和nums[m]相邻了
//   dp[i][j][k] = dp[i+1][m-1][0] + dp[m][j][k+1]

int dp[100][100][100];

int removeBoxes(std::vector<int> &nums)
{
    int n = nums.size();
    memset(dp, 0, sizeof(dp));

    return dfs(nums, 0, n-1, 0, dp);
}

int dfs(std::vector<int> &nums, int i, int j, int k)
{
    if(i > j) return 0;

    if(dp[i][j][k] > 0) return dp[i][j][k];

    int res = (1+k)*(1+k) + dfs(nums, i + 1, j, 0);

    for(int m = i + 1; m <= j; m++) {
        if(nums[m] == nums[i]) {
            res = std::max(res, dfs(nums, i + 1, m - 1, 0) + dfs(nums, m, j, k + 1));
        }
    }

    return dp[i][j][k] = res;
}

std::vector<int> findErrorNums(std::vector<int> &nums)
{
    std::vector<int> res;

    for(int i = 0; i < nums.size(); i++) {
        int index = abs(nums[i]) - 1;
        if(nums[index] > 0) nums[index] *= (-1);
        else res.push_back(abs(nums[i]));
    }

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > 0) res.push_back(i + 1);
    }

    return res;
}

int findDuplicate(std::vector<int> &nums)
{
    for(int i = 0; i < nums.size(); i++)
    {
        while(nums[i] != i+1) {
            if(nums[i] == nums[nums[i-1]]) break;
            else std::swap(nums[i], nums(nums[i]-1));
        }
    }

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != i + 1) return nums[i];
    }

    return -1;
}

std::vector<int> findErrorNums(std::vector<int> &nums)
{
    for(int i = 0; i < nums.size(); i++) 
    {
        while(nums[i] != i+1) {
            if(nums[i] == nums[nums[i]-1]) break;
            std::swap(nums[i], nums[nums[i]-1]);
        }
    }

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != i + 1) return {nums[i], i + 1};
    }

    return {};
}

std::string removeDuplicate(std::string s)
{
    std::string res;

    for(const char &c : s) {
        if(!res.empty() && c == res.back()) res.pop_back();
        else res.push_back(c);
    }

    return res;
}

std::string removeDuplicate(std::string s, int k)
{
    std::vector<std::pair<char,int>> vec;

    // for(const char &c : s)
    // {
    //     if(vec.empty() || c != vec.back().first) {
    //         vec.push_back({c,1});
    //     }
    //     else if(++vec.back().second == k) {
    //         vec.pop_back();
    //     }
    // }

    for(const char &c : s)
    {
        if(!vec.empty() && c == vec.back().first) {
            if(++vec.back().second == k) {
                vec.pop_back();
            }
        }
        else vec.push_back({c, 1});
    }

    std::string res;

    for(auto &item : vec) {
        res += std::string(item.second, item.first);
    }

    return res;
}


std::string addBracket(std::string s)
{
    std::string res;
    int left = 0;

    for(int right = 0; right < s.size(); right++)
    {
        if(!isdigit(s[right])) res.push_back(s[right]);
        else {
            res.push_back('(');
            left = right;
            while(right < s.size() && isdigit(s[right])) right++;
            res += s.substr(left, right - left);
            res.push_back(')');
            right--;
        }
    }

    return res;
}


int main() {
    std::vector<int> nums;

    for(int i = 0; i < 10; i++) nums.push_back(i);

    for(const int &n : nums) std::cout << n << " ";
    std::cout << std::endl;

    // auto it = remove_if(nums.begin(), nums.end(), [](const int &x){
    //     return !(x&1);
    // });

    // nums.erase(it, nums.end());

    nums.erase(remove_if(nums.begin(), nums.end(), [](const int &x) { return !(x&1); }), nums.end());

    for_each(nums.begin(), nums.end(), [](int &n){ std::cout << n << " "; });

    // for(const int &n : nums) std::cout << n << " ";
    // std::cout << std::endl;

    return 0;
}


bool wordBreak(std::string s, std::vector<std::string> &wordDict)
{
    int n = s.size();
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        for(auto &word : wordDict) {
            int len = word.size();
            if(i >= len && s.substr(i-len, len) == word) dp[i] = dp[i] || dp[i-len];
        }
    }

    return dp[n];
}


std::unordered_map<std::string, int> hash;

bool wordBreak(std::string s, std::vector<std::string> &wordDict)
{
    std::unordered_set<std::string> mySet(wordDict.begin(), wordDict.end());

    return dfs(s, wordDict, mySet);
}

bool dfs(std::string s, std::vector<std::string> &wordDict, std::unordered_set<std::string> &mySet)
{
    if(hash.count(s)) return hash[s];

    if(s.empty()) return true;

    for(auto &word : wordDict)
    {
        int len = word.size();
        if(s.size() >= len && mySet.count(s.substr(0,len)) && dfs(s.substr(len), wordDict, mySet)) {
            hash[s] = 1;
            return true;
        }
    }

    hash[s] = 0;

    return false;
}

int res = INT_MIN;

int maxPathSum(TreeNode *root)
{
    if(root == nullptr) return 0;

    dfs(root);

    return res;
}

int dfs(TreeNode *root)
{
    if(root == nullptr) return 0;

    int leftMax = std::max(0, dfs(root->left));
    int rightMax = std::max(0, dfs(root->right));

    res = std::max(res, root->val + leftMax + rightMax);

    return root->val + std::max(leftMax, rightMax);
}


int maxLen = 0;

int longestUnivaluePath(TreeNode *root)
{
    if(root == nullptr) return 0;

    dfs(root);

    return maxLen;
}

int dfs(TreeNode *root)
{
    if(root == nullptr) return 0;

    int leftLen = dfs(root->left);
    int rightLen =  dfs(root->right);

    int left = (root->left && root->val == root->left->val) ? leftLen + 1 : 0;
    int right = (root->right && root->val == root->right->val) ? rightLen + 1 : 0;

    maxLen = std::max(maxLen, left + right);

    return std::max(left, right);
}


bool hasPathSum(TreeNode *root, int target)
{
    if(root == nullptr) return false;

    if(root->val == target && !root->left && !root->right) return true;

    return hasPathSum(root->left, target - root->val) || hasPathSum(root->right, target - root->val);
}

std::vector<std::vector<int>> res;

std::vector<std::vector<int>> pathSum(TreeNode *root, int target)
{
    if(root == nullptr) return res;
    
    std::vector<int> path;
    dfs(root, target, path);

    return res;
}

void dfs(TreeNode *root, int target, std::vector<int> &path)
{
    if(root == nullptr) return;

    path.push_back(root->val);

    if(root->val == target && !root->left && !root->right) {
        res.push_back(path);
    }   

    dfs(root->left, target - root->val, path);
    dfs(root->right, target - root->val, path);

    path.pop_back();
}


int pathSum(TreeNode *root, int target)
{
    if(root == nullptr) return 0;

    return dfs(root, target) + pathSum(root->left, target) + pathSum(root->right, target);
}

int dfs(TreeNode *root, int target)
{
    if(root == nullptr) return 0;

    return (root->val == target ? 1 : 0) + dfs(root->left, target - root->val) + dfs(root->right, target - root->Val); 
}



int main() {
    std::string str;
    std::cin >> str;
    // getline(std::cin, str, ';');

    // std::cout << str <<  std::endl;

    // std::string str = "hello,a,2,d;";

    std::stringstream in(str);
    std::string out;

    std::vector<std::string> words;

    while(getline(in, out, ',')) {
        // if(!out.empty()) {
            words.push_back(out);
        // }
    }

    for(auto &str : words) std::cout << str << 1 << std::endl;

    return 0;
}

int calculate(std::string s)
{
    char sign = '+';

    int res = 0, n = 0, pre;
    std::stack<int> sta;

    for(int i = 0; i < s.size(); i++)
    {
        if(isdigit(s[i])) n = n*10 + (s[i]-'0');

        if((!isspace(s[i]) && !isdigit(s[i])) || i == s.size() - 1) 
        {
            switch(sign)) {
                case '+' : sta.push(n); break;
                case '-' : sta.push(-n); break;
                case '*' : pre = sta.top(); sta.pop(); sta.push(pre*n); break;
                case '/' : pre = sta.top(); sta.pop(); sta.push(pre/n); break;
            }

            sign = s[i];
            n = 0;
        }
    }

    while(!sta.empty()) {
        res += sta.top();
        sta.pop();
    }

    return res;
}

int calculate(std::string s)
{
    char sign = '+';
    int num = 0, pre;

    std::stack<int> sta;

    for(int i = 0; i < s.size(); i++)
    {
        if(isdigit(s[i])) n = n*10 + (s[i] - '0');

        if(s[i] == '(') {
            int count = 0;
            int j = i;
            for(; j < s.size(); j++) {
                if(s[j] == '(') count++;
                if(s[j] == ')') count--;
                if(count == 0) break;
            }
            num = calculate(s.substr(i+1, j-i-1));
            i = j;  //计算后将i指向j
        }

        if((!isspace(s[i]) && !isdigit(s[i])) || i == s.size()-1) 
        {
            switch(sign) {
                case '+' : sta.push(num); break;
                case '-' : sta.push(-num); break;
                case '*' : pre = sta.top(); sta.push(pre/num); break;
                case '/' : pre = sta.top(); sta.push(pre/num); break;
            }
            sign = s[i];
            num = 0;
        }
    }

    int res = 0;
    while(!sta.empty()) {
        res += sta.top();
        sta.pop();
    }

    return res;
}

double epison = pow(10, -5);        //近似看做零

std::vector<char> operations = {'+', '-', '*', '/'};

bool judgePoint24(std::vector<int> &nums)
{
    std::vector<double> numbers;
    for(const int &n : nums) {
        numbers.push_back(n*1.0);
    }

    return dfs(numbers);
}

bool dfs(std::vector<double> &nums)
{
    if(nums.size() == 1) {
        if(fabs(nums[0]-24) < epison) return true;
    }

    std::vector<double> res;

    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = 0; j < nums.size(); j++)
        {
            if(i == j) continue;
            for(int k = 0; k < nums.size(); k++) {
                if(k != i && k != j) res.push_back(nums[k]);
            }

            for(auto &op : operations) 
            {
                if(i > j && (op == '+' || op == '*')) continue;
                if(op == '/' && fabs(nums[j]) < epison) continue;

                switch(op) {
                    case '+' : res.push_back(nums[i] + nums[j]); break;
                    case '-' : res.push_back(nums[i] - nums[j]); break;
                    case '*' : res.push_back(nums[i] * nums[j]); break;
                    case '/' : res.push_back(nums[i] / nums[j]); break;
                }

                if(dfs(res)) return true;
                res.pop_back();
            }
        }
    }

    return false;
}


// #include <unordered_map>
// #include <unordered_set>
// #include <climits>
// #include <algorithm>
// #include <string.h>
// #include <numeric>
// #include <list>
// #include <sstream>

// #include <bits/stdc++.h>

// __attribute__((constructor)) void before_main() {
//     printf("%s\n", "hi");
// }

// __attribute__((destructor)) void after_main() {
//     printf("%s\n", "world");
// }

void fun1() {
    printf("%s\n", "hi");
}

void fun2() {
    printf("%s\n", "world");
}

// struct A {
//     int data[2];
//     A(int x, int y) :data{x,y} {}
//     virtual void f(){}
// };

class A {
public:
    A(){}
    ~A(){
        throw 42;
    }
};

int main(int argc, char **argv) {
    try {
        A a;
        throw 32;
    }catch(int a) {
        std::cout << a;
    }

    return 0;
}

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
{
    std::vector<std::vector<int>> res;

    sort(intervals.begin(), intervals.end(), [](const std::vector<int> &a, const std::vector<int> &b){
        return a[0] < b[0];
    });

    res.push_back(intervals.front());

    for(int i = 1; i < intervals.size(); i++) {
        if(res.back()[1] >= intervals[i][0]) {
            res.back()[1] = std::max(res.back()[1], intervals[i][1]);
        }
        else {
            res.push_back(intervals[i]);
        }
    }

    return res;
}

int eraseOverlapInterval(std::vector<std::vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [](const std::vector<int> &a, const std::vector<int> &b){
        return a[1] < b[1];
    });

    int end = intervals[i][1];
    int count = 0;

    for(int i = 1; i < intervals.size(); i++) {
        if(end > intervals[i][0]) count++;
        else end = intervals[i][1];
    }

    return count;
}

int findMinArrowShots(std::vector<std::vector<int>> &points)
{
    sort(points.begin(), points.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
        return a[1] < b[1];
    });

    int count = 1;
    int end = points[i][1];

    for(int i = 1; i < points.size(); i++) {
        if(end < points[i][0]) {
            end = points[i][1];
            count++;
        }
    }

    return count;
}




int main() {
    std::vector<std::vector<int>> nums = {{1,2}, {2,3}, {3,4}, {1,3}};

    // sort(nums.begin(), nums.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
    //     return a[1] < b[1];
    // });

    // sort(nums.begin(), nums.end(), std::vector<int>greater<>)
    std::priority_queue<int,std::vector<int>,std::greater<int>> pq;

    for(auto &num : nums) {
        for(int &n : num) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}

//求有重叠区间个数
/*

int eraseOverlapInterval(std::vector<std::vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
        return a[1] < b[1];
    });

    int end = intervals[i][1];
    int count = 0;

    for(int i = 1; i < intervals.size(); i++) {
        if(end > intervals[i][0]) count++;
        else end = intervals[i][1];
    }

    return count;
}


//求没有重叠区间个数

int findMinArrowShots(std::vector<std::vector<int>> &points)
{
    sort(points.begin(), points.end(), [](const std::vector<int> &a, const std::vector<int> &b){
        return a[1] < b[1];
    }) 

    int end = points[0][1];
    int count = 1;

    for(int i = 1; i < points.size(); i++) {
        if(end < points[i][0]) {
            count++;
            end = points[i][1];
        }
    }

    return count;
}




int singleNumber(std::vector<int> &nums)
{
    std::vector<int> bitSum(32, 0);

    for(int &n : nums) {
        for(int i = 0; i < 32; i++) {
            if(n&1) bitSum[i]++;
            n >>= 1;
        }
    }

    // for(int i = 0; i < 32; i++) std::cout << nums[i] << " ";
    // std::cout << std::endl;

    int res = 0;
    for(int i = 31; i >= 0; i--) {
        res <<= 1;
        res += bitSum[i]%3;
    }

    return res;
}

int main() {
    std::vector<int> nums = {2,2,3,2};

    singleNumber(nums);
    // std::cout << singleNumber(nums) << std::endl;

    return 0;
}



//层序遍历构建二叉树
//       3
//     /   \
//    9     20
//   / \    /\
//null null 5 6

//该二叉树的层序遍历序列为 {3,9,20,null,null,5,6},按照该层序遍历序列构建一颗二叉树
//思路:需要借助队列

struct TreeNode {
    TreeNode *left, *right;
    int val;
    TreeNode(int m_val) : val(m_val), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreeByLevenSeq(std::vector<std::string> &nums)   //因为null不好用数字表示,这里全部用字符串存储
{
    if(nums.empty()) return nullptr;

    TreeNode *root = new TreeNode(std::stoi(nums[0]));
    std::queue<TreeNode*> que;
    que.push(root);

    int i = 1;
    while(!que.empty())
    {
        auto cur = que.front(); que.pop();

        //建左子节点
        if(i < nums.size()) {
            if(nums[i] != "null") {           
                int val = std::stoi(nums[i]);  
                cur->left = new TreeNode(val);
                que.push(cur->left);
            }
        }
        i++;    //这里数组要后移

        //建右子节点
        if(i < nums.size()) {
            if(nums[i] != "null") {
                int val = std::stoi(nums[i]);
                cur->right = new TreeNode(val);
                que.push(cur->right);
            }
        }
        i++;

    }   

    return root;
}


int main() {
    std::vector<std::string> nums = {"3","9","20","null","null","5","6"};

    TreeNode *root = buildTreeByLevenSeq(nums);


    std::vector<int> res;

    std::queue<TreeNode*> que;
    que.push(root);

    while(!que.empty())
    {
        auto cur = que.front(); que.pop();
        res.push_back(cur->val);

        if(cur->left) que.push(cur->left);
        if(cur->right) que.push(cur->right);
    }

    for(const int &n : res) {
        std::cout << n << " ";
    }
    std::cout << std::endl;


    return 0;
}



class maxHeap
{
private:
    std::vector<int> heap;
    int size;

public:
    maxHeap() {
        heap.push_back(-1);
        size = 0;
    }

    void swim(int pos)
    {
        while(pos > 1 && heap[pos] > heap[pos/2]) {
            std::swap(heap[pos], heap[pos/2]);
            pos /= 2;
        }
    }

    void sink(int pos)
    {
        int tmp = heap[pos];

        for(int j = 2*pos; j <= size; j *= 2)
        {
            if(j < size && heap[j] < heap[j+1]) j++;

            if(tmp >= heap[j]) break;

            heap[pos] = heap[j];

            pos = j;
        }

        heap[pos] = tmp;
    }

    void push(int x)
    {
        heap.push_back(x);
        size++;
        swim(size);
    }

    void pop()
    {
        std::swap(heap[1], heap[size]);
        heap.pop_back();
        size--;

        sink(1);
    }

    int top()
    {
        return heap[1];
    }

    bool empty() {
        return size < 1;
    }

};

int main() {
    maxHeap heap;
    heap.push(2);
    heap.push(4);
    heap.push(0);
    heap.push(6);
    heap.push(9);

    while(!heap.empty()) {
        std::cout << heap.top() << std::endl;
        heap.pop();
    }

    return 0;
}

int longestSubstring(std::string s, int k)
{
    if(s.empty() || s.size() < k) return 0;

    int maxLen = 0;

    for(int n = 1; n <= 26; n++)
    {
        std::vector<int> count(26, 0);
        int left = 0, uniqueChar = 0;

        for(int right = 0; right < s.size(); right++)
        {
            if(count[s[right]-'a']++ == 0) uniqueChar++;

            while(uniqueChar > n) {
                if(count[s[left++]-'a']-- == 1) uniqueChar--;
            }

            if(uniqueChar == n) {
                bool valid = true;
                for(int j = 0; j < 26; j++) {
                    if(count[j] > 0 && count[j] < k) return false;
                }
                if(valid) maxLen = std::max(maxLeft, right - left + 1);
            }
        }
    }

    return maxLen;
}


struct Node {
    int x;
    int len;
    Node(int m_x, int m_len) {
        x = m_x;
        len = m_len;
    }

    bool operator<(const Node &o1, const Node &o2) {
        return o1.len > o2.len;
    }
};


void dijkstra()
{
    std::vector<std::vector<int>> map(6, std::vector<int>(6, 0));
    initMap(map);

    std::vector<int> visited(6, 0);
    std::vector<int> distance(6, INT_MAX);

    std::prioriry_queue<Node> pq;
    distance[0] = 0;
    pq.push(Node(0,0));

    while(!pq.empty())
    {
        Node tmp = pq.top(); pq.pop();
        int index = tmp.x;
        int len = tmp.len;
        visited[index] = 1;

        for(int i = 0; i < map[index].size(); i++)
        {
            if(map[index][i] > 0 && !visited[i])
            {
                Node newNode = Node(i, len + map[index][i]);
                if(distance[i] > newNode.len) {
                    distance[i] = newNode.len;
                    pq.push(newNode);
                }
            }
        }

    }


}

void dijkstra()
{
    std::vector<std::vector<int>> map(6, std::vector<int>(6,0));
    initMap(map);

    std::vector<int> visited(6,0);
    std::vector<int> distance(6, INT_MAX);

    std::prioriry_queue<Node> pq;
    distance[0] = 0;
    pq.push(Node(0,0));

    while(!pq.empty())
    {
        Node tmp = pq.top(); qp.pop();
        int index = tmp.x;
        int len = tmp.len;
        visited[index] = 1;

        for(int i = 0; i < map[index].size(); i++)
        {
            if(map[index][i] && !visited[i])
            {
                Node newNode = Node(i, len + map[index][i]);
                if(distance[i] > newNode.len) {
                    distance[i] = newNode.len;
                    pq.push(newNode);
                }
            }
        }
    }

}

#define string const char*

int main() {
    int num = 1;
    printf("%d\n", char(num));

    // string str = "123";

    // std::cout << sizeof(str) << std::endl;

    // int num = 12;
    // const int *ptr = &num;
    // int *p = ptr;

    // int *p = const_cast<int*>(ptr);

    // *p = 22;

    // std::cout << *p << std::endl;


    return 0;
}


class UF
{
private:
    int count;
    std::vector<int> parent, size;

public:
    UF(int n)
    {
        count = n;
        parent.resize(n);
        size.resize(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    void unionNode(int p, int q)
    {
        int rootP = findNode(p);
        int rootQ = findNode(q);

        if(rootP == rootQ) return;

        if(size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }

        count--;
    }

    int findNode(int x)
    {
        while(parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }

        return x;
    }

    bool connected(int p, int q)
    {
        int rootP = findNode(p);
        int rootQ = findNode(q);

        return rootP == rootQ;
    }

    int countNum() {
        return count;
    }

};


void swapNum(std::vector<int> &nums, int sep);

int main() {
    std::vector<int> nums = {10,6,3,4,100,200};

    swapNum(nums, 5);

    for(const int &n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // int res = 0;

    // for(auto &n : mySet) {
    //     int x = n, y = n;
    //     while(mySet.count(x)) x--;
    //     while(mySet.count(y)) y++;
    //     res = std::max(res, y - x - 1);
    // }

    // std::cout << res << std::endl;
    
    // std::vector<int> res;
    // sort(res.begin(), res.end());

    return 0;
}

void swapNum(std::vector<int> &nums, int sep)
{
    for(int i = 0; i < nums.size()-1; i++)
    {
        if(nums[i] > sep && nums[i+1] < sep) {
            int j = i;
            while(nums[j] > sep && nums[j+1] < sep && j >= 0) {
                std::swap(nums[j], nums[j+1]);
                j--;
            } 
        }
    }

}



// typedef (int*ptr)(int, int);
// typedef int(*ptr)(int,int);

int add(int a, int b) {
    return a + b;
}

// int func(ptr p, int a, int b) {
//     return (*p)(a,b);
// }

int func(int (*ptr)(int, int), int a, int b)
{
    return (*ptr)(a,b);
}

int main() {
    std::cout << func(add, 1, 2) << std::endl;

    return 0;
}

int countNodes(TreeNode *root)
{
    if(root == nullptr) return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countNodes(TreeNode *root)
{
    int hei = 0;
    while(root) {
        hei++;
        root = root->left;
    }

    return (int)pow(2,hei) - 1;
}

//计算完全二叉树节点个数
int countNodes(TreeNode *root)
{
    int leftHei = 0, rightHei = 0;

    TreeNode *cur = root;

    while(cur) {
        leftHei++;
        cur = cur->left;
    }

    cur = root;
    while(cur) {
        rightHei++;
        cur = cur->right;
    }

    //完全二叉树
    if(leftHei == rightHei) {
        return (int)pow(2, leftHei) - 1;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int m_val) : val(m_val), next(nullptr) {}
};

int lastRemaining(unsigned int n, unsigned int m)
{
    ListNode *head = new ListNode(0);

    ListNode *cur = head;

    for(int i = 1; i < n; i++) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }

    cur->next = head;
    
    int len = n;
    cur = head;

    while(len != 1)
    {
        for(int i = 0; i < m-2; i++) {
            cur = cur->next;
        }

        ListNode *tmp = cur->next;
        cur->next = cur->next->next;

        // std::cout << tmp->val << std::endl;
        delete tmp;

        cur = cur->next;
        
        len--;
    }

    return cur->val;
}


int main() {
    std::cout << lastRemaining(5, 3) << std::endl;

    return 0;
}


#include <vector>
#include <algorithm>
#include <queue>
#include <set>

//调整成大顶堆
class maxHeap {
private:
    std::vector<int> heap;
    int size;

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

    //下沉
    void sink(int pos)
    {
        int tmp = heap[pos];

        for(int j = 2*pos; j <= size; j *= 2)
        {
            if(j < size && heap[j+1] > heap[j]) j++;

            if(tmp > heap[j]) break;

            heap[pos] = heap[j];

            pos = j;
        }

        heap[pos] = tmp;
    }

    void push(int x)
    {
        heap.push_back(x);
        size++;
        swim(size);
    }

    void pop()
    {
        std::swap(heap[1], heap[size]);
        heap.pop_back();
        size--;

        sink(1);
    }

    int top() {
        return heap[1];
    }

    bool empty() {
        return size < 1;
    }

};

void heapAdjust(std::vector<int> &nums, int start, int end);

void heapSort(std::vector<int> &nums)
{
    int n = nums.size() - 1;
    for(int i = n/2; i >= 1; i--) {
        heapAdjust(nums, i, n);
    }

    for(int i = n; i > 1; i--) {
        std::swap(nums[1], nums[i]);
        heapAdjust(nums, 1, i-1);
    }

}

void heapAdjust(std::vector<int> &nums, int start, int end)
{
    int tmp = nums[start];

    for(int j = 2*start; j <= end; j *= 2)
    {
        if(j < end && nums[j] < nums[j+1]) j++;

        if(tmp > nums[j]) break;
        
        nums[start] = nums[j];

        start = j;
    }

    nums[start] = tmp;
}

void shellSort(std::vector<int> &nums);

int main() {
    std::vector<int> nums = {-1,5,4,2,8,0,1,7};

    shellSort(nums);

    for(const int &n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}


void shellSort(std::vector<int> &nums)
{
    int gap = nums.size();

    do {
        gap = gap/3 + 1;

        for(int i = gap; i < nums.size(); i++) {
            if(nums[i] < nums[i-gap]) {
                int tmp = nums[i];
                int j = i - gap;
                for(; j >= 0 && nums[j] > tmp; j -= gap) {
                    nums[j+gap] = nums[j];
                }
                nums[j+gap] = tmp;
            }
        }

    } while(gap != 1);

}




template<class T = int> 
class Numbers {
public:
    Numbers(T v = 0) : val(v) {}

// private:
    T val;
};


int main() {
    Numbers<long double> test1;
    Numbers<> test2;


    return 0;
}

std::string validIpAddress(std::string IP)
{
    regex ipv4("((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])\\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])");
    regex ipv6("([0-9a-fA-F]{1,4}\\:){7}([0-9a-fA-F]{1,4})");

    if(regex_match(IP, ipv4)) {
        return "IPv4";
    }
    else if(regex_match(IP, ipv6)) {
        return "IPv6";
    }

    return "Neither";
}


#define max(a, b)

*/
/*

#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <climits>

int maxSum(std::vector<int> &nums, int k);

int main() {
    std::vector<int> nums = {4};
    int k = 2;

    maxSum(nums, k);   

    return 0;
}

int maxSum(std::vector<int> &nums, int k)
{
    std::set<int> mySet;
    mySet.insert(0);

    int sum = 0, res = INT_MIN;
    for(const int &n : nums) {
        sum += n;
        auto it = mySet.lower_bound(sum - k);
        if(it == mySet.end()) {
            std::cout << "hello" << std::endl;
            std::cout << *it << std::endl;
        }
        res = std::max(res, sum - *it);
        mySet.insert(sum);
    }

    return res;
}

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

void initMap(std::vector<std::vector<int>> &map);

struct Node {
    int x;
    int len;
    Node(int m_x, int m_len): x(m_x), len(m_len) {}

    // bool operator < (const Node &o1, const Node &o2) const {
    //     return o1.len > o2.len;
    // }

    // bool operator < (const Node &demo) const {
    //     return len > demo.len;
    // }

    bool operator<(const Node &demo) const {
        return len > demo.len;
    }

};

void dijkstra()
{
    std::vector<std::vector<int>> map(6, std::vector<int>(6, 0));
    initMap(map);

    std::vector<int> visited(6, 0);
    std::vector<int> distance(6, INT_MAX);

    std::priority_queue<Node> pq;
    distance[0] = 0;
    pq.push(Node(0,0));

    while(!pq.empty())
    {
        Node tmp = pq.top(); pq.pop();
        int index = tmp.x;
        int len = tmp.len;
        visited[index] = 1;

        for(int i = 0; i < map[index].size(); i++)
        {
            if(map[index][i] > 0 && !visited[i])
            {
                Node newNode = Node(i, len + map[index][i]);
                if(distance[i] > newNode.len) {
                    distance[i] = newNode.len;
                    pq.push(newNode);
                }
            }
        }
    }

    for(const int &n : distance) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

}

void initMap(std::vector<std::vector<int>> &map)
{
    map[0][1] = 2;  map[0][2] = 3;  map[0][3] = 6;
    map[1][0] = 2;  map[1][4] = 4;  map[1][5] = 6;
    map[2][0] = 3;  map[2][3] = 2;
    map[3][0] = 6;  map[3][2] = 2;  map[3][4] = 1;  map[3][5] = 3;
    map[4][1] = 4;  map[4][3] = 1;
    map[5][1] = 6;  map[5][3] = 3; 
}


int main() {
    // std::vector<int> nums = {1,2,3,4,5,6,7};

    // nums.erase(remove_if(nums.begin(), nums.end(), [](int x){ return x&1; }), nums.end());

    // for(const int &n : nums) {
    //     std::cout << n << " ";
    // }
    // std::cout << std::endl;

    dijkstra();

    return 0;
}


int findMaxConsectiveOnes(std::vector<int> &nums)
{
    int first = 0, second = 0;
    int maxLen = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 1) first++;
        else {
            second = first + 1;
            right = 0;
        }

        maxLen = std::max(maxLen, left + right);
    }

    return maxLen;
}

int findMaxConsectiveOnes(std::vector<int> &nums)
{
    int left = 0, right = 0;
    int maxLen = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 1) right++;
        else {
            left = right + 1;
            right = 0;
        }

        maxLen = std::max(maxLen, left + right);
    }

    return maxLen;
}
*/

// #include <bits/stdc++.h>
/*

void dfs(std::vector<std::vector<int>> &graph, int num, std::vector<int> &visited, int pos);
void allPaths(std::vector<std::vector<int>> &prere, int num);

std::vector<int> path;
std::vector<std::vector<int>> res;

int main() {
    std::vector<std::vector<int>> prere = {{1,2}, {1,3}, {1,4}, {2,3}, {2,4}, {3,4}};
    int num = 4;    //四个节点

    allPaths(prere, num);   

    for(auto &nums : res) {
        for(const int &n : nums) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

void allPaths(std::vector<std::vector<int>> &prere, int num)     //m代表节点个数
{
    std::vector<std::vector<int>> graph(num + 1);

    for(auto &pre : prere) {
        graph[pre[0]].push_back(pre[1]);
        graph[pre[1]].push_back(pre[0]);
    }

    std::vector<int> visited(num + 1, 0);
    visited[1] = 1;
    path.push_back(1);  //从节点1出发

    dfs(graph, num, visited, 1);

}

void dfs(std::vector<std::vector<int>> &graph, int num, std::vector<int> &visited, int pos)
{
    if(path.size() == num) {
        res.push_back(path);
        std::cout << "hello" << std::endl;
        return;
    }

    for(const int &n : graph[pos]) 
    {
        if(!visited[n]) 
        {
            path.push_back(n);
            visited[n] = 1;

            dfs(graph, num, visited, n);

            path.pop_back();
            visited[n] = 0;
        }
    }

}




void topologySort(std::vector<std::vector<int>> &prere, int num);
void dfs(std::vector<std::vector<int>> graph, int num, std::vector<int> &indegree, std::vector<int> &visited);

std::vector<std::vector<int>> res;
std::vector<int> path;

int main() {
    std::vector<std::vector<int>> prere = {{1,2}, {1,3}, {2,4}, {2,5}, {3,4}, {3,5}, {4,6}, {4,5}};
    int num = 6;

    topologySort(prere, num);

    for(auto &nums : res) {
        for(const int &n : nums) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

void topologySort(std::vector<std::vector<int>> &prere, int num)
{
    std::vector<std::vector<int>> graph(num + 1);
    std::vector<int> indegree(num + 1, 0);

    for(auto &e : prere) {
        graph[e[0]].push_back(e[1]);
        indegree[e[1]]++;
    }

    std::vector<int> visited(num + 1, 0);

    dfs(graph, num, indegree, visited);

}

void dfs(std::vector<std::vector<int>> graph, int num, std::vector<int> &indegree, std::vector<int> &visited)
{
    if(path.size() == num) {
        res.push_back(path);
        return;
    }

    for(int i = 1; i <= num; i++)
    {
        if(!visited[i] && indegree[i] == 0)
        {
            path.push_back(i);
            visited[i] = 1;
            for(const int &n : graph[i]) {
                indegree[n]--;
            }

            dfs(graph, num, indegree, visited);

            path.pop_back();
            visited[i] = 0;
            for(const int &n : graph[i]) {
                indegree[n]++;
            }
        }
    }

}


int main() {
    int n = -2;
    int count = 0;
    for(int i = 0; i < 32; i++) {
        count += (n&1);
        n >>= 1;
    }

    std::cout << count << std::endl;

    return 0;
}

select c1, c2 from table limit n, m;

//1.给出查询的大致范围
select c1, c2 from table where id >= 2000 limit 10;

//2.子查询
select c1, c2 from table where id >= (select id from table limit 2000, 1) limit 10

//3.使用覆盖索引

int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList)
{
    std::unordered_set<std::string> mySet(wordList.begin(), wordList.end());

    if(!mySet.count(endWord)) return 0;

    std::queue<std::string> que;
    que.push(beginWord);
    mySet.erase(beginWord);

    while(!que.empty())
    {
        for(int size = que.size(); size > 0; size--)
        {
            std::string cur = que.front(); que.pop();
            if(cur == endWord) return steps;

            for(char &c : cur)
            {
                char ch = c;
                for(int k = 0; k < 26; k++) {
                    c = k + 'a';
                    if(mySet.count(cur)) {
                        que.push(cur);
                        mySet.erase(cur);
                    }
                }
            }
            c = ch;
        }

        steps++;
    }

    return 0;
}

int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList)
{
    std::unordered_set<std::string> beginSet, endSet, wordSet(wordList.begin(), wordList.end());

    if(!wordSet.count(endWord)) return 0;

    beginSet.insert(beginWord);
    endSet.insert(endWord);
    wordSet.erase(beginWord);
    wordSet.erase(endWord);

    int steps = 1;

    while(!beginSet.empty() && !endSet.empty())
    {
        if(beginSet.size() > endSet.size()) std::swap(beginSet, endSet);

        std::unordered_set<std::string> tmp;

        for(auto &cur : beginSet)
        {
            std::string word = cur;

            for(int i = 0; i < word.size(); i++) {
                char c = word[i];
                for(int k = 0; k < 26; k++) {
                    word[i] = k + 'a';
                    if(endSet.count(word)) return steps + 1;

                    if(wordSet.count(word)) {
                        tmp.insert(word);
                        wordSet.erase(word);
                    }
                }
                word[i] = c;
            }

        }

        beginSet = tmp;
        steps++;
    }

    return 0;
}




// #include <iostream>

// class Test {
// public:
//     int num;
//     static print() {
//         std::cout << num << std::endl;
//     }
// }

class A {};

class B {};

int main() {
    B *b = new B;
    // a *a = new A;
    // B *b = (B*)()
    // A *a = (A*)(b);

    A *a = static_cast<A*>(b);

    // int num = 5;

    // const int &p = num;

    // int &ptr = const_cast<int&>(p);    

    // ptr = 10;

    // std::cout << num << " " << p << " " << ptr << std::endl;

    // int val;

    // val += 2;

    // std::cout << val << std::endl;

    // int *ptr = nullptr;
    // double n;
    // std::cout << n << std::endl;

    // std::cout << sizeof(float) << " "  << sizeof(double) << std::endl;

    // std::string str = "1";

    // str = str + std::to_string(10);

    // std::cout << str << std::endl;

    return 0;
}

#include <bits/stdc++.h>

class Base {
private:
    virtual void fun() { std::cout << "Base" << std::endl; }
    friend int main();
};

class Derived : public Base {
public:
    void fun() { std::cout << "Derived" << std::endl; }
};

void bubbleSort(std::vector<int> &nums);
void bubbleSort(std::vector<int> &nums)
{
    bool flag = true;

    for(int i = 0; i < nums.size() && flag; i++)
    {
        flag = false;
        for(int j = nums.size()-2; j >= i; j--) 
        {
            if(nums[j] > nums[j+1]) {
                std::swap(nums[j], nums[j+1]);
                flag = true;
            }
        }
    }

}


int main() {
    Base *ptr = new Derived;
    ptr->fun();

    return 0;
}


__attribute__((constructor)) void before_main() {
    printf("%s\n", "hi");
}

__attribute__((destructor)) void after_main() {
    printf("%s\n", "world");
}

void fun1() {
    printf("%s\n", "test1");
}

void fun2() {
    printf("%s\n", "test2");
}


int main() {
    printf("%s\n", "main");

    atexit(fun2);
    atexit(fun1);

    std::cout << "Finish" << std::endl;

    return 0;
}


std::unordered_map<Node*,Node*> hash;

Node* cloneGraph(Node* node)
{
    if(node == nullptr) return nullptr;

    if(hash.count(node)) return hash[node];

    hash[node] = new Node(node->val);

    for(auto &pNode : node->neighbors) {
        hash[node]->neighbors.push_back(cloneGraph(pNode));
    }

    return hash[node];
}


std::unordered_map<Node*, Node*> hash;

Node* copyRandomList(Node* head)
{
    if(head == nullptr) return head;

    Node *cur = head;
    while(cur) {
        hash[node] = new Node(cur->val);
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

Node* copyRandomList(Node *head)
{
    if(head == nullptr) return head;

    Node *cur = head;
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
            cur->next->random = cur->random->next;
        }
        cur = cur->next;
    }

    //拆分出新的链表
    cur = head;
    ListNode *pCopy = head->next, pCopyHead = pCopy;

    while(pCopy && pCopy->next) {
        cur = cur->next = pCopy->next;
        pCopy = pCopy->next = cur->next;
    }

    cur->next = nullptr;

    return pCopyHead;
}



struct Test {
    char sec;
    int len;
    char name[10];
};

int main() {
    std::cout << sizeof(Test) << std::endl;

    return 0;
}


double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
{
    int m = nums1.size(), n = nums2.size();
    if(m > n) return findMedianSortedArrays(nums2, nums1);

    int left = 0, right = m;
    while(left <= right)
    {
        int i = left + ((right-left) >> 1);
        int j = (m+n+1)/2 - i;

        int leftMaxX = (i == 0 ? INT_MIN : nums1[i-1]);
        int rightMinX = (i == m ? INT_MAX : nums1[i]);

        int leftMaxY = (j == 0 ? INT_MIN : nums2[j-1]);
        int rightMinY = (j == n ? INT_MAX : nums2[j]);

        if(leftMaxX <= rightMinY && leftMaxY <= rightMinX) {
            if((m+n)&1) return std::max(leftMaxX, leftMaxY);
            return (std::max(leftMaxX, leftMaxY) + std::min(rightMinX, rightMinY)) / 2.0;
        }
        else if(leftMaxX > rightMinY) {     //右边界左移
            right = i - 1;
        }
        else left = i + 1;                  //左边界右移
    }

    return  0;
}


int mySqrt(int n)
{
    if(n == 0) return 0;

    int left = 1, right = n;

    while(left <= right)
    {
        int mid = left + ((right-left) >> 1);
        if(mid == n/mid) return mid;
        else if(mid < n/mid) left = mid + 1;
        else if(mid > n/mid) right = mid - 1;
    }

    return right;
}


int mySqrt(int n)
{
    long x = n;
    while(x*x > n) {
        x = (x + n/x)/2;
    }

    return x;
}


std::vector<int> searchReange(std::vector<int> &nums, int target)
{
    return {findLeftBound(nums, target), findRightBound(nums, target)};
}

int findLeftBound(std::vector<int> &nums, int target)
{
    int n = nums.size();

    int left = 0, right = n-1;

    while(left <= right)
    {
        int mid = left + ((right-left) >> 1);

        if(nums[mid] < target) left = mid + 1;
        else if(nums[mid] >= target) right = mid - 1;
    }

    if(left == n || nums[left] != target) return -1;

    return left;
}

int findRightBound(std::vector<int> &nums, int target)
{
    int n = nums.size();

    int left = 0, right = n - 1;

    while(left <= right)
    {
        int mid = left + ((right-left) >> 1);

        if(nums[mid] <= target) left = mid + 1;
        else if(nums[mid] > target) right = mid - 1;
    }

    if(right == -1 || nums[right] != target) return -1;

    return right;
}


int kthSmallest(std::vector<std::vector<int>> &matrix, int k)
{
    int m = matrix.size(), n = matrix[0].size();

    int left = matrix[0][0], right = matrix[m-1][n-1];

    while(left <= right)
    {
        int mid = left + ((right-left) >> 1);

        int count = 0;
        for(int i = 0; i < m; i++) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if(count < k) left = mid + 1;
        else if(count >= k) right = mid - 1;
    }

    return left;
}


int search(std::vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while(left <= right)
    {
        int mid = left + ((right-left) >> 1);

        if(nums[mid] == target) return mid;

        else if(nums[mid] > nums[right]) {
            if(nums[left] <= target && target < nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        
        else if(nums[mid] <= nums[right]) {
            if(nums[mid] < target && target <= nums[right]) left = mid + 1;
            else right = mid - 1;
        }
    }

    return -1;
}


void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
{
    int k = m + n - 1;
    int i = m-1, j = n-1;

    while(i >= 0 && j >= 0)
    {
        if(nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
    }

    while(j >= 0) {
        nums1[k--] = nums2[j--];
    }

}


int findMin(std::vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;

    while(left < right)
    {
        int mid = left + ((right-left) >> 1);

        if(nums[mid] < nums[right]) right = mid;
        else if(nums[mid] > nums[right]) left = mid + 1;
        else if(nums[mid] == nums[right]) right--;
    }

    return left;
}


class Test {
public:
    Test() {}
    ~Test() { std::cout << "~Test" << std::endl; }
};

class ADT {
public:
    ADT() { std::cout << "ADT" << std::endl; }
    ~ADT() { std::cout << "~ADT" << std::endl; }
};

// class A {
// public:
//     A() { std::cout << "A" << std::endl; }
//     void destory() { delete this; }

// private:
//     ~A() { std::cout << "~A" << std::endl; }
// };

class A {
private:
    // void* operator new(size_t t) {}
    // void operator delete(void *ptr) {}

public:
    A() { std::cout << "A" << std::endl; }
    ~A() { std::cout << "~A" << std::endl; }

    void print() = delete;

};

void A::print() {
    std::cout << "hi" << std::endl;
}


int main() {
    A a;
    a.print();

    // A a;
    // A *p = new A();

    // A *p = new A();
    // p->destory();

    // char *p = new(std::nothrow) char[sizeof(ADT)];
    // if(p == NULL) std::cout << "Failed" << std::endl;

    // ADT *q = new(p) ADT;
    // q->ADT::~ADT();
    // delete[] p;

    // int *p = new int[10];
    // Test *p = new Test[10];
    // delete[] p;
    // char *p = nullptr;
    // try {
    //     p = new char[100000000000];
    // } catch(std::bad_alloc x) {
    //     std::cout << "fail" << std::endl;
    //     return -1;
    // }
    // std::cout << "success" << std::endl;
    // delete[] p;

    return 0;
}


std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();

    int left = 0, right = n - 1;
    int up = 0, down = m - 1;

    std::vector<int> res;

    while(res.size() != m*n)
    {
        for(int j = left; j <= right && res.size() != m*n; j++) res.push_back(matrix[up][j]);

        for(int i = up + 1; i < down && res.size() != m*n; i++) res.push_back(matrix[i][right]);

        for(int j = right; j >= left && res.size() != m*n; j--) res.push_back(matrix[down][j]);

        for(int i = down - 1; i > up && res.size() != m*n; i--) res.push_back(matrix[i][left]);

        left++, right--;
        up++, down--;
    }

    return res;
}


*/

// #include <iostream>
// #include <vector>
/*
void findSubTree(int root, std::vector<int> &relation, std::vector<int> &storage, std::deque<int> &que);

int main() {
    int n;
    std::cin >> n;

    std::vector<int> value(n, 0);
    for(int i = 0; i < n; i++) std::cin >> value[i];
    
    int sum = accumulate(value.begin(), value.end(), 0);        //计算总和

    std::vector<int> tree;
    std::string str;
    while(getline(std::cin, str)) {
        if(!str.empty()) {
            std::stringstream in(str);
            std::string out;
            while(getline(in, out, ' ')) {
                if(!out.empty()) tree.push_back(std::stoi(out));
            }
        }
    }

    std::vector<int> storage;
    std::deque<int> que;

    int res[2] = {0,0};
    int maxdiff = 0;

    for(int i = 1; i < n; i++)      //根节点不需要尝试
    {
        storage.clear();

        int subTreeSum = 0;
        storage.push_back(i);

        findSubTree(i, tree, storage, que);

        for(int pos : storage) subTreeSum += value[pos];

        int diff = abs(sum - 2*subTreeSum);

        if(diff > maxdiff) {
            maxdiff = diff;
            res[0] = i, res[1] = maxdiff;
        }

    }

    std::cout << res[0] << " " << res[1] << std::endl;

    return 0;
}


void findSubTree(int root, std::vector<int> &relation, std::vector<int> &storage, std::deque<int> &que)
{
    que.clear();

    for(int i = 0; i < relation.size(); i++)
    {
        if((i%2==0) && relation[i] == root) {
            que.push_back(relation[i+1]);
            storage.push_back(relation[i+1]);
        }
    }

    for(int pos : que) {
        findSubTree(pos, relation, storage, que);
    }

}


int dfs(const std::string &str);

int countDigitOne(int n)
{
    if(n <= 0) return 0;

    std::string str = std::to_string(n);

    return dfs(str);
}

int dfs(const std::string &str)
{
    int first = str.front() - '0';
    int len = str.size();

    if(len == 1 && first == 0) return 0;
    if(len == 1 && first > 0) return 1;

    int numFirstDigit = 0;
    if(first > 1) numFirstDigit = (int)pow(10, len - 1);
    else if(first == 1) numFirstDigit = std::stoi(str.substr(1)) + 1;

    int numOtherDigit = first*(len - 1)*(int)pow(10, len-2);

    std::cout << numOtherDigit << std::endl;

    int numRecursive = dfs(str.substr(1));

    return numFirstDigit + numOtherDigit + numRecursive;
}

int main() {
    std::cout << countDigitOne(13) << std::endl;

    return 0;
}

int countDigitOne(int n)
{
    if(n <= 0) return 0;

    std::string s = std::to_string(n);

    return countDigitOneCore(s);
}

int countDigitOneCore(const std::string &str)
{
    int first = str.front() - '0';
    int len = str.size();

    if(len == 1 && first == 0) return 0;
    if(len == 1 && first > 0) return 1;

    int numFirstDigit = 0;
    if(first > 1) numFirstDigit = (int)pow(10, len-1);
    else if(first == 1) numFirstDigit = std::stoi(str.substr(1)) + 1;

    int numOtherDigit = first * (len-1) * (int)pow(10, len-2);

    int numRecursive = countDigitOneCore(str.substr(1));

    return numFirstDigit + numOtherDigit + numRecursive;
}


bool isValidBST(TreeNode *root)
{
    if(root == nullptr) return root;

    TreeNode *prev = nullptr;

    return dfs(root, prev);
}

bool dfs(TreeNode *root, TreeNode *&prev)
{
    if(root == nullptr) return true;

    if(!dfs(root->left, prev)) return false;

    if(prev && root->val <= prev->val) return false;

    prev = root;

    return dfs(root->right, prev);
}


bool isValidBST(TreeNode *root)
{
    if(root == nullptr) return true;

    return dfs(root, nullptr, nullptr);
}

bool dfs(TreeNode *root, TreeNode *min, TreeNode *max)
{
    if(root == nullptr) return true;

    if(min && root->val <= min->val) return false;
    if(max && root->val >= max->val) return false;

    return dfs(root->left, min, root) && dfs(root->right, root, max);
}


std::vector<int> res;
int maxFreq = 0, curFreq = 0;

std::vector<int> findMode(TreeNode *root)
{
    if(root == nullptr) return res;

    TreeNode *prev = nullptr;

    dfs(root, prev);

    return res;
}

void dfs(TreeNode *root, TreeNode *&prev)
{
    if(root == nullptr) return;

    dfs(root->left, prev);

    if(prev && root->val == prev->val) curFreq++;
    else curFreq = 1;

    if(maxFreq > curFreq) {
        maxFreq = curFreq;
        res.clear();
        res.push_back(root->Val);
    }
    else res.push_back(root->val);

    prev = root;

    dfs(root->right, prev);
}


std::vector<int> findOrder(int num, std::vector<std::vector<int>> &prere)
{
    std::vector<std::vector<int>> graph(num);   //邻接矩阵
    std::vector<int> degree(num);               //入度

    for(auto &e : prere) {
        graph[e[1]].push_back(e[0]);
        degree[e[0]]++;
    }

    std::vector<int> ans;
    for(int i = 0; i < num; i++) {
        if(degree[i] == 0) ans.push_back(i);
    }

    for(int i = 0; i < ans.size(); i++)
    {
        for(int &n : graph[ans[i]]) {
            if(--degree[n] == 0) ans.push_back(n);
        }
    }   

    return ans.size() == num ? ans : std::vector<int>();
}


int slidingPuzzle(std::vector<std::vector<int>> &board)
{
    int m = board.size(), n = board[0].size();

    std::string target = "123450";

    std::string start;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            start += std::to_string(board[i][j]);
        }
    }

    std::vector<std::vector<int>> dir = {{1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}};

    if(start == target) return 0;

    std::queue<int> que;
    std::unordered_set<std::string> visited;
    que.push(start);
    visited.insert(start);

    int steps = 0;

    while(!que.empty())
    {
        for(int size = que.size(); size > 0; size--)
        {
            auto cur = que.front(); que.pop();

            int index = cur.find('0');
            
            for(const int &n : dir[index])
            {
                std::swap(cur[index], cur[n]);
                if(!visited.count(cur)) {
                    if(cur == target) return steps + 1;
                    que.push(cur);
                    visited.insert(cur);
                }
                std::swap(cur[index], cur[n]);
            }
        }
    }

    return -1;
}
*/

// #include <bits/stdc++.h>
/*

class A {
public:
    void print() {}
};

class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};

int main() {
    std::vector<int> nums = {-1,-2,-3};
    transform(nums.begin(), nums.end(), nums.begin(), [](int i)->int { return i < 0 ? -1 : i;});

    for(const int &n : nums) std::cout << n << std::endl;

    return 0;
}


TreeNode* buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
{
    std::unordered_map<int,int> inorderPos;
    for(int i = 0; i < inorder.size(); i++) {
        inorderPos[inorder[i]] = i;
    }

    return dfs(preorder, 0, preorder.size()-1, 0, inorderPos);
}

TreeNode *dfs(std::vector<int> &preorder, int startPreorder, int endPreorder, int startInorder, std::unordered_map<int,int> &inorderPos)
{
    if(startPreorder > endPreorder) return nullptr;

    TreeNode *root = new TreeNode(preorder[startPreorder]);

    int rootIndex = inorderPos[preorder[startPreorder]];
    int leftLen = rootIndex - startInorder;

    root->left = dfs(preorder, startPreorder + 1, startPreorder + leftLen, startPreorder, inorderPos);
    root->right = dfs(preorder, startPreorder + leftLen + 1, endPreorder, rootIndex + 1, inorderPos);

    return root;
}


TreeNode* buildTree(std::vector<int> &postorder, std::vector<int> &inorder)
{
    std::unordered_map<int,int> inorderPos;
    for(int i = 0; i < inorder.size(); i++) {
        inorderPos[postorder[i]] = i;
    }

    return dfs(postorder, 0, postorder.size() - 1, 0, inorderPos);
}

TreeNode *dfs(std::vector<int> &postorder, int startPostorder, int endPostorder, int startInorder, std::unordered_map<int,int> &inorderPos)
{
    if(startPostorder > endPostorder) return nullptr;

    TreeNode *root = new TreeNode(postorder[endPostorder]);

    int rootIndex = inorderPos[postorder[endPostorder]];
    int leftLen = rootIndex - startInorder;

    root->left = dfs(preorder, startPreorder, startPreorder + leftLen - 1, startInorder, inorderPos);
    root->right = dfs(preorder, startPreorder + leftLen, endPostorder - 1, rootIndex + 1, inorderPos);

    return root;
}


TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root == nullptr) return root;

    if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);

    if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);

    return root;
}


TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root == nullptr || root == p || root == q) return root;

    TreeNode *pLeft = lowestCommonAncestor(root->left, p, q);
    TreeNode *pRgiht = lowestCommonAncestor(root->right, p, q);

    if(pLeft && pRight) return root;

    return pLeft ? pLeft : pRight;
}


TreeNode* invertTree(TreeNode *root)
{
    if(root == nullptr) return nullptr;

    std::swap(root->left, root->right);

    invertTree(root->left);
    invertTree(root->right);

    return root;
}


TreeNode* invertTree(TreeNode *root)
{
    if(root == nullptr) return root;

    std::stack<TreeNode*> sta;
    sta.push(root);

    while(!sta.empty())
    {
        TreeNode *pNode = sta.top(); sta.pop();

        std::swap(pNode->left, pNode->right);

        if(pNode->right) sta.push(pNode->right);

        if(pNode->left) sta.push(pNode->left);
    }

    return root;
}


std::vector<int> res;

std::vector<int> rightView(TreeNode *root)
{
    if(root == nullptr) return res;

    dfs(root, 1);

    return res;
}

void dfs(TreeNode *root, int level)
{
    if(root == nullptr) return;

    if(res.size() < level) res.push_back(root->val);

    dfs(root->right, level + 1);
    dfs(root->left, level + 1);

}


std::vector<int> rightSideView(TreeNode *root)
{
    std::vector<int> res;

    std::queue<TreeNode*> que;
    que.push(root);

    while(!que.empty())
    {
        int size = que.size();
        for(int i = 0; i < size; i++) 
        {
            auto cur = que.frnt();  que.pop();

            if(i == size-1) res.push_back(cur->val);

            if(cur->left) que.push(cur->left);
            if(cur->right) que.push(cur->right);
        }

    }

    return res;
}


namespace my {
    template<typename T>
    typename std::remove_reference<T>::type&& move(T&& t) {
        return static_cast<typename std::remove_reference<T>::type&&>(t);
    }
};

int main() {
    std::string s1("hi"), s2;
    s2 = my::move(std::string("bye"));
    s2 = my::move(s1);

    return 0;
}



void dfs(std::string num, int target, long long diff, long long curNum, std::string path);

std::vector<std::string> res;

std::vector<std::string> addOperators(std::string num, int target)
{
    std::vector<std::string> res;
    dfs(num, target, 0, 0, "");

    return res;
}

void dfs(std::string num, int target, long long diff, long long curNum, std::string path)
{
    if(num.empty() && curNum == target) {
        res.push_back(path);
        return;
    }

    for(int i = 1; i <= num.size(); i++)
    {
        std::string cur = num.substr(0, i);

        if(cur.size() > 1 && cur[0] == '0') return;     //去掉 "00x"的结果

        std::string next = num.substr(i);

        if(path.size() > 0) {
            dfs(next, target, std::stoll(cur), curNum + std::stoll(cur), path + "+" + cur);     // "+"
            dfs(next, target, -std::stoll(cur), curNum - std::stoll(cur), path + "-" + cur);     // "-"
            dfs(next, target, diff*std::stoll(cur), (curNum-diff) + diff*std::stoll(cur), path + "*" + cur);
        }
        else {
            dfs(next, target, std::stoll(cur), std::stoll(cur), cur);
        }
    }

}

int main() {
    std::string num = "123";
    int target = 6;

    addOperators(num, target);

    for(auto &str: res) {
        std::cout << str << std::endl;
    }

    return 0;
}


class Test {
public:
    Test(int m_val, std::string str) : val(m_val) {
        std::cout << "构造函数" << std::endl;
    } 
    int val;
};

int main() {
    std::vector<Test> nums;
    // nums.push_back(Test(1));
    // nums.push_back(1, "");
    nums.emplace_back(1, "");

    return 0;
}


int getMaximumGold(std::vector<std::vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    int res = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j]) res = std::max(res, dfs(grid, i, j));
        }
    }

    return res;
}

int dfs(std::vector<std::vector<int>> &grid, int i, int j)
{
    int m = grid.size(), n = grid[0].size();

    int ans = grid[i][j];

    int tmp = grid[i][j];
    grid[i][j] = 0;

    for(int k = 0; k < dir.size()-1; k++) {
        int x = i + dir[k], y = j + dir[k+1];
        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y]) {
            ans = std::max(ans, grid[i][j] + dfs(grid, x, y));
        }
    }

    grid[i][j] = tmp;

    return ans;
}



int distinctSubseqII(std::string s);

int main() {
    std::string s = "aaa";

    std::cout << distinctSubseqII(s) << std::endl;

    return 0;
}


int distinctSubseqII(std::string s)
{
    long mod = 1e9 + 7;

    std::vector<long> endsWith(26);

    for(const char &c : s) {
        endsWith[c-'a'] = accumulate(endsWith.begin(), endsWith.end(), 1) % mod;
    }

    return accumulate(endsWith.begin(), endsWith.end(), 0) % mod;
}


TreeNode *pFirst = nullptr, *pSecond = nullptr;

void recoverTree(TreeNode *root)
{
    if(root == nullptr) return;

    TreeNode *prev = nullptr;
    dfs(root, prev);

    if(pFirst && pSecond) std::swap(pFirst->val, pSecond->val);

}

void dfs(TreeNode *root, TreeNode *&prev)
{
    if(root == nullptr) return;

    dfs(root->left, prev);

    if(prev && prev->val >= root->val) {
        if(pFirst == nullptr) pFirst = prev;
        pSecond = root;
    }

    prev = root;

    dfs(root->right, prev);

}


TreeNode* sortedArrayToBST(std::vector<int> &nums)
{
    return dfs(nums, 0, nums.size() - 1);
}

TreeNode* dfs(std::vector<int> &nums, int left, int right)
{
    if(left > right) return nullptr;

    int mid = left + ((righ-left) >> 1);

    TreeNode *root = new TreeNode(nums[mid]);

    root->left = dfs(nums, left, mid - 1);
    root->right = dfs(nums, mid + 1, right);

    return root;
}

TreeNode* sortedListToBST(ListNode *head)
{
    if(head == nullptr) return nullptr;

    return dfs(head, nullptr);
}

TreeNode* dfs(TreeNode *head, TreeNode *tail)
{
    if(head == tail) return nullptr;

    ListNode *mid = head, *fast = head;
    while(fast != tail && fast->next != tail) {
        mid = mid->next;
        fast = fast->next->next;
    }

    TreeNode *root = new TreeNode(mid->val);

    root->left = dfs(head, mid);
    root->right = dfs(mid->next, tail);

    return root;
}


std::string tictactoe(std::vector<std::vector<int>> &moves)
{
    std::vector<int> aRow(3,0), aCol(3,0), bRow(3,0), bCol(3,0);
    int aD1, aD2, bD1, bD2;

    for(int i = 0; i < moves.size(); i++)
    {
        int r = moves[i][0], c = moves[i][1];
        if(i%2 == 0) {
            if(++aRow[r] == 3 || ++aCol[c] == 3 || (r == c && ++aD1 == 3) || (r + c == 2 && ++aD2 == 3)) return "A";
        }
        else {
            if(++bRow[r] == 3 || ++bCol[c] == 3 || (r == c && ++bD1 == 3) || (r + c == 2 && ++bD2 == 3)) return "B";
        }
    }

    return moves.size() == 9 ? "Draw" : "Pending";
}


class TrieNode
{
public:
    TrieNode *childNode[26];
    bool isVal;

    TrieNode() : isVal(false) {
        memset(childNode, 0, sizeof(childNode));
    }

    ~TrieNode() {
        for(int i = 0; i < 26; i++) {
            delete childNode[i];
        }
    }
};


class Trie
{
private:
    TrieNode *root;

public:
    TrieNode(): root(new TrieNode) {}

    void insert(std::string word)
    {
        TrieNode *pNode = root;
        for(const char &c : word) {
            if(pNode->childNode[c-'a'] == nullptr) {
                pNode->childNode[c-'a'] = new TrieNode;
            }
            pNode = pNode->childNode[c-'a'];
        }

        pNode->val = true;
    }

    bool search(std::string word)
    {
        TrieNode *pNode = root;
        for(const char &c : word) {
            pNode = pNode->childNode[c-'a'];
            if(pNode == nullptr) return false;
        }

        return pNode->val;
    }

    bool startsWith(std::string prefix)
    {
        TrieNode *pNode = root;
        for(const char &c : word) {
            pNode = pNode->childNode[c-'a'];
            if(pNode == nullptr) return false;
        }

        return true;
    }

};



class WordDictionary 
{
private:
    std::unordered_map<int,std::vector<std::string>> mp;

    bool Equal(const std::string &s, const std::string &t) {
        for(int i = 0; i < t.size(); i++) {
            if(t[i] == '.') continue;
            if(s[i] != t[i]) return false;
        }

        return true;
    }

public:
    WordDictionary() {}

    void addWord(std::string word) {
        mp[word.size()].push_back(word);
    }

    bool search(std::string word) {
        for(const std::string &str : mp[word.size()]) {
            if(Equal(str, word)) return true;
        }

        return false;
    }

};



class TrieNode {
public:
    TrieNode *childNode[26];
    std::string word;           //记录以该字符结尾的字符串

    TrieNode() {
        memset(childNode, 0, sizeof(childNode));
    }

    ~TrieNode() {
        for(int i = 0; i < 26; i++) {
            delete childNode[i];
        }
    }

};


TrieNode* buildTree(std::vector<std::string> &words)
{
    TrieNode *root = new TrieNode;

    for(const std::string &word : words)
    {
        TrieNode *pNode = root;
        for(const char &c : word) {
            if(pNode->childNode[c-'a'] == nullptr) {
                pNode->childNode[c-'a'] = new TrieNode;
            }
            pNode = pNode->childNode[c-'a'];
        }

        pNode->word = word;
    }

    return root;
}


std::vector<std::string> findWords(std::vector<std::vector<char>> &board, std::vector<std::string> &words)
{
    std::vector<std::string> res;

    int m = board.size(), n = board[0].size();

    TrieNode *root = new TrieNode(words);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            dfs(board, i, j, root, res);
        }
    }

    return res;
}

void dfs(std::vector<std::vector<char>> &board, int i, int j, TrieNode *root, std::vector<std::string> &res)
{
    int m = board.size(), n = board[0].size();

    if(i < 0 || i >= m || j < 0 || j >= n) return;

    char c = board[i][j];
    if(c == '#' || root->childNode[c-'a'] == nullptr) return ;

    root = root->childNode[c-'a'];

    if(!(root->word.empty())) {
        res.push_back(word);
        root->word.clear();
    }

    board[i][j] = '#';

    dfs(board, i, j + 1, root, res);
    dfs(board, i, j - 1, root, res);
    dfs(board, i + 1, j, root, res);
    dfs(board, i - 1, j, root, res);

    board[i][j] = c;
}



struct TrieNode 
{
    TrieNode *childNode[26];
    std::vector<int> wordIndex;

    TrieNode() {
        memset(childNode, 0, sizeof(childNode));
    }

    ~TrieNode() {
        for(int i = 0; i < 26; i++) {
            delete childNode[i];
        }
    }

    void add(const std::string &word, int begin, int index)
    {
        wordIndex.push_back(index);
        if(begin < word.size()) {
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

        if(childNode[prefix[begin]-'a'] == nullptr) return {};
        else return childNode[prefix[begin]-'a']->find(prefix, begin + 1);
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
        std::vector<int> forwardMatch = forwardTrie->find(prefix, 0)

        reverse(suffix.begin(), suffix.end());
        std::vector<int> backwardMatch = backwardTree->find(suffix, 0);

        auto fIter = forwardMatch.rbegin(), bIter = backwardMatch.rbegin();

        while(fIter != forwardMatch.rend() && bIter != backwardMatch.rend())
        {
            if(*fIter == *bIter) return *fIter;
            else if(*fIter > *bIter) fIter++;
            else bIter++;
        }

        return -1;
    }

};

int findMaxConsectiveOnes(std::vector<int> &nums)
{
    int left = 0, res = 0;
    
    for(int right = 0; right < nums.size(); right++)
    {
        if(nums[right] == 1) {
            int left = right;
            while(right < nums.size() && nums[right] == 1) right++;
            res = std::max(res, right - left);
        }
    }

    return res;
}



int findMaxConsectiveOnes(std::vector<int> &nums)
{
    int left = 0, right = 0;
    int res = 0;

    for(const int &n : nums)
    {
        if(n == 1) right++;
        else {
            left = right + 1;
            right = 0;
        }
        res = std::max(res, left + right);
    }

    return res;
}


int main() {
    std::vector<int> nums = {1,1,0,1,1,1};

    std::cout << findMaxConsectiveOnes(nums) << std::endl;

    return 0;
}

int longestOnes(std::vector<int> &nums, int k)
{
    int count = 0, maxLen = 0;
    int left = 0;

    for(int right = 0; right < nums.size(); right++)
    {
        if(nums[right] == 1) count++;

        while(count > k) {
            if(nums[left] == 1) count--;
            left++;
        }

        maxLen = std::max(maxLen, right - left + 1);
    }

    return maxLen;
}


int countPrimes(int n)
{
    std::vector<int> prime(n + 1, 1);

    int count = n-2;

    for(int i = 2; i*i < n; i++)
    {
        if(prime[i]) {
            for(int j = i*i; j < n; j += i) {
                if(prime[j]) {
                    count--;
                    prime[j] = 0;
                }
            }
        }
    }

    return count;
}




int main() {
    int count = 0;
    count += 0.5;

    std::cout << sizeof(count) << std::endl;

    return 0;
}

bool isHappy(int n)
{
    std::unordered_set<int> mySet;
    mySet.insert(n);

    while(n != 1)
    {
        int sum = 0;
        while(n) {
            sum += (int)pow(n%10, 2);
            n /= 10;
        }

        n = sum;

        if(mySet.count(n)) return false;

        mySet.insert(n);
    }

    return true;
}


std::unordered_map<Node*, Node*> mp;

Node* cloneGraph(Node* node)
{
    if(node == nullptr) return nullptr;

    if(mp.count(node)) return mp[node];

    mp[node] = new Node(node->val);

    for(auto &e : node->neighbors) {
        mp[node]->neighbors.push_back(cloneGraph(e));
    }

    return mp[node];
}



Node* copyRandomList(Node *head)
{
    if(head == nullptr) return nullptr;

    std::unordered_map<Node*, Node*> hash;

    Node *pNode = head;
    while(pNode) {
        hash[pNode] = new Node(pNode->val);
        pNode = pNode->next;
    }

    pNode = head;
    while(pNode)
    {
        if(pNode->next) hash[pNode]->next = hash[pNode->next];
        if(pNode->random) hash[pNode]->random = hash[pNode->random];
        pNode = pNode->next;
    }

    return hash[head];
}


Node* copyRandomList(Node *head)
{
    if(head == nullptr) return nullptr;

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
            cur->next->random = cur->random->next;
        }
        cur = cur->next->next;
    }

    //奇偶链表拆分
    cur = head;
    Node *pCopy = head->next, *pCopyHead = pCopy;

    while(pCopy && pCopy->next) {
        cur = cur->next = pCopy->next;
        pCopy = pCopy->next = cur->next;
    }
    cur->next = nullptr;

    return pCopyHead;
}



void allPaths(std::vector<std::vector<int>> &prere, int num);
void dfs(std::vector<std::vector<int>> &graph, int num, std::vector<int> &visited, int pos);

void topologySort(std::vector<std::vector<int>> &prere, int num);
void dfs(std::vector<std::vector<int>> &graph, int num, std::vector<int> &indegree, std::vector<int> &visited);


std::vector<int> path;
std::vector<std::vector<int>> res;

int main() {
    // std::vector<std::vector<int>> prere = {{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}};
    // int num = 4;
    std::vector<std::vector<int>> prere = {{1,2},{1,3},{2,4},{2,5},{3,4},{3,5},{4,6},{5,6}};
    int num = 6;

    topologySort(prere, num);

    for(auto &num : res) {
        for(auto &n : num) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

void allPaths(std::vector<std::vector<int>> &prere, int num)
{
    std::vector<std::vector<int>> graph(num + 1);

    //计算入度
    for(auto &e : prere) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    std::vector<int> visited(num + 1, 0);
    visited[1] = 1; 
    path.push_back(1);      //从节点1出发

    dfs(graph, num, visited, 1);

}

void dfs(std::vector<std::vector<int>> &graph, int num, std::vector<int> &visited, int pos)
{
    if(path.size() == num) {
        res.push_back(path);
        return;
    }

    for(const int &n : graph[pos])
    {
        if(!visited[n])
        {
            path.push_back(n);
            visited[n] = 1;

            dfs(graph, num, visited, n);

            path.pop_back();
            visited[n] = 0;
        }
    }

}


void topologySort(std::vector<std::vector<int>> &prere, int num)
{
    std::vector<std::vector<int>> graph(num + 1);
    std::vector<int> indegree(num + 1);

    for(auto &e : prere) {
        graph[e[0]].push_back(e[1]);
        indegree[e[1]]++;
    }

    std::vector<int> visited(num + 1, 0);

    dfs(graph, num, indegree, visited);

}


void dfs(std::vector<std::vector<int>> &graph, int num, std::vector<int> &indegree, std::vector<int> &visited)
{
    if(path.size() == num) {
        res.push_back(path);
    }

    for(int i = 1; i <= num; i++)
    {
        //该节点未遍历过,其入度为0,则将其加入到结果中
        if(!visited[i] && indegree[i] == 0)     
        {
            path.push_back(i);
            visited[i] = 1;
            for(const int &n : graph[i]) {
                indegree[n]--;
            }

            dfs(graph, num, indegree, visited);

            path.pop_back();
            visited[i] = 0;
            for(const int &n : graph[i]) {
                indegree[n]++;
            }
        }
    }

}


std::vector<int> findOrder(int num, std::vector<std::vector<int>> &prere)
{
    std::vector<std::vector<int>> graph(num);
    std::vector<int> degree(num);

    for(auto &e : prere) {
        graph[e[1]].push_back(e[0]);
        degree[e[0]]++;
    }

    std::queue<int> que;
    std::vector<int> res;

    for(int i = 0; i < num; i++) {
        if(degree[i] == 0) que.push(i);
    }

    while(!que.empty())
    {
        auto cur = que.front(); que.pop();
        res.push_back(cur);

        for(const int &n : graph[cur]) {
            if(--degree[n] == 0) que.push(n);
        }
    }

    return res.size() == num ? res : std::vector<int>();
}
>

void initMap(std::vector<std::vector<int>> &map);
void dijkstra();


struct Node {
    int id, len;
    Node(int m_id, int m_len) : id(m_id), len(m_len) {}

    bool operator<(const Node &demo) const {
        return len > demo.len;
    }
};

void dijkstra()
{
    std::vector<std::vector<int>> map(6, std::vector<int>(6,0));
    initMap(map);

    std::vector<int> visited(6, 0);
    std::vector<int> distance(6, INT_MAX);

    std::priority_queue<Node> pq;
    distance[0] = 0;
    pq.push(Node(0,0));

    while(!pq.empty())
    {
        Node tmp = pq.top(); pq.pop();
        int index = tmp.id;
        int len = tmp.len;
        visited[index] = 1;

        for(int i = 0; i < map[index].size(); i++)
        {
            if(map[index][i] > 0 && !visited[i])
            {
                Node newNode = Node(i, len + map[index][i]);
                if(distance[i] > newNode.len) {
                    distance[i] = newNode.len;
                    pq.push(newNode);
                }
            }
        }
    }

    for(const int &n : distance) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

}


void initMap(std::vector<std::vector<int>> &map)
{
    map[0][1] = 2;  map[0][2] = 3;  map[0][3] = 6;
    map[1][0] = 2;  map[1][4] = 4;  map[1][5] = 6;
    map[2][0] = 3;  map[2][3] = 2;
    map[3][0] = 6;  map[3][2] = 2;  map[3][4] = 1;  map[3][5] = 3;
    map[4][1] = 4;  map[4][3] = 1;
    map[5][1] = 6;  map[5][3] = 3; 
}


int main() {
    dijkstra();

    return 0;
}


class LRUCache
{
public:
    LRUCache(int capacity): size(capacity) {}

    int get(int key)
    {
        auto it = hash.find(key);
        if(it == hash.end()) {
            return -1;
        }

        cache.splice(cache.begin(), cache, it->second);

        return cache.front().second;
    }

    void put(int key, int value)
    {
        auto it = hash.find(key);
        if(it != hash.end()) {
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
            return;
        }

        // cache.insert(cache.begin(), std::make_pair(key,value));
        // cache.push_front(std::make_pair(key,value));
        cache.push_front({key, value});
        hash[key] = cache.begin();

        if(cache.size() > size) {
            hash.erase(cache.back().first);
            cache.pop_back();
        }

    }

private:
    std::list<std::pair<int,int>> cache;
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> hash;
    int size;
};



int maxProduct(std::vector<std::string> &words)
{
    std::vector<int> mask(words.size(), 0);
    int res = 0;

    for(int i = 0; i < words.size(); i++)
    {
        for(const char &c : words[i]) {
            mask[i] |= (1 << (c-'a'));
        }

        for(int j = 0; j < i; j++) {
            if((mask[i]&mask[j]) == 0) {
                res = std::max(res, (int)(words[i].size() * words[j].size()));
            }
        }
    }

    return res;
}

int main() {
    std::string str = "hello";
    std::unordered_set<char> mySet(str.begin(), str.end());

    // if(mySet.count('l')) std::cout << "hi" << std::endl;

    // std::vector<std::bitset<32>> dp = {std::bitset<32>()};
    std::vector<std::bitset<32>> dp;

    return 0;
}


//Leetcode第1239题: 将字符串数组中的字符串组合成一个不含有重复字符的最长字符串,求这个最长字符串的长度

//思路一:DFS

int maxLength(std::vector<std::string> &arr)
{
    return dfs(arr, "", 0);
}

int dfs(std::vector<std::string> &arr, std::string str, int pos)
{
    //利用集合来判断字符串str中是否存在重复字符
    std::unordered_set<char> mySet(str.begin(), str.end());

    if(str.size() != mySet.size()) return 0;

    int res = str.size();

    for(int i = pos; i < arr.size(); i++) {
        res = std::max(res, str + arr[i], i + 1);
    }

    return res;
}


//思路二:利用Bitset(比较难理解)

int maxLength(std::vector<std::string> &arr)
{
    std::vector<std::bitset<26>> dp = { std::bitset<26>() };        //这个初始的第一个bitset一定要添加
    int res = 0;

    for(auto &s : arr)
    {
        std::bitset<26> a;
        for(const char &c : s) a.set(c-'a');
        
        if(a.count() < s.size()) continue;  //含有重复字符

        for(int i = dp.size() - 1; i >= 0; i--)
        {
            std::bitset c = dp[i];
            if((a & c).any()) continue;
            dp.push_back(a | c);
            res = std::max(res, (int)(c.count() + s.size()))
        }
    }

    return res;
}


int compress(std::vector<char> &chars)
{
    if(chars.empty()) return 0;

    int left = 0;

    for(int right = 0; right < chars.size(); )
    {
        chars[left] = chars[right];
        int count = 0;
        while(right < chars.size() && chars[right] == chars[left]) {
            count++;
            right++;
        }

        if(count != 1) {
            std::string num = std::to_string(count);
            for(const char &c : num) {
                chars[++left] = c;
            }
            left++;
        }
        else if(count == 1) left++;
    }

    return left;
}
/*
std::string compressString(std::string s)
{
    if(s.empty()) return "";

    std::string res;
    int left = 0;

    for(int right = 0; right < s.size(); right++)
    {
        if(s[right] == s[left]) continue;
        else {
            int count = right - left;
            if(count == 1) res += s[left];
            else res += s[left] + std::to_string(count);

            left = right;
        }
    }

    if(s.size() - left == 1) {
        res += s[left];
    }
    else res += s[left] + std::to_string(s.size() - left);

    return res;
}
*/
/*
std::string compressString(std::string s);


int main() {
    std::cout << compressString("aabbbb") << std::endl;

    return 0;
}


std::string compressString(std::string s)
{
    if(s.empty()) return "";

    std::string res;
    int left = 0;

    for(int right = 0; right < s.size();)
    {
        while(right < s.size() && s[right] == s[left]) right++;

        int count = right - left;
        if(count == 1) res += s[left];
        else res += s[left] + std::to_string(count);

        left = right;
    }

    return res;
}


std::string decodeString(std::string s)
{
    std::string res;

    for(const char &c : s)
    {
        if(isalnum(c) || c == '[') {
            res += c;
        }
        else if(c == ']'){
            std::string tmp;
            while(res.back() != '[') {
                tmp += res.back();
                res.pop_back();
            }
            res.pop_back();

            std::string num;
            while(isdigit(res.back())) {
                num += res.back();
                res.pop_back();
            }

            reverse(tmp.begin(), tmp.end());
            reverse(num.begin(), num.end());

            for(int i = 0; i < std::stoi(num); i++) {
                res.push_back(tmp);
            }
        }
    }

    return res;
}


std::vector<std::string> res;

std::vector<std::string> removeInvalidParentheses(std::string s)
{
    int left = 0, right = 0;

    for(const char &c : s) {
        if(c == '(') left++;
        else if(c == ')') {
            if(left > 0) left--;
            else right++;
        }
    }

    dfs(s, left, right, 0);
}


void dfs(std::string s, int left, int right, int pos)
{
    if(left < 0 || right < 0) return;

    if(left == 0 && right == 0) {
        if(isValid(s)) {
            res.push_back(s);
            return;
        }
    }

    for(int i = pos; i < s.size(); i++)
    {
        if(i > pos && s[i] == s[i-1]) continue;

        if(s[i] == '(') {
            dfs(s.substr(0,i) + s.substr(i+1), left - 1, right, i);
        }
        else if(s[i] == ')') {
            dfs(s.substr(0,i) + s.substr(i+1), left, right - 1, i);
        }
    }

}

bool isValid(const std::string &s)
{
    int count = 0;

    for(const char &c : s)
    {
        if(c == '(') count++;
        else if(c == ')') {
            if(count > 0) count--;
            else return false;
        }
    }

    return count == 0;
}


std::vector<std::string> res;

std::vector<std::string> generateParenthesis(int n)
{
    std::string s;
    dfs(n, n, s);

    return res;
}

void dfs(int left, int right, std::string &s)
{
    if(left > right) return;

    if(left < 0 || right < 0) return ;

    if(left == 0 && right == 0) {
        res.push_back(s);
        return;
    }

    s.push_back('(');
    dfs(left - 1, right, s);
    s.pop_back();

    s.push_back(')');
    dfs(left, right - 1, s);
    s.pop_back();

}

SYN = 1, Seq = x
SYN = 1, ACK = 1, Seq = y, ack = x + 1
ACK = 1, Seq = x + 1, ack = y + 1



struct Node {
    int id, len;          //节点编号以及到达该节点的距离
    Node(int m_id, int m_len): id(m_id), len(m_len) {}

    bool operator<(const Node &demo) const {    //注意重载 "< > + -" 这个const关键字一定要加,否则编译器报错,不加的话const对象无法调用
        return len > demo.len;                  //而且下面Node会被装进优先队列,优先队列实现是大顶堆,默认里面的元素是不允许修改的,都是const成员
    }
};


int main() {
    int n = 4;
    // std::cin >> n;

    std::vector<std::vector<int>> map(n, std::vector<int>(n, 0));  //用map来记录路径的权值
    // initMap(map);   //初始化map临接矩阵

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         std::cin >> map[i][j];
    //     }
    // }

    map = {{0,30,6,4}, {30,0,5,10}, {6,5,0,20}, {4,10,20,0}};


    std::vector<int> visited(n, 0);           //判断这个点是否已经确定
    std::vector<int> distance(n, INT_MAX);      //记录源节点到其他每个节点的距离

    std::priority_queue<Node> pq;
    distance[0] = 0;                            //从0这个点开始(0为起始点，距离当然为0)
    pq.push(Node(0, 0));

    while(!pq.empty())
    {
        Node tmp = pq.top(); pq.pop();
        int index = tmp.id;              //节点编号
        int len = tmp.len;               //节点长度
        visited[index] = 1;              //抛出的点已经确定

        //1.遍历这个点的邻居
        for(int i = 0; i < map[index].size(); i++)
        {
            //2.如果这个点的邻居没有被访问过
            if(map[index][i] > 0 && !visited[i]) {
                
                //3.计算(更新)到这个邻居点的距离,如果小于之前的距离则更新该点距离
                Node newNode = Node(i, len + map[index][i]);
                if(distance[i] > newNode.len) {             //只有0这个点distance是0,其他点的初始距离都是无穷大
                    distance[i] = newNode.len;              //找到离第i点最近的点
                    pq.push(newNode);
                }
            }
        }
    }


    for(int i = 0; i < n; i++) {
        std::cout << distance[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}


std::string breakPalindrome(std::string str)
{
    int n = str.size()/2;

    int left = 0, right = str.size() - 1;
    int count = 1;

    while(left < right)
    {
        if(count++ == n) {
            if(str[left] == 'a') str[right] = 'b';
            else str[left] = 'a';
        }

        if(str[left] == 'a') {
            left++;
            right--;
        }
        else str[left] = 'a';
    }

    return str;
}


std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
        return a[0] < b[0];
    });

    std::vector<std::vector<int>> res;
    res.push_back(intervals.front());

    for(int i = 1; i < intervals.size(); i++)
    {
        if(res.back()[1] >= intervals[i][0]) {
            res.back()[1] = std::max(res.back()[1], intervals[i][1]);
        }
        else {
            res.push_back(intervals[i]);
        }
    }

    return res;
}


int eraseOverlapInterval(std::vector<std::vector<int>> &intervals)
{
    if(intervals.empty()) return 0;

    sort(intervals.begin(), intervals.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
        return a[1] < b[1];
    });

    int end = intervals[0][1];
    int count = 0;

    for(int i = 1; i < intervals.size(); i++)
    {
        if(end > intervals[i][0]) count++;
        else end = intervals[i][1];
    }

    return count;
}

int findMinArrowShots(std::vector<std::vector<int>> &points)
{
    if(points.empty()) return 0;

    sort(points.begin(), points.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
        return a[1] < b[1];
    });

    int count = 1;
    int end = points[0][1];

    for(int i = 1; i < points.size(); i++)
    {
        if(end < points[i][0]) {
            count++;
            end = points[i][1];
        }
    }

    return count;
}


int minMeetingRooms(std::vector<std::vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    std::prioriry_queue<int, std::vector<int>, std::greater<int>> pq;
    pq.push(intervals[0][1]);

    int count = 0;

    for(int i = 1; i < intervals.size(); i++) {
        if(pq.empty() || intervals[i][0] < pq.top()) count++;
        else pq.pop();
        pq.push(intervals[i][1]);
    }

    return count;
}


NumArray(std::vector<int> &nums)
{
    int n = nums.size();

    sum = std::vector<int>(n+1, 0);
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i-1] + nums[i-1];
    }

}

int sumRange(int left, int right)
{
    return sum[right+1] - sum[left];
}


std::vector<std::vector<int>> integral;

NumMatrix(std::vector<std::vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    
    integral = std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1));

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            integral[i][j] = matrix[i-1][j-1] + integral[i-1][j] + integral[i][j-1] - matrix[i-1][j-1];
        }
    }

}

int sumRegion(int row1, int col1, int row2, int col2)
{
    return integral[row2+1][col2+1] - integral[row2+1][col1] - integral[row1][col2+1] + integral[row1][col1];
}

class Base {
public:
    Base(): b(1) {}
    virtual void print() { std::cout << b << std::endl; }
    int b;
};

class Son : public Base {
public:
    Son() : s(2) {}
    void print() { std::cout << s << std::endl; }
    int s;
};


class A { int a; };
class B { int b; };
class C : public B { int c; };

int main() {
    A *a = new A;
    B *b = new B;
    // C *p = (C*)a;
    C *p = static_cast<C*>(a);

    // Base *b = new Son;
    // Son *s = static_cast<Son*>(b);
    // s->print();


    // Base *b = new Son;
    // Son *s = dynamic_cast<Son*>(b);

    // if(s == nullptr) {
    //     std::cout << "Fail" << std::endl;
    // }

    // double x = 1.2;
    // int y = static_cast<int>(x);

    // void *p = &x;
    // double *ptr = static_cast<double*>(p);

    // std::cout << *ptr << std::endl;

    // const int val = 12;
    // const int *p = &val;

    // int *ptr = const_cast<int*>(p);

    // std::cout << *ptr << std::endl;

    // int i = 2;
    // float *p = reinterpret_cast<float*>(&i);

    // std::cout << *p << std::endl;

    return 0;
}


#include <memory>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <queue>
#include <climits>
#include <unordered_set>
#include <bitset>



// #include <iostream>
#include <thread>
#include <mutex>

volatile int val = 0;
std::mutex mut;

void increment()
{
    for(int i = 0; i < 100; i++) {
        mut.lock();
        val++;
        mut.unlock();
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << val << std::endl;

    return 0;
}
*/


/*
    旅行商问题
*/

/*
#include <iostream>
#include <vector>

const int INF = 1e9;

int main() {
    int n = 5;
    int m = 1 << (n-1);
    int dp[n][m];

    int g[n][n] = {{0, 3, INF, 8, 9},
                   {3, 0, 3, 10, 5},
                   {INF, 3, 0, 4, 3},
                   {8, 10, 4, 0, 20},
                   {9, 5, 3, 20, 0}};

    //初始化dp[i][0]
    for(int i = 0; i < n; i++) {
        dp[i][0] = g[i][0];
    }


    //求解dp[i][j],先更新列再更新行
    for(int j = 1; j < m; j++)
    {
        for(int i = 0; i < n; i++)
        {
            dp[i][j] = INF;
            
            //如果集合j(或者状态j)中包含节点i,则不符合条件退出
            if(((j>>(i-1))&1) == 1) continue;

            //枚举集合j中的节点
            for(int k = 1; k < n; k++)
            {
                //如果集合中没有节点k,则退出
                if(((j>>(k-1))&1) == 0) continue;

                //使用异或运算去除掉集合j中的节点k
                if(dp[i][j] > g[i][k] + dp[k][j^(1<<(k-1))]) {
                    dp[i][j] = g[i][k] + dp[k][j^(1<<(k-1))];
                }
            }
        }
    }

    // std::cout << dp[0][m-1] << std::endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}



std::vector<int> res;

std::vector<int> rightSideView(TreeNode *root)
{
    if(root == nullptr) return res;

    dfs(root, 1);

    return res;
}

void dfs(TreeNode *root, int level)
{
    if(root == nullptr) return;

    if(res.size() < level) res.push_back(root->val);

    dfs(root->right, level + 1);
    dfs(root->left, level + 1);

}

int tribonacci(int n)
{
    int first = 0, second = 1, thrid = 1;

    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;

    int cur;
    for(int i = 3; i <= n; i++)
    {
        cur = first + second + thrid;
        first = second;
        second = thrid;
        thrid = cur;
    }

    return cur;
}

*/


#include <iostream>
#include <vector>
#include <climits>

/*
double getUpMedian(std::vector<int> &nums1, std::vector<int> &nums2)
{
    int m = nums1.size(), n = nums2.size();
    if(m > n) return getUpMedian(nums2, nums1);

    int left = 0, right = m;

    while(left <= right)
    {
        int i = left + ((right-left) >> 1);
        int j = (m + n + 1)/2 - i;

        int leftMaxX = (i == 0 ? INT_MIN : nums1[i-1]);
        int rightMinX = (i == m ? INT_MAX : nums1[i]);

        int leftMaxY = (j == 0 ? INT_MIN : nums2[j-1]);
        int rightMinY = (j == n ? INT_MAX : nums2[j]);

        if(leftMaxX <= rightMinY && leftMaxY <= rightMinX) {
            return std::max(leftMaxX, leftMaxY);                //无论奇数还是偶数返回左侧部分的最大值即可
        }
        else if(leftMaxX > rightMinY) {
            right = i - 1;
        }
        else left = i + 1;
    }

    return 0;
}
*/


int getUpMedian(std::vector<int> &nums1, int s1, int e1, std::vector<int> &nums2, int s2, int e2)
{
    int left = s1, right = e1;

    int m = e1 - s1 + 1, n = e2 - s2 + 1;

    while(left <= right)
    {
        int i = left + ((right - left) >> 1);
        int j = s2 + (m + n + 1)/2 - i;

        int leftMaxX = (i == 0 ? INT_MIN : nums1[i-1]);
        int rightMinX = (i == m ? INT_MAX : nums1[i]);

        int leftMaxY = (j == 0 ? INT_MIN : nums2[j-1]);
        int rightMinY = (j == n ? INT_MAX : nums2[j]);

        if(leftMaxX <= rightMinY && leftMaxY <= rightMinX) {
            return std::max(leftMaxX, leftMaxY);                //无论奇数还是偶数返回左侧部分的最大值即可
        }
        else if(leftMaxX > rightMinY) {
            right = i - 1;
        }
        else left = i + 1;
    }

    return 0;
}


int getUpMedian(std::vector<int> &nums1, int s1, int e1, std::vector<int> &nums2, int s2, int e2)
{
    int mid1 = 0, mid2 = 0;
    int offset = 0;

    while(s1 < e1)
    {
        mid1 = (s1 + e1) / 2;
        mid2 = (s2 + e2) / 2;
        offset = ((e1-s1+1)&1)^1;       //元素个数为奇数,则偏离为0;为偶数则偏移为1

        if(nums1[mid1] > nums2[mid2]) {
            e1 = mid1;
            s2 = mid2 + offset;
        }
        else if(nums1[mid1] < nums2[mid2]) {
            s1 = mid1 + offset;
            e2 = mid2;
        }
        else return nums1[mid1];
    }

    return std::min(nums1[s1], nums2[s2]);
}



int findKthNum(std::vector<int> &nums1, std::vector<int> &nums2, int k)
{
    int m = nums1.size(), n = nums2.size();

    if(k < 1 || k > (m+n)) return -1;       //k值不合法

    //始终保持nums1的元素个数最小
    if(nums1.size() > nums2.size()) return findKthNum(nums2, nums1, k);

    //1.如果k<=m,则在两个数组中各选取k个数取上中位数即可
    if(k <= m) {
        return getUpMedian(nums1, 0, k-1, nums2, 0, k-1);
    }

    //2.k>n
    if(k > n)
    {
        if(nums1[k-n-1] > nums2[n-1]) {
            return nums1[k-n-1];
        }
        if(nums2[k-m-1] > nums1[m-1]) {
            return nums2[k-m-1];
        }

        return getUpMedian(nums1, k-n, m-1, nums2, k-m, n-1);
    }

    //3.m<k<=n
    if(nums2[k-m-1] >= nums1[m-1]) {
        return nums2[k-m-1];
    }

    return getUpMedian(nums1, 0, m - 1, nums2, k - m, k - 1);
}


int main() {
    std::vector<int> nums1 = {10,30,60}, nums2 = {20,40,50};

    // std::cout << getUpMedian(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1) << std::endl;

    std::cout << findKthNum(nums1, nums2, 4) << std::endl;

    return 0;
}



int shortestPath(std::vector<std::vector<int>> &grid, int k)
{
    int m = grid.size(), n = grid[0].size();

    //存储在当前位置可以消除的最大障碍数
    std::vector<std::vector<int>> visited(m, std::vector<int>(n, -1));

    std::queue<std::vector<int>> que;

    que.push({0, 0, 0, k});

    while(!que.empty())
    {
        auto cur = que.front(); que.pop();

        int x = cur[0], y = cur[1];

        if(x < 0 || x >= m || y < 0 || y >= n) continue;

        if(x == m-1 && y == n-1) return cur[2];

        if(grid[x][y] == 1) {
            if(cur[3] > 0) cur[3]--;    //遇到了障碍,就将其减1
            else continue;              //如果当前点没有值可供消除了,则继续下一个点判断
        }

        if(visited[x][y] != -1 && visited[x][y] >= cur[3]) continue;

        visited[x][y] = cur[3];

        que.push({x + 1, y, cur[2] + 1, cur[3]});
        que.push({x - 1, y, cur[2] + 1, cur[3]});
        que.push({x, y + 1, cur[2] + 1, cur[3]});
        que.push({x, y - 1, cur[2] + 1, cur[3]});
    }

    return -1;
}


int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList)
{
    std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());

    if(!wordSet.count(endWord)) return 0;
    if(beginWord == endWord) return 1;

    std::queue<std::string> que;
    que.push(beginWord);
    wordSet.erase(beginWord);

    int steps = 1;

    while(!que.empty())
    {
        for(int size = que.size(); size > 0; size--)
        {
            std::string cur = que.front(); que.pop();

            for(char &c : cur)
            {
                char tmp = c;
                for(int k = 0; k < 26; k++) {
                    c = 'a' + k;
                    if(wordSet.count(cur)) {
                        if(cur == endWord) return steps + 1;
                        que.push(cur);
                        wordSet.erase(cur);
                    }
                }

                c = tmp;
            }

        }

        steps++;
    }

    return 0;
}


int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList)
{
    std::unordered_set<std::string> beginSet, endSet;
    std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());

    if(beginWord == endWord) return 1;
    if(!wordSet.count(endWord)) return 0;

    beginSet.insert(beginWord);
    endSet.insert(endWord);

    wordSet.erase(beginWord);
    wordSet.erase(endWord);

    int steps = 1;

    while(!beginSet.empty() && !endSet.empty())
    {
        if(beginSet.size() > endSet.size()) std::swap(beginSet, endSet);

        std::unordered_set<std::string> tmp;

        for(auto &cur : beginSet)
        {
            std::string word = cur;

            for(char &c : word)
            {
                char ch = c;
                for(int k = 0; k < 26; k++) {
                    c = 'a' + k;

                    if(endSet.count(word)) return steps + 1;

                    if(wordSet.count(word)) {
                        tmp.insert(word);
                        wordSet.erase(word);
                    }
                }
                c = ch;
            }
        }

        beginSet = tmp;
        steps++;
    }

    return 0;
}

std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();

    std::queue<std::pair<int,int>> que;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == 0) {
                que.push({i,j});
            }
            else mat[i][j] = INT_MAX;
        }
    }

    std::vector<int> dir = {-1, 0, 1, 0, -1};

    while(!que.empty())
    {
        auto cur = que.front(); que.pop();

        for(int k = 0; k < dir.size() - 1; k++) {
            int x = cur.first + dir[k], y = cur.second + dir[k+1];
            if(x >= 0 && x < m && y >= 0 && y < n && mat[x][y] > mat[cur.first][cur.second] + 1) {
                que.push({x, y});
                mat[x][y] = mat[cur.first][cur.second] + 1;
            }
        }
    }

    return mat;
}

std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, m*n));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == 0) dp[i][j] = 0;
            else {
                if(i > 0) dp[i][j] = std::min(dp[i][j], dp[i-1][j] + 1);
                if(j > 0) dp[i][j] = std::min(dp[i][j], dp[i][j-1] + 1);
            }
        }
    }

    for(int i = m-1; i >= 0; i--) {
        for(int j = n-1; j >= 0; j--) {
            if(mat[i][j]) {
                if(i < m-1) dp[i][j] = std::min(dp[i][j], dp[i+1][j] + 1);
                if(j < n-1) dp[i][j] = std::min(dp[i][j], dp[i][j+1] + 1);
            }
        }
    }

    return dp;
}