
/*
    链表 P56
*/

struct ListNode{
    int val;
    ListNode *next;

};


//向链表末尾添加一个新节点
void addToTail(ListNode **head, int value)
{
    ListNode *pNew = new ListNode();
    pNew->val = value;
    pNew->next = nullptr;

    if(*head == nullptr){
        *head = pNew;
    }
    else{
        ListNode *pNode = *head;
        while(pNode->next != nullptr){
            pNode = pNode->next;
        }
        pNode->next = pNew;

    }

}



//在链表中找到第一个含有某值的节点并删除该节点

void removeNode(ListNode **head, int value)
{
    if(head == nullptr || *head == nullptr) return;     //空链表直接返回

    ListNode *pToBeDeleted = nullptr;
    
    if((*head)->val == value){  //头指针就是要删除的节点
        pToBeDeleted = *head;
        *head = *head->next;    
    }
    else{
        ListNode *pNode = *head;
        while(pNode->next != nullptr && pNode->next->val != value){
            pNode = pNode->next;
        }
        if(pNode->next != nullptr && pNode->next->val == value){
            pToBeDeleted = p->next;
            pNode->next = pNode->next->next;
        }

    }

    if(pToBeDeleted != nullptr){    //表示找到了待删除节点
        delete pToBeDeleted;        //如果链表中没找到要删除的节点,则不做任何操作
        pToBeDeleted = nullptr;
    }

}


