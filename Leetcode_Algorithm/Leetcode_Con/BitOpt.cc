
/*
*
*   位运算
*   (136题)数组中有一个元素只出现一次,其余元素出现了两次,求这个出现一次的元素
*   (260题)数组中有两个元素只出现了一次,其余元素都出现了两次,找出这两个只出现一次的元素
*   (137题)数组中有一个元素出现了1次,其余元素都出现了三次,求这个只出现一次的元素
*   (461题)计算两个数有多少位不同
*   (190题)翻转比特
*   (318题)求出任意两个字符串乘积的最大值(这两个字符串不能含有相同字符) (一个很简单的布隆过滤器)
*   (338题)给定一个数n,计算从0~n的各个数每个数有多少个位为1
*   (201题)求两个正整数之间的所有数的与操作的和

*   第371题: 不用加减乘除做加法

*   第600题: 计算(1,n)之间存在多少个数的二进制表示没有连续的1存在

*/

//注意:对移位运算符,左移高位舍弃,低位补0;   右移高位补符号位,低位舍弃


//Leetcode第260题:数组中有两个数只出现了一次,其余元素都出现了两次,找出这两个只出现一次的元素

//解法一:
//时间复杂度为O(n),空间复杂度为O(1)


//解法二:
//使用哈希表存储每个元素出现的次数
//时间复杂度为O(n),空间复杂度为O(n)

std::vector<int> singleNumber(std::vector<int> &nums)
{
    long diff = 0;              //不用long可能会溢出
    for(const int &n : nums) {
        diff ^= n;
    }

    diff &= (-diff);

    std::vector<int> res = {0,0};

    for(const int &n : nums) {
        if(diff&n) res[0] ^= n;
        else res[1] ^= n;
    }

    return res;
}



//Leetcode第137题: 数组中有一个元素出现了1次,其余元素都出现了三次,求这个只出现一次的元素
//该方法如何nums的元素个数为多少,都只需要一个长度为32的辅助数组
//所以时间复杂度为O(n),空间复杂度为O(1)

int singleNumber(std::vector<int> &nums)
{
    std::vector<int> bitCount(32, 0);

    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = 31; j >= 0; j--)
        {
            int bit = nums[i] & 1;
            if(bit != 0) {
                bitCount[j]++;
            }
            nums[i] >>= 1;
        }
    }

    int res = 0;
    for(int i = 0; i < 32; i++) {
        res <<= 1;
        res += bitCount[i];
    }

    return res;
}

//利用哈希表存储每个元素出现的次数
//时间复杂度为O(n),空间复杂度为O(n)

int singleNumber(std::vector<int> &nums)
{
    std::unordered_map<int,int> hash;
    int res;

    for(int n : nums) {
        if(hash[n] == 0) {
            hash[n] = 1;
        }
        else {
            hash[n]++;
        }
    }

    for(int num : nums) {
        if(hash[num] == 1) {
            res = num;
            break;
        }
    }

    return res;
}


//Leetcode第461题:计算两个数有多少位不同
//思路:做异或运算,统计1的个数

int hammingDistance(int x, int y)
{
    int n = x^y;

    int count = 0;
    while(n) {
        count++;
        n &= (n-1);
    }

    return count;
}


//Leetcode第190题:翻转比特

uint32_t reverseBits(uint32_t n)
{
    uint32_t ans = 0;
    for(int i = 0; i < 32; i++) {
        ans <<= 1;
        ans += (n&1);
        n >>= 1;
    }

    return ans;
}




//Leetcode第318题: 求出两个字符串乘积的最大值(这两个字符串不能含有相同字符)
//思路:为每个字符串建一个长度为26的二进制数字代表该字符串中各字符出现的位置

//一个简单的布隆过滤器(题目出的非常好)

int maxProduct(std::vector<std::string> &words)
{
    std::vector<int> mask(words.size(), 0);
    int res = 0;

    for(int i = 0; i < words.size(); i++)
    {
        for(const char &c : words[i]) {
            mask[i] |= (1<<(c-'a'));        //位或运算,记录每个字符出现的位置
        }

        for(int j = 0; j < i; j++) {
            if((mask[i] & mask[j]) == 0)) {     //注意:"=="运算符优先级比"&"优先级高,这个()一定要加
                res = std::max(res, (int)(words[i].size() * words[j].size()));  //.size()返回类型是无符号整形,max函数要求两个参数的类型必须相同
            }
        }
    }

    return res;
}


//Leetcode第338题:给定一个数n,计算从0~n的各个数每个数有多少个位为1
//思路:动态规划
//dp[i]代表数i有几个位上值为1
//数i为[0,n],如果i的末尾为1,则dp[i] = dp[i-1]+1
//如果i的末尾为0,则其1的个数与其右移一位得到的数的个数相同 dp[i] = dp[i>>1]

std::vector<int> countBits(int num)
{
    std::vector<int> dp(num, 0);

    for(int i = 1; i <= num; i++) {
        dp[i] = (i&1) ? dp[i-1]+1 : dp[i>>1];
    }

    return dp;
}


//Leetcode第201题 : 求两个正整数之间的所有数的与操作的和
//思路:求出m和n的高位比特的公共部分

//删除n后面的不同部分

int rangeBitwiseAnd(int m, int n)
{
    while(m < n) {
        n &= (n-1);
    }

    return n;
}


//Leetcode第371题: 不用加减乘除做加法
//唯一一道适合使用 do while 循环的题目

int getSum(int a, int b)
{
    int sum, carry;

    do {
        sum = a^b;
        carry = (unsigned int)(a&b)<<1;       //带符号数int如果是负数，并<<，则符号位超出范围，结果是未定义的，转化成无符号数unsigned int 超出则抛弃
        a = sum;            
        b = carry;
    } while(carry != 0);

    return a;
}




/*

*   第1178题: 计算Puzzle对应的有效的单词数
*   第1286题: Iterator for Combation

*/

//Leetcode第1178题:每个Puzzle对应的有效单词数量

std::vector<int> findNumOfValidWords(std::vector<std::string> &words, std::vector<std::string> &puzzles)
{
    std::unordered_map<int,int> mp;

    for(auto &word : words) {
        int mask = 0;
        for(const char &c : word) {
            mask |= 1 << (c-'a');
        }
        mp[mask]++;     //使用bit记录每个单词
    }

    std::vector<int> res;

    for(auto &str : puzzles)
    {
        int mask = 0;
        for(const char &c : str) {
            mask |= 1 << (c - 'a');
        }

        int c = 0;
        int sub = mask;
        int first = 1 << (str.front() - 'a');

        while(1) {
            if((sub & first) == first && mp.count(sub)) {   //判断单词首字母是否在puzzle里面
                c += mp[sub];
            }
            if(sub == 0) break;         //点睛之笔
            sub = (sub - 1) & mask;     //继续找下一个与mask有相同字符的字符串(所以这里要与mask做一个按位与运算)
        }

        res.push_back(c);
    }

    return res;
}


//第1286题：设计一个迭代器,判断有序字符串的输出

class CombationIterator {
    
    std::set<std::string> generateAllCombination(std::string s, int len) 
    {
        int mask = 1 << s.size();
        std::set<std::string> mySet;
        std::string comStr;

        for(int no = 1; no < mask; no++)
        {
            int num = no, i = 0;
            while(num) {
                if(num & 1) comStr = comStr + s[i];
                i++, num >>= 1;
            }

            if(comStr.size() == len) mySet.insert(comStr);
            comStr = "";
        }

        return mySet;
    }


public:

    std::set<std::string> mySet;
    std::set<std::string>::iterator cur;

    CombationIterator(std::string characters, int combinationLength) {
        mySet = generateAllCombination(characters, combinationLength);
        cur = mySet.begin();
    }

    std::string next() {
        return *cur++;
    }

    bool hasNext() {
        return cur != mySet.end();
    }

};


