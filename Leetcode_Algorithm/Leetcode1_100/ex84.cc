

//Leetcode第84题
//Largest Rectangle int Histogram : 求出柱状图所能勾勒出的最大矩形的面积

//思路:参考CSDN收藏夹 <图解Leetcode>


#include <iostream>
#include <vector>

int largestRectangle(std::vector<int> &heights);

int main(){
    std::vector<int> heights = {2,1,5,6,2,3};

    std::cout << largestRectangle(heights) << std::endl;

    return 0;
}


//解法一:暴力破解

int largestRectangle(std::vector<int> &heights)
{
    if(heights.size() == 0) return 0;

    int len = heights.size();
    int res = 0;

    for(int i = 0; i < len; i++){
        int tmp = heights[i];
        for(int j = i; j < len; j++){
            tmp = std::min(tmp, heights[j]);
            res = std::max(res, tmp*(j-i+1));
        }
    }

    return res;

}



//利用单调栈
//思路:就是求出能覆盖每个柱子的最大面积,这样只需遍历一次就可得到解答
//比如求出完全覆盖0号柱的面积,再求出完全覆盖1号柱的面积,等等依次与最大值比较


int largestRectangle(std::vector<int> &heights)
{
    heights.push_back(0);   //注:在heights末尾添加一个0是为了让所有元素都出栈; 如 heights = {1}这种只有一个元素的情况,下面的循环会输出0
    int res = 0;            //另外:如 {1,2,3}所有元素都入栈了,不在末尾添加0最后一个元素就出不了栈,再末尾添加一个0是为了判断最后一个元素能够组成的面积大小

    std::stack<int> indexes;    //定义单调栈用来存放其下标
    for(int i = 0; i < heights.size(); i++)
    {
        while(!indexes.empty() && heights[indexes.top()] > heights[i]) {
            int h = heights[indexes.top()];
            indexes.pop();      //出栈
            int l = indexes.empty() ? -1 : indexes.top();
            res = std::max(res, h*(i-l-1));
        }

        indexes.push(i);
    }

    return res;
}