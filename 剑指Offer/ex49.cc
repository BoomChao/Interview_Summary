
/*
    面试题49:丑数
    找出从小到大的第1500个数
*/



#include <iostream>

int getUglyNumber_Solution2(int index);
int Min(int num1, int num2, int num3);


int main(){
    std::cout << getUglyNumber_Solution2(4) << std::endl;

    return 0;
}

//判断一个数是否是丑数
bool isUgly(int number)
{
    while(number%2 == 0) {
        number /= 2;
    }
    while(number%3 == 0) {
        number /= 3;
    }
    while(number %5 == 0) {
        number /= 5;
    }

}


int getUglyNumber(int index)
{
    //输入的个数小于等于0,则直接返回0表示没找到
    if(index <= 0) return 0;

    int number = 0;    
    int uglyFound = 0;    //找到了第几个丑数

    while(uglyFound < index)
    {
        ++number;
        if(isUgly(number)) {    //判断number是否为丑数,如果为丑数将标记数加1
            ++uglyFound;        //当标记的个数等于index时就代表找到了第index个丑数
        }
    }

    return number;

}


//方法二:
//这种方法是创建一个数组来存储丑数,按照数组中已有的丑数来生成其他的丑数
//这就避免了上一种方法中的每次都要判定一个数是不是丑数

int getUglyNumber_Solution2(int index)
{
    if(index <= 0) return 0;

    int *pUglyNumber = new int[index];
    pUglyNumber[0] = 1;
    int nextUglyIndex = 1;

    int *pMultiply2 = pUglyNumber;
    int *pMultiply3 = pUglyNumber;
    int *pMultiply5 = pUglyNumber;

    while(nextUglyIndex < index)
    {
        int min = Min(*pMultiply2*2, *pMultiply3*3, *pMultiply5*5);
        pUglyNumber[nextUglyIndex] = min;

        while(*pMultiply2*2 <= pUglyNumber[nextUglyIndex]) {
            ++pMultiply2;
        }
        while(*pMultiply3*3 <= pUglyNumber[nextUglyIndex]) {
            ++pMultiply3;
        }
        while(*pMultiply5*5 <= pUglyNumber[nextUglyIndex]) {
            ++pMultiply5;
        }

        ++nextUglyIndex;

    }

    int ugly = pUglyNumber[index-1];

    delete [] pUglyNumber;

    return ugly;

}


int Min(int num1, int num2, int num3)
{
    int min = (num1 < num2) ? num1 : num2;
    min = (min < num3) ? min : num3;

    return min;

}