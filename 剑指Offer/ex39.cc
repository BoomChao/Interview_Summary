

//面试题39 : 数组中出现次数超过数组长度一半的数
//两种解法



int partition(int num[], int len, int low, int hig) {
    if(num == nullptr || len <= 0 || low < 0 || hig >= len){
        std::cout << "Error";
        exit(1);
    }

    int pivotkey = num[low];
    while(low < hig)
    {
        while(low < hig && num[hig] >= pivotkey){
            hig--;
        }
        num[low] = num[hig];

        while(low < hig && num[low] <= pivotkey){
            low++;
        }
        num[hig] = num[low];
    }

    num[low] = pivotkey;

    return low;
}


bool checkMoreThanHalf(int number[], int length, int target) {
    int times = 0;
    for(int i = 0; i < length; i++){
        if(number[i] == target) times++;
    }

    bool isMoreThanHalf = true;

    if(times*2 <= length){
        isMoreThanHalf = false;
    }

    return isMoreThanHalf;
}




//解法一：利用快排的思想
//注：这种解法会修改输入的数组，即因为会交换数组中元素的顺序，这就会修改输入的数组

int moreThanHalfNum(int *number, int length)
{
    if(number == nullptr || length <= 0) return 0;  //检测输入参数是否合法

    int middle = length/2;
    int start = 0;
    int end = length-1;
    int index = partition(number, length, start, end);

    while(index != middle){
        if(index > middle){
            end = index-1;
            index = partition(number, length, start, end);
        }

        if(index < middle){
            start = index+1;
            index = partition(number, length, start, end);
        }

    }

    int result = number[middle];

    if(!checkMoreThanHalf(number, length, result)){     //检查数组中位数出现的次数是否大于数组长度的一半
        result = 0;
    }

    return result;
}






//解法二：(推荐使用这种解法)
//利用数组本身的特点，这种解法不需要修改输入数组

int moreThanHalfNum(int *number, int length)
{
    if(number == nullptr || length <= 0) return 0;

    int result = number[0];
    int times = 1;
    for(int i = 1; i < length; i++) {
        if(times == 0) {
            result = number[i];
            times = 1;
        }
        else if(number[i] == result) times++;
        else times--;
    }

    if(!checkMoreThanHalf(number, length, result)){
        result = 0;
    }

    return result;
}