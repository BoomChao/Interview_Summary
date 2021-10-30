

//Leetcode第147题 : Insertion Sort List
//对链表进行插入排序


ListNode* sortList(ListNode *head)
{
    //链表为空,或者只有一个元素,不需要排序,直接返回头结点
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *preHead = new ListNode(-1);
    preHead->next = head;

    ListNode *cur = head;
    ListNode *last = cur->next;

    while(last != nullptr)
    {
        ListNode *pre = preHead;
        ListNode *tmp = preHead->next;
        while(tmp != last && tmp->val < last->val) {
            pre = pre->next;
            tmp = tmp->next;
        }

        if(tmp == last) {
            cur = last;
        }
        else {
            cur->next = last->next;
            last->next = tmp;
            pre->next = last;
        }

        last = cur->next;
    }

    return preHead->next;

}