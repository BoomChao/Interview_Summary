

//Leetcode第74题 : Search a 2D matrix(在杨氏矩阵中寻找指定的元素)

//思路:参考<剑指>面试题4



#include <iostream>
#include <vector>

bool searchMatrix(std::vector<std::vector<int>> &matrix, int target);

int main(){
    std::vector<std::vector<int>> matrix = {{1,3,5,7}, {10,11,16,20}, {23,30,34,50}};

    std::cout << searchMatrix(matrix, 3) << std::endl;

    return 0;
}


bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
{
    if(matrix.size() == 0) return false;

    int rows = matrix.size();
    int cols = matrix[0].size();

    int row = 0;
    int col = cols-1;
    while(row < rows && col >= 0){
        if(target > matrix[row][col]) row++;
        else if(target < matrix[row][col]) col--;
        else return true; 

    }


    return false;

}