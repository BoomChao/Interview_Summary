
/*
*
*   连续子数组
*
*/


//Leetcode第53题:最大子数组的和(也简称为最大子序和)

int maxSubArray(std::vector<int> &nums)
{
    int res = INT_MIN, sum = 0;
    for(const int &n : nums) {
        sum += n;
        if(sum < n) {
            sum = n;
        }
        res = std::max(res, sum);
    }

    return res;
}

//扩展:如果是一个环形数组,即数组首尾元素是相连的,求最大子数组的和
//Leetcode第918题

//思路:环形数组最大子数组的和可能是不环形最大子数组或者整个环形数组的和减去不环形数组的最小子数组和

int maxSubArrayCircular(std::vector<int> &nums)
{
    int maxSum = 0, finMaxSum = INT_MIN;
    int minSum = 0, finMinSum = INT_MAX;
    
    for(const int &n : nums) {
        maxSum += n;
        maxSum = std::max(maxSum, n);
        finMaxSum = std::max(finMaxSum, maxSum);

        minSum += n;
        minSum = std::min(minSum, n);
        finMinSum = std::min(finMinSum, minSum);
    }

    int total = accumulate(nums.begin(), nums.end(), 0);

    //如果数组全为负数或者0,则这时finalSum等于全数组的和    (比如数组{-3,-2,-1})
    if(finMinSum == total) return finMaxSum;

    return std::max(finMaxSum, total - finMinSum);

}


//Leetcode第363题: 二维数组超过k的最大子数组和(题目出的非常好)

//一维数组的最大子数组和(不超过k)
//时间复杂度O(nlogn)
//空间复杂度O(n)

int maxSubarrySumNoMoreThanK(std::vector<int> &nums, int k)
{
    std::set<int> mySet;
    mySet.insert(0);        //这是为了防止数组只有一个元素的情况，比如{2}, k=2

    int res = INT_MIN, sum = 0;

    for(const int &n : nums) 
    {
        sum += n;
        auto it = mySet.lower_bound(sum - k);                   //这是lower_bound函数,想象成一个区间 {x...sum}, 找到最小的sum-k
        if(it != mySet.end()) res = std::max(res, sum - *it);
        mySet.insert(sum);
    }

    return res;
}


//下面滑动窗口这种方式适合找到子数组和<=k的最大长度，不能找到<=k的最大的子数组和
//
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

        res = std::max(res, sum);
    }

    return res;
}


//二维数组的最大子数组和(不超过k)

//时间复杂度O(col*col*row*log(row))
//空间复杂度O(row)

int maxSumSubmatrix(std::vector<std::vector<int>> &matrix, int k)
{
    if(matrix.empty()) return 0;

    int m = matrix.size(), n = matrix[0].size();
    int res = INT_MIN;

    for(int left = 0; left < n; left++)
    {
        std::vector<int> sums(m, 0);
        for(int right = left; right < n; right++)
        {
            for(int i = 0; i < m; i++) {
                sums[i] += matrix[i][right];
            }

            //在sums中找到最大的子数组和
            res = std::max(res, maxSubarrySumNoMoreThanK(sums, k));
        }
    }

    return res;
}





///////////////////////////////////////////////
//    递增子序列(或者子数组)
//
//       31题: 下一个递增的排列
//      300题: 最长递增子序列
//      334题: 判断数组是否存在三个连续增长元素的子序列 (和第414题非常相似)

//      128题: 求出数组中最长的连续序列(注:不是子序列,而且要求序列中元素满足方差为1)

//      674题: 最长递增子数组长度
//      673题: 最长递增子序列的个数
//
//////////////////////////////////////////////

//Leetcode第31题: 下一个递增的子序列

//思路:
//1.找到最大的i, nums[i] < nums[i+1], 如果i不存在则返回原数组逆序的结果
//2.找到最大的j, i < j, nums[i] < nums[j]
//3.交换nums[i]和nums[j]
//4.将nums[i+1:]的元素逆序

void nextPermutation(std::vector<int> &nums)
{
    int i = nums.size() - 2;
    for(; i >= 0; i--) {
        if(nums[i] < nums[i+1]) break;
    }

    if(i < 0) {
        reverse(nums.begin(), nums.end());
        return;
    }

    int j = nums.size() - 1;
    for(; j > i; j--) {
        if(nums[j] > nums[i]) break;
    }

    std::swap(nums[i], nums[j]);

    reverse(nums.begin() + i + 1, nums.end());
}




//Leetcode第300题: 最长递增子序列
//思路:动态规划

int lengthOfLIS(std::vector<int> &nums)
{
    if(nums.empty()) return 0;

    std::vector<int> dp(nums.size(), 1);    //子序列至少也要包含自己,所以初始化为1

    int res = 1;

    for(int i = 0; i < nums.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);   //取所有递增序列长度的最大值
            }
        }
        res = std::max(res, dp[i]);     //记录当前i元素结尾的子序列最大值
    }    
    
    return res;
}


//另外一种方法
//试图用vector来维护一个递增子序列
//时间复杂度O(nlogn),空间复杂度为O(n)
//注意:这种方法时间复杂度之所以为O(nlogn),是因为res是排序数组,那么lower_bound方法寻找下边界是按照二分查找的方式来进行的
//二分查找的时间复杂度为O(logn)

//lower_bound函数对于排序数组的查找是对数级别(logn)

int lengthOfLIS(std::vector<int> &nums)
{
    if(nums.empty()) return res;

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


//Leetcode 334题 : 判断数组中是否存在连续递增的三个元素的子序列  (与第414题对比)
//假设 x < y, 判断数组中元素与x和y的关系, 初始设定 x, y 为 INT_MAX
// 1. n <= x, 则 x = n
// 2. n > x && n <= y, 则 y = n
// 3. n > y return true;
// else return false

// 注意:这里不能将x和y的初值设定为INT_MIN
// 因为当 x < y, 且初值都是INT_MIN时
// 如果 n > x, 则不明确到底将n赋值给 x 还是 y

//时间复杂度O(n), 空间复杂度O(1)
bool increasingTriplet(std::vector<int> &nums)
{
    int x = INT_MAX, y = INT_MAX;

    for(const int &n : nums) {
        if(n <= x) {            //这里要用<=,防止出现重复元素的情况
            x = n;
        } 
        else if(n > x && n <= y) {
            y = n;
        }
        else {
            return true;
        }
    }

    return false;
}


//采用上面一题的思路:维护一个三个长度的递增子序列就行
// 时间复杂度O(n), 空间复杂度O(n)
bool increasingTriplet(std::vector<int> &nums)
{
    std::vector<int> res;

    for(const int &n : nums) {
        if(res.empty() || n > res.back()) {
            res.push_back(n);
        }
        else {
            auto it = lower_bound(nums.begin(), nums.end(), n);
            *it = n;
        }

        if(res.size() == 3) return true;
    }
    
    return false;
}


//Leetcode第128题 : 求出数组中最长的连续序列(注:不是子序列,而且要求序列中元素满足方差为1)

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

// 1.将元素全部放入一个集合set中
// 2.对集合中的元素从左(自减)右(自增)两边同时开始遍历,将集合中存在的元素删除

int longestConsecutive(std::vector<int> &nums)
{
    std::unordered_set<int> mySet(nums.begin(), nums.end());

    int res = 0;

    for(const int &n : mySet)
    {
        int x = n - 1, y = n + 1;

        while(mySet.count(x)) mySet.erase(x--);
        while(mySet.count(y)) mySet.erase(y++);

        res = std::max(res, y - x - 1);
    }

    return res;
}



//第673题:最长递增子序列的个数
//动态规划,需要两个数组,一个用来记录到当前字符的最大长度,一个用来记录到当前字符的最长递增子序列的个数

// len[i]表示以第i个字符结尾的最长子序列的长度
// count[i]表示子序列长度为len[i]的子序列的个数

// 对于当前字符i,遍历前面比i小的所有元素,如果 len[j]+1 > len[i], 则 len[i] = len[j]+1, count[i] = count[j]
//                                ,如果 len[j]+1 = len[i], 则 count[i] += count[j]

int findNumbersOFLIS(std::vector<int> &nums)
{
    int n = nums.size();
    std::vector<int> len(n, 1), count(n, 1);
    int maxLen = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) 
            {
                if(len[i] < len[j] + 1) {     //更新最大长度和子序列个数
                    len[i] = len[j] + 1;
                    count[i] = count[j];
                }
                else if(len[i] == len[j] + 1) {  //累加子序列个数
                    count[i] += count[j];   //注意:这里不是加1, 比如例子{1,1,1,2,2,2,3,3,3}
                }
            }
        }
        maxLen = std::max(maxLen, len[i]);
    }

    //统计最长子序列的数量
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(maxLen == len[i]) res += count[i];
    }

    return res;
}


//Leetcode第674题:最长的连续递增子数组
//遍历的时候比较

int findLengthOfLCIS(std::vector<int> &nums)
{
    int count = 0;
    int res = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(i == 0 || nums[i] > nums[i-1]) count++;
        else count = 1;

        res = std::max(res, count);
    }

    return res;
}

//本质是利用动态规划
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





/*
    寻找数组中的重复元素

    第268题: 在不重复元素数组中找到唯一的缺失元素
    第287题: 找到数组中唯一重复的元素(不修改原始数组,这个元素可能重复多次)
    第442题: 找到数组中所有重复出现了两次的元素
    第448题: 找到数组中所有缺失的元素
    第41题 : 第一个缺失的正整数  
    第645题: 找到被替换的元素和缺失的元素
    第540题: 有序数组除了一个数重复一次外其余数字均重复了两次,找到这个只重复一次的数字(题目出的非常好)

    第137题: 数组中只有一个元素出现了一次,其余元素均出现了三次,找到这个只出现了一次的元素

    第414题: 找到数组中第三大的数(很有技巧)
*/

//Leetcode第268题 : 在不重复元素数组中找到唯一的缺失元素

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

//方法三:交换的思想
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




//Leetcode第287题: 找到数组中唯一重复的元素(不修改原始数组)

//方法一：链表找环节点的思路(时间复杂度度O(n), 空间复杂度O(1))

int findDuplicate(std::vector<int> &nums)
{
    //slow和fast表示是位置(在数组中的位置)
    int slow = nums[0], fast = nums[nums[0]];

    while(slow != fast)     //这个是找到环的起点
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    int finder = 0;
    while(finder != slow)   //这个是找到重复数
    {
        finder = nums[finder];
        slow = nums[slow];
    }

    return finder;
}



// 二分的思想 时间复杂度O(nlogn),空间复杂度O(1)
// 已知数组最大元素和最小元素，在这个区间上搜索满足条件的元素
// 1.找到中间元素mid,搜索数组得到 <=mid 的元素个数count
// 2.如果count<=mid, 说明重复元素在右侧区间, left = mid + 1, 且mid不可能是重复元素
// 3.如果count>mid, 说明重复元素在左侧区间, right = mid, mid可能是重复元素

int findDuplicate(std::vector<int> &nums)
{
    int left = 1, right = nums.size() - 1;

    while(left < right)
    {
        int mid = left + ((right-left) >> 1);
        int count = 0;
        for(const int &n : nums) {
            if(n <= mid) count++;
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


//也可以这样写
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



//Leetcode第442题 : 找到数组中所有重复出现了两次的元素
//注意:看到题目所给的范围为1<=a[i]<=n就应该知道这一题要用标记法

std::vector<int> findDuplicate(std::vector<int> &nums)
{
    std::vector<int> res;

    for(int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;
        if(nums[index] < 0) {
            res.push_back(nums[i]);
            continue;                  //这个continue加不加都可
        }                              //加了这个contine能将数组中的所有重复元素都找出来
        
        nums[index] = -nums[index];
    }

    return res;
}



//Leetcode第448题 : 找到数组中缺失的所有元素
//看到题目所给的数据范围为[1,n]就知道这道题使用标记的思想

std::vector<int> findDisappearedNumbers(std::vector<int> &nums)
{
    std::vector<int> res;

    for(int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;
        if(nums[index] > 0) {
            nums[index] = -nums[index];
        }
    }

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > 0) {
            res.push_back(i+1);
        }
    }

    return res;
}


//Leetcode第287题: 找到数组中唯一重复的元素 (这种方法会修改原始数组)
//看到题目给出的数组范围为[1,n],立马想到利用标记的手法

int findDuplicate(std::vector<int> &nums)
{
    for(int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;
        if(nums[index] < 0) {
            return abs(nums[i]);
        }

        nums[index] = -nums[index];
    }

    return -1;
}



//Leetcode第41题 : 找到第一个缺失的正整数

//思路(交换):将所有的正整数放到规定的位置上
//因为如果元素不缺失,则数组应该为[1,2,3,4..,n]

int firstMissingPositive(std::vector<int> &nums)
{
    int n = nums.size();

    for(int i = 0; i < n; i++) 
    {
        //将元素全部交换到合适的位置上
        while(nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i]) {
            std::swap(nums[nums[i]-1], nums[i]);
        }
    }

    for(int i = 0; i < n; i++) {
        if(nums[i] != i+1) return i + 1;
    }

    return n + 1;
}


//Leetcode第645题 : 找到被替换的元素和缺失的元素

//方法一 : 标记的思想：分两步走
//先找到重复的数字，再找到缺失的数字

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

//方法二 : 交换元素到相应的位置
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
        if(nums[i] != i + 1) return {nums[i], i + 1};       //nums[i]即为重复的元素,i+1即为缺失的元素
    }

    return {};
}


//Leetcode第540题: 有序数组除了一个数重复一次外其余数字均重复了两次,找到这个只重复一次的数字

//暴力解:位或运算

//最优解:二分查找 

int singleNoDuplicate(std::vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;

    while(left < right)
    {
        int mid = left + ((right - left) >> 1);

        if(mid&1) {     //下标为奇数
            if(nums[mid] == nums[mid-1]) {
                left = mid + 1;
            }
            else right = mid;
        }
        else {      //下标为偶数
            if(nums[mid] == nums[mid+1]) {
                left = mid + 2;
            }
            else right = mid;
        }
    }

    return nums[left];
}


//Leetcode第414题: 找到数组中第三大的数

//思路一:定义一个集合set(set中的元素是有序的), 遍历数组将元素全部加入到set中, 加入的过程中如果set的个数大于3, 则剔除set首元素
//一直维持set中的元素个数为3, 则这样第三大的元素就是集合首元素

//注意:这里由于集合中的元素个数始终为3,则插入和删除操作insert和erase都是常量时间复杂度
//时间复杂度O(n),空间复杂度O(1)

int thridMax(std::vector<int> &nums)
{
    std::set<int> mySet;

    for(const int &n : nums)
    {
        mySet.insert(n);
        if(mySet.size() > 3) {
            mySet.erase(*mySet.begin());    //使用erase(mySet.begin())也行, 里面是元素则erase函数返回的是删除的元素个数,不是0就是1
        }                                   //                             里面是迭代器则erase函数返回的是删除后的下一个元素位置
    }

    //数组中不足三个元素则取最大值
    return mySet.size() == 3 ? *mySet.begin() : *mySet.rbegin();
}


//时间复杂度O(n),空间复杂度O(1)

// 这样更好理解,求最大的前几个数,将x,y,z赋值成 INT_MIN; 求最小的几个数,将x,y,z赋值成INT_MAX
//   x < y < z
//3. n >= x, x = n
//2. n >= y, x = y, y = n
//1. n >= z, x = y, y = z, z = n

// 注意 : x,y,z 初值不能使用INT_MIN类型,因为如果数组元素第三大元素恰好为INT_MIN
// 则此时不能确定到底存不存在第三大的数还是第三大的数就是INT_MIN
// 因为我们是根据 x 的初值是否改变来判断是否存在第三大的元素的

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


//Leetcode第137题: 数组中只有一个元素出现了一次,其余元素均出现了三次,找到这个只出现了一次的元素

// 方法一:将每个元素出现的次数用hash表存储下来,最后遍历哈希表找到这个只出现一个的元素即可
// 时间复杂度O(n), 空间复杂度O(n)

// 方法二:记录每个元素的bit位,存到bit数组中,因为其余元素出现了三次,则对数组中元素%3即得到这个出现一次的元素的bit位置
// 时间复杂度O(n), 空间复杂度O(1)

int singleNumber(std::vector<int> &nums)
{
    std::vector<int> bitSum(32, 0);

    for(int &n : nums) {
        for(int i = 0; i < 32; i++) {
            if(n&1) bitSum[i]++;
            n >>= 1;
        }
    }

    int res = 0;

    //找到出现一次的数
    for(int i = 31; i >= 0; i--) {
        res <<= 1;
        res += bitSum[i]%3;
    }

    return res;
}






//////////////////////////////
//
//      Combination问题
//      第39题 : 组合和     第40题 : 组合和(II)
//      第216题: 组合和(III)
//      第377题: 组合个数(IV)
//
/////////////////////////////


//Leetcode第39题:组合和
//思路:DFS
//时间复杂度:O(2^n)
//对于每个元素，有选和不选这两种可能，一共有n个元素，所以有2^n种可能

std::vector<std::vector<int>> res;

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
    if(target < 0) return;      //减枝

    for(int i = pos; i < nums.size(); i++) {        //如果要求不能有重复组合,下面加一行
        path.push_back(nums[i]);                    // if(i > pos && nums[i] == nums[i-1]) continue;
        dfs(nums, path, target - nums[i], i);    
        path.pop_back();
    }

} 


//Leetcode第216题:

std::vector<std::vector<int>> res;

std::vector<std::vector<int>> combinationSum3(int k, int n)
{
    std::vector<int> path;

    dfs(k, n, path, 1);

    return res;
}

void dfs(int k, int target, std::vector<int> &path, int pos)
{
    if(target == 0 && path.size() == k) {
        res.push_back(path);
        return;
    }

    if(target < 0) return;      //注意:这里一定要记得减枝

    for(int i = pos; i <= 9; i++)
    {
        path.push_back(i);
        dfs(k, target-i, path, i+1);
        path.pop_back();
    }     

}


//第377题: 这一题既可以用DFS也可以使用DP
//但是如果使用DFS很有可能会超时,因为如果target很大,数组元素很小,组合数太大

//解法一: 使用DP(无界背包问题),不太好想到此解法
//与518题Coin Change对比

int combinationSum4(std::vector<int> &nums, int target)
{
    std::vector<unsigned int> dp(target + 1, 0);     //这里使用int很有可能溢出,因为元素组合数太多,
    dp[0] = 1;                              //但是使用unsigned int到达最大值后+1会变成0,Leetcode不会提示溢出

    for(int i = 1; i <= target; i++) {
        for(const int n : nums) {
            if(i >= n) dp[i] += dp[i-n];
        }
    }

    return dp[target];
}


//解法二: DFS搜索 
//上面的解法中, i是从[1,target]中间的好多数都没有用,我们只关心能用数组中元素减去得到的数

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
        count += combinationSum4(nums, target - nums[i]);
    }

    hash[target] = count;

    return count;
}




//////////////////////////////////
//
//      Jump Game
//      第55题 :   判断是否能到达终点
//      第45题 :   计算到达终点的最小步数
//      第1306题 : 判断是否能到达元素值为0的位置
//      第1345题 : Jump Game IV (BFS)
//      第1340题 : Jump Game V  (DFS)
//      第1696题 : Jump Game VI (滑动窗口)
//
//////////////////////////////////

//Leetcode第55题 : Jump Game

// 只会有一种情况跳不过去,当前位置元素为0,且能到达的最大位置<=当前位置,则一定跳不过去

bool canJump(std::vector<int> &nums)
{
    int maxPos = 0;
    for(int i = 0; i < nums.size() - 1; i++) 
    {        
        maxPos = std::max(maxPos, i + nums[i]);

        if(maxPos <= i) return false;   //当前位置元素为0且最大位置不超过当前元素时则一定不能跳过去
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

// 将遍历过的坐标全部记录下来以免重复遍历
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

// 写法二:
bool canReach(std::vector<int> &arr, int start)
{
    if(start < 0 || start >= arr.size() || visited.count(start)) return false;

    visited.insert(start);

    if(arr[start] == 0) return true;

    return canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
}

// 写法三:
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



//Leetcode第1345题:Jump Game IV
//BFS

int minJumps(std::vector<int> &arr)
{
    int n = arr.size();
    std::unordered_map<int, std::vector<int>> indicesOfValue;
    for(int i = 0; i < arr.size(); i++) {
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
            int i = que.front();  que.pop();
            if(i == n - 1) return steps;

            std::vector<int> &next = indicesOfValue[arr[i]];    //注意这里需要传递引用
            next.push_back(i - 1); next.push_back(i + 1);

            for(int &j : next) {
                if(j >= 0 && j < n && !visited[j]) {
                    visited[j] = 1;
                    que.push(j);
                } 
            }

            next.clear();       //将map中的元素清空防止重复遍历
        }

        steps++;
    }

    return 0;
}


//Leetcode第1340题 : Jump Game V
//思路:回溯 (带记忆化的暴力搜索)

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



// Leetcode第1696题 : Jump Game VI
// 维持一个单调递减队列 (思路与第239滑动窗口的最大值非常相似)
// 利用双端队列

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

        while(!dq.empty() && nums[i] > nums[dq.back())]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    return nums[dq.back()];
}


//动态规划思路:(用动态规划会超时)
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


////////////////////////
//
//      区间调度
//  
//      第56题 ：合并区间
//      第435题：求有重叠的区间个数
//      第452题：求没有重叠的区间(也就是不算上重叠的区间,和上面的问题恰恰相反)

//
//      252,253 会议室问题
//
///////////////////////

// [start, end]

//Leetcode第56题：合并区间

//思路：对start排序(对第一个元素进行排序)

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [](const std::vector<int> &a, const std::vector<int> &b){
        return a[0] < b[0];
    });

    std::vector<std::vector<int>> res;
    res.push_back(intervals.front());

    for(int i = 1; i < intervals.size(); i++)
    {
        if(intervals[i][0] <= res.back()[1]) {          //区间相邻也需要合并，如 [1,4],[4,5] 合并成[1,5]
            //注意：也有可能是前一个区间完全包含后一个区间，所以这里需要取较大值
            res.back()[1] = std::max(rea.back()[1], intervals[i][1]);
        }
        else {
            res.push_back(intervals[i]);
        }
    }

    return res;
}


//Leetcode第435题：求有重叠的区间个数

//贪心思想:如果end越小,则留给其他区间的范围就越大
//思路：对end进行排序

int eraseOverlapInterval(std::vector<std::vector<int>> &points)
{
    if(points.size() <= 1) return 0;

    sort(points.begin(), points.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
        return a[1] < b[1];
    });

    int end = points[0][1];
    int count = 0;

    for(int i = 1; i < points.size(); i++)
    { 
        if(end > points[i][0]) count++;
        else end = points[i][1];
    }

    return count;
}


//Leetcode第452题：求没有重叠的区间个数(也就是不算上重叠的区间)

//思路：对end进行排序

int findMinArrowShots(std::vector<std::vector<int>> &points)
{
    sort(points.begin(), points.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
        return a[1] < b[1];
    })

    int end = points[0][1];
    int count = 1;

    for(int i = 1; i < points.size(); i++)
    {
        if(end < points[i][0]) {
            count++;
            end = points[i][1];
        }
    }

    return count;
}


/*
Leetcode第252题:会议室

描述:给定一个会议时间安排的数组,每个会议时间都会包含开始和结束的时间[[s1,e1],[s2,e2]....](si < ei) 判断一个人是否能够参加这里面的全部会议
如: [[0,30],[5,10],[15,20]] 输出false
    [[7,10],[2,4]] 输出true

*/

//思路:判断是否存在重叠区间即可

bool canAttendingMeetings(std::vector<std::vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
        return a[1] < b[1];
    });

    int end = intervals[i][1];

    for(int i = 1; i < intervals.size(); i++) {
        if(end > intervals[i][0]) return false;
        else end = intervals[i][1];
    }

    return true;
}


/*
Leetcode第253题(与牛客NC147题相同)

描述:给定一个会议时间安排的数组,每个会议时间都会包含开始和结束的时间[[s1,e1],[s2,e2]....](si < ei),为避免会议冲突,同时要考虑和充分利用会议资源,请计算至少需要多少间会议室
如: [[0,30],[5,10],[15,20]] 输出 2
    [[7,10],[2,4]]  输出1

*/

//思路:每个会议都要按期进行,所以首先按照会议的开始时间排序
//对于给定一个时刻,找到之前最先结束会议的时间,看看这个时间是否早于当前会议开始时间,如果早于那就不用申请新的会议室,否则需要申请新的会议室
//使用最小堆

int minMeetingRooms(std::vector<std::vector<int>> &intervals)
{
    int n = intervals.size();

    sort(intervals.begin(), intervals.end());

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    pq.push(intervals[0][1]);

    for(int i = 1; i < n; i++)
    {
        if(pq.top() <= nums[i][0]) pq.pop();
        pq.push(nums[i][1]);
    }

    return pq.size();
}




/////////////////////////////////
//
//  第149题: 一条直线上的最多的点数
//  第218题: 天际线问题
//
///////////////////////////////


//Leetcode第149题:一条直线上的最多的点数
//题目出的非常好

//思路:千万不要尝试用hash[double, int]来存储斜率,这样会有精度差错

// x和y的取值范围为[-10000,10000]
// 则mx的范围为[-20000,20000], my的范围为[0,20000]

// 假设mx的范围为[-2,2], my的范围为[0,2]
// 则要想 a*mx+b*my存在组合的唯一值
// val = (2+1)*mx + my

int gcd(int a, int b)  
{
    return b ? gcd(b, a%b) : a;
}


int maxPoints(std::vector<std::vector<int>> &points)
{
    if(points.size() <= 2) return points.size();

    int n = points.size();

    int max = 0;

    for(int i = 0; i < n; i++) 
    {
        if(max >= n - i || max > n/2) break;
        std::unordered_map<int,int> hash;

        for(int j = i + 1; j < n; j++) 
        {
            int mx = points[j][0] - points[i][0];
            int my = points[j][1] - points[i][1];
            if(mx == 0) my = 1;
            else if(my == 0) mx = 1;
            else {
                if(my < 0) {
                    mx = -mx;
                    my = -my;
                }
                int gcdXY = gcd(mx, my);
                mx /= gcdXY;
                my /= gcdXY;
            }
            
            //重点,怎么表示mx和my之间的关系,这里为什么使用20001原因见上面
            hash[mx + 20001*my]++;
        }

        for(auto item : hash) {
            max = std::max(max, item.second + 1);
        }
    }

    return max;
}


//Leetcode第218题: 天际线问题

std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>> &buildings)
{
    std::vector<std::vector<int>> ans;

    if(buildings.empty()) return ans;

    std::set<std::pair<int,int>> corner;
    std::multiset<int> height;              //注意:这里不能使用set,防止建筑物高度为 {0,2,3} {2,5,3} 这种情况
    height.insert(0);

    for(auto &bd : buildings) {
        corner.insert({bd[0], -bd[2]});     //起点的高度用负数表示
        corner.insert({bd[1], bd[2]});      //终点的高度用正数表示
    }

    std::vector<int> pre(2,0);
    for(auto &cn : corner) 
    {
        if(cn.second < 0) {
            height.insert(-cn.second);
        }
        else {
            height.erase(cn.second);
        }

        int maxH = *height.rbegin();
        if(maxH != pre[1]) {
            pre[0] = cn.first;
            pre[1] = maxH;
            ans.push_back(pre);
        }
    }

    return ans;
}



////////////////
//
//    在两个排序数组中找到第k小的数  <面试指南> P521
//    将数字转化成中文表示          <面试指南> P503
//
//////////////////

//这种方法求得上中位数是错误的
/*
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
*/


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



//数字转汉字表示

//先解决1-9之间的数字表达
std::string num1To9(int num)
{
    if(num < 1 || num > 9) return "";

    std::vector<std::string> names = {"一", "二", "三", "四", "五", "六", "七", "八", "九"};

    return names[num-1];
}


//1-99之间的表达
std::string num1To99(int num, bool hasBai)
{
    if(num < 1 || num > 99) return "";

    if(num < 10) return num1To9(num);

    int shi = num/10;
    if(shi == 1 && !hasBai) {               //如果有百位的话,比如114,则读为一百一十四
        return "十" + num1To9(num%10);      //没有百位的话,比如14,则读为十四
    }
    else {
        return num1To9(shi) + "十" + num1To9(num%10);
    }

}


//1-999之间的表达
std::string num1To999(int num)
{
    if(num < 1 || num > 999) return "";

    if(num < 100) {
        return num1To99(num, false);
    }

    std::string res = num1To9(num/100) + "百";
    int rest = num % 100;

    if(rest == 0) {
        return res;
    }
    else if(rest >= 10) {
        res += num1To99(rest, true);
    }
    else {
        res += "零" + num1To9(rest);
    }

    return res;
}


//1-9999之间的表达
std::string num1To9999(int num)
{
    if(num < 1 || num > 9999) return "";

    if(num < 1000) return num1To999(num);

    std::string res = num1To9(num/1000) + "千";
    int rest = num % 1000;

    if(rest == 0) {
        return res;
    }
    else if(rest >= 100) {
        res += num1To999(rest);
    }
    else {
        res += "零" + num1To99(rest, false);
    }

    return res;
}


std::string num1To99999999(int num)
{
    if(num < 1 || num > 99999999) return "";

    int wan = num / 10000;
    int rest = num % 10000;

    if(wan == 0) return num1To9999(rest);

    std::string res = num1To9999(wan) + "万";

    if(rest == 0) return res;
    else {
        if(rest < 1000) return res + "零" + num1To999(rest);
        else return res + num1To9999(rest);
    }

}


std::string getNumChiExp(int num)
{
    if(num == 0) return "零";

    std::string res = num < 0 ? "负" : "";
    int yi = abs(num / 100000000);
    int rest = abs((num % 100000000));

    if(yi == 0) return res + num1To99999999(rest);

    res += num1To9999(yi) + "亿";

    if(rest == 0) return res;
    else {
        if(rest < 10000000) return res + "零" + num1To99999999(rest);
        else return res + num1To99999999(rest);
    }

}

