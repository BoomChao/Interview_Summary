

//Leetcode第104题:判断二叉树的深度

//方法一:使用递归
//思路:参考<剑指>面试题55

int maxDepth(TreeNode *root)
{
    return maxDepthCore(root);
}

int maxDepthCore(TreeNode *root)
{
    if(root == nullptr) return 0;

    int depthLeft = maxDepthCore(root->left);
    int depthRight = maxDepthCore(root->right);

    return (depthLeft > depthRight) ? (depthLeft + 1) : (depthRight + 1);
}



//方法二:使用迭代

int maxDepth(TreeNode *root)
{
    if(root == nullptr) return 0;

    int res = 0;
    std::queue<TreeNode*> que;
    que.push(root);

    while(!que.empty())
    {
        ++res;
        int n = que.size();         //上面这两行的写法一定要注意
        for(int i = 0; i < n; i++)
        {
            TreeNode *pNode = que.front();
            que.pop();

            if(pNode->left != nullptr) {
                que.push(pNode->left);
            }

            if(pNode->right != nullptr) {
                que.push(pNode->right);
            }
        }

    }

    return res;
}


//更加简洁的一行代码
int maxDepth(TreeNode* root) 
{
    return root ? 1 + std::max(maxDepth(root->left), maxDepth(root->right)) : 0;
}