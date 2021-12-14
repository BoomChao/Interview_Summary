

/*
    面试题55:二叉树的深度
*/


//思路:分情况
//1.二叉树只有一个根节点,则深度为1
//2.二叉树只有左子树没有右子树,则深度为左子树的深度+1
//3.二叉树只有右子树没有左子树,则深度为右子树的深度+1
//4.二叉树既有左子树又有右子树,则深度为左子树的深度+右子树的深度+1


struct binaryTreeNode{
    int val;
    binaryTreeNode *left;
    binaryTreeNode *right;

};


int treeDepth(binaryTreeNode *root)
{
    if(root == nullptr) return 0;

    int nLeft = treeDepth(root->left);
    int nRight = treeDepth(root->right);

    return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);

}



//附:判断一颗二叉树是不是平衡二叉树
//思路:也可以按照上面计算二叉树的深度代码来实现;但是存在一个节点需要遍历多次
//如果采用后序遍历,那么每个节点只需遍历一次,边遍历边记录每个节点的深度

bool isBalanced(binaryTreeNode *root)
{
    int depth = 0;

    return isBalancedCore(root, &depth);
}


bool isBalancedCore(binaryTreeNode *root, int *depth)
{
    if(root == nullptr) {
        *depth = 0;
        return true;
    }

    int left, right;
    if(isBalancedCore(root->left, &left) && isBalancedCore(root->right, &right))
    {
        int diff = left-right;
        if(diff <= 1 && diff >= -1) {
            *depth = 1 + (left > right) ? left : right;
            return true;
        }

    }

    return false;

}