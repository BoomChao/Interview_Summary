### 一、基本语法（变量，函数）

1.不能做switch( )的参数类型是？     （谭浩强P100）

**答：**类型参数应该为整数类型 (包括字符型(这里的字符型指的是只有1个字符，超过两个字符的字符串也不能做类型参数))；其余都不能做switch()的参数，比如浮点型，布尔型等 



4.何为回调函数

**答：**程序在运行过程中，调用某些函数接口时，某些函数的参数会要求传入另一个函数的指针及其对应的参数，以便在合适的时候在接口函数中就可以通过该函数指针直接调用另一个函数，来完成程序的执行任务这种通过参数形式把函数指针传递给其它函数，而在其他函数里面通过这个函数指针来调用某个函数，这个过程就叫回调，而通过指针被调用的函数就叫回调函数（callback function）回调函数并不是由该函数的实现方来直接调用，而是在特定的事件或条件发生时在其他模块或者库中进行调用，用于对该事件或条件进行响应和处理

```C++
typedef int(*callback)(int,int);
int fun(int a, int b, callback p) {
    return (*p)(a,b);
}

int add(int a, int b) {
    return a+b;
}

int res = fun(4,2,add);    //add就是一个回调函数

//上面如果不使用typedef则这样调用
int fun(int(*ptr)(int,int), int a, int b);
```

函数指针的应用场景就是回调，我们调用别人的提供的API函数就称为call；如果别人调用我们的函数，则称为callback说白了就是对某些函数参数我们会传入一个函数指针，而这个指针指向的函数何时被调用取决于某些事件的发生；只有满足特定条件了，才会通过这个函数指针去调用其指向的函数处理特定的事件



5.如何定义Bool变量的TRUE和FALSE的值？

**答：**C语言是不能直接使用bool类型的，C++才有bool类型；所以这个问题是针对C语言而言的；对于C语言，系统并没有自带的bool类型和false与true的定义,如果想使用就必须自定类型； 这个问题就是在问有哪些方法可以定义这两个类型;   

```C++
1.通过宏定义
typedef int Bool;        //bool类型本质上也是整形类型（见谭浩强P43）
#define False 0
#define True 1

2.通过枚举定义
typedef enum {
    False, True        //默认False值为0，True值为1
} Bool;
```





10.#include尖括号和双引号的区别   

**答：**#include指令也称为文件包含指令，作用就是将另一个源文件嵌入到当前文件中；这个被嵌入的文件可以是.h文件，也可以是.cpp文件

1.#include<xxx.h> 系统自带的头文件用尖括号括起来，这样编译器就会在系统目录下查找该头文件

2.#include"xxx.h" 用户自定义的头文件用双括号括起来，这样编译器首先会在当前目录下查找，然后在到C或者C++安装目录( 比如 Unix和Linux就可以通过设定环境变量 )中查找，最后再在系统目录下查找

附录：教材对这二者的解释（郑莉P173）

1.#include<> 就表示按标准方式搜索目标源文件，**文件位于系统目录的include子目录下**

2.#include"" 表示首先在当前目录搜索，没有的话再按标准方式搜索



13.字符串string和char,以及char和char[ ]的区别

**答：**1.string和char\*的区别

(1).string是一个类，char\*是一个指向char类型的指针

(2).string不用考虑内存释放和越界string 封装了char* ，管理char\*字符串，管理为char*所分配的内存；string每一次的复制和取值都由string类负责维护，不用担心复制越界和取值

(3).string支持运算，且string能提供字符串操作函数



2.string和char\*之间的转换

(1)string转换成char*类型 （两种方法）

```C++
string s = "abc";  
const char *t = s.c_str();  //方法一
const char *t = s.data(); 	//方法二:必须使用const char*类型来接受
```

(2)char*转换为string类型

```c++
char *p = "abc";
string s = p;		//直接赋值即可
```

(3)string转char[ ]数组，先将string转化成char*，再利用strcpy( )函数

```C++
string s = "abc";
char str[18];
strcpy(str, s.data());
strcpy(str, s.c_str());
```



3.char[]和char\*之间的转换

```C++
char *a = "abc"; 	//这是字符串常量；表示定义字符指针变量ａ, 并把字符串第一个元素的地址赋值给a；相同的常量字符串在内存中只有一个拷贝
char b[] = "abc";	//这是用字符数组表示的字符串变量；定义字符数组b, 并把字符串赋值给数组中各元素；

b[0] = 'b';		//正确
a[0] = 'b';		//错误
```

char *a = "abc"; 中的"abc"被分配在常量存储区，a为字符指针是存在栈区； 指针存放在栈区，但是指针指向的内容内存放常量存储区而常量存储区是不能被更改的，是只读区域，所以当你试图去写入数据的时候就会报错，"abc"实际上是一个隐含创建的类型为char的数组，一个字符串常量就表示这样一个数组的首地址，因此可以把字符串常量赋值给字符串指针，由于常量值是不能修改的，应将字符串常量赋给指向常量的指针，即：const char *a = "abc"; 	注：有的文章也把字符串常量也叫字符串

而 char b[ ] = "abc"中的"abc"是存放在栈区中的，是可以进行写操作的

为了节省内存，C和C++把常量字符串存放到单独的一个内存区域；当几个指针赋值给相同的常量字符串时，他们实际上会指向相同的内存地址；但是用常量内存初始化数组却不同

如：char str[12] = "hello World"; str是一个字符串数组，我们会为其分配长度为12字节的空间，并把字符串“hello world”的内容复制到数组中去   《剑指》P49



17.怎么判断一个浮点数为0？3.请写出bool x，int x，float x, 指针变量 x与"零值"比较的if 语句

**答：**

1.bool型就只有true和false两种结果，所以bool型的零值就是对应的false；   即：if(x == true)

2.int型的零值就是0，即：if(x == 0)

3.对指针变量，零值就是空指针nullptr，即：if(x == nullptr)

4.对float型变量，由于一个区间内有无限个实数，所以计算机的浮点类型不能表示所有数，浮点数通常只是实际值的近似值，如5可能被存储为4.9999；因此两个浮点数比较大小时，只要两数之间的差距在一定的区间内，就可以认为它们是相等的；这个区间大小按照实际情况确定，如：

```C++
const float EPSINON = 0.00001;
if(x >= -EPSINON && x <= EPSINON)     //其中EPSINON是允许的误差(即精度)
```

附：C++里面取绝对值的函数有以下几个：

```C++
int abs(i)                 //整形参数i的绝对值
double fabs(double x)      //双精度参数x的绝对值
long abs(long n)           //长整型参数n的绝对值，这几个函数均需要包含头文件 <cmath>
```

因为C++是强类型语言，一个函数只能有一种类型的返回值，所以需要不同的函数取处理不同类型的数值；



8.声明一个变量和定义一个变量有什么区别？

**答：**变量的声明只规定了变量的类型和名字；变量的定义不仅规定了变量的类型和名字，还申请了存储空间，也可能会为变量赋一个初始值

如果只想声明一个变量并不是定义它，可以利用extern关键字，如：

```C++
extern int i;    //声明并非定义i        (extern的详细用法参考  谭浩强P206)
int j;           // 声明并且定义j
```

除非有extern关键字，否则都是变量的定义

附：全局变量如果没有显示初始化，编译器会帮助执行默认的初始化，但是局部变量就不会了， 局部变量不初始化其值就是随机值 (包括类中的成员变量也是，如果不显示初始化其值也是随机值)

```c++
int num;
int *ptr;

class Test {
public:
    int number;
    int *pointer;
};
```

注意：编译器会将num初始化成0，指针初始化成 nullptr但是类Test中的number和pointer的值是多少就不确定了



26.i++和++i的区别

**答：**

i++是先赋值再自增；而++i是先自增后赋值

++i 是 i = i+1，表达式的值就是 i 本身；返回的是引用；i++也是 i = i+1，但表达式的值是加1前的副本，由于要先保存副本，因此效率要低一些；返回的是副本，最后真实值再加1

对于C++内置类型而言(比如，int, double 这些数据类型都是内置类型)，大部分编译器会做优化，因此效率没什么区别

```C++
std::string str = "abc";
int i = 0;
if(str[i++] < str[i]) std::cout << "hello" << std::endl;     
//注意:i++是在执行完当前语句(第一个str[i])后就将i自增,所以这行语句其实比较的是 str[0] < str[0+1]
```

附：i++和++i是原子操作吗？

**答：**前置自增和后置自增都不是原子操作

原子操作是指不会被线程调度机制打断的操作；这种操作一旦开始，就一直运行到结束，中间不会切换到另一个线程

原子操作是不可分割的，在执行完毕前不会被任何其它任务或事件中断：在单线程中， 能够在单条指令中完成的操作都可以认为是 原子操作，不能在单条指令中完成的操作也都可以认为不是原子操作，因为中断可以且只能发生于指令之间；在多线程中，不能被其它进程（线程）打断的操作就叫原子操作

而i++和++i实际上会执行三条指令，而这三条指令都有可能被其他线程打断

1、将值从内存拷贝到寄存器；2、寄存器自增；3、将值从寄存器拷贝到内存



9.两个线程不加保护地操作i++ 100次，分析过程和答案，起始 i 的值为0

**答：**对多核CPU来说：最小值为2，最大值为200

首先对i++的操作可分成三步：1.首先把 i 的值从内存放到寄存器   2.将寄存器中的值加1     3.把寄存器中的值写回到内存
**1). 得到最小值2的情况**

线程A先把 i 的值取出，此时寄存器里面的值为0，内存的值为0；线程B也把内存中 i 的值取出，此时寄存器中的值为0，内存中的值为0接着A执行自增操作，将 i 写回到内存中，此时i的值为1之后B都没有抢到CPU，则线程A一直执行到第99次，此时内存中的为99；

此时B抢到CPU将第一次执行的1重新写入到内存，此时内存中的 i=1之后A又抢到CPU，则寄存器中的自增后值为2，此时失去了CPU之后B一直执行到100次后结束，内存中的值为100B执行结束后A抢到CPU将寄存器中的2写入到内存中，此时A，B都执行结束，内存中的值为2

即：A,B线程同时取到初始值0，之后A执行99次内存中的值为99，B将第一次取的值写入到内存中i的值更新为1，A第100次取到值为1， 之后B一直执行到结束，内存中的值为100，则A将寄存器里面的值加1后写入到内存得到最终值为2

**2).最大值为200的情况**

A，B恰好交替打印输出；或者一开始CPU就被其中一个抢占，直到其中一个线程结束另一个线程才抢到CPU



对单核CPU来说：最小值为100，最大值为200；单核CPU i 的值只能在寄存器中存在一份副本

**1).得到最小值100的情况：**

每次线程一取出 i 的值后CPU时间切换到线程二，线程二也取出 i 的值，取到的值和线程一相等，线程二给i加一后放回去，线程一也将i加一后放回去，放回去的值也相等，相当于两个线程都执行一次i++操作，i的值只增加1，这样操作100次i的值为100

**2).得到最大值200的情况：**

线程一和线程二间隔操作，即线程一对i++操作完成，把已经加一的数据放回去之后线程二再操作，轮流进行，最后每个线程都对i加了100次，i的值为200



30.二维数组按行遍历还是按列遍历效率高？为什么？

**答：**按行遍历效率高，首先数组在内存中是按行存储的，按行遍历时可以从数组首元素地址一直走下去，就可以遍历完整个数组，而按列遍历则需要每一次指向每一列的第n行元素；但是指针寻址很快，所以并不会有明显的差别那么按行遍历比按列遍历效率高在哪里？

![](C:\Users\12458\Desktop\Typora\PNG\Image16.png) 



37.C++调动C库函数需要注意什么？

17.C++中怎么使用C

**答：**使用 extern "C"，其作用是告诉编译器括号里面的内容是按照C语言的文件格式编译的，需要链接的话按照C的命名规则去查找

```c++
extern "C" {
    #include "f.h"
}
```

现在我们有一个C库文件，它的头文件是 f.h，产生的lib文件的 f.lib，那么我们如果想要在C++中使用这个头文件，需要像上面那样写

C++程序有时候需要调用其他语言编写的函数，最常见的就是调用C语言编写的函数；像所有其他名字一样，C++其他语言中的函数名字也必须在C++中进行声明，并且该声明必须指定返回类型和形参列表；对其他语言编写的函数来说，编译器检查其调用方式与处理C++函数的方式相同，但是生成的代码有所区别，C++使用**链接指示**指出任意非C++使用的语言

注：要想把C++代码和其他语言(包括C语言)编写的代码放在一起使用，要求我们必须有权访问该语言的编译器，并且这个编译器与当前的C++编译器兼容　　　(《C++Primer》P758)

