


//Leetcode第160题:两个链表的第一个公共节点
//与<剑指>面试题52相同,但这里的思路更好


//思路:把两个链表相同的部分记做c,相交节点记为*,则第一个链表记为a*c,第二个链表记为b*c
//两个虚拟链表可记为 
// a*cb*c
// b*ca*c 
// a和b的长度不一定相同,但是第二个*之前的两个链表的长度相同,由此两个虚拟链表走相同步数可以到达第二个*处


//下面的代码对没有公共节点的链表也合适
//比如: LinklistA: 1->2->nullptr    LinklistB: 3->nullptr
//curA:1->2->nullptr->3->nullptr
//curB:3->nullptr->1->2->nullptr  最后的相交点为 nullptr,返回nullptr


ListNode* getFirstK(ListNode *headA, ListNode *headB)
{
    ListNode *curA = headA;
    ListNode *curB = headB;

    while(curA != curB)
    {
        curA = curA ? curA->next : headB;
        curB = curB ? curB->next : headA;
    }

    return curA;
}
