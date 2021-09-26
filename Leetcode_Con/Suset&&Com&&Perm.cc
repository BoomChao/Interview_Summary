/*
*
*   子集 组合 排列问题
*
*/


//子集 
//Leetcode第78题 第90题

// 1.先将第一个元素加入到集合中,再在剩下的元素中寻找新的集合
// 2.到达数组末尾就回溯

std::vector<std::vector<int>> res;

std::vector<std::vector<int>> subsets(std::vector<int> &nums)
{
    std::vector<int> path;

    dfs(nums, 0, path);

    return res;
}

void dfs(std::vector<int> &nums, int pos, std::vector<int> &path)
{
    res.push_back(path);

    for(int i = pos; i < nums.size(); i++) 
    {
        path.push_back(nums[i]);
        dfs(nums, i + 1, path);
        path.pop_back();
    }

}



//组合问题 Leetcode第77题

std::vector<std::vector<int>> res;

std::vector<std::vector<int>> combine(int n, int k)
{
    if(n <= 0 || k <= 0) return res;

    std::vector<int> path;
    
    dfs(n, k, 1, path);

    return res;
}

void dfs(int n, int k, int pos, std::vector<int> &path)
{
    if(path.size() == k) {
        res.push_back(path);
        return;
    }

    for(int i = pos; i <= n; i++) 
    {
        path.push_back(i);
        dfs(n, k, i + 1, path);
        path.pop_back();
    }

}




//排列问题  Leetcode第46题:排列I(不包含重复元素)
//两种解法

//方法一:与首部元素交换,之后剩下的元素做全排列

std::vector<std::vector<int>> res;

std::vector<std::vector<int>> permute(std::vector<int> &nums)
{
    dfs(nums, 0);

    return res;
}

void dfs(std::vector<int> &nums, int pos)
{
    if(pos == nums.size()) {
        res.push_back(nums);
        return;
    }

    for(int i = pos; i < nums.size(); i++) 
    {
        swap(nums[pos], nums[i]);
        dfs(nums, pos + 1);         //交换位置以后的元素再做全排列(注意:这里是pos+1,不是i+1)
        swap(nums[pos], nums[i]);
    }

}


//方法二:递归遍历,如果包含重复元素则不加入数组

std::vector<std::vector<int>> res;

std::vector<std::vector<int>> permute(std::vector<int> &nums)
{
    std::vector<int> path;

    dfs(nums, path);

    return res;
}

void dfs(std::vector<int> &nums, std::vector<int> &path)
{
    if(path.size() == nums.size()) {
        res.push_back(path);
        return ;
    }

    for(int i = 0; i < nums.size(); i++)
    {
        //path中已经存在该元素,直接选择跳过该元素
        if(find(path.begin(), path.end(), nums[i]) != path.end()) continue;

        path.push_back(nums[i]);
        dfs(nums, path);
        path.pop_back();
    }

}



//Leetcode第47题:排列II(含有重复元素)

//方法一:
std::vector<std::vector<int>> res;

std::vector<std::vector<int>> permutation(std::vector<int> &nums)
{
    dfs(nums, 0);

    return res;
}

void dfs(std::vector<int> &nums, int pos)
{
    if(pos == nums.size()) {
        res.push_back(nums);
        return;
    }

    std::unordered_set<int> mySet;

    for(int i = pos; i < nums.size(); i++) 
    {
        if(mySet.count(nums[i])) continue;  //表示以该元素开头的组合只能有一个
        mySet.insert(nums[i]);
    
        std::swap(nums[i], nums[pos]);
        dfs(nums, pos + 1);
        std::swap(nums[i], nums[pos]);
    }

}


//方法二:值传递,交换后不能再次交换回来(不好理解)

std::vector<std::vector<int>> permutation(std::vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    dfs(nums, 0);

    return res;
}

void dfs(std::vector<int> nums, int pos)
{
    if(pos == nums.size()) {
        res.push_back(nums);
        return;
    }

    for(int i = pos; i < nums.size(); i++) {
        if(i > pos && nums[i] == nums[pos]) continue;
        std::swap(nums[i], nums[pos]);
        dfs(nums, pos + 1);
    }

}

