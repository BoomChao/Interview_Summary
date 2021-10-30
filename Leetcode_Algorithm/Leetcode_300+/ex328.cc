

//Leetcode第328题:Odd Even List
//把序号为奇数的节点全部放在链表的前半段,序号为偶数的节点全部放在链表的后半段

//注意:一定要看清题目,是按照序号奇偶性,不是按照节点数值奇偶性


ListNode* oddEvenList(ListNode *head)
{
    ListNode *pOdd = head;
    ListNode *pEven = head->next, *pEvenHead = even;      //这个语句就相当于ListNode *even = head->next; ListNode *evenHead = even;

    //后面的pEven->next != nullptr 一定要加上,不加的话如果像1->2->nullptr,这种情况就会出错
    while(pEven != nullptr && pEven->next != nullptr)
    {
        pOdd = pOdd->next = pEven->next;
        pEven = pEven->next = pOdd->next;
    }

    pOdd->next = pEvenHead;

    return head;

}
