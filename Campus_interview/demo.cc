
/*
    多线程顺序打印
*/
/*
#include <iostream>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;

int k = 0;

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *fun1(void *arg)
{
    for(int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex);      //加锁
        
        while(k%3 != 0) {
            pthread_cond_wait(&cond, &mutex);
        }

        printf("A\n");
        k++;

        pthread_mutex_unlock(&mutex);    // 解锁
        pthread_cond_broadcast(&cond);   // 唤醒阻塞在此条件变量上的所有线程

        // sleep(1);
    }

}

void *fun2(void *arg)
{
    for(int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex);      
        
        while(k%3 != 1) {
            pthread_cond_wait(&cond, &mutex);
        }

        printf("B\n");
        k++;

        pthread_mutex_unlock(&mutex);    //解锁
        pthread_cond_broadcast(&cond);  //解除阻塞的条件变量
        
        // sleep(1);
    }

}


void *fun3(void *arg)
{
    for(int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex);      //加锁
        
        while(k%3 != 2) {
            pthread_cond_wait(&cond, &mutex);
        }

        printf("C\n");
        k++;

        pthread_mutex_unlock(&mutex);    //解锁
        pthread_cond_broadcast(&cond);  //解除阻塞的条件变量

        // sleep(1);
    }

}

int main()
{
    pthread_mutex_init(&mutex, NULL);       //初始化一个互斥锁

    pthread_t tid1, tid2, tid3;

    pthread_create(&tid1, NULL, fun1, NULL);
    pthread_create(&tid2, NULL, fun2, NULL);
    pthread_create(&tid3, NULL, fun3, NULL);

    // 阻塞等待线程回收
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}


/*
    模拟猴子吃桃问题
    生产者和消费者问题
*/
/*

// 参看CSDN IPC收藏夹

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define COUNT 7

int int_grow_number = 0;
int int_eat_number = 0;

pthread_mutex_t lock;
pthread_cond_t can_eat = PTHREAD_COND_INITIALIZER;     //通知猴子可以吃桃了
pthread_cond_t can_grow = PTHREAD_COND_INITIALIZER;    //通知桃树需要长桃子了


void *eat(void *arg)
{
    while(1)
    {
        pthread_mutex_lock(&lock);

        //如果吃完了所有的桃子,则阻塞
        if(int_grow_number == int_eat_number) {
            pthread_cond_wait(&can_eat, &lock);
        }

        if(int_grow_number == -1) {
            printf("猴子已经吃饱了\n");
        }
        else {
            int_eat_number++;
            printf("猴子正在吃第 %d 个桃子 \n", int_eat_number);
        }

        // std::cout << int_grow_number << std::endl;
        // printf("%d\n", int_grow_number);

        sleep(1);

        pthread_cond_signal(&can_grow);      //通知桃树长桃子
        pthread_mutex_unlock(&lock);

        if(int_grow_number == -1) break;
    }

}


void *grow(void *arg)
{
    while(1)
    {
        pthread_mutex_lock(&lock);

        //如果生成的桃子猴子还没有吃完,则阻塞等待猴子吃
        if(int_grow_number > int_eat_number) {
            pthread_cond_wait(&can_grow, &lock);
        }

        if(int_grow_number >= COUNT) {
            int_grow_number = -1;
            printf("本次喂食结束\n");
        }
        else {
            int_grow_number++;
            printf("桃树正在长第 %d 个桃子\n", int_grow_number);
        }

        pthread_cond_signal(&can_eat);  //通知猴子吃桃子
        pthread_mutex_unlock(&lock);

        if(int_grow_number == -1) break;
    }

}

int main()
{
    pthread_t th_peach, th_monkey;

    //初始化互斥锁, 条件变量在定义的时候已经静态初始化了
    pthread_mutex_init(&lock, NULL);

    pthread_create(&th_peach, NULL, eat, NULL);
    pthread_create(&th_monkey, NULL, grow, NULL);

    pthread_join(th_peach, NULL);
    pthread_join(th_monkey, NULL);

    return 0;
}

#include <pthread.h>


// pthread_cond_t thread1 = PTHREAD_COND_INITIALIZER;
// pthread_cond_t thread2 = PTHREAD_COND_INITIALIZER;
// pthread_cond_t thread3 = PTHREAD_COND_INITIALIZER;

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int k = 0;

void *fun1(void *arg)
{
    for(int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&lock);

        while(k%3 != 0) {
            pthread_cond_wait(&cond, &lock);
        }

        printf("A\n");
        k++;

        pthread_mutex_unlock(&lock);
        pthread_cond_broadcast(&cond);

    }

}


void *fun2(void *arg)
{
    for(int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&lock);

        while(k%3 != 1) {
            pthread_cond_wait(&cond, &lock);
        }

        printf("B\n");
        k++;

        pthread_mutex_unlock(&lock);
        pthread_cond_broadcast(&cond);

    }

}

void *fun3(void *arg)
{
    for(int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&lock);

        while(k%3 != 2) {
            pthread_cond_wait(&cond, &lock);
        }

        printf("C\n");
        k++;

        pthread_mutex_unlock(&lock);
        pthread_cond_broadcast(&cond);

    }

}


int main() {
    pthread_t tid1, tid2, tid3;

    pthread_create(&tid1, NULL, fun1, NULL);
    pthread_create(&tid2, NULL, fun2, NULL);
    pthread_create(&tid3, NULL, fun3, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int delete_blanks(char *str)
{
    int len = strlen(str);
    int cur = 0;

    for(int i = 0; i < len; i++) {
        if(str[i] == ' ') continue;
        else str[cur++] = str[i];
    }

    str[cur] = '\0';

    return len - cur;
}


int delete_blanks(char *str);

int main() {
    
    // int a = (int)(((int*)0) + 4);

    // printf("%d\n", a);

    // char *src = "hello";

    // char *dest = NULL;

    // int len = strlen(src);

    // dest = (char*)malloc(len + 1);
    // char *d = dest;
    // char *s = src + len - 1;

    // while(len-- != 0) {
    //     *(d++) = *(s--);
    // }
    // *d = '\0';

    // printf("%s\n", dest);

    // free(dest);

    // char str[20] = "h e l lo";

    // printf("%d\n", delete_blanks(str));

    // printf("%s\n", str);

    char buf[4] = {0x12, 0x34, 0x56, 0x78};

    printf("%x\n", *(short*)&buf[3]);

    return 0;
}


int k = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *func1(void *arg)
{
    for(int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex);

        while(k%3 != 0) {
            pthread_cond_wait(&cond, &mutex);
        }

        printf("A\n");
        k++;
        // sleep(1);

        pthread_mutex_unlock(&mutex);
        pthread_cond_broadcast(&cond);
    }

}


void *func2(void *arg)
{
    for(int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex);

        while(k%3 != 1) {
            pthread_cond_wait(&cond, &mutex);
        }

        printf("B\n");
        k++;
        // sleep(1);

        pthread_mutex_unlock(&mutex);
        pthread_cond_broadcast(&cond);
    }

}

void *func3(void *arg)
{
    for(int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex);

        while(k%3 != 2) {
            pthread_cond_wait(&cond, &mutex);
        }

        printf("C\n");
        k++;
        // sleep(1);

        pthread_mutex_unlock(&mutex);
        pthread_cond_broadcast(&cond);
    }

}

int main()
{
    pthread_t tid1, tid2, tid3;

    pthread_create(&tid1, NULL, func1, NULL);
    pthread_create(&tid2, NULL, func2, NULL);
    pthread_create(&tid3, NULL, func3, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}

*/

/*

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


/*
    C语言实现函数重载(C语言不能函数不能同名,使用函数指针去除掉这个限制)

    使用函数指针来实现,重载的函数不能使用相同名称,只是类似的实现了函数重载功能
    重载函数使用可变参数
*/
/*
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


void printStirng2()
{
    std::unique_lock<std::mutex> lock(mut);

    while(1)
    {
        // std::cout << "hello" << std::endl;
        while(k != 2) cv.wait(lock);

        for(int i = 0; i < s2.size(); i++) {
            std::cout << s2[i] ;
        }

        // std::cout << "B" << std::endl;
        sleep(1);

        k = 1;
        cv.notify_all();
    }
    
}

/*
void printStirng3()
{
    std::unique_lock<std::mutex> lock(mut);

    while(1)
    {
        while(k != 3) cv.wait(lock);

        std::cout << "C" << std::endl;
        sleep(1);

        k = 1;
        cv.notify_all();
    }
    
}*/
/*
int main() {
    int a = 23;
    double b = 23.23;

    c_func(func_int, &a);
    c_func(func_double, &b);

    return 0;
}


std::mutex mut;
std::condition_variable cv;

int k = 1;

std::string s1 = "abcd";
std::string s2 = "1234";

// void printStirng1()
// {
//     std::unique_lock<std::mutex> lock(mut);

//     while(1)
//     {
//         std::cout << "Hi" << std::endl;
//         while(k != 1) cv.wait(lock);

//         for(int i = 0; i < s1.size(); i++) {
//             std::cout << s1[i];
//         }
//         // std::cout << "A" << std::endl;
//         sleep(1);

//         k = 2;
//         cv.notify_all();
//     }

// }

void printString1()
{
    std::unique_lock<std::mutex> lock(mut);

    while(1)
    {
        for(int i = 0; i < s1.size(); i++)
        {
            while(k != 1) cv.wait(lock);
            std::cout << s1[i] << std::endl;
            sleep(1);

            k = 2;

            cv.notify_all();            
        }
    }

}


void printString2()
{
    std::unique_lock<std::mutex> lock(mut);

    while(1)
    {
        for(int i = 0; i < s2.size(); i++)
        {
            while(k != 2) cv.wait(lock);
            std::cout << s2[i] << std::endl;

            sleep(1);

            k = 1;

            cv.notify_all();
        }
    }

}



int main() {
    // std::thread t1(printString1);
    // std::thread t2(printString2);
    // // std::thread t3(printStirng3);

    // t1.join();
    // t2.join();
    // t3.join();

    // int i = 0, j = 1, k = 2;
    // int num = ++i||--j&&++k;

    // std::cout << num << std::endl;

    int i = 217;
    int arr[i] = {0};

    return 0;
}*/



#include <iostream>
#include <vector>
#include <thread>
#include <unistd.h>
#include <condition_variable>

template<typename ... Args> 
void g(Args ... args) {
    std::cout << sizeof...(Args) << std::endl;
    std::cout << sizeof...(args) << std::endl;
}

template<typename It>
auto fcn(It beg, It end) -> decltype(*beg) {
    return *beg;
}





std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2)
{
    std::unordered_map<int,int> mp;
    for(const int &n : nums1) mp[n]++;

    std::vector<int> res;

    for(const int &n : nums2) {
        if(mp.count(n) && mp[n]-- > 0) res.push_back(n);
    }

    return res;
}

