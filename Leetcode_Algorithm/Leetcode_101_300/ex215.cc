


//Leetcode第215题 : Kth Largest Element in an Array
//找到数组中第k个最大的数

//思路:利用快速排序


#include <iostream>
#include <vector>

int findKthLargest(std::vector<int> &nums, int k);
int findKthLargestCore(std::vector<int> &nums, int low, int hig, int k);


int main(){
    std::vector<int> nums = {3,2,1,5,6,4};
    std::cout << findKthLargest(nums, 2) << std::endl;

    return 0;
}



//利用快排(递归写法)

int findKthLargest(std::vector<int> &nums, int k)
{
    return findKthLargestCore(nums, 0, nums.size()-1, k-1);    //数组中是以0开始索引的
}

int findKthLargestCore(std::vector<int> &nums, int low, int hig, int k)
{
    int pivot = nums[low];
    int i = low;
    int j = hig;

    while(i < j)
    {
        while(i < j && nums[j] <= pivot) {
            j--;
        }
        nums[i] = nums[j];

        while(i < j && nums[i] >= pivot) {
            i++;
        }
        nums[j] = nums[i];

    }

    nums[i] = pivot;

    if(i == k) {
        return nums[i];
    }

    if(i < k) {
        return findKthLargestCore(nums, i+1, hig, k);
    }

    if(i > k) {
        return findKthLargestCore(nums, low, i-1, k);
    }

}




//将上面的写法拆开

int findKthLargest(std::vector<int> &nums, int k)
{
    return findKthLargestCore(nums, 0, nums.size()-1, k-1);    //数组中是以0开始索引的
}


int findKthLargestCore(std::vector<int> &nums, int low, int hig, int k)
{
    int q = partition(nums, low, hig);

    if(q == k) {
        return nums[q];
    }

    if(q < k) {
        return findKthLargestCore(nums, q+1, hig, k);
    }

    if(q > k) {
        return findKthLargestCore(nums, low, q-1, k);
    }

}

int partition(std::vector<int> &nums, int low, int hig)
{
    int pivot = nums[low];

    while(low < hig)
    {
        while(low < hig && nums[hig] <= pivot) {
            hig--;
        }
        nums[low] = nums[hig];

        while(low < hig && nums[low] >= pivot) {
            low++;
        }
        nums[hig] = nums[low];
    }

    nums[low] = pivot;

    return low;

}



//利用快排(迭代写法)

int findKthLargest(std::vector<int> &nums, int k)
{
    int n = nums.size(); 
    int start = 0, end = n - 1;
    int index = partition(nums, start, end);
    
    while(index != n-k)
    {
        if(index > n-k) {
            end = index - 1;
            index = partition(nums, start, end);
        }
        else {
            start = index + 1;
            index = partition(nums, start, end);
        }
    }

    return nums[index];
}

int partition(std::vector<int> &nums, int low, int hig)
{
    int pivot = nums[low];

    while(low < hig)
    {
        while(low < hig && nums[hig] >= pivot) hig--;
        std::swap(nums[low], nums[hig]);

        while(low < hig && nums[low] <= pivot) low++;
        std::swap(nums[low], nums[hig]);
    }

    return low;
}
