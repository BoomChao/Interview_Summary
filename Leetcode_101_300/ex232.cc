

//Leetcode第232题:Implement Queue using Stacks(<剑指>面试题9)
//用栈来实现一个队列


class MyQueue
{
public:
    MyQueue(){}

    void push(int x) {
        sta1.push(x);
    }

    int pop() {
        if(sta2.empty()) 
        {
            while(!sta1.empty()) {
                int tmp = sta1.top();
                sta1.pop();
                sta2.push(tmp);
            }
        }

        int top = sta2.top();
        sta2.pop();

        return top;
    }


    int peek() {
        if(sta2.empty()) 
        {
            while(!sta1.empty()) {
                int tmp = sta1.top();
                sta1.pop();
                sta2.push(tmp);
            }
        }

        return sta2.top();
    }

    bool empty() {
        if(sta1.empty() && sta1.empty()) {
            return true;
        }

        return false;
    }


private:
    stack<int> sta1;
    stack<int> sta2;

};


