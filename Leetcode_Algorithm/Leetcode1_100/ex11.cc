

//Leetcode第11题
//Comtainer with most water : 容器接水问题


//思路:利用二重指针
//1.如果尾指针指向的值小于头指针指向的值,则将尾指针前移,并计算当前的容器蓄水量
//2.反之如果头指针指向的值大于尾指针指向的值,则将头指针后移,计算当前的蓄水量并与之前的最大的蓄水箱比较取较大值
//3.一直遍历到头尾指针重复为止



#include <iostream>
#include <vector>

int maxArea(std::vector<int> &height);

int main(){
    std::vector<int> height = {1,8,6,2,5,4,8,3,7};
    std::cout << maxArea(height) << std::endl;

    return 0;
}


int maxArea(std::vector<int> &height)
{
    int max = 0;
    int wide = 0;
    int area = 0;
    int hei = 0;
    int left = 0, right = height.size()-1;

    while(left < right){
        wide = right - left;

        hei = height[left] < height[right] ? height[left++] : height[right--];      //可以用if else 的地方可以尝试替换为条件表达式,这样看起来很简洁
        // if(height[left] < height[right]){
        //     hei = height[left++];
        // }else{
        //     hei = height[right--];
        // }

        area = wide * hei;
        if(area > max)    max = area;

    }

    return max;    

}