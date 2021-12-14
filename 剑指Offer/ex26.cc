

/*
    面试题26:树的子结构
    输入两颗二叉树Ａ和Ｂ，判断B是否是A的子树
*/

//思路
//1.在树A中找到树B的根节点一样的节点R
//2.判断在树Ａ中以Ｒ为节点的子树是不是包含和树Ｂ一样的结构


struct binaryTreeNode {
    double val;
    binaryTreeNode *left;
    binaryTreeNode *right;

};


bool hasSubtree(binaryTreeNode *pRoot1, binaryTreeNode *pRoot2)
{
    bool result = false;

    if(pRoot1 != nullptr && pRoot2 != nullptr)
    {
        //在树Ａ中找到了树Ｂ的根节点，接下来判断树Ａ是否包含树Ｂ
        if(equal(pRoot1->val, pRoot2->val)){
            result = doesTree1HaveTree2(pRoot1, pRoot2);
        }

        //没有找到树Ｂ的根节点，往树Ａ的左子树搜索
        if(!result){
            result = hasSubtree(pRoot1->left, pRoot2);
        }

        //没有找到树Ｂ的根节点，往树Ａ的右子树搜索
        if(!result){
            result = hasSubtree(pRoot1->right, pRoot2);
        }

    }

    return result;

}


bool doesTree1HaveTree2(binaryTreeNode *pRoot1, binaryTreeNode *pRoot2)
{
    //一直搜索到了树Ｂ的叶节点，则说明成功;这两个if语句不能调换顺序
    if(pRoot2 == nullptr) return true;

    //搜索到了树A的叶节点,则说明失败
    if(pRoot1 == nullptr) return false;

    if(!equal(pRoot1->val, pRoot2->val)) return false;

    return doesTree1HaveTree2(pRoot1->left, pRoot2->left) && doesTree1HaveTree2(pRoot1->right, pRoot2->right);

}


//判断两个浮点数是否相等
bool equal(double num1, double num2)
{
    if(num1-num2 > -0.00000001 && num1-num2 < 0.00000001){
        return true;
    }
 
    return false;
}