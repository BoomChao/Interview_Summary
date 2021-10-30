

//Leetcode第70题
//参考 <剑指>面试题10

//Climbing Stairs : 爬楼梯
//这类题目和青蛙跳一样,本质都是斐波那契数列
//两种解法:迭代或者递归


#include <iostream>

int climbStairs_1(int n);
int fun(int n);

int climbStairs_2(int n);

int main(){
    std::cout << climbStairs_2(45) << std::endl;

    return 0;
}


// 使用递归(注意:实际面试过程中使用这种方法可能会超时)  不推荐使用
int climbStairs_1(int n)
{
    return fun(n);

}

int fun(int n) {
    if(n == 1) return 1;
    if(n == 2) return 2;

    return fun(n-1) + fun(n-2);
}


// 使用迭代
int climbStairs_2(int n)
{
    int res[] = {0,1,2};
    if(n <= 2) return res[n];

    int stairOne = 1;
    int stairTwo = 2;
    int ans;
    for(int i = 3; i <= n; i++) {
        ans = stairOne + stairTwo;
        stairOne = stairTwo;
        stairTwo = ans;
    }

    return ans;
}