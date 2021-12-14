

/*
    面试题题31:栈的压入,弹出序列
*/


#include <iostream>
#include <stack>

bool isPopOrder(const int *pPush, const int *pPop, int nLength);

int main(){
    int push[] = {1,2,3,4,5};
    int pop[] = {4,3,5,1,2};

    std::cout << isPopOrder(push, pop, 5) << std::endl;

    return 0;
}



bool isPopOrder(const int *pPush, const int *pPop, int nLength)
{
    if(pPush == nullptr || pPop == nullptr || nLength <= 0) return false;

    const int *pNextPush = pPush;
    const int *pNextPop = pPop;

    std::stack<int> stackData;

    while(pNextPop-pPop < nLength)
    {
        while(stackData.empty() || stackData.top() != *pNextPop)
        {
            if(pNextPush-pPush == nLength) break;
            stackData.push(*pNextPush);
            pNextPush++;
        }

        if(stackData.top() != *pNextPop) break;

        stackData.pop();
        pNextPop++;

    }

    if(stackData.empty() && pNextPop-pPop == nLength) return true;

    return false;

}