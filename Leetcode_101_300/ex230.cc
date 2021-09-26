


//Leetcode第230题:Kth Smallest Element in a BST
//找到二叉搜索树的第k大节点


//方法一:使用递归(参考<剑指>面试题54)
//按照中序遍历

int kthSmallest(TreeNode *root, int k)
{
    return kthSmallestCore(TreeNode, k)->val;
}

TreeNode* kthSmallestCore(TreeNode *root, int &k)
{
    TreeNode *target = nullptr;

    if(root->left != nullptr) {
        target = kthSmallestCore(root->left, k);
    }

    if(target == nullptr)
    {
        if(k == 1) target = root;
        k--;
    }

    if(target == nullptr && root->right != nullptr) {
        target = kthSmallestCore(root->right, k);
    }

    return target;

}


//方法二:使用迭代
//利用栈

int kthSmallest(TreeNode *root, int k)
{
    std::stack<TreeNode*> sta;
    TreeNode *pNode = root;

    while(pNode != nullptr || !sta.empty())
    {
        while(pNode != nullptr) {
            sta.push(pNode);
            pNode = pNode->left;
        }

        pNode = sta.top();;
        if(--k == 0) {
            return pNode->val;
        }
        sta.pop();

        pNode = pNode->right;
    }

}