

//Leetcode第179题 : Largest Number
//将数组中的数字排列组合成最大的一个数

//与<剑指>面试题45相同


#include <iostream>
#include <vector>
#include <algorithm>

std::string largestNumber(std::vector<int> &nums);
bool cmp(std::string &s1, std::string &s2) ;


int main(){
    std::vector<int> nums = {3, 30, 34, 5, 9};
    std::cout << largestNumber(nums) << std::endl;


    return 0;
}


bool cmp(std::string &s1, std::string &s2) 
{
    return s1 + s2 > s2 + s1;
}


//方法一:借助系统函数sort()

std::string largestNumber(std::vector<int> &nums)
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


    //或者直接利用lambda表达式(推荐这种比较方法)
    sort(strNum.begin(), strNum.end(), [](std::string s1, std::string s2) {
        return s1 + s2 > s2 + s1;
    });

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




//利用快排的思想(建立跟着程序走一遍来理清思路)

std::string largestNumber(std::vector<int> &nums)
{
    std::vector<std::string> strNum(nums.size());
    
    for(int i = 0; i < nums.size(); i++) {
        strNum[i] = std::to_string(nums[i]);
    }

    quickSort(strNum, 0, strNum.size() - 1);

    if(strNum[0] == "0") return "0";

    std::string res;
    for(std::string &s : strNum) {
        std::cout << s << " ";
        res += s;
    }
    std::cout << std::endl;

    return res;
}

void quickSort(std::vector<std::string> &strs, int left, int right)
{
    if(left >= right) return ;

    int low = left, hig = right;
    std::string pivot = strs[low];
    int i = low + 1;

    while(i <= hig)
    {
        if(pivot + strs[i] < strs[i] + pivot) {
            std::swap(strs[i++], strs[low++]);
        }
        else if(pivot + strs[i] > strs[i] + pivot) {
            std::swap(strs[i], strs[hig--]);
        }
        else {
            i++;
        }
    }
    
    quickSort(strs, left, low - 1);
    quickSort(strs, hig + 1, right);

}