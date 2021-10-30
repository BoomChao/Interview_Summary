

//Leetcode第92题
//Reverse Linked List II : 翻转指定位置区间的链表

//思路:两种方法
//1.参考第206题
//2.参考第25题


//思路:参照206题的思路
//1.我们先根据m找到指定的pre和cur
//2.接下来依据n来翻转中间部分链表
//3.需要注意的是之前第1步找的的pre和cur需要记录下来,因为中间链表翻转完成后需要考虑前后两端的指向


ListNode* reverseBetween_1(ListNode *head, int m, int n)
{   
    if(head == nullptr || m >= n || m <= 0 || n<=0) return head;

    ListNode *preHead = new ListNode(-1);       //预防第一个位置就是链表第一个元素,所以这里额外申请一个节点指向链表头结点
    pre->next = head;

    int i = 1;
    ListNode *pre = preHead;
    ListNode *cur = head;
    for(; i < m && cur != nullptr; i++){
        pre = cur;
        cur = cur->next;
    }   //这个循环出来之后i的结果为m

    ListNode *tmp1 = pre;     //将这两个变量值先保存起来
    ListNode *tmp2 = cur;
    for(; i <= n && cur != nullptr; i++){   //注意:这里是 i<=n
        ListNode *last = cur->next;
        cur->next = pre;
        pre = cur;
        cur = last;
    }

    tmp1->next = pre;
    tmp2->next = cur;

    return preHead->next;

}




//或者参照第25题的解法

ListNode *reverseBetween_2(ListNode *head, int m, int n)
{
    if(head == nullptr || m >= n || m <= 0 || n<=0) return head;

    ListNode *preHead = new ListNode(-1);
    preHead->next = head;

    ListNode *pre = preHead;
    for(int i = 0; i < m-1; i++){
        pre = pre->next;
    }
    ListNode *cur = pre->next;

    for(int i = 0; i < n-m; i++){
        ListNode *tmp = cur->next;
        cur->next = tmp->next;
        tmp->next = pre->next;
        pre->next = tmp;
    }

    return preHead->next;

}