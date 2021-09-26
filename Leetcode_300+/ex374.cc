

// Leetcode第374题:Guess Number Higher or Lower
// 猜数问题

// 思路:二分

int guessNumber(int n) 
{
    int left = 1, right = n;
    while(left <= right)
    {
        int mid = left + ((right-left) >> 1);
        if(guess(mid) == -1) {
            right = mid-1;
        }
        else if(guess(mid == 1)) {
            left = mid+1;
        }
        else {
            return mid;
        }
    }
    
    return -1;
}