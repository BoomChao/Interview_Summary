
/*
    C语言实现函数重载(C语言不能函数不能同名,使用函数指针去除掉这个限制)

    使用函数指针来实现,重载的函数不能使用相同名称,只是类似的实现了函数重载功能
    重载函数使用可变参数
*/

void func_int(void *a) 
{
    printf("%d\n", *(int*)a);
}

void func_double(void *b)
{
    printf("%f\n", *(double*)b);
}

typedef void (*ptr)(void *);

void c_func(ptr p, void *param)
{
    p(param);
}


int main() {
    int a = 23;
    double b = 23.23;

    c_func(func_int, &a);
    c_func(func_double, &b);

    return 0;
}


/*
    C语言实现继承和多态(动态多态)
*/


typedef void(*func)();      //定义一个函数指针来实现对成员函数的继承

//父类
struct A {      
    func fun;   //由于C语言结构体中不能包含函数，故只能用函数指针在类外实现
};

//子类
struct B {
    struct A m_a;     //子类中定义一个基类的对象来实现对父类的继承
};

void fA() {             //父类的调用函数
    printf("A::\n");
}

void fB() {             //子类的调用函数
    printf("B::\n");
}


int main()
{
    A a;
    B b;

    a.fun = fA;     //父类的对象调用父类的函数
    b.m_a.fun = fB; //子类的对象调用子类的函数

    A* p2 = &a;     //定义父类指针指向父类的对象
    p2->fun();

    p2 = (A*)&b;    //让父类指针指向派生类的对象，由于类型不匹配需要强制转换
    p2->fun();
}



/*
    C语言实现封装
    C语言是不存在封装这一特性的,要实现它有两种路径
    1.利用C语言里面的头文件,在头文件进行声明,在.C文件中进行定义,这样就可以隐藏内部信息,用户只能看到接口和公开的信息,无法知道对象所占的内存
    2.第二种方法是把私有的信息放在一个不透明的私有变量或者结构体当中,只有类的实现代码才知道私有变量或者结构体的真正含义
*/

//  第1种方法

/*
    .h文件
*/
#ifndef POINT_H
#define POINT_H

struct Point;

typedef struct Point point;

point* new_point();       //创建对象

void free_point(point *m_point);        //释放空间

#endif


/*
    .C文件
*/

struct Point {
    int x;
    int y;
};

point* new_project() 
{
    point *newPoint = (point*)malloc(sizeof(point));

    return newPoint;
}

void free_point(point *m_point) 
{
    if(m_point != NULL) {
        free(m_point);
    }
}




