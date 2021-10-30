

//Leetcode第42题
//Trapping Rain Water : 容器接雨水问题
//计算容器的凹槽能够接多少雨水


//思路一:利用二重指针
//1.比较左指针和右指针指向数据的大小,如果 num[left]<num[right] 则将left右移一位,否则将right左移一位
//2.移动左右指针的过程中需要记录左右的最大值maxL 和 maxR,
//3.当首指针指向的值小于maxL时,则蓄水量就等于 maxL-num[left], 同理对右指针也是如此
//4.循环退出条件是左右指针指向相同元素


//思路二:利用单调栈
//1.遇到比栈顶元素小的就将其下标索引入栈
//2.遇到比栈顶元素大的就说明可以存雨水,先将栈顶出栈,判断栈是否为空,为空的话就没有了左边界
//3.如果不为空,则计算接雨水的量 res += (左右边边界的高度的最小值)*(当前位置的索引减去与栈顶元素的值),上一步出栈后栈顶元素就是左边界


#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

int trap_1(std::vector<int> &height);
int trap_2(std::vector<int> &height);

int main(){
    std::vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    std::cout << trap_2(height) << std::endl;

    return 0;
}



//使用二重指针(这道题使用二重指针来解决比较快)

int trap_1(std::vector<int> &height)
{
    if(height.size() <= 2) return 0;

    int left = 0, right = height.size()-1;
    int maxL = 0, maxR = 0;
    int res = 0;

    while(left < right){
        if(height[left] < height[right]){
            if(height[left] >= maxL){
                maxL = height[left];
            }else{
                res += maxL-height[left];
            }
            left++;

        }else{
            if(height[right] >= maxR){
                maxR = height[right];
            }else{
                res += maxR-height[right];
            }
            right--;
        }
    }


    return res;

}



//使用单调栈(维护一个单调递减栈)

int trap_2(std::vector<int> &height)
{
    if(height.size() <= 2) return 0;

    std::stack<int> sta;
    int res = 0;
    int i = 0;

    while(i < height.size()){
        if(sta.empty() || height[i]<=height[sta.top()]){
            sta.push(i++);
        }
        else{
            int pre = sta.top();        //C++ pop()函数没有返回值,不能写成 int pre = sta.pop(); 这是错误的
            sta.pop();      //弹出一个元素之后一定要对栈判定是否为空
            if(!sta.empty()){
                int midHeight = std::min(height[sta.top()], height[i]);
                res += (midHeight-height[pre])*(i-sta.top()-1);
            }
        }
    }

    return res;

}