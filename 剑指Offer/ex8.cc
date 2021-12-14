

/*
    面试题8:二叉树的下一个节点  
    找出中序遍历序列的下一个节点
    //题目出的非常好
*/

//思路:分两种情况
//1.如果节点有右子树,则其下一个节点就是它的右子树的最左子节点
//2.1.如果节点没有右子树,并且该节点是它父节点的左子节点,则其下一个节点就是它的父节点
//2.2.如果节点没有右子树,并且该节点是它父节点的右子节点,则需要沿着指向父节点的指针一直往上遍历,直到找到一个是它父节点的左子节点的节点;那这个父节点就是我们要找的目标节点



struct binaryTreeNode {
    int val;
    binaryTreeNode *left;
    binaryTreeNode *right;
    binaryTreeNode *parent;

};


binaryTreeNode* getNext(binaryTreeNode *pNode)
{
    if(pNode == nullptr) return nullptr;

    binaryTreeNode *pNext = nullptr;

    //存在右子树,则下一个节点是右子树的最左子节点
    if(pNode->right != nullptr) 
    {
        binaryTreeNode *pRight = pNode->right;
        while(pRight != nullptr) {
            pRight = pRight->left;
        }

        pNext = pRight;
  
    }

    //不存在右子树但是存在父节点(注意:只有根节点不存在父节点)
    else if(pNode->parent != nullptr)
    {
        binaryTreeNode *pCurrent = pNode;
        binaryTreeNode *pParent = pNode->parent;
        
        //不存在右子树并且该节点为父节点的右节点,则一直往上搜索
        while(pParent != nullptr && pCurrent == pParent->right) 
        {
            pCurrent = pParent;
            pParent = pParent->parent;
        }

        pNext = pParent;

    }

    return pNext;
}



TreeNode* getNextNode(TreeNode *node)
{
    if(node == nullptr) return nullptr;

    //存在右子树
    if(node->right) {
        TreeNode *pNext = node->right;
        while(pNext->left) {
            pNext = pNext->left;
        }
        return pNext;
    }

    if(node->parent) {
        TreeNode *pParent = node->parent;
        if(node == pParent->left) {          //不存在右子树,且是父节点的左孩子
            return pParent;
        }
        else {      //父节点的右孩子
            TreeNode *pCur = node;
            while(parent && pCur == pParent->right) {    //一直往上找到一个是父节点左孩子的节点
                pCur = pParent;
                pParent = pParent->parent;
            }
            return pParent;
        }
    }

    //其他情况返回空指针
    return nullptr;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
};

TreeNode *GetNextNode(TreeNode *pNode)
{
    if(pNode == nullptr) return pNode;

    if(pNode->right)    //存在右子树,则下一个节点为右子数的最左子节点
    {
        TreeNode *pNext = pNode->right;
        while(pNext->left) {
            pNext = pNext->left;
        }

        return pNext;
    }
    else if(pNode->parent)
    {
        //不存在右子树
        TreeNode *pParent = pNode->parent;
        if(pNode == pParent->left) {    //当前节点是父节点的左子节点,则下一个节点就是父节点
            return pParent;
        }

        //当前节点是父节点的右子节点,则一直往上找到一颗节点为父节点的左子节点,则这个父节点就是下一个节点
        while(pParent && pNode == pParent->left)
        {
            pNode = pParent;
            pParent = pParent->parent;
        }
        return pParent;
    }

    //不存在右子树且不存在父节点,说明是根节点,直接返回nullptr
    return nullptr; 
}

