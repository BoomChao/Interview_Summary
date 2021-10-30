

//Leetcode第295题:Find Median from Data Stream
//找到数据流中的中位数

//思路:利用优先队列


#include <iostream>
#include <queue>

class MedianFinder
{
private:
    std::priority_queue<int> maxQue;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minQue;


public:
    void addNum(int num) {
        if(maxQue.empty() || maxQue.top() > num) maxQue.push(num);      //注意:maxQue中的元素存储顺序是从大到小,如 3 2 1
        else minQue.push(num);                                          //minQue中的元素存储顺序是从小到大,如 1 2 3

        //平衡两个队列的长度,使其长度差不超过1
        if(maxQue.size() > (minQue.size() + 1)) {
            minQue.push(maxQue.top());
            maxQue.pop();
        }
        else if((maxQue.size() + 1) < minQue.size()) {
            maxQue.push(minQue.top());
            minQue.pop();
        }

    }

    double findMedian() {
        if(maxQue.size() == minQue.size()) return maxQue.empty() ? 0 : (maxQue.top() + minQue.top())/2.0;   //注意:这里只需要判断maxQue是否为空,因为maxQue是一定会有元素的
        else return ( maxQue.size() > minQue.size() ) ? maxQue.top() : minQue.top();                        //如果maxQue中都没元素,就说明没有添加任何数进去
    }

};


int main(){
    MedianFinder med;
    med.addNum(1);
    med.addNum(2);
    med.addNum(3);
    med.addNum(4);

    std::cout << med.findMedian() << std::endl;

    return 0;
}
