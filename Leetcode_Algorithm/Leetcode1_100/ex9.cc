

//Leetcode第9题 : Palindrome Number
//判断一个数是否为回文数

bool isPalindrome(int x)
{
    if(x < 0) return false;

    long ans = 0;   //防止输入的数据不合理,而导致数据翻转后很大溢出,所以这里使用long型来存储翻转后的结果
    int s = x;      //其实上面不使用long也可以,因为如果溢出后则结果为一个负数,就肯定不与之前的数相等了,所以这道题不需要关心是否会溢出
    
    while(s != 0) {
        ans = ans*10 + s%10;
        s /= 10;
    }

    return ans == x;
}