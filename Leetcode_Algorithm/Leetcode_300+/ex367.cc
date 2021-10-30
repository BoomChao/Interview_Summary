

//Leetcode第367题:Valid Square
//判断一个数是否为完全平方数

bool isPerfectSquare(int num)
{
    if(num <= 0) return false;

    int left = 1, right = num;
    while(left <= right)
    {
        long mid = left + ((right-left)>>1);
        if(mid*mid == num) return true;
        else if(mid*mid < num) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return false;
}
