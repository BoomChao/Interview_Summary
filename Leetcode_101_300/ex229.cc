


//Leetcode第229题:Majority Element II
//找到数组中出现次数超过(n/3)次的元素

//方法一:使用map
//时间复杂度O(n),空间复杂度O(1)

std::vector<int> majorityElement(std::vector<int> &nums)
{
    std::unordered_map<int, int> mp;
    std::vector<int> res;

    for(int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    for(auto &n:mp) 
    {
        if(n.second > nums.size()/3) {
            res.push_back(n.first);
        }
    }

    return res;

}



//方法二:因为要找出的是出现次数超过(n/3)的元素,所以一个数组中最多只会有两个这种元素
//也就是结果返回数组中元素个数最多为2
//参考第169题:Majority Element的解法,找到这两个出现次数超过(n/3)的元素就行

std::vector<int> majorityElement(std::vector<int> &nums)
{
    int a = 0, b = 1;
    int ca = 0, cb = 0;

    for(int &num:nums)
    {
        if(num == a) {
            ca++;
        }
        else if(num == b) {
            cb++;
        }
        else if(ca == 0) {
            a = num;
            ca = 1;
        }
        else if(cb == 0) {
            b = num;
            cb = 1;
        }
        else {
            ca--;
            cb--;
        }

    }

    std::vector<int> res ;
    if(count(nums.begin(), nums.end(), a) > nums.size()/3) {    //判断出现次数是否大于(n/3)
        res.push_back(a);
    }

    if(count(nums.begin(), nums.end(), b) > nums.size()/3) {
        res.push_back(b);
    }

    return res;

}

