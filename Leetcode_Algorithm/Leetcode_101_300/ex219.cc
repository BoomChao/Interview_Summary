

//Leetcode第219题:Contains Duplicate II
//判断数组中是否包含重复的数组

bool containsNearbyDuplicate(std::vector<int> &nums, int k)
{
    //先判断是否有重复元素,不存在重复元素则直接返回false
    std::set<int> mySet(nums.begin(), nums.end());      //这个判断可要可不要,如果不包含重复的数则下面的代码也会返回false
    if(mySet.size() == nums.size()) {
        return false;   
    }

    std::unordered_map<int, int> myMap;
    for(int i = 0; i < nums.size(); i++)
    {
        if(myMap.count(nums[i]) == 0) {         //map中不存在这个数则记录进map中
            myMap[nums[i]] = i;
        }
        else {      //map中已经存在这个数就先比较距离是否在k以内,再更新map
            if(i-myMap[nums[i]] <= k){
                return true;
            }

            myMap[nums[i]] = i;
        }
    }

    return false;

}
