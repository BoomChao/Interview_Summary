
/*
    附：strcpy和memcpy的区别是什么？
    答：1.复制的内容不同；strcpy只能复制字符串，而memcpy可以复制任何内容，例如字符数组、整形、结构体、类等
    2.复制的方法不同；strcpy不需要指定长度，它遇到被复制的字符的串结束符'\0'才结束，所以容易溢出；而memcpy则是根据第3个参数(字节数)来决定复制的长度
    3.用途不同；通常在复制字符串时使用strcpy，而需要复制一些其他类型数据时则一般使用memcpy

    附：使用memcpy需要注意些什么？
    答：memcpy函数原型为 void *memcpy(void *dest, void *src, size_t n);  memcpy用来拷贝src所指的前n个字节到dest所指的地址上
    1.如果赋值的字节数超过了dest的空间容量，或者n超出了src的容量，这个函数是不会进行判断的，这样就会很危险；需要程序员自己检查是否有溢出的情况
    2.注意内存重叠，即dest和src指向的数组是否具有相同的空间
*/

/*
    实现memcpy函数
    注:下面转成char*这种类型是一个一个字节拷贝,可以提前对size的值进行计算,如果是4的倍数,直接转成int型来进行拷贝,这样可以加快效率
*/

void* memcpy(void *des, const void *src, size_t size)
{
    char *pDes = NULL, *pSrc = NULL;

    //泛型指针不能执行加减操作，但是可以比较大小,不能对void指针进行算法操作,所以这里需要转换成char*
    //如果存在内存重叠则从后往前进行赋值
    if(src < des && (char*)src + size > (char*)des)
    {
        pDes = (char*)des + size - 1;      //char类型的所占的字节数恰好为1
        pSrc = (char*)src + size - 1;
        while(size--) {
            *pDes-- = *pSrc--;
        }
    }
    else 
    {
        //不存在内存重叠就从前往后赋值
        pDes = (char*)des;
        pSrc = (char*)src;
        while(size--) {
            *pDes++ = *pSrc++;
        }
    }

    return des;
}


/*
    strcpy函数的实现 (会将结尾的'\0'也复制过去)
*/

void strcpy(char *des, char *src)
{
    if(des == nullptr || src == nullptr) return;

    char *pDes = des, *pSrc = src;

    while((*pDes++ = *pSrc++) != '\0');    

}


/*
    实现strcmp函数
*/

// 注意:这里函数参数是一个char类型,但是下面比较的时候必须转化成unsigned char类型
// char类型的数值范围为 -128~127, 无符号字符值的范围为 0~255, 而字符串的ASCII没有负值
// 比如某个字符ASCII为1, 某个字符ASCII为 = 255, 作为无符号数相减会得到-254,结果正确; 但是作为有符号数相减会得到2,结果错误

int strcmp(const char *str1, const char *str2)
{
    int res = 0;

    while(!(res = *(unsigned char*)str1 - *(unsigned char*)str2) && *str1 && *str2) {
        str1++;
        str2++;
    }

    if(res > 0) return 1;
    else if(res < 0) return -1;

    return 0;
}



/*
    string类的实现

*/

class String
{
private:
    char *str;         //指向字符串的指针
    size_t len;  //字符串中的的实际字符长度(不包含结尾的'\0')

public:
    String(const char *s = NULL)  //这里给出了默认值就可以实现空对象, 如 String str;
    {
        if(s == NULL) {       
            str = new char[1];
            *str = '\0';
            len = 0;
        }
        else {
            len = strlen(s);
            str = new char[len + 1];
            strcpy(str, s);        //字符串复制函数(会将结尾符一起复制)
        }
    }

    //拷贝构造(深拷贝)
    String(const String &demo) 
    {
        len = demo.len;
        str = new char[len + 1];
        strcpy(str, demo.str);
    }

    //注意：以后一切赋值运算符全部返回引用,防止产生临时对象调用拷贝构造
    String& operator=(const String &demo)
    {
        //检查自赋值,这里是拿地址比较,因为对象的地址是唯一的,而值可能相同
        if(this == &demo) return *this;

        delete[] str;

        len = demo.len;
        str = new char[len + 1];
        strcpy(str, demo.str);

        return *this;   //返回本对象的引用
    }

    //'+'运算符返回一个新的对象，但是原来的对象不能析构掉
    //由于返回的是临时对象,临时量在函数调用结束后就被析构了，所以只能使用值返回，不能使用引用返回
    String operator+(const String &demo) const 
    {
        int len = strlen(str) + strlen(demo.str) + 1;
        char *sp = new char[len];
        strcpy(sp, str);
        strcat(sp, demo.str);   //strcat(char *des, const char *src)表示将src所指向的内存中的字符连接到des所指向的内存空间后面
        String tmp(sp);
        return tmp;
    } 

    ~String() {
        delete[] str;
    }

    void print() {
        std::cout << str << std::endl;
    }

};




/*
    智能指针shared_ptr的实现    
    //参看CSDN博客C++分栏
*/

//注意:shared_ptr未定义下标操作([]),并且不支持对指针的算术运算(++,--)

template<class T>
class shared_ptr
{
private:
    T *ptr;         //实际地址
    int *count;     //存放引用计数的地址(这里必须要用地址,因为可能存在多个变量对其更改,使用地址可以多个变量都可以访问)

public:
    shared_ptr(T *pointer = nullptr)
    {
        ptr = pointer;

        if(ptr == nullptr) {
            count = new int(0);
        }
        else {
            count = new int(1);
        }
    }

    shared_ptr(const shared_ptr &smartPtr)
    {
        ptr = smartPtr.ptr; 
        count = smartPtr.count;     // 多个指针变量指向同一块地址

        //从这里可以看出,如果不使用指针更改引用计数,那么更改不了之前的智能指针的引用计数
        (*count)++;
    }

    shared_ptr& operator=(const shared_ptr &smartPtr)
    {
        //检查自赋值
        if(ptr != smartPtr.ptr)
        {
            //需要先减去原来的指针的引用计数,如果引用计数为0,则需要释放原来的内存再进行赋值
            //但是如果指针原来指向为空,则引用计数为0,不能再减了
            if(ptr != nullptr && --(*count) == 0) {
                delete ptr;
                delete count;   
            }

            ptr = smartPtr.ptr;     //这里只是释放掉ptr指向的内存,ptr指针仍然可以指向某个地址
            count = smartPtr.count;
            (*count)++;
        }
        
        return *this;
    }

    //取指针指向的值(返回的是引用)
    T& operator*() { return *ptr; }

    //注意:->操作符返回的是地址;  p->fun(); 等价于 (*p).fun();
    //使用指针直接->指向函数地址,p需要是一个指针
    T* operator->() { return ptr; }

    //只能指针只有当引用计数等于0时才释放指向的内存
    ~shared_ptr() 
    {
        //为空则说明该智能指针没有直接指向任何对象,只释放count的内存即可
        if(ptr == nullptr) {
            delete count;
        }
        else if(--(*count) == 0) {
            delete ptr;
            delete count;
        }

    }

    //返回引用计数
    int use_count() { return *count; }

};


//实现weak_ptr

template<class T>
class weak_ptr
{
public:
    friend class shared_ptr<T>; //方便shard_ptr的赋值
    T *ptr;
    int *count;

    weak_ptr() {
        ptr = nullptr;
        count = nullptr;
    }

    weak_ptr(shared_ptr<T> &smartPtr) 
    {
        ptr = smartPtr.ptr;
    }
};



/*
    weak_ptr的使用
*/

#include <iostream>
#include <vector>
#include <memory>

struct Node {
    int data;
    std::weak_ptr<Node> next;       //此处如果定义成shared_ptr会导致析构函数不能执行导致内存泄露

    Node(int n) : data(n) {}

    ~Node() {
        std::cout << "~Node() called" << std::endl;
    }

};

int main() {
    // std::shared_ptr<Node> p1(new Node(1));        
    // std::shared_ptr<Node> p2(new Node(2));

    // std::shared_ptr<Node> p1 = std::make_shared<Node>(1); 此处也可以用make_shared模板函数
    // 推荐使用make_shared
    std::shared_ptr<Node> p1 = std::make_shared<Node>(1);
    std::shared_ptr<Node> p2 = std::make_shared<Node>(2);

    p1->next = p2;
    p2->next = p1;

    return 0;
}



/*
    怎么判断系统是大端存储还是小端存储
    //使用联合体

    大端存储好处: 接受数据的程序可以优先得到数据的最高位,以便快速反应(比如网络协议的应用)
    小端存储好处: 小端计算精度便于确认,因为是先读取的字节序的低位,数组的第0位固定是最低位,而大端存储下如果精度可变,很难判断数组第0位代表多大(因为先读取的是高位,舍入的话不好取舍)
                由于CPU本身是小端存储,如果内存和文件也采用小端排序的话,就可以把文件中的数据直接存储到内存中,再直接把内存中的数据存储到CPU的寄存器,这样能提高CPU读取效率
                而且小端序比较符合人的思维
*/



int JudgeSystem()
{
    union Test {
        int num;
        char ch;
    };

    union Test test;
    test.num = 1;

    return test.ch;
}






/*
    怎么定义自己的比较函数
*/

#include <iostream>
#include <vector>
#include <queue>


//第一种方式:这种方法只能用于结构体中,就是我们排序的对象必须要是结构体才可以
//重载比较运算符"<"

struct Edge {
    int from, to, weight;
    Edge(int m_from, int m_to, int m_weight) : from(m_from), to(m_to), weight(m_weight) {}

    //1.放在结构体内部实现                            //括号里面的const表示不允许修改比较的对象,这里传引用避免了对实参的拷贝
    bool operator< (const Edge &other) const {     //注意:这个const必须要有,表示不修改类的成员变量,如果在函数里修改了会报错
        return weight > other.weight;
    }

    //2.使用友元函数实现
    friend bool operator<(const Edge &a, const Edge &b) {
        return a.weight > b.weight;
    }

};

//3.结构体外面实现
// 使用大于号实现小于号,代表排序顺序与默认的顺序相反
bool operator< (Edge a, Edge b) {
    return a.weight > b.weight;
}

int main() {
    std::priority_queue<Edge> que;
    que.push(Edge(0,1,7));
    que.push(Edge(1,2,4));
    que.push(Edge(2,3,10));
    que.push(Edge(3,4,5));

    while(!que.empty())
    {
        std::cout << (que.top().weight) << std::endl;
        que.pop();
    }

    return 0;
}



//第二种方式(用的最多)
//定义一个普通的比较函数或者使用lambda表达式

bool cmp(std:vector<int> a, std::vector<int> b) {
    return a[0] > b[0];
};


int main() {
    std::vector<std::vector<int>> nums;
    nums.push_back({2,3},{1,4},{5,6});

    //使用定义的普通函数
    sort(nums.begin(), nums.end(), cmp);

    //使用Lambda表达式
    sort(nums.begin(), nums.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
        return a[0] > b[0];
    })

    return 0;
}



//第三种方式:operator()重载函数需要被定义在一个新的结构体内
//重载"()"

struct cmp {
    bool operator()(const int &a, const int &b) {
        return a > b;
    }
};

int main() {
    //将这个类作为模板参数传递给STL容器就可以了
    std::set<int, cmp> mySet;
    mySet.insert(3);
    mySet.insert(2);
    mySet.insert(1);

    for(const int &num : mySet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}




/*
    哈希表怎么删除奇数元素(关联容器怎么删除元素)
*/

int main() {
    std::map<int,int> hash;
    hash.insert({1,1});
    hash.insert({2,2});
    hash.insert({3,3});
    hash.insert({4,4});
    hash.insert({5,5});

    for(auto it = hash.begin(); it != hash.end();)
    {
        if(it->second&1) {
            it = hash.erase(it);  //erase删除it指向的元素后返回指向it后一个元素的迭代器
        }
        else it++;
    }

    for(auto item : hash) {
        std::cout << item.first << " " << item.second << std::endl;
    }

    return 0;
}


//附:vector怎么删除偶数元素

void deleteEven(std::vector<int> &nums)
{
    for(auto it = nums.begin(); it != nums.end();)
    {
        if((*it)&1) {   //如果是奇数
            it++;
        }
        else {
            it = nums.erase(it);
        }
    }
}





/*
    手动实现一个vector
*/

class MyVector 
{
private:
    int *data;      //实际存放元素的数组
    int capacity;   //容量
    int size;       //数组大小

    void addsize(int newsize)   //动态扩容函数
    {
        int *newData = new int[newsize];
        for(int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;

        data = newData;
        capacity = newsize;   //扩容时容量增加但是size不增加,size代表的是数组元素个数   
    }

public:
    MyVector() {
        capacity = 1;   //初始容量设置为1
        size = 0;
        data = new int[capacity];
    }

    MyVector(int m_size, int val) {
        data = new int[m_size];
        memset(data, val, sizeof(data));
        capacity = m_size;
        size = m_size;
    }

    void push_back(int val)
    {
        if(capacity == size) {
            addsize(2*size);     //两倍扩容
        }
        data[size++] = val;
    }

    void pop_back() {
        if(size > 0) size--;
    }

    int getsize() {
        return size;
    }

    int &operator[] (int i) {
        return data[i];
    }

    ~MyVector() {
        delete[] data;
    }

};


//上面的扩展:实现泛型(模版vector)

template <class T> 
class MyVector
{
private:
    T *data;
    int capacity, size;

    void addsize(int newsize)
    {
        T *newData = new T[newsize];
        for(int i = 0; i < size; i++) newData[i] = data[i];
        delete[] data;

        data = newData;
        capacity = newsize;
    }

public:
    MyVector()
    {
        capacity = 1;
        size = 0;
        data = new int[capacity];
    }

    MyVector(int m_size, T val = 0)
    {
        data = new T[m_size];
        for(int i = 0; i < m_size; i++) data[i] = val;      //注意这里使用泛型就不能再使用上面的memset了,memset的第二个参数要求是int类型

        capacity = m_size;
        size = m_size;
    }

    //拷贝构造
    MyVector(const MyVector &demo)
    {
        size = demo.size;
        capacity = size;
        data = new T[size];
        for(int i = 0; i < size; i++) data[i] = demo.data[i];
    }

    ~MyVector()
    {
        delete[] data;
    }

    void push_back(int val)
    {
        if(size == capacity) addsize(2*size);

        data[size++] = val;
    }

    void pop_back() {
        if(size > 0) size--;
    }

    T& operator[](int i) {
        return data[i];
    }

};




//虚继承问题

class Base
{
public:
    void print() { std::cout << "Base print!" << std::endl; }
    Base(){ std::cout << "Constructor" << std::endl; }
};

class Mid1 : virtual public Base
{
public:

};

class Mid2 : virtual public Base
{
public:

};

class Child : public Mid1, public Mid2
{
public:

};

int main() {
    Child d;
    d.print();      //如果上面不加上virtual则,这里的print是无法使用的,因为存在二义性问题,Mid1继承一个base,Mid2也继承一个Base
                    //加上了virtual,就将共同基类设置成了虚基类,这时从不同路径继承过来的同名数据成员之在内存中只会有一个拷贝
    return 0;
}



//赋值构造和移动构造问题

class Test 
{
public:
    Test(int a) : data(new int(a)) {
        std::cout << "构造函数调用" << std::endl;
    }

    //拷贝构造
    Test(const Test &demo) {
        std::cout << "拷贝构造调用" << std::endl;
        this->data = new int(*demo.data);   
    }

    //移动构造,注意传参不能传入const类型,因为下面会修改
    Test(Test &&demo) {
        std::cout << "移动构造调用" << std::endl;
        this->data = demo.data;
        demo.data = nullptr;
    }

    ~Test() {
        std::cout << "析构函数调用" << std::endl;
        // delete data;
        if(data) {
            delete data;
        }
    }

    void print() {
        if(data == nullptr) std::cout << "置为空了" << std::endl;
    } 

private:
    int *data;
};




/*
    实现一个栈: 支持三个操作:top取栈顶元素,pop弹出元素,max取栈中最大元素
    实现一个循环队列
*/

class myStack
{
private:
    std::vector<int> nums, maxVal;
    int end, size, index;

public:
    myStack(int n = 0) {
        nums.resize(n);
        maxVal.resize(n);
        end = -1;
        index = -1;
        size = n;
    }

    bool isFull()
    {
        if(end == size - 1) return true;
        else return false;
    }
    
    bool isEmpty()
    {
        if(end == -1) return true;
        else return false;
    }

    int top() 
    {
        if(isEmpty()) return -1;
        return nums[end];
    }

    void push(int x)
    {
        if(isFull()) return;

        nums[++end] = x;

        if(index == -1 || x > maxVal[index]) maxVal[++index] = x;
        else {
            int tmp = maxVal[index];
            maxVal[++index] = tmp;
        }
    }
    
    int max()
    {
        if(isEmpty()) return -1;
        return maxVal[index];
    }

    void pop()
    {
        if(isEmpty()) return ;
        --end;
        --index;
    }
};


class myQueue
{
private:
    int pre, tail, size;
    std::vector<int> nums;

public:
    myQueue(int n = 0)
    {
        nums.resize(n);
        pre = tail = 0;
        size = n;
    }

    bool empty()
    {
        return pre == tail;
    }

    bool full()
    {
        if((tail+1)%size == pre) return true;
        return false;
    }

    void push(int x)
    {
        if(full()) return;
        nums[tail] = x;
        tail = (tail+1)%size;
    }

    void pop()
    {
        if(empty()) return;

        pre = (pre+1)%size;
    }

    int front()
    {
        if(empty()) return -1;
        return nums[pre];
    }

    //返回队列的长度
    int len()
    {
        return (tail-pre+size)%size;
    }

};



/*
    数字转汉字
    180 -> 一百八十
    203 -> 二百零三
    8008 -> 八千零八
*/

std::vector<std::string> AA = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九", "十"};
std::vector<std::string> BB = {"", "十", "百", "千", "万", "十万", "百万", "千万", "亿"};

std::string numberToChinese(int num)
{
    std::string res;
    std::string numStr = std::to_string(num);
    int k = numStr.size();

    for(int i = 0; i < numStr.size(); i++)
    {
        int tmp = numStr[i] - '0';

        if(tmp == 0) {
            if(numStr[i-1] == '0' || i == numStr.size() - 1) continue;
            else res += AA[tmp];
        }
        else {
            res += AA[tmp];
            if(numStr.size() == 2 && numStr[0] == '1' && i == 0) {
                res.erase(0);                                       //12读作十二,把1去掉
            }
            res += BB[k-i-1];
        }
    }

    return res;
}

int main() {
    std::cout << numberToChinese(12) << std::endl;

    return 0;
}


