//Leetcode第61题
//Rotate List : 旋转链表


//思路一:对于链表 1->2->3->4->5->NULL
//1.先将单链表形成循环链表并得出循环链表的长度,即 1->2->3->4->5(->1)
//2.此时指针指向元素5,对于k=2,则将原来单链表的右边两个元素依次移动到首部,相当于指针
//沿着循环链表移动5-2=3步,抽离出来则指针需要沿着循环链表移动 (n-(k%n))步


#include <iostream>

ListNode* rotateRight(ListNode *head, int k)
{
    if(head == nullptr || head->next == nullptr || k == 0) return head;

    int count = 1;
    ListNode *tail = head;
    while(tail->next != nullptr){
        count++;            //计算链表的长度
        tail = tail->next;
    }
    tail->next = head;      //形成循环链表

    ListNode *pre = tail;
    int n = count-(k%count);
    for(int i = 0; i < n; i++){
        pre = pre->next;
    }
    
    ListNode *res = pre->next;
    pre->next == nullptr;

    return res;

}





//思路二:(这个比较好理解)
//1.找到链表尾部形成循环链表
//2.定义一个指针指向表头,则旋转k步,则指向表头指针走(n-k-1)步,将其下一节点置为空即可


ListNode* rotate(ListNode* head, int k)
{
    //当为空表,或者表中只有一个元素,或者k=0时直接返回
    if(head == nullptr || head->next == nullptr || k == 0) return head;    

    ListNode* tail = head;
    int len = 1;
    while(tail->next != nullptr){
        tail = tail->next;
        len++;
    }
    tail->next = head;    //形成循环链表

    k %= len;   //k = len时,相当于没有旋转,所以这里需要取余
    ListNode *pre = head;
    for(int i = 0; i < len-k-1; i++){    
        pre = pre->next;
    }

    ListNode *res = pre->next;
    pre->next == nullptr;

    return res;

}