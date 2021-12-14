

//面试题41:数据流中的中位数
//参看Leetcode第295题(利用优先队列)


class MedianFinder
{
public:
    MedianFinder() {}

    void addNum(int num) {
        if(maxQue.empty() || num < maxQue.top()) maxQue.push(num);
        else minQue.push(num);

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
        if(maxQue.size() == minQue.size()) {
            return maxQue.empty() ? 0 : (maxQue.top() + minQue.top()) / 2.0;
        }
        else {
            return (maxQue.size() > minQue.size()) ? maxQue.top() : minQue.top();
        }
    }


private:
    std::priority_queue<int> maxQue;    
    std::priority_queue<int, std::vector<int>, std::greater<int>> minQue;

};