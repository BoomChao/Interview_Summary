


//ListNode第83题
//Remove Duplicates from the Sorted List : 从排序的链表中删除掉重复的元素


//思路:
//1.比较当前节点的值和下一个节点的值,如果相同则将当前节点指向下下节点,继续与下下节点比较(因为可能出现三个节点相同的情况,即 1->1->1 的情况)
//2.如果不同则节点后移继续比较


ListNode* deleteDuplicates(ListNode *head)
{
    ListNode *cur = head;
 
    while(cur != nullptr && cur->next != nullptr)
    {
        if(cur->val == cur->next->val)
        {
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;    //删除掉的节点空间也释放掉
        }
        else
        {
            cur = cur->next;
        }
        
    }

    return head;

}