
/*
    求二叉树的最小深度和最大深度
*/

//求二叉树的最大深度(Lc第104题)

int maxDepth(TreeNode *root)
{
    if(root == nullptr) return 0;

    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}


//求二叉树的最小深度(错误解法)
//      1
//    2   
//  3
//如果是这么一颗二叉树,则用下面的算法返回结果为1,但实际结果应该为3

int minDepth(TreeNode *root)
{
    if(root == nullptr) return 0;

    return 1 + std::min(minDepth(root->left), minDepth(root->right));
}

//正确解法

int minDepth(TreeNode *root)
{
    if(root == nullptr) return 0;

    //左子树为空,返回右子树的深度
    if(root->left == nullptr) {
        return 1 + minDepth(root->right); 
    } 

    //右子树为空,返回左子树的深度
    if(root->right == nullptr) {
        return 1 + minDepth(root->left);
    }

    //左右子树都不为空,返回左右子树深度的最小值
    return std::min(minDepth(root->left), minDepth(root->right)) + 1;
}




/*
    序列化与反序列化二叉树(Lc第297题)
*/

std::string serialize(TreeNode *root)
{
    if(root == nullptr) return "#";
    
    return std::to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
}


TreeNode* deserialize(std::string data)
{
    std::stringstream in(data);

    return deserializeCore(in);
}

TreeNode* deserializeCore(std::stringstream &in)
{
    std::string val;
    getline(in, val, ',');

    if(val == "#") return nullptr;

    TreeNode *root = new TreeNode(std::stoi(val));
    root->left = deserializeCore(in);
    root->right = deserializeCore(in);

    return root;
}



/*
    写一个宏计算两个数之中的较小者,三个数之中的较小者(要求不用if else 语句)
*/

//求两个数之间的最小值
//方法一:这种方法不好
#define MIN(a, b) ((a) < (b) ? (a) : (b))   //加括号防止预处理展开的错误

//方法二:(宏里面如果有多行代码则需要使用 {} )
#define MIN(a, b) ({ \
    typeof(a) m_x = (a); \
    typeof(b) m_y = (b); \
    (m_x < m_y) ? m_x : m_y; \
})

//1.typeof关键字用来获得变量的数据类型,
//2.宏定义的实现,用{}作为宏整体,里面是一个代码块,语句用";"隔开
//3.当宏的实现很长的时候,使用换行符 "\" 换到下一行, 注意 "\"的后面不允许有一个空格
//4.使用输入数据的类型定义局部变量 m_x, m_y 实现对原始数据的保护
//5.宏实现不能使用 ";" 结尾


//求三个数之间的最小值(宏定义里面没有return语句)
#define MIN(x, y, z) ({\
    typeof(x) m_x = (x);\
    typeof(y) m_y = (y);\
    typeof(z) m_z = (z);\
    m_x < m_y ? (m_x < m_z ? m_x : m_z) : (m_y > m_z ? m_z : m_y);\
})


//附:写一个函数计算三个数中的较小者(不能使用if else 语句)

int min(int x, int y, int z)
{
    return x < y ? (x < z ? x : z) : (y > z ? z : y);
}


//附:写一个宏交换两个数的值
#define swap(x, y) ({\
    typeof(x) tmp = x;\
    x = y;\
    y = tmp;\
})

#define swap(x,y) ({\
    x = x^y;\
    y = x^y;\
    x = x^y;\
})

#define swap(x,y) ({\
    x = x + y; \
    y = x - y;\
    x = x - y;\
})


/*
    链表和数组实现栈和队列
*/

struct stack {
    int *data;
    int top;        //top初始化为-1表示这是一个空栈

    stack(int n = 0) : data(new int[n]), top(-1) {}
    
    ~stack() {
        delete data;
    }

    //判断栈是否满
    bool isFull() 
    {
        if(top == sizeof(data)/sizeof(int) - 1) return true;
        else return false; 
    }

    //判断是否空
    bool isEmpty() 
    {
        if(top == -1) return true;
        else return false;
    }

    //压入栈
    bool push(int num) 
    {
        if(isFull()) return false;

        data.[++top] = num;

        return true;
    }

    //弹出栈
    bool pop()
    {
        if(isEmpty()) return false;

        --top;

        return true;
    }
};


//链表实现栈

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

struct stack {
    ListNode *top;
    int count;      //记录栈的个数,由于是链表存储,则判断栈空或者满时不需要遍历链表

    stack() : top(nullptr), count(0) {}

    bool push(int num) 
    {
        ListNode *pNode = new(std::nothrow) ListNode(num);
        if(pNode == nullptr) return false;

        pNode->next = top;
        top = pNode;
        count++;

        return true;
    }

    bool pop()
    {
        if(count == 0) return false;

        ListNode *pNode = top();
        top = top->next;

        delete pNode;
        return true;
    }
};


/*
        1
    -2    3
   4 -5  6 -7
     8 9

    给出一个二叉树,层序遍历该二叉树,但是规定节点为负数算作虚节点,不能算进层数,遇到虚节点直接打印其子节点(子节点要再是虚节点再打印其非虚子节点)
    如上面节点打印 {1,4,8,9,3,6}
*/

//使用双端队列
//1.如果当前节点的值大于0,则正常加入到队列末端
//2.如果当前节点的值小于0,则先将右节点加入到队头,再将左节点加入队头

void traversal(TreeNode *root)
{
    if(root == nullptr) return;

    std::deque<TreeNode*> dq;
    dq.push_back(root);

    while(!dq.empty())
    {
        auto cur = dq.front(); dq.pop_front();
        
        if(cur->val > 0) {
            printf("%d\n", cur->val);
        }
        
        if(cur->val < 0) {
            if(cur->right) dq.push_front(cur->right);
            if(cur->left) dq.push_front(cur->left);
        }
        else {
            if(cur->left) dq.push_back(cur->left);
            if(cur->right) dq.push_back(cur->right);
        }
    }

}


/*
    快手二面:给定一组关系(child,parent),返回树的祖先

    如:(2,1) (3,1) (5,4), (2,1)子节点为2,父节点为1, (3,1)代表子节点为3,父节点为1
    这颗树形如
      1       4
    /  \      |
   2    3     5

   要求返回节点1,和节点4,注意返回的根节点要求可以通过给定的子节点指针的指向遍历到其所有子节点
*/

struct TreeNode {
    int val;
    std::vector<TreeNode*> childNode;
    TreeNode(int m_val) : val(m_val), isRoot(0) {}
};

std::unordered_set<TreeNode*> hash;                 //判断某个节点是否存在

std::unordered_map<TreeNode*, TreeNode*> parent;    //用来存储节点对应的父亲节点

std::vector<TreeNode*> parse(std::vector<std::vector<int>> relation)
{
    std::vector<TreeNode*> res;

    for(int i = 0; i < relation.size(); i++)
    {
        int childId = relation[i][0], parentId = relation[i][1];

        if(hash.count(parentId))
        {
            TreeNode *pParent = nullptr;
            for(auto &node : res) {
                if(node->val == parentId) {
                    pParent = node;
                    break;
                }
            }

            TreeNode *pChild = new TreeNode(childId);

            pParent->childNode.push_back(pChild);
            parent[pChild] = pParent;
        }
        else 
        {
            TreeNode *pParent = new TreeNode(parentId);
            TreeNode *pchild = new TreeNode(childId);
            pParent->childNode.push_back(pChild);
            parent[pChild] = pParent;
            res.push(pParent);
        }
    }

    std::vector<TreeNode*> ans;
    for(auto &node : res)
    {
        if(!parent.count(node)) ans.push_back(node);
    }

    return ans;
}


