

//Leetcode第99题:Recover Binary Tree : 复原二叉搜索树
//二叉搜索树存在两个节点被错误的交换了.请复原该二叉搜索树


//思路:二叉搜索树的中序遍历为递增序列
//1.中序遍历找到第一个比前一个节点小的值,将该节点前一个节点保存下来记为pFirst
//2.继续遍历找到比前一个节点小的值,保存下来记为pSecond,更新pSecond直到遍历结束

//如对中序遍历序列 3 2 1 第一个比前一个节点小的节点为2,则pFirst=3,pSecond=2,但是后面的1还比2小,则pSecond=2
//如对中序遍历序列 1 3 2 4 第一个比前一个节点小的节点为2,则pFirst=3,pSenond=2,后面的4比2大,则pSecond不需要更新


//pFirst和pSecond为需要交换的节点,注意只需交换节点的值,指向不用改变
//preRoot为上一个根节点,也就是中序遍历的上一个节点
TreeNode *pFirst = nullptr;
TreeNode *pSecond = nullptr;
TreeNode *preRoot = nullptr;


void recoverTree(TreeNode *root)
{
    recoverTreeCore(root);

    std::swap(pFirst->val, pSecond->val);

}

void recoverTreeCore(TreeNode *root)
{
    if(root == nullptr) return;

    recoverTreeCore(root->left)

    if(preRoot != nullptr && root->val < preRoot->val) {
        if(pFirst == nullptr) pFirst = preRoot;
        pSecond = root;
    }

    preRoot = root;

    recoverTreeCore(root->right);

}