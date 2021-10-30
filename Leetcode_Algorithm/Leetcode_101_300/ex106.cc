

//Leetcode第106题 : Construct Binary Tree From Inorder and Postorder Traversal
//根据中序和后序序列在重建二叉树

TreeNode* buildTree(std::vector<int> &inorder, std::vector<int> &postorder)
{
    //利用哈希表来存储中序遍历中元素出现的位置
    std::unordered_map<int, int> inorderPos;
    for(int i = 0; i < inorder.size(); i++) {
        inorderPos[inorder[i]] = i;
    }
    
    return buildTreeCore(postorder, 0, postorder.size()-1, 0, inorderPos);

}

TreeNode* buildTreeCore(std::vector<int> &postorder, int startPostorder, int endPostorder, int startInOrder, std::unordered_map<int, int> &inorderPos)
{
    if(startPostorder > endPostorder) return nullptr;

    TreeNode *root = new TreeNode(postorder[endPostorder]);

    int rootIndex = inorderPos[postorder[endPostorder]];

    //左子树的长度
    int leftLen = rootIndex - startInOrder;

    //注意这里不像前序遍历第一个元素是根节点,这里左子树的长度也包括第一个元素,所以左子树的后序遍历的最后一个元素为 startPostorder + (leftLen -1)
    root->left = buildTreeCore(postorder, startPostorder, startPostorder + leftLen - 1, startInOrder, inorderPos);

    root->right = buildTreeCore(postorder, startPostorder + leftLen, endPostorder - 1, rootIndex + 1, inorderPos);

    return root;

}