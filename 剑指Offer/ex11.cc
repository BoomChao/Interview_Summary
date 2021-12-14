//面试题11
//寻找旋转数组的最小数字

//思路:二分查找


#include <iostream>

int minOrder(int *numbers, int low, int hig);
int min(int *numbers, int length);

int main(){
    int num[] = {1,0,1,1,1};
    std::cout << min(num,5) << std::endl;

    return 0;
}


int min(int *numbers, int length)
{
    if(numbers == nullptr || length <= 0)  return -1;   //失败返回-1

    int low = 0, hig = length-1;
    int mid = low;

    while(numbers[low] >= numbers[hig]){
        if(hig-low == 1){
            mid = hig;
            break;
        }
        mid = (low+hig)/2;

        if(numbers[low]==numbers[hig] && numbers[low]==numbers[mid]){   //首位末位和中间位相等时只能采用顺序查找
            return minOrder(numbers, low, hig);
        }

        if(numbers[mid] >= numbers[low]) low = mid;    //说明中间位置数位于左半部分
        
        else if(numbers[mid] <= numbers[hig]) hig = mid;    //说明中间位置数位于右半部分

    }

    return numbers[mid];

}


int minOrder(int *numbers, int low, int hig){
    int result = numbers[low];
    for(int i = low+1; i <= hig; i++){
        if(result > numbers[i]) result = numbers[i];
    }

    return result;

}