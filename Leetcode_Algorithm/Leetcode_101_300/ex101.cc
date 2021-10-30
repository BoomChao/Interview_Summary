

//Leetcode第101题:Symetric Tree
//判断二叉树是否镜像对称


bool isSymmetric(TreeNode *root)
{
    if(root == nullptr) return true;

    isSymmetricCore(root, root);

}

bool isSymmetricCore(TreeNode *pRoot1, *pRoot2)
{
    if(pRoot1 == nullptr && pRoot2 == nullptr) return true;

    if(pRoot1 == nullptr || pRoot2 == nullptr) return false;

    if(pRoot1->val != pRoot2->val) return false;

    return isSymmetricCore(pRoot1->left, pRoot2->right) && isSymmetricCore(pRoot1->right, pRoot2->left);

}