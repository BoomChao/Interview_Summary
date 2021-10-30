
/*
*
*   数学问题的解法
*
*/


//计算阶乘C(m+n, n)
int C(int m, int n)
{
    long long res = 1;
    for(int i = 1; i <= n; i++) {
        res = res*(i + m)/i;        //注意:这里千万不能写成 res *= (i+m)/i,这样会先计算右边的数值,不能保证右边都是整除
    }

    return res;
}



// Leetcode第204题:数质数
// 埃式筛法
// 先把素数2的倍数全部删除
// 再把素数3的倍数全部删除
// 再把素数5的倍数全部删除...
// 也就是i先从2开始，再从3开始,再从4开始(由于4是2的倍数，已经被删除了)，那就从5开始筛


int countPrimes(int n)
{
    if(n < 2) return 0;
    
    std::vector<int> prime(n, 1);
    int count = n - 2;  //除去不是质数的1

    for(int i = 2; i*i < n; i++) 
    {
        if(prime[i]) {
            for(int j = i*i; j < n; j += i) {       //这里为什么可以从i*i开始，比如n=25,i=4时会标记4x2=8,4x3=12等数字,但是这些数字在i=2和i=3已经被2x4和3x4标记过了
                if(prime[j]) {
                    prime[j] = 0;
                    count--;
                }
            }
        }
    }

    return count;
}


// Leetcode第172题: 判断一个非负整数的阶乘有几个0
// 只有可能2*5相乘才会得到0,只要是偶数就可分解出2,所以只需要关心5的倍数即可

int trailingZeros(int n) {
    return n ? n/5 + trailingZeros(n/5) : 0;
}

int trailingZeros(int n)
{
    int count = 0;

    while(n >= 5) {
        count += n/5;
        n /= 5;
    }

    return count;
}



//Leetcode第202题: 快乐数

//解法一:将经历过的数都记录下来

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


//解法二:按照快乐数的计算逻辑,则一个走快,一个走慢,最后一定会相遇
//判断相遇的数是否等于1即可
//如果是快乐数,则最后快慢指针指向的数一定是1
//如果不是快乐数,则快慢指针也一定会相遇,因为这时会存在环

int next(int n) 
{
    int sum = 0;
    while(n) {
        sum += (int)pow(n%10, 2);
        n /= 10;
    }

    return sum;
}

bool isHappy(int n)
{
    int slow = next(n), fast = next(next(n));

    while(slow != fast) {
        slow = next(slow);
        fast = next(next(fast));
    }

    return slow == 1;
}





////////////////////////////
//
//       进制转换
//       504题: 十进制转换7进制
//       405题: 十进制转换16进制
// 168题和171题: Excel转换
//
////////////////////////////

//Leetcode第504题: 十进制转换7进制

std::string convertToBase7(int num)
{
    if(num == 0) return "0";

    std::string res;

    bool isMinus = false;
    if(num < 0) {
        isMinus = true;
        num = -num;
    }

    while(num) {
        res = std::to_string(num%7) + res;
        num /= 7;
    }

    return isMinus ? "-" + res ? res;
}


//Leetcode第405题: 十进制转换成16进制
//四位二进制等于一位16进制

std::string toHex(int num)
{
    if(num == 0) return "0";

    std::string str = "0123456789abcdef";

    std::string res;
    int count = 0;
    while(num && count++ < 8) {     //这里必须加count++ < 8,因为负数右移高位是补符号位
        res = str[num&0xf] + res;
        num >>= 4;
    }

    return res;
}


//Leetcode第168题: 数字转换成Excel表字母

std::string convertToTitle(int n)
{
    std::string res;

    while(n) {
        res = (char)((n-1)%26 + 'A') + res;
        n = (n-1)/26;
    }

    return res;
}


//Leetcode第171题: Excel表字母转换成数字

int titleToNumber(std::string s)
{
    int res = 0;
    
    for(int i = 0; i < s.size(); i++) {
        res = res*26 + (s[i]-'A'+1);
    }

    return res;
}



////////////////////////
//
//      判断是否整数次方
//      第231题: 判断是否为2的n次方
//      第342题: 判断是否为4的n次方
//
/////////////////////////

//Leetcode第231题: 判断是否为2的n次方

bool isPowerOfTwo(int n)
{
    return (n > 0) && !(n&(n-1));       //如果时2的n次方,则写成二进制的形式只有一个bit位为1
}


//Leetcode第342题:判断是否为4的整数次方

bool isPowerOfFour(int n)
{
    return (n > 0) && !(n&(n-1)) && (n&(0x55555555));   //限制该唯一的bit位出现的位置为 0101 这两个位置
}


//Leetcode第326题: 判断是否为3的整数次方

bool isPowerOfthree(int n)
{
    if(n <= 0) return false;

    int maxVal = (int)pow(3, (int)(log(INT_MAX)/log(3)));

    return maxVal%n == 0;
}

//方法二: 辗转相除
bool isPowerOfthree(int n)
{
    if(n <= 0) return false;

    while(n%3 == 0) {
        n /= 3;
    }

    return n == 1;
}