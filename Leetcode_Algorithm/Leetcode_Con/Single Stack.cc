
/*
*
*    单调栈题型汇总
*
*/


/*
    下面这三题写成一个统一的写法
    第42题 : 接雨水
    第739题: 每日温度 
    496题 + 503题 + 556题 : 下一个更大的数字
*/

//Leetcode第42题:接雨水
//维持一个单调递减栈

int trap(std::vector<int> &height)
{
    if(height.size() <= 2) return 0;

    int res = 0;
    std::stack<int> index;

    for(int i = 0; i < height.size(); i++)
    {
        while(!index.empty() && height[i] > height[index.top()]) {
            int midIndex = index.top();
            index.pop();

            if(!index.empty()) {
                int hei = std::min(height[i], height[index.top()]) - height[midIndex];
                int wide = i - sta.top() - 1;
                res += wide * hei;
            }
        }

        index.push(i);
    }

    return res;
}


//Leetcode第739题 : 每日温度
//维持一个单调递减栈

std::vector<int> dailyTemperatures(std::vector<int> &T)
{
    if(T.empty()) return {};

    std::vector<int> ans(T.size(), 0);
    std::stack<int> sta;

    for(int i = 0; i < T.size(); i++)
    {
        while(!sta.empty() && T[sta.top()] < T[i]) {
            ans[sta.top()] = i - sta.top();
            sta.pop();
        }

        sta.push(i);
    }

    return ans;
}


//Leetcode第84题 : 直方图的最大矩形面积
//思路:维持一个单调递增栈

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


//Leetcode第85题 : 0和1组成的最大的矩形面积(利用到了第84题)

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

        res = std::max(res, largestRectangleArea(height));  //调用上面84题的计算直方图的面积函数
    }

    return res;
}


// Leetcode第496题 : Next Greater Element I
// 找到比当前数字大的下一个临近数字

// 思路:单调栈+哈希
// 对nums2建立一个哈希,mp[n1]=n2,代表nums2数组中第一个比n1大的元素为n2
// 依次判断nums1中的元素在哈希表中的value,如果存在就说明第一个最大的元素就是hash[nums1]

std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2)
{
    std::stack<int> sta;
    std::unordered_map<int, int> mp;    //mp用来记录后面比当前数字大的第一个数字

    for(const int &n : nums2)
    {
        while(!sta.empty() && n > sta.top()) {
            mp[sta.top()] = n;
            sta.pop();                          //这里需要pop, 防止数组num2={4,3,2,1,6},先递减再递增
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


//Leetcode第503题 : Next Greater Element II 

//思路:第一次遍历得到正常数组的下一个比当前数值大的元素
//第二次遍历得到比环形数组的下一个比当前数值大的元素

std::vector<int> nextGreaterElement(std::vector<int> &nums)
{
    std::stack<int> sta;
    std::vector<int> res(nums.size(), -1);

    int n = nums.size();
    for(int i = 0; i < 2*n; i++)
    {
        while(!sta.empty() && nums[sta.top()] < nums[i%n]) {
            res[sta.top()] = nums[i%n];
            sta.pop();
        }

        sta.push(i%n);
    }

    return res;
}


//Leetcode第556题 : Next Greater Element III (与第31题下一个排列解法非常相似)

//思路:转化成字符串
//1.从后往前找,找到第一个字符c1,该字符小于后一个字符
//2.从后往前找,找到第二个字符c2,该字符大于c1
//3.交换c1和c2的位置,之后将c1之后的元素逆序排列

// 比如: "23871", 找到3后,再从末尾开始找到比3大的第一个数字7, 交换3和7的位置,得到27831, 将831逆序得到128, 结果为27138

int nextGreaterElement(int n)
{
    std::string str = std::to_string(n);
    int n = str.size();
    if(n <= 1) return -1;

    //从末尾开始找到第一个比后一个字符小的字符
    int i = nums.size()-2;
    while(i >= 0 && nums[i] >= nums[i+1]) {
        i--;
    }

    if(i == 0) return -1;   //数字是递减的,不存在比该数字大的数

    //从后开始找到第一个比i位置大的数
    int j = nums.size() - 1;
    while(j > i && nums[j] <= nums[i]) {
        j--;
    }

    //将i之后的字符串逆序
    reverse(str.begin() + i + 1, str.end());

    //判断下一个数是否在INT的范围内
    if(std::stol(str) > INT_MAX) return -1;
    else return std::stoi(str);
}



//////////////////////////////////////////////////

//          基本计算器
//         第224题: Basic Calculator I (带'+','-'号和'()'运算的计算器)
//         第227题: Basic Calculator II (带'+','-','*','/'运算的计算器)
//         第772题: Basic Calculator III (上面两题的综合版本, 既带加减乘除，又带括号运算)

//         回溯解决下面问题
//         第282题: 计算可能组成target的所有数字组合
//         第679题: 计算24点          
//
//////////////////////////////////////////////////


//Leetcode第227题 : 实现加减乘除计算器

//思路：将数据带上符号逐个入栈即可
//如: "3+2-1", 将 +3, +2, -1 逐个入栈，然后出栈相加
//对于 "3+2*2", 遇到'*','/'需要先将前一个数出栈与当前数做操作后再将结果入栈

//注意：遇到符号了才将前一个数入栈,并更改当前的符号

int calculate(std::string s)
{
    int num = 0, pre = 0;
    char sign = '+';

    std::stack<int> sta;

    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        if(isdigit(c)) {
            num = num*10 + (c - '0');
        }

        //下面不能写成 else if, 因为最后一个字符也可能是数字
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


// Leetcode第772题 : 带括号的计算器
// 思路：知道了不带括号怎么计算，遇到括号了直接将括号内容丢进递归让其计算

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
            int count = 0;
            int j = i;
            for(; j < s.size(); j++) {
                if(s[j] == '(') count++;
                else if(s[j] == ')') count--;
                if(count == 0) break;
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

    //累加栈中元素
    int res = 0;
    while(!sta.empty()) {
        res += sta.top();
        sta.pop();
    }

    return res;
}


//Leetcode第282题: 计算所有可能组成target的目标字符串组合
//思路:这一题返回全局变量行不通,必须把res带入到函数参数列表中去

std::vector<std::string> res;

std::vector<std::string> addOperators(std::string num, int target)
{
    dfs(num, target, 0, 0, "");

    return res;
}

//prev记录前一个数字,curNum计算当前数字的和
void dfs(std::string num, int target, long prev, long curNum, std::string path)
{
    if(num.empty() && curNum == target) {
        res.push_back(path);
        return;
    }

    for(int i = 1; i <= nums.size(); i++)
    {
        std::string cur = num.substr(0, i);

        if(cur.size() > 1 && cur.front() == '0') return;    //去除掉 "0X"

        std::string next = num.substr(i);

        //第一个数前面不需要添加任何符号
        if(path.size() > 0) {
            dfs(next, target, std::stol(cur), curNum + std::stol(cur), path + "+" + cur);       // "+"
            dfs(next, target, -std::stol(cur), curNum - std::stol(cur), path + "-" + cur);      // "-"

            //除法运算:需要修正一下之前的结果,减去之前加上的结果, 再加上最新的乘积
            dfs(next, target, prev*std::stol(cur), (curNum-prev) + prev*std::stol(cur), path + "*" + cur);
        }
        else {
            dfs(next, target, std::stol(cur), std::stol(cur), cur);
        }

    }


}

//Leetcode第679题:计算24点
//注意这里的除法计算的是分数,不是整数除法

//思路:每次拿出两个数计算,将其余的数放到另外一个新数组,将拿出来的两个数计算完后也放入新数组
//以此递归直到新数组的元素个数为1,且值为24

double epison = pow(10.0, -5);

std::vector<char> operations = {'+', '-', '*', '/'};

bool judgePoint24(std::vector<int> &nums)
{
    std::vector<double> numbers;
    for(const int &n : nums) {
        numbers.push_back(n*1.0);       //之所以转化成浮点数是为了处理除以分数
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
                if(k != i && k != j) res.push_back(nums[k]);    //将其余的数放到新数组
            }

            for(char &op : operations)
            {
                if((op == '+' || op == '*') && i > j) continue;    //这种运算符满足交换律
                if(op == '/' && (nums[j] < epison)) continue;      //除数不能为0

                switch(op) {
                    case '+' : res.push_back(nums[i] + nums[j]); break;     //将生成的数加入到数组中
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



