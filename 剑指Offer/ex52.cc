

/*
    面试题52：两个链表的第一个公共节点
*/

struct ListNode{
    int key;
    ListNode *next;

};


ListNode* findFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
{
    //得到两个链表的长度
    unsigned int nLength1 = getListLength(pHead1);
    unsigned int nLength2 = getListLength(pHead2);
    int nLengthDif = nLength1 - nLength2;

    ListNode *pListHeadLong = pHead1;
    ListNode *pListHeadShort = pHead2;
    if(nLength2 > nLength1)
    {
        pListHeadLong = pHead2;
        pListHeadShort = pHead1;
        nLengthDif = nLength2 - nLength1;
    }

    //现在长链表上走几步，再同时在两个链表上遍历
    for(int i = 0; i < nLengthDif; i++) {
        pListHeadLong = pListHeadLong->next;
    }

    while((pListHeadLong != nullptr) && (pListHeadShort != nullptr) && (pListHeadShort != pListHeadLong))
    {
        pListHeadLong = pListHeadLong->next;
        pListHeadShort = pListHeadShort->next;
    }

    //得到第一个公共节点
    ListNode *pFirstCommonNode = pListHeadLong;

    return pFirstCommonNode;

}


//得到链表的长度
unsigned int getListLength(ListNode *pHead)
{
    unsigned int nLength = 0;
    ListNode *pNode = pHead;

    while(pNode != nullptr) {
        ++nLength;
        pNode = pNode->next;
    }

    return nLength;
    
}