

//Leetcode第24题 : Swap Nodes int Pairs
//交换链表中相邻的两个元素


//解法一:不推荐

//此题解法与23题中的合并n个有序链表的解法二的思想相同
//利用剥离的思想,从链表中抽离出来,将链表中的数据提取到向量中,在向量中将其相邻的元素交换好后
//再利用向量中交换好的数据重新生成一个链表


ListNode* swapPairs(ListNode* head)
{
    if(head == nullptr) return nullptr;

    std::vector<int> res;
    ListNode *temp = head;
    while(temp != nullptr){
        res.push_back(temp->val);
        temp = temp->next;
    }

    if(res.size() == 0) return nullptr;

    int i = 1;
    while(i < res.size()){
        swap(res[i],res[i-1]);
        i += 2;
    }

    ListNode *base = new ListNode(0);
    ListNode *newNode = base;
    for(int i = 0; i < res.size(); i++){
        newNode->next = new ListNode(res[i]);
        newNode = newNode->next;
    }

    return base->next;

}


void swap(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}



//解法二:直接在原链表上操作
//对指针的操作其实并不复杂,但是要非常细心

ListNode *swapPairs(ListNode *head)
{
    ListNode *p = head, *s = nullptr;

    if(p != nullptr && p->next != nullptr)
    {
        s = p->next;
        p->next = s->next;
        s->next = p;
        head = s;
        while(p->next != nullptr && p->next->next != nullptr) {
            s = p->next->next;
            p->next->next = s->next;
            s->next = p->next;
            p->next = s;
            p = s->next;
        }
    }

    return head;
}
