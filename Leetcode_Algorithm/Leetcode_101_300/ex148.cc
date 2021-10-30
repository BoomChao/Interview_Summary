

//Leetcode第148题: Sort List
//排序链表

//题目要求的时间复杂度为O(nlogn)
//时间复杂度为O(nlogn)的排序算法只有快排,堆排序,以及归并排序
//快速是在数组中进行交换操作,不适用于链表
//可选的只有堆排序和归并排序
//归并排序比较好实现

//注意:归并排序并不是常量内存

ListNode* sortList(ListNode *head)
{
    return sortListCore(head);

}


ListNode* sortListCore(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return head;

    //快慢指针寻找链表中间节点
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = nullptr;
    while(fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = nullptr;

    /*
    需要注意这里切分链表进行递归时,对于奇数个数链表,则后半部分比前半部分多一个
    对于偶数个数链表,前后部分要求个数相同
    如果不定义prev,则对于 {4,3,2,1} 则前半部分为{4,3,2},后半部分为{1}
    再次递归,对于{4,3,2},其前半部分为{4,3},后半部分为{2}
    再次递归,对于{4,3},其前半部分为{4,3},后半部分为空,这样就会形成死循环导致栈溢出
    所以才需要定义pre,将链表从slow处切断,使得slow为右半部分头结点
    */
    ListNode *head1 = sortListCore(head);
    ListNode *head2 = sortListCore(slow);

    return merge(head1, head2);

}


ListNode* merge(ListNode *head1, ListNode *head2)
{
    ListNode *preHead = new ListNode(-1);
    ListNode *cur = preHead;

    while(head1 != nullptr && head2 != nullptr)
    {
        if(head1->val < head2->val) {
            cur->next = head1;
            head1 = head1->next;
        }
        else {
            cur->next = head2;
            head2 = head2->next;
        }

        cur = cur->next;
    }

    if(head1 != nullptr) {
        cur->next = head1;
    }

    if(head2 != nullptr) {
        cur->next = head2;
    }

    return preHead->next;
}



//方法二:采用插入排序的方法
ListNode *sortList(ListNode *head)
{
    if(head == nullptr) return head;

    ListNode *dummy = new ListNode(-1);
    dummy->next = head;

    ListNode *pCur = head;
    ListNode *pNex = head->next;
    ListNode *pTmp = head;

    while(pNex)
    {
        if(pCur->val <= pNex->val) {
            pCur = pCur->next;
            pNex = pNex->next;
            continue;   
        }

        //上述的if语句也可以改成while循环如下
        /*
        while(pCur->val <= pNex->val) {
            pCur = pCur->next;
            pNex = pNex->next;
            if(pNex == nullptr) return dummy->next;
        }
        */


        //找到新元素的插入位置
        pTmp = dummy;   
        while(pTmp->next->val <= pNex->val) {
            pTmp = pTmp->next;
        }

        pCur->next = pNex->next;
        pNex->next = pTmp->next;
        pTmp->next = pNex;

        pNex = pCur->next;
    }

    return dummy->next;
}

