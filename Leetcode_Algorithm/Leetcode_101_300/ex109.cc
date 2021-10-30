

//Leetcode第109题:Convert Sorted List to Binary Search Tree
//将排序链表转换成平衡二叉树

//思路:先利用快慢指针找到链表的中间节点,该节点就是平衡二叉树的根节点,这样链表的
//左半部分属于左子树,右半部分就属于右子树
//对左半部分链表,依旧利用快慢指针找到根节点,右半部分依然如此;如此递归即可


TreeNode* sortedListToBST(ListNode *head)
{
    return sortedListToBSTCore(head, nullptr);
}

TreeNode* sortedListToBSTCore(ListNode *head, ListNode *tail)
{
    if(head == tail) {
        return nullptr;
    }

    //利用快慢指针找到链表中间节点
    ListNode *mid = head;
    ListNode *fast = head;
    while(fast != tail && fast->next != tail) {
        mid = mid->next;
        fast = fast->next->next;
    }

    TreeNode *root = new TreeNode(mid->val);
    root->left = sortedListToBSTCore(head, mid);
    root->right = sortedListToBSTCore(mid->next, tail);

    return root;

}