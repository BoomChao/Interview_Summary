

/*
    面试题9:利用两个栈来实现一个队列:实现其两个函数,在队列尾插入元素,在队首删除元素
*/


// 思路:定义两个栈stack1和stack2,stack1用来存放压入栈的数据
//当队列插入数据时,直接将其压入栈1
//当队列需要删除元素时,由于队列的先进先出的特点,先进去的元素都在栈1的
//栈底,所以删除元素时先将栈1的所有元素弹出压入栈2,则先入队的元素就在
//栈2的栈顶,再弹出栈2的栈顶元素即可完成队列的删除操作
//总结起来删除操作过程为:判断栈2是否为空,若不为空,直接弹出栈2的栈顶元素
//若栈2为空,将栈1的元素弹出逐个压入栈2再弹出栈2的栈顶元素即可


template<typename T> class CQueue{
    public:
        CQueue();
        ~CQueue();

        void appendTail(const T &node);
        T deleteHead();

    private:
        stack<T> stack1;
        stack<T> stack2;

};


template<typename T> void CQueue<T>::appendTail(const T &element){
    stack1.push(element);

}


template<typename T> T CQueue<T>::deleteHead(){
    if(stack2.size() <= 0){
        while(stack1.size() > 0){
            T data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }

    // if(stack2.size() == 0)  throw new execption("Queue is empty!");    //只有throw没有catch,也可写成下面这样的形式
    if(stack2.size() == 0){    //栈为空输出警告信息后直接退出程序
        std::cout << "Queue is Empty!" << std::endl;
        exit(0);
    }


    T head = stack2.top();
    stack2.pop();

    return head;

}