


//Leetcode第222题:Count Complete Tree Nodes
//计算特殊二叉树的节点总数


int countNodes(TreeNode *root)
{
    if(root == nullptr) return 0;

    int heightLeft = 0, heightRight = 0;

    TreeNode *pLeft = root;
    TreeNode *pRight = root;

    while(pLeft != nullptr)
    {
        heightLeft++;
        pLeft = pLeft->left;
    }

    while(pRight != nullptr)
    {
        heightRight++;
        pRight = pRight->right;
    }

    //判断是否为满二叉树
    if(heightLeft == heightRight) {
        return (int)(pow(2,heightLeft)) - 1;
    }

    //不是满二叉树就递归计算
    return 1 + countNodes(root->left) + countNodes(root->right);

}