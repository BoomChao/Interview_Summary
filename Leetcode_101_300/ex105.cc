

//Letcode第105题 : Construct Binary Tree From Preorder and Inorder Traversal
//根据前序和中序序列来重建二叉树

//参考<剑值>面试题7
//这是给出的数组是vector,所以解法会相对简单一点


TreeNode* buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
{
    //利用哈希表来存储中序遍历中元素出现的下标索引
    std::unordered_map<int, int> inorderPos;
    for(int i = 0; i < inorder.size(); i++) {
        inorderPos[inorder[i]] = i;
    }

    return buildTreeCore(preorder, 0, preorder.size()-1, 0, inorderPos);
}

TreeNode* buildTreeCore(std::vector<int> &preorder, int startPreorder, int endPreorder, int startInOrder, std::unordered_map<int, int> &inorderPos)
{
    if(startPreorder > endPreorder) return nullptr;

    TreeNode *root = new TreeNode(preorder[startPreorder]);
    //注:root->left = nullptr,或者root->right = nullptr加不加都可以,因为TreeNode有构造函数

    //找到根节点在中序遍历序列中的位置
    int rootIndex = inorderPos[preorder[startPreorder]];

    //左子树的长度
    int leftLen = rootIndex - startInOrder;

    root->left = buildTreeCore(preorder, startPreorder + 1, startPreorder + leftLen, startInOrder, inorderPos);

    root->right = buildTreeCore(preorder, startPreorder + leftLen + 1, endPreorder, rootIndex + 1, inorderPos);

    return root;
}