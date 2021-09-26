//Leetcode第79题:
//Word Search : 在一个二维矩阵中搜索给定的单词


//思路:dfs搜索  (参考<剑指>面试题12)
//这里有一种情况要特别注意
//如:二维矩阵 a b  
//          c f
//千万注意在dfs中循环遍历过的元素一定要加上标记,表示已经遍历过了
//如果像上面这个矩阵,我想要找单词 "abfb"
//当找到字母'f'的时候,如果不标记,这时就又会找到上面已经遍历过的字母'b',这样字母'b'就被遍历了两次
//但是题目要求每个字符只能遍历一次


#include <iostream>
#include <vector>

bool exist(std::vector<std::vector<char>> &board, std::string word);
bool dfsSearch(std::vector<std::vector<char>> &board, std::string word, int k, int i, int j, int m, int n);


int main(){
    std::vector<std::vector<char>> board = {{'A', 'B', 'C', 'E'},{'S','F','C','S'},{'A','D','E','E'}};
    
    std::cout << exist(board, "ABCCC") << std::endl;

    return 0;
}


bool exist(std::vector<std::vector<char>> &board, std::string word)
{
    if(word.empty()) return false;
    if(board.empty() || board[0].empty()) return false;     //注意边界条件的处理

    int m = board.size();
    int n = board[0].size();

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(dfsSearch(board, word, 0, i, j, m, n)) return true;
        }
    }

    return false;

}


bool dfsSearch(std::vector<std::vector<char>> &board, std::string word, int index, int i, int j, int m, int n){
    if(index == word.size()) return true;

    if(i < 0 || i > m-1 || j < 0 || j > n-1 || word[index] != board[i][j]) return false;    //超出了边界并且搜索的字符不匹配就返回false

    char cur = board[i][j];
    board[i][j] = '*';  //当前搜索过了就进行标记
                                                                                                                    
    bool search_next =    dfsSearch(board, word, index+1, i-1, j, m, n)   //向上搜索    
                       || dfsSearch(board, word, index+1, i, j+1, m, n)   //向右搜索    注:这是vector,如果j=m-1,此时j+1=m,但是vector可以大胆使用,不需要担心下标越界的问题
                       || dfsSearch(board, word, index+1, i+1, j, m, n)   //向下搜索    //但是如果用的是二维数组,则不能像上面这样写
                       || dfsSearch(board, word, index+1, i, j-1, m ,n);  //向左搜索
    
    board[i][j] = cur;  //恢复成原来的字符

    return search_next;

}