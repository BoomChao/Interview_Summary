
/*
    并查集

    第547题 : 相连的省份
    第684题 : 返回能够构成树的第一个边

    第399题 : 计算除法(较难)
*/

class UF
{
private:
    int count;                  //连通分量个数
    std::vector<int> parent;    //存储一棵树
    std::vector<int> size;      //记录每棵树的重量

public:
    UF(int n) 
    {
        count = n;
        parent.resize(n);
        size.resize(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    void unionNode(int p, int q) 
    {
        int rootP = findNode(p);
        int rootQ = findNode(q);

        //已经在一颗树上了就不用再联结了
        if(rootP == rootQ) return;

        //小树接到大树下面,较平衡
        if(size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }

        count--;    //连通分量减1
    }

    int findNode(int x) 
    {
        while(parent[x] != x) {
            parent[x] = parent[parent[x]];  //这样可以压缩路径,一下走两步
            x = parent[x];
        }

        return x;
    }

    bool connected(int p, int q)
    {
        int rootP = findNode(p);
        int rootQ = findNode(q);
        
        return rootP == rootQ;
    }

    //返回连通分量个数
    int countNum() {
        return count;
    }
    
};


//Leetcode第547题 : 相连的省份

//方法一:使用并查集

int findCircleNum(std::vector<std::vector<int>> &isConnected)
{
    int n = isConnected.size();

    UF uf(n);

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(isConnected[i][j]) {
                uf.unionNode(i, j);
            }
        }
    }

    return uf.countNum();
}






/*
    求数组的交集,合并所有的子数组,最终返回一个互相没有交集的数组列表

    如数组 arr = {{1,2,3}, {3,5,4}, {8,6}, {3,6}, {7,222}, {7,32}}
    返回 {{1,2,3,5,4,6,8}, {7,222,32}}
*/


std::map<int,int> parent;       //注意这个父节点存的是当前父亲，比如 {8,6}, parent[6]=8, {3,6}, 合并后parent[8]=3, 虽然6,8的祖节点都是3，但是parent[6]还是等于8
                                
std::map<int,std::vector<int>> mp;

int findNode(int x)
{
    while(parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }

    return x;
}

void unionNode(int x, int y)
{
    if(!parent.count(x)) {
        parent[x] = x;
    }
    if(!parent.count(y)) {
        parent[y] = y;
    }

    int m_x = findNode(x);
    int m_y = findNode(y);

    parent[m_y] = m_x;
}

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &arr)
{
    std::vector<std::vector<int>> res;
 
    for(auto &nums : arr)
    {
        if(nums.size() == 1) mp[nums[0]].push_back(nums[0]);
        else {
            for(int i = 1; i < nums.size(); i++)
            {
                unionNode(nums[0], nums[i]);
            }
        }
    }

    for(auto &item : parent) {
        mp[findNode(item.first)].push_back(item.first);     //注意这个一定是mp[findNode(item.first)], 不要写成parent[item.second],因为这个parent不一定是祖节点
    }

    for(auto item : mp) {
        res.push_back(item.second);
    }

    return res;
}
