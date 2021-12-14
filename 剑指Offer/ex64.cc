

/*
    面试题64:求1+2+3+...+n
*/

//解法一:使用构造函数

class Temp 
{
    public:
        Temp() {
            ++N;
            Sum += N;
        }

        static int Reset() {
            N = 0;
            Sum = 0;
        }

        static unsigned int GetSum() {
            return Sum;
        }

    private:
        static unsigned int N;
        static unsigned int Sum;

};


unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

unsigned int Sum_Solution1(unsigned int n)
{
    Temp::Reset();

    Temp *a = new Temp[n];
    delete[] a;
    a = nullptr;        //防止其成为悬空指针

    return Temp::GetSum();
}



//解法二:利用虚函数求解

class A;
A* Array[2];

class A
{
    public:
        virtual unsigned int Sum(unsigned int n) {
            return 0;
        }

};


class B : public A 
{
    public:
        virtual unsigned int Sum(unsigned int n) {
            return Array[!!n]->Sum(n-1) + n;
        }

};


int Sum_Solution2(int n)
{
    A a;
    B b;
    Array[0] = &a;
    Array[1] = &b;

    int value = Array[1]->Sum(n);

    return value;

}



//解法三:利用函数指针来求解

typedef unsigned int(*fun)(unsigned int);

unsigned int Soluton3_Teminator(unsigned int n)
{
    return 0;
}

unsigned int Sum_Solution3(unsigned int n)
{
    static fun f[2] = {Soluton3_Teminator, Sum_Solution3};
    
    return n + f[!!n](n-1);
}



//解法四:利用模板类型求解

template<unsigned int n> struct Sum_Solution4
{
    enum Value { N = Sum_Solution4<n-1>::N + n };
};

template<> struct Sum_Solution4<1>
{
    enum Value { N = 1 };
};



#include <iostream>

int main(){
    std::cout << Sum_Solution1(100) << std::endl;
    std::cout << Sum_Solution2(100) << std::endl;
    std::cout << Sum_Solution3(100) << std::endl;
    std::cout <<  Sum_Solution4<100>::N << std::endl;

    return 0;
}

