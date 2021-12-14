//面试题4
//在杨氏矩阵中查找指定的数


#include <iostream>

bool find(int *matrix, int rows, int colums, int number);

int main(){
    int matrix[] = {1,2,8,9, 2,4,9,12, 4,7,10,13, 6,8,11,15};
    int rows = 4, colums = 4;
    std::cout << find(matrix, rows, colums, 7) << std::endl;

    return 0;
}


bool find(int *matrix, int rows, int colums, int number)
{
    bool find = false;

    if(matrix != NULL || rows >= 0 || colums >= 0)
    {
        //从右上角开始查找
        int row = 0;
        int colum = colums-1;

        while(row < rows && colums >= 0){
            if(number < matrix[row*colums+colum]) { colum--; }

            else if(number > matrix[row*colums+colum]) { row++; }
            
            else { find = true; break; }
        }

    }

    return find;

}





bool Find(int *matrix, int rows, int columns, int number)
{
    bool found = false;

    if(matrix != nullptr && rows > 0 && columns > 0)
    {
        //从左下角开始查找
        int row = rows - 1;
        int column = 0;

        while(row > 0 && column < columns)
        {
            if(matrix[row*columns+column] == number) {
                found = true;
                break;
            }

            else if(matrix[row*columns+column] > number) {
                row--;
            }
            else{
                column++;
            }
        }

    }


    return found;

}
