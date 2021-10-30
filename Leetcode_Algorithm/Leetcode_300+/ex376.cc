


//Leetcode第376题:Wiggle Sequence
//摆动序列(求出最长的摆动序列的元素个数)

//思路:动态规划


int wiggleMaxLength(std::vector<int> &nums)
{
    if(nums.empty()) return 0;

    std::vector<int> up(nums.size(), 0);
    std::vector<int> down(nums.size(), 0);
    up[0] = 1;
    down[0] = 1;

    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] > nums[i-1]) {
            up[i] = down[i-1] + 1;
            down[i] = down[i-1];
        }
        else if(nums[i] < nums[i-1]){
            down[i] = up[i-1] + 1;
            up[i] = up[i-1];
        }
        else {
            up[i] = up[i-1];
            down[i] = down[i-1];
        }
    }

    return std::max(up.back(), down.back());
}


//上面方法的优化,将空间复杂度降低为O(1)

int wiggleMaxLength(std::vector<int> &nums)
{
    if(nums.empty()) return 0;

    int up = 1, down = 1;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] > nums[i+1]) {
            up = down + 1;
        }
        else if(nums[i] < nums[i-1]) {
            down = up + 1;
        }
    }

    return std::max(down, up);
}
