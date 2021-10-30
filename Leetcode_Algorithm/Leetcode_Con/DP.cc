
/*
    动态规划系列
*/

/////////////////////////////////////////////
//
//  股票买卖问题(重点画出状态转移图)
//  121题直接遍历记录最小值即可
//  122题 (k = INF)
//  309题 (k = INF, 但是包含冷冻期)
//  714题 (k = INF, 但是包含手续费)
//  123题 (k = 2)
//  188题 (k = 任意数)
//
/////////////////////////////////////////////

// dp[i][k][0] 代表第i天不持有股票,至今最多进行了k次交易
// dp[i][k][1] 代表第i天持有股票,至今最多进行了k次交易

//base case: dp[-1][k][0] = 0, dp[-1][k][1] = -INF
//           dp[i][0][0] = 0, dp[i][0][1] = -INF

// 则状态转移方程: dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])      注意:买进和卖出算一次交易,卖出交易数不会减少
//              dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])   //买入交易数就要加1(寻找上一次最多交易数为k-1的)

// 最终结果为 dp[n-1][k][0]



//第121题: k = 1

// dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
// dp[i][1] = max(dp[i-1][1], -prices[i]);

int maxProfit(std::vector<int> &prices)
{
    int n = prices.size();
    int dp_i_0 = 0, dp_i_1 = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        dp_i_0 = std::max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = std::max(dp_i_1, -prices[i]);
    }

    return dp_i_0;
}

//方法二:
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


//第122题: k = INF
//相当于k不变,忽略掉k

// dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
// dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);

int maxProfit(std::vector<int> &prices)
{
    int n = prices.size();
    int dp_i_0 = 0, dp_i_1 = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        int tmp = dp_i_0;
        dp_i_0 = std::max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = std::max(dp_i_1, tmp - prices[i]);
    }

    return dp_i_0;
}


int maxProfit(std::vector<int> &prices)
{
    int n = prices.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2,0));

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


//最快速的办法: 发现有价格比之间的高时立刻买出即可

int maxProfit(std::vector<int> &prices)
{
    int res = 0;
    
    for(int i = 1; i < prices.size(); i++) {
        if(prices[i] > prices[i-1]) {
            res += prices[i] - prices[i-1];
        }
    }

    return res;
}




//第309题: k = INF, 但是包含冷冻期

// 买入的时候需要从第ｉ-2天转移
// dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
// dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);

//base case变成i = 0,和 i = 1

int maxProfit(std::vector<int> &prices)
{
    int n = prices.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2, 0));

    dp[0][0] = 0;
    dp[0][1] = INT_MIN;
    dp[1][0] = 0;
    dp[1][1] = -prices[0];

    for(int i = 2; i <= n; i++)
    {
        dp[i][0] = std::max(dp[i-1][0], dp[i-1][1] + prices[i-1]);
        dp[i][1] = std::max(dp[i-1][1], dp[i-2][0] - prices[i-1]);
    }

    return dp[n][0];
}


int maxProfit(std::vector<int> &prices)
{
    int n = prices.size();
    int dp_i_0 = 0, dp_i_1 = INT_MIN;
    int dp_pre_0 = 0;
    for(int i = 0; i < n; i++)
    {
        int tmp = dp_i_0;
        dp_i_0 = std::max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = std::max(dp_i_1, dp_pre_0 - prices[i]);
        dp_pre_0 = tmp;     //这种写法不好(很难理解)
    }

    return dp_i_0;
}


//第714题: k = INF, 但是包含手续费

//卖出的时候将手续费扣掉即可

// dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - free)    
// dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);

int maxProfit(std::vector<int> &prices,, int fee)
{
    int n = prices.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = INT_MIN;

    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = std::max(dp[i-1][0], dp[i-1][1] + prices[i-1] );    //fee如果放入到这里可能会溢出,因为i=1时,dp[i-1][1]为一个INT_MIN
        dp[i][1] = std::max(dp[i-1][1], dp[i-1][0] - prices[i-1] - fee);
    }

    return dp[n][0];
}


int maxProfit(std::vector<int> &prices, int fee)
{
    int n = prices.size();
    int dp_i_0 = 0, dp_i_1 = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        int tmp = dp_i_0;
        dp_i_0 = std::max(dp_i_0, dp_i_1 + prices[i]);   //如果这里减fee 可能会溢出
        dp_i_1 = std::max(dp_i_1, tmp - prices[i] - fee);
    }

    return dp_i_0;
}



//第123题: k = 2
//需要穷举

// base case 为i=0,和k=0时
// dp数组初值赋值为0, 则 i = 0 时, dp[0][k][1] = -INF
//                    k = 0, dp[i][0][1] = -INF


int maxProfit(std::vector<int> &prices)
{
    int n = prices.size();

    int dp[n+1][3][2];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i <= n; i++) {
        for(int k = 0; k <= 2; k++) {
            if(i == 0 || k == 0) {          //处理base case的情况
                dp[i][k][1] = INT_MIN;
                continue;
            }

            dp[i][k][0] = std::max(dp[i-1][k][0], dp[i-1][k][1] + prices[i-1]);
            dp[i][k][1] = std::max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i-1]);
        }
    }

    return dp[n][2][0];
}



//第188题: k为任意数

int maxProfit(std::vector<int> &prices, int max_k)
{
    int n = prices.size();
    if(max_k > n/2) {
        return maxProfitUnlimit(prices);
    }

    int dp[n+1][max_k+1][2];
    memset(dp, 0, sizeof(dp));     //数组初始化全部使用memeset方式

    for(int i = 0; i <= n; i++) {
        for(int k = 0; k <= max_k; k++) {
            if(i == 0 || k == 0) {          //处理 Base case
                dp[i][k][1] = INT_MIN;
                continue;
            }
            
            dp[i][k][0] = std::max(dp[i-1][k][0], dp[i-1][k][1] + prices[i-1]);
            dp[i][k][1] = std::max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i-1]);
        }
    }

    return dp[n][max_k][0];
}

//方法一:发现有价格比前面大时,立即买入卖出即可
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




//////////////////////////////
//
//      石子合并问题(动态规划+贪心)
//
/////////////////////////////


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

//2.只能合并相邻的两个石头(参考美团2020校招系统开发方向)
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





////////////////////
//
//     背包问题  
//     (0-1背包)  思路:外层物品的价值,里层总价值,逆向遍历
//     第416题: 切分相同的子数组和
//     第474题: 给定m个0和n个1,求能构成的最多的字符串个数 (题目比较难理解)

//     (无界背包)  思路:外层总价值,里层物品的价值,正向遍历
//     第279题: 组成目标所需的最小平方数数目

//     第322题: 钱币兑换I  (返回组成目标target所需的最少的硬币数)
//     第518题: 钱币兑换II (返回组成目标target的方法数,即有多少种钱币组合能组成target)
//
////////////////////


// Youtube 0-1背包问题
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


//Leetcode第416题:切分子数组

// dp[i][j] 表示前i个数的是否存在组合数的和等于j
// dp[i][j] = dp[i-1][j] || dp[i-1][j-n], j >= n(n为第i个数的数值)
//          = dp[i-1][j],  j < n(代表背包放不下去) 

// base case dp[i][0] = 1, dp[0][j] = 0

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


// 状态空间压缩成一维, 则 dp[j] = dp[j] || dp[j-n], 注意j要逆序遍历
// base case dp[0] = 1

bool canPartition(std::vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum & 1) return false;

    int target = sum/2;
    std::vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for(const int &n : nums) {
        for(int j = target; j >= n; j--) {
            dp[j] = dp[j] || dp[j-n];
        }
    }
    
    return dp[target];
}



// Leetcode第474题 : 
// dp[k][i][j]代表前k个字符串,i个'0'和j个'1'时能组成的最大长度
// dp[k][i][j] = dp[k-1][i-cnt0][j-cnt1] + 1, 将第k个字符串加入
//             = dp[k-1][i][j],               不加入

// 状态压缩到二维, 则遍历需要从后往前遍历
// base case 是 k = 0, 但是现在压缩到二维空间,所以没有base case 


int findMaxForm(std::vector<std::string> &strs, int m, int n)
{
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for(const auto &str : strs)
    {
        int cnt0 = count(str.begin(), str.end(), '0');
        int cnt1 = str.size() - cnt0;

        for(int i = m; i >= cnt0; i--) {
            for(int j = n; j >= cnt1; j--) {
                dp[i][j] = std::max(dp[i][j], dp[i-cnt0][j-cnt1] + 1);
            }
        }
    }

    return dp[m][n];
}



//第279题 : 组成目标所需的最小平方数数目

// dp[i] 表示数字i所需的最小平方数数目多少种钱币组合能组
// dp[i] = min(dp[i], dp[i-j*j] + 1)

// base case dp[0] = 0

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



//Leetcode第322题 : 钱币找零(返回组成目标target所需的最少的硬币数)

//无穷背包问题

// dp[i][j]表示钱数为j时从前i种硬币中换出的最少硬币数
// dp[i][j] = dp[i-1][j],  不换
// dp[i][j] = dp[i][j-n] + 1,  换
// dp[i][j] 就取这两者最小值

// dp[i][j] = dp[i-1][j], if j < nums[i]
//            min(dp[i-1][j], dp[i][j-nums[i]]) else


// base case i = 0(表示硬币种数为0), dp[0][0] = 0,  dp[0][j] = inf(表示不可能) 
//           j = 0(表示兑换的钱数为0), dp[i][0] = 0

//二维问题的写法
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

//二维空间压缩成一维空间

// dp[i]表示兑换i元有多少种方法,
// dp[i] = min(dp[i], dp[i-n] + 1);

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



// 第518题: 钱币兑换II (返回组成目标target的方法数,即有多少种钱币组合能组成target)

// dp[i][j]表示前i种硬币组成钱j的方法数
// dp[i][j] = dp[i-1][j], if j < nums[i]
//          = dp[i-1][j] + dp[i][j-n], if j >= nums[i]


///////////////////////////
//
//      World Break问题
//
//      第97题 : 交错字符串
//      第139题: 字符串切分

//////////////////////////

//Leetcode第139题 : Word Break

// 方法一:动态规划
// dp[i]表示字符串的下标为i的位置是否能被切分,或者表示为i前面的字符是否在wordDict中
// 则dp[i] = dp[i] || dp[i-size], size为单词的长度
// size的长度至少为1,则base case 为 i = 0

bool wordBreak(std::string s, std::vector<std::string> &wordDict)
{
    int n = s.size();
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
       for(const auto &word : wordDict) {
            int len = word.size();
            if(i >= len && s.substr(i-len, len) == word) {
                dp[i] = dp[i] || dp[i-len];
            }
        }
    }

    return dp[n];
}


//方法二:DFS(暴力破解)

std::unordered_map<std::string, int> hash;  //已经搜索过的需要记录下来,否则会超时

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



//Leetcode第97题:判断交错字符串

// 思路 : dp[i][j] 代表s1前i个字符和s2的前j个字符是否能交错组成字符串s3的前(i+j)个字符
// 注意 : i>=1, j>=1
// 如果 s1[i-1]==s3[i+j-1], 则dp[i][j] = dp[i-1][j]
// 如果 s2[j-1]==s3[i+j-1], 则dp[i][j] = dp[i][j-1]

// base case 为i=0, 或者j=0; i=0 代表s1为空,j=0代表s2为空
// i = 0, j = 0, dp[0][0] = 1
// i = 0, dp[0][j] = dp[0][j-1] && s2[j-1] == s3[i+j-1]
// j = 0, dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i+j-1]

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

//解法二:
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


////////////////////////
//
//      字符串匹配问题

//      (72题): 最小编辑距离
//      (10题): 正则表达式匹配
//      (44题): 通配符匹配
//
///////////////////////

// Leetcode第72题:最小编辑距离
// dp[i][i]代表s[0..i]完全匹配t[0..j]部分需要修改几次(这个修改可以是插入,删除,替换)

// dp[i][j] = dp[i-1]][j-1], if s[i] = t[j]    相等不需要做任何修改

// dp[i][j] = dp[i][j-1] + 1,   1.在s中插入一个字符,则新插入的字符就和s[j]匹配了,所以结果就等于s[i]和t[j-1]匹配的结果
//            dp[i-1][j] + 1,   2.删除s中第i个字符,则结果就等于s[i-1]和t[j]匹配的结果
//            dp[i-1][j-1]+1    3.将s的第i个字符替换成t的第j个字符,则s[i]和t[j]就匹配了,结果就等于s[i-1]和t[j-1]匹配的结果
// 则dp[i][j]的结果就是上面三次尝试操作的最小操作数

//  base case 就是i=0, j=0, 为了更好处理边界条件,将dp移动一个维度

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
                dp[i][j] = std::min(std::min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            }
        }
    }
    
    return dp[m][n];
}


//Leetcode第10题:正则表达式匹配

// dp[i][j] 表示s[0...i]与p[0...j]这部分是否匹配

// if s[i]=p[j] || p[j]='.',  dp[i][j] = dp[i-1][j-1]

// else if p[j] = '*'
//      if s[j] != p[j-1] || p[j-1] != '.'  dp[i][j] = dp[i][j-2]
//      else dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i][j-2]

// dp[i][j-1]代表忽略掉'*', dp[i-1][j]代表'*'匹配当前字符, dp[i][j-2]代表'*'和前面字符全部忽略

bool isMatch(std::string s, std::string p)
{
    int m = s.size(), n = p.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    dp[0][0] = 1;
    for(int j = 1; j <= n; j++) {
        if(p[j-1] == '*') dp[0][j] = dp[0][j-2];
    }

    for(int i = 1; i <= m; i++) 
    {
        for(int j = 1; j <= n; j++) 
        {
            //s的当前字符与p的当前字符匹配 或者 p当前字符为'.',则s和p各后移一位    
            if(p[j-1] == '.' || s[i-1] == p[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] == '*') {
                if(s[i-1] != p[j-2] && p[j-2] != '.') {
                    dp[i][j] = dp[i][j-2];
                }
                else if(s[i-1] == p[j-2] || p[j-2] == '.') {
                    //dp[i-1][j]表示模式不变,字符串后移一位  (等价于'*'匹配n次)     "a*" = "aa..." 
                    //dp[i][j-1]表示忽略掉'*'             (等价于'*'匹配0次)     "a*" = "a"
                    //dp[i][j-2]表示'*'和前面的字符都忽略掉 (等价与'*'匹配0次并且前面的字符串也被忽略)   "a*" = ""
                    dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i][j-2];
                }
            }
        }
    }
    
    return dp[m][n];
}


//Leetcode第44题:通配符匹配

// dp[i][j] = dp[i-1][j-1], if s[i] = p[j] || p[j] = '.'
//          = dp[i-1][j] || dp[i][j-1], else if p[j] = '*'
//            dp[i-1][j]表示'*'匹配多次
//            dp[i][j-1]表示忽略'*'

bool isMatch(std::string s, std::string p)
{
    int m = s.size(), n = p.size();
    
    std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));

    dp[0][0] = 1;
    for(int j = 1; j <= n; j++) {
        if(p[j-1] == '*') {
            dp[0][j] = dp[0][j-1];
        }
    }

    for(int i = 1; i <= m; i++) 
    {
        for(int j = 1; j <= n; j++) 
        {
            if(s[i-1] == p[j-1] || p[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] == '*') {    //注意:这里的dp[i-1][j-1]表示字符串和模式都前移一位(这个加不加都可以)(思考为什么)
                dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i-1][j-1];    
            }                                                       
        }
    }

    return dp[m][n];
}



/////////////////////////////////
//
//      打家劫舍问题
//      第198题 : House Robber I
//      第213题 : 数组为一个环形数组
//      第337题 : 二叉树结构
//
/////////////////////////////////

//Leetcode第198题:
// dp[i]表示到达第i间房屋偷得的最大钱数,则第i间房屋只有两种选择,偷或者不偷
// dp[i] = dp[i-1], 不偷第i间房屋
// dp[i] = dp[i-2] + nums[i], 偷第i间房屋
// base case 为 i = 0,1;    dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);

int rob(std::vector<int> &nums)
{
    if(nums.size() == 1) return nums[0];
    
    int n = nums.size();
    std::vector<int> dp(n, 0);

    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);

    for(int i = 2; i < n; i++) {
        dp[i] = std::max(dp[i-1], dp[i-2] + nums[i]);
    }

    return dp[n-1];
}


//优化解法
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


//Leetcode第213题:数组为环形数组

// 一共三种情况:
// 1.首尾都不抢
// 2.抢首不抢尾
// 3.抢尾不抢首
// 只需考虑后两种情况即可(后两种情况包括第一种情况)

// 只需将上一题的数组遍历范围改成 [0, n-2] 和 [1, n-1]
// 在这两个范围内找到能抢到的最大金币数,取两者的较大值就行

int rob(std::vector<int> &nums)
{
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return std::max(nums[0], nums[1]);

    int n = nums.size();

    return std::max(robCore(nums, 0, n-2), robCore(nums, 1, n-1));
}

int robCore(std::vector<int> &nums, int left, int right)
{
    if(left == right) return nums[left];

    int first = nums[left];
    int second = std::max(nums[left], nums[left+1]);
    int cur = second;

    for(int i = left + 2; i <= right; i++) {
        cur = std::max(second, first + nums[i]);
        first = second;
        second = cur;
    }  

    return cur;
}



//Leetcode第337题 : 房屋为二叉树结构
//分为偷根节点和不偷根节点

std::unordered_map<TreeNode*, int> hash;

int rob(TreeNode *root)
{
    if(root == nullptr) return 0;

    if(hash.count(root)) return hash[root];

    //偷根节点
    int money1 = root->val;

    if(root->left) {
        res1 += rob(root->left->left) + rob(root->left->right);
    }
    if(root->right) {
        res1 += rob(root->right->left) + rob(root->right->right);
    }

    //不偷根节点
    int money2 = rob(root->left) + rob(root->right);

    int res = std::max(money1, money2);

    hash[root] = res;

    return res;
}


///////////////////////////
//
//     动态规划问题
//     第134题 : 加油站
//     第871题 : 最少加几次油 (题目出的非常好)   
//     
//     第576题 : 球出界的方法数,三维DP降维成二维DP
//
//     第91题 : 字符解码
//     第639题: 字符解码(II)
//
//     第546题: 消箱子游戏  
//
//
//     第115题 Distince Subsequence : 组成目标序列的组合个数和
//     第940题 Distince SubsequenceII : 上一题的升级版,找到所有不重复的子序列
//
//////////////////////////


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


//Leetcode第871题 : 最少加几次油

//方法一: 动态规划

// dp[t]代表加油t次能到达的最远距离
// if dp[t] >= s[i][0], dp[t+1] = dp[t] + s[i][1], t为0到n(n为加油站的总个数)
// 之后遍历dp数组,找到第一个 >=target 的t即可

int minRefuelStops(int target, int startFuel, std::vector<std::vector<int>> &stations)
{
    int dp[501] = {startFuel};

    for(int i = 0; i < stations.size(); i++) {
        for(int j = i; j >= 0 && dp[j] >= stations[i][0]; j--) {    //注意:这里必须逆向遍历才合乎逻辑
            dp[j+1] = std::max(dp[j+1], dp[j] + stations[i][1]);
        }
    }

    for(int t = 0; t <= stations.size(); t++) {
        if(dp[t] >= target) return t; 
    }

    return -1;
}

//方法二:优先队列

//维持一个优先队列,只要起始startFuel大于每个距离,就将每个加油站的油量加入到优先队列中
//之后加油量加上队列前面第一个元素的值,依次循环判断是否能到达目标target

int minRefuelStops(int target, int cur, std::vector<std::vector<int>> &s)
{
    int res = 0, i = 0;
    std::priority_queue<int> pq;

    for(; cur < target; res++)
    {
        while(i < s.size() && cur >= s[i][0]) {
            pq.push(s[i++][1]);
        }

        if(pq.empty()) return -1;

        cur += pq.top();    pq.pop();
    }

    return res;
}


//Leetcode第576题:球出界的总共可能数

// dp[i][j][k]表示从(i,j)出界,一共可以移动k次的可能数
// dp[i][j[k] = dp[i][j-1][k-1] + dp[i][j+1][k-1] + dp[i+1][j][k-1] + dp[i-1][j][k-1]

// base case就是边界移动出界的可能数
// base case, i<0 || i>=m || j<0 || j>=n 返回1  
//            k = 0 返回0

//方法一:动态规划(三维DP)

const int N = 1e9 + 7;
std::vector<int> dir = {-1, 0, 1, 0, -1};

int findPaths(int m, int n, int max_k, int x, int y)
{
    int dp[m][n][max_k+1];
    memset(dp, 0, sizeof(dp));

    for(int k = 1; k <= max_k; k++) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int w = 0; w < dir.size() - 1; w++)
                {
                    int m_x = i + dir[w], m_y = j + dir[w+1];
                    if(m_x < 0 || m_x >= m || m_y < 0 || m_y >= n) dp[i][j][k]++;
                    else dp[m_x][m_y][k] = (dp[m_x][m_y][k] + dp[i][j][k]) % N;

                    //else dp[m_x][m_y][k] += dp[i][j][k-1];    //理论上应该这样写,但是数值太大会溢出
                }
            }
        }
    }

    return dp[x][y][max_k];
}


//方法二: 利用DFS
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



//Leetcode第91题 : 字符解码(和青蛙跳台阶问题非常相似)

// dp[i]代表第i个字符结尾共有多少解码方式
// if s[i]位于(0,9)之间，则 dp[i] += dp[i-1]           
// if s[i-1...i]位于(10,26)之间，则 dp[i] += dp[i-2]
// base case i = 0 代表是空字符串 dp[0] = 1;
//           i = 1 代表只有一个字符, dp[1] = 1

int numDecodings(std::string s)
{
    if(s[0] == '0') return 0;

    int n = s.size();

    std::vector<int> dp(n + 1, 0);

    dp[0] = dp[1] = 1;

    for(int i = 2; i <= n; i++) 
    {
        int first = std::stoi(s.substr(i-1, 1));
        int second = std::stoi(s.substr(i-2, 2));

        if(first > 0 && first <= 9) dp[i] += dp[i-1];
        if(second >= 10 && second <= 26) dp[i] += dp[i-2];
    }

    return dp[n];
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


//Leetcode第115题: 组成目标序列的组合总数
// 思路:
// dp[i][j] 表示字符串s[0..i]和t[0..j]部分的组合个数
// dp[i][j] = dp[i-1][j],  if s[i] != t[j], 因为s字符串的数目要比t字符串长
//          = dp[i-1][j] + dp[i-1][j-1],  if s[i] = t[j]

// base case: i = 0, dp[0][0] = 1, dp[0][j] = 0
//            j = 0, dp[i][0] = 1


int numDistinct(std::string s, std::string t)
{
    if(s.empty() && t.empty()) return 1;
    if(s.empty() || t.empty()) return 0;
    if(s.size() < t.size()) return 0;

    int m = s.size(), n = t.size();
    // std::vector<std::vector<unsigned long>> dp(m, std::vector<int>(n));     //这里需要使用unsigned long,否则会溢出
    unsigned long dp[m+1][n+1];

    for(int i = 0; i <= m; i++) dp[i][0] = 1;       //初始化 base case 
    for(int j = 1; j <= n; j++) dp[0][j] = 0;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    return dp[m][n];
}


//Leetcode第940题: Distince Sequence II
// 思路:定义一个数组,全部初始化为0, int endsWith[26]
// endsWith[i]表示以第i个字母结束的sequence数量

int distinctSubseqII(std::string s)
{
    std::vector<long> endsWith(26,0);
    long mod = 1e9 + 7;

    for(const char &c : s) {
        endsWith[c-'a'] = accumulate(endsWith.begin(), endsWith.end(), 1L);     //注意:这里的1L就是long 1,
    }                                                                           //accumulate的第三个参数不仅代表累加和的初始值,同时也决定了返回值的类型,所以这里直接必须写成long类型才可

    return accumulate(endsWith.begin(), endsWith.end(), 0L);
}
