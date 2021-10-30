

//Leetcode第124题:Binary Tree Maximum Path Sum
//返回二叉树路径最大和,路径不一定要经过根节点

int maxPathSum(TreeNode *root)
{
    if(root == nullptr) return 0;

    int res = INT_MIN;
    maxPathSumCore(root, res);

    return res;

}

int maxPathSumCore(TreeNode *root, int &res)
{
    if(root == nullptr) return 0;

    int leftMax = std::max(0, maxPathSumCore(root->left, res));
    int rightMax = std::max(0, maxPathSumCore(root->right, res));

    res = std::max(res, root->val + leftMax + rightMax);

    //这里选择的是根,根+左/右,两者之间的较大值,代表root为根节点的树对上层的贡献
    //为什么不是根+左+右,因为这里找的是路径,返回根+左+右那么根的上层节点到了这一层就没办法不重复的遍历三个节点
    return std::max(root->val, root->val + std::max(leftMax, rightMax));

}