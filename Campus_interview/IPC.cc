
/*
    实现三个进程顺序打印
*/


#include <iostream>
#include <thread>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int ready = 1;

void printString_1()
{
    std::unique_lock<std::mutex> lk(mtx);

    int cnt = 0;
    while(cnt < 10)         //控制打印十次
    {
        while(ready != 1) cv.wait(lk);  //线程wait时会自动放弃所拥有的锁并阻塞等待; 当被唤醒时则又自动尝试申请获得原来所拥有的锁

        std::cout << std::this_thread::get_id() << " " << "A" << std::endl;

        ready = 2;
        cnt++;
        cv.notify_all();
    }
}

void printString_2()
{
    std::unique_lock<std::mutex> lk(mtx);

    int cnt = 0;
    while(cnt < 10)
    {
        while(ready != 2) cv.wait(lk);

        std::cout << std::this_thread::get_id() << " " << "B" << std::endl;

        ready = 3;
        cnt++;
        cv.notify_all();
    }
}

void printString_3()
{
    std::unique_lock<std::mutex> lk(mtx);

    int cnt = 0;
    while(cnt < 10)     
    {
        while(ready != 3) cv.wait(lk);

        std::cout << std::this_thread::get_id() << " " << "C" << std::endl;

        ready = 1;
        cnt++;
        cv.notify_all();
    }
}

//编译的时候需要链接线程库 -lpthread
int main() {
    std::thread t1(printString_1);
    std::thread t2(printString_2);
    std::thread t3(printString_3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}   


/*
    两个线程,一个线程打印数字1234,一个线程打印字母abc,要求交替打印a1b2c3d4a1b2...
*/


#include <iostream>
#include <thread>
#include <condition_variable>
#include <unistd.h>

std::mutex mut;
std::condition_variable cv;

int k = 0;  //区分线程

std::string s1 = "abcd";
std::string s2 = "1234";

void print1()
{
    std::unique_lock<std::mutex> lock(mut);

    while(1) 
    {
        for(int i = 0; i < s1.size(); i++) 
        {        
            while(k != 0) cv.wait(lock);
            std::cout << s1[i] << std::endl;    //如果这里写 printf("%c", s[i]) 则会卡住
            k = 1;

            sleep(1);           //打印完暂停一秒看出变化
            
            cv.notify_all();
        }
    }

}

void print2()
{
    std::unique_lock<std::mutex> lock(mut);

    while(1)
    {
        for(int i = 0; i < s2.size(); i++) 
        {       
            while(k != 1) cv.wait(lock);
            std::cout << s2[i] << std::endl;
            k = 0;
            sleep(1);   
            cv.notify_all();
        }
    }

}

int main() {
    std::thread t1(print1), t2(print2);

    t1.join();
    t2.join();

    return 0;
}






/*
    十个人排队使用打印机，任一时刻只能有一个人使用，用一个变量0和1两种状态分别表示这台打印机能不能使用
*/


#include <iostream>
#include <thread>
#include <condition_variable>
#include <vector>

std::vector<std::thread> tv;    //保存线程的状态
std::condition_variable cv;
std::mutex mut;

int i = 1;      //打印机资源，初始化为1，表示可用

/*
std::condition_variable_any cv;     //下面使用自动锁，则这里需要使用_any
void subi()
{
    std::lock_guard<std::mutex> locker(mut);    //使用自动锁，调用即加锁，离开作用域即解锁

    while(i == 0) {
        cv.wait(mut);     //资源不可用则阻塞等待
    }

    i--;    //可以使用打印机
}

void addi()
{
    std::lock_guard<std::mutex> locker(mut);

    i++;                //将资源变为可用
    cv.notify_all();    //通知其他阻塞的线程可以使用了
}
*/

void subi()
{
    std::unique_lock<std::mutex> lock(mut);     //加锁

    while(i == 0) {
        cv.wait(lock);
    }

    i--;

    cv.notify_all();
}

void addi()
{
    std::unique_lock<std::mutex> lock(mut);

    i++;        //对共享资源的访问一定要加锁

    cv.notify_all();
}



void func(int j)
{
    subi();     //模拟使用打印机
    std::cout << "I am thread " << j << ", i = " << i << std::endl;
    addi();     //使用完归还打印机资源
}


int main() {
    for(int j = 0; j < 10; j++) {
        std::thread t(func, j);
        tv.push_back(std::move(t));
    }

    for(auto &thread : tv) {
        thread.join();
    }

    return 0;
}




/*
    多线程顺序打印
*/

#include <iostream>
#include <pthread.h>
#include <unistd.h>


int k = 0;

pthread_mutex_t mutex;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *fun1(void *arg)
{
    for(int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex);      //加锁
        
        while(k%3 != 0) {
            pthread_cond_wait(&cond, &mutex);   //条件不满足,则阻塞等待
        }

        printf("A\n");
        k++;        
        // sleep(1);

        pthread_mutex_unlock(&mutex);    // 解锁
        pthread_cond_broadcast(&cond);   // 唤醒阻塞在此条件变量上的所有线程
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
        // sleep(1);

        pthread_mutex_unlock(&mutex);    
        pthread_cond_broadcast(&cond);  
    }

}


void *fun3(void *arg)
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
    pthread_mutex_init(&mutex, NULL);       //初始化一个互斥锁(可以直接使用静态初始化)

    pthread_t tid1, tid2, tid3;

    pthread_create(&tid1, NULL, fun1, NULL);
    pthread_create(&tid2, NULL, fun2, NULL);
    pthread_create(&tid3, NULL, fun3, NULL);

    // 阻塞等待线程回收
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}



/*
    模拟猴子吃桃问题
    生产者和消费者问题
*/

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
    pthread_mutex_init(&lock, NULL);    // 互斥锁也可以静态初始化

    pthread_create(&th_peach, NULL, eat, NULL);
    pthread_create(&th_monkey, NULL, grow, NULL);

    pthread_join(th_peach, NULL);
    pthread_join(th_monkey, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&can_eat);
    pthread_cond_destroy(&can_grow);

    return 0;
}