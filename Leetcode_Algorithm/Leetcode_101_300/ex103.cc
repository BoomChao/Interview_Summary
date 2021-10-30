

//Leetcode第103题:Binary Zigzag Level Order Traversal
//之字型遍历二叉树

//参考<剑指>面试题32


std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if(root == nullptr) return {{}};

    std::vector<std::vector<int>> res;
    std::vector<int> zigzagLevel;
    std::stack<TreeNode*> level[2];

    int current = 0;
    int next = 1;

    level[0].push(root);
    while(!level[0].empty || !level[1].empty())
    {
        TreeNode *pNode = level[current].top();
        level[current].pop();
        zigzagLevel.push_back(pNode->val);

        if(current == 0) 
        {
            if(pNode->left != nullptr) {
                level[next].push(pNode->left)
            }

            if(pNode->right != nullptr) {
                level[next].push(pNode->right);
            }

        }
        else
        {
            if(pNode->right != nullptr) {
                level[next].push(pNode->right);
            }

            if(pNode->left != nullptr) {
                level[next].push(pNode->left);
            }

        }

        if(level[current].empty())
        {
            res.push_back(zigzagLevel);
            zigzagLevel.clear();
            current = 1-current;
            next = 1-next;
        }

    }

    return res;
}