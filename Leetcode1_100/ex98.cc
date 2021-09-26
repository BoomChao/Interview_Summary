

//Leetcode第98题:Valid Binary Search Tree
//判断一颗二叉树是否为二叉搜索树


//思路:中序遍历二叉树,判断其比前一个值大就可以

#include <iostream>
#include <climits>


bool isValidBST(TreeNode *root)
{
    long pre = INT_MIN;

    return isValidBSTCore(root, pre);

}

bool isValidBSTCore(TreeNode *root, long &pre)  //注:这里要传引用,如果是传值则在函数体内仍然可以修改实参的值,但是返回主函数后原实参不会改变
{
    if(root == nullptr) return true;

    if(!isValidBSTCore(root->left, pre)) return false;

    if(root->val <= pre) return false; 

    pre = root->val;

    return isValidBSTCore(root->right, pre);

}