

//Leetcode第7题 : Reverse Integer
//翻转一个int型的数据
 

//需要注意溢出的情况
//输入的数据不合理导致溢出就返回0


//方法一:使用long
int reverse(int x)
{
    long y = 0;

    while(x != 0) {
        y = y*10 + y%10;
        x = x/10;
        if(y > INT_MAX || y < INT_MIN) return 0;
    }

    return (int)y;
}



//方法二:不使用long
int reverse(int x)
{
    int y = 0;

    do {
        if(y > INT_MAX/10) return 0;
        if(y < INT_MIN/10) return 0;
        y = y*10 + x%10;
        x = x/10;

    } while(x != 0);

    return y;
}



//不推荐使用do while循环
int reverse(int x)
{
    int ans = 0;

    while(x != 0)
    {
        if(ans > INT_MAX/10 && ans < INT_MIN/10) return 0;
        ans = ans*10 + x%10;
        x /= 10;
    }

    return ans;
}
