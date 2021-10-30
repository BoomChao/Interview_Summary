
//Leetcode第19题
//Remove Nth Node From End of List : 删除链表的倒数第n个元素


//思路:
//1.利用快慢指针,让快指针和慢指针差n个元素,则当快指针指到末尾时,慢指针指到倒数第n+1元素
//2.向将快指针移动n位,之后让快慢指针同时移动直到快指针到达末尾
//3.将慢指针的下一个元素指向改为指向下下一个元素,这样就删除掉了倒数第n个元素


#include <iostream>
int main(){

    return 0;
}

//单链表的定义
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};





//利用快慢指针,删除完的节点需要delete释放内存

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode *fast = head;
    ListNode *slow = head;

    for(int i = 0; i < n; i++) {
        if(fast == nullptr) return nullptr;  //说明节点都不够n个
        fast = fast->next;
    }

    if(fast == nullptr) {
        ListNode *res = head->next;
        delete head;
        return res;
    }

    while(fast->next != nullptr){
        fast = fast->next;
        slow = slow->next;
    }

    ListNode *tmp = slow->next;

    slow->next = slow->next->next;

    delete tmp;

    return head;

}