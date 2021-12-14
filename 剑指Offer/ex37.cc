

/*
    面试题37:序列化二叉树
*/


void serialize(BinaryTreeNode *pRoot, ostream &stream)
{
    if(pRoot == nullptr) {
        stream << "$,";
        return;
    }

    stream << pRoot->value << ',';
    serialize(pRoot->left, stream);
    serialize(pRoot->right, stream);

}


void deserialize(BinaryTreeNode **pRoot, istream &stream)
{
    int number;

    if(ReadStream(stream, &number)      //ReadStream函数每次从流中读入一个数字或者字符"$",当从流中读入一个数字时,返回true,否则返回false
    {
        *pRoot = new BinaryTreeNode();
        (*pRoot)->value = number;
        (*pRoot)->left = nullptr;
        (*pRoot)->right = nullptr;

        deserialize(&((*pRoot)->left), stream);
        deserialize(&((*pRoot)->right), stream);
    }

}
