

/*
    面试题7:重建二叉树
*/


struct binaryTreeNode {
    int val;
    binaryTreeNode *left;
    binaryTreeNode *right;

};


binaryTreeNode* construct(int *preorder, int *inorder, int length)
{
    if(preorder == nullptr || inorder == nullptr || length <= 0) return nullptr;

    return constructCore(preorder, preorder+length-1, inorder, inorder+length-1);

}

binaryTreeNode *constructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder)
{
    //前序遍历的第一个节点就是根节点的数值
    int rootValue = startInorder[0];    

    binaryTreeNode *root = new binaryTreeNode();
    root->val = rootValue;
    root->left = root->right = nullptr;

    //如果前序序列元素只有一个
    if(startPreorder == endPreorder)
    {
        //如果前序遍历只有一个元素,中序遍历也只有一个元素;说明该树只有一个节点
        //并且如果前序遍历的这个元素和中序遍历的这个元素的值相等,则返回根节点
        //否则返回错误信息
        if(startPreorder == endPreorder && *startPreorder == *startInorder) {
            return root;
        }
        else {
            std::cout << "Invalid input!" << std::endl;
            exit(1);
        }

    }

    
    //下面的情况为前序序列的元素不只一个

    //在中序遍历中找到根节点的位置
    int *rootInorder = startInorder;
    while(rootInorder < endInorder && *rootInorder != rootValue) {
        rootInorder++;
    }

    //如果在中序遍历中找到末尾了还没有找到根节点,说明中序遍历输入有错;直接返回错误信息
    if(rootInorder == endInorder && *rootInorder != rootValue) {
        std::cout << "Invalid input!" << std::endl;
        exit(1);
    }

    int leftLength = rootInorder - startInorder;    //得到根节点左子树的长度
    int *leftPreorderEnd = startPreorder + leftLength;    //得到左子树在前序序列中结束的位置
    
    //构建左子树
    if(leftLength > 0) 
    {
        root->left = constructCore(startPreorder+1, leftPreorderEnd, startInorder, rootInorder-1);
    }

    //构建右子树
    //endProrder-startInorder得到的长度是树中除去根节点的所有节点的数量;也就是左子树和右子树的长度之和
    if(leftLength < endPreorder-startPreorder) 
    {   
        root->right = constructCore(leftPreorderEnd+1, endPreorder, rootInorder+1, endInorder);
    }


    return root;
}



//以下为Leetcode第105题的依据前序遍历和中序遍历重建二叉树和第106题的依据后序和中序遍历重建二叉树


struct TeeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode () : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x) , left(left), right(right) {}
};


// 根据前序和中序遍历来重建二叉树
TreeNode* buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
{
    std::unordered_map<int, int> inorderPos;
    for(int i = 0; i < inorder.size(); i++) {
        inorderPos[inorder[i]] = i;
    }

    return buildTreeCore(preorder, 0, preorder.size() - 1, 0, inorderPos);
}


//这里定义startInorder是为了在重建的过程中得到左右子树的长度
TreeNode* buildTreeCore(std::vector<int> &preorder, int startPreorder, int endPreorder, int startInorder, std::unordered_map<int, int> &inorderPos)
{
    if(startPreorder > endPreorder) return nullptr;

    TreeNode *root = new TreeNode(preorder[startPreorder]);

    int rootIndex = inorderPos[preorder[startPreorder]];

    int leftLen = rootIndex - startInorder;

    root->left = buildTreeCore(preorder, startPostorder + 1, startPreorder + leftLen, startInorder, inorderPos);

    root->right = buildTreeCore(preorder, startPreorder + leftLen + 1, endPreorder, rootIndex + 1, inorderPos);

    return root;
}



//依据后序和中序遍历来重建二叉树
TreeNode* buildTree(std::vector<int> &postorder, std::vector<int> &inorder)
{
    std::unordered_map<int, int> inorderPos;
    for(int i = 0; i < inorder.size(); i++) {
        inorderPos[inorder[i]] = i;
    }

    return buildTreeCore(postorder, 0, postorder.size() - 1, 0, inorderPos);
}

TreeNode *buildTreeCore(std::vector<int> &postorder, int startPostorder, int endPostorder, int startInorder, std::unordered_map<int, int> &inorderPos)
{
    if(startPostorder > endPostorder) return nullptr;

    TreeNode *root = new TreeNode(postorder[endPostorder]);
    
    int rootIndex = inorderPos[postorder[endPostorder]];

    int leftLen = rootIndex - startInorder;

    root->left = buildTreeCore(postorder, startPostorder, startPostorder + leftLen - 1, startInorder, inorderPos);

    root->right = buildTreeCore(postorder, startPostorder + leftLen, endPostorder - 1, rootIndex + 1, inorderPos);

    return root;
}




