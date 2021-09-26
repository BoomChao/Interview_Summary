

//Leetcode第448题:Find All Numbers Disappeared in an Array
//找到数组中未出现的元素

//思路:第一次遍历找到所有出现过的元素,并做出标记
//第二次遍历根据标记找出所有未出现的元素

std::vector<int> findDisappearedNumbers(std::vector<int> &nums)
{
    std::vector<int> res;
    if(nums.empty()) return res;

    for(int i = 0; i < nums.size(); i++)
    {
        int m = abs(nums[i]) - 1;
        nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
    }

    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] > 0) {
            res.push_back(i + 1);
        }
    }

    return res;
}
