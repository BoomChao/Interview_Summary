
//Leetcode第82题
//Remove Duplicates from the Sorted List II : 81题的升级版,去除掉链表中所有重复的元素


//思路:
//1.由于可能重复的数在首位,我们先定义一个值为-1的节点指向链表首元素
//2.遍历链表节点,如果当前节点值和下一个节点的值相等时,定义一个临时节点pNext指向当前节点,
//  并与下一个节点判断,如果两者值还等于,则将pNext节点指向后一节点,一直到两者值不相等或者到达链表尾部为止,此时将当前遍历到的位置节点的指向pNext
//3.否则将遍历指针后移


ListNode* deleteDuplicates(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return head;   //处理边界条件,链表为空或者只有一个元素直接返回

    ListNode *preHead = new ListNode(-1);
    preHead->next = head;
    ListNode *cur = preHead;

    while(cur->next != nullptr && cur->next->next != nullptr)
    {
        int value = cur->next->val;

        if(value == cur->next->next->val)
        {
            ListNode *pNext = cur->next;
            while(pNext != nullptr && pNext->val = value) {
                ListNode *tmp = pNext;
                pNext = pNext->next;
                delete tmp;         //删除掉的节点将内存释放掉
            }

            cur->next = pNext;
        }
        else
        {
            cur = cur->next;
        }

    }

    return preHead->next;


}