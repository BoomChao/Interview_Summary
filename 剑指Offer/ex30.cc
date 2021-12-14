//面试题30

/*
    包含min函数的栈(min函数是取栈中元素的最小值)
*/

//思路:
//题目要求是定义一个特殊的栈,这个栈的min,push,pop函数的时间复杂度都是O(1)
//不要以为将栈中元素重新排序后得到最小值就可以了,这样栈的数据结构就被破坏了,
//顺序全都打乱了,最先入栈的元素不一定最先弹出

//定义一个辅助栈,比如现在压入栈的元素是3421;
//数据栈压入元素3,辅助栈初始为空,压入元素3
//数据栈压入元素4,由于辅助栈的栈顶元素小于4,故接着压入3;    数据栈为3,4; 辅助栈为3,3
//数据栈压入元素2,由于辅助栈的栈顶元素大于2,此时压入2       数据栈为3,4,2; 辅助栈为3,3,2
//数据栈压入元素1,由于辅助栈的栈顶元素大于1,此时压入1       数据栈为3,4,2,1; 辅助栈为3,3,2,1

//这样无论数据栈是压入元素还是弹出元素,辅助栈栈顶元素都是当前数据栈中元素的最小值


//这种写法没有使用assert函数,下面的第二种写法使用了assert函数
template<typename T> void StackWithMin<T>::push(const T &value){
    m_data.push(value);

    if(m_min.size()==0 || value<m_min.top()){
        m_min.push(value);
    }else{
        m_min.push(m_min.top());

    }

}


template<typename T> void StackWithMin<T>::pop(){
    if(m_data.size>0 && m_min.size()>0){
        m_data.pop();
        m_min.pop();
    }else{
        std::cout << "Error" << std::endl;
        exit(0);
    }

}


template<typename T> const T& StackWithMin<T>::min() const{
   if(m_data.size>0 && m_min.size()>0){
       return m_min.top();
   }

}



//测试算例
#include <iostream>
#include <assert.h>
#include <stack>


template <typename T> class StackWithMin{
    public:
        StackWithMin() {}
        virtual ~StackWithMin() {}

        T& top();
        const T& top() const;

        void push(const T& value);      //主要实现这三个关键函数即可
        void pop();
        const T& min() const;

        bool empty() const;
        size_t size() const;

    private:
        std::stack<T>   m_data;    //定义两个栈,一个存放原始数据一个存放栈中最小元素
        std::stack<T>   m_min;      

};



template <typename T> void StackWithMin<T>::push(const T& value){
    m_data.push(value);

    if(m_min.size()==0 || value<m_min.top()){
        m_min.push(value);
    }else{
        m_min.push(m_min.top());
    }

}

template <typename T> void StackWithMin<T>::pop(){
    assert(m_data.size()>0 && m_min.size()>0);

    m_data.pop();
    m_min.pop();

}

template <typename T> const T& StackWithMin<T>::min() const{
    assert(m_data.size()>0 && m_min.size()>0);

    return m_min.top();

}