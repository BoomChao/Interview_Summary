

//Leetcode第143题 : Reorder List
//重排链表



//解法一:这种解法会超时
//思路:先找到链表中间节点,从中点节处断开,翻转中点之后的链表,再合并两个链表成目标链表
//这里的合并不是按照链表数值升序合并,而是每个链表轮流取一个元素合并

void reorderList(ListNode *head)
{
    //链表为空,或者只有一个或者两个元素,则直接返回
    if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return;

    //找到中间节点
    ListNode *mid = findMiddleNode(head);

    //从中点处断开分开为两个链表
    ListNode *leftHead = head;
    ListNode *rightHead = mid->next;
    mid->next = nullptr;

    //将右半侧链表翻转
    rightHead = reverList(rightHead);

    //开始遍历两个链表并开始合并
    ListNode *pLeft = leftHead;
    ListNode *pRight = rightHead;
    while(pLeft != nullptr && pRight != nullptr)
    {
        ListNode *tmpLeft = pLeft->next;    //暂存左链表的下一个节点
        ListNode *tmpRight = pRight->next;  //暂存右链表的下一个节点
        pLeft->next = pRight;               //左链表指向右链表
        pRight->next = tmpLeft;             //右链表指向左链表暂存节点
        
        //指针后移
        pLeft = tmpLeft;
        pRight = tmpRight;
    }

}

ListNode* findMiddleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    whil(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;

}


TreeNode reverList(ListNode *head)
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



//解法二:把函数实现放在内部

void reorderList(ListNode *head)
{
    if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return;

    ListNode *slow = head;
    ListNode *fast = head;
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    //最后的slow就是中间节点

    //左链表的头节点为head,右链表的头结点为rightHead
    ListNode *rightHead = slow->next;
    slow->next = nullptr;

    //翻转第二个链表
    ListNode *tmp = rightHead->next;
    rightHead->next = nullptr;
    while(tmp != nullptr)
    {
        ListNode *last = tmp->next;
        tmp->next = rightHead;
        rightHead = tmp;
        tmp = last;
    }

    //开始遍历两个链表并开始合并
    ListNode *pLeft = head;
    ListNode *pRight = rightHead;
    while(pLeft != nullptr && pRight != nullptr)
    {
        ListNode *tmpLeft = pLeft->next;    //暂存左链表的下一个节点
        ListNode *tmpRight = pRight->next;  //暂存右链表的下一个节点
        pLeft->next = pRight;               //左链表指向右链表
        pRight->next = tmpLeft;             //右链表指向左链表暂存节点
        
        //指针后移
        pLeft = tmpLeft;
        pRight = tmpRight;
    }


}