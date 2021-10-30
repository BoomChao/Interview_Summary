

//Leetcode第21题 : Merge Two Sorted List
//给出两个排好序的链表,合并这两个链表,要求合并后的链表元素依然有序


struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <iostream>

int main(){


    return 0;
}


//解法一:迭代解法

ListNode* mergeTwoLists(ListNode *L1, ListNode *L2)
{
    ListNode* base = new ListNode(0);
    ListNode* L3 = base;

    while(L1!=nullptr && L2!=nullptr)
    {
        if(L1->val < L2->val) 
        {
            L3->next = L1;
            L1 = L1->next;
        } else 
        {
            L3->next = L2;
            L2 = L2->next;
        }

        L3 = L3->next;
    }

    if(L1 != nullptr)   L3->next = L1;      //防止还有一个链表有剩余元素,此时直接将L3的下一个节点指向剩余的链表的第一个节点
    if(L2 != nullptr)   L3->next = L2;

    return base->next;
}


//上面迭代解法的优化

ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *base = new ListNode(0), *node = base;

    while(l1 != nullptr && l2 != nullptr) 
    {
        if(l1->val < l2->val) {
            node->next = l1;
            l1 = l1->next;
        }
        else {
            node->next = l2;
            l2 = l2->next;
        }
        
        node = node->next;
    }

    node->next = l1 ? l1 : l2;

    return base->next;
}



//解法二:递归解法
//参看剑指offer面试题第25题

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if(l1 == nullptr) return l2;    //l1为空,返回链表l2;
    else if(l2 == nullptr ) return l1;  

    if(l1->val < l2->val){
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else{
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }

}