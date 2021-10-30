

//Leetcode第95题:Unique Binary Search Trees II
//给出一个数字n,生成1-n的所有的可能的二叉搜索树

//思路:这题是96题的升级版
//1.对于给定的数n,我们遍历0-n中的值,假设i为当前二叉搜索树的根,则序列被划分为(0,i-1)和(i+1,n)两部分
//2.递归调用这两部分,就可以获得所有可行的左子树和右子树
//3.最后我们先从左子树中集合中选一颗,再从右子树集合中选一颗拼接到根节点上即可


std::vector<TreeNode*> generateTrees(int n)
{
    if(n == 0) return {nullptr};

    return generateTreesCore(1, n);

}


std::vector<TreeNode*> generateTreesCore(int left, int right)
{
    if(left > right) return {nullptr};

    std::vector<TreeNode*> res;

    for(int i = left; i <= right; i++)
    {
        //获得左子树和右子树的集合
        std::vector<TreeNode*> leftNodes = generateTreesCore(left, i-1);
        std::vector<TreeNode*> rightNodes = generateTreesCore(i+1, right);

        //从左子树集合中选出一颗左子树,从右子树集合中选出一颗右子树.组合到根节点上形成二叉树
        for(TreeNode *left_node : leftNodes)
        {
            for(TreeNode *right_node : rightNodes)
            {
                TreeNode *root = new TreeNode(i);
                root->left = left_node;
                root->right = right_node;
                res.push_back(root);
            }

        }

    }

    return res;

}