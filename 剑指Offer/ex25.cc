

/*
    面试题25:合并两个升序链表
*/

//面试官要求讲思路的话最好画图来解释



struct ListNode{
    int value;
    ListNode *next;

};


ListNode* Merge(ListNode *pHead1, ListNode *pHead2)
{
    if(pHead1 == nullptr) {
        return pHead2;
    }
    else if(pHead2 == nullptr) {
        return pHead1;
    }

    ListNode *pMergeHead;
    if(pHead1->value < pHead2->value)
    {
        pMergeHead = pHead1;
        pMergeHead->next = Merge(pHead1->next, pHead2);
    }
    else
    {
        pMergeHead = pHead2;
        pMergeHead->next = Merge(pHead1, pHead2->next);
    }

    return pMergeHead;

}