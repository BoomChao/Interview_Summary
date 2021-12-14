

/*
    面试题54:二叉搜索树的第k大节点
    考察中序遍历
*/


struct binaryTeeNode{
    int value;
    binaryTeeNode *pLeft;
    binaryTeeNode *pRight;
};


binaryTeeNode* kthNode(binaryTeeNode *pRoot, unsigned int k)
{
    if(pRoot == nullptr || k == 0) return nullptr;

    return kthNodeCore(pRoot, k);

}


binaryTeeNode *kthNodeCore(binaryTeeNode *pRoot, unsigned int &k)
{
    binaryTeeNode *target = nullptr;
    if(pRoot->pLeft != nullptr) {
        target = kthNodeCore(pRoot->left, k);
    }

    if(target == nullptr)
    {
        if(k == 1) {
            target = pRoot;
        }

        k--;
    }

    if(target == nullptr && pRoot->pRight != nullptr) {
        target = kthNodeCore(pRoot->pRight, k);
    }

    return target;
}
