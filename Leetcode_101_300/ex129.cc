

//Leetcode第129题:Sum Root to Leaf Number
//计算根节点到所有叶子节点的总和

//思路:前序遍历,该节点不是叶子节点就将之前的值*10加上当前节点的值
//否则到了叶子节点则返回和sum


int sumNumbers(TreeNode *root)
{


}

int sumNumbersCore(TreeNode *root, int cur)
{    
    if(root == nullptr) return 0;

    int sum = cur*10 + root->val;

    if(root->left == nullptr && root->right == nullptr) return sum;

    return sumNumbersCore(root->left, sum) + sumNumbersCore(root->right, sum);

}