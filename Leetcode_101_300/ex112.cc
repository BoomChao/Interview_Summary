

//Leetcode第112题:Path Sum
//判断二叉树是否存在一条从根节点到叶子节点的路径其和等于给定的sum

//思路:
//我们每经过一个节点就判断一下sum是否等于当前节点的值,如果等于当前节点的值,并且当前节点还是叶子节点,则返回true
//否则将sum减去当前节点的值作为新的sum与当前节点的子节点进行比较,如果遍历到了叶子节点sum还不等于节点值,返回false


bool hasPathSum(TreeNode *root, int sum)
{
    return hasPathSumCore(root, sum);
}

bool hasPathSumCore(TreeNode *root, int sum)
{
    //遍历过了叶子节点还没找到,直接返回false
    if(root == nullptr) return false;

    //判断该节点是否是叶子节点,如果是叶子节点并且和等于sum,则表示找到了一条路径
    if(root->val == sum && root->left == nullptr && root->right == nullptr) return true;

    //否则继续往下搜索
    return hasPathSumCore(root->left, sum-root->val) || hasPathSumCore(root->right, sum-root->val);

}