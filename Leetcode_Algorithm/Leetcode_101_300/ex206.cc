
//Leetcode第206题
//REverse Linked List : 反转链表

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(0), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(nullptr) {}

};


ListNode* reverseList(ListNode *head)
{
    ListNode *pre = nullptr;
    ListNode *cur = head;

    while(cur != nullptr){
        ListNode *last = cur->next;
        cur->next = pre;
        pre = cur;
        cur = last;
    }

    return pre;

}

