


// 1.Leetcode第298题 : 二叉树的最长递增子序列

//解法一:对每个节点判断

int res = 0;

std::unodered_map<TreeNode*, int> hash;

int maxLenOfTree(TreeNode *root)
{
    if(root == nullptr) return 0;

    res = std::max(dfs(root), std::max(maxLenOfTree(root->left), maxLenOfTree(root->right)));

    return res;
}

int dfs(TreeNode *root)
{
    if(root == nullptr) return 0;

    if(hash.count(root)) return hash[root];

    int leftLen = 0, rightLen = 0;

    if(root->left && root->left->val == root->val + 1) leftLen += dfs(root->left);
    if(root->right && root->right->val == root->val + 1) rightLen += dfs(root->right);

    hash[root] = 1 + std::max(leftLen, right);

    return 1 + std::max(leftLen, rightLen);
}


//解法二:遍历的是否记下当前节点累计递增的个数即可

int maxLen = 0;

int longestConsecutive(TreeNode *root)
{
    if(root == nullptr) return 0;

    dfs(root, 1);

    return maxLen;
}

void dfs(TreeNode *root, int len)
{
    if(root == nullptr) return ;
    
    maxLen = std::max(maxLen, len);

    //存在左子树
    if(root->left) 
    {
        //左子节点比父节点大1
        if(root->left->val == root->val + 1) {
            dfs(root->left, len + 1);
        }
        else {
            dfs(root->len, 1);
        }
    } 
    else if(root->right) 
    {
        if(root->right->val == root->val + 1) {
            dfs(root->right, len + 1);
        }
        else {
            dfs(root->right, 1);
        }
    }

}


//解法三: 递归的时候记录最长连续序列长度

int maxLen = 0;

int longestConsecutive(TreeNode *root)
{
    dfs(root, nullptr, 0);

    return maxLen;
}

//root为pNode的父节点
void dfs(TreeNode *pNode, TreeNode *root, int len)
{
    if(pNode == nullptr) return ;

    len = (root && pNode->val == root->val + 1) ? len + 1 : 1;

    maxLen = std::max(maxLen, len);

    dfs(pNode->left, pNode, len);
    dfs(pNode->right, pNode, len);
}

