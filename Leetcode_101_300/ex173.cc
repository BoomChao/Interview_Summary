


//Leetcode第173题:Binary Search Tree Iterator
//二叉树迭代器

//注意:题目的要求是中序遍历
//利用栈来实现


class BSTIterator
{
    stack<TreeNode*> myStack;       //不加访问修饰符则默认的访问属性是私有的

    public:
        BSTIterator(TreeNode *root) {
            pushAll(root);
        }


        int next() {
            TreeNode *tmpNode = myStack.top();
            myStack.pop();
            pushAll(tmpNode->right);

            return tmpNode->val;
        }


        bool hasNext() {
            return !myStack.empty();
        }


    private:
        void pushAll(TreeNode *node) 
        {
            while(node != nullptr) {    //开始只存储左节点
                myStack.push(node);
                node = node->left;
            }
        }


};