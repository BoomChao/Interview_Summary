

/*
    面试题56:数组中数字出现的次数

    1.给定一个数组,其中有两个元素只出现一次,其余元素出现多次;找出这两个只出现一次的元素

    2.在一个数组中只有一个元素出现了一次,其余元素都出现了三次,找出这个只出现一次的元素
*/



#include <iostream>

void findNumsApperOnce(int data[], int length, int *num1, int *num2);
unsigned int findFirstBitIs1(int num);
bool isBit1(int num, unsigned int indexBit);

int findNumsAppearingOnce(int numbers[], int length);


int main(){

    int numbers[] = {1,1,1,3};
    int length = sizeof(data)/sizeof(data[0]);

    std::cout << findNumsAppearingOnce(data, length) << std::endl;

    return 0;
}



void findNumsApperOnce(int data[], int length, int *num1, int *num2)
{
    if(data == nullptr || length < 2) return;

    int resultExclusive = data[0];
    for(int i = 1; i < length; i++) {
        resultExclusive ^= data[i];
    }

    unsigned int indexOf1 = findFirstBitIs1(resultExclusive);

    //这里这两个数必须要赋值,否则下面第一次异或的结果不确定;
    //0与num异或的结果还是num; 即 0^num = num
    *num1 = *num2 = 0;
    for(int j = 0; j < length; j++)
    {
        if(isBit1(data[j], indexOf1)) {
            *num1 ^= data[j];
        }
        else {
            *num2 ^= data[j];
        }
    }

}


//在整数num的二进制表示中找到最右边第一个是1的位
unsigned int findFirstBitIs1(int num)
{
    int indexBit = 0;
    
    //第二个语句是避免无限的右移导致溢出,比如num=0的情况,第一个条件(num&1)==0永远满足
    while((num & 1) == 0 && (indexBit < 8*sizeof(int)))     //千万不要写成 num & 1 == 0, "&"的优先级比"=="低
    {
        num = num >> 1;
        ++indexBit;
    }

    return indexBit;
}

//判断整数num的二进制表示中从最右边数的indexBit位是否为1
bool isBit1(int num, unsigned int indexBit)
{
    num = num >> indexBit;

    return(num & 1);
}



int findNumsAppearingOnce(int numbers[], int length)
{
    if(numbers == nullptr || length <= 0) {
        std::cout << "Invalid Input!" << std::endl;
        exit(1);
    }

    //int型的数据占4字节,也就是32位
    int bitSum[32] = {0};
    for(int i = 0; i < length; i++)
    {
        int bitMask = 1;
        for(int j = 31; j >= 0; j--)
        {
            int bit = numbers[i] & bitMask;
            if(bit != 0) {
                bitSum[j] += 1;
            }

            bitMask = bitMask << 1;     //注意:在Leetcode第137题中,这样写会报错溢出;可以改写为 nums[i] = nums[i] >> 1;
        }                               //将nums[i]右移的效果和bitMask左移的效果是一样的

    }

    int result = 0;
    for(int i = 0; i < 32; i++) 
    {
        result = result << 1;
        result += bitSum[i] % 3;

    }

    return result;

}