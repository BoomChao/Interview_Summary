
/*
    实现单例模式
    (面试遇到一律写成返回全局对象的单例,因为返回全局对象的单例无论懒汉还是恶汉都是线程安全的)
*/

// 将成员函数声明成private就表示不允许外界进行访问,但是类内部成员函数和友元函数还是可以访问的
// 为了防止类内部成员函数和友元函数访问,则将拷贝构造和和赋值运算符只给出声明,不给出实现
// 因为单例要求有一个例子，所以构造函数需要给出实现语句

class Singleton
{
private:
    Singleton() {}                                      //防止外部调用构造函数创建对象
    Singleton(const Singleton &);                 //阻止拷贝创建对象              (将这两个函数放在public底下使用 =delete关键字来定义成删除函数也可以)
    Singleton& operator=(const Singleton &);      //阻止复制运算符对对象复制

public:

    //懒汉式:只有调用getInstance函数才会创建对象
    static Singleton& getInstance() {       //提供一个全局访问点,就需要在类中定义一个static函数,返回在类中的唯一构造的实例
        static Singleton instance;          //这里的getInstace函数不能以值返回,主要是因为构造函数是私有的,外部不能创建临时对象
        return instance;                    //内部静态变量也是线程安全的,只会创建一个实例
    }

    void printTest() {
        std::cout << "do something!" << std::endl;
    }

};


//饿汉式,程序一启动对象就创建完成了,缺点是无论用于是否使用单例对象都会创建单例对象
class Singleton
{
private:
    Singleton() {}                                      
    Singleton(const Singleton &);                 
    Singleton& operator=(const Singleton &);      
    static Singleton instance;                  //这是错误的.static变量必须在外部实例化,而instance无法在外部调用构造函数

public:
    static Singleton& getInstance() {
        return instance;
    }

    void printTest() {
        std::cout << "do something!" << std::endl;
    }

};


/*
    返回全局对象的懒汉式和恶汉式都是线程安全的,因为类中静态成员只会被创建一次
    所谓线程安全就是线程执行这项操作不会带来什么危险操作(比如创建多个单例对象,段错误,内存重复释放这些错误)
*/

//返回指针的懒汉式单例(线程安全)
//由于懒汉式是在用于需要时才进行单例对象的创建,如果遇到多线程容易发生内存泄露,所以需要使用互斥锁

class Singleton
{
private:
    Singleton() {
        std::cout << "我是懒汉式" << std::endl;
    }
    Singleton(const Singleton &);
    Singleton& operator=(const Singleton &);
    static Singleton *instance;
    static std::mutex mut;

public:
    //返回指针的引用
    static Singleton* &getInstance()
    {      
        //使用双检锁,好处在于只有判断指针为空的时候才加锁,避免每次调用该方法都加锁,锁的开销还是比较大的
        if(instance == nullptr) 
        {
            std::unique_lock<std::mutex> lock(mut);
            if(instance == nullptr) {                    //注意这里也要判断一次,否则当两个线程同时进入时,刚开始instance都为空,第一个线程加完锁创建对象,第二个线程也会创建对象
                instance = new(std::nothrow) Singleton();
            }
        }
        return instance;
    }

};

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mut;                  //这个互斥锁必须初始化



//返回指针的恶汉式单例本身就是线程安全的,因为静态实例初始化之前就由主线程以单线程的方式完成了初始化,不必担心多线程问题

class Singleton
{
private:
    Singleton() {}
    Singleton(const Singleton &);
    Singleton& operator=(const Singleton &);

    static Singleton* instance;

public:
    static Singleton* &getInstance() {          //返回值和返回引用区别:返回值会产生一份副本,返回引用不会,但是不能返回局部对象的引用
        return instance;
    }

    //释放单实例
    void deleteInstance() {
        if(instance) delete instance;   
        instance = nullptr;
    }

};

Singleton* Singleton::instance = new(std::nothrow) Singleton;       //虽然构造函数私有,但是全局对象初始化还是可以调用的






/*
    工厂方法模式
*/

class Product 
{
public:
    virtual ~Product() {}
    virtual std::string operation() const = 0;
};

class ConcreteProduct1 : public Product
{
public:
    std::string operation() const override {
        return "result of ConcreteProduct1";
    }
};

class ConcreteProduct2 : public Product
{
public:
    std::string operation() const override {
        return "result of ConcreteProduct2";
    }
};

class Creator
{
public:
    virtual ~Creator() {}
    virtual Product* FactoryMethod() const = 0;

    std::string SomeOperation() const {
        Product *product = this->FactoryMethod();
        std::string result = "Creator: The same creator's code has just worked with " + product->operation();
        
        delete product;
        return result;
    }

};

class ConcreteCreator1 : public Creator
{
public:
    Product* FactoryMethod() const override {
        return new ConcreteProduct1();
    }
};

class ConcreteCreator2 : public Creator
{
public:
    Product* FactoryMethod() const override {
        return new ConcreteProduct2();
    }

};


void clientCode(const Creator &creator)
{
    std::cout << creator.SomeOperation() << std::endl;
}


