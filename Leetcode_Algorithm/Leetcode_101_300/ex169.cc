


//Leetcode第169题 : Majority Element
//找到数组出现次数超过一半的元素

int majorityElement(std::vector<int> &nums)
{
    int result = nums[0];
    int times = 1;

    for(int i = 1; i < nums.size(); i++)
    {
        if(times == 0) {
            result = nums[i];
        }
        else if(result == nums[i]) {
            times++;
        }
        else {
            times--;
        }
    }

    //检查结果是否为超过一半的数字,如果不是则返回0
    if(!isMoreThanHalf(nums, result)) {
        return 0;
    }

    return result;
}

bool isMoreThanHalf(std::vector<int> &nums, int target)
{
    int times = 1;

    for(int i = 0; i < nums.size(); i++) {
        if(target == nums[i]) {
            times++;
        }
    }

    if(times*2 < nums.size()) {
        return false;
    }

    return true;
}
