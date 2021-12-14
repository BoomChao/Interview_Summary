

/*
    面试题32:从上到下打印二叉树 : 利用队列和栈

    1.二叉树的层序遍历

    2.分行从上到下打印二叉树

    3.之字形打印二叉树

*/




struct binaryTreeNode {
    int val;
    binaryTreeNode *left;
    binaryTreeNode *right;

};


//  1.二叉树的层序遍历
//思路:利用队列deque
//打印一个节点,如果该节点有子节点,则将其加入队尾,一直到所有节点被全部打印

void printFromTopToButton(binaryTreeNode *pTreeRoot)
{
    if(pTreeRoot == nullptr) return;

    std::deque<binaryTreeNode*> dequeTreeNode;

    dequeTreeNode.push_back(pTreeRoot);    //将根节点加入到队列中

    while(!dequeTreeNode.size().empty())    //队列非空则继续打印
    {
        //队首元素出队并打印节点的值
        binaryTreeNode *pNode = dequeTreeNode.front();
        dequeTreeNode.pop_front();     
        printf("%d ", pNode->val);

        //存在子节点则先让左节点入队,再让右节点入队
        if(pNode->left != nullptr) {
            dequeTreeNode.push_back(pNode->left);
        }

        if(pNode->right != nullptr) {
            dequeTreeNode.push_back(pNode->right);
        }

    }

}




// 2.分行从上到下打印二叉树
//思路:还是利用队列,只不过需要额外的两个变量
//一个用来表示当前层还没有打印的节点数;另一个变量表示下一层的节点数

void print(binaryTreeNode *pRoot)
{
    if(pRoot == nullptr) return;

    std::deque<binaryTreeNode*> nodes;

    nodes.push_back(pRoot);

    //nextLevel表示下一层的节点数
    int nextLevel = 0;

    //toBePrinted保存当前层还没有打印的节点数
    int toBePrinted = 1;

    while(!nodes.empty())
    {
        binaryTreeNode *pNode = nodes.front();
        nodes.pop_front();
        printf("%d ", pNode->val);

        if(pNode->left != nullptr) {
            nodes.push_back(pNode->left);
            ++nextLevel;
        }

        if(pNode->right != nullptr) {
            nodes.push_back(pNode->right);
            ++nextLevel;
        }

        //每打印一个节点则toBePrinted减1
        --toBePrinted;

        //toBePrinted为0表示该层节点全部打印完毕,输出换行符
        if(toBePrinted == 0)
        {
            printf("\n");
            toBePrinted = nextLevel;
            nextLevel = 0;
        }

    }

}



// 3.之字形打印二叉树

void print(binaryTreeNode *pRoot)
{
    if(pRoot == nullptr) return;

    //定义两个栈
    std::stack<binaryTreeNode*> levels[2];

    int current = 0;
    int next = 1;

    levels[current].push(pRoot);
    while(!levels[0].empty() || !levels[1].empty())
    {
        binaryTreeNode *pNode = levels[current].top();
        levels[current].pop();
        printf("%d ", pNode->val);

        //规定栈level[0]中的的元素节点子节点入栈level[1]
        //对栈levels[1],但是要求左子节点先入栈,右子节点后入栈
        if(current == 0)
        {
            if(pNode->left != nullptr) {
                levels[next].push(pNode->left);
            }

            if(pNode->right != nullptr) {
                levels[next].push(pNode->right);
            }

        }

        //同样规定栈levels[1]中的元素入栈levels[0]
        //对栈levels[0],要求右子节点先入栈,左子节点后入栈
        else
        {
            if(pNode->right != nullptr) {
                levels[next].push(pNode->right);
            }

            if(pNode->levels != nullptr) {
                levels[next].push(pNode->left);
            }

        }

        //当前栈中元素全部打印完毕,则输出换行符,交换栈继续打印下一层
        if(levels[current].empty()) 
        {
            printf("\n");
            current = 1-current;
            next = 1-next;
        }
    }

}