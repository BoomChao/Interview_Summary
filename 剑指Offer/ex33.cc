

/*
    面试题33:二叉搜索树的后序遍历
    给出一个整数数组,判断该数组是否为二叉搜索树的后序遍历结果
*/


bool verifySequenceOfBST(int sequence[], int length)
{
    if(sequence == nullptr || length <= 0) return false;

    //根节点的值
    int root = sequence[length-1];

    //二叉搜索树中左子树的节点值小于根节点的值
    int i = 0;
    for(; i < length-1; i++)
    {
        if(sequence[i] > root) break;
    }

    //二叉搜索树的右子树的节点值都大于根节点的值
    int j = i;
    for(; j < length-1; j++) 
    {
        if(sequence[j] < root) return false;
    }

    //判断左子树是不是二叉搜索树
    bool left = true;
    if(i > 0) {
        left = verifySequenceOfBST(sequence, i);
    }

    //判断右子树是不是二叉搜索树
    bool right = true;
    if(i < length-1) {
        right = verifySequenceOfBST(sequence + i, length-1-i);
    }

    return (left && right);

}


