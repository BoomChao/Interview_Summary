
/*
*
*   树
*
*/

/////////////////////////////////
//
//  树的前序,中序,后序,层序,之字形遍历
//
//
//  235题和236题: 树的最近公共祖先
//  226题: 翻转二叉树
//  199题: 二叉树的右视图
//
////////////////////////////////

//Leetcode第144题:前序遍历

std::vector<int> preorderTraversal(TreeNode *root)
{
    std::vector<int> res;
    if(root == nullptr) return res;

    std::stack<TreeNode*> sta;
    sta.push(root);

    while(!sta.empty())
    {
        TreeNode *pNode = sta.top();
        res.push_back(pNode->val);
        sta.pop();

        if(pNode->right) {
            sta.push(pNode->right);
        }
        if(pNode->left) {
            sta.push(pNode->left);
        }
    }

    return res;
}


//Leetcode第94题:中序遍历

std::vector<int> inorderTraversal(TreeNode *root)
{
    std::vector<int> res;
    std::stack<TreeNode*> sta;
    TreeNode *pNode = root;     //这里也不能立刻让root入栈

    while(pNode || !sta.empty())
    {
        while(pNode) {
            sta.push(pNode);
            pNode = pNode->left;
        }

        pNode = sta.top(); sta.pop();
        res.push_back(pNode->val);

        pNode = pNode->right;       //注意:这里千万不能写成if(pNode->right) pNode = pNode->right;
    }

    return res;
}


//Leetcode第145题:后序遍历

std::vector<int> postorderTraversal(TreeNode *root)
{
    std::vector<int> res;
    if(root == nullptr) return res;

    std::stack<TreeNode*> sta;
    sta.push(root);

    while(!sta.empty())
    {
        TreeNode *pNode = sta.top();
        res.push_back(pNode->val);
        sta.pop();

        if(pNode->left) {
            sta.push(pNode->left);
        }
        if(pNode->right) {
            sta.push(pNode->right);
        }
    }

    reverse(res.begin(), res.end());

    return res;
}



//Leetcode第102题:层序遍历

//借助队列实现层序遍历
std::vector<std::vector<int>> levelOrder(TreeNode *root)
{
    std::vector<std::vector<int>> res;
    if(root == nullptr) return res;

    std::queue<TreeNode*> que;
    que.push(root);

    while(!que.empty())
    {
        std::vector<int> tmp;
        int n = que.size();
        for(int i = 0; i < n; i++) 
        {
            TreeNode *pNode = que.front();
            tmp.push_back(pNode->val);
            que.pop();

            if(pNode->left) {
                que.push(pNode->left);
            }
            if(pNode->right) {
                que.push(pNode->right);
            }
        }

        res.push(tmp);
    }

    return res;
}


//非递归实现层序遍历

std::vector<int> res;

std::vector<std::vector<int>> levelOrder(TreeNode *root)
{
    dfs(root, 0);

    return res;
}


void dfs(TreeNode *root, int depth)     //depth用来标识当前是第几层
{
    if(root == nullptr) return;

    if(depth >= res.size()) res.push_back({});
    res[depth].push_back(root->val);

    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}



//Leetcode第103题: 之字形层序遍历
//思路:依然按照层序遍历的方式,只不过当遍历到偶数层时将其结果翻转下即可
//使用reverse函数

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root)
{
    std::vector<std::vector<int>> res;
    if(root == nullptr) return res;

    std::queue<TreeNode*> que;
    que.push(root);

    int flag = 0;

    while(!que.empty())
    {
        std::vector<int> tmp;
        for(int size = que.size(); size > 0; size--)
        {
            TreeNode *pNode = que.front(); que.pop();
            tmp.push_back(pNode->val);

            if(pNode->left) que.push(pNode->left);
            if(pNode->right) que.push(pNode->right);
        }

        if(flag) {
            reverse(tmp.begin(), tmp.end());
        }
        res.push_back(tmp);

        flag = 1 - flag;
    }

    return res;
}


//方法三:不使用reverse函数,遍历到偶数层时倒着插就行

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root)
{
    std::vector<std::vector<int>> res;

    if(root == nullptr) return res;

    std::queue<TreeNode*> que;
    que.push(root);

    int curLevel = 0;

    while(!que.empty())
    {
        int n = que.size();
        std::vector<int> tmp(n);
        for(int i = 0; i < n; i++)
        {
            TreeNode *pNode = que.front();  que.pop();
            if(curLevel == 1) {         //遍历到偶数层时倒着插就行
                tmp[n-1-i] = pNode->val;
            }
            else {
                tmp[i] = pNode->val;
            }

            if(pNode->left) que.push(pNode->left);
            if(pNode->right) que.push(pNode->right);
        }

        res.push_back(tmp);

        curLevel = 1 - curLevel;
    }

    return res;
}


////////////////////
//
//      重建二叉树
//      第105题和106题: 层序遍历构建二叉树

//      第235题: 二叉搜索树的最近公共祖先
//      第236题: 二叉树的最近公共祖先
//      第226题: 翻转二叉树
//      第199题: 二叉树的右视图
//
////////////////////


//根据前序和中序遍历重建二叉树
//时间复杂度O(logn), 空间复杂度O(n),需要一个map存储元素

TreeNode* buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
{
    std::unordered_map<int,int> inorderPos;
    for(int i = 0; i < inorder.size(); i++) {
        inorderPos[inorder[i]] = i;
    }

    return buildTreeCore(preorder, 0, preorder.size() - 1, 0, inorderPos);
}

// 传入startInorder是为了计算左右子树的长度,使用map是为了快速找到左子树的长度

TreeNode *buildTreeCore(std::vector<int> &preorder, int startProrder, int endPreorder, int startInorder, std::unordered_map<int,int> &inorderPos)
{
    if(startProrder > endPreorder) return nullptr;

    int rootIndex = inorderPos[preorder[startProrder]];

    TreeNode *root = new TreeNode(preorder[startProrder]);

    int leftLen = rootIndex - startInorder;

    root->left = buildTreeCore(preorder, startProrder + 1, startProrder + leftLen, startInorder, inorderPos);

    root->right = buildTreeCore(preorder, startProrder + leftLen + 1, endPreorder, rootIndex + 1, inorderPos);

    return root;
}

//根据后序和中序遍历重建二叉树

TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder)
{
    std::unordered_map<int,int> inorderPos;
    for(int i = 0; i < inorder.size(); i++) {
        inorderPos[inorder[i]] = i;
    }
    
    return buildTreeCore(postorder, 0, postorder.size() - 1, 0, inorderPos);
}

TreeNode* buildTreeCore(std::vector<int> &postorder, int startPostorder, int endPostorder, int startInorder, std::unordered_map<int,int> &inorderPos)
{
    if(startPostorder > endPostorder) return nullptr;

    int rootIndex = inorderPos[postorder[endPostorder]];        //和上一题的差别1

    int leftLen = rootIndex - startInorder;

    TreeNode *root = new TreeNode(postorder[endPostorder]);
    
    // 和上一题的差别2,前序遍历首先遍历根节点,所以上一题前序遍历去掉前序第一个元素,
    // 后续遍历最后遍历根节点,所以这一题后续遍历去掉最后一个元素
    root->left = buildTreeCore(postorder, startPostorder, startPostorder + leftLen - 1, startInorder, inorderPos);

    root->right = buildTreeCore(postorder, startPostorder + leftLen, endPostorder - 1, rootIndex + 1, inorderPos);

    return root;
}



//层序遍历构建二叉树
//       3
//     /   \
//    9     20
//   / \    /\
//null null 5 6

//该二叉树的层序遍历序列为 {3,9,20,null,null,5,6},按照该层序遍历序列构建一颗二叉树
//思路:需要借助队列

struct TreeNode {
    TreeNode *left, *right;
    int val;
    TreeNode(int m_val) : val(m_val), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreeByLevenSeq(std::vector<std::string> &nums)   //因为null不好用数字表示,这里全部用字符串存储
{
    if(nums.empty()) return nullptr;

    TreeNode *root = new TreeNode(std::stoi(nums[0]));
    std::queue<TreeNode*> que;
    que.push(root);

    int i = 1;
    while(!que.empty())
    {
        auto cur = que.front(); que.pop();

        //建左子节点
        if(i < nums.size()) {
            if(nums[i] != "null") {           
                int val = std::stoi(nums[i]);  
                cur->left = new TreeNode(val);
                que.push(cur->left);
            }
        }
        i++;    //这里数组要后移

        //建右子节点
        if(i < nums.size()) {
            if(nums[i] != "null") {
                int val = std::stoi(nums[i]);
                cur->right = new TreeNode(val);
                que.push(cur->right);
            }
        }
        i++;

    }   

    return root;
}


//Leetcode第235题:二叉搜索树的最近公共祖先

TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root == nullptr) return root;

    //如果根节点比两个节点都大,则说明最近公共祖先在左子树上 
    if(root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    }

    //如果根节点比两个节点都小,则说明最近公共祖先在右子树上
    if(root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    }

    //不大不小则说明找到了
    return root;
}


//Leetcode第236题:二叉树的最近公共祖先

TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    //找到任一节点或者找到末尾的叶子节点就返回
    if(root == nullptr || root == p || root == q) return root;

    //现在不是二叉搜索树,先左子树上查找
    TreeNode *pLeft = lowestCommonAncestor(root->left, p, q);

    //在右子树上查找
    TreeNode *pRight = lowestCommonAncestor(root->right, p, q);

    //pLeft都pRight都不为空,说明这两个节点分布在根节点的两颗子树上
    if(pLeft && pRight) {
        return root;
    }

    //否则说明分布在根节点的其中一颗子树上,找到p或者q就可以返回 (上面的第二个 else if语句和else可以汇总写成下面这一条)
    return pLeft ? pLeft : pRight;
}



//Leetcode第226题:翻转二叉树

//解法一:利用递归

//从上往下翻转,先翻转父节点,再翻转对应的左右子节点

TreeNode* invertTree(TreeNode *root)
{
    if(root == nullptr) return root;

    std::swap(root->left, root->right);     //这里可以使用swap函数来交换

    invertTree(root->left);
    invertTree(root->right);

    return root;
}


//或者从下往上翻转,先翻转叶子节点

TreeNode* invertTree(TreeNode *root)
{
    if(root == nullptr) return nullptr;

    TreeNode *pLeft = invertTree(root->left);
    TreeNode *pRight = invertTree(root->right);

    root->left = pRight;
    root->right = pLeft;

    return root;
}


//解法二:迭代方法
//利用前序遍历

TreeNode *invertTree(TreeNode *root)
{
    if(root == nullptr) return root;

    std::stack<TreeNode*> sta;
    sta.push(root);

    while(!sta.empty())
    {
        TreeNode *pNode = sta.top();
        sta.pop();

        TreeNode *tmp = pNode->left;
        pNode->left = pNode->right;
        pNode->right = tmp;

        if(pNode->left) sta.push(pNode->left);
    
        if(pNode->right) sta.push(pNode->right);
        
    }

    return root;
}


//Leetcode第199题: 二叉树的右视图

//方法一:使用递归
std::vector<int> rightSideView(TreeNode *root)
{
    std::vector<int> res;

    if(root == nullptr) return res;

    dfs(root, 1, res);

    return res;
}

// res中的元素个数是和二叉树的深度相同的
// DFS搜索最右边子树即可
void dfs(TreeNode *root, int level, std::vector<int> &res)
{
    if(root == nullptr) return;

    if(res.size() < level) res.push_back(root->val);

    //先搜索右子树
    dfs(root->right, level + 1, res);
    dfs(root->left, level + 1, res);

}


// 方法二 : 使用迭代,层序遍历
// BFS搜索只取每层的最后一个节点

std::vector<int> rightSideView(TreeNode *root)
{
    std::vector<int> res;

    if(root == nullptr) return res;

    std::queue<TreeNode*> que;
    que.push(root);

    while(!que.empty())
    {
        for(int size = que.size(); size > 0; size--)
        {
            TreeNode *pNode = que.front(); que.pop();
            
            // 只需要取最后一个节点
            if(size == 1) res.push_back(pNode->val);

            if(pNode->left) que.push(pNode->left);
            if(pNode->right) que.push(pNode->right);
        }
    }

    return res;
}




///////////////////////////////////////
//     二叉搜索树
//   第98题 : 判断二叉搜索树是否有效     (NC60,判断一颗二叉树是否为完全二叉树)
//   第530题: 计算二叉树节点值的最小差
//   第501题: 找到BST中出现次数最多的节点集合
//   第230题: 找到BST中第k小节点

//   第700题: 在BST找寻找指定节点
//   第701题: 在BST中插入一个节点      //注意:二叉树的查找操作不会改变树的结构,所以递归返回的是空
//   第450题: 在BST中删除一个节点      //但是像插入和删除节点的操作会改变二叉树的结构,所以此时递归函数返回的不能是空.而是实际的树节点

//   第95题: 生成二叉搜索树
//   第96题: 复原二叉搜索树

//   108题: 将排序数组转换成BST  (这两题出的非常好)
//   109题: 将排序链表转化成BST

//   第96题: 给出节点总数,计算可能有多少种不同的BST二叉树 
//   第95题: 给出节点总数，返回所有可能的BST二叉树根节点集合

//////////////////////////////////////

//Leetcode第98题: 判断一颗二叉搜索树是否是有效
//二叉搜索树是任意一个节点都大于其左子树的所有节点,小于其右子树的所有节点

//时间复杂度O(n), 空间复杂度O(n)

//方法一: 根据二叉树的性质,从根节点开始遍历,遍历过程中记录最大值和最小值节点

bool isValidBST(TreeNode *root) {
    return isValidBSTCore(root, nullptr, nullptr);
}

bool isValidBSTCore(TreeNode *root, TreeNode *min, TreeNode *max)
{
    if(root == nullptr) return true;

    if(min && root->val <= min->val) return false
    if(max && root->val >= max->val) return false;
    
    return isValidBSTCore(root->left, min, root) && isValidBSTCore(root->right, root, max); 
}


//方法二: 二叉搜索树的中序遍历为递增序列,记录前一个节点的值与根节点比较
//利用中序遍历

bool isValidBST(TreeNode *root)
{
    long pre = LONG_MIN;

    return isValidBSTCore(root, pre);
}

bool isValidBSTCore(TreeNode *root, long &pre)  //注意：是传引用
{
    if(root == nullptr) return true;

    if(!isValidBSTCore(root->left, pre)) return false;  //只要有一个不满足,立即返回false

    if(root && root->val <= pre) {
        return false;
    } 

    pre = root->val;

    return isValidBSTCore(root->right, pre);
}


//方法三:不传值的引用,而是直接记录前一个节点,比较前一个节点和当前节点的值

bool isValidBST(TreeNode *root)
{
    TreeNode *prev = nullptr;

    return isValidBSTCore(root, prev);
}

//注意:这里需要传指针的引用, 因为如果直接传指针,指针在函数调用过程中也是当做一个值调用的(C中函数传递都是传值调用的)
//传值调用的作用域仅仅在子函数中,离开值函数值就自己释放了

bool isValidBSTCore(TreeNode *root, TreeNode *&prev)    
{
    if(root == nullptr) return true;

    if(!isValidBSTCore(root->left, prev)) return false;

    if(prev && root->val <= prev->val) return false

    prev = root;

    return isValidBSTCore(root->right, prev);
}


//NC60: 判断一颗二叉树是否为完全二叉树

//思路:利用bfs,如果层序遍历过程种遇到空节点后又发现非空节点,则说明不是完全二叉树

bool isCompleteTree(TreeNode *root)
{
    if(root == nullptr) return true;

    std::queue<TreeNode*> que;
    que.push(root);

    int flag = 0;

    while(!que.empty())
    {
        auto cur = que.front(); que.pop();

        if(cur->left) {
            if(flag) return false;
            else que.push(cur->left);
        }
        else flag = 1;

        if(cur->right) {
            if(flag) return false;
            else que.push(cur->right);
        }
        else flag = 1;
    }

    return true;
}




//Leetcode第530题:计算二叉树节点的最小正整数差

//利用中序遍历
//方法一:记录前一个节点的值

int ans = INT_MAX;

int getMinimumDifference(TreeNode *root)
{
    int prev = -1;

    getMinCore(root, prev);

    return ans;
}

void getMinCore(TreeNode *root, int &prev)
{
    if(root == nullptr) return;

    getMinCore(root->left, prev);

    if(prev != -1) {
        ans = std::min(ans, root->val - prev);
    }

    prev = root->val;

    getMinCore(root->right, prev);
}


//方法二:直接记录前一个节点

int getMinimumDifference(TreeNode *root)
{
    TreeNode *prev = nullptr;

    getMinCore(root, prev);

    return ans;
}

void getMinCore(TreeNode *root, TreeNode *&prev)    //注意:需要传指针的引用
{
    if(root == nullptr) return;

    getMinCore(root->left, prev);

    if(prev && root->val-prev->val < ans) {
        ans = root->val - prev->val;
    }

    prev = root;

    getMinCore(root->right, prev);
}


//Leetcode第700题: 在二叉搜索数中寻找指定节点

TreeNode* searchBST(TreeNode* root, int val) 
{
    if(root == nullptr) return root;
    
    if(root->val == val) return root;
    else if(root->val < val) {
        return searchBST(root->right, val);
    }
    else if(root->val > val) {
        return searchBST(root->left, val);
    }

    //这一行返回不加在Leetcode中编译过不了
    return nullptr;
}


//Leetcode第501题: 找到二叉搜索树中出现次数最多的节点
//思路:中序遍历统计出现的次数,遍历的时候统计好每个节点出现的次数(在遍历的时候统计即可,因为BST中序遍历是一个递增序列)

std::vector<int> res;
int maxFreq = 0, curFreq = 0;

std::vector<int> findMode(TreeNode *root)
{
    TreeNode *prev = nullptr;

    inorderTraversal(root, prev);

    return res;
}

void inorderTraversal(TreeNode *root, TreeNode *&prev)
{
    if(root == nullptr) return ;

    inorderTraversal(root->left, prev);

    if(prev && root->val == prev->val) curFreq++;
    else curFreq = 1;

    if(curFreq > maxFreq) {
        res.clear();
        maxFreq = curFreq;
        res.push_back(root->val);
    }
    else if(curFreq == maxFreq) {
        res.push_back(root->val);
    }

    prev = root;

    inorderTraversal(root->right, prev);
}


//Leetcode第230题: 找到二叉搜索树第k小节点
//思路:中序遍历

//采用递归解法和迭代解法复杂度都一样
//时间复杂度:最好的情况下BST是平衡二叉树,则时间复杂度为O(log(n)+k),空间复杂度为O(logn),就是二叉树的深度
//最差的情况下就是一颗左斜树,则时间复杂度为O(n),空间复杂度为O(n)

int ans;

int kthSmallest(TreeNode *root, int k) 
{
    inorderTraversal(root, k);

    return ans;
}

void inorderTraversal(TreeNode *root, int &k)   //注意:是传递引用
{
    if(root == nullptr) return root;

    inorderTraversal(root->left, k);

    if(--k == 0) {
        ans = root->val;
        return;
    }

    inorderTraversal(root->right, k)
}


//采用迭代解法:

int kthSmallest(TreeNode *root, int k)
{
    std::stack<TreeNode*> sta;
    TreeNode *pNode = root;

    while(pNode || !sta.empty())
    {
        while(pNode) {
            sta.push(pNode);
            pNode = pNode->left;
        }

        pNode = sta.top();  sta.pop();

        if(--k == 0) {
            return pNode->val;
        }

        pNode = pNode->right;
    }

    return -1;
}



//Leetcode第701题: 在二叉搜索树中插入一个节点
//该题包括下面删除节点,一旦涉及到改的操作,函数就要返回TreeNode类型,并且对递归函数的调用的返回值进行接受

//思路:　如果当前节点为空，直接将其插入当前节点即可, 递归二叉树找到其插入位置即可

TreeNode* insertIntoBST(TreeNode *root, int val)
{
    if(root == nullptr) return (new TreeNode(val));     //注意:这里是要返回一个指针

    if(root->val < val) {
        root->right = insertIntoBST(root->right, val);
    }
    else if(root->val > val) {
        root->left = insertIntoBST(root->left, val);
    }

    return root;
}

//解法二:(为了形成框架,最好还是用上面的解法,比较通用)
TreeNode* insertIntoBST(TreeNode *root, int val)
{
    if(root == nullptr) return (new TreeNode(val));

    TreeNode *tmp = root;

    dfs(tmp, val);

    return root;
}

void dfs(TreeNode *&root, int val)
{
    if(root == nullptr) {
        root = new TreeNode(val);
        return;
    }

    if(root->val < val) {
        dfs(root->right, val);
    }
    else {
        dfs(root->left, val);
    }

}


//Leetcode第450题:　在二叉搜索树中删除指定节点

//思路: 对二叉树的插入或者删除操作会改变树的结构,所以这里递归返回的不能是空,而是返回实际节点

//递归寻找要删除的节点,找到后
//1.要删除的节点是叶子节点(没有左右子树), 直接返回nullptr(此时root->right = nullptr && root->left == nullptr) (将情况1合并到情况2或者3中都行)
//2.要删除的节点只有右子树,没有左子树, 直接返回 root->right
//3.要删除的节点只有左子树,没有右子树, 直接返回 root->left
//4.要删除的节点既有左子树和右子树, 找到左子树的最大值或者右子树的最大节点, 比如找到左子树的最大值, 将root->val替换掉, 之后删除左子树的最大节点


TreeNode* deleteNode(TreeNode *root, int key)
{
    if(root == nullptr) return root;

    //找到了删除的节点
    if(root->val == key) 
    {
        //如果是叶子节点或者只有一个子节点，直接返回叶子节点
        if(root->left == nullptr) return root->right;
        else if(root->right == nullptr) return root->left;

        //如果节点存在两个子节点,这时需要找到左子树的最大节点，或者右边子树的最小节点
        TreeNode *minNode = getRightMin(root->right);
        root->val = minNode->val;
        root->right = deleteNode(root->right, minNode->val);    //删除右子树的最小节点
    }
    else if(root->val < key) {
        root->right = deleteNode(root->right, key);
    }
    else if(root->val > key) {
        root->left = deleteNode(root->left, key);
    }

    return root;
}

//找到右子树的最小节点
TreeNode *getRightMin(TreeNode *root)
{
    while(root->left) {
        root = root->left;
    }

    return root;
}

//找到左子树的最大节点
TreeNode *getLeftMax(TreeNode *root)
{
    while(root->right) {
        root = root->right;
    }

    return root;
}


// 方法二: 要删除的节点root既有左子树和右子树时,找到右子树的最小值(不能找左子树大值),将左边子树接到该最小值的左子树上,返回root->right

TreeNode *deleteNode(TreeNode *root, int key)
{
    if(root == nullptr) return root;

    if(root->val == key) {
        if(root->left == nullptr) return root->right;
        else if(root->right == nullptr) return root->left;

        TreeNode *rightSmall = root->right;
        while(rightSmall->left) {
            rightSmall = rightSmall->left;
        }
        rightSmall->left = root->left;
        return root->right;
    }
    else if(root->val < key) {
        root->right = deleteNode(root->right, key);
    }
    else if(root->val > key) {
        root->left = deleteNode(root->left, key);
    }

    return root;
}


//Leetcode第95题:生成二叉搜索树

// Leetcode第99题：复原BST
// 思路：
// 1.题目中只是有两个节点被交换了
// 2.依据前序遍历的思路，BST中序遍历为一个递增序列
// 3.比如现在得到的中序遍历序列为 6,3,4,5,2, 
//  找到第一个prev > root时，将prev记录到pFist记录下来，这是我们第一个要交换的节点; 第二个要交换的节点就是root,保存到pSeond中
//  下一次再遇到 prev>root时，将root记录到pSecond保存下来，更新第二个要交换的节点，之后交换这两个节点即可

TreeNode *pFirst = nullptr, *pSecond = nullptr;

void recoverTree(TreeNode *root)
{
    TreeNode *prev = nullptr;
    
    dfs(root, prev);

    //pFirst和pSecond不为空时才能交换
    if(pFirst && pSecond) std::swap(pFirst->val, pSecond->val);
}

void dfs(TreeNode *root, TreeNode * &prev)
{
    if(root == nullptr) return;

    dfs(root->left, prev);

    if(prev && prev->val >= root->val) {
        if(pFirst == nullptr) pFirst = prev;
        pSecond = root;
    }

    prev = root;

    dfs(root->right, prev);
}



//Leetcode第108题: 将升序数组转化成BST

TreeNode* sortedArrayToBST(std::vector<int> &nums)
{
    //找到中点后二分,前半部分为左子树,后半部分为右子树
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}

TreeNode* sortedListToBST(std::vector<int> &nums, int left, int right)
{
    if(left > right) return nullptr;

    int mid = left + ((right-left) >> 1);

    TreeNode *root = new TreeNode(nums[mid]);

    root->left = sortedListToBST(nums, left, mid - 1);
    root->right = sortedListToBST(nums, mid + 1, right);

    return root;
}


//Leetcode第109题: 将升序链表转化成BST
//题目出的非常好

TreeNode* sortedListToBST(ListNode *head)
{
    if(head == nullptr) return nullptr;    //这里不能return head,因为head是链表节点,这里需要返回树节点

    return sortedListToBST(head, nullptr);
}

TreeNode* sortedListToBST(ListNode *head, ListNode *tail)
{
    if(head == tail) return nullptr;

    ListNode *mid = head, *fast = head;
    while(fast != tail && fast->next != tail) {
        mid = mid->next;
        fast = fast->next->next;
    }

    TreeNode *root = new TreeNode(mid->val);

    root->left = sortedListToBST(head, mid);
    root->right = sortedListToBST(mid->next, tail);

    return root;
}


// Leetcode第96题: 给出二叉搜索树节点总数，判断有多少种可能的组成形式
// Leetcode第95题: 给出上述所有的二叉树根节点的集合

// f(n)表示节点总数为n时的二叉树种类数
// f(0) = 1, f(1) = 1;
// f(2) = f(0) *(根节点) * f(2-1-0)  +  f(1) * (根节点) * f(2-1-1)
// f(i) = f(左子树) * (根节点) *(右子树)

int numTrees(int n)
{
    std::vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i] += dp[j-1] * dp[i-j];     //dp[j-1]表示左子树的种类数 dp[i-j]表示右子树的种类数
        }
    }

    return dp[n];
}


std::vector<TreeNode*> generateTrees(int n) 
{
    return dfs(1, n);       //[left,right]表示根节点的取值范围
}

std::vector<TreeNode*> dfs(int left, int right)
{   
    if(left > right) return { nullptr };

    std::vector<TreeNode*> res;

    for(int i = left; i <= right; i++)
    {
        auto leftSet = dfs(left, i - 1);
        auto rightSet = dfs(i + 1, right);

        for(auto &pLeft : leftSet) {
            for(auto &pRight : rightSet) {
                TreeNode *root = new TreeNode(i);
                root->left = pLeft;
                root->right = pRight;
                res.push_back(root);
            }
        }
    }

    return res;
}




/////////////////////////
//
//      树的路径和(pathSum系列)
//
//     第112题 : 判断树中是否存在从根节点到叶子节点的一条路径其和等于target
//     第113题 : 求出所有可行的路径
//     第437题 : 返回所有路径总数(不必从根节点开始)
//     第687题 : 计算相同节点的最多边数      

//     第124题 : 返回任意两个节点之间的最大路径   (第543题: 返回二叉树的最大直径) 这两题非常相似
//     第257题 : 打印二叉树的所有路径
//
////////////////////////

//第112题 : 判断树中是否存在从根节点到叶子节点的一条路径其和等于target

bool hasPathSum(TreeNode *root, int targetSum)
{
    if(root == nullptr) return false;

    // if(root->val > targetSum) return false;  //这句话不能加,防止节点和目标都是负数,正数减去一个正数变小,负数减去一个负数会变大

    if(root->val == target && root->left == nullptr && root->right == nullptr) return true;

    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}


//第113题 : 求出所有可行的路径

std::vector<std::vector<int>> res;

std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum)
{
    std::vector<int> path;

    dfs(root, targetSum, path);

    return res;
}

void dfs(TreeNode *root, int target, std::vector<int> &path)
{
    if(root == nullptr) return ;

    path.push_back(root->val);

    if(root->val == target && root->left == nullptr && root->right == nullptr) {
        res.push_back(path);
        // return;              //注意传引用的话这里不能返回
    }

    dfs(root->left, target - root->val, path);
    dfs(root->right, target - root->val, path);

    path.pop_back();    //回溯
}


//第437题: 返回所有路径和(不必从根节点开始)

int pathSum(TreeNode *root, int sum) 
{
    if(root == nullptr) return 0;

    return pathSumStartWithRoot(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);   
    //注意不能写成pathSumStartWithRoot(root, sum) + pathSumStartWithRoot(root->left, sum) + pathSumStartWithRoot(root->right, sum)
    //这样把root, root->left和root->right这三个节点当做了根节点进行了遍历,没有把所有节点当做根节点进行遍历
}

int pathSumStartWithRoot(TreeNode *root, int sum)
{
    if(root == nullptr) return 0;

    int count = (root->val == sum ? 1 : 0);

    count += pathSumStartWithRoot(root->left, sum - root->val); 
    count += pathSumStartWithRoot(root->right, sum - root->val);

    return count;
}


//Leetcode第687题:计算节点值相同的最多边数 (题目出的非常好)

//注意:这一题需要先从叶子节点计算，注意路径不能重复

int maxLen = 0;

int longestUnivaluePath(TreeNode *root)
{
    dfs(root);

    return maxLen;
}

int dfs(TreeNode *root) //符合要求的单条路径最大长度
{
    if(root == nullptr) return 0;

    int leftLen = dfs(root->left);      //左子树满足要求的长度
    int rightLen = dfs(root->right);    //右子树满足要求的长度

    //left表示根节点连同左子树的长度，right表示根节点连同右子树的长度
    int left = (root->left && root->left->val == root->val) ? leftLen + 1 : 0;
    int right = (root->right && root->right->val == root->val) ? rightLen + 1 : 0;

    maxLen = std::max(maxLen, left + right);

    return std::max(left, right);   //返回最大长度
}

//第124题: (题目出的非常好,仔细理解体会)

int res = INT_MIN;

int maxPathSum(TreeNode *root) 
{
    maxPathSumCore(root);

    return res;
}

int maxPathSumCore(TreeNode *root)  //返回的是包括根节点的单条子路径的最大和(包括根节点)
{
    if(root == nullptr) return 0;

    int leftMax = std::max(0, maxPathSumCore(root->left));
    int rightMax = std::max(0, maxPathSumCore(root->right));

    res = std::max(res, root->val + leftMax + rightMax);

    return root->val + std::max(maxLeft, maxRight);
}


//第543题: 返回二叉树的最大直径(也就是任意两个节点的最大距离)

//最大距离肯定是某个根节点到其左子树的最大长度和右子树的最大长度之和
//递归依次判断每个节点的的左右子树长度和即可

int maxDistance = INT_MIN;

int diameterOFBinary(TreeNode *root)
{
    if(root == nullptr) return 0;

    dfs(root);

    return maxDistance;
}

int dfs(TreeNode *root)     //这里返回的是包括根节点的单条子路径的最大节点数
{
    if(root == nullptr) return 0;

    int maxLeft = dfs(root->left), maxRight = dfs(root->right);

    maxDistance = std::max(maxDistance, maxLeft + maxRight);

    return 1 + std::max(maxLeft, maxRight);
}



//Leetcode第257题 : 打印二叉树的所有路径

std::vector<std::string> res;

std::vector<std::string> binaryTreePaths(TreeNode *root)
{
    std::string path;

    dfs(root, path);
    
    return res;
}

void dfs(TreeNode *root, std::string path)   //这里只能传递值,不能传引用
{
    if(root == nullptr) return;

    if(root->left == nullptr && root->right == nullptr) {
        path += std::to_string(root->val);
        res.push_back(path);
        return;                               //理论上这里返不返回都行,因为值传递,再次递归的结果不会影响到下一次递归结果
    }

    path += std::to_string(root-val) + "->";

    dfs(root->left, path);
    dfs(root->right, path);

}



//////////////////////////
//
//  计算二叉树的节点个数
//  
// 牛客NC62: 判断一个二叉树是否为平衡二叉树
//  第894题: All Possible Full Binary Trees(所有可能的full二叉树)
//
/////////////////////////


// 牛客NC62: 判断一个二叉树是否为平衡二叉树(不是BST)
// 自底而上判断,时间复杂度O(n)

bool isBalanced(TreeNode *root)
{
    if(root == nullptr) return true;

    return dfs(root) != -1;
}

int dfs(TreeNode *root)
{
    if(root == nullptr) return 0;

    int left = dfs(root->left);
    if(left == -1) return -1;

    int right = dfs(root->right);
    if(right == -1) return -1;

    return abs(left-right) > 1 ? -1 : std::max(left,right) + 1;
}




//计算普通二叉树的节点个数
//时间复杂度O(n)
int countNodes(TreeNode *root)
{
    if(root == nullptr) return 0;
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}


//计算满二叉树的节点个数
//时间复杂度O(logn)
int countNodes(TreeNode *root)
{
    int hei = 0;
    while(root) {
        hei++;
        root = root->left;
    }

    return (int)pow(2, hei) - 1;
}

// 计算完全二叉树的节点个数
// 递归算法的深度 = 程序递归的次数*每次执行所需的时间
// 因为完全二叉树一定会有一颗子树为满二叉树，所以 1 + countNodes(root->left) + countNodes(root->right) 只会有一个真的递归下去，另一个一定会触发 leftHei=rightHei而返回
// 所以递归深度就是树的高度logn,每次递归所花费的时间就是while循环，需要logn
// 时间复杂度O(logn*logn)

int countNodes(TreeNode *root)
{
    int leftHei = 0, rightHei = 0;

    TreeNode *cur = root;

    while(cur) {
        leftHei++;
        cur = cur->left;
    }

    cur = root;
    while(cur) {
        rightHei++;
        cur = cur->right;
    }

    //是完全二叉树
    if(leftHei == rightHei) {
        return (int)pow(2, leftHei) - 1;
    }

    //不是完全二叉树

    return 1 + countNodes(root->left) + countNodes(root->right);
}


//Leetcode第894题:所有可能的full二叉树(题目出的非常好)
//思路: 偶数个节点不可能构成full二叉树

std::vector<TreeNode*> allPossibleFBT(int n) 
{
    std::vector<TreeNode*> res;
    if(!(n&1)) return res;

    if(n == 1) {
        TreeNode *root = new TreeNode(0);
        res.push_back(root);
        return res;
    }

    n = n-1;    //排除掉根节点
    for(int i = 1; i <= n; i += 2)
    {
        std::vector<TreeNode*> L = allPossibleFBT(i);
        std::vector<TreeNode*> R = allPossibleFBT(n - i);

        for(auto &pLeft : L) {
            for(auto &pRight : R) {
                TreeNode *root = new TreeNode(0);
                root->left = pLeft;
                root->right = pRight;
                res.push_back(root);
            }
        }
    }

    return res;
}



/*
    求二叉树的最小深度和最大深度
    
    Leetcode第104题: 二叉树的最大深度
    Leetcode第559题: 多叉树的最大深度

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


//Leetcode第559题: 多叉树的最大深度

// 方法一：DFS

int maxDepth(Node *root)
{
    if(root == nullptr) return 0;

    int depth = 0;
    for(auto &node : root) {
        depth = std::max(depth, maxDepth(node));    
      //depth = std::max(depth, maxDepth(node) + 1);    //注意这里不能写成这样，因为可能root没有任何根节点，这样返回的结果就是depth的初值0,不是1
    }

    return depth + 1;
}

//或者写成这样
int maxDepth(Node *root)
{
    if(root == nullptr) return 0;

    int depth = 1;
    for(auto &node : root) {
        depth = std::max(depth, maxDepth(node) + 1);
    }

    return depth;
}


//方法二: BFS层序遍历判断二叉树高度

int maxDepth(Node *root)
{
    if(root == nullptr) return 0;

    int depth = 0;
    std::queue<Node*> que;
    que.push(root);

    while(!que.empty())
    {
        for(int size = que.size(); size > 0; size--)
        {
            auto cur = que.front(); que.pop();
            for(auto &node : cur->children) {
                que.push(node);
            }
        }

        depth++;
    }

    return depth;
}

