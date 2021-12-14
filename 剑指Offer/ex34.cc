

/*
    面试题34:二叉树和为某一值的路径
    打印二叉树中节点值的和为输入整数的所有路径;从树的根节点开始往下一直到叶节点所经过的节点形成一条路径
*/


struct binaryTreeNode{
    int val;
    binaryTreeNode *left;
    binaryTreeNode *right;

};


void findPath(binaryTreeNode *root, int expectedSum)
{
    if(root == nullptr) return;

    std::vector<int> path;
    int currentSum = 0;
    
    findPathCore()

};

void findPathCore(binaryTreeNode *root, int expectedSum, std::vector<int> &path, int currentSum)
{
    //将当前遍历的节点加入到路径中
    currentSum += root->val;
    path.push_back(root->val);

    //如果是叶节点,并且这条路径上节点值的和等于输入的值
    //那么就打印这条路径
    bool isLeaf = (root->left == nullptr) && (root->right == nullptr);
    if(currentSum == expectedSum && isLeaf)
    {
        std::cout << "A path is founded: ";
        for(auto num : path) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

    }

    //如果不是叶节点,则遍历它的子节点
    if(root->left != nullptr) {
        findPathCore(root->left, expectedSum, path, currentSum);
    } 

    if(root->right != nullptr) {
        findPathCore(root->right, expectedSum, path, currentSum);
    }

    //返回父节点之前,在路径上删除当前节点
    path.pop_back();

}