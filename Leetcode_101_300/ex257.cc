


//Leetcode第257题:Binary Tree Path
//打印二叉树从根节点到叶子节点的所有路径

//递归(dfs)


std::vector<std::string> binaryTreePath(TreeNode *root)
{
    if(root == nullptr) return {};

    std::vector<std::string> res;

    binaryTreePathCore(root, std::to_string(root->val), res);

    return res;

}


void binaryTreePathCore(TreeNode *root, std::string path, std::vector<std::string> &res)
{
    if(root->left == nullptr && root->right == nullptr) {
        res.push_back(path);
        return;
    }

    if(root->left != nullptr) {
        binaryTreePathCore(root->left, path + "->" + std::to_string(root->left->val), res);
    }

    if(root->right != nullptr) {
        binaryTreePathCore(root->right, path + "->" + std::to_string(root->right->val), res);
    }

}
