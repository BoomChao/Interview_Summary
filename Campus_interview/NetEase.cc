
/*
    设计一个公平的扑克牌洗牌程序
*/

#include <iostream>
#include <vector>

void shuffle(std::vector<int> &nums);

int main() {
    std::vector<int> nums = {1,2,3,4,5,6,7,8};

    shuffle(nums);

    return 0;
}


void shuffle(std::vector<int> &nums)
{
    srand(time(0));

    for(int i = nums.size() - 1; i > 0; i--) {
        int j = random() % (i+1);    // 生成一个下标范围为[0,i]的随机数
        std::swap(nums[i], nums[j]);
    }

    for(int &num : nums) {
        std::cout << num << " ";
    }

    std::cout << std::endl;
}


/*
    给定一个等概率生成0-4的随机数生成器,用这个生成器实现等概率生成0-6
*/

int rand4() 
{
    return rand()%5;    //生成[0,4]之间的随机数
}

int rand6()
{
    /*
    while(1)
    {
        int num = 5*rand4() + rand4();
        if(num < 21) {
            return num%7;
        }
    }
    */      
    //写成上面或者下面这种都可以

    int num = 5*rand4() + rand4();

    while(num > 20)
    {
        num = 5*rand4() + rand4();
    }

    return num%7;
}


/*
    rand5生成rand7
*/

//生成1~5之间的随机数
int rand5() 
{
    return rand()%5 + 1;
}

int rand7()
{
    //必须乘以5这样能够保证所有数出现的概率是相同的
    int result = 5*(rand5()-1) + rand5();     //result的范围为[1,25],这里面的数出现的概率都是相同的,去除掉22-25

    //或者写成这样, int result = INT_MAX;

    while(result > 21) {
        result = 5*(rand5()-1) + rand5();
    }

    return result%7 + 1;
}


/*
    Leetcode第253题:会议室(必须要会)
    参看Leetcode题型总结
*/



/*
    连续子数组和为k的最大长度
    如:{3,4,1,7,8},和为15的最长子数组为{3,4,1,7}

    附:给定一个字符串,由字符"0"和"1"组成,找到含有相同数量的"0"和"1"的最长子串的长度;
    如:输入"01001001",输出4,满足要求的最长子串为 "1001"
    思路:将字符串的'0'换成-1则等价于求和为0的最长子串
*/

int findMaxLength(std::vector<int> &nums, int target)
{
    std::unordered_map<int,int> hash;
    hash[0] = -1;

    int n = nums.size();
    int res = 0;
    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += nums[i];
        if(hash.count(sum-target)) res = std::max(res, i - hash[sum-target]);
        hash[sum] = i;
    } 

    return res == 0 ? -1 : res;
}


//附加题
int findMaxLength(const std::string &str)
{
    std::unordered_map<int,int> hash;
    hash[0] = -1;

    int n = str.size();
    int res = 0;
    int sum = 0;

    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '0') sum += -1;
        else if(str[i] == '1') sum += 1;

        if(hash.count(sum)) res = std::max(res, i - hash[sum]);
        else hash[sum] = i;     //注意:只有当sum不存在的时候才更新,因为求的是最长的长度
    }

    return res;
}