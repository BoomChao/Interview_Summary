
/*
*
*   前缀和题型汇总

*   第560题: 一维数组中等于目标和的子数组的个数 (第930题与该题思路完全相同)
*  第1248题: 优美子数组的数量
*   第974题: 可被k整除的子数组的个数
*  第1074题: 二维数组中等于目标和的子数组的个数
*   第523题: 判断数组中是否存在连续子数组的和等于k的整数倍,且这个连续子数组的个数必须>=2

*/

//将前缀和和前缀和出现的次数存放到map中即可


//Leetcode第560题 : 数组中等于k的连续子数组的个数

//时间复杂度O(n^2),空间复杂度为O(n)
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

// 优化,使用哈希表,记录该前缀和出现的次数
// 遍历的过程记录前缀和,用哈希表记录当前和的个数,之后判断k-num在哈希表的value
// 当遍历到位置i时,假设当前前缀和为psum, 则hash[psum-k]就是以当前位置结尾,和为k的子数组个数
// 时间复杂度O(n)

int subarraySum(std::vector<int> &nums, int k)
{
    int count = 0, preSum = 0;
    std::unordered_map<int, int> hash;
    hash[0] = 1;

    for(const int &n : nums) {
        preSum += n;
        count += hash[preSum-k];        //注意:不要减反了,这是前缀和减去target
        hash[preSum]++;
    }

    return count;
}



//Leetcode第1248题: 统计优美子数组的数量
//哈希表hash[i]表示数组中奇数个数为i时的子数组数量

int numberOfSubarrays(std::vector<int> &nums, int k)
{
    std::unordered_map<int,int> hash;
    hash[0] = 1;

    int oddNum = 0, count = 0;
    for(const int &n : nums)
    {
        if(n&1) oddNum++;
        count += hash[oddNum-k];
        hash[oddNum]++;         //子数组以当前元素n结尾,并且子数组中奇数个数为oddNum的子数组元素个数
    }    

    return count;
}



//上一题的升级版
//第1074题: 在二维数组中寻找等于target的子数组的数目
//当成一维数组来处理

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


//Leetcode第974题 : 和可被k整除的子数组的个数
//思路很巧：好好推敲

int subarraysDivByK(std::vector<int> &A, int K)
{
    //哈希表里存储的是前缀和被k整数得到的余数出现的次数,比如hash[3]=2,就代表一共有两个子数组的和被Ｋ整除得到的余数是3
    std::unordered_map<int,int> hash;   
    hash[0] = 1;

    int preSum = 0, count = 0;

    for(const int &n : A) {
        preSum += n;
        int key = (preSum%K + K)%K;     //细节,对负数需要转换一下(这一步操作很关键)
        count += hash[key];
        hash[key]++;
    }

    return count;
}


//Leetcode第523题:判断数组中是否存在连续子数组的和等于k的整数倍,且这个连续子数组的个数必须>=2
//和上一题思路相同

bool checkSubarraySum(std::vector<int> &nums, int k)
{
    std::unordered_map<int, int> hash;
    hash[0] = -1;       //细节1, 现在hash里面保存的是取余后数组下标
    
    int preSum = 0;
    for(int i = 0; i < nums.size(); i++) 
    {
        preSum += nums[i];
        int key = (k == 0) ? preSum : preSum%k;     //细节2(防止k为0的情况)

        if(hash.count(key)) {
            if(i - hash[key] >= 2) return true;   // (] 左开右闭,所以当元素个数>=2时就代表里面存在两个可以取值的元素了,满足条件
            else continue;                        //细节3, 让hash[key]存储的是key值最小的下标
        }

        hash[key] = i;
    }

    return false;
}


// Leetcode第724题：找到枢纽下标
// 思路：前缀和思想

int pivot(std::vector<int> &nums)
{
    int total = accumulate(nums.begin(), nums.end(), 0);

    int sum = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(total - nums[i] = 2*sum) return i;       //sum相加之前提前判断一下
        sum += nums[i];
    }

    return -1;
}


// Leetcode第554题: 砖墙
// 思路:前缀和思想

int leastBricks(std::vector<std::vector<int>> &wall)
{
    std::unordered_map<int,int> mp;

    for(int i = 0; i < wall.size(); i++)
    {
        if(wall[i].size() == 1) continue;
        
        mp[wall[i][0]]++;                               //起点
        for(int j = 1; j < wall[i].size()-1; j++) {     //注:最后一个数值不能相加
            wall[i][j] += wall[i][j-1];
            mp[wall[i][j]]++;
        }
    }

    int maxVal = 0;
    for(auto &item : mp) {
        maxVal = std::max(maxValm, item.second);
    }

    return wall.size() - maxVal;
}




