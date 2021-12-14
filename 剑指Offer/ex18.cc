

/*
    面试题18:删除链表的节点

    1.给定单向链表的头指针和一个节点指针,定义一个函数在O(1)时间内删除该节点

    2.删除链表中重复的节点:提供的解法不太好,参考Leetcode第83题和第84题

*/


struct ListNode {
    int val;
    ListNode *next;
};



//1.给定单向链表的头指针和一个节点指针,定义一个函数在O(1)时间内删除该节点

//思路:给定了要删除的节点指针,需要在O(1)时间内完成删除操作
//我们将要删除节点i的下一个节点j的内容复制给i,然后把i的指针指向j的下一个节点
//然后再删除节点j,其效果刚好就是把节点i删除了

//需要注意:当删除节点不是不是尾节点是就按上述方法进行
//当链表只有一个元素,则需要删除头结点,并将链表置空
//当链表有多个元素,但是删除节点是尾节点,这时只能使用顺序遍历到要删除节点的前一个节点,时间复杂度为O(n)



void deleteNode(ListNode **pListHead, ListNode *pToBeDeleted)
{
    if(pListHead == nullptr || pToBeDeleted == nullptr) return;

    //要删除的节点不是尾节点
    if(pToBeDeleted->next != nullptr)
    {
        ListNode *pNext = pToBeDeleted->next;
        pToBeDeleted->val = pNext->val;
        pToBeDeleted->next = pNext->next;

        delete pNext;
        pNext = nullptr;    //防止成为悬空指针

    }
    
    //要删除的节点是尾节点,但是链表只有一个节点,删除尾节点(也是头节点)
    else if(*pListHead == pToBeDeleted)
    {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        *pListHead = nullptr;

    }

    //要删除的节点是尾节点,而且链表有多个节点
    else
    {
        ListNode *pNode = *pListHead;
        while(pNode->next != pToBeDeleted) {
            pNode = pNode->next;        //找到删除节点的前一个节点
        }

        pNode->next = nullptr;

        delete pToBeDeleted;
        pToBeDeleted = nullptr;

    }

}