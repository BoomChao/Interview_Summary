//Leetcode第二题
//将两个链表的元素相加并输出

//思路:仔细观察就会发现,比如对 l1 = 1->2->5; l2 = 3->2->5
//从链表的第一个节点开始相加,如果和小于10,则新链表的节点值为该和
//但是如果相加之和大于10,比如恰好为10,则需要向后进一位(后一位的和需要加上1),而当前节点的值就等于和%10


typedef struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}       //三个构造函数
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {} 

}ListNode;



ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode *base = new ListNode(0);   //base用来指向链表第一个节点
    ListNode *l3 = base;

    int carry = 0;  //carry表示需要进位的数的大小;  如:carry=1表示下一位需要加上1
    while(l1!=nullptr || l2!=nullptr ||carry){      //这里判断循环条件要把carry也加上,比如 l1 = 1->2->5; l2 = 3->2->5; 结果l3 = 4->4->0->1; 这时链表的长度要增加
        int val1 = (l1 != nullptr) ? l1->val : 0;
        int val2 = (l2 != nullptr) ? l2->val : 0;
        int cur = l1val + l2val + carry;
        carry = cur/10;  
        int last_digit = cur%10;

        ListNode* newNode = new ListNode(last_digit);
        l3->next = newNode;

        if(l1 != nullptr) l1 = l1->next;    //三个链表都往后移一位
        if(l2 != nullptr) l2 = l2->next;
        l3 = l3->next;

    }

    return base->next;  //因为链表第一个数据是0,是为了初始化方便而添加的,而结果不需要

}