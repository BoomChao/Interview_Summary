

/*
    面试题28:对称的二叉树
    判断一颗二叉树是否和它的镜像相同
*/


//思路:二叉树的镜像是将左右子节点交换得来的
//也就是说如果我们先遍历二叉树的右子节点再遍历左子节点,如果得到的序列和前序遍历的序列一样就说明这颗二叉树是对称的;
//反之有一个节点不一样则不是对称的
//需要注意的是nullptr指针也要考虑进去


struct binaryTreeNode{
    int val;
    binaryTreeNode *left;
    binaryTreeNode *right;

};


bool isSymmetric(binaryTreeNode *pRoot)
{
    return isSymmetricCore(pRoot, pRoot);

}

bool isSymmetricCore(binaryTreeNode *pRoot1, binaryTreeNode *pRoot2)
{
    if(pRoot1 == nullptr && pRoot2 == nullptr) return true;

    if(pRoot1 == nullptr || pRoot2 == nullptr) return false;

    if(pRoot1->val != pRoot2->val) return false;

    return isSymmetricCore(pRoot1->left, pRoot2->right) && isSymmetricCore(pRoot1->right, pRoot2->left);

}
