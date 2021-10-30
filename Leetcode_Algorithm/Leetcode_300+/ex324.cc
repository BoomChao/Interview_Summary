

//Leetcode第324题 : Wiggle Sort II
//摆动排序

//思路:先排序然后找到插入的规律

void wiggleSort(std::vector<int> &nums)
{
    if(nums.empty()) return ;

    std::vector<int> sorted(nums);
    sort(sorted.begin(), sorted.end());

    for(int i = nums.size()-1, j = 0, k = i/2+1; i >= 0; i--) 
    {
        if(i & 1) {             //i为奇数
            nums[i] = sorted[k++];
        }
        else {                  //i为偶数
            nums[i] = sorted[j++];
        }
    }

}
