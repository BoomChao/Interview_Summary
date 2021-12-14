


/*
    面试题59:队列的最大值
*/

#include <iostream>
#include <vector>
#include <deque>

std::vector<int> maxInWindows(const std::vector<int> &num, unsigned int size);

int main(){
    std::vector<int> num = {2,3,4,2,6,2,5,1};
    
    std::vector<int> window = maxInWindows(num, 3);

    for(int n:window) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}


std::vector<int> maxInWindows(const std::vector<int> &num, unsigned int size)
{
    std::vector<int> maxInWindows;
    
    if(num.size() >= size && size >= 1)
    {
        std::deque<int> index;

        //找到第一次滑动窗口中的最大元素
        for(unsigned int i = 0; i < size; i++)
        {
            while(!index.empty() && num[i] >= num[index.back()]) {
                index.pop_back();
            }

            index.push_back(i);
        }

        for(unsigned int i = size; i < num.size(); i++)
        {
            maxInWindows.push_back(num[index.front()]);

            //存入index队列中的元素是单调递减的
            while(!index.empty() && num[i] >= num[index.back()]) {
                index.pop_back();
            }

            //滑动窗口移动后,判断队首的元素是否还在窗口中
            if(!index.empty() && index.front() <= (int)(i-size)) {
                index.pop_front();
            }

            index.push_back(i);
        }

        //这是存储的最后一次窗口中的最大数值
        maxInWindows.push_back(num[index.front()]);

    }

    return maxInWindows;

}
