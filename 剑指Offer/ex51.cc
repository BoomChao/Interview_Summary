//面试题51
//数组中的逆序对

//思路:归并排序的思想


#include <iostream>

int inversePairs(int *data, int len);
int inversePairsCore(int *data, int *copy, int start, int end);

int main(){
    int data[4] = {7,5,6,4};
    std::cout << inversePairs(data,4) << std::endl;

    return 0;
}


int inversePairs(int *data, int len)
{
    if(data == nullptr || len < 0) return 0;

    int *copy = new int[len];
    for(int i = 0; i < len; i++) {
        copy[i] = data[i];    //这个copy数组必须要和data数组元素相同
    }

    int count = inversePairsCore(data, copy, 0, len-1);

    delete[] copy;

    return count;

}

int inversePairsCore(int *data, int *copy, int start, int end)
{
    if(start == end) {
        copy[start] = copy[end];
        return 0;               //递归的出口不要忘记了
    }

    int length = (end-start)/2;

    int left = inversePairsCore(copy, data, start, start+length);   //弄清楚这个copy和data的顺序,更改的是第二个参数数组data的值
    int right = inversePairsCore(copy, data, start+length+1, end);  //下面的操作都是在对copy数组操作,所以这里递归调用的第二个参数应该是data数组

    int i = start+length;      //i初始化为前半段最后一个数字的下标
    int j = end;               //j初始化为后半段最后一个数字的下标
    int indexCopy = end;       //这是将data中的数据从后往前复制到copy数组中
    int count = 0;

    while(i >= start && j >= start+length+1)
    {
        if(data[i] > data[j])
        {
            copy[indexCopy--] = data[i--];
            count += j - (start + length);      //(start+length)是前半段最后一个元素的下标
        }
        else
        {
            copy[indexCopy--] = data[j--];
        }

    }

    for(; i >= start; i--) {
        copy[indexCopy--] = data[i];
    }

    for(; j >= start+length+1; j--) {
        copy[indexCopy--] = data[j];
    }

    return left + right + count;

}


//Leetcode第493题
//下面这种归并比较好理解

int inversePairs(std::vector<int> &nums, int left, int right)
{
    if(left == right) {
        return 0;
    }

    int mid = left + ((right - left) >> 1);
    int leftCount = inversePairs(nums, left, mid);
    int rightCount = inversePairs(nums, mid + 1, right);

    //在归并的过程中加入了计算逆序的过程
/*
    int count = 0;
    int i = mid, j = right;
    while(i >= left && j >= mid + 1) 
    {
        if(nums[i] > 2*nums[j]) {
            count += (right - mid);
            i--;
        }
        else {
            j--;
        }
    }
*/

    //注:写成上面那种形式是错误的
    int i = left, j = mid + 1 ;
    while(i <= mid && j <= right)
    {
        if(nums[i] > 2*nums[j]) {
            count += (mid - i + 1);
            j++;
        }
        else {
            i++;
        }
    }

    //有序合并子数组
    merge(nums, left, mid, right);

    return count + leftCount + rightCount;
}


void merge(std::vector<int> &nums, int left, int mid, int right)
{
    int *team = new int[right - left + 1];
    int index = 0;
    int lindex = left, rindex = mid + 1;
    while(lindex <= mid && rindex <= right)
    {
        if(nums[lindex] <= nums[rindex]) {
            team[index++] = nums[lindex++];
        }
        else {
            team[index++] = nums[rindex++];
        }
    }

    while(lindex <= mid) {
        team[index++] = nums[lindex++];
    }

    while(rindex <= right) {
        team[index++] = nums[rindex++];
    }

    for(int i = 0; i < index; i++) {
        nums[left + i] = team[i];
    }

    delete [] team;
}


