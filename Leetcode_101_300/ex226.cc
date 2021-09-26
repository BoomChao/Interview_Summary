

//Leetcode第226题:Invert Binary Tree (<剑指offer>面试题27)
//翻转二叉树(二叉树的镜像)

//思路:先遍历这个二叉树的每个节点,如果遍历到的节点有子节点,就交换它的两个子节点
//当交换完所有非叶节点的左右子节点之后,就得到了二叉树的镜像

TreeNode* invertTree(TreeNode *root)
{
    invertTreeCore(root);

    return root;
}


TreeNode* invertTreeCore(TreeNode *root)
{
    if(root == nullptr) return;

    if(root->left == nullptr && root->right == nullptr) return;

    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    if(root->left != nullptr) {
        invertTreeCore(root->left);
    }

    if(root->right != nullptr) {
        invertTreeCore(root->right);
    }

}

