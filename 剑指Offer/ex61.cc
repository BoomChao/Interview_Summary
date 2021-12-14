


/*
    面试题61:扑克牌中的顺子
    这题重在题意的理解
*/


#include <iostream>
#include <vector>
#include <algorithm>

bool isContinuous(int *numbers, int length);
int compare(const void *arg1, const void *arg2);

bool isContinuous(std::vector<int> &numbers);


int main(){
    int numbers[] = {0,1,3,4,5};
    int length = sizeof(numbers)/sizeof(numbers[0]);

    std::cout << isContinuous(numbers, length) << std::endl;

    std::vector<int> number = {0,1,3,4,5};
    std::cout << isContinuous(number) << std::endl;

    return 0;
}


//C语言解法

bool isContinuous(int *numbers, int length)
{
    if(numbers == nullptr || length < 1) return false;

    qsort(numbers, length, sizeof(int), compare);

    int numberOfZero = 0;
    int numberOfGap = 0;

    //统计数组中0的个数
    for(int i = 0; i < length && numbers[i] == 0; i++) {
        numberOfZero++;
    }

    //统计数组中间隔的数目
    int small = numberOfZero;
    int big = small+1;
    while(big < length)
    {
        if(numbers[small] == numbers[big]) return false;

        numberOfGap += numbers[big]-numbers[small]-1;
        small = big;
        ++big;
    }

    return (numberOfZero > numberOfGap) ? false : true;

}

int compare(const void *arg1, const void *arg2)
{
    return *(int*)arg1 - *(int*)arg2;
}



//C++解法

bool isContinuous(std::vector<int> &numbers)
{
    if(numbers.empty()) return false;

    sort(numbers.begin(), numbers.end());

    int length = numbers.size();

    int numberOfZero = 0;
    int numberOfGap = 0;

    //统计数组中0的个数
    for(int i = 0; i < length && numbers[i] == 0; i++) {
        numberOfZero++;
    }

    //统计数组中间隔的数目
    int small = numberOfZero;
    int big = small+1;
    while(big < length)
    {
        if(numbers[small] == numbers[big]) return false;

        numberOfGap += numbers[big]-numbers[small]-1;
        small = big;
        ++big;
    }

    return (numberOfZero > numberOfGap) ? false : true;

}
