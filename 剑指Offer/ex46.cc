

/*
    面试题46:把数字翻译成字符串
    从尾部往前进行搜索
*/


#include <iostream>
int getTranslationCount(int number);
int getTranslationCount(const std::string &number);


int main(){
    std::cout << getTranslationCount(12258) << std::endl;

    return 0;
}


int getTranslationCount(int number)
{
    //输入的是负数就直接返回0
    if(number < 0) return 0;

    std::string numberInString = std::to_string(number);

    return getTranslationCount(numberInString);

}


int getTranslationCount(const std::string &number)
{
    int length = number.size();
    int *counts = new int[length];
    int count = 0;

    for(int i = length-1; i >= 0; i--)
    {
        count = 0;

        if(i < length-1) {
            count = counts[i+1];
        } else {
            count = 1;
        }

        if(i < length-1)
        {
            int digit1 = number[i] - '0';
            int digit2 = number[i+1] - '0';
            int converted = digit1*10 + digit2;

            if(converted >= 10 && converted <= 25) {
                if(i < length-2) {
                    count += counts[i+2];
                } else {
                    count += 1;
                }
            }

        }

        counts[i] = count;

    }

    count = counts[0];
    delete[] counts;

    return count;

}