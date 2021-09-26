


//Leetcode第268题:Missing Number
//找到缺失的数字


#include <iostream>
#include <vector>



int missingNumber(std::vector<int> &nums);

int main(){
    std::vector<int> nums = {3,0,1};

    std::cout << missingNumber(nums) << std::endl;

    return 0;
}

//方法一:利用数列的性质,因为给出的数组是一个连续的数组

int missingNumber(std::vector<int> &nums)
{
    long total = (nums.size()+1)*(nums.size())/2;   //使用long防止求和超出范围
    int sum = 0;

    for(auto &num:nums) {
        sum += num;
    }

    return total-sum;
}


// 方法二:利用位运算
// 利用异或操作
// 一个数异或其本身得0, 0与任何数异或还是得任何数
// 假设数组为[0,1,3,4]
// 则 res = 0^1^2^3^4^0^1^3^4 = 2

int missingNumber(std::vector<int> &nums)
{
    int res = 0;

    for(int i = 0; i <= nums.size(); i++) {
        res ^= i;
    }

    for(int i = 0; i < nums.size(); i++) {
        res ^= nums[i];
    }

    return res;
}


// 发现上面两个循环区别只是上一个循环多亦或了一个nums.size()
// 所以如果初始就将res设定为nums.size()则一个循环就可以解决

int missingNumber(std::vector<int> &nums)
{
    int res = nums.size();    

    for(int i = 0; i < nums.size(); i++)
    {
        res ^= nums[i];
        res ^= i;
    }

    return res;
}

