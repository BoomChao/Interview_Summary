

/*
    面试题24:反转链表
    参考Leetcode第506题
*/


ListNode* reverseList(ListNode *head)
{
    ListNode *pre = nullptr;
    ListNode *cur = head;

    while(cur != nullptr)
    {
        ListNode *pNext = cur->next;
        cur->next = pre;
        pre = cur;
        cur = pNext;
    }

    return pre;

}
