

//Leetcode第876题:Middle of the Linked List
//找到链表的中间节点

//思路:利用快慢指针


ListNode* findMiddleNode(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *slow = head;
    ListNode *fast = head;

    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    //如果是节点个数是奇数,则跳过中间节点,这时slow恰好指向链表后半部分的开始节点
    if(fast != nullptr) {
        slow = slow->next;
    }

    return slow;

}