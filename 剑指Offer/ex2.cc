

/*
    面试题52:两个链表的第一个公共节点
*/


//思路:先得到两个链表的长度
//让长链表先多走几步走到和短链表相同的起点,之后长短链表同时出发,直到走到公共节点

struct ListNode{
    int key;
    ListNode *next;
};

ListNode* findFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
{
    //得到两个链表的长度
    unsigned int nLength1 = getListLength(pHead1);
    unsigned int nLength2 = getListLength(pHead2);
    int nLengthDif = nLength1-nLength2;

    ListNode *pListHeadLong = pHead1;
    ListNode *pListHeadShort = pHead2;
    if(nLength2 > nLength1)
    {
        pListHead1 = pHead2;
        pListHeadShort = pHead1;
        nLengthDif = nLength2-nLength1;
    }

    //先在长链表上走几步,再同时在两个链表上遍历
    for(int i = 0; i < nLengthDif; i++) {
        pListHeadLong = pListHeadLong->next;
    }

    while((pListHeadLong != nullptr) && (pListHeadShort != nullptr) && (pListHeadShort != pListHeadLong))
    {
        pListHeadLong = pListHeadLong->next;
        pListHeadShort = pListHeadShort->next;
    }

    ListNode *pFirstCommonNode = pListHeadLong;

    return pFirstCommonNode;

}


//计算链表的长度
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
