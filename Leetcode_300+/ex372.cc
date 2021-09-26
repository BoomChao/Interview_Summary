

//Leetcode第372题:Super Pow
//计算超级幂乘

//思路:数学原理

const int base = 1337;

int powmod(int a, int k) 
{
    a %= base;
    int result = 1;
    for(int i = 0; i < k; i++) {
        result = (result*a)%base;
    }

    return result;
}


int superPow(int a, std::vector<int> &b)
{
    if(b.empty()) return -1;
    if(a == 1) return 1;

    int digit = b.back();
    b.pop_back();

    return powmod(superPow(a,b),10) * powmod(a,digit) % base;
}