

//Leetcode第88题
//Merge Sorted Array : 合并两个数组


//思路: 注意这题不能使用额外的空间,但是告诉了数组1的空间能够容纳下这两个数组所有元素的大小
//1.采用尾插法即可


#include <iostream>
#include <vector>
#include <iterator>

void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n);

int main(){
    std::vector<int> nums1 = {1,2,3,0,0,0};
    std::vector<int> nums2 = {2,5,6};

    merge(nums1, 3, nums2, 3);

    for(int i = 0; i < nums1.size(); i++){
        std::cout << nums1[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}



void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
{
    int i = m-1;
    int j = n-1;
    int k = m+n-1;
    
    while(i >= 0 && j >= 0)
    {
        if(nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }

    }
    
    while(j >= 0) {              //防止i遍历到了首部,但是j还未到首部,如num1={5,0,0},num2={2,3}这种情况
        nums1[k--] = nums2[j--];
    }

}

