

//Leetcode第264题 : Ugly Number II
//返回第n个丑数

//参考<剑指>面试题49
//C语言写法

int nthUglyNumber(int n)
{
    if(n <= 0) return 0;

    int *pUglyNumber = new int[n];
    pUglyNumber[0] = 1;
    int nextUglyIndex = 1;

    int *pMultiply2 = pUglyNumber;
    int *pMultiply3 = pUglyNumber;
    int *pMultiply5 = pUglyNumber;

    while(nextUglyIndex < n)
    {
        int min = Min(*pMultiply2*2, *pMultiply3*3, *pMultiply5*5);
        pUglyNumber[nextUglyIndex] = min;

        while(*pMultiply2*2 <= pUglyNumber[nextUglyIndex]) {    //注意:这里一定要是<=, 只是<是不行的
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

    int ugly = pUglyNumber[n-1];

    delete [] pUglyNumber;

    return ugly;

}


int Min(int num1, int num2, int num3)
{
    int min = (num1 < num2) ? num1 : num2;
    min = (min < num3) ? min : num3;

    return min;

}



//C++的解法,更加简洁

int nthUglyNumber(int n)
{
    if(n <= 0) return 0;

    std::vector<int> res(1, 1);
    int i = 0, j = 0, k = 0;

    while(res.size() < n)
    {
        res.push_back(std::min(res[i]*2, std::min(res[j]*3, res[k]*5)));

        if(res.back() == res[i] * 2) i++;
        if(res.back() == res[j] * 3) j++;
        if(res.back() == res[k] * 5) k++;
    }

    return res.back();

}
