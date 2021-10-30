

//Leetcode第94题
//Binary Tree Inorder Traversal : 二叉树的中序遍历


std::vector<int> inorderTraversal(TreeNode *root)
{
    if(root == nullptr) return {};

    std::vector<int> res;
    inorderTraverse(root, res);

    return res;

}


//方法一:使用递归

void inorderTraverse(TreeNode *root, std::vector<int> &res)
{
    if(root->left != nullptr){
        inorderTraverse(root->left, res);
    }
    
    res.push_bakc(root->val);
    
    if(root->right != nullptr){
        inorderTraverse(root->left, res);
    }

}


//方法二:使用循环(利用栈)

void inorderTraversal(TreeNode *root)
{
    std::vector<int> nodes;
    std::stack<TreeNode*> toVisit;

    while(1)
    {
        while(root != nullptr) {
            toVisit.push(root);
            root = root->left;
        }
        if(toVisit.empty()) break;

        TreeNode *tmp = toVisit.top();
        toVisit.pop();

        nodes.push_back(tmp->val);
        root = tmp->right;
    }

    return res;
}


//上面方法虽然是递归但是while(1)不太好,优化掉      (可以用此方法解决第230题:二叉树搜索树的最小的第k个数)
std::vector<int> inorderTraversal(TreeNode *root)
{
    std::vector<int> res;
    TreeNode *pNode = root;
    std::stack<TreeNode*> sta;

    while(pNode || !sta.empty())
    {
        while(pNode) {
            sta.push(pNode);
            pNode = pNode->left;
        }

        pNode = sta.top();
        res.push_back(pNode->val);
        sta.pop();

        pNode = pNode->right;
    }

    return res;
}