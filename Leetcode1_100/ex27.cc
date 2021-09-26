//Leetcode第27题
//Remove : 去掉数组中指定的元素


#include <iostream>
#include <vector>

int removeElement(std::vector<int> &nums ,int val);

int main(){
    
    std::vector<int> s = {3,2,2,3};
    std::cout << removeElement(s, 3) << std::endl;

    for(int i = 0; i < s.size(); i++) std::cout << s[i] << " ";
    std::cout << std::endl;

    return 0;
}



//方法一:逐个遍历寻找
int removeElement(std::vector<int> &nums ,int val)
{
    int j = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != val) nums[j++] = nums[i];
    }

    return j;
}



//方法二
int removeElement(std::vector<int> &nums, int val)
{
    int lenght = 0;
    for(int n:nums){        //很巧妙的利用了for循环,这样写可以让面试官眼前一亮
        if(n != val) nums[lenght++] = n;
    }

    return lenght;
}