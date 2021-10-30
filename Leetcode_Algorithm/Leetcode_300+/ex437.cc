

//Leetcode第437题 : Path Sum III
//判断二叉树中存在几条路径其和等于sum

int pathSum(TreeNode *root, int sum)
{
    if(root == nullptr) return 0;

    //遍历所有节点,是否存在从任意节点开始的路径和等于sum
    return rootSum(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);

}


//计算从当前节点开始是否存在路径等于指定的sum
//存在的话就返回1,不存在的话就返回0
int rootSum(TreeNode *root, int sum) 
{
    if(root == nullptr) return 0;

    return (sum == root->val) + rootSum(root->left, sum - root->val) + rootSum(root->right, sum - root->val);
}

