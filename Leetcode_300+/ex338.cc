

//Leetcode第338题 : Counting Bits
//计算从0至n这n+1个数的二进制表示中的比特位数

//思路:参考剑指向面试题15

std::vector<int> countBits(int num)
{
    std::vector<int> res;

    if(num < 0) return {};

    for(int i = 0; i <= num; i++) {
        res.push_back(NumberOf1(i));
    }

    return res;
}


//计算数字n的二进制表示中有几位为1
int NumberOf1(int n)
{
    int count = 0;

    while(n) {
        ++count;
        n = n&(n-1);
    }

    return count;
}