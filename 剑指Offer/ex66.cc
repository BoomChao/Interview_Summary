

/*
    面试题66:构建乘积数组
*/


#include <iostream>
#include <vector>

void multiply(const std::vector<double> &array1, std::vector<double> &array2);


int main(){
    std::vector<double> array1 = {1,2,3,4};
    std::vector<double> array2(array1.size(), 0);

    //注意:上面array2在传入该函数之前必须初始化,因为函数内部存在两个容器的判断语句: length1 == length2
    multiply(array1, array2);

    for(double num:array2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}


void multiply(const std::vector<double> &array1, std::vector<double> &array2)
{
    int length1 = array1.size();
    int length2 = array2.size();

    if(length1 == length2 && length2 > 1)
    {
        array2[0] = 1;
        for(int i = 1; i < length1; i++) {
            array2[i] = array2[i-1] * array1[i-1];
        }

        double temp = 1;
        for(int i = length1-2; i >= 0; i--) {
            temp *= array1[i+1];
            array2[i] *= temp;
        }

    }

}