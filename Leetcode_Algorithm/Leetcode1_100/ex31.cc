//Leetcode第31题
//寻找最佳的下一个permutation

//思路:
//此题看看就行,题目给出的例子太少,无法准确定义出permutation


#include <iostream>
#include <vector>
#include <algorithm>

void swap(int &num1, int &num2);
void nextPermutation(std::vector<int>& nums);

int main(){
    std::vector<int> nums = {1,3,2};
    nextPermutation(nums);
    for(int i = 0; i < nums.size(); i++) std::cout << nums[i] << " ";
    std::cout << std::endl;

    return 0;
}

void nextPermutation(std::vector<int>& nums)
{
    int n = nums.size();
    if(n < 2) return;

    std::vector<int> tmp = nums;
    sort(tmp.begin(), tmp.end());
    for(int i = 0; i < nums.size(); i++){
        if(tmp[i] != nums[i]){
            nums = tmp;
            return;
        } 
    }

    swap(nums[n-1],nums[n-2]);

}


void swap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}