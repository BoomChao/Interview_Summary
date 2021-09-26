


//Leetcode第225题:Implement Stach using Queues
//用队列来实现一个栈

class MyStack 
{
public:
    MyStack(){}

    void push(int x) {
        que.push(x);
        for(int i = 0; i < que.size()-1; i++) {
            que.push(que.front());
            que.pop();
        }
    }

    int pop() {
        int top = que.front();
        que.pop();

        return top;
    }

    int top() {
        return que.front();
    }

    bool empty() {
        return que.empty();
    }


private:
    queue<int> que;

};