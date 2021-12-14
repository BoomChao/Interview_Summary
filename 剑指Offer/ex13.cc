
//面试题13 : 机器人的运动范围 


#include <iostream>
#include <cstring>

int movingCount(int threshold, int rows, int cols);
int movingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited);
bool check(int threshold, int rows, int cols, int row, int col, bool *visited);
int getDigitSum(int num);


int main(){

    std::cout << movingCount(5, 10, 10) <<std::endl;


    return 0;
}



int movingCount(int threshold, int rows, int cols)
{
    if(threshold < 0 || rows <=0 || cols <= 0) return 0;

    bool *visited = new bool[rows*cols];
    memset(visited, 0, rows*cols);

    int count = movingCountCore(threshold, rows, cols, 0, 0, visited);

    delete[] visited;

    return count;

}


int movingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited){

    int count = 0;
    if(check(threshold, rows, cols, row, col, visited)){

        visited[row*cols+col] = true;
        count = 1 + movingCountCore(threshold, rows, cols, row-1, col, visited)    //上移
                  + movingCountCore(threshold, rows, cols, row, col+1, visited)    //右移
                  + movingCountCore(threshold, rows, cols, row+1, col, visited)    //下移
                  + movingCountCore(threshold, rows, cols, row, col-1, visited);   //左移

    }

    return count;

}


bool check(int threshold, int rows, int cols, int row, int col, bool *visited){
    
    if(row >= 0 && row < rows && col >= 0 && col < cols && getDigitSum(row) + getDigitSum(col) <= threshold && !visited[row*cols+col]){
        return true;
    }

    return false;

}


int getDigitSum(int number){
    int sum = 0;
    while(number > 0){
        sum += number%10;
        number /= 10;
    }

    return sum;

}