

//Leetcode第144题
//Binary Tree Preorder Traversal : 二叉树的前序遍历



//方法一:利用递归
std::vector<int> preorderTraversal(TreeNode *root)
{
    if(root == nullptr) return {};

    std::vector<int> res;
    preorderTraversal(root, res);

    return res;

}

void preorderTraverse(TreeNode *root, std::vector<int> &res)
{
    res.push_bakc(root->val);

    if(root->left != nullptr){
        preorderTraversal(root->left, res);
    }
        
    if(root->right != nullptr){
        preorderTraversal(root->left, res);
    }

}



//方法二:利用迭代
vector<int> preorderTraversal(TreeNode* root) 
{
    std::vector<int> res;
    std::stack<TreeNode*> toVisit;
    
    if(root == nullptr) return res;
    toVisit.push(root);
    
    while(!toVisit.empty())
    {
        TreeNode *tmp = toVisit.top();
        toVisit.pop();
        
        res.push_back(tmp->val);
        
        if(tmp->right != nullptr) toVisit.push(tmp->right);
        if(tmp->left != nullptr) toVisit.push(tmp->left);
    }
    
    return res;
    
}
