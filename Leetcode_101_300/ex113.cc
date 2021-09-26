

//Leeetcode第113题 : Path Sum II
//返回树中路径和等于sum的所有路径

//思路:深度优先


std::vector<std::vector<int>> res;
std::vector<int> path;


std::vector<std::vector<int>> pahtSum(TreeNode*root, int sum)
{
    pahtSumCore(root, sum);

}

void pahtSumCore(TreeNode*root, int sum)
{
    if(root == nullptr) return;

    path.push_back(root->val);

    if(root->val == sum && root->left == nullptr && root->right == nullptr) {
        res.push_back(path);
        // return;          //注意:这里不能加上return
    }
    
    pahtSumCore(root->left, sum - root->val);
    pahtSumCore(root->right, sum - root->val);

    path.pop_back();

}