

//Leetcode第145题
//Binary Tree Postorder Traversal : 二叉树的后序遍历

//方法一:使用递归
std::vector<int> postorderTraversal(TreeNode *root)
{
    if(root == nullptr) return {};

    std::vector<int> res;
    postorderTraversal(root, res);

    return res;

}

void postorderTraversal(TreeNode *root, std::vector<int> &res)
{
    if(root->left != nullptr){
        postorderTraversal(root->left, res);
    }
        
    if(root->right != nullptr){
        postorderTraversal(root->left, res);
    }

    res.push_bakc(root->val);

}



//方法二:使用循环(利用栈实现)
vector<int> postorderTraversal(TreeNode* root) 
{
    vector<int> res;
    stack<TreeNode*> toVisit;
    
    if(root == nullptr) return res;
    toVisit.push(root);
    
    while(!toVisit.empty())
    {
        TreeNode *tmp = toVisit.top();
        res.push_back(tmp->val);
        toVisit.pop();
        
        if(tmp->left != nullptr) toVisit.push(tmp->left);
        if(tmp->right != nullptr) toVisit.push(tmp->right);
    } 
    
    reverse(res.begin(), res.end());
    
    return res;
}

