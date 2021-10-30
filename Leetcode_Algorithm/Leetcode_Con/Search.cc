
/*
*
*   查找
*
*/


//////////////////////
//  二分查找
// 有序数组的二分查找,如果while循环的退出条件为 left <= right
// 则如果数组中不存在目标元素,则left指向第一个比target大的元素,right指向第一个比target小的元素

//  第4题  : 两个排序数组的中位数
//  第69题 : 求开平方
//  第34题 : 在数组找到给定元素的第一个和最后一个位置(第34题)
//  第378题: 在杨氏矩阵中查找第k小元素

//  第33和88: 在旋转数组中找给定元素(第33和81题)(无重复元素和有重复元素) + (剑指offer)面试题11(旋转数组的最小数字h)
//  第154题 :  旋转数组中找到最小的数

//  第162题 : 找到 Peak Element
//  第852题 : 找到山脉数组查找最大值
//  第1095题: 山脉数组查找给定值

//  第875题 :  koko吃香蕉问题            这两题很相似,都是在找左边界
//  第1011题:  货物运输问题
//  第410题 :  切割子数组最小和           (全部二分查找)
//
//  第658题 : 在有序数组中寻找最接近x的k个数字(题目出的非常好)
//
/////////////////////////



//Leetcode第4题:两个排序数组的中位数
//更好的解法：参看Youtube
//时间复杂度O(log(min(n,m)))

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
        int minRightX = (i == m ? INT_MAX : nums1[i]);      //注意：这是判断在nums1数组中的位置

        int maxLeftY = (j == 0 ? INT_MIN : nums2[j-1]);
        int minRightY = (j == n ? INT_MAX : nums2[j]);      //注意：这是判断在nums2数组中的位置

        if(maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if((m+n)%2 == 0) return (std::max(maxLeftX, maxLeftY) + std::min(minRightX, minRightY)) / 2.0;
            else return std::max(maxLeftX, maxLeftY);
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



//第69题:　求开平方

//方法一：二分

int mySqrt(int x) 
{
    if(x <= 0) return 0;    // 这里处理一下边界情况是否为0,如果为0则下面的 x/mid 可能除0异常

    int left = 1, right = x;    // 这里left不能设置成0

    while(left <= right)
    {
        int mid = left + ((right-left) >> 1);
        if(mid == x/mid) {                       //这样写是为了防止 mid*mid 溢出
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

//方法二：牛顿迭代法
// f(x) = x^2 - n
int mySqrt(int n)
{
    long x = n;
    while(x*x > n) {
        x = (x + n/x)/2;
    }

    return x;
}



//第34题: 找到给定元素的第一次和最后一次出现的位置

//方法一:
std::vector<int> searchReange(std::vector<int> &nums, int target)
{
    int first = leftBound(nums, target);
    int second = rightBound(nums, target);

    return {first, second};
}


//1.找到左侧区间的二分查找

// 思路:二分
// 1.当nums[mid] < target时, left右移动
// 2.当nums[mid] > target时, right左移动
// 3.当nums[mid] = target时, 由于是找左侧区间, 则缩小右边界(right左移)

// base case : 最后的退出条件为 left = right + 1, 
// 1.首先需要判断left是否等于size, 等于size就表明left出界了,数组中的所有数都小于target
// 2.没有出界,也需要判断nums[left]是否等于target, 数组中未必存在这样的元素

int left_bound(std::vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while(left <= right)
    {
        int mid = left + ((right-left) >> 1);
        if(nums[mid] == target) {
            right = mid - 1;
        }
        else if(nums[mid] < target){
            left = mid + 1;
        }
        else if(nums[mid] > target) {
            right = mid - 1;
        }
    }

    if(left == num.size() || nums[left] != target) return -1;

    return left;
}

//2.找到右侧区间的二分查找

int right_bound(std::vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if(nums[mid] == target) {
            left = mid + 1;
        }
        else if(nums[mid] < target) {
            left = mid + 1;
        }
        else if(nums[mid] > target) {
            right = mid - 1;
        }
    }

    if(right == -1 || nums[right] != target) return -1;

    return right;
}


//方法二:利用自带的lower_bound和upper_bound函数
std::vector<int> searchReange(std::vector<int> &nums, int target)
{
    int first;
    auto itFirst = lower_bound(nums.begin(), nums.end(), target);
    if(itFirst == nums.end() || *itFirst != target) first = -1;
    else first = itFirst - nums.begin();

    int second;
    auto itSecond = upper_bound(nums.begin(), nums.end(), target);
    if(itSecond == nums.begin()) second = -1;           //数组元素都大于target
    else if(*(--itSecond) != target) second = -1;       //数组元素都小于targett或者数组中元素不存在target
    else {
        second = itSecond - nums.begin();
    }

    return {first, second};
}


//Leetcode第378题:杨氏矩阵中第k小的元素
// 二分查找寻找左边界
// 时间复杂度O(nlog(max-min)),整个while循环的时间复杂度为log(max-min),循环里面的寻找小于mid的元素个数时间复杂度
// 最差情况下查找的数比矩阵里面的元素都大，则里面的upper_bound函数需要执行 nlog(n)次，时间复杂度一共为 nlog(n) * log(max-min)

int kthSmallest(std::vector<std::vector<int>> &matrix, int k)
{
    if(matrix.empty()) return -1;

    int n = matrix.size();
    int left = matrix[0][0], right = matrix[n-1][n-1];

    while(left <= right)
    {
        int mid = left + ((right-left) >> 1);
        int count = 0;
        for(int i = 0; i < n; i++) {    //upper_bound找到的是第一个大于mid的元素,则下面的count计算的就是数组中 <=mid 的元素总个数
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if(count < k) {
            left = mid + 1;     //向右扩大边界
        }
        else if(count >= k) {
            right = mid - 1;    //向左缩小边界
        }

    }
    
    return left;
}




//Leetcode第33题: 旋转数组中查找目标元素

// 思路: 二分查找
// 0.判断nums[mid]是否等于target, 等于直接返回mid
// 1.当 nums[mid] 小于 nums[right] 时, 就表明右侧[mid, right]之间是有序的, 如果 nums[mid] < target < nums[right], 则left右移, 否则right左移
// 2.当 nums[mid] 大于 nums[right] 时, 就表明左侧[left, mid]之间是有序的, 如果 nums[left] < tartet < nums[mid], 则right左移, 否则left右移

// 3.当 nums[mid] 等于 nums[right]移动哪一侧都行(因为数组不存在重复元素,所以当且仅当 mid = right时会出现这种情况,也就是数组中不存在target)
// 如 nums = {1}, target = 2

// Leetcode第81题: 有重复元素的数组中查找目标元素
// 增加一个判断,当nums[mid] == nums[right]时,分不清是前半部分有序还是后半部分有序,直接将right--, 相当于去除掉了一个重复项

int search(std::vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);

        if(nums[mid] == target) return mid;
        
        //左边数组是有序的
        else if(nums[mid] >= nums[right]) {     //注意:这个等于号放在哪一侧都行,因为存在可能数组中不存在目标,则最后left和right肯定会指向同一个元素,不加上这个'='就是死循环
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

//Leetcode第153题 : 旋转数组中寻找最小值(不含有重复元素)
//Leetcode第154题 : 旋转数组中寻找最小值(含有重复元素)

// 二分:
// 1.nums[mid] < nums[right], right = mid
// 2.nums[mid] > nums[right], left = mid + 1
// 3.nums[mid] = nums[right], 相等则缩小右边界.right--

int findMin(std::vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;

    while(left < right)
    {
        int mid = left + ((right-left) >> 1);

        if(nums[mid] > nums[right]) {
            left = mid + 1;
        }
        else if(nums[mid] < nums[right]) {
            right = mid;
        }
        else if(nums[mid] == nums[right]) {     //如果相等了,则缩小右边界
            right--;
        }
    }

    return nums[left];
}


//Leetcode第875题 : Koko吃香蕉问题

//二分查找(本质是二分查找寻找左边界)
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
        time += n/speed + (n%speed ? 1 : 0);
    }

    return time <= h;
}



//第1011题: 船只运输的最小装载量

int shipWithinDays(std::vector<int> &weight, int D)
{
    int maxVal = 0, sum = 0;
    for(const int &n : weight) {
        maxVal = std::max(maxVal, n);
        sum += n;
    }

    int left = maxVal, right = sum;

    while(left <= right)
    {
        int mid = left + ((right-left) >> 1);

        if(canFinish(weights, mid, D)) {
            right = mid - 1;
        }
        else left = mid + 1;
    }

    return left;
}

//关键在于这个判断
//这个判断只能判断在days天内以速度speed运输是否能运输完成
//如 weights = {1,2,3,1,1} days = 4
// 分三天运输 {1,2} {3} {1,1}   最少只需三天就可运输完成
// 也可以分四天运输, 如 {1,2} {3}, {1} {1}

bool canFinish(std::vector<int> &weights, int speed, int days)
{
    int i = 0;
    for(int d = 0; d < days; d++)
    {
        int maxCap = speed;
        while((maxCap -= weights[i]) >= 0) {        //由于"-="的优先级比 ">="小,所以这里一定要加括号
            i++;
            if(i == weights.size()) return true;
        }
    }

    return false;
}


//第410题: 求最小的切割子数组和
//思路:最小的满足要求的子数组和为数组中单个元素的最大值,最大的满足要求的子数组的和为数组元素总和
//在这个范围内寻找满足条件m的最小的值

int splitArray(std::vector<int> &nums, int m)
{
    int maxVal = 0, sum = 0;

    for(const int &n : nums) {
        maxVal = std::max(maxVal, n);
        sum += n;
    }

    int left = maxVal, right = sum;

    while(left <= right)
    {
        int mid = left + ((right-left) >> 1);

        if(isValid(nums, mid, m)) {
            right = mid - 1;
        }
        else left = mid + 1;
    }

    return left;
}

//关键在于这个判断
bool isValid(std::vector<int> &nums, int target, int m)
{
    int sum = 0;
    int count = 1;  //(易错)这个默认的值需要为1,因为至少需要一个子数组

    for(const int &n : nums) {
        sum += n;
        if(sum > target) {   //大于目标值则肯定还需要一个子数组
            sum = n;
            if(++count > n) return false;   //判断需要的子数组数是否大于给定的m
        }
    }

    return true;
}



//Leetcode第162题 : 找到 Peak Element(数组并非有序)

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



//第1539题: 第k个缺失的正整数(数组是有序的)
//可与第41题对比(该题给出的数组没有排好序)



//Leetcode第658题：在有序数组中寻找最接近x的k个数字

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


// 解法二： 二分查找 + 滑动窗口
// [0, n-k]之内查找，之后比较 A[mid] 和 A[mid+k]与 x 的差距

//          A[mid]     A[mid+k]
// 1.  x                           此时右边界左移  x - A[mid] < A[mid+k] - x
// 2.             x                此时右边界左移  x - A[mid] < A[mid+k] - x
// 3.                 x            此时左边界右移  x - A[mid] > A[mid+k] - x
// 4.                          x   此时左边界右移  x - A[mid] > A[mid+k] - x


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





//////////////////////////////////
//
//   在数组中查找等于指定目标的元素和

//     第1题 : 两数相加(数组无序)
//   第167题 : 两数之和(数组有序)

//   第653题 : 两数之和(输入为一个BST)
//   第15题  : 三数之和 
//   第16题  : 最接近目标的三数之和
//   第18题  : 四数之和
//
/////////////////////////////////

//Leetcode第1题:两数之和 
//哈希

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::unordered_map<int,int> hash;

    for(int i = 0; i < nums.size(); i++) {
        if(hash.count[target-hash[i]]) {        //不要使用hash[target-nums[i]]来判断元素是否存在,因为下标可能为0
            return {i, hash[target-nums[i]]};
        }
        else {
            hash[nums[i]] = i;
        }
    }

    return {};
}


//Leetcode第167题 : 两数之和(数组有序)

//方法一 : 二分查找,固定一个, 找到另外一个(利用二分查找)

//时间: O(nlogn), 空间 : O(1)

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    for(int i = 0; i < nums.size(); i++)
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

//方法二 : 双指针
//时间: O(n), 空间: O(1)

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    int i = 0, j = nums.size() - 1;

    while(i < j)
    {
        int sum = nums[i] + nums[j];

        if(sum == target) {
            return {i + 1, j + 1};
        }
        else if(sum < target) {
            i++;
        }
        else if(sum > target) {
            j--;
        }
    }

    return {};
}


//Leetcode第653题:两数之和(输入数组是一个BST)

//方法一:暴力搜索(每个节点都搜索,同样适用于不是BST的情形)
//哈希存储每个遍历过的节点
//递归遍历每个节点只需要遍历一次,所以时间复杂度为O(n)
//最差情况下的递归调用的深度为O(n),所以空间复杂度为O(n)

std::unordered_set<int> mySet;

bool findTarget(TreeNode *root, int k)
{
    if(root == nullptr) return false;

    if(mySet.count(k - root->val)) return true;
    
    mySet.insert(root->val);

    return findTarget(root->left, k) || findTarget(root->right, k);
}


//方法二:利用二叉树中序遍历为一个有序序列,求出这个有序序列后利用双指针查找
//时间复杂度O(n),空间复杂度O(n)

bool findTarget(TreeNode *root, int k)
{
    std::vector<int> nums = inorderTraversal(root);

    int left = 0, right = nums.size() - 1;
    while(left < right)
    {
        if(nums[left] + nums[right] == k) return true;
        else if(nums[left] + nums[right] < k) left++;
        else if(nums[left] + nums[right] > k) right--;
    }

    return false;
}

std::vector<int> inorderTraversal(TreeNode *root)
{
    std::vector<int> res;
    std::stack<TreeNode*> sta;
    TreeNode *pNode = root;

    while(pNode || !sta.empty())
    {
        while(pNode) {
            sta.push(pNode);
            pNode = pNode->left;
        }

        pNode = sta.top();
        sta.pop();
        res.push_back(pNode->val);

        pNode = pNode->right;
    }

    return res;
}


//方法三:利用BST的性质
//时间复杂度O(nh),空间复杂度O(h),h为二叉树的深度
//固定一个节点,搜索另一个节点

bool findTarget(TreeNode *root, int k)
{
    return dfs(root, root, k);
}

bool dfs(TreeNode *root, TreeNode *cur, int k)
{
    if(cur == nullptr) return false;
    return search(root, cur, k - cur->val) || dfs(root, cur->left, k) || dfs(root, cur->right, k);
}

//固定cur,搜索从root开始
bool search(TreeNode *root, TreeNode *cur, int value)
{
    if(root == nullptr) return false;

    return (root->val == value) && (root != cur) 
            || (root->val < value) && search(root->right, cur, value) 
            || (root->val > value) && search(root->left, cur, value);
}


//Leetcode第15题:三数之和
//时间复杂度O(n^2)

std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    std::vector<std::vector<int>> res;
    if(nums.size() < 3) return res;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size() - 2; i++)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        
        if(nums[i] + nums[i+1] + nums[i+2] > 0) return res;     //真实面试中这个 return res 最好写成 break语句(不会出错)
        if(nums[i] + nums[n-1] + nums[n-2] < 0) continue; 
                
        int left = i + 1, right = nums.size() - 1;

        while(left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if(sum == 0) {
                res.push_back({nums[i], nums[left], nums[right]});
                while(left < right && nums[left] == nums[left+1]) left++;
                while(left < right && nums[right] == nums[right-1]) right--;
                left++;
                right--;
            }
            else if(sum < 0) {
                left++;
            }
            else if(sum > 0) {
                right--;
            }
        }
    }

    return res;
}


//Leetcode第16题:上一题的改编版(找到三个数的和使其最接近目标)
//固定一个,搜索另外两个

int threeSumCloset(std::vector<int> &nums, int target)
{
    int res = 0, diff = INT_MAX;    //diff表示与目标target的差值

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size() - 2; i++)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue;     //避免重复的数遍历

        int left = i + 1, right = nums.size() - 1;

        while(left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if(abs(sum - target) < diff) {
                diff = abs(sum - target);       //记录最小的绝对值差
                res = sum;
                if(diff == 0) return res;       //如果绝对值等于0,则说明sum等于target,直接返回sum即可
            }

            if(sum < target) left++;
            else if(sum > target) right--;
        }
    }

    return res;
}

//Leetcode第18题:四数之和
//时间复杂度O(n^3)
//固定两个,寻找另外两个

std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
{
    std::vector<std::vector<int>> res;
    int n = nums.size();

    if(n < 4) return res;

    sort(nums.begin(), nums.end());

    //固定第一个元素(注意第一个元素的范围,否则下面容易溢出)
    for(int i = 0; i < n - 3; i++)
    {
        //排除重复的元素
        if(i > 0 && nums[i] == nums[i-1]) continue;
        
        int minSum = nums[i] + nums[i+1] + nums[i+2] + nums[i+3];   
        if(minSum > target) break;              //后面元素都是递增的,当前元素的最小和都大于target, 则后面的元素和肯定也都大于taregt

        int maxSum = nums[i] + nums[n-1] + nums[n-2] + nums[n-3];
        if(maxSum < target) continue;          //当前元素的最大和都小于target,那以这个元素开头的序列没有满足条件的子数组,所以继续下一个判断

        //固定第二个元素(注意范围,否则下面会溢出)
        for(int j = i + 1; j < n - 2; j++)
        {
            if(j > i+1 && nums[j] == nums[j-1]) continue;

            // 这里也判断一下加快速度
            int min4Sum = nums[i] + nums[j] + nums[j+1] + nums[j+2];
            if(min4Sum > target) break;

            int max4Sum = nums[i] + nums[j] + nums[n-1] + nums[n-2];
            if(max4Sum < target) continue;

            int left = j + 1, right = n - 1;
            while(left < right)
            {
                int fourSum = nums[i] + nums[j] + nums[left] + nums[right];

                if(fourSum == target) {
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
                else if(fourSum < target) {
                    left++;
                }
                else if(fourSum > target) {
                    right--;
                }
            }
        }
    }

    return res;
}

