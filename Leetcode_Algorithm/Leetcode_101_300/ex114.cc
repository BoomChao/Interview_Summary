

//Leetcode第114题:Flatten Binary Tree to Linked List
//将二叉树调整成链表
//注:这里题目是利用二叉树的右指针来链接成链表

//思路:后序遍历
//1.先将右子树的值赋值给一个临时变量
//2.再将左子树的值赋值给右子树,将左子树置为NULL
//3.遍历右子树,找到最后一个右子树,再把temp赋值给该右子树


void flatten(TreeNode *root)
{
    flattenCore(root);

}


void flattenCore(TreeNode *root)
{
    if(root == nullptr) return;

    flatten(root->left);
    flatten(root->right);

    TreeNode *temp = root->right;
    root->right = root->left;
    root->left = nullptr;

    while(root->right != nullptr) {
        root = root->right;
    }
    root->right = temp;

    return;

}