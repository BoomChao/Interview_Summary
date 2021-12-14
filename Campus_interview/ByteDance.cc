
/*
    找到数组中第一个不重复的数
*/

//思路：用哈希存储每个元素出现的次数即可，找到只出现一次的元素

int firstDistinctNum(std::vector<int> &nums)
{
    std::unordered_map<int, int> hash;

    for(const int &n : nums) {
        hash[n]++;
    }

    for(const int &n : nums) {
        if(hash[n] == 1) return n;
    }

    return -1;
}



/*
    字符串翻转 "I love you"->"you love I"(相邻单词以单个空格间隔)
*/

void reverseStr(std::string &str)
{
    if(str.size() <= 1) return ;

    int left = 0;

    for(int right = 0; right < str.size(); right++)
    {
        if(str[right] == ' ') {
            reverse(str.begin() + left, str.begin() + right);   //注意:这里翻转的是[left, right)范围内的字符,右边是开区间
            left = right + 1;
        }
    }

    reverse(str.begin(), str.end());

}

// 或者这样写也可以

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

    //最后right = s.size() 单独拿出来
    reverse(s.begin() + left, s.begin() + right);

    reverse(s.begin(), s.end());
}



//注意:上面如果是单词之间存在多个空格,要求翻转后的单词每个间隔一个空格
//参考Leetcode第151题
//使用字符串流处理

std::string reverseWords(std:string s)
{
    std::istringstream in(s);
    std::string out, res;

    while(in >> out) {
        reverse(out.begin(), out.end());
        res += out + " ";
    }

    res.pop_back();
    reverse(res.begin(), res.end());

    return res;
}



/*
    链表,奇数位递增,偶数位递减,从小到大排序该链表
*/

//思路:1.先按奇偶位置分成两个个链表 (Leetcode第328题)
//2.将偶数位链表逆序    (Leetcode第206题)    
//3.合并两个链表        (Leetcode第21题)

ListNode *sortOddAndEvenList(ListNode *head)
{
    if(head == nullptr) return head;

    //分割两个链表
    ListNode *pOdd = head, pEven = head->next;
    ListNode *pOddHead = pOdd, pEvenHead = pEven;

    while(pEven && pEven->next) {
        pOdd = pOdd->next = pEven->next;
        pEven = pEven->next = pOdd->next;
    }

    pOdd->next = nullptr;

    //翻转偶数位链表
    pEvenHead = reverList(pEvenHead);

    //合并两个链表
    head = mergeTwoList(pOddHead, pEvenHead);

    return head;
}

//翻转链表
ListNode *reverList(ListNode *head)
{
    ListNode *prev = nullptr;
    while(head)
    {
        ListNode *pNext = head->next;
        head->next = prev;
        prev = head;
        head = pNext;
    }

    return prev;
}


//合并两个链表(递归写法)
ListNode* mergeTwoList(ListNode *l1, ListNode *l2)
{
    if(l1 == nullptr) return l2;
    else if(l2 == nullptr) return l1;

    if(l1->val < l2->val) {
        l1->next = mergeTwoList(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoList(l1, l2->next);
        return l2;
    }

}

//迭代写法
ListNode* mergeTwoList(ListNode *l1, ListNode *l2)
{
    ListNode *base = new ListNode(-1);
    ListNode *node = base;

    while(l1 && l2)
    {
        if(l1->val < l2->val) {
            node->next = l1;
            l1 = l1->next;
        }
        else {
            node->next = l2;
            l2 = l2->next;
        }
        node = node->next;
    }

    node->next = l1 ? l1 : l2;

    return base->next;
}


/*
    给定一条长度为L的线段,除了头和尾两个点之外,上面还有n个整数点,需要在上面再放k个新的点,使得相邻的两个点之间的最大距离最小,求这个最小的距离
*/

//思路:二分

int main() {
    int L, n, k;
    std::cin >> L >> n >> k;

    std::vector<int> nums(n + 2, 0);
    nums[0] = 0;
    for(int i = 1; i <= n; i++) {
        std::cin >> nums[i];
    }
    nums[n+1] = L;

    //最短距离为1,最大距离就为L
    int left = 1, right = L;
    while(left <= right)
    {
        int mid = left + ((right-left) >> 1);
        int count = 0;  //计算每个相连的点之间的长度<=mid 需要插入几个点
        for(int i = 1; i < n-2; i++) {
            count += (nums[i] - nums[i-1] - 1)/mid;     //注意:这里是需要再减去1,因为两点长度恰为mid不需要插入点
        }

        //要插入的点太多,则说明m太小
        if(count > k) {
            left = mid + 1;
        }
        else if(count <= k) {   //要插入的节点比要求的k小或者等于k,则尝试减小mid(减小距离)
            right = mid - 1;
        }
    }

    std::cout << left << std::endl;

    return 0;
}




/*
    给定一个字符串,对该字符串进行删除操作,保留k个字符且相对位置不变,使得字典序最小
*/

//单调栈

//维持一个单调递增的字符串res,遍历原来字符串,如果当前字符小于res.back()且还没删够,则弹出res末尾字符
//如果当前字符大于res末尾字符,则直接将其加入到res中

std::string KeepKChar(std::string str, int k)
{
    if(k <= 0 || str.size() <= k) return str;
    
    k = str.size() - k;     //保留k个字符就是删除n-k个字符

    for(const char &c : str)
    {
        if(!res.empty() && c < res.back() && k) {
            res.pop_back();
            k--;
        }

        res.push_back(c);
    }

    return res;
}



/*
    返回所有和为k的连续子数组的下标
    //题目出的非常好
*/

//hash[sum]存储的是所有和为sum的子数组的下标
//但是如果和sum==k,这时少了从头遍历到sum的子数组

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



/*
    有一个环上有10个点,编号从0-9,问从0点出发,每步可以顺时针到下一个点,也可以逆时针到下一个点,问经过n步到达点k有多少种方法 
*/

// dp[i][j]表示前i步到达j点的方法数,
// 则 dp[i][j] = dp[i-1]][(j-1+n)%n] + dp[i-1][(j+1)%n]
// base case i = 0, dp[0][0] = 1, 代表0步到达0点方法数是1

int GetSteps(int k)
{
    if(k <= 1) return 0;

    if(k&1) return 0;   //因为一来一回需要两次,所以k为奇数则不能到达原点

    int n = 10; //10个点

    std::vector<std::vector<int>> dp(k+1, std::vector<int>(n, 0));
    dp[0][0] = 1;   

    for(int i = 1; i <= k; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = dp[i-1][(j-1+n)%n] + dp[i-1][(j+1)%n];
        }
    }

    return dp[k][0];
}



/*
    求数组中第一个不连续的数
    如：数组为{8,1,4,5,2,7}, 排序后为{1,2,4,5,7,8} 所以第一个不连续的数是4
*/

//思路:存入有序集合中,从集合第一个元素开始递增查找,直到找到第一个不在集合中的元素
//在集合中找到 >= 该元素的第一个元素即可

int firstNotSuccesiveNum(std::vector<int> &nums)
{
    std::set<int> mySet(nums.begin(), nums.end());

    int x = *mySet.begin();

    while(mySet.count(x)) {
        x++;
    }

    auto res = mySet.lower_bound(x);        //可能数组中的数都连续
    if(res == mySet.end()) return -1;

    return *res;
}


/*
    有N个窗口，给定每个窗口处理一个人所需的时间，求M个人都处理完的最短时间
    如：3个窗口，2个人, 窗口处理时间 {2,2,5}, 最终处理完最短时间是2,这两个人分别分配在前两个最小的窗口
    如：2个窗口，3个人，窗口处理时间 {2,5}, 第一个人和第二个人放在第一个窗口，第三个人放在第2个窗口，处理时间为5
*/

//思路：利用堆
//建立一个最小堆，每到来一个人取堆顶元素加上对应窗口的处理时间重新放入到堆中
//从第二个人开始算起，时间为堆顶元素再加上自身的值,之后再放入堆中

int minTimeToHandle(std::vector<int> &time, int num)
{
    std::priority_queue<int,std::vector<int>, std::greater<int>()> pq;

    for(const int &n : time) {
        pq.push(time);
    }

    for(int i = 1; i < num; i++) {
        pq.push(pq.top()*2);
    }

    return pq.top();
}



/*
    Leetcode第967题
*/


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


/*
    有n个任务,每个任务有开始和结束时间,如何安排任务的顺序,使得完成的任务个数是最多的
    例如:(5,10), (6,9), (7,8), (9,11)
*/

//按照结束时间排序

int mostTasks(std::vector<std::vector<int>> nums)
{
    sort(nums.begin(), nums.end(), [](std::vector<int> &a, std::vector<int> &b){
        return a[1] < b[1];
    });

    int count = 0;

    int end = nums[1];
    for(int i = 1; i < nums.size(); i++) {
        if(end <= nums[i][0]) {
            end = nums[i][1];
            count++;
        }
    }

    return count;
}



