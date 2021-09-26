

//Leetcode第100题:判断两个二叉树是否相同


bool isSameTree(TreeNode *p, TreeNode *q)
{
    return isSameTreeCore(p, q);

}



bool isSameTreeCore(TreeNode *p, TreeNode *q)
{
    if(p == nullptr || q == nullptr) return p == q;

    if(p->val != q->val) return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

}