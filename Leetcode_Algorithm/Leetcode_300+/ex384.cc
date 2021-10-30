

//Leetcode第384题:Shuffle An Array
//对数组洗牌


class Solution 
{
public:
    Solution(std::vector<int> &nums) {
        srand(time(NULL));      //为下面的随机数产生设置随机数种子
        this->nums = nums;
    }

    std::vector<int> reset() {
        return nums;
    }

    std::vector<int> shuffle() {
        std::vector<int> res(nums);
        for(int i = res.size()-1; i >= 0; i--) {
            int pos = rand()%(i+1);
            std::swap(res[i], res[pos])
        }

        return res;
    }


private:
    std::vector<int> nums;

};

