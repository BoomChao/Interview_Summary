

/*

利用快慢指针原理:设置两个指针*search,*mid都指向单链表的头结点;(重点在于区分头结点和头指针)
其中*search的移动速度是*mid的两倍;
则当*search指向末尾节点的时候,则mid就正好在中间了

*/

//对链表个数为奇数,恰好能找到中间节点;
//对链表个数为偶数,如链表个数为4,则找到的是第2号节点
// int GetMidNode(LinkList L, Elemtype *e)
// {
//     LinkList search, mid;
//     mid = search = L;   //使mid和search指向链表头结点

//     while(search->next != NULL)
//     {
//         if(search->next->next != NULL){
//             search = search->next->next;
//             mid = mid->next;
//         }else{
//             search = search->next;
//         }

//     }

//     *e = mid->data;    //*e表示链表中间节点的数据

//     return 1;

// }


// bool fun(int number)
// {
//     if(number < 0) return false;
//     int s = number;
//     int y = 0;
//     do{
//         y = y*10 + s%10;
//         s = s/10;

//     }while(s != 0);
    
//     if(y == number){
//         return true;
//     }else{
//         return false;
//     }

// }

// #include <iostream>

// int main(){
//     int n = 1201;
    
//     if(fun(n)){
//         std::cout << "Success" << std::endl;
//     }else{
//         std::cout << "Failure" << std::endl;
//     }

//     return 0;

// }

/*
#include <iostream>

void print();

int main(){
    print();

    printf("\n");

    return 0;
}



void print(){
    char a;
    scanf("%c", &a);
    if(a != '#') print();   //以#作为结束标记
    if(a != '#') printf("%c", a);

}
*/

/*
#include <iostream>

int main(){
    int a[5] = {2};
    std::cout << a[4] << std::endl;

    return 0;
}

*/

/*
#include <iostream>

//声明两个全局变量
int findValue[2000] = {2};  //题目说了有足够的内存,可以这样使用数组
static int find = 1;    //find为findVlaue数组中元素的个数;即素数的个数

bool adjust(int value);

int main(){
    for(int i = 2; i <= 25; i++) adjust(i);

    for(int i = 0; i < find; i++){
        std::cout << findValue[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

bool adjust(int value)
{
    if(value == 2){
        return true;
    }else{
        for(int i = 0; i < find; i++){
            if(value % findValue[i] == 0)   return false;   //判断当前数是否能被已查找出的素数整除
        }                                                   //能被已经查找出的素数整除的数当然就不是素数
        findValue[find++] = value;  //此等同于find[find] = value; find++;
    }   //不能写成findValue[++find] = value;否则会报错

}
*/


/*
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};




ListNode* getMidNode(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;

    while(fast->next != nullptr){
        if(fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }else{
            slow = slow->next;
        }
    }

    return slow;

}
*/





/*
//这是小甲鱼的版本
typedef int Elemtype;

void GetMidNode(LinkList L, Elemtype *e)
{
    LinkList search, mid;   //search代表快指针,mid代表慢指针
    mid = search = L;   //使mid和search指向链表第一个结点

    while(search->next != NULL)
    {
        if(search->next->next != NULL){
            search = search->next->next;
            mid = mid->next;
        }else{
            search = search->next;
        }

    }

    *e = mid->data;    //*e表示链表中间节点的数据

}
*/

// #include <iostream>

// void swap1(int &x, int &y);
// void swap2(int &x, int &y);

// int main(){
//     int num_1 = 5, num_2 = 10;
//     swap2(num_1, num_2);
//     std::cout << "num_1 = " << num_1 << std::endl;
//     std::cout << "num_2 = " << num_2 << std::endl;

//     return 0;
// }

// //解法一:基于加减法
// void swap1(int &x, int &y)
// {
//     x = x-y;
//     y = y+x;
//     x = y-x; 
// }


// //解法二:基于位运算
// void swap2(int &x, int &y)
// {
//     x = x^y;
//     y = x^y;
//     x = x^y;
    
// }

/*

#include <iostream>

void fun(int n, int m) ;

int main(){
    fun(4, 6);
    std::cout << std::endl;

    return 0;
}



void fun(int n, int m)  //n是总人数,m是序数
{
    bool a[n+1] = {0}; //用1表示被杀,0表示未被杀掉;刚开始所有人都是0(未被杀)
    int f = 0, t = 0, s = 0;

    do{
        ++t;
        if(t > n) t = 1;
        if(!a[t]) s++;
        if(s == m){
            s = 0;
            std::cout << t << " ";
            a[t] = 1;	//该人被杀,标记为1
            f++; 
        }

    }while(f != n);

}


// void fun(int n, int m)    //n是总人数,m是序数
// {
//     bool a[n+1] = {0};    //a是标记数组
//     int f = 0, t = 0, s = 0;

//     do{
//         t++;
//         if(t > n) t = 1;
//         if(!a[t]) s++;
//         if(s == m){
//             s = 0;
//             std::cout << t << " ";
//             a[t] = 1;   //标记位为1表示该人被杀
//             f++
//         }
//     }while(f != n)

// }

*/


/*
#include <iostream>
#include <vector>
#include <algorithm>


std::string transfer(int num);
std::string transferFrom10To2(int num);

int main() {
    int num = 100;
    // std::cout << transfer(num) << std::endl;

    // std::string transferFrom10To2(int num);
    std::cout << transferFrom10To2(num) << std::endl;

    // shuffle(nums); 
    // std::string str = "I love you";
    // std::cout << reverseWords(str) << std::endl;

    // srand(time(0));
    // std::cout << rand()%4 << std::endl;


    return 0;
}


std::string transferFrom10To2(int num)
{
    // std::string res;
    // while(num) {
    //     int b = num % 2;
    //     res = std::to_string(b) + res;
    //     num = num/2;
    // }
    if(num == 0) return "0";

    std::string bin = "01";
    std::string res;
    int count = 0;
    while(num && count++ < 32)
    {
        res = bin[num & 1] + res;
        num >>= 1;
    }

    return res;
}
/*

void OddInOddEvenInEven(std::vector<int> &nums)
{
    if(nums.size() <= 1) return;

    int i = 0, j = 1;
    while(i < nums.size() && j < nums.size())
    {
        //判断nums[i]是否为偶数,如果为偶数则向前进两位到达下一个偶数位
        while(i < nums.size() && (nums[i]%2 == 0)) {
            i += 2;   
        }

        while(j < nums.size() && (nums[j]%2 == 1)) {
            j += 2;
        }
        
        if(i < nums.size() && j < nums.size()) {
            std::swap(nums[i], nums[j]);
        }
    }

}


void shuffle(std::vector<int> &nums)
{
    srand(time(0));

    for(int i = nums.size() - 1; i > 0; i--) {
        int j = random() % (i+1);
        std::swap(nums[i], nums[j]);
    }

    for(int &num : nums) {
        std::cout << num << " ";
    }

    std::cout << std::endl;
}

std::string reverseStr(std::string &str)
{
    if(str.empty()) return str;

    int left = 0, right = 0;
    while(right <= str.size())
    {
        if(str[right] == ' ' || right == str.size()) {
            reverse(str.begin() + left, str.begin() + right);
            left = right + 1;
        }

        right++;
    }


    reverse(str.begin(), str.end());

    return str;
}

void moveZeros(std::vector<int> &nums)
{
    if(nums.empty()) return ;

    int cur = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] != 0) {
            std::swap(nums[cur++], nums[i]);
        }
    }

}

int firstMissingPositive(std::vector<int> &nums)
{
    int j = 1;
    std::vector<int> tmp(nums.size(), 0);
    for(int i = 0; i < tmp.size(); i++) {
        tmp[i] = j++;
    }

    for(int i = 0; i < nums.size(); i++) {
        if(find(tmp[i], nums)) continue;
        else return tmp[i];
    }

    return nums.size() + 1;
}

bool find(int target, std::vector<int> &nums)
{
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == target) return true;
    }

    return false;
}


int firstMissingPositive(std::vector<int> &nums)
{
    int n = nums.size();
    for(int i = 0; i < n; i++)
    {
        while(nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i]) {
            std::swap(nums[i], nums[nums[i]-1]);
        }
    }

    for(int i = 0; i < n; i++) {
        if(nums[i] != i+1) {
            return i + 1;
        }
    }
    
    return n + 1;   //如果数据是完整的,比如nums={1,2,3},则应该返回(数组长度+1)
}

*/
/*
#include <iostream>
#include <cstring>

void* myMemcpy(void *dest, void *src, unsigned int size);

int main() {
    // int a[10] = {0,1,2,3,4,5,6,7,8,9};
    // unsigned int n = 3;
    // void *p = memcpy(a + 3, a, n);

    // char *target = (char*)malloc(sizeof(char)*10);
    char target[] = "0123456789";
    char target1[] = "0123456789";
    memcpy(target + 3*sizeof(char), target, 5*sizeof(char));
    myMemcpy(target1 + 3*sizeof(char), target1, 5*sizeof(char));

    puts(target);
    puts(target1);

    return 0;
}

void* myMemcpy(void *dest, void *src, unsigned int size)
{
    char *pdest = NULL, *psrc = NULL;

    //判断是否存在内存重叠
    if((src < dest) && (char*)src + size > (char*) dest)
    {
        //从后往前复制
        psrc = (char*)src + size - 1;
        pdest = (char*)dest + size - 1;

        while(size--) {
            *pdest-- = *psrc--;
        }
    }
    else
    {
        //不存在内存重叠则从前往后复制
        psrc = (char*)src;
        pdest = (char*)dest;

        while(size--) {
            *pdest++ = *psrc++;
        }
    }

    return (void*)dest;
}

*/

/*
#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums = {4,4,4,1};
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        nums[(nums[i]-1)%n] += n;   //注意:这里要取余,因为前面的数会改变掉后面的数的值
    }

    for(int i = 0; i < n; i++) {
        nums[i] = (nums[i]-1)/n;
    }

    for(int num:nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
*/

/*
#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> &nums);
void selectSort(std::vector<int> &nums);
void insertSort(std::vector<int> &nums);
void shellSort(std::vector<int> &nums);
void heapAdjust(std::vector<int> &nums, int start, int end);
void heapSort(std::vector<int> &nums, int len);
void mergeSort(std::vector<int> &nums, int left, int right);
void merge(std::vector<int> &nums, int left, int mid, int right);
void quickSort(std::vector<int> &nums, int left, int right);
int partition(std::vector<int> &nums, int left, int right);


int main() {
    std::vector<int> nums = {3,0,2,1,5,6};

    // bubbleSort(nums);
    // selectSort(nums);
    // insertSort(nums);
    // shellSort(nums);
    // heapSort(nums, nums.size()-1);
    quickSort(nums, 0, nums.size() - 1);

    for(int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}


//冒泡排序
//思想:由下往上,两两比较,将最小的数冒泡到最上面(也就是数组的首部)

//时间复杂度最好为O(n),这时数组是顺序的,只需要做(n-1)比较
//最差为O(n^2),这时数组恰好为逆序的
//平均就是O(n^2)

void bubbleSort(std::vector<int> &nums)
{
    bool flag = true;

    for(int i = 0; i < nums.size() && flag; i++)
    {
        flag = false;
        for(int j = nums.size() - 2; j >= i; j--)
        {
            if(nums[j] > nums[j+1]) {
                std::swap(nums[j], nums[j+1]);
                flag = true;
            }
        }
    }

}


//选择排序
//思想:每一趟依次找到最小的元素与首部元素进行交换

//时间复杂度:最好最差和平均都是O(n^2),因为无论数据是否有序,比较的次数都是一样多

void selectSort(std::vector<int> &nums)
{
    for(int i = 0; i < nums.size(); i++)
    {
        int min = i;
        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[min] > nums[j]) {
                min = j;
            }
        }

        if(i != min) {
            std::swap(nums[i], nums[min]);
        }
    }

}


//插入排序
//思想:将一个新的元素插入到已经排好序的序列中

//时间复杂度:最好为O(n),此时数组本身是有序的,只需(n-1)比较
//最差情况O(n^2),此时数组恰好是倒序的
//平均情况为O(n^2)

void insertSort(std::vector<int> &nums)
{
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] < nums[i-1]) 
        {
            int tmp = nums[i];
            int j;
            for(j = i-1; nums[j] > tmp && j >= 0; j--) {
                nums[j+1] = nums[j];
            }
            nums[j+1] = tmp;
        }
    }

}


//希尔排序
//思想:引入了一个增量,将相隔某个"增量"的记录组成一个子序列,实现跳跃式的移动,从而使得排序效率更高
//注意:增量序列的最后一个增量必须是1才行

//时间复杂度:最好为O(n^1.3)
//最差为O(n^2)
//注意:希尔排序的增量的选取对算法时间复杂度很重要

void shellSort(std::vector<int> &nums)
{
    int gap = nums.size();
    
    do {
        gap = gap/3 + 1;

        for(int i = gap; i < nums.size(); i++)  //注意:这里下标从0开始,所以i=gap,不是书中的gap+1
        {
            if(nums[i] < nums[i-gap]) 
            {
                int tmp = nums[i];
                int j;
                for(j = i-gap; nums[j] > tmp && j >= 0; j -= gap) {
                    nums[j+gap] = nums[j];
                }
                nums[j+gap] = tmp;
            }
        }

    } while(gap > 1);

}


//堆排序
//思想:将所有数据构造成一个大顶堆或者小顶堆

//时间复杂度:可以看出堆排序对原始记录的状态并不敏感,所以最好最差和平均复杂度都为O(nlogn)
//新建一个堆是针对非终端节点的,对于每个非终端节点来说,最多比较两次,所以时间复杂度为O(n)
//在正式排序时,取堆顶和重建堆的时间复杂度为O(nlogn)
//所以总的时间复杂度为O(n+nlogn)

void heapSort(std::vector<int> &nums, int len)
{
    for(int i = len/2; i > 0; i--) {   //建成大顶堆(前面添加的第0个元素不要管,是设置的为了让其下标构成二叉树所做的)         
        heapAdjust(nums, i, len);
    }

    for(int i = len; i > 1; i--) {
        std::swap(nums[1], nums[i]);   //将堆顶记录和当前未排序的子序列的最后一个记录交换
        heapAdjust(nums, 1, i-1);      //将剩下的元素重新调整成大顶堆
    }

}

void heapAdjust(std::vector<int> &nums, int start, int end)
{
    int tmp = nums[start];
    
    for(int j = 2*start; j <= end; j*=2)
    {
        if(j < end && nums[j] < nums[j+1]) j++;

        if(tmp > nums[j]) break;

        nums[start] = nums[j];

        start = j;
    }

    nums[start] = tmp;
}
 


//归并排序(二路归并)

void mergeSort(std::vector<int> &nums, int left, int right)
{
    if(left < right)
    {
        int mid = left + ((right-left) >> 1);
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

}

void merge(std::vector<int> &nums, int left, int mid, int right)
{
    int lindex = left, rindex = mid + 1;
    int *team = new int[right-left+1];
    int teamIndex = 0;

    while(lindex <= mid && rindex <= right)
    {
        if(nums[lindex] < nums[rindex]) {
            team[teamIndex++] = nums[lindex++];
        }
        else {
            team[teamIndex++] = nums[rindex++];
        }
    }

    while(lindex <= mid) {
        team[teamIndex++] = nums[lindex++];
    }

    while(rindex <= right) {
        team[teamIndex++] = nums[rindex++];
    }

    for(int i = 0; i < teamIndex; i++) {
        nums[left+i] = team[i];
    }

    delete[] team;
}


//快速排序

void quickSort(std::vector<int> &nums, int left, int right)
{
    if(left < right)
    {
        int pivot = partition(nums, left, right);
        quickSort(nums, left, pivot - 1);
        quickSort(nums, pivot + 1, right);
    }

}

int partition(std::vector<int> &nums, int left, int right)
{
    int pivot = nums[left];

    while(left < right)
    {
        while(left < right && nums[right] >= pivot) right--;
        std::swap(nums[left], nums[right]);

        while(left < right && nums[left] <= pivot) left++;
        std::swap(nums[left], nums[right]);
    }

    return left;
}
*/

/*
#include <iostream>
#include <algorithm>
#include <vector>

// template<class T>
// struct greater : public binary_function<T, T, bool> {
//     bool operator()(const T &x, const T &y) const {
//         return x > y;
//     }
// };

// template<class T>
// struct less : public binary_function<T, T, bool> {
//     bool operator()(const T &x, const T &t) const {
//         return x < y;
//     }
// };

bool myfunction(int i, int j) {
    return i < j;
}

void shellSort(std::vector<int> &nums);
void insertSort(std::vector<int> &nums);
void heapAdjust(std::vector<int> &nums, int start, int end);
void heapSort(std::vector<int> &nums, int len);

union Test 
{
    int num;
    char c;
};

// void GetIntA(int &p) {
//     p = (int*)malloc(sizeof(int));
//     return;
// }


class A
{
public:
    void print(int n) {
        std::cout << n << std::endl;
    }

};


int main() {
    // union Test test;
    // test.num = 1;

    // std::cout << (int)test.c << std::endl;
    // // int a = 0x00001234;

    // // char *p = (char*)(&a);

    // // printf("0x%x\n", (int)*p);
    // // printf("0x%x\n", (int)*(p+1));
    // // printf("0x%x\n", (int)*(p+2));

    // // std::cout << a << std::endl;

    // int a = (int)(((int*)0) + 4);
    // int *p = 0;
    // p = p + 4;

    // // int a = (int)p;
    // int a = static_cast<int>(p);

    // std::cout << a << std::endl;

    // std::string str = "123";

    // std::cout << sizeof(str) << std::endl;

    // ((A*)0)->print(4);

    // char buf[4] = {0x12, 0x34, 0x56, 0x78};
    
    // std::cout << *(short*)(&buf[3]) << std::endl;

    int b = 129;
    char c = b;
    printf("%d\n", c);

    return 0;
}

bool isPalindrome(ListNode *head)
{
    if(head->next == nullptr) return true;

    ListNode *slow = head, *fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow = reverList(slow);

    while(head && slow) {
        if(head->val != slow->val) return false;
        head = head->next;
        slow = slow->next;
    }

    return true;
}

ListNode* reverList(ListNode *head)
{
    ListNode *prev = nullptr;

    while(head) 
    {
        ListNode *pNext = head->next;
        head->next = prev;
        prev = head;
        head = pNext;
    }

    return prev;
}




void insertSort(std::vector<int> &nums)
{
    for(int j = 1; j < nums.size(); j++)
    {
        if(nums[j-1] > nums[j]) {
            int tmp = nums[j];
            int i = j-1;
            for(; i >= 0 && nums[i] > tmp; i--) {
                nums[i+1] = nums[i];
            }
            nums[i+1] = tmp;
        }
    }

}


// void shellSort(std::vector<int> &nums)
// {
//     int gap = nums.size();

//     do {
//         gap = gap/3 + 1;

//         for(int i = gap; i < nums.size(); i++)
//         {
//             if(nums[i] < nums[i-gap]) {
//                 int tmp = nums[i];
//                 int j = i - gap;
//                 for(; j >= 0 && nums[j] > tmp; j -= gap) {
//                     nums[j+gap] = nums[j];
//                 }                
//                 nums[j+gap] = tmp;
//             }
//         }


//     }while(gap > 1);

// }


void shellSort(std::vector<int> &nums)
{
    int gap = nums.size();
    
    do {
        gap = gap/3 + 1;

        for(int i = gap; i < nums.size(); i++)
        {
            if(nums[i-gap] > nums[i]) {
                int tmp = nums[i];
                int j = i - gap;
                for(; j >= 0 && nums[j] > tmp; j -= gap) {
                    nums[j+gap] = nums[j];
                }
                nums[j+gap] = tmp;
            }
        }

    }while(gap > 1);

}

void heapSort(std::vector<int> &nums, int len)
{
    for(int i = len/2; i > 0; i--) {
        heapAdjust(nums, i, len);
    }

    for(int i = len; i > 1; i--) {
        std::swap(nums[1], nums[i]);
        heapAdjust(nums, 1, i - 1);
    }

}

void heapAdjust(std::vector<int> &nums, int start, int end)
{
    int tmp = nums[start];

    for(int j = 2*start; j <= end; j *= 2)
    {
        if(j < end && nums[j] < nums[j+1]) j++;

        if(tmp > nums[j]) break;

        nums[start] = nums[j];

        start = j;
    }

    nums[start] = tmp;

}
*/
/*
#include <iostream>
#include <vector>

class Singleton
{
private:
    Singleton() {}  
    Singleton(const Singleton &);
    Singleton& operator=(const Singleton &);

public:
    static Singleton& getInstance() 
    {
        static Singleton instance;
        return instance;
    }

    void print() {
        std::cout << "do something..." << std::endl;
    }

};

int main() {
    // Singleton &demo = Singleton::getInstance();
    // demo.print();

    return 0;
}
*/
/*
#include <iostream>

class Singleton
{
private:
    Singleton() {}
    Singleton(const Singleton &);
    Singleton& operator=(const Singleton&);

public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void print() {
        std::cout << "do something..." << std::endl;
    }

};

int main() {
    // Singleton::getInstance().print();
    Singleton demo;

    return 0;
}


//1.实现赋值运算符函数

class CMyString
{
public:
    CMyString(char *pData = nullptr);
    CMyString(const CMyString &str);
    ~CMyString();

private:
    char *m_pData;

};

//第一种解法
CMyString& CMyString::operator=(const CMyString &str)
{
    if(this != &str)
    {
        delete[] m_pData;
        m_pData = nullptr;

        m_pData = new char[strlen(str) + 1];    //存在一个隐患，如果分配内存失败,则是会抛出异常的
        strcpy(m_pData, str.m_pData);          //则m_pData是一个空指针,这样非常容易导致程序崩溃
    }                                          //也即CMyString的实例也不存在了,在申请内存之前释放掉了

    return *this;
}

//第二种写法:考虑线程安全
CMyString& CMyString::operator=(const CMyString &str)
{
    if(this != &str)
    {
        CMyString strTmp(str);      //先申请一个临时对象申请够足够的内存,如果程序崩溃了原对象还存在

        char *pTmp = strTmp.m_pData;
        strTmp.m_pData = m_pData;   //strTmp的m_pData指向的是实例之前的内存,所以相当于自动调用析构函数释放内存
        m_pData = pTmp;
    }

    return *this;
}
*/
/*
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
/*
class string 
{
private:
    char* pStr;
    unsigned int size;

public:
    string(const char *str = nullptr) 
    {
        if(str == nullptr) {
            pStr = new char[1];
            *pStr = '\0';
            size = 0;
        }
        else {
            int len = strlen(str);
            pStr = new char[len + 1];
            strcpy(pStr, str);
            size = len;
        }
    }

    string(const string &str) : pStr(new char[str.size + 1])
    {
        std::cout << "拷贝构造函数"<< std::endl;
        strcpy(pStr, str.pStr);
        size = str.size;
    }

    string operator=(const string &str) 
    {
        if(this != &str)
        {
            // string strTmp(str);

            // char *pSTrTmp = strTmp.pStr;
            // strTmp.pStr = pStr;
            // pStr = pSTrTmp;
            
            char *pStr = new char[str.size + 1];
            strcpy(pStr, str.pStr);
            size = str.size;
        }

        return *this;
    }

    ~string() 
    {
        // std::cout << "析构" << std::endl;
        delete[] pStr;
    }
};

*/
/*
bool judgePoint(std::vector<int> &nums);
bool isValid(std::vector<int> nums, int tmp);


int main() {
    std::vector<int> nums = {9,2,1,1};

    std::cout << judgePoint(nums) << std::endl;

    return 0;
}


//加减乘除计算24点(不包含括号运算)
//典型的DFS

//思路:四个数字轮流拿出来充当第一个数,并将拿出来的数从数组中删除
//之后递归,判断这个拿出来的数与下一个数的和,差,商,积,计算完后将下一个数踢出数组
//以此递归知道数组中已经没有元素,判断此时和是否为24点

bool judgePoint(std::vector<int> &nums)
{
    std::vector<int> tmpNum = nums;

    for(int i = 0; i < tmpNum.size(); i++)
    {
        int tmp = tmpNum[i];
        tmpNum.erase(tmpNum.begin() + i);
        if(isValid(tmpNum, tmp)) return true;
        tmpNum = nums;
    }

    return false;
}

bool isValid(std::vector<int> nums, int tmp)
{
    if(!nums.empty())
    {
        for(int i = 0; i < nums.size(); i++)
        {
            int n = nums[i];
            nums.erase(nums.begin() + i);;
            if(isValid(nums, tmp*n) || isValid(nums, tmp+n) || isValid(nums, tmp-n) || (n && isValid(nums,tmp/n))) {
                return true;
            }
        }
    }

    if(tmp == 24) return true;

    return false;
}


ListNode* mergeKLists(std::vector<ListNode*> &lists)
{
    if(lists.empty()) return nullptr;

    int len = lists.size();
    while(len > 1)
    {
        for(int i = 0; i < len/2; i++) {
            lists[i] =  mergeTwoList(lists[i], lists[len-1-i]);
        }

        len = (len+1) >> 1;
    }

    return lists[0];
}


ListNode* mergeTwoList(ListNode*l1, ListNode *l2)
{
    if(l1 == nullptr) return l2;
    else if(l2 == nullptr) return l1;

    if(l1->val < l2->val) {
        l1->next = mergeTwoList(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoList(l1, l2->next);
        return l2;
    }

}

ListNode* mergeTwoList(ListNode *l1, ListNode *l2)
{
    ListNode *base = new ListNode(-1);
    ListNode *head = base;

    while(l1 && l2)
    {
        if(l1->val < l2->val) {
            base->next = l1;
            l1 = l1->next;
        }
        else {
            base->next = l2;
            l2 = l2->next;
        }

        base = base->next;
    }

    base->next = l1 ? l1 : l2;

    return head->next;
}
*/

/*
#include <iostream>
#include <vector>
#include <unordered_map>

std::string subTwoNumber(std::string str1, std::string str2);
bool bigger(std::string str1, std::string str2);

// long long findMaxButtons(std::vector<int> &buttons);

// int findMaxLength(std::string s);
// void dfs(std::vector<int> &nums, std::vector<int> &count, int pos);

int main() {

    std::string str1 = "90", str2 = "90";

    std::cout << subTwoNumber(str1, str2) << std::endl;


    return 0;
}

/*
void dfs(std::vector<int> &nums, std::vector<int> &count, int pos)
{
    if(pos > 9) {
        if(nums[0]*100 + nums[1]*10 + nums[2] + nums[3]*100 + nums[4]*10 + nums[5] == nums[6]*100 + nums[7]*10 + nums[8]) {
            printf("%d%d%d + %d%d%d = %d%d%d\n", nums[0], nums[1], nums[2], nums[3], nums[4], nums[5], nums[6], nums[7], nums[8]);
        }
        return ;
    }

    for(int i = 0; i <= 9; i++)
    {
        if(count[i] == 1) continue;
        nums[pos] = i;  //将该位置赋值
        count[i] = 1;   //标记已经用过的数
        dfs(nums, count, pos + 1);
        count[i] = 0;   //回溯
    }

}

int findMaxLength(std::string s)
{
    std::vector<int> count(2), dp(s.size());

    int res = 0;

    for(int i = 0; i < s.size(); i++)
    {
        count[s[i]-'0']++;
        dp[i] = count[1] - count[0];
        if(dp[i] == 0) {
            res = i + 1;
        }
    }

    std::unordered_map<int,std::vector<int>> mp;
    for(int i = 0; i < dp.size(); i++) {
        mp[dp[i]].push_back(i);
    }

    for(auto m : mp) {
        res = std::max(res, m.second.back() - m.second.front());
    }

    return res;
}


long long findMaxButtons(std::vector<int> &buttons)
{
    long long res = 0;
    for(int i = 0; i < buttons.size(); i++) {
        res += buttons[i] + (buttons[i]-1)*i;
    }

    return res;
}
*/

/*
std::string subTwoNumber(std::string str1, std::string str2)
{
    std::string res;
    if(str1 == str2) {
        return "0";
    }

    bool positive = bigger(str1, str2);

    if(!positive) {
        std::swap(str1, str2);
    }

    while(str2.size() < str1.size()) {
        str2 = "0" + str2;
    }

    for(int i = str1.size() - 1; i >= 0; i--)
    {
        if(str1[i] < str2[i] && i > 0) {
            str1[i-1]--;
            str1[i] += 10;
        }

        str1[i] -= (str2[i]-'0');       //注意:这里容易出错
    }    

    res = str1;

    if(!positive) {
        res = '-' + res; 
    }

    return res;
}

bool bigger(std::string str1, std::string str2)
{
    if(str1.size() != str2.size()) return str1.size() > str2.size();

    for(int i = 0; i < str1.size(); i++) {
        if(str1[i] != str2[i]) {
            return str1[i] > str2[i];
        }
    }

}



std::string multiplyTwoNumber(std::string num1, std::string num2)
{
    int m = num1.size(), n = num2.size();
    std::string res(m + n, '0');

    for(int i = m-1; i >= 0; i--) {
        for(int j = n-1; j >= 0; j--) {
            int prod = (num1[i]-'0')*(num2[j]-'0') + res[i+j+1];
            res[i+j+1] = prod%10;
            res[i+j] += prod/10;
        }
    }

    for(int i = 0; i < res.size(); i++) {
        if(res[i] != '0') {
            return res.substr(i);
        }
    }

    return "0";
}
*/


/*
#include <iostream>
#include <vector>
#include <string.h>

void* memcpy(void *dest, void *src, size_t size);

class Singleton
{
private:
    Singleton(){};
    Singleton(const Singleton&);
    Singleton& operator+(const Singleton&);

public:
    static Singleton& getInstance() {
        static Singleton demo;
        return demo;
    }

    void print() {
        std::cout << "hello" << std::endl;
    }

};


void* memcpy(void *dest, void *src, size_t size)
{
    if(dest == NULL || src == NULL) return NULL;

    char *psrc = NULL, *pdest = NULL;

    if(src < dest && (char*)src + size > (char*)dest)
    {
        psrc = (char*)src + size - 1;
        pdest = (char*)dest + size - 1;

        while(size--) {
            *pdest-- = *psrc--;
        }
    }
    else 
    {
        psrc = (char*)src, pdest = (char*)dest;
        while(size--) {
            *pdest++ = *psrc++;
        }
    }

    return (void*)dest;
}


class String
{
private:
    char *pStr;
    unsigned int size;

public:
    String(const char *str = NULL)
    {
        if(str == NULL) {
            pStr = new char[1];
            *pStr = '\0';
            size = 0;
        }
        else
        {
            int len = strlen(str);
            pStr = new char[len+1];
            strcpy(pStr, str);
            size = len;
        }

    }

    String(const String &str)
    {
        int len = str.size;
        pStr = new char[len+1];

        strcpy(pStr, str.pStr);
        size = len;
    }

    String& operator=(const String &str)
    {
        if(this != &str)
        {
            delete [] pStr;
            int len = str.size;
            pStr = new char[len+1];
            strcpy(pStr, str.pStr);
            size = len;
        }

        return *this;
    }

    ~String() 
    {
        delete [] pStr;
        printf("析构\n");
    }

    void print() {
        printf("%s\n", pStr);
    }
};





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
        count = smartPtr.count;

        (*count)++;
    }

    shared_ptr& operator=(const shared_ptr &smartPtr)
    {
        if(ptr != smartPtr.ptr)
        {
            //需要先减去原来的指针的引用计数,如果引用计数为0,则需要释放原来的内存再进行赋值
            //但是如果指针原来指向为空,则引用奇数为0,不能再减了
            if(ptr != nullptr) 
            {
                (*count)--;
                if((*count) == 0) {
                    delete ptr;
                    delete count;
                }
            }

            ptr = smartPtr.ptr;
            count = smartPtr.count;
            (*count)++;
        }

    }

    //取指针指向的值(返回的是引用)
    T& operator*()
    {
        if(ptr != nullptr) {
            return *ptr;
        }
    }

    //注意:->操作符返回的是地址;  p->fun(); 等价于 (*p).fun();
    //使用指针直接->指向函数地址,p需要是一个指针
    T& operator->() {
        if(ptr != nullptr) {
            return ptr;
        }
    }

    //只能指针只有当引用计数等于0时才释放指向的内存
    ~shared_ptr() 
    {
        //为空则说明该只能指针没有直接向任何对象,只释放count的内存
        if(ptr == nullptr) {
            std::cout << "释放空指针" << std::endl;
            delete count;
        }
        else if(--(*count) == 0) {
            delete ptr;
            delete count;
        }

    }

    //返回引用计数
    int use_count() {
        return *count;
    }

};



int main() {
    shared_ptr<int> sm(new int(10));

    shared_ptr<int> sm2(sm);

    std::cout << sm.use_count() << std::endl;

    shared_ptr<int> sm3;
    sm3 = sm;
    std::cout << sm.use_count() << std::endl;

    std::cout << *sm3 << std::endl;

    return 0;
}

int res = INT_MIN;

int maxPathSum(TreeNode *root)
{
    maxPathSumCore(root);

    return res;
}

int maxPathSumCore(TreeNode *root)
{
    if(root == nullptr) return 0;

    int leftMax = std::max(0, maxPathSumCore(root->left));  //左子树的最大值(因为路径和的左子树路径也可以是空的)
    int rightMax = std::max(0, maxPathSumCore(root->right));

    res = std::max(res, root->val + leftMax + rightMax);

    return std::max(root->val, root->val + leftMax + rightMax);
}
*/






/*
int rand4() 
{
    return rand()%5;    //生成[0,4]之间的随机数
}

int rand6()
{
    /*
    while(1)
    {
        int num = 5*rand4() + rand4();
        if(num < 21) {
            return num%7;
        }
    }
    */     
    /* 
    //写成上面或者下面这种都可以

    int num = 5*rand4() + rand4();

    while(num > 21)
    {
        num = 5*rand4() + rand4();
    }

    return num%7;
}

void bucketSort(std::vector<int> &nums)
{
    int maxVal = INT_MIN, minVal = INT_MAX;

    for(const int &n : nums) {
        maxVal = std::max(maxVal, n);
        minVal = std::min(minVal, n);
    }

    //计算桶的数量
    int bucketNum = (maxVal - minVal)/nums.size() + 1;  //向上取整

    std::vector<std::vector<int>> buckets(bucketNum, std::vector<int>());

    //每个元素放入桶
    for(int i = 0; i < nums.size(); i++) {
        int num = (nums[i]-minVal)/nums.size();
        buckets[num].push_back(nums[i]);
    }

    //对每个桶进行排序
    for(int i = 0; i < bucketNum; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    //将桶中的元素赋值到原序列
    int index = 0;
    for(int i = 0; i < bucketNum; i++) {
        for(int j = 0; j < buckets[i].size(); j++) {
            nums[index++] = buckets[i][j];
        }
    }

}
*/
/*
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

void bubbleSort(std::vector<int> &nums);
void selectSort(std::vector<int> &nums);
void insertSort(std::vector<int> &nums);
void shellSort(std::vector<int> &nums);
void heapAdjust(std::vector<int> &nums, int start, int end);
void heapSort(std::vector<int> &nums);
void mergeSort(std::vector<int> &nums, int left, int right);
void merge(std::vector<int> &nums, int left, int mid, int right);
void quickSort(std::vector<int> &nums, int left, int right);
int partition(std::vector<int> &nums, int left, int right);
void bucketSort(std::vector<int> &nums);

int main() {
    std::vector<int> nums = {18, 11, 28, 45, 23, 50};
    // std::vector<int> nums = {18, 11, 23};

    // bucketSort(nums, 0, nums.size() - 1);
    bucketSort(nums);

    for(const int &n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}


void bubbleSort(std::vector<int> &nums)
{
    bool flag = true;

    for(int i = 0; i < nums.size() && flag; i++) 
    {
        flag = false;
        for(int j = nums.size()-2; j >= i; j--) 
        {
            if(nums[j] > nums[j+1]) {
                std::swap(nums[j], nums[j+1]);
                flag = true;
            }
        }
    }

}

void selectSort(std::vector<int> &nums)
{
    for(int i = 0; i < nums.size(); i++)
    {
        int min = i;
        for(int j = i+1; j < nums.size(); j++) 
        {
            if(nums[min] > nums[j]) {
                min = j;
            }
        }

        if(i != min) {
            std::swap(nums[min], nums[i]);
        }
    }

}

void insertSort(std::vector<int> &nums)
{
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] < nums[i-1]) 
        {
            int tmp = nums[i];
            int j = i-1;
            for(; nums[j] > tmp && j >= 0; j--) {
                nums[j+1] = nums[j];
            }
            nums[j+1] = tmp;
        }
    }

}


void shellSort(std::vector<int> &nums)
{
    int gap = nums.size();

    while(gap >= 1)
    {
        gap = gap/3 + 1;

        for(int i = gap; i < nums.size(); i++)
        {
            if(nums[i] < nums[i-gap]) 
            {
                int tmp = nums[i];
                int j = i - gap;
                for(; nums[j] > tmp && j >= 0; j -= gap) {
                    nums[j+gap] = nums[j];
                }
                nums[j+gap] = tmp;
            }
        }

        if(gap == 1) break;
    }

}


void heapAdjust(std::vector<int> &nums, int start, int end)
{
    int tmp = nums[start];

    for(int j = 2*start; j <= end; j *= 2)
    {
        if(j < end && nums[j] < nums[j+1]) {
            j++;
        }

        if(tmp >= nums[j]) break;

        nums[start] = nums[j];

        start = j;
    }

    nums[start] = tmp;
}

void heapSort(std::vector<int> &nums)
{
    int len = nums.size() - 1;

    for(int i = len/2; i > 0; i--) {
        heapAdjust(nums, i, len);
    }

    for(int i = len; i > 0; i--) {
        std::swap(nums[1], nums[i]);
        heapAdjust(nums, 1, i-1);
    }

}

void mergeSort(std::vector<int> &nums, int left, int right)
{
    if(left < right)
    {
        int mid = left + ((right-left) >> 1);
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

}

void merge(std::vector<int> &nums, int left, int mid, int right)
{
    int lindex = left, rindex = mid + 1;
    int *team = new int[right - left + 1];
    int teamIndex = 0;

    while(lindex <= mid && rindex <= right)
    {
        if(nums[lindex] <= nums[rindex]) {
            team[teamIndex++] = nums[lindex++];
        }
        else {
            team[teamIndex++] = nums[rindex++];
        }
    }

    while(lindex <= mid) {
        team[teamIndex++] = nums[lindex++];
    }

    while(rindex <= right) {
        team[teamIndex++] = nums[rindex++];
    }

    for(int i = 0; i < right-left+1; i++) {
        nums[left + i] = team[i];
    }

    delete[] team;
}


void quickSort(std::vector<int> &nums, int left, int right)
{
    if(left < right)
    {
        int pivot = partition(nums, left, right);
        quickSort(nums, left, pivot - 1);
        quickSort(nums, pivot + 1, right);
    }

}

int partition(std::vector<int> &nums, int left, int right)
{
    int mid = left + ((right - left) >> 1);

    // if(nums[left] > nums[mid]) std::swap(nums[left], nums[mid]);
    // if(nums[mid] > nums[right]) std::swap(nums[mid], nums[right]);
    // if(nums[mid] < nums[left]) std::swap(nums[left], nums[mid]);

    // if(nums[left] > nums[right]) std::swap(nums[left], nums[right]);
    // if(nums[mid] > nums[right]) std::swap(nums[mid], nums[right]);
    // if(nums[mid] < nums[left]) std::swap(nums[left], nums[mid]);

    //三数取中
    if(nums[left] > nums[right]) std::swap(nums[left], nums[right]);    //保证right最大
    if(nums[mid] > nums[right]) std::swap(nums[mid], nums[right]);
    if(nums[left] < nums[mid]) std::swap(nums[left], nums[mid]);    //保证mid最小

    int pivotkey = nums[left];

    while(left < right)
    {
        while(left < right && nums[right] >= pivotkey) right--;
        // std::swap(nums[left], nums[right]);
        nums[left] = nums[right];

        while(left < right && nums[left] <= pivotkey) left++;
        // std::swap(nums[left], nums[right]); 
        nums[right] = nums[left];
    }

    nums[left] = pivotkey;

    // for(int i = left; i <= right; i++) {
    //     std::cout << nums[i] << " ";
    // }
    // std::cout << std::endl;

    return left;
}


void bucketSort(std::vector<int> &nums)
{
    int maxVal = INT_MIN, minVal = INT_MAX;

    for(const int &n : nums) {
        maxVal = std::max(maxVal, n);
        minVal = std::min(minVal, n);
    }   

    int bucketNum = (maxVal - minVal)/nums.size() + 1;

    std::vector<std::vector<int>> buckets(bucketNum);    

    //每个元素放入桶
    for(const int &n : nums) {
        int num = (n - minVal)/nums.size();
        buckets[num].push_back(n);
    }

    for(int i = 0; i < buckets.size(); i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for(int i = 0; i < buckets.size(); i++) {
        for(int j = 0; j < buckets[i].size(); j++) {
            nums[index++] = buckets[i][j];
        }
    }

}
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>

std::string addTwoNumber(std::string num1, std::string num2);
bool bigger(std::string num1, std::string num2);
std::string subTwoNumber(std::string num1, std::string num2);
int findMaxForm(std::vector<std::string> &strs, int m, int n);

int main() {
    std::vector<std::string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;

    findMaxForm(strs, m, n);

    return 0;
}

std::string addTwoNumber(std::string num1, std::string num2)
{
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int carry = 0;
    int i = 0, j = 0;
    std::string res;

    while(i != num1.size() || j != num2.size() || carry)
    {
        int val1 = (i != num1.size()) ? (num1[i++]-'0') : 0;
        int val2 = (j != num2.size()) ? (num2[j++]-'0') : 0;
        int sum = val1 + val2 + carry;
        carry = sum/10;
        res += std::to_string(sum%10);
    }

    reverse(res.begin(), res.end());

    return res;
}

//我们让 num1 - num2, 且num1的绝对值大于num2,这样方便处理借位
std::string subTwoNumber(std::string num1, std::string num2)
{
    if(num1 == num2) return "0";

    bool positive = bigger(num1, num2);

    if(!positive) {
        std::string tmp = num1;
        num1 = num2;
        num2 = tmp;
    }

    while(num1.size() > num2.size()) {
        num2 = '0' + num2;
    }

    for(int i = num1.size() - 1; i >= 0; i--) 
    {
        if(num1[i] < num2[i] && i > 0) {
            num1[i-1]--;            
            num1[i] += 10;
        }

        num1[i] -= (num2[i]-'0');
    }

    std::string res = num1;
    if(!positive) {
        res = "-" + res;
    }

    return res;
}

bool bigger(std::string num1, std::string num2)
{
    if(num1.size() != num2.size()) return num1.size() > num2.size();

    for(int i = 0; i < num1.size(); i++) {
        if(num1[i] > num2[i]) return true;
    }

    return false;
}

// std::string multiplyTwoNumber(std::string num1, std::string num2)
// {
//     int m = num1.size(), n = num2.size();
//     std::string res(m + n, '0');

//     for(int i = m-1; i >= 0; i--) {
//         for(int j = n-1; j >= 0; j--) {
//             int prod = (num1[i]-'0') * (num2[j]-'0') + (res[i+j+1]-'0');
//             res[i+j] += prod/10;
//             res[i+j+1] = std::to_string(prod%10);
//         }
//     }

//     for(int i = 0; i < res.size(); i++) {
//         if(res[i] != '0') {
//             return res.substr(i);
//         }
//     }

//     return "0";
// }


int findMaxForm(std::vector<std::string> &strs, int m, int n)
{
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for(const auto &str : strs)
    {
        int count0 = count(str.begin(), str.end(), '0');
        int count1 = str.size() - count0;

        for(int i = m; i >= count0; i--) {
            for(int j = n; j >= count1; j--) {
                dp[i][j] = std::max(dp[i][j], 1 + dp[i-count0][j-count1]);
            }
        }

        for(int i = 0; i < dp.size(); i++) {
            for(int j = 0; j < dp[i].size(); j++) {
                std::cout << dp[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return dp[m][n];
}


bool isMatch(std::string s, std::string p)
{
    int m = s.size(), n = p.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    dp[0][0] = 1;
    for(int j = 1; j <= n; j++) {
        if(p[j-1] == '*') {
            dp[0][j] = dp[0][j-1];
        }
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == p[j-1] || p[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] == '*') {
                dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
            }
        }
    }

    return dp[m][n];
}*/
/*

#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <unordered_map>

int rand7();
int rand5();
double mySqrt(int x);


int main() {
    std::unordered_multimap<int,int> hash;
    hash.insert({1,4});
    hash.insert({1,3});
    hash.insert({1,2});

    for(auto item : hash) {
        std::cout << item.first << " " << item.second << std::endl;
    }

    return 0;
}

//生成1~5之间的随机数
int rand5() 
{
    return rand()%5 + 1;
}

int rand7()
{
    //为什么乘以5,这样可以找到离7的倍数最近的21,如果乘以4范围为[1,20],这样得去除掉15-20
    int result = 5*(rand5()-1) + rand5();     //result的范围为[1,25],这里面的数出现的概率都是相同的,去除掉22-25
    while(result > 21) {
        result = 5*(rand5()-1) + rand5();
    }

    return result%7 + 1;
}


double mySqrt(int x)
{
    if(x < 0) return -1;

    double left = 0, right = x;

    while(left <= right)
    {
        double mid = left + (right-left)/2;
        if(fabs(mid*mid - x) < 0.0001) {
            return mid;
        }
        else if(mid*mid < x) {
            left = mid;
        }
        else if(mid*mid > x) {
            right = mid;
        }
    }

    return -1;
}

/*
int maxScore(std::vector<int> &nums, int k)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);

    int n = nums.size();
    int minSum = accumulate(nums.begin(), nums.begin() + n-k, 0);

    int resMinSum = minSum;
    for(int i = n-k; i < n; i++) {
        minSum += nums[i] - nums[i-(n-k)]
        if(resMinSum > minSum) {
            resMinSum = minSum;
        }
    }

    return sum - resMinSum;
}

std::vector<int> preorderTraversal(TreeNode *root)
{
    std::vector<int> res;
    if(root == nullptr) return res;

    std::stack<TreeNode*> sta;
    sta.push(root);

    while(!sta.empty())
    {
        TreeNode *pNode = sta.top(); sta.pop();
        res.push_back(pNode->val);

        if(pNode->right) {
            sta.push(pNode->right);
        }

        if(pNode->left) {
            sta.push(pNode->left);
        }
    }

    return res;
}

std::vector<int> inorderTraversal(TreeNode *root)
{
    std::vector<int> res;
    if(root == nullptr) return res;

    std::stack<TreeNode*> sta;
    TreeNode *pNode = root;

    while(pNode || !sta.empty())
    {
        while(pNodet) {
            sta.push(pNode);
            pNode = pNode->left;
        }

        pNode = sta.top();  sta.pop();
        res.push(pNode->val);

        pNode = pNode->right;
    }

    return res;
}

std::vector<int> postorderTraversal(TreeNode *root)
{
    std::vector<int> res;
    if(root == nullptr) return res;

    std::stack<TreeNode*> sta;
    sta.push(root);

    while(!sta.empty())
    {
        TreeNode *pNode = sta.top();  sta.pop();
        res.push_back(pNode->val);

        if(pNode->left) {
            sta.push(pNode->left);
        }
        if(pNode->right) {
            sta.push(pNode->right);
        }
    }

    reverse(res.begin(), res.end());

    return res;
}
*/

/*
int maxArea(std::vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
    int maxArea = 0;

    while(left < right)
    {        
        int wide = right - left;
        int hei = nums[left] < nums[right] : nums[left++] ? nums[right--];
        maxArea = std::max(maxArea, hei*wide);
    }

    return maxArea;
}

int trap(std::vector<int> &height)
{
    std::stack<int> sta;
    int res = 0;

    for(int i = 0; i < height.size(); i++)
    {
        while(!sta.empty() && height[i] > height[sta.top()]) {
            int midIndex = sta.top();   sta.pop();
            if(!sta.empty()) {
                int wide = i - sat.top() - 1;
                int hei = std::min(height[i], height[sta.top()]) - height[midIndex];
                res += wide*hei;
            }
        }

        sta.push(i);
    }

    return res;
}


int calculateMinimumHP(std::vector<std::vector<int>> &dungeon)
{
    int m = dungeon.size(), n = dungeon[0].size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<std::vector<int>>(n + 1, INT_MAX));
    dp[m-1][n] = 1; 
    dp[m][n-1] = 1;

    for(int i = m-1; i >= 0; i--) {
        for(int j = n-1; j >= n; j--) {
            dp[i][j] = std::min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
        }
    }

    return dp[0][0];
}
*/
/*
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <map>
#include <memory>
#include <set>

struct Node 
{
    int data;
    // std::shared_ptr<Node> next;
    std::weak_ptr<Node> next;

    Node(int n) : data(n) {}

    ~Node() {
        std::cout << "~Destructor!" << std::endl;
    }

};

bool isNumber(std::string s);
bool scanInteger(std::string s, int &i);
bool scanUnsignedInteger(std::string s, int &i);

int main() {
    // std::set<int> mySet;
    // std::cout << mySet.capacity() << std::endl;
    // std::cout << mySet.size() << std::endl;
    // std::shared_ptr<Node> p1 = std::make_shared<Node>(1);
    // std::shared_ptr<Node> p2 = std::make_shared<Node>(2);
    
    // p1->next = p2;
    // p2->next = p1;

    // std::map<int,int> hash;
    // hash.insert({1,1});
    // hash.insert({2,2});
    // hash.insert({3,3});
    // hash.insert({4,4});
    // hash.insert({5,5});

    // // for(auto it = hash.begin(); it != hash.end();)
    // // {
    // //     if((it->second&1)) {
    // //         hash.erase(it++);
    // //     }
    // //     else {
    // //         it++;
    // //     }
    // // }

    // for(std::map<int,int>::iterator it = hash.begin(); it != hash.end();)
    // {
    //     if(it->second&1) {
    //         it = hash.erase(it);
    //     }
    //     else it++;
    // }


    // for(auto item : hash) {
    //     std::cout << item.first << " " << item.second << std::endl;
    // }

    // std::vector<int> nums;
    // nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(3);
    // nums.push_back(4);
    // nums.push_back(4);

    // std::cout << nums.capacity() << std::endl;

    std::cout << isNumber(".") << std::endl;

    return 0;
}

//匹配模式为 A[.[B]][e|EC]
//由于小数点前可能为空,如果为空,则小数点后一定要有数子 .B[e|Ec]
//[]代表可选项,可以没有,其中A和C都代表可能以'+'或者'-'开头的数字,而B不可能以符号开头

bool isNumber(std::string s)
{   
    if(s.empty()) return false;

    int i = 0;
    bool numeric = scanInteger(s, i);   //扫描A部分

    //扫描B部分
    if(s[i] == '.') {
        i++;
        numeric = scanUnsignedInteger(s, i) || numeric; //注意这里是或,小数点前面或者后面可能没有数字
    }

    //扫描C部分
    if(s[i] == 'E' || s[i] == 'e') {    
        i++;
        numeric = numeric && scanInteger(s, i);     //注意:这里是用与,因为e前面必须要求有数字
    }

    return numeric && (i == s.size());      //判断是否到达了字符串末尾
}

bool scanInteger(std::string s, int &i)
{
    if(i >= s.size()) return false;

    if(s[i] == '+' || s[i] == '-') i++;

    return scanUnsignedInteger(s, i);
}

bool scanUnsignedInteger(std::string s, int &i)
{
    if(i >= s.size()) return false;

    int before = i;

    while(i < s.size())
    {
        if(s[i] >= '0' && s[i] <= '9') i++;
        else break;
    }

    //s中存在无符号数时才返回
    return i > before;
}
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

std::vector<int> shortestToChar(std::string s, char c);
int findMaxLength(std::string s);
void getMaxNum(int N, int &A);
int dfs(int N, int &A);
int solve(int n);

int main() {
    // std::string s = "my_test_str";
    // char c = 't';

    // std::vector<int> res = shortestToChar(s, c);

    // for(const int &n : res) {
    //     std::cout << n << " ";
    // }
    // std::cout << std::endl;

    // std::string s = "01001001";

    // std::cout << findMaxLength(s) << std::endl;

    // int A = 0, N = 200;

    // getMaxNum(N, A);

    // std::cout << A << std::endl;

    // std::cout << solve(200) << std::endl;

    // int num = solve(200);
    int mul = 81;
    int num = 200;

    while(num)
    {

    }


    return 0;
}

std::vector<int> shortestToChar(std::string s, char c)
{
    if(s.find(c) == std::string::npos) return {};

    std::vector<int> index;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == c) {
            index.push_back(i);
        }
    }

    std::vector<int> res;

    for(int i = 0; i < s.size(); i++)
    {
        auto it = lower_bound(index.begin(), index.end(), i);

        if(it == index.begin()) {
            res.push_back(*it - i);
        }
        else if(it == index.end()) {
            res.push_back(i - *(--it));
        }
        else {
            int later = *it;
            int prev = *(--it);
            res.push_back(std::min(later - i, i - prev));
        }
    }

    return res;
}

int findMaxLength(std::string s)
{
    std::vector<int> dp(s.size(), 0);
    std::unordered_map<int,std::vector<int>> hash;

    int res = 0;

    std::vector<int> count(2, 0);
    for(int i = 0; i < s.size(); i++) {
        count[s[i]-'0']++;
        dp[i] = count[1] - count[0];
        if(dp[i] == 0) res = i + 1;
        hash[dp[i]].push_back(i);
    }

    for(auto it : hash) {
        res = std::max(res, it.second.back() - it.second.front());
    }

    return res;
}

/*
void getMaxNum(int N, int &A)
{
    dfs(N, A);
}

int dfs(int N, int &A)
{
    if(N == 0) {
        A = 1;
        return 1;
    }
    if(N < 10) {
        A = N;
        return N;
    }

    int res1 = 9*dfs((N/10)-1, A);
    int res2 = (N%10)*dfs(N/10, A);

    if(res1 >= res2) {
        A = A*10 + 9;
    }
    else {
        A = A*10 + (N%10);
    }

    std::cout << A << std::endl;

    return std::max(res1, res2);
}
*/
/*
int solve(int n)
{
    if(n == 0) return 1;
    else if(n < 10) return n;
    else return std::max(solve(n/10)*(n%10), solve(n/10-1)*9);
}

std::vector<std::string> res;

std::vector<std::string> restoreIpAddresses(std::string s)
{
    std::string path;

    dfs(s, 0, 0, path);

    return res;
}

void dfs(std::string s, int count, int pos, std::string path)
{
    if(count > 4) return;
    if(pos == s.size() && count == 4) {
        path.pop_back();
        res.push_back(path);
        return;
    }

    for(int i = 1; i <= 3 && pos + i <= s.size(); i++)
    {
        std::string tmp = s.substr(pos, i);
        if(tmp[0] == '0' && i > 1) return;
        else if(std::stoi(tmp) <= 255) {
            dfs(s, count + 1, pos + i, path + tmp + ".", res);
        }
    }

}


int longestStrChain(std::vector<std::string> &words)
{
    sort(words.begin(), words.end(), [](std::string str1, std::string str2){
        return str1.size() < str2.size();
    });

    std::unordered_map<std::string, int> hash;

    int res = 0;

    for(const auto &word : words) {
        for(int i = 0; i < word.size(); i++) {
            std::string pre = word.substr(0,i) + word.substr(i + 1);
            hash[word] = std::max(hash[word], hash.count(pre) ? hash[pre] + 1 : 1);
        }
        res = std::max(res, hash[word]);
    }

    return res;
}
*/





/*
int data[2000];
int tail;
int head;
int pop(int *d);
int push(int d);

void initQueue() {
    head = tail = 0;
}

bool ifFull() {
    if((tail+1)%head == 2000) {
        return true;
    }
    return false;
}

bool isEmpty() {
    if(head == tail) {
        return true;
    }
    return false;
}

int pop(int *d)
{
    if(isEmpty()) return -1;
    *d = data[head];
    head = (head+1)%2000;
}

int push(int d)
{
    if(isFull()) return -1;
    data[tail] = d;
    tail = (tail+1)%2000;
}
*/
/*

class MyCircularQueue 
{
    int *data;
    int front, tail;
    int size;

public:
    MyCircularQueue(int k) : data(new int[k+1]) {
        memset(data, 0, sizeof(data));
        front = tail = 0;
        size = k+1;
    }

    bool enQueue(int value) {
        if(isFull()) return false;
        data[tail] = value;
        tail = (tail + 1)%size;
        return true;
    }

    bool deQueue() {
        if(isEmpty()) return false;
        front = (front + 1)%size;
        return true;
    }

    int Front() {
        if(isEmpty()) return -1;
        return data[front];
    }

    int Rear() {
        if(isEmpty()) return -1;
        return data[(size+tail-1)%size];
    }

    bool isEmpty() {
        if(front == tail) return true;
        return false;
    }

    bool isFull() {
        if((tail+1)%size == front) return true;
        return false;
    }

};

int randNum();
int getNumber() ;

void reverseStr(std::string &str);
void reverse(char *pBegin, char *pEnd);
void reverseStr(char *pStr);
std::string KeepKChar(std::string str, int k)
{
    if(k <= 0 || str.size() < k) return str;

    k = str.size() - k;

    std::string res;

    for(int i = 0; i < str.size(); i++)
    {
        while(!res.empty() && str[i] < res.back() && k)
        {
            res.pop_back();
            k--;
        }

        res.push_back(str[i]);
    }

    return res;
}

#define DEBUG 1

#ifdef DEBUG
    #define WHILE(x) write(__FILE__,__LINE__); while(x)
#else
    #define WHILE(x) while(x)
#endif

int main() {

    // std::string str = "bcade";
    // int k = 3;

    // std::cout << KeepKChar(str, k) << std::endl;

    // char str[] = "hello world I am a student";
    // char str[] = "hello ";
    // std::vector<int> nums = {1,2,3};
    // // nums.reserve(100);
    // std::vector<int>(nums).swap(nums);

    // std::cout << sizeof(nums) << std::endl;

    // std::string str = "hello";

    // std::string str = "123456";

    // for(int i = 0; i <= str.size()+2; i++) {
    //     std::cout << str[i] - '0' << std::endl;
    // }

    // std::cout << str[8] << std::endl;

    // reverseStr(str);

    // std::cout << str << std::endl;
    // printf("%s\n", str);

    // int num = 0;

    // int n = !num;

    // std::cout << n << std::endl;

    // while(1)
    // #ifdef DEBUG
    //     #define WHILE(x) writes(__FILE__,__LINE__); while(x)
    // #else
    //     #define WHILE(x) while(x)
    // #endif
    WHILE(1)
    {
        std::cout << "is" << std::endl;
    }

    return 0;
}

//等概率生成一个[1~600]之间的数
int randNum() 
{
    int num; 
    while(1)
    {   num = rand()%65536;
        if(num > 59999) continue;
        else break;
    }

    return num%600 + 1;
}

//等概率生成一个[1~30W]之间的数
int getNumber() 
{
    int num;
    while(1)
    {
        num = 600*(randNum()-1) + randNum();
        if(num > 300000) continue;
        else break;
    }

    return num;
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int s1 = (C-A)*(D-B), s2 = (G-E)*(H-F);

    if(C <= E || A >= G || B >= F || D <= H) return s1 + s2;

    int s = (std::min(C,G) - std::max(A,E)) * (std::min(D, H) - std::max(B, F));

    return s1 + s2 - s;
}

void nextPermutation(std::vector<int> &nums)
{
    int i = nums.size() - 2;
    for(; i >= 0; i--) {
        if(nums[i] < nums[i+1]) break;
    }

    if(i == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    int j = nums.size() -1;
    for(; j > i; j--) {
        if(nums[j] > nums[i]) break;
    }

    std::swap(nums[i], nums[j]);

    reverse(nums.begin() + i + 1, nums.end());
}


void reverseStr(std::string &str)
{
    if(str.empty()) return;

    int i = 0, j = 0;
    while(i <= str.size())
    {
        if((i < str.size() && str[i] == ' ') || i == str.size()) {
            reverse(str.begin() + j, str.begin() + i);
            j = i + 1;
        }
        i++;
    }

    reverse(str.begin(), str.end());
}



void reverseStr(char *pStr)
{
    char *pBegin = pStr, *pEnd = pStr;

    //先翻转单个单词
    while(*pBegin != '\0')
    {
        if(*pEnd == ' ' || *pEnd == '\0') {
            reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        }
        
        if(*pBegin == ' ') {
            pBegin++;
            pEnd++;
        }
        else if(*pEnd != '\0')
            pEnd++;
    }

    pBegin = pStr, pEnd = pStr;

    while(*pEnd != '\0') {
        pEnd++;
    }

    reverse(pBegin, --pEnd);
}

void reverse(char *pBegin, char *pEnd)
{
    if(pBegin == nullptr || pEnd == nullptr) return;

    while(pBegin < pEnd)
    {
        char ch = *pBegin;
        *pBegin = *pEnd;
        *pEnd = ch;
        pBegin++;
        pEnd--;
    }
}

std::vector<std::string> findAndReplacePattern(std::vector<std::string> &words, std::string pattern)
{
    std::vector<std::string> res;

    std::string P = F(pattern);

    for(auto &word : word)
    {
        if(F(word) == P) {
            res.push_back(word);
        }
    }

    return res;
}

std::string F(std::string word)
{
    std::unordered_map<char,int> hash;

    //序列化,记录该字符前面有多少个不同字符就行
    for(const char &c : word) {
        if(!hash.count(c)) hash[c] = hash.size();
    }

    for(int i = 0; i < word.size(); i++) {
        word[i] = 'a' + hash[word[i]];
    }

    return word;
}
*/


/*
int numsSubarrayWithSum(std::vector<int> &A, int S)
{
    int sum = 0, count = 0;
    std::unordered_map<int,int> hash;
    hash[0] = 1;

    for(int i = 0; i < A.size(); i++)
    {
        sum += A[i];
        count += hash[sum-S];
        hash[sum]++;
    }

    return count;
}
*/
/*
void dfs(std::vector<std::string> &matrix, std::vector<int> &row, std::vector<int> &col, std::vector<int> &rightDiag, std::vector<int> &leftDiag, int i);

// std::vector<std::string> res;
std::vector<std::vector<std::string>> res;

std::vector<std::vector<std::string>> solveNQeens(int n)
{
    std::vector<int> row(n, 0), col(n, 0), rightDiag(2*n-1, 0), leftDiag(2*n-1, 0);

    std::vector<std::string> matrix(n, std::string(n, '.'));

    dfs(matrix, row, col, rightDiag, leftDiag, 0);

    return res;
}

void dfs(std::vector<std::string> &matrix, std::vector<int> &row, std::vector<int> &col, std::vector<int> &rightDiag, std::vector<int> &leftDiag, int i)
{
    int n = matrix.size();

    if(i == n) {
        res.push_back(matrix);
        return;
    }

    for(int j = 0; j < n; j++)
    {
        if(!row[j] && !col[j] && !leftDiag[i+j] && !rightDiag[i+n-1-j])
        {
            matrix[i][j] = 'Q';
            row[j] = col[j] = leftDiag[i+j] = rightDiag[i+n-1-j] = 1;

            dfs(matrix, row, col, rightDiag, leftDiag, i + 1);

            matrix[i][j] = '.';
            row[j] = col[j] = leftDiag[i+j] = rightDiag[i+n-1-j] = 0;            
        } 

    }

}

int main() {
    // std::shared_ptr<int> sp1 = std::make_shared<int>(2);
    // std::shared_ptr<int> sp2 = sp1;

    // sp1.reset();

    // // std::cout << *sp1 << std::endl;

    // std::cout << sp1.use_count() << std::endl;

    // std::vector<int> nums;
    // nums.push_back(1);

    solveNQeens(4);

    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


std::vector<std::vector<int>> row(9, std::vector<int>(9, 0)), col(9, std::vector<int>(9,0)), block(9, std::vector<int>(9, 0));

bool find = false;

void solveSudoku(std::vector<std::vector<char>> &board)
{
    //先把数逐个填入row,col,block,方便确定下面填充哪些数

    int m = board.size(), n = board[0].size();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] != '.') {
                int k = (i/3)*3 + j/3;
                int n = board[i][j] - '1';
                row[i][n] = col[j][n] = block[k][n] = 1
            }
        }
    }

    dfs(board, 0, 0);


}

void dfs(std::vector<std::vector<char>> &board, int i, int j)
{
    if(find) {
        return;
    }

    if(i == 9) {
        find = true;
        return;
    }

    if(j == 9) {
        dfs(board, i + 1, 0);
        return;
    }

    if(board[i][j] != '.') {
        dfs(board, i, j+1);
    }
    else
    {
        int m = board.size(), n = board[0].size();

        for(int n = 0; n < 9; n++)
        {
            int k = (i/3)*3 + j/3;
            if(!row[i][n] && !col[j][n] && !block[k][n])
            {
                row[i][n] = col[j][n] = block[k][n] = 1;
                board[i][j] = n + '1';

                dfs(board, i, j+1);
                if(find) return;

                row[i][n] = col[j][n] = block[k][n] = 0;
                board[i][j] = '.';
            }
        }

    }

}

*/

/*
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
    MyVector() : data(nullptr), capacity(0), size(0) {

    }

    ~MyVector() {
        delete[] data;
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
        if(size != 0) {
            size--;
        }
    }

    int getsize() {
        return size;
    }

    int &operator[] (int i) {
        return data[i];
    }

};

int main() {

    MyVector vector(3, 0);
    vector.pop_back();
    vector.pop_back();
    vector.pop_back();

    std::cout << vector.getsize() << std::endl;

    // MyVector num;
    // std::vector<int> nums(100, 0);
    // nums.pop_back();
    // std::vector<int> nums(5, 1);
    // nums.resize(3,0);

    // for(int i = 0; i < nums.size(); i++) {
    //     std::cout << nums[i] << " ";
    // }
    // std::cout << std::endl;

    // std::cout << nums.size() << " " << nums.capacity() << std::endl;

    return 0;
}


int coinChange(std::vector<int> &coins, int amount)
{
    int n = coins.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(amount + 1, amount + 1));
    for(int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= amount; j++) {
            if(j >= coins[i-1]) {
                dp[i][j] = std::min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
            }
            else {
                dp[i][j] =  dp[i-1][j];
            }
        }
    }

    return dp[n][amount] == amount + 1 ? -1 : dp[n][amount];
}


bool Isomorphic(TreeNode *root1, TreeNode *root2)
{
    if(root1 == nullptr || root2 == nullptr) return root1 == root2;

    if(root1->val != root2->val) return false;

    if(root1->left == nullptr && root2->left == nullptr) {
        return Isomorphic(root1->right, root2->right);
    }
    else if(root1->right == nullptr && root2->right == nullptr) {
        return Isomorphic(root1->left, root2->left);
    }
    else if(root1->left && root2->left && root1->left->val == root2->left->val) {
        return Isomorphic(root1->left, root2->left) && Isomorphic(root1->right, root2->right);
    }
    else {
        return Isomorphic(root1->right, root2->left) && Isomorphic(root1->left, root2->right);
    }

}

bool findNode(TreeNode *root, TreeNode *pFind)
{
    if(root == nullptr) return false;

    if(root == pFind) return true;

    if(root->val < pFind->val) {
        return findNode(root->right, pFind);
    }
    else {
        return findNode(root->left, pFind);
    }

}


int evalRPN(std::vector<std::string> &tokens)
{
    std::stack<int> sta;

    for(int i = 0; i < tokens.size(); i++)
    {
        std::string str = tokens[i];

        if(str == '+') {
            int second = sta.top(); sta.pop();
            int first = sta.top();  sta.pop();
            sta.push(first+second);
        }
        else if(str == "-") {
            int second = sta.top(); sta.pop();
            int first = sta.top();  sta.pop();
            sta.push(first-second);
        }
        else if(str == "*") {
            int second = sta.top(); sta.pop();
            int first = sta.top();  sta.pop();
            sta.push(first*second);
        }
        else if(str == "/") {
            int second = sta.top(); sta.pop();
            int first = sta.top();  sta.pop();
            sta.push(first/second);
        }
        else {
            sta.push(stoi(str));
        }
    }

    return sta.top();
}


int evalRPN(std::vector<std::string> &tokens)
{
    std::stack<int> sta;

    for(int i = 0; i < tokens.size(); i++)
    {
        if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
        {
            int second = sta.top(); sta.pop();
            int first = sta.top(); sta.pop();
            sta.push(applyOp(first, second, tokens[i]));
        }
        else {
            sta.push(stoi(tokens[i]));
        }
    }

    return sta.top();
}

int applyOp(int first, int second, std::string op)
{
    int res;
    switch(op[0]) {
        case '+' : res = first + second; break;
        case '-' : res = first - second; break;
        case '*' : res = first * second; break;
        case '/' : res = first / second; break;
    }

    return res;
}

int calculate(std::string s)
{
    int result = 0;
    int number = 0;
    int sign = 1;

    std::stack<int> sta;

    for(int i = 0; i < s.size(); i++)
    {
        if(isdigit(s[i])) {
            number = number*10 + (s[i] - '0');
        }
        else if(s[i] == '+') {
            result += sign*number;
            number = 0;
            sign = 1;
        }
        else if(s[i] == '-') {
            result += sign*number;
            number = 0;
            sign = -1;
        }
        else if(s[i] == '(') {
            sta.push(result);
            sta.push(sign);
            result = 0
            sign = 1;
        }
        else if(s[i] == ')') {
            result += sign*number;
            number = 0;
            result *= sta.top();
            result += sta.top();
        }
    }

    if(number != 0) return result += sign*number;

    return result;
}
*/



/*
int maxProduct(std::vector<std::string> &words)
{
    int n = words.size();
    int res = 0;

    for(int i = 0; i < n ;i++) 
    {
        int count = 0;
        int size = words[i].size();
        for(const char &c : words[i]) {
            count |= (1 << (c-'a'));
        }

        for(int j = i+1; j < n; j++) {
            int tmp = 0;
            for(const char &c : words[j]) {
                tmp |= (1 << (c-'a'));
            }
            
            if((count & tmp) == 0) {
                res = std::max(res, (int)(size*words[j].size()));
            }
        }
    }

    return res;
}

int maximumUniqueSubarray(std::vector<int> &nums)
{
    std::unordered_map<int,int> hash;

    int sum = 0, res = 0;

    int j = 0, i = 0;
    while(j < nums.size())
    {
        while(hash.count(nums[j])) {
            sum -= nums[i];
            if(--hash[nums[i]] == 0) {
                hash.erase(nums[i]);
            }
            i++;
        }

        sum += nums[j];
        res = std::max(res, sum);
        hash[nums[j++]]++;
    }

    return res;
}


int maximumUniqueSubarray(std::vector<int> &nums)
{
    std::unordered_set<int> mySet;

    int sum = 0, res = 0;

    int i = 0, j = 0;
    while(j < nums.size())
    {
        while(mySet.count(nums[j])) {
            sum -= nums[i];
            mySet.erase(nums[i++]);
        }

        sum += nums[j];
        res = std::max(res, sum);
        mySet.insert(nums[j++]);
    }

    return res;
}

int Get_0_1() {

    while(1)
    {
        int first = rand(), second = rand();

        if(first == 0 && second == 1) {
            return 1;
        }
        else if(first == 1 && second == 0) {
            return 0;
        }
    }

    return -1;
}

std::vector<int> findDuplicate(std::vector<int> &nums)
{
    std::vector<int> res;

    for(int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;
        if(nums[index] < 0) {
            res.push_back(abs(nums[i]));
        }
        else {
            nums[index] *= (-1);
        }        
    }

    return res;
}


int maximumGap(std::vector<int> &nums)
{
    if(nums.size() < 2) return 0;

    sort(nums.begin(), nums.end());

    int diff = INT_MIN;
    for(int i = 1; i < nums.size(); i++) {
        diff = std::max(diff, nums[i] - nums[i-1]);
    }

    return diff;
}
*/



/*

int maximumGap(std::vector<int> &nums)
{
    if(nums.size() < 2) return 0;

    int minVal = INT_MAX, maxVal = INT_MIN;
    for(const int &n : nums) {
        minVal = std::min(minVal, n);
        maxVal = std::max(maxVal, n);
    }

    int n = nums.size();
    int bucketNum = (maxVal - minVal)/n + 1;

    if(maxVal == minVal) return 0;  //表明所有元素都相等

    //记录桶中是否存在元素以及桶中每个元素的最大和最小值
    std::vector<int> hasNum(bucketNum, 0);
    std::vector<int> mins(bucketNum), maxs(bucketNum);    

    for(int i = 0; i < n; i++)
    {
        //计算桶编号
        int num = (nums[i] - minVal)/n;
        mins[num] = hasNum[num] ? std::min(mins[num], nums[i]) : nums[i];
        maxs[num] = hasNum[num] ? std::max(maxs[num], nums[i]) : nums[i];
        hasNum[num] = 1;
    }

    //计算前一个桶的最大值和后一个桶的最小值之差就是最大的diff.不用管桶内数据,因为桶内的数据差肯定要比桶外的数据差小
    int diff = maxs[0] - mins[0];   //防止只有一个桶
    int preMax = maxs[0];
    for(int i = 1; i < bucketNum; i++) {
        if(hasNum[i]) {
            diff = std::max(diff, mins[i] - preMax);
            preMax = maxs[i];
        }
    }

    return diff;
}

int climbStairs(int n)
{
    if(n == 1) return 1;

    std::vector<int> dp(n+1);

    dp[1] = 1, dp[2] = 2;
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int climbStairs(int n)
{
    if(n == 1) return 1;

    int first = 1, second = 2;

    int cur = second;

    for(int i = 3; i <= n; i++) {
        cur = first + second;
        first = second;
        second = cur;
    }

    return cur;
}


int rob(std::vector<int> &nums)
{
    if(nums.size() == 1) return nums[0];

    std::vector<int> dp(nums.size(), 0);

    dp[0] = nums[0], dp[1] = std::max(nums[0], nums[1]);

    for(int i = 2; i < nums.size(); i++) {
        dp[i] = std::max(dp[i-2] + nums[i], dp[i-1]);
    }
    
    return dp[nums.size()-1];
}

int rob(std::vector<int> &nums, int left, int right)
{
    int first = nums[left], second = std::max(nums[left], nums[left+1]);
    int cur = second;

    for(int i = left + 2; i <= right; i++) {
        cur = std::max(first + nums[i], second);
        first = second;
        second = cur;
    }

    return cur;
}

int rob(std::vector<int> &nums)
{
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return std::max(nums[0], nums[1]);

    return std::max(rob(nums, 0, nums.size()-2), rob(nums, 1, nums.size()-1));
}

std::unordered_map<TreeNode*,int> hash;

int rob(TreeNode *root)
{
    if(root == nullptr) return 0;

    int money1 = root->val;

    if(root->left) {
        money1 += rob(root->left->left) + rob(root->left->right);
    }    
    if(rob->right) {
        money1 += rob(root->right->left) + rob(root->right->right);
    }

    int money2 = rob(root->left) + rob(root->right);

    hash[root] = std::max(money1, money2);

    return std::max(money1, money2);
}

int numberOfArithmeticsSlices(std::vector<int> &nums)
{
    if(nums.size() < 3) return 0;

    std::vector<int> dp(nums.size(), 0);

    for(int i = 2 ; i < nums.size(); i++) {
        if((nums[i] - nums[i-1]) == (nums[i-1] - nums[i-2])) {
            dp[i] = dp[i-1] + 1;
        }
    }

    return accumulate(dp.begin(), dp.end(), 0);
}


ListNode* removeNthFromEnd(ListNode *head, int n)
{
    if(head == nullptr) return head;

    ListNode *base = new ListNode(-1);
    base->next = head;

    ListNode *fast = base, *slow = fast;

    for(int i = 0; i < n; i++) {
        fast = fast->next;
        if(fast == nullptr) break;
    }

    if(fast == nullptr) return head;

    while(fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return base->next;
}

int myAtoi(std::string s)
{
    int res = 0;

    int i = 0;
    while(s[i] == ' ') i++;

    bool minus = false;
    if(s[i] == '+') {
        i++;
    }
    else if(s[i] == '-') {
        minus = true;
        i++;
    }

    int flag = minus ? -1 : 1;
    for(; i < s.size(); i++)
    {
        if(!isdigit(s[i])) break;

        if(res > INT_MAX/10 || (res == INT_MAX/10 && (s[i]-'0') > 7)) {
            res = INT_MAX;
            break;
        }
        else if(res < INT_MIN/10 || (res == INT_MIN/10 && (s[i]-'0') > 8)) {
            res = INT_MIN;
            break;
        }

        res = res*10 + flag*(s[i]-'0');
    }

    return res;
}

*/
/*
void quickSort(std::vector<int> &nums, int left, int right);
int partition(std::vector<int> &nums, int left, int right);

int main() {
    std::vector<int> nums = {5,4,2,6,1};

    quickSort(nums, 0, nums.size() - 1);

    for(const int &n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}

void quickSort(std::vector<int> &nums, int left, int right)
{
    if(left < right) 
    {
        int mid = partition(nums, left, right);
        quickSort(nums, left, mid);
        quickSort(nums, mid + 1, right);
    }

}

int partition(std::vector<int> &nums, int left, int right)
{
    int pivot = nums[left];

    while(left < right)
    {
        while(left < right && nums[right] >= pivot) right--;
        std::swap(nums[left], nums[right]);

        while(left < right && nums[left] <= pivot) left++;
        std::swap(nums[left], nums[right]);
    }

    return left;
}

int findKthLargest(std::vector<int> &nums, int k)
{
    if(nums.size() < k || k <= 0) return -1;

    int left = 0, right = nums.size() - 1;
    
    k = nums.size() - k;

    while(left <= right)
    {
        int index = partition(nums, left, right);

        if(index == k) return nums[k];
        else if(index < k) {
            left = index + 1;
        }
        else if(index > k) {
            right = index - 1;
        }
    }

    return -1;
}



int findKthLargest(std::vector<int> &nums, int k)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for(const int &n : nums) {
        pq.push(n);
        if(pq.size() > k) pq.pop();
    } 

    return pq.top();

}

*/

/*
class Foo
{
public:
    Foo() = default;
    explicit Foo(int a) {
        std::cout << "Explicit Foo(int a)" << std::endl;
    }

};


void bubbleSort(std::vector<int> &nums)
{
    int n = nums.size();

    for(int i = 0; i < n; i++) {
        for(int j = n-2; j >= i; j--) {
            if(nums[j] > nums[j+1]) {
                std::swap(nums[j], nums[j+1]);
            }
        }
    }

}

int max(int a, int b)
{
    return a > b ? a : b;
}

void printMax(int(*p)(int, int)  ,int a, int b)
{
    std::cout << (*p)(a,b) << std::endl;
}

void bubbleSort(std::vector<int> &nums);



class Singleton
{
private:
    Singleton() {}
    Singleton(const Singleton &);
    Singleton& operator=(const Singleton &);

public:
    static Singleton& getInstance() {
        static Singleton demo;
        return demo;
    }

    void print() {
        std::cout << "Do something~" << std::endl;
    }

};

std::string::size_type find_char(const std::string &s, char c, std::string::size_type &occurs, ...);

int main() {
    std::string s = "hello world";

    // unsigned long num;
    std::string::size_type num;

    std::cout << find_char(s, 'l', num) << std::endl;

    std::cout << num << std::endl;

    return 0;
}


std::string::size_type find_char(const std::string &s, char c, std::string::size_type &occurs, ...)
{
    auto res = s.size();
    occurs = 0;

    for(decltype(res) i = 0; i != s.size(); i++)
    {
        if(s[i] == c) {
            if(res == s.size()) res = i;
            ++occurs;
        }
    }

    return res;
}

void sortAges(std::vector<int> &ages)
{
    int n = ages.size();

    std::vector<int> timesOfAge(100, 0);

    for(int i = 0; i < n; i++) {
        timesOfAge[ages[i]]++;
    }

    int index = 0;
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < timesOfAge[i]; j++) {
            ages[index++] = i;
        }
    }

}


const int N = (int)pow(10,9) + 7;

int maxArea(int h, int w, std::vector<int> &horizontalCuts, std::vector<int> &vecticalCuts)
{
    std::vector<long> heights, widths;
    heights.reverse(horizontalCuts.size() + 1);
    widths.reverse(vecticalCuts.size() + 1);

    for(int i = 0; i < horizontalCuts.size(); i++) {
        if(i == 0) heights.push_back(horizontalCuts[i]);
        else heights.push_back(horizontalCuts[i] - horizontalCuts[i-1]);
    }
    heights.push_back(h - horizontalCuts.back());

    for(int i = 0; i < vecticalCuts.size(); i++) {
        if(i == 0) widths.push_back(vecticalCuts[i]);
        else widths.push_back(vecticalCuts[i] - vecticalCuts[i-1]);
    }
    widths.push_back(w - vecticalCuts.back());

    long maxHeight = LONG_MIN;
    for(int i = 0; i < heights.size(); i++) {
        maxHeight = std::max(maxHeight, heights[i]);
    }

    long maxWidth = LONG_MIN;
    for(int i = 0; i < widths.size(); i++) {
        maxWidth = std::max(maxWidth, widths[i]);
    }

    return maxWidth*maxHeight%N;
}


const std::string &shortestString(const std::string &s1, const std::string &s2)
{
    return s1.size() > s2.size() ? s2 : s1;
}

std::string &shortestString(std::string &s1, std::string &s2)
{
    auto &r = shortestString(const_cast<const std::string &>(s1), const_cast<const std::string&>(s2));

    return const_cast<std::string&>(r);
}

void reverseString(std::vector<char> &s)
{
    int n = s.size();
    for(int i = 0; i < n/2; i++) {
        std::swap(s[i], s[n-1-i]);
    }

}



int GetSteps(int n, int k)
{
    if(n == 0) return -1;

    std::vector<std::vector<int>> dp(k+1, std::vector<int>(n, 0));
    dp[0][0] = 1;   //0步到达0点只有一种方法

    for(int i = 1; i <= k; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = dp[i-1][(j-1+n)%n] + dp[i-1][(j+1)%n];
        }
    }

    return dp[k][0];
}
int slidingPuzzle(std::vector<std::vector<int>> &board);
std::string swapChar(std::string cur, int i, int j);
int GetSteps(int n, int k);

int main() {
    int n = 2, k = 2;

    // std::cout << GetSteps(n, k) << std::endl;

    return 0;
}

//Leetcode第773题 : 2X3滑动谜题

//思路:BFS
//相当于寻找字符串到指定字符串的交换次数,广度优先搜索记录搜索的层数就行

int slidingPuzzle(std::vector<std::vector<int>> &board)
{
    std::string target = "123450";
    std::string start = "";

    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            start += std::to_string(board[i][j]);
        }
    }

    std::unordered_set<std::string> mySet;      //记录已经被遍历过的字符串组合

    std::vector<std::vector<int>> direction = {{1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}};

    std::queue<std::string> que;
    
    que.push(start);
    mySet.insert(start);
    
    int res = 0;

    while(!que.empty())
    {
        int size = que.size();
        for(int i = 0; i < size; i++) 
        {
            std::string cur = que.front();  que.pop();

            if(cur == target) return res;

            int zero = cur.find('0');

            for(int dir : direction[zero]) {
                std::string next = swapChar(cur, zero, dir);
                if(mySet.count(next)) continue;
                
                mySet.insert(next);
                que.push(next);
            }
        }

        res++;
    }

    return -1;
}


std::string swapChar(std::string cur, int i, int j)
{
    std::swap(cur[i], cur[j]);

    return cur;
}


void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
{
    int i = m -1, j = n-1;
    int k = m + n - 1;

    while(i >= 0 && j >= 0)
    {
        if(nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        }
        else {
            nums1[k--] = nums2[j--];
        }
    }

    while(j >= 0)
    {
        nums1[k--] = nums2[j--];
    }

}

std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();

    int left = 0, right = n - 1;
    int up = 0, down = m - 1;

    std::vector<int> res;

    while(res.size() < m*n)
    {
        for(int j = left; j <= right && res.size() < m*n; j++; ) {
            res.push_back(matrix[left][j]);
        }

        for(int i = up + 1; i < down && res.size() < m*n; i++;) {
            res.push_back(matrix[i][right]);
        }

        for(int j = right; j >= left && res.size() < m*n; j--) {
            res.push_back(matrix[down][j]);
        }

        for(int i = down - 1; i > up && res.size() < m*n; i--) {
            res.push_back(matrix[i][left]);
        }

        left++, right--;
        up++, down--;
    }

    return res;
}

int i = 0;

void test()
{
    int num = 100;
    for(int n = 0; n < num; n++) i  = i + 1;
}

/*
void merge(std::vector<int> &nums, int left, int mid, int right);

void mergeSort(std::vector<int> &nums, int left, int right)
{
    if(left < right)
    {
        int mid = left + ((right - left) >> 1);
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

}

void merge(std::vector<int> &nums, int left, int mid, int right)
{
    int lindex = left, rindex = mid + 1;
    int *team = new int[right - left + 1];
    int teamIndex = 0;

    while(lindex <= mid && rindex <= right)
    {
        if(nums[lindex] < nums[rindex]) {
            team[teamIndex++] = nums[lindex++];
        }
        else {
            team[teamIndex++] = nums[rindex++];
        }
    }

    while(lindex <= mid) {
        team[teamIndex++] = nums[lindex++];
    }

    while(rindex <= right) {
        team[teamIndex++] = nums[rindex++];
    }

    for(int i = 0; i < teamIndex; i++) {
        nums[left+i] = team[i];     //注意left一定要加上
    }

    delete[] team;

}


int reversePairs(std::vector<int> &nums);
int mergeSort(std::vector<int> &nums, int left, int right);


int main(void) {
    std::vector<int> nums = {1,3,2,3,1};

    std::cout << reversePairs(nums) << std::endl;

    return 0;
}


//计算逆序对(归并排序)

int reversePairs(std::vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}

int mergeSort(std::vector<int> &nums, int left, int right)
{
    if(left >= right) return 0;

    int mid = left + ((right - left) >> 1);

    int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);

    std::vector<int> tmp(right - left + 1);
    int index = 0;

    int lindex = left, rindex = mid + 1;

    while(lindex <= mid && rindex <= right)     //这和剑指上的思路不同,这是从左往右合并判断
    {
        if(nums[lindex] <= nums[rindex]) {      //注意:这是小于等于
            count += rindex - (mid + 1);
            tmp[index++] = nums[lindex++];
        }
        else {
            tmp[index++] = nums[rindex++];
        }
    }

    while(lindex <= mid) {
        count += rindex - (mid + 1);
        tmp[index++] = nums[lindex++];
    }

    while(rindex <= right) {
        tmp[index++] = nums[rindex++];
    }

    for(int i = 0; i < index; i++) {
        nums[left + i] = tmp[i];
    }    

    return count;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *curA = headA, curB = headB;

    while(curA != curB)
    {
        // curA = curA->next ? curA->next : headB;
        // curB = curB->next ? curB->next : headA;
        curA = curA ? curA->next : headB;
        curB = curB ? curB->next : headA;
    }

    return curA;
}






class String
{
private:
    char *pStr;
    unsigned int size;

public:
    String(const char* str = NULL) {
        if(str == NULL) {
            pStr = new char[1];
            *pStr = '\0';
            size = 0;
        }
        else {
            int len = strlen(str);
            pStr = new char[len + 1];
            strcpy(pStr, str);
            size = len;
        }
    }

    ~String() {
        delete [] pStr;
    }

    String(const String &s) {
        int len = s.size;
        pStr = new char[len + 1];
        strcpy(pStr, s.pStr);
        size = len;
    }

    String& operator=(const String &s) {
        if(this != &s)
        {
            delete[] pStr;
            int len = s.size;
            pStr = new char[len + 1];
            strcpy(pStr, s.pStr);
            size = len;
        }

        return *this;
    }

    int getSize() {
        return this->size;
    }

};


int JudgeSystem();

int main() {
    // shared_ptr<int> p1(new int(10));
    // shared_ptr<int> p2 = p1;
    // std::cout << p1.use_count() << std::endl;
    // std::cout << p1.use_count() << std::endl;

    std::cout << JudgeSystem() << std::endl;

    return 0;
}

int JudgeSystem()
{
    union Test {
        int x;
        char c;
    };

    Test demo;
    demo.x = 1;

    return demo.c;
}


template<class T>
class shared_ptr
{
private:
    T *ptr;
    int *count;

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
        count = smartPtr.count;

        (*count)++;
    }

    shared_ptr& operator=(const shared_ptr &smartPtr) 
    {
        if(ptr != smartPtr.ptr) 
        {
            if(ptr != nullptr) 
            {
                (*count)--;
                if(*count == 0) {
                    delete ptr;
                    delete count;
                }
            }

            ptr = smartPtr.ptr;
            count = smartPtr.count;
            (*count)++;
        }

        return *this;
    }

    T& operator*() {
        if(ptr != nullptr) {
            return *ptr;
        }
    }

    T& operator->() {
        if(ptr != nullptr) {
            return ptr;
        }
    } 

    ~shared_ptr()
    {
        if(ptr == nullptr) {
            delete count;
        }
        else if(--(*count) == 0) {
            delete ptr;
            delete count;
        }
    }

    int use_count() {
        return *count;
    }

};




int strcmp(const char *str1, const char* str2);

int main() {
    // char str1[1] = {1}; 
    // char str2[1] = {255};
    // char *str1 = 1, *str2 = 255;
    // char str1[5] = "bcd", str2[5] = "abaf";

    // std::cout << strcmp(str1, str2) << std::endl;

    char c = -2;

    // std::cout << (unsigned char)c << std::endl;
    printf("%d\n", (unsigned char)c);

    return 0;
}

int strcmp(const char *str1, const char* str2)
{
    int res = 0;

    // while(!(res = *(unsigned char*)str1 - *(unsigned char*)str2) && *str1)
    // {
    //     str1++;
    //     str2++;
    // }

    while(!(res = *str1 - *str2) && *str1) {
        str1++;
        str2++;
    }

    if(res > 0) return 1;
    else if(res < 0) return -1;

    return 0;
}


#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int ready = 0;

void printString_1()
{
    std::unique_lock<std::mutex> lk(mtx);

    int cnt = 0;
    while(cnt < 10)
    {
        while(ready != 0) cv.wait(lk);

        std::cout << std::this_thread::get_id() << " " << "A" << std::endl;

        ready = 1;
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
        while(ready != 1) cv.wait(lk);

        std::cout << std::this_thread::get_id() << " " << "B" << std::endl;

        ready = 2;
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
        while(ready != 2) cv.wait(lk);

        std::cout << std::this_thread::get_id() << " " << "C" << std::endl;

        ready = 0;
        cnt++;
        cv.notify_all();
    }
}

int maxResult(std::vector<int> &nums, int k);


int main() {
    std::vector<int> nums = {1,-5,-20,4,-1,3,-6,-3};
    int k = 2;

    std::cout << maxResult(nums, k) << std::endl;

    return 0;
}   

int maxResult(std::vector<int> &nums, int k)
{
    int i = 0;

    int res = nums[0];

    while(i < nums.size() - 1)
    {
        int maxVal = nums[i+1];
        int maxIndex = i + 1;

        int j = i + 2;
        for(; j <= std::min(i + k, (int)(nums.size() - 1)); j++) 
        {
            if(maxVal < nums[j]) {
                maxVal = nums[j];
                maxIndex = j;
            }
            else if(maxVal == nums[j] && maxVal < 0) {
                maxVal = nums[j];
                maxIndex = j;
            }
        }

        res += nums[maxIndex];

        // std::cout << res << std::endl;

        i = maxIndex;

        // std::cout << i << std::endl;
    }

    return res;
}

// Leetcode第1696题 : Jump Game VI
// 维持一个单调递减队列

int maxResult(std::vector<int> &nums, int k)
{
    std::deque<int> dq;
    dq.push_back(0);

    for(int i = 1; i < nums.size(); i++)
    {
        if(dq.front() + k < i) {
            dq.pop_front();
        }

        nums[i] += nums[dq.front()];

        while(!dq.empty() && nums[i] > nums[dq.back())]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    return nums[dq.back()];
}


// 堆排序
void heapAdjust(std::vector<int> &nums, int start, int end)
{
    int tmp = nums[start];

    for(int i = 2*start; i <= end; i *= 2)
    {
        if(i < end && nums[i] < nums[i+1]) i++;

        if(tmp >= nums[i]) break;

        nums[start] = nums[i];

        start = i;
    }

    nums[start] = tmp;
}


void heapSort(std::vector<int> &nums)
{
    int len = nums.size() - 1;

    for(int i = len/2; i > 0; i--) {
        heapAdjust(nums, i, len);
    }

    for(int i = len; i > 1; i--) {
        std::swap(nums[i], nums[1]);
        heapAdjust(nums, 1, i - 1);
    }

}
ListNode *addTwoNumber(ListNode *l1, ListNode *l2)
{
    ListNode *head = new ListNode(-1);
    ListNode *base = head;

    int carry = 0;

    while(l1 || l2 || carry) 
    {
        carry = (l1 ? l1->val ? 0) + (l2 ? l2->val ? 0);
        base->next = new ListNode(carry%10);
        carry /= 10;

        base = base->next;

        if(l1) l1 = l1->next;
        
        if(l2) l2 = l2->next;
    }

    return head->next;
}

template<class T>
struct plus {
    T operator()(const T &x, const T &y) const {
        return x + y;
    }
};

template<class T>
struct minus {
    T operator()(const T &x, const T &y) const {
        return x - y - z;
    }
};


void insertSort(std::vector<int> &nums)
{
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] < nums[i-1]) {
            int tmp = nums[i];
            int j = i-1;
            for(; j >= 0 && nums[j] > tmp; j--) {
                nums[j+1] = nums[j];
            }
            nums[j+1] = tmp;
        }
    }
}

std::string addTwoNumber(std::string num1, std::string num2);


int main() {
    std::string num1 = "123", num2 = "959";

    std::cout << addTwoNumber(num1, num2) << std::endl;

    return 0;
}



std::string addTwoNumber(std::string num1, std::string num2)
{
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int carry = 0;
    int i = 0, j = 0;
    std::string res;

    while(i != num1.size() || j != num2.size() || carry)
    {
        carry += (i == num1.size() ? '0' : num1[i++]) - '0' + (j == num2.size() ? '0' : num2[j++]) - '0';

        res += std::to_string(carry%10);

        carry /= 10;
    }

    reverse(res.begin(), res.end());

    return res;
}

// dp[i] 代表第i的元素结尾满足条件的子数组总个数
// if nums[i] < L, dp[i] = dp[i-1]
// if nums[i] > R, dp[i] = 0, prev = i
// if L <= nums[i] <= R, dp[i] = i - prev, 

// base case i = 0

int numsSubarrayBoundedMax(std::vector<int> &nums, int left, int right)
{
    std::vector<int> dp(nums.size(), 0);

    int prev = -1;

    if(nums[0] >= left && nums[0] <= right) dp[0] = 1;
    else if(nums[0] > right) prev = 0;

    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] < left && i > 0) {
            dp[i] = dp[i-1];
        }
        else if(nums[i] > right) {
            dp[i] = 0;
            prev = i;
        }
        else if(nums[i] >= left && nums[i] <= right) {
            dp[i] = i - prev;
        }
    }

    return accumulate(dp.begin(), dp.end(), 0);
}

int numsSubarrayWithSum(std::vector<int> &nums, int left, int right)
{
    int prev = -1;

    int dp = 0;
    int res = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] < left && i > 0) {
            res += dp;
        }
        else if(nums[i] > right) {
            dp = 0;
            prev = i;
        }
        else if(nums[i] >= left && nums[i] <= right) {
            dp = i - prev;
            res += dp;
        }
    }

    return res;    
}


#include <thread>
// #include <stdio.h>

const char* getText() ;

// class A
// {
// public:
//     A() { std::cout << "A" << std::endl; }
//     ~A() { std::cout << "~A" << std::endl; }

// };

// class B
// {
// public:
//     B(A &a):_a(a) {
//         std::cout << "B" << std::endl;
//     }
//     ~B() {
//         std::cout << "~B" << std::endl;
//     }

// private:
//     A _a;

// };

std::string reverse(std::string str)
{
    if(str.size() <= 1) return str;

    return reverse(str.substr(1)) + str.substr(0, 1);
}

class A {
public:
    A() {
        m_data = 1;
    }
    virtual ~A() {}
    int getData() {
        return m_data;
    }

private:
    int m_data;

};

class B : public A
{
public:
    B(){}
    virtual ~B(){}

};

int main() {

    // B b;
    // memset(&b, 0x0, sizeof(b));

    char *c[] = {"ENTER", "NEW", "POINT", "FIRST"};
    char **cp[] = {c + 3, c+2, c+1, c};
    char ***cpp = cp;

    printf("%s\n", **++cpp);
    printf("%s\n",*--*++cpp+3);
    printf("%s\n",*cpp[-2]+3);
    printf("%s\n",cpp[-1][-1]+1);

    // const char* showText = getText();
    // printf("%s\n", showText);

    // A a;
    // B b(a);

    // std::string str = "hello";

    // std::cout << reverse(str) << std::endl;
    

    return 0;
}

const char* getText() 
{
    const char* text = "this is the show Text";
    return text;
}

int reversePairs(std::vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}


int mergeSort(std::vector<int> &nums, int left, int right)
{
    if(left >= right) return 0;

    int mid = left + ((right - left) >> 1);

    int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);

    std::vector<int> tmp(right - left + 1);
    int index = 0;

    int lindex = left, rindex = mid + 1;

    while(lindex <= mid && rindex <= right)
    {
        if(nums[lindex] <= nums[rindex]) {
            count += rindex - (mid + 1);
            tmp[index++] = nums[lindex++];
        }
        else {
            tmp[index++] = nums[rindex++];
        }
    }

    while(lindex <= mid) {
        count += rindex - (mid + 1);
        tmp[index++] = nums[lindex++];
    }

    while(rindex <= right) {
        tmp[index++] = nums[rindex++];
    }

    for(int i = 0; i < tmp.size(); i++) {
        nums[left + i] = tmp[i];
    }

    return count;
}


int mergeSort(std::vector<int> &nums, int left, int right)
{
    if(left >= right) return 0;

    int mid = left + ((right - left) >> 1);

    int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);

    std::vector<int> tmp(right - left + 1);
    int index = right - left;

    int lindex = mid, rindex = right;

    while(lindex >= left && rindex >= mid + 1)
    {
        if(nums[lindex] > nums[rindex]) {       //从右往左计数
            count += rindex - mid;
            tmp[index--] = nums[lindex--];
        }
        else {
            tmp[index--] = nums[rindex--];
        }
    }

    while(lindex >= left) {
        tmp[index--] = nums[lindex--];
    }

    while(rindex >= mid + 1) {
        tmo[index--] = nums[rindex--];
    }

    for(int i = 0; i < tmp.size(); i++) {
        nums[left+i] = tmp[i];
    }

    return count;
}



class Base 
{
public:
    Base(){
        std::cout << "I am base constructor" << std::endl;
    }
    virtual void print() {
        std::cout << "I am base" << std::endl;
    }

private:
    short val;
};

class Derived : public Base
{
public:
    void print() {
        std::cout << "I am derived" << std::endl;
    }

};


int main() {
    // Base demo(1);

    // Derived d;

    // Base *pb = new Base;
    // pb->print();
    // Base *pb = &d;
    // pb->print();

    // Derived *pd = &d;
    // pd->print();

    Derived d;
    std::cout << sizeof(d) << std::endl;

    return 0;
}

int numMatchingSubseq(std::string s, std::vector<std::string> &words)
{
    int count = 0;
    for(const auto &word : words) {
        if(isMatch(word, s)) {
            count++;
        }
    }

    return count;
}

bool isMatch(std::string &t, std::string &p)
{
    int j = 0;

    for(int i = 0; i < p.size() && j < t.size(); i++) {
        if(p[i] == t[j]) j++;
    }

    return j == t.size();
}

int numMatchingSubseq(std::string s, std::vector<std::string> &words)
{
    int count = 0;

    std::vector<std::vector<int>> index(128);
    for(int i = 0; i < s.size(); i++) {
        index[s[i]].push_back(i);
    }

    for(const auto &word : words)
    {
        int j = 0, k = 0;
        for(; k < word.size(); k++) {
            char ch = word[k];
            if(index[ch].empty()) break;

            auto pos = lower_bound(index[ch].begin(), index[ch].end(), j);
            if(pos == index[ch].end()) break;

            j = *pos + 1;
        }

        if(k == word.size()) count++;
    }

    return count;
}

int numMatchingSubseq(std::string s, std::vector<std::string> &words)
{
    std::vector<std::vector<int>> alpha(26);
    for(int i = 0; i < s.size(); i++) {
        alpha[s[i]-'a'].push_back(i);
    }

    int count = 0;

    for(const auto &word : words)
    {
        int x = 0;
        bool find = true;

        for(char &c : word) {
            auto it = lower_bound(alpha[c-'a'].begin(), alpha[c-'a'].end(), x);
            if(it == alpha[c-'a'].end()) {
                find = false;
                break;
            }
            x = *it + 1;
        }

        if(find) count++;
    }

    return count;
}

struct Base1 {
    Base1() = default;
    Base1(const std::string &);
    Base1(std::shared_ptr<int>);
};

struct Base2 {
    Base2() = default;
    Base2(const std::string &);
    Base2(int);
};

struct D1: public Base1, public Base2 {
    using Base1::Base1;
    using Base2::Base2;
};


// int main() {

//     D1 d;

//     // int *p;
//     // std::cout << sizeof(*p) << std::endl;

//     // int x[10] = {1,2,3};
//     // int *p = x;

//     // std::cout << sizeof(x)/sizeof(*x) << std::endl;
//     // std::cout << sizeof(p)/sizeof(*p) << std::endl;

//     // std::cout << *p << std::endl;
//     // std::cout << sizeof(*x) << std::endl;

//     return 0;
// }


int bfs(std::vector<std::vector<char>> &map, int i, int j);

struct Node {
    int x, y, k, step;
    Node(int m_x, int m_y, int m_k, int m_step) {
        x = m_x;
        y = m_y;
        k = m_k;
        step = m_step;
    }
};

std::vector<int> dir = {-1, 0, 1, 0, -1};

int visited[105][105][1030];

int main() {
    int M, N;
    std::cin >> M >> N;
    std::vector<std::vector<char>> map(M, std::vector<char>(N));

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> map[i][j];
        }
    }

    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(map[i][j] == '2') {
                visited[i][j][0] = 1;
                std::cout << bfs(map, i, j) << std::endl;
                return 0;
            }
        }
    }

    return 0;
}


int bfs(std::vector<std::vector<char>> &map, int i, int j)
{
    int m = map.size(), n = map[0].size();

    std::queue<Node> que;
    que.push(Node(i, j, 0, 0));

    while(!que.empty())
    {
        Node tmp = que.front();   que.pop();

        if(map[tmp.x][tmp.y] == '3') return tmp.step;

        for(int k = 0; k < dir.size() - 1; k++) {
            int x = tmp.x + dir[k], y = tmp.y + dir[k+1];
            if(x < 0 || x >= m || y < 0 || y >= n || map[x][y] == '0') continue;
                        
            int key = tmp.k;

            if('a' <= map[x][y] && map[x][y] <= 'z') key |= (1 << (map[x][y] - 'a'));
            if(('A' <= map[x][y] && map[x][y] <= 'Z') && ((key & (1 << (map[x][y] - 'A'))) == 0)) continue; //

            if(!visited[x][y][key]) {
                visited[x][y][key] = 1;
                que.push(Node(x, y, key, tmp.step + 1));
            }
        }
    }

}

std::string removeDuplicate(std::string s)
{
    std::string res;

    for(const char &c : s) {
        if(res.empty()) {
            res.push_back(c);
            continue;
        }
        if(res.back() == c) res.pop_back();
        else res.push_back(c);
    }

    return res;
}



class Singleton
{
private:
    Singleton() {}
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
    

public:
    // static Singleton& getInstance() {
    //     static Singleton demo;
    //     return demo;
    // }
    static Singleton& getInstance();

    void print() {
        std::cout << "do something!" << std::endl;
    }

};


Singleton& Singleton::getInstance()
{
    static Singleton demo;
    return demo;
}


int main() {
    Singleton& demo = Singleton::getInstance();

    demo.print();

    return 0;
}

int findMaxConsectiveOnes(std::vector<int> &nums)
{
    int count = 0;

    int left = 0, right = 0;
    while(left < nums.size())
    {
        if(nums[left] == 1) {
            right = left;
            while(right + 1 < nums.size() && nums[right] == nums[right+1]) right++;
            count = std::max(count, right - left + 1);
            left = right + 1;
        }
        else {
            left++;
        }
    }

    return count;
}


int findMaxConsectiveOnes(std::vector<int> &nums)
{
    int count = 0, maxLen = 0;

    for(int &n : nums) {
        if(n == 1) maxLen = std::max(maxLen, ++count);
        else count = 0;
    }

    return maxLen;
}



void insertSort(std::vector<int> &nums)
{
    for(int i = 1; i < nums.size(); i++) 
    {
        if(nums[i] < nums[i-1]) {
            int tmp = nums[i];
            int j = i - 1;
            for(; nums[j] >= tmp && j >= 0; j--) {
                nums[j+1] = nums[j];
            }
            nums[j+1] = tmp;
        }
    }
}

void shellSort(std::vector<int> &nums)
{
    int gap = nums.size();

    while(gap >= 1)
    {
        gap = gap/3 + 1;
        
        for(int i = gap; i < nums.size(); i++)
        {
            if(nums[i] < nums[i-gap]) {
                int tmp = nums[i];
                int j = i - gap;
                for(; nums[j] > tmp && j >= 0; j -= gap) {
                    nums[j+gap] = nums[j];
                }
                nums[j+gap] = tmp;
            }
        }


        for(const int &n : nums) {
            std::cout << n << " ";
        }
        std::cout << std::endl;

        if(gap == 1) break;
    }

}

int partition(std::vector<int> &nums, int left, int right)
{
    int pivotkey = nums[left];

    while(left < right)
    {
        while(left < right && nums[right] > pivotkey) right--;
        std::swap(nums[left], nums[right]);

        while(left < right && nums[left] < pivotkey) left++;
        std::swap(nums[left], nums[right]);
    }

    return left;
}


void quickSort(std::vector<int> &nums, int left, int right)
{
    if(left < right)
    {
        int pivot = partition(nums, left, right);
        quickSort(nums, left, pivot - 1);
        quickSort(nums, pivot + 1, right);
    }

}



int main() {
    std::vector<int> nums = {2,1,3,6,4,7,5,8,9};

    quickSort(nums, 0, nums.size() - 1);

    for(const int &n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}



int main() {
    // std::vector<int> nums = {-1,-2,-3};

    // transform(nums.begin(), nums.end(), nums.begin(), [](int i) -> int { 
    //     return i < 0 ? -i : i;
    // });

    // for(const int &n : nums) {
    //     std::cout << n << " ";
    // }
    // std::cout << std::endl;

    // int a = 0x1234;
    // char *p = (char*)&a;

    // printf("%x\n", *(p+2));

    // std::cout << *p << std::endl;

    // int a = 0x44332211;
    // int *p1 = &a;
    // char *p2 = (char*)&a;
    // p2++;

    // printf("%x\n", *p1);
    // printf("%x\n", *p2);

    // int *a = (((int*)0) + 4);

    // printf("%d\n", a);

    // long num = 0x0095AFF9F703A8;

    // printf("%lu\n", num);

    unsigned char *hex = "0x0095AFF9F703A8";

    unordered_map<char, int> hash = {{'A',10}, {'B',11}, {'C',12}, {'D',13}, {'E',14}, {'F',15}};

    long long res = 0;

    int n = strlen(hex);

    for(int i = n - 1; i >= 0; i--)
    {

    } 

    return 0;
}


//给出一个用16进制表示的字符串，将该字符串转化成十进制数字表示



//开链法实现哈希


#define HASHSIZE 10     //哈希表元素个数

typedef struct Node {
    char *key;
    char *value;
    Node *next;
} Node;


class HashTable
{
private:
    Node *node[HASHSIZE];

public:
    HashTable() {
        memset(node, NULL, sizeof(node));
    }


    //散列函数，计算key值位于node数组中的位置
    int Hash() {}

    //查找key值
    Node* find(const char *key) 
    {
        int index = hash(key);      //由散列函数计算出在节点数组node中的下标

        Node *pNode = node[index];
        while(pNode)
        {
            //strcmp相同返回0
            if(!strcmp(pNode->key, key)) return pNode;
            
            pNode = pNode->next;
        }

        return NULL;    //表示未查找到
    }

    //插入键值对
    bool insert(const char *key, char *value)
    {
        Node *pNode = find(key);

        //key值不能存在
        if(pNode == NULL)
        {
            int index = hash(key);
            pNode = (Node*)malloc(sizeof(Node));

            if(pNode == NULL) return false;     //申请失败则返回false

            pNode->key = key;
            pNode->value = value;
            node[index] = pNode;
        }

        //key值已经存在,则更新value值
        pNode->value = value;

        return true;
    }

    //删除某个key
    bool deleteKey(const char *key) 
    {
        Node *pNode = find(key);
        if(pNode == NULL) return false;     //不存在该key值

        //找到要删除节点的上一个节点prev,将prev指向要删除节点的下一个节点
        int index = hash[key];
        if(node[index] == pNode) {
            free(pNode);                    //不存在哈希冲突，也就是该位置链表只有一个节点
            pNode = NULL;
        }
        else {                              //存在哈希冲突
            Node *prev = node[index];
            while(prev->next != pNode) {
                prev = prev->next;
            }
            prev->next = pNode->next;
            free(pNode);
            pNode = NULL;
        }

        pNode = NULL;
        return true;
    }

};



struct Node {
    int value;
    Node *next;
};

int main() {
    // Node *p1 = (Node*)malloc(sizeof(Node));
    // p1->val = 1;
    // p1->next = nullptr;

    Node* node[1];
    // memset(node, NULL, sizeof(node));
    node[0] = NULL;

    if(!node[0]->next) {
        std::cout << "null" << std::endl;
    }

    return 0;
}

int kthSmallest(std::vector<std::vector<int>> &matrix, int k)
{
    int m = matrix.size(), n = matrix[0].size();

    int left = matrix[0][0], right = matrix[m-1][n-1];

    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);

        for(int i = 0; i < m; i++) {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if(count < k) {
            left = mid + 1;
        }
        else if(count >= k) {
            right = mid - 1;
        }
    }

    return left;
}



/*
class A {
public:
    void fun() {
        std::cout << "A" << std::endl;
    }
};

class B : public A {

};

class C : public A {

};

class D : public B, public C {
public:
    void funD() {
        std::cout << "D" << std::endl;
    }
};
*/

// class Base
// {
// private:
//     virtual void fun() { std::cout << "Base" << std::endl; }    
//     friend void test() {
//         std::cout << "hello" << std::endl;
//         // fun();
//     };
// };

// class Derived : public Base
// {
// public:
//     void fun() { std::cout << "Derived" << std::endl; }
// };

// void test();

// class Base
// {
// public:
//     // Base() { std::cout << "hello" << std::endl; }
//     // Base() = default;
//     Base(int m) : val(m) {}

// private:
//     int val;
// };


// class Derived : public Base
// {
// public:
//     Derived(int m_val): Base(m_val) {}

// };


// void fun(void) {
//     std::cout << "hello" << std::endl;
// }
/*
void *fun(void) {
    std::cout << "1" << std::endl;
}

int insertSort(std::vector<int> &nums);
int shellSort(std::vector<int> &nums);
void heapSort(std::vector<int> &nums);
void heapAdjust(std::vector<int> &nums, int start, int end);

int main() {
    // typedef void(*pFunc)(void);
    // void(*pFunc)(void);
    // pFunc = fun;

    // pFunc();

    // D d;
    // d.funD();
    // A *ptr = new D();
    // ptr->funD();

    // Base *ptr = new Derived()
    // Derived d;
    // d.fun();

    // Base *ptr = new Derived();
    // ptr->fun();

    // test();
    // Base b;
    // b(1);
    // Derived(1);
    // Base a(1), b;

    // std::vector<int> nums = {-1, 9,4,2,1,0};

    // heapSort(nums);

    // for(const int &n : nums) {
    //     std::cout << n << " ";
    // }
    // std::cout << std::endl;
    

    return 0;

    // atexit(fun);
}

int insertSort(std::vector<int> &nums)
{
    int n = nums.size();

    for(int i = 1; i < n; i++) {
        if(nums[i] < nums[i-1]) {
            int tmp = nums[i];
            int j = i-1;
            for(; j >= 0 && nums[j] >= tmp; j--) {
                nums[j+1] = nums[j];
            }
            nums[j+1] = tmp;
        }
    }

}


int shellSort(std::vector<int> &nums)
{
    int n = nums.size();
    int gap = n;

    while(gap >= 1)
    {
        gap = gap/3 + 1;

        for(int i = gap; i < n; i++) {
            if(nums[i] < nums[i-gap]) 
            {
                int tmp = nums[i];
                int j = i - gap;
                for(; j >= 0 && nums[j] >= tmp; j -= gap) {
                    nums[j+gap] = nums[j];
                }
                nums[j+gap] = tmp;
            }
        }

        if(gap == 1) break;
    }

}


void heapSort(std::vector<int> &nums)
{
    int n = nums.size() - 1;

    for(int i = n/2; i >= 1; i--) {
        heapAdjust(nums, i, n);
    }

    for(int i = n; i > 1; i--) {
        std::swap(nums[1], nums[i]);
        heapAdjust(nums, 1, i-1);
    }

}

void heapAdjust(std::vector<int> &nums, int start, int end)
{
    int tmp = nums[start];

    for(int i = 2*start; i <= end; i *= 2)
    {
        if(i < end && nums[i] < nums[i+1]) i++;

        if(tmp > nums[i]) break;

        nums[start] = nums[i];

        start = i;
    }

    nums[start] = tmp;
}





// int*  find(int *arrayHead, int arraysize, int value)
// {
//     int i = 0;
//     for(; i < arraysize; i++) {
//         if(arrayHead[i] == value) break;
//     }

//     return &arrayHead[i];
// }

// int* find(int *begin, int *end, int value)
// {
//     while(begin != end && *begin != value) begin++;

//     return begin;
// }

template<class T>
T* find(T* begin, T* end, const T &value)
{
    while(begin != end && *begin != value) begin++;

    return begin;
}




#define max 100

std::string to_string(int n)
{
    int m = n;
    char s[max], ss[max];

    int i = 0, j = 0;

    if(n < 0) {
        m = -n;
        ss[j++] = '-';
    }

    while(m > 0) {
        s[i++] = m%10 + '0';
        m /= 10;
    }

    i--;
    while(i >= 0) {
        ss[j++] = s[i--];
    }

    ss[j] = '\0';

    return ss;
}

int main() {
    // const int arraysize = 7;
    // int ia[arraysize] = {0,1,2,3,4,5,6};

    // int *end = ia + arraysize;

    // int *ip = find(ia, end, 4);

    // if(ip == end) std::cout << "Not Found" << std::endl;
    // else std::cout << "Found" << std::endl;

    // std::shared_ptr<int> sp1 = std::make_shared<int>(10);
    // std::shared_ptr<int> sp2 = sp1;

    // std::cout << sp2.use_count() << std::endl;

    // std::cout << to_string(-12) << std::endl;

    std::stringstream in;

    int n = 100;

    in << n;

    std::string s1 = in.str();

    std::cout << sizeof(s1) << std::endl;


    return 0;
}

// res = res*10 + (flag)*s[i]-'0'
// if res < 0, res*10 < INT_MIN || n > 8  return INT_MIN
// if res > 0, res*10 > INT_MAX || n > 7  return INT_MIN

int myAtoi(std::string s)
{
    int res = 0;

    int i = 0;
    while(isspace(s[i])) i++;

    bool minus = false;
    if(s[i] == '-') {
        minus = true;
        i++;
    }
    else if(s[i] == '+') {
        i++;
    }

    int flag = minus ? -1 : 1;

    for(; i < s.size(); i++)
    {
        if(!isdigit(s[i])) break;

        if(res < INT_MIN/10 || (res == INT_MIN/10 && s[i] > '8')) return INT_MIN;
        else if(res > INT_MAX/10 || (res == INT_MAX/10 && s[i] > '7')) return INT_MAX;

        res = res*10 + flag*(s[i] - '0');
    }

    return res;
}



int main() {
    std::vector<std::vector<std::pair<int,int>>> nums(10000);

    int a,b,c;
    char s;

    getchar();
    while(getchar() == '[') {
        scanf("%d%c%d%c%d%c%c", &a, &s, &b, &s, &c, &s, &s);
        nums[a].push_back({b,c});
        std::cout << a << " " << b << " " << c << std::endl;
    }


    return 0;
}


template<class T>
class shared_ptr
{
private:
    T *ptr;
    int *count;

public:
    shared_ptr(T *pointer = nullptr) 
    {
        if(pointer == nullptr) {
            count = new int(0);
        }
        else {
            ptr = pointer;
            count = new int(1);
        }
    }

    shared_ptr(const shared_ptr &smartPtr) 
    {
        ptr = smartPtr.ptr;
        count = smartPtr.count;

        (*count)++;
    }

    shared_ptr& operator=(const shared_ptr &smartPtr)
    {
        if(ptr != smartPtr.ptr)
        {
            if(ptr != nullptr && --(*count) == 0) {
                delete ptr;
                delete count;
            }

            ptr = smartPtr.ptr;
            count = smartPtr.count;
            (*count)++;
        }
    }

    T& operator*() { return *ptr; }

    T* operator->() { return ptr; }

    ~shared_ptr() 
    {
        if(ptr == nullptr) {
            delete count;
        }
        else if(--(*count) == 0) {
            delete ptr;
            delete count;
        }
    }
};

/*
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

struct Node {
    int val;
    shared_ptr<Node> next;

    Node(int m_val) : val(m_val) {}

    ~Node() {
        std::cout << "~Destructor" << std::endl;
    }

};




class String
{
private:
    char *str;
    int len;

public:
    String(const char* s) 
    {
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }

    String(const String &demo) 
    {
        len = demo.len;
        str = new char[len + 1];
        strcpy(str, demo.str);
        std::cout << "拷贝构造" << std::endl;
    } 

    String operator=(const String &demo) 
    {
        if(this == &demo) return *this;

        delete[] str;

        len = demo.len;
        str = new char[len + 1];
        strcpy(str, demo.str);

        std::cout << "赋值" << std::endl;
        return *this;
    }

    ~String()
    {
        std::cout << "析构" << std::endl;
        delete[] str;
    }

    void print() {
        std::cout << str << std::endl;
    }

};



int main() {

    String str1("abc");
    str1 = str1;
    // String str2("123");
    // String str3("456");
    // String str4;

    // str1.print();
    // str2.print();
    // std::cout << "hello" << std::endl; 
    // str1 = str2 = str3;
    // std::cout << "hello" << std::endl;
    // str4.print();

    // shared_ptr<int> sm(new int(10));
    // std::cout << *sm << std::endl;
    // shared_ptr<int> sm2(sm);
    // sm = sm2;
    // std::cout << *sm << std::endl;

    // shared_ptr<Node> p1 = new Node(1);
    // shared_ptr<Node> p2 = new Node(2);
    // std::cout << p1->val << std::endl;
    // std::cout << p1->use_count() << std::endl;
    // std::shared_ptr<Node> p1(new Node(1));
    // std::shared_ptr<Node> p2(new Node(2));
    // std::cout << p1->val << std::endl;
    // p1->next = nullptr;
    // p2->next = p1;
    // pNode1->next = pNode2;
    // pNode2->next = pNode1;

    // std::shared_ptr<int> sp1 = std::make_shared<int>(22);
    // std::shared_ptr<int> sp2 = sp1;

    // std::cout << *sp1 << " " << *sp2 << std::endl;

    // sp1.reset();

    // std::cout << *sp1 << std::endl;

    return 0;
}

class MyString
{
private:
    int *pData;

public:
    MyString(char *data = nullptr);
    MyString(const MyString &demo);
    ~MyString();

    MyString& operator=(const MyString &demo);

}

MyString& MyString::operator=(const MyString &demo)
{
    if(this == &demo) return *this;

    delete[] pData;

    pData = new char[strlen(demo.pData) + 1];   //不是异常安全的
    memcpy(pData, str.pData);

    return *this;
}

MyString& MyString::operator=(const MyString &demo)
{
    if(this != &demo)
    {
        MyString tmp(demo);
        char *ptmp = tmp.pData;
        tmp.pData = pData;
        pData = ptmp;
    }

    return *this;
}




void* memcpy(void *des, const void *src, size_t size)
{
    char *pDes = NULL, *pSrc = NULL;

    //泛型指针不能执行加减操作，但是可以比较大小
    //如果存在内存重叠则从后往前进行赋值
    if(src < des && (char*)src + size > (char*)des)
    {
        pDes = (char*)des + size - 1;
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

char* strcpy(char *des, char *src)
{
    char *pDes = des;

    while((*des++ = *src++) != '\0');

    return pDes;
}

int strcmp(const char *str1, const char *str2);



int main() {
    char str1[] = "1", str2[] = "255";

    std::cout << strcmp(str1, str2) <<std::endl;

    return 0;
}

int strcmp(const char *str1, const char *str2)
{
    int res = 0;

    // while(!(res = *(unsigned char*)str1 - *(unsigned char*)str2) && *str1)
    while(!(res = *(char*)str1 - *(char*)str2) && *str1)
    {
        str1++;
        str2++;
    }

    if(res > 0) return 1;
    else if(res < 0) return -1;
    
    return res;
}





std::mutex mtx;
std::condition_variable cv;
int ready = 0;

void printString_1()
{
    std::unique_lock<std::mutex> lk(mtx);

    int count = 0;
    while(count < 10) 
    {
        while(ready != 0) cv.wait(lk);

        std::cout << std::this_thread::get_id() << " " << "A" << std::endl;
        
        ready = 1;
        count++;
        cv.notify_all();
    }

}

void printString_2()
{
    std::unique_lock<std::mutex> lk(mtx);

    int count = 0;
    while(count < 10) 
    {
        while(ready != 1) cv.wait(lk);

        std::cout << std::this_thread::get_id() << " " << "B" << std::endl;
        
        ready = 2;
        count++;
        cv.notify_all();
    }

}


void printString_3()
{
    std::unique_lock<std::mutex> lk(mtx);

    int count = 0;
    while(count < 10) 
    {
        while(ready != 2) cv.wait(lk);

        std::cout << std::this_thread::get_id() << " " << "C" << std::endl;
        
        ready = 0;
        count++;
        cv.notify_all();
    }

}




int main() {
    std::thread t1(printString_1);
    std::thread t2(printString_2);
    std::thread t3(printString_3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}


int val = 0;
std::mutex mut;

void increment1()
{
    for(int i = 0; i < 100; i++) {
        // mut.lock();
        // val++;
        // mut.unlock();
    }
}

void increment2()
{
    for(int i = 0; i < 100; i++) {
        // mut.lock();
        // val++;
        // mut.unlock();
    }
}

int main() {
    std::thread t1(increment1);
    std::thread t2(increment2);

    t1.join();
    t2.join();

    std::cout << val << std::endl;

    return 0;
}


*/

/*
    十个人排队使用打印机，任一时刻只能有一个人使用，用一个变量0和1两种状态分别表示这台打印机能不能使用
*/
/*

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
/*

void subi()
{
    std::unique_lock<std::mutex> lock(mut);

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


#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int k = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *fun1(void *arg)
{
    for(int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex);

        while(k != 0) {
            pthread_cond_wait(&cond, &mutex);
        }

        printf("A\n");

        k = 1;

        pthread_mutex_unlock(&mutex);
        pthread_cond_broadcast(&cond);
    }

}

void *fun2(void *arg)
{
    for(int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex);

        while(k != 1) {
            pthread_cond_wait(&cond, &mutex);
        }

        printf("B\n");

        k = 2;

        pthread_mutex_unlock(&mutex);
        pthread_cond_broadcast(&cond);
    }
    
}

void *fun3(void *arg)
{
    for(int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex);

        while(k != 2) {
            pthread_cond_wait(&cond, &mutex);
        }

        printf("C\n");

        k = 0;

        pthread_mutex_unlock(&mutex);
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

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
int firstNotSuccesiveNum(std::vector<int> &nums)
{
    std::set<int> mySet(nums.begin(), nums.end());

    int x = *mySet.begin();

    while(mySet.count(x)) {
        x++;
    }

    auto res = mySet.lower_bound(x);
    if(res == mySet.end()) return -1;

    return *res;
}


std::vector<int> theFreqencyOfNums(std::vector<int> &nums)
{
    std::vector<int> res(nums.size());

    for(const int &n : nums) {
        res[n-1]++;
    }

    return res;
}
demo


int firstNotSuccesiveNum(std::vector<int> &nums);
std::vector<int> theFreqencyOfNums(std::vector<int> &nums);

int main() {
    std::vector<int> nums = {1,1,4,5,2,6};

    // std::cout << firstNotSuccesiveNum(nums) << std::endl;
    std::vector<int> res = theFreqencyOfNums(nums);

    for(const int &n : res) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
void dfs(int num, std::vector<std::vector<int>> &graph, std::vector<int> &degree, std::vector<int> &ans)
{
    if(ans.size() == num) {
        res.push_back(ans);
        return;
    }

    for(int i = 1; i <= num; i++)
    {
        if(degree[i] == 0 && find(ans.begin(), ans.end(), i) == ans.end())  //ans中不存在这个数
        {
            ans.push_back(i);
            for(int &n : graph[ans.back()]) {
                --degree[n];
            }
            
            dfs(num, graph, degree, ans);

            ans.pop_back();
            for(int &n : graph[ans.back()]) {
                ++degree[n];
            }
        }
    }

}


/*
    输出有向无环图的所有拓扑排序序列


void dfs(int num, std::vector<std::vector<int>> &graph, std::vector<int> indegree, std::vector<int> &visited);

std::vector<int> ans;
std::vector<std::vector<int>> res;


//prepre表示节点的关系,num表示图的节点个数
std::vector<std::vector<int>> topologySort(int num, std::vector<std::vector<int>> &prere)    
{
    std::vector<std::vector<int>> graph(num + 1);       //建立临接表(临接表与临接矩阵的区别在于临接表只存储与给定节点相邻的元素)
    std::vector<int> indegree(num + 1);                 //记录节点的入度(节点是从1开始编号的)

    for(auto &e : prere) {
        graph[e[0]].push_back(e[1]);
        indegree[e[1]]++;
    }

    std::vector<int> visited(num + 1, 0);

    dfs(num, graph, indegree, visited);

    return res;
}


void dfs(int num, std::vector<std::vector<int>> &graph, std::vector<int> indegree, std::vector<int> &visited)
{
    if(ans.size() == num) {
        res.push_back(ans);
        return ;
    }

    for(int i = 1; i <= num; i++)
    {
        //该节点未遍历过,且度为0,则加入到结果中
        if(!visited[i] && indegree[i] == 0)
        {
            ans.push_back(i);
            visited[i] = 1;

            for(const int &n : graph[i]) {
                indegree[n]--;
            }

            dfs(num, graph, indegree, visited);

            //回溯
            ans.pop_back();
            visited[i] = 0;

            for(const int &n : graph[i]) {
                indegree[n]++;
            }
        }
    }

}


int main() {

    Singleton &demo =  Singleton::getInstance();

    // std::vector<std::vector<int>> prepre = {{1,2},{1,3},{2,4},{2,5},{3,4},{3,5},{4,6},{5,6}};
    // int num = 6;

    // /*
    // std::vector<int> ans = topologySort(num, prepre);

    // for(const int &n : ans) {
    //     std::cout << n << " ";
    // }
    // std::cout << std::endl;
    // */

    // auto res = topologySort(num, prepre);

    // for(auto &num : res) {
    //     for(auto &n : num) {
    //         std::cout << n << " ";
    //     }
    //     std::cout << std::endl;
    // }
/*
    return 0;
}

/*
class Singleton
{
private:
    Singleton() {
        std::cout << "我是懒汉式" << std::endl;
    }                                      //防止外部调用构造函数创建对象
    Singleton(Singleton const &single);                 //阻止拷贝创建对象              (将这两个函数放在public底下使用 =delete关键字来定义成删除函数也可以)
    Singleton& operator=(Singleton const &single);      //阻止复制运算符对对象复制

public:

    //懒汉式:只有调用getInstance函数才会创建对象
    static Singleton& getInstance() {       //提供一个全局访问点,就需要在类中定义一个static函数,返回在类中的唯一构造的实例
        static Singleton instance;          //这里的getInstace函数不能以值返回,主要是因为构造函数是私有的,外部不能创建临时对象
        return instance;
    }

};



class Singleton
{
private:
    Singleton() {
        std::cout << "我是懒汉式" << std::endl;
    }
    Singleton(Singleton const &);
    Singleton& operator=(Singleton const &);
    static Singleton *instance;
    static std::mutex mut;

public:
    static Singleton* getInstance() {
        
        //使用双检锁,只有判断指针为空的时候才加锁
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



void func()
{
    for(int i = 0; i < 3; i++) {
        // std::cout << "thread1" << std::endl;
        // Singleton *demo1 = Singleton::getInstance();
        Singleton &demo = Singleton::getInstance();
        // std::cout << demo1 << std::endl;
    }
}



int count = 0;

void dfs(std::vector<int> &nums, std::vector<int> &visited, int steps)
{
    if(steps == 10) {
        if(nums[1]*100 + nums[2]*10 + nums[3] + nums[4]*100 + nums[5]*10 + nums[6] == nums[7]*100 + nums[8]*10 + nums[9]) {
            printf("%d%d%d + %d%d%d = %d%d%d\n", nums[1], nums[2], nums[3], nums[4], nums[5], nums[6], nums[7], nums[8], nums[9]);
            count++;
        }
        return ;
    }

    for(int i = 1; i <= 9; i++)
    {
        if(!visited[i]) 
        {
            nums[steps] = i;
            visited[i] = 1;

            dfs(nums, visited, steps + 1);
            
            visited[i] = 0;
        }
    }

}

std::string addTwoNumber(std::string num1, std::string num2);

int main() {
    // std::vector<int> nums(10), visited(10, 0);

    // dfs(nums, visited, 1);

    // std::cout << count/2 << std::endl;

    std::string num1 = "1", num2 = "999";

    std::cout << addTwoNumber(num1, num2) << std::endl;

    return 0;
}

std::string addTwoNumber(std::string num1, std::string num2)
{
    if(num1.empty()) return num2;
    else if(num2.empty()) return num1;

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    std::string res;
    int carry = 0;
    int i = 0, j = 0;

    while(i < num1.size() || j < num2.size() || carry)
    {
        carry += (i < num1.size() ? (num1[i++]-'0') : 0) + (j < num2.size() ? (num2[j++] - '0') : 0);        

        res += std::to_string(carry%10);

        carry /= 10;
    }

    reverse(res.begin(), res.end());

    return res;
}


int i = 0;

void selfIncreasing() {
    for(int j = 0; j < 1000000; j++) {
        i++;
    }
}

int fun1(int i);
int fun2(unsigned int n);

int f(int m, int n) ;


int main() {

    std::cout << f(30, 10) << std::endl;

    // std::cout << fun2(fun1(101)) << std::endl;

    // std::thread threadOne(selfIncreasing);
    // std::thread threadTwo(selfIncreasing);

    // threadOne.join();
    // threadTwo.join();

    // std::cout << i << std::endl;

    // auto add = [](int a, int b) -> int { return a + b; };

    // std::cout << add(1,2) << std::endl;

    // std::cout << add(1,2) << std::endl;
    // std::cout << "hello" << std::endl;


    // int a = 1, b = 1, c = 1, d = 1, e

    return 0;
}



int f(int m, int n) 
{
    if(n == 0) return 1;
    else if(m < n) return 0;

    return f(m-1, n) + f(m, n-1);
}

int fun1(int i) 
{
    return i < 10 ? i : (5*fun1(i-1) + 2*fun1(i-2) + fun1(i-3) + fun1(i-4)) & 0x5ffff;
}

int fun2(unsigned int n) 
{
    unsigned int f = 2020;
    return (f&n)/2;
}

void bubbleSort(std::vector<int> &nums)
{
    int n = nums.size();

    bool flag = true;

    for(int i = 0; i < n && flag; i++) 
    {
        flag = false;
    
        for(int j = n-2; j >= i; j--) 
        {
            if(nums[j] > nums[j+1]) {
                std::swap(nums[j], nums[j+1]);
                flag = true;
            }
        }
    }

}

void selectSort(std::vector<int> &nums)
{
    int n = nums.size();

    for(int i = 0; i < n; i++)
    {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            if(nums[min] > nums[j]) min = j;
        }

        if(min != i) std::swap(nums[i], nums[min]);
    }

}

void insertSort(std::vector<int> &nums)
{
    int n = nums.size();

    for(int i = 1; i < n; i++)
    {
        if(nums[i] < nums[i-1]) 
        {
            int tmp = nums[i];
            int j = i - 1;
            for(; j >= 0 && nums[j] > tmp; j--) {
                nums[j+1] = nums[j];
            }
            nums[j+1] = tmp;
        }
    }
}

void shellSort(std::vector<int> &nums)
{
    int gap = nums.size(), n = nums.size();

    while(gap >= 1)
    {
        gap = gap/3 + 1;

        for(int i = gap; i < n; i++) 
        {
            if(nums[i] < nums[i-gap]) 
            {
                int tmp = nums[i];
                int j = i - gap;
                for(; j >= 0 && nums[j] > tmp; j -= gap) {
                    nums[j+gap] = nums[j];
                }
                nums[j+gap] = tmp;
            }
        }

        if(gap == 1) break;
    }

}

std::pair<int,int> find() {
    return {};
}


//方法一:
#define MIN(a, b) ((a) < (b) ? (a) : (b))   //加括号防止预处理展开的错误

// #define MIN(a, b) ({\
//     if(a < b) return a; \
//     return b;\
// })

//方法二:(宏里面如果有多行代码则需要使用 {} )
// #define MIN(a, b) ({ \
//     typeof(a) m_x = (a); \
//     typeof(b) m_y = (b); \
//     (m_x < m_y) ? m_x : m_y; \
// })

//1.typeof关键字用来获得变量的数据类型,
//2.宏定义的实现,用{}作为宏整体,里面是一个代码块,语句用";"隔开
//3.当宏的实现很长的时候,使用换行符 "\" 换到下一行
//4.使用输入数据的类型定义局部变量 m_x, m_y 实现对原始数据的保护
//5.宏实现不能使用 ";" 结尾

int min(int x, int y, int z)
{
    return x < y ? (x < z ? x : z) : (y > z ? z : y);
}
int findLucky(std::vector<int> &arr)
{
    std::vector<int> arr(501,0);

    for(const int &n : arr) {
        arr[n]++;
    }

    for(int i = 500; i > 0; i--) {
        if(arr[i] == i) return i;
    }

    return -1;
}

int findLucky(std::vector<int> &arr)
{
    sort(arr.rbegin(), arr.rend());

    int count = 1;
    for(int i = 0; i < arr.size() - 1; i++) {
        if(arr[i] == arr[i+1]) {
            count++;
        }
        else {
            if(count == arr[i]) return arr[i];
            count = 1;
        }
    }

    return arr.back() == count ? count : -1;
}

std::vector<int> luckyNumbers(std::vector<std::vector<int>> &matrix)
{
    std::vector<int> res;

    int m = matrix.size(), n = matrix[0].size();
    if(m == 0 || n == 0) return res;

    std::vector<int> rowMin(m, INT_MAX), colMax(n, INT_MIN);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            rowMin[i] = std::min(matrix[i][j], rowMin[i]);
            colMax[j] = std::max(matrix[i][j], colMax[j]);
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(rowMin[i] == colMax[j]) res.push_back(rowMin[i]);
        }
    }

    return res;
}


int main() {
    std::cout << MIN(1,2) << std::endl;
    // std::cout << MIN(1,2) << std::endl;
    // std::cout << min(10,2,3) << std::endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <memory>
#include <unordered_map>
#include <climits>
#include <unordered_set>
#include <queue>
#include <set>
#include <memory>
#include <sstream>
#include <thread>
#include <unistd.h>
#include <mutex>


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
    ~ListNode() {
        std::cout << "析构" << std::endl;
        delete next;
    }
};


void fun()
{
    std::cout << std::this_thread::get_id() << std::endl;
}


int main() {
    // ListNode *pNode = new ListNode(1);
    // delete pNode;

    // std::pair<int,std::string> anon = {};

    // if(anon.second.empty()) {
    //     std::cout << "fail" << std::endl;
    // } 

    // std::set<int> iset = {0,1,2,3,4,5};
    // std::set<int>::iterator set_it = iset.cbegin();

    // std::cout << *set_it << std::endl;

    // for(int i = 0; i < 10; i++) {
        std::thread t1(fun);
    // }

    t1.join();

    return 0;
}

void print_even(int x)
{
    if(x%2 == 0) {
        std::cout << x << " is even" << std::endl;
    }
    else {
        throw(std::logic_error("not even"));
    }
}

void print_id(int id)
{
    try {
        std::lock_guard<std::mutex> lock(mut);
        print_even(id);
    }
    catch (std::logic_error &) {
        std::cout << "except\n" << std::endl;
    }
}

int main() {
    std::thread threads[10];
    // std::vector<std::thread> threads(10);
    for(int i = 0; i < 10; i++) {
        threads[i] = std::thread(print_id, i + 1);
    }

    for(auto &th : threads) {
        th.join();
    }

    return 0;
}


std::mutex mut;
std::condition_variable cv;

int k = 0;

void print1()
{
    std::unique_lock<std::mutex> lock(mut);

    while(1)
    {
        while(k != 0) cv.wait(lock);

        printf("A\n");

        k = 1;

        sleep(1);

        cv.notify_all();
    }
}

void print2()
{
    std::unique_lock<std::mutex> lock(mut);

    while(1)
    {
        while(k != 1) cv.wait(lock);

        printf("B\n");

        k = 2;

        sleep(1);

        cv.notify_all();
    }
}

void print3()
{
    std::unique_lock<std::mutex> lock(mut);

    while(1)
    {
        while(k != 2) cv.wait(lock);

        printf("C\n");

        k = 0;

        sleep(1);

        cv.notify_all();
    }
}


int main() {
    std::thread t1(print1), t2(print2), t3(print3);

    t1.detach();
    t2.join();
    t3.join();

    return 0;
}

bool isPalindrome(ListNode *head)
{
    if(head->next == nullptr) return true;

    ListNode *fast = head, *slow = head;

    while(fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode *mid = slow->next;
    slow->next = nullptr;

    ListNode *head2 = reverse(mid);

    while(head && head2)
    {
        if(head->val != hea2->val) return false;

        head = head->next;
        head2 = head2->next;
    }

    return true;
}


ListNode *reverse(ListNode *head)
{
    ListNode *prev = nullptr;
    
    while(head) {
        ListNode *pNext = head->next;
        head->next = prev;
        prev = head;
        head = pNext;
    }

    return prev;
}


#include <iostream>
#include <thread>
#include <mutex>
#include <stdexcept>
#include <condition_variable>
#include <unistd.h>

const int size = 1000;

int data[size];

int head = 0;
int tail = 0;

void push(int n)
{
    if((tail + 1)%size == head) return;
    data[tail] = 0;
    tail = (tail+1)%size;
}

void pop()
{
    if(head == tail) return;

    head = (head + 1)%size;
}



int main() {


    return
}

std::vector<int> nums;
int size;
int head, tail;

MyCircularQueue(int k) {
    size = k + 1;
    nuns.resize(size);
    head = tail = 0;
}

bool isEmpty()
{
    if(head == tail) return true;
    return false;
}

bool isFull()
{
    if((tail+1)%size == head) return true;
    return false;
}

bool enQueue(int value)
{
    if(ifFull) return false;
    nums[tail] = value;
    tail = (tail + 1)%size;
    return true;
}

bool deQueue()
{
    if(isEmpty()) return false;
    head = (head + 1)%size;
    return true;
}

int front() {
    return nums[head];
}

int Rear() {
    int tmp = tail;
    return nums[--tmp];
}


int GetSteps(int k);

int main() {
    std::cout << GetSteps(5) << std::endl;

    return 0;
}

int GetSteps(int k)
{
    if(k <= 1) return 0;

    if(k&1) return 0;   //因为一来一回需要两次,所以k为奇数则不能到达原点

    int n = 10; //10个点

    std::vector<std::vector<int>> dp(k+1, std::vector<int>(n, 0));
    dp[0][0] = 1;

    for(int i = 1; i <= k; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = dp[i-1][(j-1+n)%n] + dp[i-1][(j+1)%n];
        }
    }

    return dp[k][0];
}


int heapAdjust(std::vector<int> &nums, int start, int end);

void heapSort(std::vector<int> &nums)
{
    int n = nums.size() - 1;

    for(int i = n/2; i >= 1; i--) {
        heapAdjust(nums, i, n);
    }

    for(int i = n; i > 1; i--) {
        std::swap(nums[1], nums[i]);
        heapAdjust(nums, 1, i-1);
    }

}

int heapAdjust(std::vector<int> &nums, int start, int end)
{
    int tmp = nums[start];

    for(int j = 2*start; j <= end; j *= 2)
    {
        if(j < end && nums[j] < nums[j+1]) j++;

        if(tmp > nums[j]) break;

        nums[start] = nums[j];

        start = j;
    }

    nums[start] = tmp;
}


// #define swap(x, y) ({typeof(x) tmp = x; x = y; y = tmp;})
// #define swap(x, y) ({ typeof(x) tmp = x; x = y; y = tmp; })



std::vector<std::vector<int>> path;

int minimumTota(std::vector<std::vector<int>> triangle)
{
    int m = triangle.size(), n = triangle[0].size();

    path = std::vector<std::vector<int>>(m, std::vector<int>(n));

    // std::vector<int> tmp = triangle[m-1];

    for(int i = m-2; i >= 0 ; i--) {
        for(int j = 0; j <= i; j++) {
            triangle[i][j] += std::max(triangle[i+1][j], triangle[i+1][j+1]);
            // tmp[j] = std::min(tmp[j], tmp[j+1]) + triangle[i][j];

            if(triangle[i+1][j] > triangle[i+1][j+1]) {
                path[i][j] = 1;
            }
            else {
                path[i][j] = 2;
            }

        }
    }

    return triangle[0][0];
}

void print(std::vector<std::vector<int>> triangle, int i, int j)
{
    if(i >= triangle.size()) return ;

    std::cout << triangle[i][j] << std::endl;

    if(path[i][j] == 1) {
        print(triangle, i+1, j);
    }
    else if(path[i][j] == 2) {
        print(triangle, i+1, j+1);
    }

}

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


void shellSort(std::vector<int> &nums)
{
    int gap = nums.size();

    while(gap >= 1)
    {
        gap = gap/3 + 1;

        for(int i = gap; i < nums.size(); i++)
        {
            if(nums[i] < nums[i-gap]) 
            {
                int tmp = nums[i];
                int j = i - gap;
                for(; nums[j] > tmp && j >= 0; j -= gap) {
                    nums[j+gap] = nums[j];
                }
                nums[j+gap] = tmp;
            }
        }
        break;
        if(gap == 1) break;     //避免死循环,当跨度等于1直接跳出
    }

}


class Singleton
{
private:
    Singleton() {}
    Singleton(const Singleton &);
    Singleton& operator=(const Singleton &);

    static Singleton* instance;

public:
    static Singleton* getInstance() {
        return instance;
    }

    void deleteInstance() {
        if(instance) delete instance;   //释放单实例
        instance = nullptr;
    }

};

Singleton* Singleton::instance = new(std::nothrow) Singleton;


int main() {

    // std::list<int> mylist = {1,-1,-1,0,-1,2};

    // for(auto it = mylist.begin(); it != mylist.end();)
    // {
    //     if(*it == -1) {
    //         it = mylist.erase(it);
    //     } else{
    //         it++;
    //     }
    // }

    // for(auto &n : mylist) {
    //     std::cout << n << " ";
    // }
    // std::cout << std::endl;

    // Singleton* demo = Singleton::getInstance();

    // printf("%d\n", demo);

    // std::vector<int> nums = {9,1,5,8,3,7,4,6,2};

    // shellSort(nums);

    // // heapSort(nums);

    // for(const int &n : nums) {
    //     std::cout << n << " ";
    // }
    // std::cout << std::endl;

    // int a = 1, b = 2;
    // swap(a,b);

    // std::cout << a << " " << b << std::endl;
    
    // std::vector<std::vector<int>> triangle = {{7}, {3,8}, {8,1,0}, {2,7,4,4}, {4,5,2,6,5}};

    // std::cout << minimumTota(triangle) << std::endl;

    // print(triangle, 0, 0);

    // std::vector<int> nums = {0,1,2,3,4,3};

    // // deleteEven(nums);
    // nums.erase(nums.begin(), nums.begin() + 1);

    // for(const int &n : nums) {
    //     std::cout << n << " ";
    // }
    // std::cout << std::endl;

    std::vector<int> nums = {1,2,3};

    nums.resize(nums.size(), 0);

    for(const int &n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}

class BitMap
{
private:
    std::vector<size_t> vec;

public:
    BitMap(size_t size) {           //size_t为无符号整形,不会存在负数.size为存储的元素总个数
        vec.resize(size/32 + 1);    //每个整形可以存储32个数,当size<32时,size/32=0,因此为了保证小于32的元素个数能存储,需要加1
    }

    //设置第x bit位为1
    bool set(size_t x) 
    {
        if(x/32 > vec.size()) {
            return false;
        }

        size_t index = x/32;        //找到是第几个数
        size_t num = x%32;          //找到是在vec[index]第几个bit位

        vec[index] |= (1 << num);
        return true;
    }

    bool reset(size_t x)    //将x的状态为置为0
    {
        if(x/32 > vec.size()) {
            return false;
        }

        size_t index = x/32;
        size_t num = x%32;

        vec[index] ^= (1 << num);
        return true;
    }

    int find(size_t x)  //查找x的状态并返回
    {
        if(x/32 > vec.size()) {
            return -1;
        }

        size_t index = x/32;
        size_t num = x%32;

        return (vec[index] >> num) & 1;
    }


    void clear()    //置空该位图
    {
        vec.clear();
    }

};


// class A
// {
// public:
//     int test() {
//         std::cout << "A" << std::endl;
//     }
// };

// class B : public A {
// public:
//     int test() {
//         std::cout << "B" << std::endl;
//     }
// };

class A {
public:
    A() { printf("A\n"); }
    virtual ~A() { printf("~A\n"); }
};

class B : public A {
public:
    B() { printf("B\n"); }
    ~B() { printf("~B\n"); }
};

class Base {
private:
    virtual void fun() { std::cout << "Base" << std::endl; }
    // friend int main();
};

class Derived : public Base {
public:
    void fun() { std::cout << "Derived" << std::endl; }
};



int main() {
    Base *ptr = new Base();
    ptr->fun();

    // A *c = new B();
    // delete c;

    // A *p = new B();
    // p->test();

    // BitMap map(30);

    // map.set(1);
    // map.set(10);
    // map.set(20);

    // map.reset(20);

    // std::cout << map.find(20) << std::endl;

    return 0;
}

class MyVector
{
private:
    int *data;
    int capacity;
    int size;

    void addsize(int newsize)
    {
        int newData = new int[newsize];
        for(int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;

        data = newData;
        capacity = newsize;
    }

public:
    MyVector() : data(nullptr), capacity(0), size(0) {}

    ~MyVector() {
        delete[] data;
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
            addsize(size*2);
        }
        data[size++] = val;
    }

    void pop_back() {
        if(size > 0) size--;
    }

    int& operator[](int i) {
        return data[i];
    }

};


class MyVector
{
private:
    int *data;
    int size;
    int capacity;

    void addsize(int newsize)
    {
        int *newData = new int[newsize];
        for(int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;

        data = newData;
        capacity = newsize;
    }

public:
    MyVector(): data(nullptr), capacity(0), size(0) {}

    ~MyVector() {
        delete[] data;
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
            addsize(size*2);
        }
        data[size++] = val;
    }

    void pop_back() {
        if(size > 0) size--;
    }

    int& operator[](int i) {
        return data[i];
    }

};


template<class T>
class shared_ptr
{
private:
    T *ptr;
    int *count;

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
        count = smartPtr.count;

        (*count)++;
    }

    shared_ptr& operator=(const shared_ptr &smartPtr)
    {
        if(ptr != smartPtr.ptr)
        {
            if(ptr != nullptr && --(*count) == 0) {
                delete ptr;
                delete count;
            }

            ptr = smartPtr.ptr;
            count = smartPtr.count;

            (*count)++;
        }

        return *this;
    }

    T& operator*() { return *ptr };

    T& operator->() { return ptr; }

    ~shared_ptr()
    {
        if(ptr == nullptr) delete count;
        else if(--(*count) == 0) {
            delete ptr;
            delete count;
        }
    }

    int use_count() { return *count; }
};


template<class T>
class weak_ptr
{
public:
    friend class shared_ptr<T>;

    T *ptr;
    int *count;

    weak_ptr() {
        ptr = nullptr;
        count = nullptr;
    }

    weak_ptr(const shared_ptr<T> smartPtr) {
        ptr = smartPtr.ptr;
    }

};


void insertSort(std::vector<int> &nums);

struct Node {
    int data;
    std::weak_ptr<Node> next;

    Node(int n) : data(n) {}

    ~Node() {
        std::cout << "~Node()" << std::endl;
    }
};

int main() {
    // std::shared_ptr<Node> p1(new Node(1));
    // std::shared_ptr<Node> p2(new Node(2));

    // p1->next = p2;
    // p2->next = p1;

    std::vector<int> nums = {0,4,3,2,1};

    insertSort(nums);

    for(const int &n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}

void insertSort(std::vector<int> &nums)
{
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] < nums[i-1]) {
            int tmp = nums[i];
            int j = i-1;
            for(; j >=0 && nums[j] > tmp; j--) {
                nums[j+1] = nums[j];
            }
            nums[j+1] = tmp;
        }
    }

}



class String
{
private:
    char *str;

public:
    String(const char *s = NULL)
    {
        if(s == NULL) {
            str = new char[1];
            *str = '\0';
        }
        else {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
    }

    String(const String &demo) 
    {
        str = new char[strlen(demo.str) + 1];
        strcpy(str, demo.str);
    }

    String& operator=(const String &demo)
    {
        if(this == &demo) return *this;

        delete[] str;

        str = new char[strlen(demo.str) + 1];
        strcpy(str, demo.str);

        return *this;
    }

    String operator+(const String &demo) const
    {
        char *sp = new char[strlen(demo.str) + strlen(str) + 1];
        strcpy(sp, str);
        strcat(sp, demo.str);

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


void func_int(void *a) 
{
    printf("%d\n", *(int*)a);
}


void func_double(void *b)
{
    printf("%f\n", *(double*)b);
}

typedef void (*ptr)(void*);

void c_func(ptr p, void *arg)
{
    p(arg);
}


typedef void(*func)();      //定义一个函数指针来实现对成员函数的继承

//父类
struct A {      
    func fun;   //由于C语言结构体中不能包含函数，故只能用函数指针在类外实现
};

//子类
struct B {
    A m_a;     //子类中定义一个基类的对象来实现对父类的继承
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

    p2 = (A*)&b;    //让父类指针指向父类的对象，由于类型不匹配需要强制转换
    p2->fun();
}

    // int a = 23;
    // double b = 23.23;

    // c_func(func_int, &a);
    // c_func(func_double, &b);

    // String str1("hello"), str2("world");

    // String str3 = str1 + str2;

    // str3.print();

    // char str1[] = "hello", str2[] = "world";

    // std::cout << str3 << std::endl;

    return 0;
}

std::string multiplyTwoNumber(std::string num1, std::string num2)
{
    int m = num1.size(), n = num2.size();

    std::string res(m + n, '0');

    for(int i = m-1; i >= 0; i--) {
        for(int j = n-1; j >= 0; j--) {
            int prod = (num1[i]-'0')*(num2[j]-'0') + res[i+j+1];
            res[i+j+1] = prod%10 + '0';
            res[i+j] += prod/10;
        }
    }

    for(int i = 0; i < res.size(); i++) {
        if(res[i] != '0') return res.substr(i);
    }

    return "0";
}


*

class A {
public:
    A() {
        std::cout << "A" << std::endl;
    }
    void print() {
        std::cout << "hello" << std::endl;
    }
};

class C {
public:
    C() {
        std::cout << "C" << std::endl;
    }
};

class B : public A {
    C c;
public:
    B() : c(){
        std::cout << "B" << std::endl;
    }
};




// class B : virtual public A {};
// class C : virtual public A {};

// class D : public B, public C {};


int main() {

    B b;

    // D d;
    // d.print();
    // d.B::print();
    // d.C::print();

    return 0;
}

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
            std::cout << s1[i] << std::endl;
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


int rand4() 
{    
    return rand()%5;
}

int rand6() 
{
    int n = rand4()*5 + rand4();

    while(n > 20) {
        n = rand4()*5 + rand4();
    }

    return n%7;
}


int rand5() {
    srand(time(0));
    return rand()%5 + 1;
}

int rand7() {
    int n = (rand5()-1)*5 + rand5();

    while(n > 21) {
        n = (rand5()-1)*5 + rand5();
    }

    return n%7 + 1;
}


void shuffle(std::vector<int> &nums)
{
    for(int i = nums.size() - 1; i >= 0; i--)
    {
        int j = rand()%(i+1);
        std::swap(nums[i], nums[j]);
    }

}


void merge(std::vector<int> &nums, int left, int right, int mid);

void mergeSort(std::vector<int> &nums, int left, int right)
{
    if(left < right)
    {
        int mid = left + ((right - left) >> 1);
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, right, mid);
    }

}

void merge(std::vector<int> &nums, int left, int right, int mid)
{
    int lindex = left, rindex = mid + 1;
    int *team = new int[right-left+1];
    int index = 0;

    while(lindex <= mid && rindex <= right)
    {
        if(nums[lindex] < nums[rindex]) {
            team[index++] = nums[lindex++];
        }
        else {
            team[index++] = nums[rindex++];
        }
    }

    while(lindex <= mid) {
        team[index++] = nums[lindex++];
    }

    while(rindex <= right) {
        team[index++] = nums[rindex++];
    }

    for(int i = 0; i < index; i++) {
        nums[left+i] = team[i];
    }

    delete[] team;
}

int main() {

    std::vector<int> nums = {50,10,90,30};

    mergeSort(nums, 0, nums.size() - 1);

    for(const int &n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // std::cout << rand7() << std::endl;
    // std::thread t1(print1), t2(print2);
    // t1.join();
    // t2.join();

    return 0;
}


int reversePairs(std::vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}

int mergeSort(std::vector<int> &nums, int left, int right)
{
    if(left >= right) return 0;

    int mid = left + ((right - left) >> 1);

    int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);

    std::vector<int> tmp(right - left + 1);
    int index = 0;

    int lindex = left, rindex = mid + 1;

    while(lindex <= mid && rindex <= right)
    {
        if(nums[lindex] <= nums[rindex]) {
            count += rindex - (mid + 1);
            tmp[index++] = nums[lindex++];
        }
        else {
            tmp[index++] = nums[rindex++];
        }
    }

    while(lindex <= mid) {
        count += rindex - (mid + 1);
        tmp[index++] = nums[lindex++];
    }

    while(rindex <= right) {
        tmp[index++] = nums[rindex++];
    }
 
    for(int i = 0; i < index; i++) {
        nums[left+i] = tmp[i];
    }

    return count;
}



void subtractOne(std::string &str);

int main() {
    std::string str;
    std::cin >> str;

    if(str == "0") {
        std::cout << "-1" << std::endl;
        return 0;
    }
    else if(str == "1") {
        std::cout << "0" << std::endl;
        return 0;
    }

    subtractOne(str);

    for(int i = 0; i < str.size(); i++) {
        if(str[i] != '0') {
            std::cout << str.substr(i) << std::endl;
            break;
        }
    }

    return 0;
}

void subtractOne(std::string &str)
{
    int n = str.size();
    if(str[n-1] == '0') {
        int i = n-1;
        while(str[i] == '0') i--;
        str[i]--;
        for(int j = i + 1; j < str.size(); j++) str[j] = '9';
    }
    else {
        str[n-1]--;
    }

}


bool bigger(const std::string &num1, const std::string &num2)
{
    if(num1.size() != num2.size()) return num1.size() > num2.size();

    for(int i = 0; i < num1.size(); i++) {
        if(num1[i] != num2[i]) return num1[i] > num2[i];
    }

    //这里返回true或者false都可以,这一句永远不会被执行
    return false;
}

std::string subTwoNumber(std::string num1, std::string num2)
{
    if(num1 == num2) return "0";

    //让num1始终比num2大,这样方便处理借位
    bool positive = bigger(num1, num2);

    if(!positive) {
        std::swap(num1, num2);
    }

    //将num2的长度补齐到和num1一样
    while(num1.size() > num2.size()) {
        num2 = "0" + num2;
    }

    for(int i = num1.size() -1; i >= 0; i--)
    {
        //不足就向上一位借位
        if(num1[i] < num2[i] && i > 0) {
            num1[i-1]--;
            num1[i] += 10;
        }

        num1[i] -= (num2[i] - '0');
    }

    std::string res = num1;

    if(res[0] == '0') res = res.substr(1);  //去掉开头的0,比如 "100" - "1" = "099"

    if(!positive) res = "-" + res;

    return res;
}


int main() {
    std::string num1 = "100", num2 = "10";

    std::cout << subTwoNumber(num1, num2) << std::endl;

    return 0;
}


//C语言实现函数重载

void func_int(void *a)
{
    printf("%d\n", *(int*)a);
}

void func_double(void *a)
{
    printf("%f\n", *(double*)a);
}

typedef void (*ptr)(void *);

void c_func(ptr p, void *arg)
{
    p(arg);
}


/*
int main() {
    int a = 23;
    double b = 23.23;

    c_func(func_int, &a);
    c_func(func_double, &b);

    return 0;
}


typedef void(*func)();

struct A {
    func fun;
};

struct B {
    struct A m_a;
};


void fA() {
    printf("A::\n");
}

void fB() {
    printf("B::\n");
}


// typedef void (*p)();

const char* getString(char *ptr)
{
    return ptr;
}



// int main() {
//     char str[] = "abc";
//     const char *ptr = getString(str);
//     // std::cout << *ptr << std::endl;
//     printf("%s\n", ptr);
//     // void (*ptr)();
//     // ptr = fA;
//     // (*ptr)();

//     // p fun;
//     // fun = fA;
//     // fun();

//     // A a;
//     // B b;

//     // a.fun = fA;
//     // b.m_a.fun = fB;

//     // A *p = &a;
//     // p->fun();

//     // p = (A*)&b;
//     // p->fun();

//     return 0;
// }


void* memcpy(void *des, const void *src, size_t size)
{
    char *pDes = NULL, *pSrc = NULL;

    if(src < des && (char*)src + size > (char*)des) 
    {
        pDes = (char*)des + size - 1;
        pSrc = (char*)src + size - 1;
        while(size--) {
            *pDes-- = *pSrc--;
        }
    }
    else    //不存在内存重叠
    {
        pDes = (char*)des;
        pSrc = (char*)src;
        while(size--) {
            *pDes++ = *pSrc++;
        }
    }

    return des;
}


void strcpy(char *des, char *src)
{
    if(des == nullptr || src == nullptr) return;

    char *pDes = des, *pSrc = src;

    while((*pDes++ = *pSrc++) != '\0');

    // return des;
}


#include <iostream>
#include <thread>
#include <condition_variable>
#include <unistd.h>
#include <vector>
#include <map>
#include <algorithm>

class A {
public:
    int data;
    A() : data(100) {}
    void print() { std::cout << data << std::endl; }
};

class B : public A {
public:
    int val;
    B(): val(200) {}
    void print() { std::cout << val << std::endl; }
};

void print(int (&arr)[5]) {
    for(auto n : arr)
        std::cout << n << " ";
}

template<class T>
int compare(const T&, const T&) {
    return 0;
}


int main() {

    
    // long lng;
    // // compare(lng,1024);

    // compare<int>(lng, 1024);

    // compare("bye", "dats");

    // int i = 10;
    // int j[] = {1,2,3,4,5};

    // print(&i);

    // std::map<int,int> hash = {{1,1}, {2,2}, {3,3}, {4,4}, {5,5}};

    // std::vector<int> hash = {1,2,3,4,5};

    // for(auto it = hash.begin(); it != hash.end();)
    // {
    //     if(*it & 1) hash.erase(it++);
    //     else it++;
     

    // for(std::pair<const int, int> &item : hash) {
    //     std::cout << item.first << " " << item.second << " ";
    // }
    // std::cout << std::endl;

    // remove_if(hash.begin(), hash.end(), [](auto item){return !(item.second&1);});

    // hash.erase(remove_if(hash.begin(), hash.end(), [](std::pair<const int,int> &item){ return !(item.first&1); }), hash.end());

    // A *p = new A();

    // B *ptr = static_cast<B*>(p);

    // ptr->print();

    // char str1[10];
    // const char str2[] = "abc";

    // char *ptr = str2;

    // int n = 5;
    // const int * ptr = &n;
    // // const int *ptr = &n;
    // int *p = ptr;
    // ptr = new int(4);

    // strcpy(str1, str2);

    // printf("%s\n", str1);

    return 0;
}


// #include <stdio.h>  
// #include <time.h>  
// #include <stdlib.h>

template<class T>
bool isPtr(T *p)
{
    return true;
}

bool isPtr(...)
{
    return false;
}

class Test {
public:
    Test() {}
    virtual ~Test(){}
};

int main() {  
    // Test *p = new Test();
    // // Test p;

    // int i = 0;

    Test t;
    // Test *pt = &t;

    std::cout << isPtr(t) << std::endl;


    return 0;  
}  


int strcmp(const char *str1, const char *str2)
{
    int res = 0;

    while(!(res = *(unsigned char*)str1 - *(unsigned char*)str2) && *str1++ && *str2++);

    if(res > 0) return 1;
    else if(res < 0) return -1;

    return 0;
}


struct MyStruct {
    int a;
};

class Test1 {
    MyStruct struct1;
};

class Test2 {
    MyStruct *str;
};


void func(std::string &str, const std::string &from, const std::string &to)
{
    size_t pos = 0;
    while((pos = str.find(from, pos)) != std::string::npos) {
        str.replace(pos, from.size(), to);
        pos += to.size();
    }
}

const int max = 100;

std::string to_string(int n)
{
    int m = n;
    char s[max], ss[max];
    int i = 0, j = 0;

    if(n < 0) {
        m = -n;
        ss[j++] = '-';
    }

    while(m > 0) {
        s[i++] = m%10 + '0';
        m /= 10;
    }

    i--;
    while(i >= 0) {
        ss[j++] = s[i--];
    }

    ss[j] = '\0';

    return ss;
}


template<size_t M, size_t N>
int compare(const char(&)[N], const char(&)[M]) {}

template<class T>
int compare(const T & a, const T &b)
{
    return a < b;
}


template<typename T, typename ... Args>
void foo(const T&, const Args& ... args) {
    std::cout << sizeof ... (Args) << std::endl;
    std::cout << sizeof ... (args) << std::endl;
}


int main() {
    std::vector<int> nums = {1,2,3};

    if(auto it = find(nums.begin(), nums.end(), 3); it != nums.end())) *it = 4;

    


    // int i = 0;
    // double d = 3.14;
    // std::string s = "how";

    // foo(i, s, 42, d);

    // const char *p1 = "hi", *p2 = "mom";
    // std::cout << compare("hi", "mom") << std::endl;

    // std::vector<int> nums = {1,2,3};
    // nums.resize(4);

    // for(const int &n : nums) {
    //     std::cout << n << " ";
    // }
    // std::cout << std::endl;

    // std::cout << to_string(-289) << std::endl;

    // std::string str = "helloworldllo";
    // std::string from = "llo", to = "abc";

    // func(str, from, to);

    // std::cout << str << std::endl;

    // std::map<std::pair<int,int>, int >mp;

    // mp[{1,1}]++;

    // std::string str = "dsdhelloew", from = "hello", to = "world";

    // func(str, from, to);

    // std::cout << str << std::endl;

    // std::cout << sizeof(Test1) << std::endl;
    // std::cout << sizeof(Test2) << std::endl;
    // char str1[] = "", str2[] = "a";

    // std::cout << strcmp(str1, str2) << std::endl;

    return 0;
}

int findMaxLength(std::string &str);
int findMaxGuests(std::vector<int> &start, std::vector<int> &end);
int findMaxLength(std::vector<int> &nums, int target);

int main() {
    // std::vector<int> nums = {3,4,1,7,8};
    // int target = 15;
    // std::cout << findMaxLength(nums, target) << std::endl;

    std::string str = "01001001";

    std::cout << findMaxLength(str) << std::endl;

    return 0;
}

int findMaxGuests(std::vector<int> &start, std::vector<int> &end)
{
    if(start.size() != end.size()) return -1;

    int n = start.size();

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i = 0, j = 0;
    int count = 0, res = 0;

    while(i < n && j < n)
    {
        if(start[i] <= end[j]) {
            res = std::max(res, ++count);
            i++;
        }
        else {
            count--;
            j++;
        }
    }

    return res;
}


int findMaxLength(std::vector<int> &nums, int target)
{
    std::unordered_map<int,int> hash;
    hash[0] = -1;

    int n = nums.size();
    int res = 0;
    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += nums[i];
        if(hash.count(sum-target)) res = std::max(res, i - hash[sum-target]);
        hash[sum] = i;
    } 

    return res == 0 ? -1 : res;
}

int findMaxLength(std::string &str)
{
    std::unordered_map<int,int> hash;
    hash[0] = -1;

    int n = str.size();
    int res = 0;
    int sum = 0;

    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '0') sum += -1;
        else if(str[i] == '1') sum += 1;

        if(hash.count(sum)) res = std::max(res, i - hash[sum]);
        else hash[sum] = i;
    }

    return res;
}

class String
{
private:
    char *str;
    size_t len;

public:
    String(const char *s = NULL) 
    {
        if(s == NULL) {
            str = new char[1];
            *str = '\0';
            len = 0;
        }
        else {
            len = strlen(s);
            str = new char[len+1];
            strcpy(str, s);
        }
    }

    //构造函数(深拷贝)
    String(const String &demo)
    {
        len = demo.len;
        str = new char[len+1];
        strcpy(str, demo.str);
    }

    String& operator=(const String &demo)
    {
        if(this == &demo) return *this;

        delete[] str;

        len = demo.len;
        str = new char[len+1];
        strcpy(str, demo.str);

        return *this;
    }

    String operator+(const String &demo) const
    {
        int len = strlen(str) + strlen(demo.str) + 1;
        char *sp = new char[len];
        strcpy(sp, str);
        strcate(sp, demo.str);
        
        String tmp(sp);
        return tmp;
    }

    ~String() {
        delete[] str;
    }

};


void print1()
{
    std::unique_lock<std::mutex> lock(mut);

    while(1)
    {
        while(k != 1) {
            cv.wait(lock);
        }

        printf("A\n");
        sleep(1);

        k = 2;
        cv.notify_all();
    }

}

void print2()
{
    std::unique_lock<std::mutex> lock(mut);

    while(1)
    {
        while(k != 2) {
            cv.wait(lock);
        }

        printf("B\n");
        sleep(1);

        k = 3;
        cv.notify_all();
    }

}

void print3()
{
    std::unique_lock<std::mutex> lock(mut);

    while(1)
    {
        while(k != 3) {
            cv.wait(lock);
        }

        printf("C\n");
        sleep(1);

        k = 1;
        cv.notify_all();
    }

}



#include <unistd.h>
// #include <iostream>
// #include <map>
// #include <vector>
// #include <algorithm>
// #include <unordered_map>

int k = 1;

std::condition_variable cv;
std::mutex mut;

std::string s1 = "1234", s2 = "abcd";

void print1()
{
    std::unique_lock<std::mutex> lock(mut);

    while(1)
    {
        for(int i = 0; i < s1.size(); i++)
        {
            while(k != 1) cv.wait(lock);

            printf("%c\n", s1[i]);
            // std::cout << s1[i] << std::endl;

            k = 2;
            sleep(1);

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
            while(k != 2) cv.wait(lock);

            printf("%c\n", s2[i]);
            // std::cout << s2[i] << std::endl;

            k = 1;
            sleep(1);

            cv.notify_all();
        }
    }
    
}


int main() {
    // std::thread t1(print1), t2(print2);

    // t1.join();
    // t2.join();

    std::vector<int> nums = {0,1,2,3,4,5};

    nums.erase(remove_if(nums.begin(), nums.end(), [](int x){ return x&1; }), nums.end());

    for(auto &n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}


/*
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
            std::cout << s1[i] << std::endl;
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


struct Node {
    int data;
    std::weak_ptr<Node> next;

    Node(int n): data(n) {}
    ~Node() {
        std::cout << "~Node()" << std::endl;
    }
};



class Base {
public:
    Base(): d(2) {}
    virtual void print() {
        std::cout << d << std::endl;
    }
    int d;
};

class Son : public Base {
public:
    Son() : d(20) {}
    void print() {
        std::cout << d << std::endl;
    }
    int d;
};

int main() {
    // Son *ptr = new Son();
    // Base *p = dynamic_cast<Base*>(ptr);

    // p->print();

    Base *p = new Son();
    Son *ptr = dynamic_cast<Son*>(p);

    ptr->print();

    return 0;
}


/*
    实现一个栈
    支持三个操作:top取栈顶元素,pop弹出元素,max取栈中最大元素
*/
/*

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


int main() {
    myStack sta(10);
    sta.push(1);
    sta.push(3);
    sta.push(1);

    while(!sta.isEmpty())
    {
        std::cout << sta.max() << std::endl;
        sta.pop();
    }

    // std::cout << sta.topNum() << std::endl;

    return 0;
}




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
        nums[tail++] = x;
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

    int len()
    {
        return (tail-pre+size)%size;
    }

};


int main() {
    myQueue que(4);
    que.push(1);
    que.push(2);
    que.push(3);

    while(!que.empty()) {
        std::cout << que.front() << std::endl;
        que.pop();
    }

    return 0;
}



class Singleton
{
private:
    Singleton() {}
    Singleton(Singleton const &);
    Singleton& operator=(Singleton const &);

public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

};

class Singleton
{
private:
    Singleton() {}
    Singleton(const Singleton &);
    Singleton& operator=(Singleton const &);

public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
};


class Singleton
{
private:
    Singleton() {}
    Singleton(const Singleton &);
    Singleton& operator=(const Singleton &);
    static Singleton *instance;
    static std::mutex mut;

public:
    static Singleton* &getInstance() 
    {
        if(instance == nullptr) 
        {
            std::unique_lock<std::mutex> lock(mut);
            if(instance == nullptr) {
                instance = new(std::nothrow) Singleton();
            }
        }

        return instance; 
    }

};

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mut;
*/

/*
#include <bits/stdc++.h>
// #include <iostream>

// #define min(a,b) ((a) < (b) ? (a) : (b))

// #define swap(x, y) ({\
//     typeof(x) tmp = x;\
//     x = y;\
//     y = tmp;\
// })

#define MIN(a, b) ({\
    typeof(a) x = a;\
    typeof(b) y = b;\
    x < y ? x : y;\
})


class Base 
{
public:
    void print() {
        std::cout << "base" << std::endl;
    }
};

class Derived : public Base {
public:
    void print() {
        std::cout << "Derived" << std::endl;
    }
};

/*
class A
{
public:
    A(){}
    void destory() {
        delete this;
    }

private:
    ~A(){
        std::cout << "~A" << std::endl;
    }

};
*/
/*
class A
{
protected:
    A() { std::cout << "A" << std::endl; }
    ~A() { std::cout << "~A" << std::endl; }

public:
    static A* create() {
        return new A();
    }    

    void destory() {
        delete this;
    }

};
*/

/*
class B {
public:
    virtual void funB(){};
    int b;
};

class C {
public:
    virtual void func(){};
    int c;
};

class A : public B, public C {
public:
    virtual void funcA(){};
    int a;
};

void test(C *pc) {
    pc->c = 9;
}
*/

/*
class A {
public:
    virtual void print() {}
};

class B : public A {
public:
    virtual void print() {}
};

class C : public A {
public:
    virtual void print(){}
};


class D : public B, public C {
public:
    virtual void print() {}
};


int findNum(std::vector<int> &nums, int left, int right, int target)
{
    if(left > right) return -1;

    int mid = left + ((right-left) >> 1);
    if(nums[mid] < target) {
        return findNum(nums, mid + 1, right, target);
    }
    else if(nums[mid] > target) {
        return findNum(nums, left, mid - 1, target);
    }

    return mid;
}


void insertSort(std::vector<int> &nums)
{
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] < nums[i-1]) {
            int tmp = nums[i];
            int j = i-1;
            for(; j >= 0 && nums[j] >= tmp; j--) {
                nums[j+1] = nums[j];
            }
            nums[j+1] = tmp;
        }
    }

}


void shellSort(std::vector<int> &nums)
{
    int gap = nums.size();

    do {
        gap = gap/3 + 1;

        for(int i = gap; i < nums.size(); i++) {
            if(nums[i] < nums[i-gap]) {
                int tmp = nums[i];
                int j = i-gap;
                for(; j >= 0 && nums[j] > tmp; j -= gap) {
                    nums[j+gap] = nums[j];
                }
                nums[j+gap] = tmp;
            }
        }
    } while(gap != 1);

}

void heapAdjust(std::vector<int> &nums, int start, int end);

void heapSort(std::vector<int> &nums)
{
    int n = nums.size() - 1;

    for(int i = n/2; i >= 1; i--) {
        heapAdjust(nums, i, n);
    }

    for(int i = n; i > 1; i--)
    {
        std::swap(nums[i], nums[1]);
        heapAdjust(nums, 1, i-1);
    }

}


void heapAdjust(std::vector<int> &nums, int start, int end)
{
    int tmp = nums[start];

    for(int j = 2*start; j <= end; j *= 2)
    {
        if(j < end && nums[j] < nums[j+1]) j++;

        if(tmp > nums[j]) break;

        nums[start] = nums[j];

        start = j;
    }

    nums[start] = tmp;
}




int main() {
    std::vector<int> nums = {-1, 1,3, 2, 4, 6, 5};
    heapSort(nums);

    for(const int &n : nums) std::cout << n << " ";
    std::cout << std::endl;

    // std::cout << findNum(nums, 0, 4, 5) << std::endl;

    // std::cout << sizeof(D) << std::endl;
    // A *pA = new A();
    // C *pC = (C*)pA;

    // test(pC);

    // std::cout << pC->c << std::endl;

    // A *ptr = A::create();
    // ptr->destory();

    // A *p = new A();
    // p->destory();
    // delete p;

    // Derived *p = new Derived();
    // Base *ptr = static_cast<Base*>(p);

    // ptr->print();

    // p->print();

    // std::cout << min(1,2) << std::endl;    
    // int a = 1;
    // float b = 2.2;
    // swap(a, b);
    // std::cout << a << " " << b << std::endl;
    // std::cout << MIN(1, 2) << std::endl; 

    return 0;
}
*/



/*
class MyVector
{
private:
    int *data;
    int capacity;
    int size;

    void addsize(int newsize)
    {
        int *newData = new int[newsize];
        for(int i = 0; i < size; i++) newData[i] = data[i];
        delete[] data;

        data = newData;
        capacity = newsize;
    }

public:
    MyVector() : data(nullptr), capacity(0), size(0) {}

    ~MyVector() {
        delete[] data;
    }

    MyVector(int m_size, int val = 0)
    {
        data = new int[m_size];
        memset(data, val, sizeof(data));
        capacity = m_size;
        size = m_size;
    }

    void push_back(int val)
    {
        if(capacity == size) {
            addsize(2*size);
        }

        data[size++] = val;
    }

    void pop_back() {
        if(size > 0) size--;
    }

    int getsize() {
        return size;
    }

    int& operator[](int i) {
        return data[i];
    }
};

int main() {
    MyVector nums;

    // nums[0] = 1, nums[1] = 2, nums[2] = 3;

    // nums.push_back(4);

    int size = nums.getsize();

    std::cout << size << std::endl;

    // for(int i = 0; i < size; i++) {
    //     std::cout << nums[i] << " ";
    // }
    // std::cout << std::endl;


    return 0;
}



template<class T>
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
    MyVector(): data(nullptr), capacity(0), size(0) {}

    MyVector(int m_size, T val = 0)
    {
        data = new T[m_size];
        // memset(data, val, sizeof(data));
        for(int i = 0; i < m_size; i++) data[i] = val;

        capacity = m_size;
        size = m_size;
    }

    MyVector(const MyVector &demo)
    {
        size = demo.size;
        capacity = size;
        data = new T[size];
        for(int i = 0; i < size; i++) data[i] = demo.data[i];
    }

    void push_back(int val)
    {
        if(capacity == size) {
            addsize(2*size);
        }
        data[size++] = val;
    }

    void pop_back() {
        if(size > 0) size--;
    }

    int getsize() {
        return size;
    }

    T& operator[](int i) {
        return data[i];
    }
};


int main() {
    MyVector<int> nums(3, 3);

    MyVector<int> nums2(nums);

    int size = nums2.getsize();
    for(int i = 0; i < size; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}


class String
{
private:
    char *str;
    size_t len;

public:
    String(const char *s = NULL)
    {
        if(s == NULL) {
            str = new char[1];
            *str = '\0';
            len = 0;
        }
        else {
            len = strlen(s);
            str = new char[len+1];
            strcpy(str, s);
        }
    }

    String(const String &demo)
    {
        len = demo.len;
        str = new char[len+1];
        strcpy(str, demo.str);
    }

    String& operator=(const String &demo)
    {
        if(this == demo) return *this;

        delete[] str;

        len = demo.len;
        str = new char[len+1];
        strcpy(str, demo.str);

        return *this;
    }

    String operator+(const String &demo) const 
    {
        int len = strlen(str) + strlen(demo.str) + 1;
        char *sp = new char[len];
        strcpy(sp, str);
        strcat(sp, demo.str);
        String tmp(sp);
        return tmp;
    }

    ~String() {
        delete[] str;
    }

};

#define MIN(a, b) ({\
    typeof(a) m_a = (a);\
    typeof(b) m_b = (b);\
    (m_x < m_y) ? m_a : m_b\
})

*/
// #include <iostream>
// #include <string.h>


//单例模式:懒汉式(返回全局对象的单例模式)

/*
class Singleton
{
private:
    Singleton() {}
    Singleton(const Singleton &);
    Singleton& operator=(const Singleton &);

public:
    static Singleton& getInstance() {
        static Singleton demo;
        return demo;
    }

    void print() {
        std::cout << "hello" << std::endl;
    }
};
*/

/*
class Singleton
{
private:
    Singleton() {}
    Singleton(const Singleton &);
    Singleton& operator=(const Singleton &);
    static Singleton *instance;
    static std::mutex mut;

public:
    static Singleton* &getInstance() {
        if(instance == nullptr) 
        {
            std::unique_lock<std::mutex> lock(mut);
            if(instance == nullptr) {
                instance = new(std::nothrow) Singleton();
            }
        }

        return instance;
    }

    void fun() {
        std::cout << "hello" << std::endl;
    }

};

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mut;


int main() {
    // Singleton &demo = Singleton::getInstance();
    // demo.print();
    Singleton* &ptr = Singleton::getInstance();
    ptr->fun();

    return 0;
}
*/

/*
#include <bits/stdc++.h>
#include <mutex>

// #define swap(x,y) ({\
//     x = x^y;\
//     y = x^y;\
//     x = x^y;\
// })

// #define swap(x,y) ({\
//     x = x + y; \
//     y = x - y;\
//     x = x - y;\
// })

#define swap(x, y) ({\
    typeof(x) tmp = x;\
    x = y;\
    y = tmp;\
})



int main() {
    int a = 1, b = 2;

    swap(a, b);

    std::cout << a << " " << b << std::endl;

    return 0;
}


void heapAdjust(std::vector<int> &nums, int start, int end);
void heapSort(std::vector<int> &nums);

void mergeSort(std::vector<int> &nums, int left, int right);
void merge(std::vector<int> &nums, int left, int mid, int right);

void quickSort(std::vector<int> &nums, int left, int right);
int partition(std::vector<int> &nums, int left, int right);

int main() {
    std::vector<int> nums = {-1,9,1,5,8,3,7,4,6,2};

    // heapSort(nums);
    quickSort(nums, 0, nums.size() - 1);

    for(const int &n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}

void heapSort(std::vector<int> &nums)
{
    int n = nums.size() - 1;

    for(int i = n/2; i >= 1; i--) {
        heapAdjust(nums, i, n);
    }

    for(int i = n; i > 1; i--)
    {
        std::swap(nums[1], nums[i]);
        heapAdjust(nums, 1, i-1);
    }

}

void heapAdjust(std::vector<int> &nums, int start, int end)
{
    int tmp = nums[start];

    for(int j = 2*start; j <= end; j *= 2)
    {
        if(j < end && nums[j] < nums[j+1]) j++;

        if(tmp > nums[j]) break;

        nums[start] = nums[j];

        start = j;
    }

    nums[start] = tmp;
}


void mergeSort(std::vector<int> &nums, int left, int right)
{
    if(left < right)
    {
        int mid = left + ((right - left) >> 1);
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

}

void merge(std::vector<int> &nums, int left, int mid, int right)
{
    int lindex = left, rindex = mid + 1;
    int *team = new int[right-left+1];
    int index = 0;

    while(lindex <= mid && rindex <= right)
    {
        if(nums[lindex] < nums[rindex]) {
            team[index++] = nums[lindex++];
        }
        else team[index++] = nums[rindex++];

    }

    while(lindex <= mid) team[index++] = nums[lindex++];

    while(rindex <= right) team[index++] = nums[rindex++];

    for(int i = 0; i < index; i++) {
        nums[left+i] = team[i];
    }

    delete[] team;
}


void quickSort(std::vector<int> &nums, int left, int right)
{
    if(left < right)
    {
        int mid = partition(nums, left, right);
        quickSort(nums, left, mid);
        quickSort(nums, mid + 1, right);
    }

}

int partition(std::vector<int> &nums, int left, int right)
{
    int pivot = nums[left];

    while(left < right)
    {
        while(left < right && nums[right] >= pivot) right--;
        std::swap(nums[left], nums[right]);

        while(left < right && nums[left] <= pivot) left++;
        std::swap(nums[left], nums[right]);
    }

    return left;
}

std::vector<int> findSubstring(std::string s, std::vector<std::string> &words)
{
    std::vector<int> res;

    if(s.empty() || words.empty()) return res;

    std::unordered_map<std::string, int> mp;
    for(auto &word : words) mp[word]++;

    int n = s.size(), num = words.size(), length = words[0].size();
    if(n < num*length) return res;

    for(int i = 0; i < length; i++)
    {
        int j = i;
        while(j <= n-num*length)
        {
            int count = num;
            std::unordered_map<std::string, int> seen;
            while(count > 0) {
                std::string word = s.substr(j + (count-1)*length, length);
                seen[word]++;
                if(!mp.count(word) || seen[word] > mp[word]) break;
                count--;
            }
            if(count == 0) res.push_back(j);
            j += std::max(1, count)*length;
        }

    }

    return res;
}


std::vector<int> findSubstring(std::string s, std::vector<std::string> &words)
{
    std::vector<int> res;

    if(s.empty() || words.empty()) return res;

    std::unordered_map<std::string, int> mp;
    for(auto &word : words) mp[word]++;

    int n = s.size(), num = words.size(), length = words[0].size();
    if(n < length*num) return res;

    for(int i = 0; i < length; i++)
    {
        int j = i;
        while(j <= n-num*length)
        {
            int count = 0;      //统计以j开头的合格单词个数
            std::unordered_map<std::string, int> seen;
            while(count < num)
            {
                std::string word = s.substr(j + count*length, length);
                seen[word]++;
                if(!mp.count(word) || seen[word] > mp[word]) break;     //如果以j开头的这个字符不在words中,或者出现次数大于words中单词出现次数,则跳出
                count++;
            }

            if(count == num)  res.push_back(j);     //说明j是一个合格的位置
            j += std::max(1, count) * length;       //细节,这里一定要取 max(1,count)
        }
    }

    return res;
}

std::vector<int> findSubstring(std::string s, std::vector<std::string> &words)
{
    std::vector<int> res;

    if(s.empty() || words.empty()) return res;

    std::unordered_map<std::string, int> mp;
    for(auto &word : words) mp[word]++;

    int n = s.size(), num = words.size(), length = words[0].size();

    for(int i = 0; i <= n - num*length; i++)
    {
        std::unordered_map<std::string, int> seen;
        int count = 0;
        while(count < num)
        {
            std::string word = s.substr(i + count*length, length);
            seen[word]++;
            if(!mp.count(word) || seen[word] > mp[word]) break;
            count++;
        }

        if(count == num) res.push_back(i);
    }

    return res;
}

class BitMap {
private:
    std::vector<size_t> vec;

public:
    BitMap(size_t size) {
        vec.resize(size/32 + 1);
    }

    bool set(size_t x) 
    {
        if(x/32 > vec.size()) {
            return false;
        }

        size_t index = x/32;
        size_t num = x%32;

        vec[index] |= (1 << num);

        return true;
    }

    int find(size_t x)
    {
        if(x/32 > vec.size()) return -1;

        size_t index = x/32;
        size_t num = x%32;

        return (vec[index] >> num) & 1; 
    }

    void clear() 
    {
        vec.clear();
    }

};

int count = 0;
int countNum(std::vector<int> &nums, int target);
void dfs(std::vector<int> &nums, int target, int pos);

int main() {
    std::vector<int> nums = {1,3,5};
    int target = 100;

    countNum(nums, target);

    std::cout << count/2 << std::endl;

    return 0;
}


int countNum(std::vector<int> &nums, int target)
{
    dfs(nums, target, 0);
}

void dfs(std::vector<int> &nums, int target, int pos)
{
    if(target == 0) {
        count++;
        return;
    }

    if(target < 0) return;

    for(int i = pos; i < nums.size(); i++) {
        dfs(nums, target - nums[i], i);
    }

}
std::mutex mut;
std::condition_variable cv;

int k = 1;

void printStirng1()
{
    std::unique_lock<std::mutex> lock(mut);

    while(1)
    {
        while(k != 1) cv.wait(lock);

        std::cout << "A" << std::endl;

        k = 2;
        cv.notify_all();
    }

}

void printStirng2()
{
    std::unique_lock<std::mutex> lock(mut);

    while(1)
    {
        while(k != 2) cv.wait(lock);

        std::cout << "B" << std::endl;

        k = 3;
        cv.notify_all();
    }
    
}

void printStirng3()
{
    std::unique_lock<std::mutex> lock(mut);

    while(1)
    {
        while(k != 3) cv.wait(lock);

        std::cout << "C" << std::endl;

        k = 1;
        cv.notify_all();
    }
    
}

int main() {
    std::thread t1(printStirng1);
    std::thread t2(printStirng2);
    std::thread t3(printStirng3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


std::string serialize(TreeNode *root)
{
    if(root == nullptr) return "#";

    return std::to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
}

TreeNode* deserialize(std::string data)
{
    std::stringstream in(data);

    return dfs(in);
}

TreeNode* dfs(std::stringstream &in)
{
    std::string val;
    getline(in, val, ',');

    if(val == "#") return nullptr;

    TreeNode *root = new TreeNode(std::stoi(val));
    root->left = dfs(in);
    root->right = dfs(in);

    return root;
}


int main() {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);

    TreeNode *pRight = root->right;
    pRight->right = new TreeNode(3);

    std::cout << serialize(root) << std::endl;

    return 0;
}


std::string lastSubstring(std::string s)
{
    char maxChar = 'a';
    for(const char &c : s) {
        maxChar = std::max(maxChar, c);
    }

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == maxChar) return s.substr(i);
    }

    return "";
}



/*
class Singleton 
{
private:
    Singleton() {}
    Singleton(const Singleton &);
    Singleton& operator=(const Singleton &);

public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void print() {
        std::cout << "do something!" << std::endl;
    }
};
*/

// class Singleton
// {
// private:
//     Singleton() {}                                      
//     Singleton(const Singleton &);                 
//     Singleton& operator=(const Singleton &);      
//     static Singleton instance;

// public:
//     static Singleton& getInstance() {
//         return instance;
//     }

//     void print() {
//         std::cout << "do something!" << std::endl;
//     }

// };

// Singleton::instance;

/*
class Singleton
{
private:
    Singleton() {}
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
    static Singleton *instance;
    static std::mutex mut;

public:
    static Singleton* &getInstance() 
    {
        if(instance == nullptr) 
        {
            std::unique_lock<std::mutex> lock(mut);
            if(instance == nullptr) {
                instance = new(std::nothrow) Singleton();
            }
        }
        return instance;
    }

    void print() {
        std::cout << "do something!" << std::endl;
    }

};

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mut;


// int main() {
//     Singleton* &demo = Singleton::getInstance();
//     demo->print();

//     return 0;
// }

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





class myStack
{
private:
    std::vector<int> nums, maxVal;
    int size;   //表示栈中元素大小
    int end;    //表示nums栈顶元素位置
    int index;  //表示maxVal栈顶元素位置

public:
    myStack(int n = 0) {
        nums.resize(n);
        maxVal.resize(n);
        end = -1;
        index = -1;
        size = n;
    }

    bool isFull() {
        if(end == size - 1) return true;
        else return false;
    }

    bool isEmpty() {
        if(end == -1) return true;
        else return false;
    }

    int top() {
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

    int max() {
        if(isEmpty())  return -1;
        return maxVal[index];
    }

    void pop() {
        if(isEmpty()) return;
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
    myQueue(int n = 0) {
        nums.resize(n);
        pre = tail = 0;
        size = n;
    }

    bool empty() {
        return pre == tail;
    }

    bool full() {
        if((tail+1)%size == pre) return true;
        return false;
    }

    void push(int x) {
        if(full()) return ;
        nums[tail] = x;
        tail = (tail+1)%size;
    }

    void pop() {
        if(empty()) return;
        pre = (pre+1)%size;
    }

    int front() {
        if(empty()) return -1;
        return nums[pre];
    }

    int len() {
        return (tail-pre+size)%size;
    }
};

int main() {
    myQueue que(3);
    que.push(3);
    que.push(1);
    que.push(2);

    while(!que.empty()) {
        std::cout << que.front() << std::endl;
        que.pop();
    }


    return 0;
}


void strcpy(char *des, char *src)
{
    if(des == nullptr || src == nullptr) return;

    char *pDes = des, *pSrc = src;
    
    while((*pDes++ = *pSrc) != '\0');

}


class String
{
private:
    char *str;
    size_t len;

public:
    String(const char *s = NULL)
    {
        if(s == NULL) {
            str = new char[1];
            *str = '\0';
            len = 0;
        }
        else {
            len = strlen(s);
            str = new char[len+1];
            strcpy(str, s);
        }
    }

    String(const String &demo)
    {
        len = demo.len;
        str = new char[len+1];
        strcpy(str, demo.str);
    }

    String& operator=(const String &demo)
    {
        if(this == &demo) return *this;

        delete[] str;

        len = demo.len;
        str = new char[len+1];
        strcpy(str, demo.str);

        return *this;
    }

    String operator+(const String &demo) const
    {
        int len = strlen(str) + strlen(demo.str) + 1;
        char *sp = new char[len];
        strcpy(sp, str);
        strcat(sp, demo.str);
        String tmp(sp);
        return tmp;
    }

    ~String() {
        delete[] str;
    }

    void print() {
        printf("%s\n", str);
    }

};




template<class T>
class shared_ptr
{
private:
    T *ptr;
    int *count;

public:
    shared_ptr(T *pointer = nullptr)
    {
        ptr = pointer;

        if(ptr == nullptr) count = new int(0);
        else count = new int(1);
    }

    shared_ptr(const shared_ptr &smartPtr)
    {
        ptr = smartPtr.ptr;
        count = smartPtr.count;

        (*count)++;
    }

    shared_ptr& operator=(const shared_ptr &smartPtr)
    {
        if(ptr != smartPtr.ptr)
        {
            if(ptr != nullptr && --(*count) == 0) {
                delete ptr;
                delete count;
            }

            ptr = smartPtr.ptr;
            count = smartPtr.count;
            (*count)++;
        }
    }

    T& operator*() { return *ptr; }

    T* operator->() { return ptr; }

    ~shared_ptr()
    {
        if(ptr == nullptr) delete count;
        else if(--(*count) == 0) {
            delete ptr;
            delete count;
        }
    }

    int use_count() { return *count; }

};




template<class T>
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
    MyVector() {
        capacity = 1;       //初始容量设置为1
        size = 0;
        data = new int[capacity];
    }

    MyVector(int m_size, T val = 0)
    {
        data = new T[size];
        for(int i = 0; i < m_size; i++) data[i] = val;

        capacity = m_size;
        size = m_size;
    }

    MyVector(const MyVector &demo)
    {
        size = demo.size;
        capacity = size;
        data = new T[size];

        for(int i = 0; i < size; i++) data[i] = demo.data[i];
    }

    ~MyVector() {
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

    void print() {
        std::cout << size << " " << capacity << std::endl;
    }

};


int main() {
    MyVector<int> vec;
    vec.push_back(9);
    vec.push_back(3);
    vec.push_back(1);

    std::cout << vec[0] << std::endl;
    vec.print();

    // int *data = new int[0];
    // data[0] = 1;
    // data[1] = 2;

    // std::cout << data[1] << std::endl;
    // delete[] data;

    return 0;
}
*/



// template<typename T>
// struct ListNode {
//     T val;
//     ListNode *next;
//     ListNode(int m_val) : val(m_val), next(nullptr) {}
// };

/*
template<typename T>
int compare(const T &a, const T &b) {
    if(std::less<T>()(a, b)) return -1;
    if(std::less<T>()(a, b)) return 1;
    return 0;
}


// class A {
// public:
//     A(int m_val) : val(m_val) {}

// private:
//     int val;
// };

// class B {
// public:
//     // B(A &m_a) { a(m_a); }
//     B(A &m_a) : a(m_a) {}

// private:
//     A a;
// };

// class Base {
// public:
//     Base() {}
//     Base(int m_val) : val(m_val) {}
//     int val;
// };

// class Derived : public Base {
// public:
//     Derived(int m_val) : val(m_val) {}
//     // Derived(int m_val) { val = m_val; }
// }; 


class A {
public:
    explicit A(int a) {}
    explicit A(const A &a) {}
};


int main() {
    // ListNode<int> node1 = ListNode(2.0);
    // ListNode<int> *pNode1 = new ListNode(2.0);

    // std::cout << compare(1,2) << std::endl;

    A a(1);
    // A b = A(1);
    A c = a;

    return 0;
}
*/

/*
class String 
{
private:
    char *str;
    size_t len;

public:
    String(const char *s = NULL) 
    {
        if(s == NULL) {
            str = new char[1];
            *str = '\0';
            len = 0;
        }
        else {
            len = strlen(s);
            str = new char[len + 1];
            strcpy(str, s);
        }
    }

    String(const String &demo) 
    {
        len = demo.len;
        str = new char[len + 1];
        strcpy(str, demo.str);        
    }

    String& operator=(const String &demo) 
    {
        if(this = &demo) return *this;

        delete[] str;

        len = demo.len;
        str = new char[len + 1];
        strcpy(str, demo.str);

        return *this;
    }


    //'+'运算符返回一个新的对象，
    String operator+(const String &demo) const 
    {
        int len = strlen(str) + strlen(demo.str) + 1;
        char *sp = new char[len];
        strcpy(sp, str);
        strcat(sp, demo.str);
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
*/

/*
class Student
{
public:
    int id, age;

    Student(int m_id, int m_age) : id(m_id), age(m_age) {}

    Student(int r) {
        id = 1000;      
        age = r;  
    }

    Student operator+(const Student &demo) const 
    {
        return Student(id + demo.id, age + demo.age);
    }

};

class A {
public:
    A(int m_x) : x(m_x) {}
    static void f(A a);

private:
    int x;
};

void A::f(A a) {
    std::cout << a.x << std::endl;
}

int main() {
    // Student stu1(1, 100);

    // Student stu2 = stu1 + 111;

    // std::cout << stu2.id << " " << stu2.age << std::endl;


    A demo(100);

    demo.f(demo);
    // A::f(demo);
    // A::f(demo);

    return 0;
}
*/


/*
#include <vector>
#include <string.h>
#include <algorithm>

// template<typename T>
// void add(T a, T b) {
//     std::cout << "Version 1" << std::endl;
// }

// template<typename T>
// void add(const T &a, const T &b) {
//     std::cout << "Version 2" << std::endl;
// }

template<typename T>
void debug(const T &t) {
    std::cout << "Version 1" << std::endl;
}


template<typename T>
void debug(T *p) {
    std::cout << "Version 2" << std::endl;
}

template<typename T>
bool isPtr(T *p) {
    return true;
}

bool isPtr(...) {
    return false;
}

template<typename T>
int compare(const T &a, const T &b) {
    return a < b;
}

template<size_t N, size_t M>
int compare(const char(&a)[N], const char(&b)[M]) {
    for(int i = 0; i < std::min(N, M); i++) {
        if(a[i] == b[i]) continue;
        else return a[i] < b[i];
    }

    return false;
}


int main() {
    const char *p1 = "hi", *p2 = "mom";

    // std::cout << compare(p1, p2) << std::endl;
    std::cout << compare("hi", "mom") << std::endl;

    // int n1 = 1, n2 = 2;
    // std::cout << add(1, 2) << std::endl;

    // add(1,2);

    // std::string s("hi");
    // debug(&s);
    // debug(s.data());

    // int n = 1;
    // int *p = &n;

    // std::cout << isPtr(p) << std::endl;
    // std::cout << isPtr(n) << std::endl;

    return 0;
}


int res = INT_MIN;

int diameterOfBinary(TreeNode *root)
{
    if(root == nullptr) return 0;

    dfs(root);

    return res;
}

void dfs(TreeNode *root)
{
    if(root == nullptr) return 0;

    int leftLen = dfs(root->left);
    int rightLen = dfs(root->right);

    res = std::max(res, leftLen + rightLen);

    return std::max(leftLen, rightLen) + 1;
}
*/


#include <iostream>
#include <mutex>

/*
class Singleton
{
private:
    Singleton() {}
    Singleton(const Singleton &);
    Singleton& operator=(const Singleton &);

public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void printTest() {
        std::cout << "do something!" << std::endl;
    }

};
*/

class Singleton
{
private:
    Singleton() {}
    Singleton(const Singleton &);
    Singleton& operator=(const Singleton &);
    static Singleton *instance;
    static std::mutex mut;

public:
    static Singleton* &getInstance() 
    {
        if(instance == nullptr)
        {
            std::unique_lock<std::mutex> lock(mut);
            if(instance == nullptr) {
                instance = new(std::nothrow) Singleton();
            }
        }
        return instance;
    }

    void print() {
        std::cout << "do something!" << std::endl;
    }
  
};

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mut;


void strcmp(char *des, char *src)
{
    if(des == nullptr || src == nullptr) return;

    char *pDes = des, *pSrc = src;

    while((*pDes++ = *pSrc++) != '\0');
}


int main() {
    // Singleton& demo = Singleton::getInstance();
    // demo.printTest();

    Singleton* demo = Singleton::getInstance();
    demo->print();

    return 0;
}


void mergeSort(std::vector<int> &nums, int left, int right)
{
    if(left < right)
    {
        int mid = left + ((right - left) >> 1);
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

}

void merge(std::vector<int> &nums, int left, int mid, int right)
{
    int lindex = left, rindex = mid + 1;
    int *team = new int[right-left+1];
    int index = 0;

    while(lindex <= mid && rindex <= right)
    {
        if(nums[lindex] <= nums[rindex]) {
            team[index++] = nums[lindex++];
        }
        else {
            team[index++] = nums[rindex++];
        }
    }

    while(lindex <= mid) team[index++] = nums[lindex++];
    while(rindex <= right) team[index++] = nums[rindex++];

    for(int i = 0; i < index; i++) {
        nums[left+i] = team[i];
    }

    delete[] team;
}


