


/*
    面试题22:链表中的倒数第k个节点
    利用快慢指针
*/


struct ListNode{
    int value;
    ListNode *next;
};


ListNode *findKthToTail(ListNode *pListHead, unsigned int k)
{
    if(pListHead == nullptr || k == 0) return nullptr;

    ListNode *pAhead = pListHead;
    ListNode *pBehind = pListHead;

    //快指针先走k-1步
    for(unsigned int i = 0; i < k-1; i++) 
    {
        if(pAhead->next != nullptr) {
            pAhead = pAhead->next;
        }
        else {
            return nullptr;
        }

    }
    
    //快指针走了k-1步后,快慢指针同时出发
    while(pAhead->next != nullptr)
    {
        pAhead = pAhead->next;
        pBehind = pBehind->next;
    }

    return pBehind;

}
