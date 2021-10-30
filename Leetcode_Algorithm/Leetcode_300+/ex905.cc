

//Leetcode第905题 : Sort Array By Parity
//把数组中的偶数放在前面,奇数放在后面

//思路:参考<剑指>面试题21  (双指针)
//注意怎么判断一个数是否为奇数或偶数

std::vector<int> sortArrayByParity(std::vector<int> &A)
{
    if(A.empty()) return {};

    std::vector<int> nums = A;

    int low = 0, hig = nums.size()-1;
    while(low < hig)
    {
        while(low < hig && (nums[low] & 0x1) == 0) {
            low++;
        }

        while(low < hig && (nums[hig] & 0x1) == 1) {
            hig--;
        }

        if(low < hig) {
            std::swap(nums[low], nums[hig]);
        }
    }

    return nums;
}

