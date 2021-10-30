


//Leetcode第228题:Summary Ranges
//总结区间


//思路:定义四个指针
//start 和 end 指向的是一个连续区间的开始和结束
//pre 和 cur 表示之前指向的元素和当前指向的元素
//遍历nums,判断nums[cur]-nums[pre]==1;  如果成立则cur++,pre++; 
//否则令end=pre,此时如果start!=end,我们就将"nums[start]->nums[end]"添加到结果中去,如果start=end,则直接将nums[start]添加到结果中去


#include <iostream>
#include <vector>
#include <climits>

std::vector<std::string> summaryRanges(std::vector<int> &nums);

int main(){
    std::vector<int> nums = {-1};

    std::vector<std::string> ans = summaryRanges(nums);

    for(std::string &str:ans) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}


std::vector<std::string> summaryRanges(std::vector<int> &nums)
{
    std::vector<std::string> res;

    if(nums.empty()) return res;

    int start = 0, end = 0;
    int pre = 0, cur = 1;

    while(cur <= nums.size())   //这里不能写成 cur<nums.size(); 可用例子{0,1,2,4,5,7}验证
    {
        if(cur < nums.size() && nums[cur]-nums[pre] == 1) 
        {
            pre++;
            cur++;
        }
        else
        {
            end = pre;
            if(end != start) {
                res.push_back(std::to_string(nums[start]) + "->" + std::to_string(nums[end]));
            }
            else {
                res.push_back(std::to_string(nums[start]));
            }

            start = cur;
            pre++;
            cur++;
        }
    }

    return res;

}