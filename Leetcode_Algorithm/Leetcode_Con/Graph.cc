
//dijkstra算法 <参考bigSai>的文章
//用来计算单源点到其他节点的最短距离

// 1.Djikstra处理的是带正权值的有权图,就需要一个二维数组存储各个点到边的权值大小
// 2.其次还需要一个boolean数组判断哪些点已经确定了最短长度,哪些点没有确定最短长度,以及用一个int数组来记录距离(因为求的是最短距离,初始这个距离值设定为无穷大)
// 3.需要优先队列加入已经确定的周围点; 每次抛出确定最短路径的那个并且确定最短,直到所有点路径确定最短为止

// 时间复杂度O(ElogV)
// 空间复杂度O(E+V)         需要将边的权值和节点都存储下来


struct Node {
    int id, len;          //节点编号以及到达该节点的距离
    Node(int m_id, int m_len): id(m_id), len(m_len) {}

    bool operator<(const Node &demo) const {    //注意重载 "< > + -" 这个const关键字一定要加,否则编译器报错,不加的话const对象无法调用
        return len > demo.len;                  //而且下面Node会被装进优先队列,优先队列实现是大顶堆,默认里面的元素是不允许修改的,都是const成员
    }
};

/*
struct Cmp {
    bool operator()(const Node &o1, const Node &o2) {   //最小堆
        return o1.len > o2.len;
    }
};
std::priority_queue<Node, std::vector<Node>, Cmp> pq;
*/


void dijkstra()
{
    std::vector<std::vector<int>> map(6, std::vector<int>(6, 0));  //用map来记录路径的权值
    initMap(map);   //初始化map临接矩阵

    std::vector<int> visited(6, 0);           //判断这个点是否已经确定
    std::vector<int> distance(6, INT_MAX);      //记录源节点到其他每个节点的距离

    std::priority_queue<Node> pq;
    distance[0] = 0;                            //从0这个点开始(0为起始点，距离当然为0)
    pq.push(Node(0, 0));

    while(!pq.empty())
    {
        Node tmp = pq.top(); pq.pop();
        int index = tmp.id;              //节点编号
        int len = tmp.len;               //节点长度
        visited[index] = 1;              //抛出的点已经确定

        //1.遍历这个点的邻居
        for(int i = 0; i < map[index].size(); i++)
        {
            //2.如果这个点的邻居没有被访问过
            if(map[index][i] > 0 && !visited[i]) {
                
                //3.计算(更新)到这个邻居点的距离,如果小于之前的距离则更新该点距离
                Node newNode = Node(i, len + map[index][i]);
                if(distance[i] > newNode.len) {             //只有0这个点distance是0,其他点的初始距离都是无穷大
                    distance[i] = newNode.len;              //找到离第i点最近的点
                    pq.push(newNode);
                }
            }
        }
    }

    for(int i = 0; i < 6; i++) {
        std::cout << distance[i] << " ";
    }
    std::cout << std::endl;

}

void initMap(std::vector<std::vector<int>> &map)
{
    map[0][1] = 2;  map[0][2] = 3;  map[0][3] = 6;
    map[1][0] = 2;  map[1][4] = 4;  map[1][5] = 6;
    map[2][0] = 3;  map[2][3] = 2;
    map[3][0] = 6;  map[3][2] = 2;  map[3][4] = 1;  map[3][5] = 3;
    map[4][1] = 4;  map[4][3] = 1;
    map[5][1] = 6;  map[5][3] = 3; 
}


//floyd算法:用来计算多源点之间的最短距离

const int max = 6666;

void floyed()
{
    std::vector<std::vector<int>> distance = {
    {0, 2, 3, 6, max, max},
    {2, 0, max, max,4,6},
    {3, max,0,2, max,max},
    {6, max,2,0,1,3},
    {max,4,max,1,0,max},
    {max,6,max,3,max,0}};

    for(int k = 0; k < 6; k++) 
    {
        for(int i = 0; i < 6; i++) {
            for(int j = 0 j < 6; j++) {     //这里得从0开始,不能从i+1开始,因为否则左下的元素不能更改
                distance[i][j] = std::min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            std::cout << distance[i][j] << " ";
        }
        std::cout << std::endl;
    }
}





/*
    旅行商问题
*/

#include <iostream>
#include <vector>

const int INF = 1e9;

int main() {
    int n = 5;
    int m = 1 << (n-1);
    int dp[n][m];

    int g[n][n] = {{0, 3, INF, 8, 9},
                   {3, 0, 3, 10, 5},
                   {INF, 3, 0, 4, 3},
                   {8, 10, 4, 0, 20},
                   {9, 5, 3, 20, 0}};

    //初始化dp[i][0]
    for(int i = 0; i < n; i++) {
        dp[i][0] = g[i][0];
    }


    //求解dp[i][j],先更新列再更新行
    for(int j = 1; j < m; j++)
    {
        for(int i = 0; i < n; i++)
        {
            dp[i][j] = INF;
            
            //如果集合j(或者状态j)中包含节点i,则不符合条件退出
            if(((j>>(i-1))&1) == 1) continue;

            //枚举集合j中的节点
            for(int k = 1; k < n; k++)
            {
                //如果集合中没有节点k,则退出
                if(((j>>(k-1))&1) == 0) continue;

                //使用异或运算去除掉集合j中的节点k
                if(dp[i][j] > g[i][k] + dp[k][j^(1<<(k-1))]) {
                    dp[i][j] = g[i][k] + dp[k][j^(1<<(k-1))];
                }
            }
        }
    }

    // std::cout << dp[0][m-1] << std::endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}





/*
    输出有向无环图的所有拓扑排序序列(必须掌握)
    图的例子参考印象笔记 <图>
*/

std::vector<int> path;
std::vector<std::vector<int>> res;

int main() {
    std::vector<std::vector<int>> prepre = {{1,2},{1,3},{2,4},{2,5},{3,4},{3,5},{4,6},{5,6}};
    int num = 6;

    for(auto &num : res) {
        for(auto &n : num) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


//prepre表示节点的关系,num表示图的节点个数
void topologySort(std::vector<std::vector<int>> &prere, int num)    
{
    std::vector<std::vector<int>> graph(num + 1);       //建立临接表(临接表与临接矩阵的区别在于临接表只存储与给定节点相邻的元素)
    std::vector<int> indegree(num + 1);                 //记录节点的入度(节点是从1开始编号的)

    for(auto &e : prere) {
        graph[e[0]].push_back(e[1]);
        indegree[e[1]]++;
    }

    std::vector<int> visited(num + 1, 0);

    dfs(num, graph, indegree, visited);

    return res;
}

//graph表示临接表,indegree表示每个节点的入度
void dfs(std::vector<std::vector<int>> &graph, int num, std::vector<int> &indegree, std::vector<int> &visited)
{
    if(path.size() == num) {
        res.push_back(path);
        return ;
    }

    for(int i = 1; i <= num; i++)
    {
        //该节点未遍历过,且度为0,则加入到结果中
        if(!visited[i] && indegree[i] == 0)
        {
            path.push_back(i);
            visited[i] = 1;
            for(const int &n : graph[i]) {
                indegree[n]--;
            }

            dfs(num, graph, indegree, visited);

            //回溯
            path.pop_back();
            visited[i] = 0;
            for(const int &n : graph[i]) {
                indegree[n]++;
            }
        }
    }

}




/*
    已知某无向图如图所示，输出该无向图从起点1遍历所有节点的不重复路径  
    注：拓扑排序和输出从图的某个起点到某个点的所有路径是不同的,拓扑排序是按照入度为0来逐个输出图的节点
       2--
      /| |
    1--3 |
     \ | |
       4--

    联结关系为 (1,2) (1,3) (1,4) (2,3) (2,4) (3,4)
*/

std::vector<int> path;
std::vector<std::vector<int>> res;

int main() {
    std::vector<std::vector<int>> prere = {{1,2}, {1,3}, {1,4}, {2,3}, {2,4}, {3,4}};
    int num = 4;

    allPaths(prere, num);

    return 0;
}

void allPaths(std::vector<std::vector<int>> &prere, int num)     //num代表节点个数
{
    std::vector<std::vector<int>> graph(num + 1);

    for(auto &e : prere) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    std::vector<int> visited(num + 1, 0);
    visited[1] = 1;
    path.push_back(1);  //从节点1出发

    dfs(graph, num, visited, 1);

}

void dfs(std::vector<std::vector<int>> &graph, int num, std::vector<int> &visited, int pos)
{
    if(path.size() == num) {
        res.push_back(path);
        return;
    }

    for(const int &n : graph[pos]) 
    {
        if(!visited[n]) {
            path.push_back(n);
            visited[n] = 1;

            dfs(graph, num, visited, n);

            path.pop_back();
            visited[n] = 0;
        }
    }

}





//////////////////////////////
//
//       拓扑排序
//
// 207题和210题: 课表(判断有向图是否存在环)
//       310题: 最小高度树(无向图的拓扑排序)
//
///////////////////////////////



//Leetcode第207题和210题: 课表(I,II)

// 1.拓扑排序:找到入度为0的节点,加入到队列中,依据临接矩阵的关系将相连节点的入度减1
//           判断减去后入度是否等于0,等于0接续加入队列
// 2.判断遍历过的节点数是否等于总的节点数

//方法一: 利用队列(BFS解法)

bool canFinsh(int n, std::vector<std::vector<int>> &prere)
{
    std::vector<std::vector<int>> graph(n); //临接矩阵
    std::vector<int> degree(n);     //记录各个节点的度
    
    std::queue<int> que;
    for(int i = 0; i < n; i++) {
        if(degree[i] == 0) que.push(i);
    }

    int count = 0;
    while(!que.empty())
    {
        int num = que.front();   que.pop();
        count++;

        for(const int &n : graph[num]) {
            if(--degree[n] == 0) que.push(n);
        }
    }

    return count == n;  //判断队列中访问的元素个数是否等于总的个数
}


//方法二: 不利用队列,将遍历过的节点直接存入到一个vector中,之后判断这个vector的元素个数

bool canFinsh(int num, std::vector<std::vector<int>> &prerequisites)
{
    std::vector<std::vector<int>> graph(num, std::vector<std::vector<int>>());  //邻接矩阵
    std::vector<int> degree(num);   //代表入度

    std::vector<int> ans;

    for(auto &e : prerequisites) {
        graph[e[1]].push_back(e[0]);  //加入邻接矩阵
        degree[e[0]]++;               //入度加1
    }

    //找到第一个入度为0的点即是起点
    for(int i = 0; i < num; i++) {
        if(degree[i] == 0) {
            ans.push_back(i);
        }
    }

    for(int i = 0; i < ans.size(); i++)
    {
        //依据邻接矩阵找到与起点相邻的节点,将节点入度减1
        for(int &n : graph[ans[i]]) {
            if(--degree[n] == 0) {      //邻接矩阵元素入度减1.如果度为0,则加入到结果中
                ans.push_back(n);
            }
        }
    }

    return ans.size() == num;       //把这里的判断返回值改成ans就是下面第210题的答案了
}



/*
    DFS解法
*/

std::unordered_map<int, std::vector<int>> graph;
std::vector<int> visited;
std::vector<int> onPath;

bool hasCircle = false;

bool canFinish(int num, std::vector<std::vector<int>> &prere)
{
    visited = std::vector<int>(num, 0);     //记录哪些节点已经遍历过
    onPath = std::vector<int>(num, 0);      //记录当前的搜索路径

    for(auto &e : prere) {
        graph[e[1]].push_back(e[0]);
    }

    //一个一个尝试遍历
    for(int i = 0; i < num; i++) {
        if(!visited[i]) dfs(i);
    }

    //是否存在环
    if(hasCircle) return false;

    //如果不存在环，判断每个节点是否都遍历到了
    for(int i = 0; i < num; i++) {
        if(!visited[i]) return false;
    }

    return true;
}
 
void dfs(int s)
{
    visited[s] = 1;     //记录当前
    onPath[s] = 1;      //选中

    for(const int &w : graph[s]) 
    {
        if(hasCircle) return ;
        else if(!visited[w]) dfs(w);
        else if(onPath[w]) hasCircle = true;
    }

    //回溯
    onPath[s] = false;
}



//Leetcode第210题: 课表II

//方法一: 拓扑排序利用队列
std::vector<int> findOrder(int num, std::vector<std::vector<int>> &prere)
{
    std::vector<std::vector<int>> graph(num);
    std::vector<int> degree(num);

    std::vector<int> res;
    std::queue<int> que;

    for(auto &e : prere) {
        graph[e[1]].push_back(e[0]);
        degree[e[0]]++;
    }

    for(int i = 0; i < num; i++) {
        if(degree[i] == 0) res.push_back(i);
    }

    while(!que.empty())
    {
        auto cur = que.front(); que.pop();
        res.push_back(cur);

        for(const int &n : graph[cur]) {
            if(--degree[n] == 0) que.push(n);
        }
    }

    return res.size() == num ? res : std::vector<int>();
}


//方法二: 将结果存入vector

std::vector<int> findOrder(int num, std::vector<std::vector<int>> &prere)
{
    std::vector<std::vector<int>> graph(num);   //邻接矩阵
    std::vector<int> degree(num);

    std::vector<int> ans;

    for(auto &e : prere) {
        graph[e[1]].push_back(e[0]);
        degree[e[0]]++;
    }

    for(int i = 0; i < num; i++) {
        if(degree[i] == 0) ans.push_back(i);
    }

    for(int i = 0; i < ans.size(); i++)
    {
        for(int &n : graph[ans[i]]) {
            if(--degree[n] == 0) {
                ans.push_back(n);
            }
        }
    }

    return ans.size() == num ? ans : std::vector<int>();
}
 

//Leetcode第310题 : 最小高度树
//1.拓扑排序,度为1的节点先全部加入到队列中,之后轮流出队列,将出队节点相邻的节点的度减1
//2.则最后一次队列中的节点就是结果

std::vector<int> findMinHieghtTrees(int n, std::vector<std::vector<int>> &edges)
{
    //只有一个节点则直接返回{0},否则下面会返回空
    if(n == 1) return {0};

    std::vector<std::vector<int>> graph(n);
    std::vector<int> degree(n);

    for(auto &e : edges) 
    {
        graph[e[0]].push_back(e[1]);
        degree[e[1]]++;

        graph[e[1]].push_back(e[0]);
        degree[e[0]]++;
    }

    std::queue<int> que;
    for(int i = 0; i < n; i++) {
        if(degree[i] == 1) que.push(i);
    }

    std::vector<int> res;

    while(!que.empty())
    {
        res.clear();        //这里不要忘记了
        for(int size = que.size(); size > 0; size--)
        {
            int cur = que.front(); que.pop();
            res.push_back(cur);

            for(const int &n : graph[cur]) {
                if(--degree[n] == 1) que.push(n);
            }
        }
    }

    return res;
}







//Leetcode490 : 走迷宫问题

//BFS解法
//注意中间路过的点不需要标记,只需要标记点终点即可

std::vector<int> dir = {-1, 0, 1, 0, -1};

bool hasPath(std::vector<std::vector<int>> &maze, std::vector<int> &start, std::vector<int> &dest)
{
    int m = maze.size(), n = maze[0].size();

    std::vector<std::vector<int>> visited(m, std::vector<int>(n, 0));

    std::queue<std::pair<int,int>> que;

    que.push({start[0], start[1]});
    visited[start[0]][start[1]] = 1;

    while(!que.empty())
    {
        auto cur = que.front(); que.pop();
        int x = cur.first, y = cur.second;

        if(x == dest[0] && y == dest[1]) return true;

        for(int i = 0; i < dir.size() - 1; i++)
        {
            //一直滚到到边界
            while(x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0) {
                x += dir[i], y += dir[i+1];
            }

            //将边界加入到队列中            
            x -= dir[i], y -= dir[i+1];

            if(!visited[x][y]) {
                que.push({x, y});
                visited[x][y] = 1;
            }
        }
    }

    return false;
}



//Leetcode第505题：到达迷宫终点的最短距离
// 额外定义一个数组用来记录到达边界的距离

int shorestDistance(std::vector<std::vector<int>> &maze, std::vector<int> &start, std::vector<int> &dest)
{
    int m = maze.size(), n = maze[0].size();

    std::vector<std::vector<int>> distance(m, std::vector<int>(n, 0));

    std::vector<std::vector<int>> visited(m, std::vector<int>(n, 0));
    std::queue<std::pair<int,int>> que;

    que.push({start[0], start[1]});
    visited[start[0]][start[1]] = 1;

    while(!que.empty())
    {
        auto cur = que.front(); que.pop();
        int x = cur.first, y = cur.second;

        //到达终点
        if(x == dest[0] && y == dest[1]) return distance[x][y];

        for(int i = 0; i < dir.size() - 1; i++)
        {
            int steps = 0;
            int px = x, py = y;

            //没遇到墙壁就持续滚直到遇到墙壁
            while(px >= 0 && px < m && py >= 0 && py < n && maze[px][py] == 0) {
                px += dir[i], py += dir[i+1];
                steps++;
            }            

            //将边界加入到队列中
            px -= dir[i], py -= dir[i+1], steps--;

            if(!visited[px][py]) {
                que.push({px, py});
                visited[px][py] = 1;
                distance[px][py] = distance[x][y] + steps;  //计算从上一位置滚到此边界的距离
            }
        }
    }

    return -1;
}


// Leetcode第778题 : 到达终点的最短时间
// BFS + 优先队列

struct T {
    int t, x, y;
    T(int m_t, int m_x, int m_y) : t(m_t), x(m_x), y(m_y) {}
    
    bool operator<(const T &demo) const {       
        return t > demo.t;
    }
};


int swimWater(std::vector<std::vector<int>> &grid)
{
    std::priority_queue<T> pq;

    pq.push(T(grid[0][0], 0, 0));

    int res = 0;

    int n = grid.size();

    std::vector<std::vector<int>> visited(n, std::vector<int>(n, 0));
    visited[0][0] = 1;

    std::vector<int> direction = {-1, 0, 1, 0, -1};

    while(!pq.empty())
    {
        auto demo = pq.top();   pq.pop();
        res = std::max(res, demo.t);        //记录最大值

        if(demo.x == n-1 && demo.y == n-1) return res;

        for(int i = 0; i < direction.size() -1; i++) {
            int px = demo.x + direction[i], py = demo.y + direction[i+1];
            if(px >= 0 && px < n && py >= 0 && py < n && !visited[px][py]) {
                pq.push(T(grid[px][py], px, py));
                visited[px][py] = 1;
            }
        }

    }

    return res;
}


