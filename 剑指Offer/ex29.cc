//面试题29:顺时针打印矩阵元素


//找规律

#include <iostream>

void PrintMatrixClockwisely(int **number, int row, int col);
void PrintMatrixInCircle(int **number, int row, int col, int start);
void printNumber(int num);


int main(){
    int number[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int *p[4];
    p[0] = number[0];
    p[1] = number[1];
    p[2] = number[2];
    p[3] = number[3];


    PrintMatrixClockwisely(p, 4, 4);
    std::cout << std::endl;


    return 0;
}


void PrintMatrixClockwisely(int **number, int row, int col)
{
    if(number==nullptr && row<=0 && col<=0) return;

    int start = 0;
    while(col>start*2 && row>start*2){
        PrintMatrixInCircle(number, row, col, start);
        start++;
    }

}

void PrintMatrixInCircle(int **number, int row, int col, int start){
    int endX = row-1-start;
    int endY = col-1-start;

    //从左到右打印第一行
    for(int i = start; i <= endY; i++){
        int num = number[start][i];
        printNumber(num);
    }

    //从上到下打印第一列
    if(start < endX){
        for(int i = start+1; i <= endX; i++){
            int num = number[i][endY];
            printNumber(num);
        }
    }

    //从右到左打印第二行
    if(start < endX && start < endY){
        for(int i = endY-1; i >= start; i--){
            int num = number[endX][i];
            printNumber(num);
        }
    }

    //从下到上打印第二列
    if(start < endX-1 && start < endY){
        for(int i = endX-1; i >= start+1; i--){
            int num = number[i][start];
            printNumber(num);
        }
    }

}


void printNumber(int num){
    std::cout << num << " ";
}