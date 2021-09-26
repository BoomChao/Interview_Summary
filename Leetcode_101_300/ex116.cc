

//Leetcode第116题:Populating Next Right Pointers in Each Node 
//填充每一个节点的下一个右侧节点指针(该题的树是满二叉树)

//思路:采用递归,类似于前序遍历
//每个node的左节点的next就是该node的右节点
//每个node的右节点的next就是该node->next的左节点;如果node->next为空,则该node的右节点的next也为空


Node* connect(Node *root)
{
    connectCore(root, nullptr);

    return root;
}

//这里返回值为空,因为返回的是根节点
void connectCore(Node *root, Node *next)
{
    if(root == nullptr) return;

    //先处理根节点的next
    root->next = next;
    connectCore(root->left, root->right);
    connectCore(root->right, !(root->next) ? nullptr : root->next->left);    //需要先判断一下该节点的next是否为空

    return;

}