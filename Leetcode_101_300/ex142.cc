

//Leetcode第142题
//Linked List Cycle II : 已知链表存在环,找出链表环的起点


//思路:和141题类似,还是利用二重指针
//1.由于给定的链表存在环,则快指针和慢指针必定会相遇,不妨设此时慢指针走了x步,则快指针走了2x步
//假定链表起始位置到环起点的长度为a,环的长度为b;  则 2x-x = kb, k为正整数
//由于慢指针走的步数 x = kb; 则慢指针再走a步一定能到达环起点, 因为 a+x = a+kb  
//2.所以当快慢指针重合时,定义一个指针p指向链表头结点,指针p和慢指针同时移动,当二者相等时,则说明p和慢指针同时到达了环起点位置
//3.如果没有环则直接返回空节点


ListNode* detectCycle(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;

    while(fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        {
            ListNode *pNode = head;
            while(pNode != slow)
            {
                pNode = pNode->next;
                slow = slow->next;
            }

            return pNode;
        }

    }

    return nullptr;

}