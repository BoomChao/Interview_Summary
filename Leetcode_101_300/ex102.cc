

//Leetcode第102题:Binary Tree Level Order Traversal
//层序遍历数的节点

//解法一:
//参考<剑指>面试题32

std::vector<std::vector<int>> levelOrder(TreeNode *root)
{
    if(root == nullptr) return {{}};

    std::vector<std::vector<int>> res;  //存放返回的结果
    std::vector<int> level;             //存放每一层遍历的结果
    std::deque<TreeNode*> nodes;        //存放节点到队列

    nodes.push_back(root);

    int nextLevel = 0;      //下一层的节点数
    int levelToBeTraversed = 0;    //本层要打印的节点数

    while(!nodes.empty())
    {
        TreeNode *pNode = nodes.front();
        level.push_back(pNode->val);
        nodes.pop_front();

        if(pNode->left != nullptr) {
            nodes.push_back(pNode->left);
            ++nextLevel;
        }

        if(pNode->right != nullptr) {
            nodes.push_back(pNode->right);
            ++nextLevel;
        }

        --levelToBeTraversed;

        if(levelToBeTraversed == 0)
        {
            //本层的节点都被遍历完了则将结果存放到目标容器中
            res.push_back(level);
            level.clear();
            levelToBeTraversed = nextLevel;
            nextLevel = 0;
        }

    }

    return res;
}



//解法二

std::vector<std::vector<int>> levelOrder(TreeNode *root)
{
    std::vector<std::vector<int>> res;

    if(root == nullptr) return res;

    std::deque<TreeNode*> nodes;
    nodes.push_back(root);

    while(!nodes.empty())
    {
        std::vector<int> oneLevel;
        int size = nodes.size();
        for(int i = 0; i < size; i++)
        {
            TreeNode *pNode = nodes.front();
            nodes.pop_front();
            oneLevel.push_back(pNode->val);

            if(pNode->left != nullptr) nodes.push_back(pNode->left);
            if(pNode->right != nullptr) nodes.push_back(pNode->right);

        }

        res.push_back(oneLevel);

    }

    return res;
}

