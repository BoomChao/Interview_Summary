

//Leetcode第190题 : Reverse Bits
//比特翻转

//思路:利用位运算


int reverseBit(uint32_t n)
{
    uint32_t ans = 0;

    for(int i = 0; i < 32; i++) {
        ans <<= 1;          //注意这个ans是先左移再相加
        ans += n & 1;
        n >>= 1;
    }

    return ans;
}

