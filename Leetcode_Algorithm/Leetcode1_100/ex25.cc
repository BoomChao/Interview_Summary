

//Leetcode第25题 : Reverse Nodes in k-Group
//对给定的链表,给出一个数k,对链表的每k个节点就翻转一次

//思路:迭代解法
//假设给定的链表为:1->2->3->4->5, k=3
//则首先将123翻转,先将1后面的2移至首位得213,再将1后面的3移至首位得321,翻转完成;需要翻转k-1次

//假设给定的链表为:1->2->3->4->5, k=4
//则首先将1234翻转,先将1后面的2移至首位得2134,再将1后面的3移至首位得3214,再将1后面的4移至首位得4321,翻转完成;需要翻转k-1次




struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* reverseKGroup(ListNode *head, int k)
{
    if(head == nullptr || k <= 1) return head;

    ListNode *preHead = new ListNode(-1);
    preHead->next = head;
    ListNode *pre = preHead;    //这里定义了一个指针*nex但未初始化(初始化在下面的38行),所以让其指向空
    
    int len = 1;    //len代表链表的长度
    ListNode *tmp = head;   //这个tmp指针用来计算链表节点的个数
    while(tmp->next != nullptr) {
        len++;
        tmp = tmp->next; 
    }

    if(len < k) return head;    //链表长度小于要翻转的个数,则直接返回

    while(len >= k)
    {
        ListNode *cur = pre->next;
        ListNode *nex = cur->next;

        for(int i = 1; i < k; i++)
        {     //k个节点只需要翻转k-1次
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        len -= k;
    }
    
    return preHead->next;
}



// 解法二:更好理解
// 时间复杂度O(nk),空间复杂度为O(1)

ListNode* reverseKGroup(ListNode *head, int k)
{
    if(head == nullptr || head->next == nullptr || k <= 1) return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *pointer = dummy;

    while(pointer != nullptr)
    {
        //记录上一个链表的尾
        ListNode *lastGroup = pointer;
        
        int i = 0;
        for(; i < k; i++) {
            pointer = pointer->next;
            if(pointer == nullptr) {
                break;
            }
        }

        if(i == k)
        {
            //记录下一个子链表的头
            ListNode *nextGroup = pointer->next;

            //翻转当前子链表,reverse函数返回翻转后子链表的头
            ListNode *reversedList = reverse(lastGroup->next, nextGroup);

            pointer = lastGroup->next;

            //将上一个链表的尾连向翻转后链表的头
            lastGroup->next = reversedList;

            //当前翻转后的链表的尾指向下一个子链表的头
            pointer->next = nextGroup;
        }
    }

    return dummy->next;
}


//注意这个reverse函数的第二个参数的tail传入的是下一个子链表的头节点
//返回的是tail的前一个节点
ListNode* reverse(ListNode *head, ListNode *tail)
{
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *prev = nullptr, *temp = nullptr;
    while(head != nullptr && head != tail)
    {
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }

    return prev;
}


