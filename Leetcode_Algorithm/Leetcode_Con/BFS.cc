

//////////////////////////////
//       BFS
//   
//      第127题: Word Ladder
//      第126题: Word Ladder II
//      第542题: 01 Matrix
//      第773题: 2X3滑动谜题
//      第752题: 最小的开锁次数 
//      第778题: 到达终点的最短时间
//
//////////////////////////////



//Leetcode第127题 : word Ladder (词序阶梯)

int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList)
{
    std::unordered_set<std::string> mySet(wordList.begin(), wordList.end());

    if(!mySet.count(endWord)) return 0;
    if(beginWord == endWord) return 1;
    
    std::queue<std::string> que;
    que.push(beginWord);
    mySet.erase(beginWord);

    int steps = 1;

    while(!que.empty())
    {
        for(int size = que.size(); size > 0; size--)
        {
            std::string cur = que.front(); que.pop();

            //这里必须传递引用,否则更改不了
            for(char &c : cur)
            {
                char ch = c;
                for(int k = 0; k < 26; k++) {
                    c = k + 'a';
                    if(mySet.count(cur)) {
                        if(cur == endWord) return steps + 1;
                        que.push(cur);
                        mySet.erase(cur);
                    }
                }
                c = ch;
            }
        }

        steps++;
    }

    return 0;
}


//双向BFS搜索
int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList)
{
    std::unordered_set<std::string> beginSet, endSet, wordSet(wordList.begin(), wordList.end());

    //这个一定要判断，下面没有判断这个特殊例子
    if(!wordSet.count(endWord)) return 0;

    beginSet.insert(beginWord);
    endSet.insert(endWord);
    wordSet.erase(beginWord);
    wordSet.erase(endWord);

    int steps = 1;

    while(!beginSet.empty() && !endSet.empty())
    {
        //始终从元素少的一方遍历
        if(beginSet.size() > endSet.size()) std::swap(beginSet, endSet);

        std::unordered_set<std::string> tmp;
        for(auto &cur : beginSet) 
        {
            std::string word = cur;
            for(int i = 0; i < word.size(); i++)
            {
                char c = word[i];
                for(int k = 0; k < 26; k++) 
                {
                    word[i] = k + 'a';
                    if(endSet.count(word)) return steps + 1;    //注意返回的是 steps+1
                    
                    //如果这个新单词没有被遍历过并且属于wordList，则加入到tmp中
                    if(wordSet.count(word)) {
                        tmp.insert(word);
                        wordSet.erase(word);
                    }
                }
                word[i] = c;
            }
        }

        beginSet = tmp;     //将开始集合赋值为新的集合
        steps++;
    }

    return 0;
}


//第126题: Word Ladder II
//求最短路径

std::vector<std::vector<std::string>> findLadders(std::string beginWord, std::string endWord, std::vector<std::string> &wordList)
{
    std::vector<std::vector<std::string>> ans;
    std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
    
    if(!wordSet.count(endWord)) return ans;

    wordSet.erase(beginWord);
    wordSet.erase(endWord);
    
    std::unordered_set<std::string> beginSet = {beginWord}, endSet = {endWord};

    std::unordered_map<std::string, std::vector<std::string>> next;

    bool reversed = false, found = false;

    while(!beginSet.empty() && !endSet.empty())
    {
        //始终让beginSet中的元素最少
        if(beginSet.size() > endSet.size()) {
            std::swap(beginSet, endSet);
            reversed = !reversed;           //注意这里交换后要逆序
        }

        std::unordered_set<std::string> tmp;

        for(auto &cur : beginSet)
        {
            std::string word = cur;
            
            for(char &c : word) {
                char ch = c;
                for(int k = 0; k < 26; k++) {
                    c = k + 'a';
                    if(endSet.count(word)) {
                        reversed ? next[word].push_back(cur) : next[cur].push_back(word);
                        found = true;
                    }
                    if(wordSet.count(word)) {
                        reversed ? next[word].push_back(cur) : next[cur].push_back(word);
                        tmp.insert(word);
                    }
                }
                c = ch;
            }
        }

        if(found) break;

        //将遍历过的字符全部从原有给定集合中删除
        for(auto &w : tmp) {
            wordSet.erase(w);
        }

        beginSet = tmp;
    }

    if(found) {
        std::vector<std::string> path = {beginWord};
        dfs(beginWord, endWord, next, path, ans);
    }

    return ans;
}

void dfs(std::string src, std::string des, std::unordered_map<std::string, std::vector<std::string>> &next, std::vector<std::string> &path, std::vector<std::vector<std::string>> &ans)
{
    if(src == des) {
        ans.push_back(path);
        return;
    }

    for(const auto &s : next[src]) {
        path.push_back(s);
        dfs(s, des, next, path, ans);
        path.pop_back();
    }

}



//Leetcode第542题: 01 Matrix

//方法一:
//BFS搜索,将所有的'0'加入到队列中,之后判断0到其周边元素的距离
//1.新的距离大于已有距离时不用更新
//2.将所有不是0的点距离全部写成INF

std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();

    std::queue<std::pair<int,int>> que;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matirx[i][j] == 0) {
                que.push({i,j});
            }
            else matrix[i][j] = INT_MAX;        //否则中间被1包围的节点改变不了
        }
    }

    std::vector<int> dir = {-1,0,1,0,-1};

    while(!que.empty())
    {
        auto cur = que.front(); que.pop();

        for(int k = 0; k < dir.size() - 1; k++) {
            int x = cur.first + dir[k], y = cur.second + dir[k+1];
            if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[cur.first][cur.second] + 1) {
                que.push({x, y});
                matrix[x][y] = matrix[cur.first][cur.second] + 1
            }
        }
    }

    return mat;
}


//方法二:动态规划

std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, m*n));  //这里写成INF下面相加会溢出

    //从左上到右下
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == 0) dp[i][j] = 0;
            else {
                if(j > 0) dp[i][j] = std::min(dp[i][j], dp[i][j-1] + 1);    // -->
                if(i > 0) dp[i][j] = std::min(dp[i][j], dp[i-1][j] + 1);    //  |
            }                                                               
        }
    }

    //从右下到左上 dp[0][0] 位置在这里被计算
    for(int i = m-1; i >= 0; i--) {
        for(int j = n -1; j >= 0; j--) {
            if(mat[i][j]) {
                if(j < n-1) dp[i][j] = std::min(dp[i][j], dp[i][j+1] + 1);
                if(i < m-1) dp[i][j] = std::min(dp[i][j], dp[i+1][j] + 1);
            }
        }
    }

    return dp;
}



//Leetcode第773题 : 2X3滑动谜题

//思路:BFS
//相当于寻找字符串到指定字符串的交换次数,广度优先搜索记录搜索的层数就行

// 1.确定'0'在各个位置能够移动的方向
// 2.将所有方向得到的可能结果加入到队列中(用hash去重)
// 3.弹出队首元素,判断是否等于目标,再重复2,3两个过程

int slidingPuzzle(std::vector<std::vector<int>> &board)
{
    int m = board.size(), n = board[0].size();

    std::string target = "123450";

    std::string start = "";
    for(auto &nums : board) {
        for(auto &n : nums) {
            start += std::to_string(n);
        }
    }

    std::vector<std::vector<int>> dir = {{1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}}; //以此代表每个字符的移动方向

    std::unordered_set<std::string> visited;
    std::queue<std::string> que;
    que.push(start);
    visited.insert(start);      //记录遍历过的字符串

    int steps = 0;

    while(!que.empty())
    {
        for(int size = que.size(); size > 0; size--)
        {
            auto cur = que.front(); que.pop();

            if(cur == target) return steps;

            int index = cur.find('0');

            for(int &n : dir[index]) 
            {
                std::swap(cur[index], cur[n]);
                if(!visited.count(cur)) {
                    que.push(visited);
                    visited.insert(cur);
                }
                std::swap(cur[index], cur[n]);
            }
        }
        
        steps++;
    }

    return -1;
}



// Leetcode第752题 : 最小的开锁次数 
// BFS双向搜索速度更快

int openLock(std::vector<std::string> &deadends, std::string target)
{
    std::unordered_set<std::string> deadSet(deadends.begin(), deadends.end());

    std::string start = "0000";

    if(deadSet.count(start) || deadSet.count(target)) return -1;
    if(start == target) return 0;

    std::queue<std::string> que;
    std::unordered_set<std::string> visited;          //记录已经遍历过的组合

    que.push(start);
    visited.insert(start);

    int steps = 0;

    while(!que.empty())
    {
        int size = que.size();

        for(int size = que.size(); size > 0; size--)
        {
            std::string cur = que.front(); que.pop();

            if(cur == target) return steps;

            std::vector<std::string> nextStrings = next(cur);   //当前字符一共有多少种变换方式

            for(auto str : nextStrings) 
            {
                if(deadSet.count(str)) continue;
                if(visited.count(str)) continue;

                que.push(str);
                visited.insert(str);
            }
        }

        steps++;
    }

    return -1;
}

std::vector<std::string> next(const std::string &str)
{
    std::vector<std::string> res;

    for(int i = 0; i < 4; i++)
    {
        std::string tmp = str;

        tmp[i] = (str[i] - '0' + 1)%10 + '0';   //往前转动一个数字
        res.push_back(tmp);

        tmp[i] = (str[i] - '0' - 1 + 10)%10 + '0';  //往后转动一个数字
        res.push_back(tmp);
    }

    return res;
}


//改进:双向BFS(思路非常好,仔细体会)

int openLock(std::vector<std::string> deadends, std::string target)
{
    std::unordered_set<std::string> deadSet(deadends.begin(), deadends.end());
    std::unordered_set<std::string> q1, q2, visited;

    std::string start = "0000";

    if(deadSet.count(start) || deadSet.count(target)) return -1;
    if(start == target) return 0;       //下面这种初始情况没有判断,这里需要先判断这种初始情况

    visited.insert(start);
    q1.insert(start), q2.insert(target);

    int steps = 0;

    while(!q1.empty() && !q2.empty())
    {
        if(q1.size() > q2.size()) std::swap(q1, q2);    //从小的集合中开始搜索
        pass.clear();

        std::unordered_set<std::string> tmp;

        for(auto &str : q1) 
        {   
            for(auto &s : next(str)) {
                if(q2.count(s)) return ++res;       //这个返回语句必须放在这里，否则过不了(q1和q2存储都是有效的字符串,不会包含在deadSet中)

                //已经遍历过的字符串或者deadSet中的字符串就不需要在放入到q1中了
                if(visited.count(s)) continue;
                if(deadSet.count(s)) continue;

                tmp.insert(s);
                visited.insert(s);
            }
        }

        q1 = tmp;     //将新的集合重新赋值给q1
        steps++;
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


//////////////////////////////////
//
//      第1293题: 障碍消除游戏
//
//
//
///////////////////////////////////


// Leetcode第1293题: 障碍消除游戏

int shortestPath(std::vector<std::vector<int>> &grid, int k)
{
    int m = grid.size(), n = grid[0].size();

    //存储当前位置可以消除的最大障碍数,这里初始化的值不能定义为0(思考为什么不能初始化为0)
    std::vector<std::vector<int>> visited(m, std::vector<int>(n, -1));

    std::queue<std::vector<int>> que;

    que.push({0, 0, 0, k});

    while(!que.empty())
    {
        auto t = que.front(); que.pop();
        int x = t[0], y = t[1];

        if(x < 0 || x >= m || y < 0 || y >= n) continue;

        if(x == m-1 && y == n-1) return t[2];

        if(grid[x][y] == 1) {
            if(t[3] > 0) t[3]--;        //遇到了障碍,就将其减1
            else continue;              //如果当前点没有值可供消除了,则继续下一个点判断
        }        

        //如果这个单元之前走过,且之前从该点路过的路径可以消除更多的障碍,则没必要再一次从这点路过,直接跳过去
        if(visited[x][y] != -1 && visited[x][y] >= t[3]) continue;

        visited[x][y] = t[3];

        que.push({x + 1, y, t[2] + 1, t[3]});
        que.push({x - 1, y, t[2] + 1, t[3]});
        que.push({x, y + 1, t[2] + 1, t[3]});
        que.push({x, y - 1, t[2] + 1, t[3]});

    }

    return -1;
}
