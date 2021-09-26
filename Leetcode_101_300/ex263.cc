

//Leetcode第263题 : Ugly Number :判断一个数是否为丑数

//思路:参考<剑指>面试题49

#include <iostream>

int main(){

    return 0;
}

bool isUgly(int num)
{
    if(num <= 0) return false;

    while(num%2 == 0) {
        num /= 2; 
    }
    while(num%3 == 0) {
        num /= 3;
    }
    while(num%5 == 0) {
        num /= 5;
    }

    return (num == 1) ? true : false;

}