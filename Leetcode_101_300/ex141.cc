

//Leetcode第141题
//Linked List Cycle : 判断链表是否有环


//思路:利用快慢指针
//1.如果存在环则快慢指针肯定会相遇,若相遇直接返回true即可
//2.快指针遍历到链表末尾两个指针也没相遇直接返回false


bool hasCycle(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        
        if(fast == slow){
            return true;
        }
    }

    return false;
}