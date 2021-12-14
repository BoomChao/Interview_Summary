/*
    面试题35:复杂链表的复制
*/

//方法一:利用哈希表

//方法二:

struct ComplexListNode {
    int m_nVal;
    ComplexListNode *m_pNext;
    ComplexListNode *m_pSibling;
};


//第一步:
//复制原始链表的任意节点N并创建新的节点N'

void cloneNodes(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;
    while(pNode != nullptr)
    {
        ComplexListNode *pCloned = new ComplexListNode();
        pCloned->m_nVal = pNode->m_nVal;
        pCloned->m_pNext = pNode->m_pNext;
        pCloned->m_pSibling = nullptr;

        pNode->m_pNext = pCloned;
        pNode = pCloned->m_pNext;

    }

}

//第二步:
//如果原始链表上的节点N的m_pSilbing指向s,则它对应的复制节点N'的m_pSibling指向S的复制节点S'

void connectSiblingNodes(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;

    while(pNode != nullptr) 
    {
        ComplexListNode *pCloned = pNode->m_pNext;
        if(pNode->m_pSibling != nullptr) {
            pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
        }

        pNode = pCloned->m_pNext;
    }

}


//第三步:
//把第二步得到的长链表拆分成两个链表

ComplexListNode* reconnectNodes(ComplexListNode *pHead)
{
    ComplexListNode *pNode = pHead;
    ComplexListNode *pClonedHead = nullptr;
    ComplexListNode *pClonedNode = nullptr;

    if(pNode != nullptr) 
    {
        pClonedHead = pClonedNode = pNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }

    while(pNode != nullptr)
    {
        pClonedNode->m_pNext = pNode->m_pNext;
        pClonedNode = pClonedNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }

    return pClonedHead;

}



//把上面三步合并起来

ComplexListNode* clone(ComplexListNode *pHead)
{
    cloneNodes(pHead);
    connectSiblingNodes(pHead);
    
    return reconnectNodes(pHead);

}



//Leetcode第138题

//O(n)时间,O(n)空间
Node* copyRandomList(Node *head)
{
    if(head == nullptr) return head;

    Node *cur = head;
    std::unordered_map<Node*, Node*> hash;
    while(cur)
    {
        Node *copy = new Node(cur->val);
        hash[cur] = copy;
        cur = cur->next;
    }

    cur = head;
    while(cur)
    {
        hash[cur]->next = hash[cur->next];
        hash[cur]->random = hash[cur->random];
        cur = cur->next;
    }

    return hash[head];
}

//不使用哈希表
Node* copyRandomList(Node *head)
{
    if(head == nullptr) return head;

    //复制每个链表
    Node *cur = head;
    while(cur)
    {
        Node *pNext = cur->next;
        cur->next = new Node(cur->val);
        cur->next->next = pNext;
        cur = pNext;
    }

    //复制随机指针
    cur = head;
    while(cur)
    {
        if(cur->random != nullptr) {
            cur->next->random = cur->random->next;
        }
        cur = cur->next->next;
    }

    //提取出偶数编号的节点
    cur = head;
    Node *copyHead = head->next;
    Node *copy = copyHead;

    while(copy->next) {
        cur->next = cur->next->next;
        cur = cur->next;

        copy->next = copy->next->next;
        copy = copy->next;
    }

    cur->next = nullptr;

    return copyHead;
}