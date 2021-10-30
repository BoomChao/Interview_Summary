

//Leetcode第111题:Minimun Depth of Binary Tree
//计算二叉树根节点到叶子节点的最小深度

//与第104题作对比,104题是计算二叉树的深度

int minDepth(TreeNode *root)
{
    return minDepthCore(root);

}

int minDepthCore(TreeNode *root)
{
    //说明遍历到了叶子节点的左右节点,叶子节点左右节点为空,直接返回0
    if(root == nullptr) return 0;

    //该节点的左节点为空,则该节点的最小深度一定是右节点的深度+1
    if(root->left != nullptr) return 1 + minDepthCore(root->right);

    //该节点的右节点为空,则该节点的最小深度一定是左节点的深度+1
    if(root->right != nullptr) return 1 + minDepthCore(root->left);

    //如果该节点左右节点均存在,则节点深度为最小的节点的深度+1
    return 1 + min(minDepthCore(root->left), minDepthCore(root->right));

}


