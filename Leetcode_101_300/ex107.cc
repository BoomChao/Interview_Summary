

//Leetcode第107题:Binary Tree Level Order Traversal II 
//二叉树的层序遍历II

std::vector<std::vector<int>> levelOrderBottom(TreeNode *root)
{
    std::vector<std::vector<int>> res;
    
    if(root == nullptr) return res;

    std::deque<TreeNode*> nodes;
    nodes.push_back(root);

    while(!nodes.empty())
    {
        std::vector<int> oneLevel;
        int size = node.size();
        for(int i = 0; i < size; i++)       //注意:这里千万不能写 i < nodes.size(); 因为下面往nodes中添加元素,容器大小就改变了
        {
            TreeNode *pNode = nodes.front();
            nodes.pop_front();
            oneLevel.push_back(node->val);
            
            if(pNode->left != nullptr) nodes.push_back(pNode->left);
            if(pNode->right != nullptr) nodes.push_back(pNode->right);

        }

        res.insert(res.begin(), oneLevel);      //与第102题二叉树的层序遍历相比只多了这一行代码

    }


    return res;

}