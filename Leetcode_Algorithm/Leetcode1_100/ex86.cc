

//Leetcode第86题
//Patrition List:切割链表,小数放在前面,大数放在后面



//思路:
//1.定义两个链表,一个用来保存小于该值x的链表list1,一个用于保存大于该值的链表list2
//2.遍历整个链表,将小于该值的放在list1中,大于该值的放在list2中
//3.遍历结束后,将list2插在list1尾部


ListNode* partition(ListNode *head, int x)
{
    if(head == nullptr) return head;

    ListNode *node1 = new ListNode(-1);
    ListNode *node2 = new ListNode(-1);
    ListNode *pre1 = node1;
    ListNode *pre2 = node2;

    while(head != nullptr){
        if(head->val < x){
            node1->next = head;
            node1 = node1->next;
            head = head->next;      //千万注意,这个不能放到判定语句外面     如:1->4->3;  对node1:-1->1,如果放在外面就会将主链表的4替换成了nullptr，则
            node1->next = nullptr;                                  // 下一次head = head->next就会指向nullptr
        }
        else{
            node2->next = head;
            node2 = node2->next;
            head = head->next;
            node2->next = nullptr;
        }

    }

    node1->next = pre2->next;

    return pre1->next;

}


//上面的改进版

ListNode* partition(ListNode *head, int x)
{
    if(head == nullptr) return head;

    ListNode *node1 = new ListNode(-1);
    ListNode *node2 = new ListNode(-1);
    ListNode *pre1 = node1;
    ListNode *pre2 = node2;

    while(head != nullptr){
        if(head->val < x){
            node1->next = head;
            node1 = node1->next;
        }
        else{
            node2->next = head;
            node2 = node2->next;
        }

        head = head->next;
    }

    node2->next = nullptr;  //注意:这一步一定要加,将最后一个元素的下一节点置为nullptr

    node1->next = pre2->next;

    return pre1->next;

}