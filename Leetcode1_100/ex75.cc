

//Leetcode第75题 : Sort Colors
//荷兰旗问题


//思路:
//利用三个指针,头指针beg指向首部为0的元素,尾end指针指向尾部为2的元素;mid指针指向遍历的元素
//1.遍历数组,当如果mid指向0,则将其与beg指向元素对换换,之后beg++, mid++
//2.如果mid指向2,则将其与end的指向对换,此时mid不能自增,而需要end--
//3.如果mid指向1,则什么操作也不做,将mid指针后移
//4.直到mid指针与end指针位置重合,则遍历结束


void sortColors(std::vector<int> &nums)
{
    int beg = 0;
    int end = nums.size()-1;
    int mid = 0;

    while(mid <= end)
    {                           //注意细节
        if(nums[mid] == 2) {    //这里和尾指针交换后此时mid的指向不一定是1,所以不能mid++
            std::swap(nums[mid], nums[end]);
            end--;
        }
        else if(nums[mid] == 0) {
            std::swap(nums[mid], nums[beg]);
            beg++;
            mid++;
        }
        else {
            mid++;
        }
    }

}