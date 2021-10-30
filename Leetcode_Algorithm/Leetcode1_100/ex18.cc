

//Leetcode第18题:fourSum
//给出一个目标,在给定的数组中找出四个数其和等于这个目标
//threeSum的升级版


#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target);

int main(){
    std::vector<int> nums = {-3,-2,-1,0,0,1,2,3};  int target = 0;
    // std::vector<int> nums = {-1,0,1,2,-1,-4};  int target = -1;
    std::vector<std::vector<int>> res;
    res = fourSum(nums, target);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}


//采用四重指针法(思路同threeSum)
std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
{
    sort(nums.begin(),nums.end());
    std::vector<std::vector<int>> res;
    int n = nums.size();

    for(int i = 0; i < n-3; i++)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue;

        for(int j = i+1; j < n; j++)
        {
            if(j > i+1 && nums[j] == nums[j-1]) continue;
            int tmp = target - nums[i] - nums[j];
            int low = j + 1;
            int hig = n - 1;

            while(low < hig)
            {
                if(nums[low] + nums[hig] == tmp)
                {
                    res.push_back({nums[i], nums[j], nums[low], nums[hig]});
                    while(low < hig && nums[low] == nums[low+1]) low++;
                    while(low < hig && nums[hig] == nums[hig-1]) hig--;
                    low++;
                    hig--;
                } 
                else if(nums[low] + nums[hig] < tmp) low++;
                else hig--;
            }
        }
    }

    return res;
}



//对上面方法的优化,去掉不必要的计算

std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
{
    std::vector<std::vector<int>> res;
    int n = nums.size();
    if(n < 4) return res;
    
    sort(nums.begin(), nums.end());

    for(int i = 0; i < n-3 ; i++)
    {
        if(i > 0 && nums[i-1] == nums[i]) continue;
        int min4Sum = nums[i] + nums[i+1] + nums[i+2] + nums[i+3];
        if(min4Sum > target)  break;
        
        int max4Sum = nums[i] + nums[n-1] + nums[n-2] + nums[n-3];
        if(max4Sum < target) continue;

        for(int j = i+1; j < n-2; j++)
        {
            if(j > i+1 && nums[j-1] == nums[j]) continue;
            int min4Sum = nums[i] + nums[j] + nums[j+1] + nums[j+2];
            if(min4Sum > target) break;

            int max4Sum = nums[i] + nums[j] + nums[n-1] + nums[n-2];
            if(max4Sum < target) continue;

            int l = j+1, r = n-1;
            while(l < r)
            {
                int fourSum = nums[i] + nums[j] + nums[l] + nums[r];
                if(fourSum == target) {
                    res.push_back({nums[i], nums[j], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l+1]) l++;
                    while(l < r && nums[r] == nums[r-1]) r--;
                    l++;
                    r--;
                }
                else if(fourSum < target) l++;
                else r--;
            }
        }

    }

    return res;
}