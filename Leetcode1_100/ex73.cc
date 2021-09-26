

//Leetcode第73题 : Set Matrix Zeros (将矩阵元素为０的整行整列全都置为０)


//解法一：暴力解法  算法时间复杂度为O(m*n)
//注意:这里有个陷阱,千万不可直接遍历数组元素,碰到0元素就直接将整行整列元素都置0
//这样的话只要有一个元素为0,则这种结果出来的矩阵所有元素都为0
//1.定义一个新数组,将原来数组元素都赋值到新数组中,(新数组主要用来搜寻0元素),而实际的置0操作是在原数组上进行


//解法二:  时间复杂度O(n)
//从上面解法一的思路可以看出,我们实际上要要找出0元素的位置并标记 出来,
//那么我们可以在原始数组的基础上借助第0行第0列来标记数组中的0元素的位置
//1.首先判断第0行有没有0元素,第0列有没有0元素 (因为之后再判断可能就被下面的操作覆盖掉了)
//2.接下来从数组的第1行和第1列元素开始判断,如果是0就将所在行的第一个元素置0,所在列的第一个元素置0(这样就相当于在首行首列标记处了0元素位置)
//3.找出从第1行第1列的所有元素并标记完后,我们依据标记后第0行第0列元素是否为0,如果第0列元素存在0,就将0所在的行的元素全部置0;
//4.最后依据之前标记前判断的首行首列元素是否存在0来判断是否要将首行首列置为0


#include <iostream>
#include <vector>

void setZeros_1(std::vector<std::vector<int>> &matrix);


int main(){
    // std::vector<std::vector<int>> matrix = {{1,1,1}, {1,0,1}, {1,1,1}};
    std::vector<std::vector<int>> matrix = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};

    setZeros_1(matrix);

    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}




void setZeros_1(std::vector<std::vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    std::vector<std::vector<int>> tmp(m, std::vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            tmp[i][j] = matrix[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(tmp[i][j] == 0){
                for(int k = 0; k < n; k++){
                    matrix[i][k] = 0;
                }
                for(int l = 0; l < m; l++){
                    matrix[l][j] = 0;
                }
            }
        }
    }

}


//解法二:重点掌握这种解法

void setZeros_2(std::vector<std::vector<int>> &matrix)
{
    bool flagr = false;     //用来记录第一行是否存在0元素
    bool flagl = false;     //用来记录第一列是否存在０元素
    int m = matrix.size();
    int n = matrix[0].size();

    for(int i = 0; i < n; i++){
        if(matrix[0][i] == 0){
            flagr = true;
            break;
        }
    }

    for(int j = 0; j < m; j++){
        if(matrix[j][0] == 0){
            flagl = true;
            break;
        }
    }

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }

    if(flagr){
        for(int j = 0; j < n; j++){
            matrix[0][j] = 0;
        }
    }

    if(flagl){
        for(int i = 0; i < m; i++){
            matrix[i][0] = 0;
        }
    }


}



//改进一下上面的代码(思路都一样,但是从下往上遍历)

void setZeros_2(std::vector<std::vector<int>> &matrix)
{
    bool col0 = false;  //第一列是否应该置0
    int rows = matrix.size(), cols = matrix[0].size();

    for(int i = 0; i < rows; i++){
        if(matrix[i][0] == 0) col0 = true;
        for(int j = 1; j < cols; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }

    for(int i = row-1; i >= 0; i--){
        for(int j = cols-1; j>=1; j--){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
        if(col0) matrix[i][0] = 0;
    }


}