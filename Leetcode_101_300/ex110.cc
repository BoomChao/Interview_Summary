

//Leetcode第110题:Balanced Binary Tree
//判断一棵树是否为平衡二叉树

//思路:先确定左右子树的深度,将其作差即可得平衡因子,判断平衡因子是否大于1


bool isBalanced(TreeNode *root)
{
    isBalancedCore(root);
}


//方法一:这种方法存在多个节点重复遍历的情况

bool isBalancedCore(TreeNode *root)
{
    if(root == nullptr) return true;

    if(abs(depthOfTree(root->left) - depthOfTree(root->right)) > 1) return false;

    return isBalanced(root->left) && (root->right);

}

int depthOfTree(TreeNode *root)
{
    if(root == nullptr) return 0;

    int depthLeft = depthOfTree(root->left);
    int depthRight = depthOfTree(root->right);

    return (depthLeft > depthRight) ? (depthLeft + 1) : (depthRight + 1);

}


//方法二:
//采用后序遍历每次只需要遍历每个节点一次即可

bool isBalanced(TreeNode *root)
{
    int depth = 0;
    return isBalancedCore(root, depth);
}

bool isBalancedCore(TreeNode *root, int &depth)
{
    if(root == nullptr) {
        depth = 0;
        return true;
    }

    int left, right;
    if(isBalancedCore(root->left, left) && isBalancedCore(root->right, right))
    {
        int diff = left - right;
        if(diff >= -1 && diff <= 1) {
            depth = 1 + (left > right ? left : right);      //注意这个逻辑运算符不要写成 1+(left ? right)?left:right; (>?:)这个三母运算符要写在一起,放在一个括号里面
            return true;
        }
    }

    return false;

}
