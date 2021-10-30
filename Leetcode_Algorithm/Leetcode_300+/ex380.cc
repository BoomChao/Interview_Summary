


// Leetcode第380题:Insert Delete GetRandom O(1)
// 设计数据结构


// 注:rand()是用来生成随机数
// srand()是用来设置随机数种子,二者一般是配合使用
// 如:srand(time(NULL)); rand()


class RandomizedSet
{
public:
    RandomizedSet() {}

    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        nums.push_back(val);
        mp[val] = nums.size() - 1;

        return true;
    }

    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        
        int last = nums.back();
        mp[last] = mp[val];
        nums[mp[val]] = last;
        nums.pop_back();
        mp.erase(val);

        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }


private:
    std::unordered_map<int, int> mp;
    std::vector<int> nums;

};