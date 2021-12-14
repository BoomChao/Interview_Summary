


/*
    面试题23:链表中环的入口节点
    与Leetcode第142题相同,推荐使用Leetcode解法,比这个更加简洁
*/


//在链表中存在环的前提下找到一快一慢指针相遇的节点,这个相遇的节点肯定是在环内

ListNode* MeetingNode(ListNode *pHead)
{
    if(pHead == nullptr) return nullptr;

    ListNode *pSlow = pHead->next;
    if(pSlow == nullptr) return nullptr;

    ListNode *pFast = pSlow->next;
    while(pFast != nullptr && pSlow != nullptr)
    {
        if(pFast == pSlow) return pFast;

        pSlow = pSlow->next;
        pFast = pFast->next;
        if(pFast != nullptr) {
            pFast = pFast->next;
        }

    }

    return nullptr;

}


//在找到链表中任意一个节点后,就能得出环中的节点数目,并找到环的入口节点

ListNode *entryNodeOfLoop(ListNode *pHead)
{
    ListNode *meetingNode = MeetingNode(pHead);
    if(meetingNode == nullptr) return nullptr;      //如果不存在环就直接返回

    //得到环中节点的数目
    int nodesInLoop = 1;
    ListNode *pNode1 = meetingNode;
    while(pNode1->next != nullptr)
    {
        pNode1 = pNode1->next;
        ++nodesInLoop;
    }

    //先移动pNode1,移动次数为环中节点的数目
    pNode1 = pHead;
    for(int i = 0; i < nodesInLoop; i++) {
        pNode1 = pNode1->next;
    }

    //同时移动pNode1和pNode2
    ListNode *pNode2 = pHead;
    while(pNode1 != pNode2)
    {
        pNode1 = pNode1->next;
        pNode2 = pNode2->next;
    }

    return pNode1;

}
