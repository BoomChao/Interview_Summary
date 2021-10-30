

//Leetcode第117题:Populating Next Right Pointers in Each Node II
//填充每一个节点的下一个右侧节点指针(该题的树不是满二叉树)


//思路:基本和上一题类似
//递归的话需要判断左右节点是否存在,要连接到next存在的一个节点,因此每次都要先连右边的节点,从后往前连



Node* connect(Node *root)
{
    connectCore(root);
    
    return root;
}

void connectCore(Node *root)
{
    if(root == nullptr) return;

    Node *pNext = root->next;
    while(pNext != nullptr) 
    {
        if(pNext->left != nullptr) {
            pNext = pNext->left;
            break;
        }
        if(pNext->right != nullptr) {
            pNext = pNext->right;
            break;
        }

        pNext = pNext->next;
    }

    if(root->right != nullptr) root->right->next = pNext;
    if(root->left != nullptr) root->left->next = (root->right) ? root->right : pNext;

    connectCore(root->right);
    connectCore(root->left);

    return;

}