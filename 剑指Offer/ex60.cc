

/*
    面试题60:n个骰子的点数
    
    使用循环的解法会比使用递归的解法要好
*/


#include <iostream>
#include <cmath>

int g_maxValue = 6;
void printProbability(int number);
void Probability(int number, int *pProbabilities);
void Probability(int original, int current, int sum, int *pProbabilities);


int main(){
    printProbability(11);

    return 0;
}


//方法一:使用递归

void printProbability(int number)
{
    if(number < 1) return;

    int maxSum = number*g_maxValue;
    int *pProbabilities = new int[maxSum - number + 1];

    for(int i = number; i <= maxSum; i++) {
        pProbabilities[i-number] = 0;
    }

    Probability(number, pProbabilities);

    int total = pow((double)g_maxValue, number);
    for(int i = number; i <= maxSum; i++)
    {
        double ratio = (double)pProbabilities[i-number]/total;
        printf("%d: %e\n", i, ratio);
    }

    delete[] pProbabilities;

}


void Probability(int number, int *pProbabilities)
{
    for(int i = 1; i <= g_maxValue; i++) {
        Probability(number, number, i, pProbabilities);
    }

}


void Probability(int original, int current, int sum, int *pProbabilities)
{
    if(current == 1) 
    {
        pProbabilities[sum-original]++;
    }
    else 
    {
        for(int i = 1; i <= g_maxValue; i++) {
            Probability(original, current-1, i+sum, pProbabilities);          
        }
    }

}




//方法二:使用循环

void printProbability(int number)
{
    if(number < 1) return;

    int *pProbabilities[2];
    pProbabilities[0] = new int[g_maxValue * number + 1];
    pProbabilities[1] = new int[g_maxValue * number + 1];

    for(int i = 0; i < g_maxValue*number + 1; i++)
    {
        pProbabilities[0][i] = 0;
        pProbabilities[1][i] = 0;
    }

    int flag = 0;

    for(int i = 1; i <= g_maxValue; i++) {
        pProbabilities[flag][i] = 1;
    }

    for(int k = 2; k <= number; k++)
    {
        for(int i = 0; i < k; i++) {
            pProbabilities[1-flag][i] = 0;
        }

        for(int i = k; i <= g_maxValue*k; i++) 
        {
            pProbabilities[1-flag][i] = 0;
            for(int j = 1; j <= i && j <= g_maxValue; j++) {
                pProbabilities[1-flag][i] += pProbabilities[flag][i-j];
            }
        }

        flag = 1-flag;
    }

    double total = pow((double)g_maxValue, number);

    for(int i = number; i <= g_maxValue*number; i++)
    {
        double ratio = (double)pProbabilities[flag][i]/total;
        printf("%d: %e\n", i, ratio);    //如果这里不使用%e格式输出,而使用%f格式输出,则当色子个数很多时,这个数很小就会被自动舍去了
    }


    delete[] pProbabilities[0];
    delete[] pProbabilities[1];

}
