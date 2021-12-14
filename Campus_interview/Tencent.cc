/*
    给一个vector容器只能进行交换,怎么把所有的0都移动到元素末尾  (Leetcode第283题)
    保持其他非0元素的相对位置不变
*/

void moveZeros(std::vector<int> &nums)
{
    if(nums.empty()) return ;

    int cur = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] != 0) {
            std::swap(nums[cur++], nums[i]);
        }
    }

}


/*
    设定关系(A=1,B=2,...Z=26, AA=27, AB=28,),写一个转换函数,根据规则把一个字符串转换成数字(Leetcode第171题)
*/

int titleToNumber(std::string str)
{
    int res = 0;
    for(int i = 0; i < str.size(); i++) {
        res = res*26 + (str[i]-'A'+1);
    }

    return res;
}




//附:十进制转换成二进制
std::string transferFrom10To2(int num)
{
    if(num == 0) return "0";

    std::string res;
    while(num) {
        int b = num % 2;
        res = std::to_string(b) + res;
        num = num/2;
    }

    return res;
}

//仿照下面的十进制转16进制的写法,这里转二进制也可以用位运算
std::string toBin(int num)
{
    if(num == 0) return "0";

    std::string bin = "01";
    std::string res;
    int count = 0;
    while(num && count++ < 32)
    {
        res = bin[num & 1] + res;
        num >>= 1;
    }

    return res;
}


//附:十进制转换成7进制
//Leetcode第504题


//附:十进制转化成16进制
//Leetcode第405题
std::string toHex(int num)
{
    if(num == 0)  return "0";

    std::string hex = "0123456789abcdef";
    std::string res;
    int count = 0;
    while(num && count++ < 8)
    {
        res = hex[num & 0xf] + res;
        num >>= 4;
    }

    return res;
}




/*
    两数相加
*/

//str1 + str2 (注意:str1和str2均不含负号,是两个正数相加)

// 直接从尾部相加即可(不需要逆序)

std::string addTwoNumber(std::string num1, std::string num2)
{
    std::string res;

    int i = 0, j = 0;
    int carry = 0;

    while(i >= 0 || j >= 0 || carry)
    {
        carry += (i >= 0 ? num1[i--]-'0' : 0) + (j >= 0 ? num2[j--]-'0' : 0);

        res = std::to_string(carry%10) + res;

        carry /= 10;
    }

    return res;
}




/*
    两数相减
*/

//我们让 num1 - num2, 且num1的绝对值大于num2,这样方便处理借位

//str1 - str2 (注意:str1和str2均不含有负号)

std::string subTwoNumber(std::string num1, std::string num2)
{
    if(num1 == num2) return "0";

    //让num1始终比num2大,这样方便处理借位
    bool positive = bigger(num1, num2);

    //num1不大于num2就交换位置
    if(!positive) {
        std::swap(num1, num2);
    }

    //将num2的长度补齐到和num1一样
    while(num1.size() > num2.size()) {
        num2 = "0" + num2;
    }

    for(int i = num1.size() -1; i >= 0; i--)
    {
        //不足就向上一位借位
        if(num1[i] < num2[i] && i > 0) {
            num1[i-1]--;
            num1[i] += 10;
        }

        num1[i] -= (num2[i] - '0');
    }

    std::string res = num1;

    if(res[0] == '0') res = res.substr(1);  //去掉开头的0,比如 "100" - "1" = "099"

    //将结果还原
    if(!positive) res = "-" + res;

    return res;
}

bool bigger(const std::string &num1, const std::string &num2)
{
    if(num1.size() != num2.size()) return num1.size() > num2.size();

    for(int i = 0; i < num1.size(); i++) {
        if(num1[i] != num2[i]) return num1[i] > num2[i];
    }

    //这里返回true或者false都可以,这一句永远不会被执行
    return false;
}



/*
    这种情况能够处理两个数存在负数的情况
    对上面两个函数的封装
*/
std::string AddAndSubTwoNumber(std::string str1, std::string str2)
{
    //两个数均为正数,则直接相加
    if(str1[0] != '-' && str2[0] != '-') return addTwoNumber(str1, str2);
    //两个数均为负数
    else if(str1[0] == '-' && str2[0] == '-') {
        str1 = str1.substr(1);
        str2 = str2.substr(1);
        return '-' + addTwoNumber(str1, str2);
    }

    //两个数存在一个为负数
    if(str1[0] == '-') {
        return subTwoNumber(str2, str1);
    }
    else {
        return subTwoNumber(str1, str2);
    }

}


/*
    两数相乘
    Leetcode第43题
*/

std::string multiplyTwoNumber(std::string num1, std::string num2)
{
    int m = num1.size(), n = num2.size();
    std::string res(m + n, '0');

    for(int i = m-1; i >= 0; i--) {
        for(int j = n-1; j >= 0; j--) {
            int prod = (num1[i]-'0') * (num2[j]-'0') + (res[i+j+1]-'0');
            res[i+j] += prod/10;
            res[i+j+1] = prod%10 + '0';
        }
    }

    for(int i = 0; i < res.size(); i++) {
        if(res[i] != '0') {
            return res.substr(i);
        }
    }

    return "0";
}



/*
    判断两个二叉树是否同构
*/

bool Isomorphic(TreeNode *root1, TreeNode *root2)
{
    if(root1 == nullptr || root2 == nullptr) return root1 == root2;

    if(root1->val != root2->val) return false;      // 根节点值的不相同,则不同构

    // 两棵树的左子树均为空或者右子数均为空,则只需比较另外一边子树
    if(root1->left == nullptr && root2->left == nullptr) {
        return Isomorphic(root1->right, root2->right);
    }
    else if(root1->right == nullptr && root2->right == nullptr) {
        return Isomorphic(root1->left, root2->left);
    }
    // 两棵树存在左子树且值相等
    else if(root1->left && root2->left && root1->left->val == root2->left->val) {
        return Isomorphic(root1->left, root2->left) && Isomorphic(root1->right, root2->right);
    }
    else {
        return Isomorphic(root1->left, root2->right) && Isomorphic(root1->right, root2->left);
    }

}



/*
    工行有30w个员工,其工卡号码分别为1~30万,抽取十万个员工发放奖品;有一个随机数生成器能生成0~65535的随机数
    写一个公平的抽奖过程,输出这10万个员工的工卡号码
*/


//等概率生成一个[1~600]之间的数
int randNum() 
{
    int num; 
    while(1)
    {   num = rand()%65536;
        if(num > 59999) continue;
        else break;
    }

    return num%600 + 1;
}

//等概率生成一个[1~30W]之间的数
int getNumber() 
{
    int num;
    while(1)
    {
        num = 600*(randNum()-1) + randNum();
        if(num > 300000) continue;
        else break;
    }

    return num;
}


/*
    给定一个字符串S和一个字符C,返回一个代表字符串S中每个字符到字符串中的字符C的最短距离的数组
    如输入S="my_test_str", C='t',输出{3,2,1,0,1,1,0,1,1,0,1}
*/

std::vector<int> shortestToChar(std::string s, char c)
{
    //字符串s中不存在字符c则返回为空
    if(s.find(c) == std::string::npos) return {};

    std::vector<int> index;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == c) {
            index.push_back(i);
        }
    }

    std::vector<int> res;
    for(int i = 0; i < s.size(); i++) 
    {
        auto it = lower_bound(index.begin(), index.end(), i);
        
        //1.字符位于第一个c之前
        if(it == index.begin()) {
            res.push_back(index.front() - i);
        }
        //2.字符位于最后一个c之后
        else if(it == index.end()) {
            res.push_back(i - index.back());
        }
        //3.字符位于多个c之间
        else {
            int later = *it;
            int prev = *(--it);
            int minVal = std::min(later - i, i - prev);
            res.push_back(minVal);
        }
    }

    return res;
}



/*
    给定一个字符串,由字符"0"和"1"组成,找到含有相同数量的"0"和"1"的最长子串的长度;(参见网易校招题)
    如:输入"01001001",输出4,满足要求的最长子串为 "1001"
*/

//暴力解法:如果一个长度为n的子串满足条件,则这n个元素加起来的和一定为n/2,且子串长度为偶数
//时间复杂度O(n^2)

int findMaxLength(std::string s)
{
    int res = 0;
    for(int i = 0; i < s.size(); i++) 
    {
        int sum = 0;
        for(int j = i; j < s.size(); j++) 
        {
            int len = j - i + 1;
            sum += s[j] - '0';

            if((len&1) == 0 && sum == (len<<1) && len > res) {
                res = len;
            }
        }
    }

    return res;
}

//解法二:
//思路:定义一个数组dp[i]表示字符串s[0..i]之间的0与1的个数差
//则问题就转化为在dp中求元素相同但是相距最远的一对数
//但是如果子串是从开头开始的,则个数差为0,所以需要单独提取出个数差为0的子串比较,个数差为0的子串的长度就是下标+1

int findMaxLength(std::string s)
{
    std::vector<int> dp(s.size());
    std::unordered_map<int,std::vector<int>> mp;
    int res = 0;

    std::vector<int> count(2, 0);
    for(int i = 0; i < s.size(); i++)
    {
        count[s[i]-'0']++;
        dp[i] = count[1] - count[0];        //计算1与0的个数差
        if(dp[i] == 0) {
            res = i + 1;
        }

        mp[dp[i]].push_back(i);
    }

    for(auto m : mp) {
        res = std::max(res, m.second.back() - m.second.front());
    }

    return res;
}



/*
    给出一个整数N,求小于等于N的所有整数中,哪个数A的每个位上的乘积最大,求出这个数
    (下面这个方法并没有求出这个数)
*/

//思路:比它大要么变成9,要么不变
//变成9就要向上一位借位

//找到最大的乘积
int dfs(int n)
{
    if(n == 0) return 1;
    if(n < 10) return n;

    return std::max(dfs(n/10-1)*9, dfs(n/10)*(n%10));
}



/*
    手动实现vector
    //着重注意push_back的书写(未完成)
*/


template<class T>
class vector
{
private:
    int num;
    T *list;

public:
    vector(int sz = 0);            //构造函数
    vector(const vector<T> &a);    //复制构造函数
    ~vector();                     //析构函数

    T & operator[] (int i);        //对"[]"运算符的重载
    int size() const;              //获取元素个数
    void resize(int sz);           //更改容易的元素个数
};

template<class T>
vector<T>::vector(int sz) {
    if(sz >= 0) {
        num = sz;
        list = new T[sz];
    }
    else {
        std::cout << "Error!" << std::endl;
        exit(1);
    }
}

template<class T>
vector<T>::vector(const vector<T> &a) {
    num = a.num;
    list = new T[num];

    for(int i = 0; i < num; i++) {
        list[i] = a.list[i];
    }
}

template<class T>
vector<T>::~vector() {
    delete[] list;
}

template<class T>
T &vector<T>::operator[] (int i) {
    if(i >= 0 && i < num) {
        return list[i];
    }
    else {
        std::cout << "Error\n" << std::endl;
        exit(1);
    }
}

template<class T>
int vector<T>::size() const {
    return num;
}

template<class T>
void vector<T>::resize(int sz) {
    if(sz < 0) {
        std::cout << "Error!\n" << std::endl;
        exit(1);
    }

    if(sz == num) return;

    T *newList = new T[sz];
    int n  = (sz < num) ? sz : num;

    for(int i = 0; i < n; i++) {
        newList[i] = list[i];
    }
    delete[] list;
    list = newList;
    num = sz;
}


/*
    计算平方根(精确到小数点后四位)
*/
//参考Leetcode第69题
//思路:二分

double mySqrt(int x)
{
    if(x < 0) return -1;

    double left = 0, right = x;

    while(left <= right)
    {
        double mid = left + (right-left)/2;
        if(fabs(mid*mid - x) < 0.0001) {
            return mid;
        }
        else if(mid*mid < x) {  //注意:浮点数二分不需要left=mid+1,因为浮点数的mid一定大于left
            left = mid;
        }
        else if(mid*mid > x) {
            right = mid;
        }
    }

    return -1;
}


//开链法实现哈希

const int HASHSIZE = 10;    //哈希表元素个数

struct Node {
    char *key;
    char *value;
    Node *next;
    Node() : key(nullptr), value(nullptr), next(nullptr) {}    
};


class HashTable
{
private:
    Node *node[HASHSIZE];

public:
    HashTable() {
        memset(node, NULL, sizeof(node));
    }


    //散列函数，计算key值位于node数组中的位置
    int Hash() {}

    //查找key值
    bool find(const char *key) 
    {
        int index = hash(key);      //由散列函数计算出在节点数组node中的下标

        Node *pNode = node[index];
        while(pNode)
        {
            //strcmp相同返回0
            if(!strcmp(pNode->key, key)) return true;
            
            pNode = pNode->next;
        }

        return false;    //表示未查找到
    }

    //插入键值对
    bool insert(const char *key, char *value)
    {
        Node *pNode = find(key);

        //key值不存在,则插入
        if(pNode == NULL)
        {
            int index = hash(key);
            pNode = (Node*)malloc(sizeof(Node));

            if(pNode == NULL) return false;     //申请失败则返回false

            pNode->key = key;
            pNode->value = value;
            node[index] = pNode;
        }

        //key值已经存在,则更新value值
        pNode->value = value;

        return true;
    }

    //删除某个key
    bool deleteKey(const char *key) 
    {
        Node *pNode = find(key);
        if(pNode == NULL) return false;     //不存在该key值

        //找到要删除节点的上一个节点prev,将prev指向要删除节点的下一个节点
        int index = hash[key];
        if(node[index] == pNode) {
            free(pNode);                    //不存在哈希冲突，也就是该位置链表只有一个节点
            pNode = NULL;
        }
        else {                              //存在哈希冲突
            Node *prev = node[index];
            while(prev->next != pNode) {
                prev = prev->next;
            }
            prev->next = pNode->next;       //上面的Node必须提供一个默认的构造函数，否则这里会报错,因为假设 1->2, 我现在删除2,将1指向2的下一个，没有默认构造函数2的next指针未初始化
            free(pNode);                    //则将其赋值给prev->next就是错误的
            pNode = NULL;
        }

        pNode = NULL;
        return true;
    }
};



/*
    用数组实现一个循环队列
    //参考Leetcode第622题
*/

int data[10000];

int head;

int tail;

//初始化当前队列
void initQueue() 
{
    head = 0;
    tail = 0;
}


int push(int val) 
{
    //判断队列是否满
    if((tail + 1)%(10000) == head) return 0;

    data[tail] = val;

    //尾指针向后移动一位
    tail = (tail + 1)%(10000);

    return 1;   //返回1表示插入成功
}

int pop(int *val)
{
    if(head == tail) return 0;  //队列为空则返回0

    *val = data[head];

    //头指针往后移动一位
    head = (head + 1)%(10000);

    return 1;   //返回1表示弹出成功
}

//队列满的判断
bool isFull() 
{
    if((tail + 1)%10000 == head)  return true;

    return false;
}

//队列的长度
int lenQueue() 
{
    return (10000 + tail - head)%(1000);
}
