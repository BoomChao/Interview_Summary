

/*
    面试题6:输入链表的头结点,从尾到头打印每个节点的值
*/


#include <stack>

struct ListNode
{
    int value;
    ListNode *next;
};


//方法一:使用栈
void PrintListReversingly_Iteratively(ListNode *pHead)
{
    std::stack<ListNode*> nodes;    //定义一个栈

    ListNode *pNode = pHead;
    while(pNode != NULL){   //将链表中的节点存入栈中
        nodes.push(pNode);
        pNode = pNode->next;
    }

    while(!nodes.empty()){
        pNode = nodes.top();
        std::cout << pNode->value << " ";
        nodes.pop();
    }

}




//方法二:使用递归
void PrintListReversingly_Recursively(ListNode *pHead)
{
    if(pHead != NULL){
        if(pHead->next != NULL){
            PrintListReversingly_Recursively(pHead->next);
        }
        std::cout << pHead->value;
    }


}
