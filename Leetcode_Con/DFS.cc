
/*
    DFS:深度优先搜索
    93题  : 复原IP地址
    200题 : 岛屿的数量
    301题 : 删除多余的括号                  (见string分类中的括号匹配总结)
    417题 : 搜索能到同时流到两个大洋的节点坐标
    463题 : 岛屿的周长
    695题 : 海洋中岛屿的最大面积
    733题 : 边缘填充
    526题 : 最美排列
    827题 : 添加一个1组成最大的岛屿面积

    79题  : 在矩阵中搜索指定的单词
    329题 : 矩阵中的最长增长路径(注意:四个方向搜索的时候取得是四个方向中的最大值)
    698题 : 等分成k个和相同的子数组

    第473题: 拼接火柴棍成正方形 (第698题:切分成和相等的k个数组)

    第1219题 : 黄金旷工
*/

//Leetcode93题:复原IP地址

std::vector<std::string> res;

std::vector<std::string> restoreIpAddresses(std::string s)
{
    std::string path;

    dfs(s, 0, 0, path);

    return res;
}

void dfs(std::string s, int pos, int num, std::string path)
{
    if(num > 4) return;     //一定注意需要减枝，否则会超时

    if(pos == s.size() && num == 4) {
        path.pop_back();
        res.push_back(path);
        return;
    }

    for(int i = 1; i <= 3 && pos + i <= s.size(); i++)
    {
        std::string tmp = s.substr(pos, i);
        
        if(tmp[0] == '0' && i != 1) return;         //这里用continue也可以,但是i是自增的,后面的i肯定也不满足,直接返回就可以   

        if(std::stoi(tmp) <= 255) {
            dfs(s, pos + i, num + 1, path + tmp + ".");
        }
    }

}


//Leetcode第200题:岛屿数量

// 思路 : 遇到'1'就向四周发散,只要四周存在'1',就将其置为'0'

// DFS和BFS都是这个思想,只不过DFS先一条道走到黑,将一个方向上的'1'全部置为'0'后再去搜索下一个方向
// 而BFS是先将周围的'1'全部置为'0',再将外圈的'1'置为'0',是一个由里及外的过程

//解法一 : DFS
int numIslands(std::vector<std::vector<char>> &grid)
{
    int count = 0;

    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == '1') {
                count++;
                dfs(grid, i, j);
            }
        }
    }

    return count;
}

void dfs(std::vector<std::vector<char>> &grid, int i, int j)
{
    int m = grid.size(), n = grid[0].size();

    if(i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == '1') 
    {
        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i , j + 1);
        dfs(grid, i, j - 1);
    }

}


//解法二 : BFS
std::vector<int> direction = {-1, 0, 1, 0, -1};

int numIslands(std::vector<std::vector<char>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    int island = 0;

    for(int i = 0; i < m; i++) 
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == '1')
            {
                island++;
                grid[i][j] = '0';

                std::queue<std::pair<int,int>> que;
                que.push({i,j});

                while(!que.empty())
                {
                    std::pair<int,int> p = que.front();  que.pop();

                    for(int i = 0; i < direction.size() - 1; i++) {
                        int r = p.first + direction[i], c = p.second + direction[i+1];
                        if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                            grid[r][c] = '0';                                           //放在这里可以加速
                            que.push({r, c});
                        }
                    }
                }
            }
        }
    }

    return island;
}


//Leetcode第301题 : 典型的DFS

std::vector<std::string> res;

std::vector<std::string> removeInvalidParentheses(std::string s)
{
    //先统计需要删除多少个左右括号
    //之后挨个尝试删除确定个数的左右符号
    //检查删除后的字符串是否满足要求.如果满足就加入到结果中

    int left = 0, right = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            left++;
        }
        else if(s[i] == ')') {
            if(left > 0) left--;
            else right++;
        }
    }
    
    dfs(s, 0, left, right);

    return res;
}

void dfs(std::string s, int left, int right, int pos)
{
    if(left < 0 || right < 0) return false;     //减枝

    if(left == 0 && right == 0) {
        if(isValid(s)) {
            res.push_back(s);
            return;
        }
    }

    for(int i = pos; i < s.size(); i++)
    {
        if(i > pos && s[i] == s[i-1]) continue;     // 比如 "((())", 前面连续的"((("只需要删除第一个就行，不需要三个都尝试删除

        //尝试删除一个'('
        if(s[i] == '(') {
            dfs(s.substr(0, i) + s.substr(i + 1), left - 1, right, i);  //注意：这里的i不能进位，因为删除后i恰好指向下一个新的字符了
        }
        //尝试删除一个')'
        else if(s[i] == ')') {
            dfs(s.substr(0, i) + s.substr(i + 1), left, right - 1, i);
        }
    }

}

bool isValid(const std::string &s)
{
    //统计左括号'('的数目
    int left = 0;

    for(const char &c : s) {
        if(c == '(') left++;
        else if(c == ')') {
            if(left == 0) return false;
            else left--;
        }
    }

    return left == 0;
}




//Leetcode第417题
//从四周开始搜索到两个大洋的路径,之后一次遍历找出满足条件的位置

std::vector<int> direction = {-1,0,1,0,-1};

std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>> &matirx)
{
    std::vector<std::vector<int>> res;

    if(matirx.empty() || matirx[0].empty()) return res;

    int m = matirx.size(), n = matirx[0].size();
    std::vector<std::vector<int>> can_reach_p(m, std::vector<int>(n, 0)), can_reach_a(m, std::vector<int>(n, 0));

    //从左右两列开始寻找
    for(int i = 0; i < m; i++) {
        dfs(matirx, can_reach_p, i, 0);
        dfs(matirx, can_reach_a, i, 0);
    }

    //从上下两行开始寻找
    //注意:不要写成for(int j = 1; j < n-1; j++) 上边界的每个元素都可以到达P,下边界的每个元元素都可以到达a
    for(int j = 0; j < n; j++) {
        dfs(matirx, can_reach_p, 0, j);
        dfs(matirx, can_reach_a, m-1, j);
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(can_reach_a[i][j] && can_reach_p[i][j]) {
                res.push_back(std::vector<int>{i, j});
            }
        }
    }

    return res;
}

void dfs(std::vector<std::vector<int>> &matirx, std::vector<std::vector<int>> &can_reach, int i, int j)
{
    int m = matirx.size(), n = matirx[0].size();
 
    if(can_reach[i][j]) return;

    can_reach[i][j] = 1;

    for(int k = 0; k < direction.size() - 1; k++) 
    {
        int x = i + direction[i], y = j + direction[i+1];
        if(x >= 0 && x < m && y >= 0 && y < n && matirx[x][y] >= matirx[i][j]) {
            dfs(matirx, can_reach, x, y);
        }
    }

}

//Leetcode第463题:岛屿的周长

//方法一:DFS(这是最快的,因为其只会搜索标记位为1的块)

std::vector<int> direction = {-1, 0, 1, 0, -1};

int islandPerimeter(std::vector<std::vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) {
                return dfs(grid, i, j);
            }
        }
    }

    return 0;
}

int dfs(std::vector<std::vector<int>> &grid, int i, int j)
{
    int m = grid.size(), n = grid[0].size();
    
    grid[i][j] = -1;        //注意:不能标记为0

    int count = 0;
    for(int k = 0; k < direction.size() - 1; k++) 
    {
        int x = i + direction[k], y = j + direction[k+1];
        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) count++; 
        else if(grid[i][j] == 1) {
            count += dfs(grid, x, y);
        }
    }
    
    return count;
}


//方法二:两个块只可能有两种相邻的方式,上下相邻或者左右相邻
//则总的边数 = 总的块数 - 2*(左邻居加上右邻居的和)

int islandPerimeter(std::vector<std::vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    int count = 0;
    int neighbor = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) 
            {
                count++;
                if(i+1 < m && grid[i+1][j] == 1) neighbor++;
                if(j+1 < n && grid[i][j+1] == 1) neighbor++;
            }
        }
    }

    return 4*count - 2*neighbor;
}


//方法三:遍历每个标志为1的小方格,计算该小方格旁边空格就行
//这种方法最好理解

std::vector<int> direction = {-1, 0, 1, 0, -1};

int islandPerimeter(std::vector<std::vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    int count = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1)
            {
                for(int k = 0; k < direction.size()-1; k++) 
                {
                    int x = i + direction[k], y = j + direction[k+1];
                    if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) count++;
                }
            }
        }
    }
    
    return count;
}


//Leetcode第695题 : 海洋中岛屿的最大面积

//方法一:

std::vector<int> direction = {-1,0,1,0,-1};

int maxAreaOfLands(std::vector<std::vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) {
                res = std::max(res, dfs(grid, i, j));
            }
        }
    }

    return res;
}

int dfs(std::vector<std::vector<int>> &grid, int i, int j)
{
    int m = grid.size(), n = grid[0].size();

    grid[i][j] = 0;

    int count = 1;
    for(int k = 0; k < direction.size() - 1; k++)
    {
        int x = i + direction[k], y = j + direction[k+1];
        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) continue;
        else {
            count += dfs(grid, x, y);
        } 
    }

    return count;
}


//方法二:更加简洁

int maxAreaOfLands(std::vector<std::vector<int>> &grid)
{
    int res = 0;
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            res = std::max(res, dfs(grid, i, j));
        }
    }

    return res;
}

int dfs(std::vector<std::vector<int>> &grid, int i, int j)
{
    if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1) 
    {
        grid[i][j] = 0;

        return 1 + dfs(grid, i+1, j) + dfs(i-1, j) + dfs(i, j+1) + dfs(i, j-1);
    }

    return 0;
}


//Leetcode第733题: 边缘填充

std::vector<int> direction = {-1, 0, 1, 0, -1};

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>> &image, int sr, int sc, int newColor)
{
    int m = image.size(), n = image[0].size();

    int srcColor = image[sr][sc];

    if(srcColor == newColor) return image;  //新颜色和原来颜色相同就不需要替换

    dfs(image, sr, sc, srcColor, newColor);

    return image;
}

void dfs(std::vector<std::vector<int>> &image, int i, int j, int srcColor, int newColor)
{
    int m = image.size(), n = image[0].size();

    image[i][j] = newColor;

    for(int k = 0; k < direction.size() - 1; k++) 
    {
        int x = i + direction[k], y = j + direction[k+1];
        if(x >= 0 && x < m && y >= 0 && y < n && image[x][y] == srcColor) {
            dfs(image, x, y, srcColor, newColor);
        }
    }

}

void dfs(std::vector<std::vector<int>> &image, int i, int j, int srcColor, int newColor)
{
    int m = image.size(), n = image[0].size();

    if(i >= 0 && i < m && j >= 0 && j < n && image[i][j] == srcColor)
    {
        image[i][j] = newColor;

        dfs(image, i, j + 1, srcColor, newColor);
        dfs(image, i, j - 1, srcColor, newColor);
        dfs(image, i + 1, j, srcColor, newColor);
        dfs(image, i - 1, j, srcColor, newColor);
    }

}


//Leetcode第526题:最美排列

int count = 0;

int countArranges(int n)
{
    std::vector<int> visited(n + 1, 0);

    dfs(n, 1, visited);

    return count;
}

void dfs(int n, int pos, std::vector<int> &visited)
{
    if(pos > n) {
        count++;
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i] && (pos%i == 0 || i%pos == 0)) {
            visited[i] = 1;
            dfs(n, pos + 1, visited);
            visited[i] = 0;
        }
    }
}


//Leetcode第79题:在矩阵中搜索指定的单词

//方法一:
std::vector<int> direction = {-1, 0, 1, 0, -1};

bool exist(std::vector<std::vector<char>> &board, std::string word)
{
    if(board.empty()) return false;

    int m = board.size(), n = board[0].size();

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == word[0] && dfs(board, i, j, word, 0)) {
                return true;
            }
        }
    }

    return false;
}

bool dfs(std::vector<std::vector<char>> &board, int i, int j, std::string &word, int pos)
{
    int m = board.size(), n = board[0].size();

    if(pos == word.size() - 1) return true;

    board[i][j] = '#';

    bool find = false;

    for(int k = 0; k < direction.size() - 1; k++) {
        int x = i + direction[k], y = j + direction[k+1];
        if(x >= 0 && x < m && y >= 0 && y < n && board[x][y] == word[pos+1]) {
            find = find || dfs(board, x, y, word, pos + 1);     //只要存在其中一条路径就行
        }
    }

    board[i][j] = word[pos];

    return find;
}


//方法二:
bool exist(std::vector<std::vector<char>> &board, std::string word)
{
    if(board.empty()) return false;

    int m = board.size(), n = board[0].size();

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == word[0] && find(board, i, j, word, 0)) return true;
        }
    }

    return false;
}

bool find(std::vector<std::vector<char>> &board, int i, int j, std::string &word, int pos)
{
    // if(pos == word.size()) return true;      第567行语句不写也可以,放到外面就是 pos == size, 放到里面就是 pos == size - 1 

    int m = board.size(), n = board[0].size();

    if(i >= 0 && i < m && j >= 0 && j < n && board[i][j] == word[pos])
    {
        if(pos == word.size() - 1) return true;

        board[i][j] = '#';

        bool res = find(board, i, j + 1, word, pos + 1) || find(board, i, j - 1, word, pos + 1)
                || find(board, i - 1, j, word, pos + 1) || find(board, i + 1, j, word, pos + 1);

        board[i][j] = word[pos];

        return res;
    }

    return false;
}


//Leetcode第827题
//思路:
//1.计算出所有1围成的面积,将所围区域上的所有点标上记号
//2.之后遍历找到为0的位置,将该位置的上下左右四个方向的面积相加即可求出最大值

std::vector<int> dir = {-1, 0, 1, 0, -1};

int largestIsland(std::vector<std::vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    std::unordered_map<int,int> area;   //标号及其对应的最大面积
    int index = 2, res = 0;             //标号从2开始

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) {
                area[index] = dfs(grid, i, j, index);
                res = std::max(res, area[index++]);     //单个最大面积(可能所有的图形都没有连接)
            }
        }
    }

    //遍历所有的0元素判断其连接的最大面积
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 0) 
            {
                std::unordered_set<int> seen;   //防止落在其中一个区域的正中央
                int cur = 1;
                for(int k = 0; k < dir.size() - 1; k++) {
                    int x = i + dir[k], y = j + dir[k+1];
                    if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 1 && !seen.count(grid[x][y])) {
                        seen.insert(grid[x][y]);
                        cur += area[grid[x][y]];
                    }
                }
                res = std::max(res, cur);
            }
        }
    }

    return res;
}




//Leetcode第329:矩阵中的最长增长路径

std::vector<int> direction = {-1,0,1,0,-1};

int longestIncreasingPath(std::vector<std::vector<int>> &matrix)
{
    int res = 0;
    int m = matrix.size(), n = matrix[0].size();
    std::vector<std::vector<int>> cache(m, std::vector<int>(n, 0));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            res = std::max(res, dfs(matrix, i, j, cache));
        }
    }

    return res;
}

int dfs(std::vector<std::vector<int>> &matrix, int i, int j, std::vector<std::vector<int>> &cache)
{
    int m = matrix.size(), n = matrix[0].size();

    if(cache[i][j]) return cache[i][j];

    int len = 1;
    for(int k = 0; k < direction.size() - 1; k++)
    {
        int x = i + direction[k], y = j + direction[k+1];
        if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
            len = std::max(len, 1 + dfs(matrix, x, y, cache));      //取四个方向中搜索得到的最大值
        }
    }

    cache[i][j] = len;

    return len;
}


//Leetcode第698题: 等分成k个和相同的子数组
//时间复杂度分析: 每个数最多有两种选择,选或者不选,一共有n种数,k个集合; 所以时间复杂度为O(k*2^n)

//相似题型:火柴棍(473题)

bool canPartitionKSubsets(std::vector<int> &nums, int k)
{
    int maxVal = 0, sum = 0;

    for(const int &n : nums) {
        sum += n;
        maxVal = std::max(maxVal, n);
    }

    int target = sum/k;

    if(sum%k != 0 || maxVal > target) return false;

    //优化措施1:优先把大数放到前面,这样可以尽快的排除掉不可能的组合,减少回溯的次数
    sort(nums.rbegin(), nums.rend());

    std::vector<int> subSum(k, 0);

    return dfs(nums, subSum, 0, target, k);
}

bool dfs(std::vector<int> &nums, std::vector<int> &subSum, int pos, int target, int k)
{
    if(pos == nums.size()) {
        for(const int &n : subSum) {
            if(n != target) return false;
        }
        return true;
    }

    for(int i = 0; i < k; i++) 
    {
        if(subSum[i] + nums[pos] > target) continue;

        //优化措施2:避免重复计算
        if(i > 0 && subSum[i] == subSum[i-1]) continue;     //防止比如 {5,5,6,7}, 这样把下一个数加到第一个5或者第二个5效果完全一样

        subSum[i] += nums[pos];
        if(dfs(nums, subSum, pos + 1, target, k)) return true;
        subSum[i] -= nums[pos];
    }

    return false;     //加不加都可,Leetcode不加会判定函数没有返回值
}



//Leetcode第1219题 : 黄金旷工

// 时间复杂度分析: 从任意一个起点格子移动有4种选择(上下左右), 之后的k-3个格子移动就只有3种选择, 而且从倒数第二个格子到最后一个格子肯定只有一种走法
// 所以时间复杂度为 k*4*3^(k-3) ~= 3^k
// 空间复杂度为 O(k), k为格子数目

int getMaximumGold(std::vector<std::vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    int maxVal = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j]) maxVal = std::max(maxVal, dfs(grid, i, j));
        }
    }
    
    return maxVal;
}

int dfs(std::vector<std::vector<int>> &grid, int i, int j)
{
    int m = grid.size(), n = grid[0].size();

    int value = grid[i][j];
    
    int tmp = grid[i][j];
    grid[i][j] = 0;

    for(int k = 0; k < dir.size() - 1; k++) {
        int x = i + dir[k], y = j + dir[k+1];
        if(x >= 0 && x < m  && y >= 0 && y < n && grid[x][y]) {
            value = std::max(value, tmp + dfs(grid, x, y));         //这里是加上tmp,加上grid[i][j]的话会得到0
        }
    }

    grid[i][j] = tmp;       //回溯
    
    return value;
}




//////////////////////////
//
//      第51题: N皇后问题
//      第37题: 解数独问题
//
//////////////////////////

//Leetcode第51题: N皇后问题

//row代表行是否存在皇后，col代表列是否存在皇后
//leftDiag代表左斜对角线(从左上->右下),rightDiag代表右斜对角线(从右上->左下)

std::vector<int> row, col, leftDiag, rightDiag;

std::vector<std::vector<std::string>> res;

std::vector<std::vector<std::string>> solveQueens(int n)
{
    row = col = std::vector<int>(n, 0);
    leftDiag = rightDiag = std::vector<int>(2*n-1, 0);

    std::vector<std::string> map(n, std::string(n, '.'));

    //注意：这里只需要传入行坐标就行，列坐标不用传入
    dfs(map, 0);

    return res;    
}

//i表示第i行
void dfs(std::vector<std::string> &map, int i)
{
    int n = map.size();

    if(i == n) {
        res.push_back(map);
        return;
    }

    //从第i行的第一列开始逐个尝试放置皇后
    for(int j = 0; j < n; j++)
    {
        if(!row[i] && !col[j] && !leftDiag[i+j] && !rightDiag[i+(n-1)-j])
        {
            //经过上面if语句判断后(i,j)位置可以放置皇后,则放置一个皇后
            row[i] = col[j] = leftDiag[i+j] = rightDiag[i+(n-1)-j] = 1;
            map[i][j] = 'Q';

            //继续往下搜索
            dfs(map, n, i + 1);
            
            //回溯
            row[i] = col[j] = leftDiag[i+j] = rightDiag[i+(n-1)-j] = 0;
            map[i][j] = '.';
        }
    }

}


//解数独问题
//方法一:DFS直接返回bool

//如果这样在类内定义vector编译器会报错,因为无法区分这是成员变量声明还是成员函数定义
std::vector<std::vector<int>> row(9, std::vector<int>(9, 0)), col(9, std::vector<int>(9, 0)), block(9, std::vector<int>(9, 0));

int row[9][9], col[9][9], block[9][9];

void solveSudoKu(std::vector<std::vector<char>> &board)
{
    //全局变量默认初始化为0,这里为了代码的可读性,还是建立显示初始化一下
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(block, 0, sizeof(block));

    //标记矩阵中原有已经存在的数字
    for(int i = 0; i < 9; i++) 
    {
        for(int j = 0; j < 9; j++) 
        {                
            int k = (i/3)*3 + j/3;                  //注意运算符优先级

            if(board[i][j] != '.') {
                int n = board[i][j] - '1';
                row[i][n] = row[j][n] = block[k][n] = 1;
            }
        }
    }

    dfs(board, 0, 0);

}

bool dfs(std::vector<std::vector<char>> &board, int i, int j)       //这里相比八皇后问题需要传入(i,j)双重坐标的原因在于,八皇后每行只需要填入一个值
{                                                                   //也就是八皇后只要一行填入一个值了那这一个行就满足要求了,但是解数独在这一行这一列填入一个数
    if(i == 9) return true;                                         //并不代表这一行就完全满足了,还要考虑列和块是否满足,换句话说传入双重坐标更有利于我们判断
    
    if(j == 9) {
        return dfs(board, i + 1, 0);
    }

    if(board[i][j] != '.') {
        return dfs(board, i, j+1);
    }

    for(int n = 0; n < 9; n++) 
    {
        int k = (i/3)*3 + j/3;

        //判断当前数字是否已经使用过了
        if(!row[i][n] && !col[j][n] && !block[k][n])
        {
            board[i][j] = (char)(n + '1');              //这里不强制转换也会隐式转换,但最好还是强转一下
            row[i][n] = col[j][n] = block[k][n] = 1;

            //找到一个可行解就立即返回
            if(dfs(board, i, j+1)) return true;
            
            //复原
            board[i][j] = '.';
            row[i][n] = col[j][n] = block[k][n] = 0;
        }
    }

    return false;
}


//方法二:定义一个外部变量,dfs返回空,我们判断外部变量是否为真(为真就说明找到了)

bool find = true;

void dfs(std::vector<std::vector<char>> &board, int i, int j)
{
    if(i == 9) {
        find = true;
        return;
    }

    if(j == 9) {
        dfs(board, i + 1, 0);
        return;         //注意:这一句话一定要加
    }

    if(board[i][j] != '.')
    {
        dfs(board, i, j+1);
    }
    else 
    {        
        for(int n = 0; n < 9; n++) 
        {
            int k = i/3*3 + j/3;
            if(row[i][n] || col[j][n] || block[k][n]) continue;

            board[i][j] = (char)(n + '1');              //这里不强制转换也会隐身转换,但最好还是强转一下
            row[i][n] = col[j][n] = block[k][n] = 1;

            //找到一个可行解就立即返回
            dfs(board, i, j+1);
            if(find) return;
            
            //复原
            board[i][j] = '.';
            row[i][n] = col[j][n] = block[k][n] = 0;
        }
        
    }

}


///////////////////////////////////
//
//      第1239题: Maximum Length of a Concatenated String with Unique Characters
//
//
//////////////////////////////////



//Leetcode第1239题: 将字符串数组中的字符串组合成一个不含有重复字符的最长字符串,求这个最长字符串的长度

//思路一:DFS

int maxLength(std::vector<std::string> &arr)
{
    return dfs(arr, "", 0);
}

int dfs(std::vector<std::string> &arr, std::string str, int pos)
{
    //利用集合来判断字符串str中是否存在重复字符
    std::unordered_set<char> mySet(str.begin(), str.end());

    if(str.size() != mySet.size()) return 0;

    int res = str.size();

    for(int i = pos; i < arr.size(); i++) {
        res = std::max(res, str + arr[i], i + 1);
    }

    return res;
}


//思路二:利用Bitset(比较难理解)

int maxLength(std::vector<std::string> &arr)
{
    std::vector<std::bitset<26>> dp = { std::bitset<26>() };        //这个初始的第一个bitset一定要添加
    int res = 0;

    for(auto &s : arr)
    {
        std::bitset<26> a;
        for(const char &c : s) a.set(c-'a');
        
        if(a.count() < s.size()) continue;  //含有重复字符

        for(int i = dp.size() - 1; i >= 0; i--)
        {
            std::bitset c = dp[i];
            if((a & c).any()) continue;
            dp.push_back(a | c);
            res = std::max(res, (int)(c.count() + s.size()))
        }
    }

    return res;
}

