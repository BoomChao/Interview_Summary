

/*
    面试题27:二叉树的镜像 (Leetcode第226题)
    输入一颗二叉树,完成它的镜像输出
*/

//思路:
//1.先前序遍历二叉树的节点,如果遍历到的节点有子节点,则交换它的两个子节点
//2.当交换完所有的非叶节点的左右节点之后,就得到了数的镜像


struct binaryTreeNode{
    int val;
    binaryTreeNode *left;
    binaryTreeNode *right;

};


void mirrorRecursively(binaryTreeNode *pNode)
{
    if(pNode == nullptr) return;

    //遍历到了叶子节点
    if(pNode->left == nullptr && p->right == nullptr) return;

    //将左右节点交换
    binaryTreeNode *tmp = pNode->left;
    binaryTreeNode pNode->left = pNode->right;
    binaryTreeNode pNode->right = tmp;

    //遍历左子树
    if(pNode->left != nullptr){
        mirrorRecursively(pNode->left);
    }

    //遍历右子树
    if(pNode->right != nullptr){
        mirrorRecursively(pNode->right);
    }

}