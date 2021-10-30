

//Leetcode第108题:Convert Sorted Array to Binary Search Tree
//将排序数组转换成平衡二叉树


TreeNode* sortedArrayToBST(std::vector<int> &nums)
{
    if(nums.empty()) return nullptr;

    return sortedArrayToBSTCore(nums.begin(), nums.end());

}

//解法一
//C++解法
//对容器而言,迭代器就相当于数组的指针

TreeNode* sortedArrayToBSTCore(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    if(start >= end) {
        return nullptr;
    }

    //以后无论是利用指针寻找数组的中位数,还是计算两个数之间的中位数,都建议采用这种写法
    std::vector<int>::iterator middle = start + (end - start)/2;    //指针不能相加,只能相减,指针相减返回的是这两个指针指向的元素个数差

    TreeNode *node = new TreeNode(*middle);

    node->left = sortedArrayToBSTCore(start, middle);
    node->right = sortedArrayToBSTCore(middle + 1, end);

    return node;

}

//如果我想取两个数的中位数,比如num1和num2的中位数
//理论上可以这么做:int mid = (num1+num2)/2;
//但是这里如果num1=INT_MAX,num2=1,那么num1+num2就溢出了,
//所以建议使用 mid = num1 + (num2-num1)/2; 这样就不存在溢出的情况,所以以后 (num1+num2)/2这种写法要抛弃掉



//解法二
//不使用迭代器

TreeNode* sortedArrayToBST(std::vector<int> &nums)
{
    if(nums.empty()) return nullptr;

    //这里的区间是(0, nusm.size())
    return sortedArrayToBSTCore(nums, 0, nums.size());

}

TreeNode* sortedArrayToBSTCore(std::vector<int> &nums, int left, int right)
{
    if(left >= right) {
        return nullptr;
    }

    int mid = left + (right - left)/2;
    
    TreeNode *node = new TreeNode(nums[mid]);

    node->left = buildTreeCore(nums, left, mid);
    node->right = buildTreeCore(nums, mid + 1, right);

    return node;

}



//上面的区间改进,不是从(0,nums.size())而是从(0, nums.size()-1)
TreeNode* sortedArrayToBST(std::vector<int> &nums)
{
    if(nums.empty()) return nullptr;

    //这里的区间是(0, nusm.size())
    return sortedArrayToBSTCore(nums, 0, nums.size()-1);

}

TreeNode* sortedArrayToBSTCore(std::vector<int> &nums, int left, int right)
{
    if(left > right) {
        return nullptr;
    }

    int mid = left + (right - left)/2;
    
    TreeNode *node = new TreeNode(nums[mid]);

    node->left = buildTreeCore(nums, left, mid-);
    node->right = buildTreeCore(nums, mid + 1, right);

    return node;

}
