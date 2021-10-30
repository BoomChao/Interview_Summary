


//Leetcode第260题:Single Number III
//一个数组中有两个数只出现了一次,其他都出现了两次,找出这两个只出现一次的数

//解法一:参考<剑指>面试题56

unsigned int findFirstBitIS1(int num)
{
    int indexBit = 0;
    while((num & 1) == 0 && indexBit < 8*sizeof(int))       
    {
        num = num >> 1;
        indexBit++;
    }

    return indexBit;
}

bool isBit1(int num, unsigned int indexBit)
{
    num = num >> indexBit;
    
    return (num & 1);
}


std::vector<int> singleNumber(std::vector<int> &nums)
{
    if(nums.size() < 2) {
        return {};
    }

    int resultOR = 0;

    for(int &num:nums) {
        resultOR ^= num;
    }

    unsigned int indexOf1 = findFirstBitIS1(resultOR);

    int num1 = 0, num2 = 0;

    for(int &num:nums) 
    {
        if(isBit1(num, indexOf1)) {
            num1 ^= num;
        }
        else {
            num2 ^= num;
        }
    }

    return {num1, num2};
}



//上面的优化

std::vector<int> singleNumber(std::vector<int> &nums)
{
    long diff = 0;      //这里使用long,否则下面的 diff&(-diff)可能会溢出
    for(int &n:nums) {
        diff ^= n;
    }

    //一个数与其负数做 & 操作得到的是最右侧一个比特为1的数,负数的与操作要转换成补码形式
    diff &= (-diff);  

    std::vector<int> res = {0, 0};
    for(int &num:nums)
    {
        if((num & diff) == 0) {
            res[0] ^= num;
        }
        else {
            res[1] ^= num;
        }
    }

    return res;
}