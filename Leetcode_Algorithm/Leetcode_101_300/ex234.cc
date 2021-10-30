


//Leetcode第234题:Palindrome Linked List
//判断链表是否为回文链表

//两种方法


//方法一:使用vector (不推荐使用这种方法)
//时间复杂度为O(n+logn),空间复杂度为O(n)

bool isPalindrome(ListNode *head)
{
    std::vector<int> res;

    while(head != nullptr)
    {
        res.push_back(head->val);
        head = head->next;
    }

    int n = res.size();
    for(int i = 0,j = n-1; i < j; i++,j--)
    {
        if(res[i] != res[j]) {
            return false;
        }
    }

    return true;
}


//方法二:翻转链表的后半部分(将链表断开),之后首尾比较
//时间复杂度O(n),空间复杂度O(1)

//注意:这种方法会更改原始链表,面试官可能要求不能更改原始链表,那么我们可以照样更改,之后在主函数内部将链表复原即可


bool isPalindrome(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return true;

    //翻转链表的后半部分
    ListNode *last = reverseList(findSecondBegin(head));

    while(last != nullptr && head != nullptr)
    {
        if(last->val != head->val) {
            return false;
        }

        last = last->next;
        head = head->next;
    }

    return true;

}


//找到后半部分链表的开始节点
ListNode* findSecondBegin(ListNode *head)
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


//翻转链表
ListNode* reverseList(ListNode *head)
{
    ListNode *pre = nullptr;
    ListNode *cur = head;

    while(cur != nullptr)
    {
        ListNode *pNext = cur->next;
        cur->next = pre;
        pre = cur;
        cur = pNext;
    }

    return pre;
}



//方法三:对上面方法的优化
//先利用快慢指针找到链表中点,再把链表切成两半;然后把后半段翻转,最后比较两半是否相等

bool isPalindrome(ListNode *head)
{
    // 链表为空或者只有一个元素则直接返回true
    if(head == nullptr || head->next == nullptr) {
        return true;
    }

    ListNode *slow = head, *fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr) {   // 注意返回链表中间节点有两种写法
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverseList(slow->next);
    slow = slow->next;
    while(slow != nullptr) 
    {
        if(head->val != slow->val) {
            return false;
        }
        head = head->next;
        slow = slow->next;
    }

    return true;
}

ListNode* reverseList(ListNode *head)
{
    ListNode *prev = nullptr, *pNext = nullptr;

    while(head != nullptr) 
    {
        pNext = head->next;
        head->next = prev;
        prev = head;
        head = pNext;
    }

    return prev;
}






