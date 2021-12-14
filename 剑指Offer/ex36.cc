

/*
    面试题36:二叉搜索树转换成双向链表
*/

struct binaryTreeNode{
    int val;
    binaryTreeNode *left;
    binaryTreeNode *right;

};

binaryTreeNode* convert(binaryTreeNode *pRootOfTree)
{
    binaryTreeNode *pLastNodeInList = nullptr;
    convertNode(pRootOfTree, &pLastNodeInList);

    //pLastNodeInList指向的是双向链表的尾节点
    //我们需要返回头结点
    binaryTreeNode *pHeadOfList = pLastNodeInList;
    while(pHeadOfList != nullptr && pHeadOfList->left != nullptr) {
        pHeadOfList = pHeadOfList->left;
    }

    return pHeadOfList;

}


void convertNode(binaryTreeNode *pNode, binaryTreeNode **pLastNodeInList)
{
    if(pNode == nullptr) return;

    binaryTreeNode *pCurrent = pNode;
    if(pCurrent->left != nullptr) {
        convertNode(pCurrent->left, pLastNodeInList);
    }

    pCurrent->left = *pLastNodeInList;
    if(*pLastNodeInList != nullptr) {
        (*pLastNodeInList)->right = pCurrent;
    }

    *pLastNodeInList = pCurrent;

    if(pCurrent->right != nullptr) {
        convertNode(pCurrent->right, pLastNodeInList);
    }

}

