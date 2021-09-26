

// Leetcode第331题:Verify Preorder Serialization of a Binary Tree
// 验证二叉树是否为有效的二叉树

// 思路:二叉树所有节点的出度减去入度的和等于0

bool isValidSerialization(std::string preorder)
{
    if(preorder.empty()) return false;
    
    std::istringstream in(preorder);
    std::string node;
    int diff = 1;
    
    while(getline(in, node, ','))
    {
        if(--diff < 0) return false;

        if(node != "#") {
            diff += 2;
        }
    }

    return diff == 0;