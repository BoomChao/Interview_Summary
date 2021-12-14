


/*
    面试题45:把数组排成最小的数
*/


//参看Leetcode第179题,书上写法太繁琐


#include <iostream>
#include <vector>
#include <algorithm>

std::string minmunNumber(std::vector<int> &nums);
bool cmp(std::string &s1, std::string &s2) ;


int main(){
    std::vector<int> nums = {3, 32, 321};
    std::cout << minmunNumber(nums) << std::endl;


    return 0;
}


bool cmp(std::string &s1, std::string &s2) 
{
    return s1 + s2 < s2 + s1;
}


std::string minmunNumber(std::vector<int> &nums)
{
    std::vector<std::string> strNum(nums.size());
    
    for(int i = 0; i < nums.size(); i++) {
        strNum[i] = std::to_string(nums[i]);
    }

    //排序
    sort(strNum.begin(), strNum.end(), cmp);        
    
    //sort函数的第三个参数用来定义排序规则
    //当sort函数在类内使用时,并且定义的cmp函数也是类内成员函数时,必须在cmp函数前面加上static
    //这是因为所有的普通类成员函数都不能以函数指针的形式作为其他函数的入口参数  (具体可参考Leetcode的解题写法) 


    //如果排完序后第一个字符串是0,则最后的结果一定是0
    if(strNum[0] == "0") {
        return "0";
    }

    std::string res = "";
    for(int i = 0; i < strNum.size(); i++) {
        res += strNum[i]; 
    }

    return res;

}

