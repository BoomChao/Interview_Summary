

//Leetcode第357题:Count Numbers with Unique Digits
//计算制定位数的不包含重复数字的个数

//思路:找到数学规律

//计算阶乘,相当于A(n,r)
int permutation(int n, int r)
{
    if(r == 0) {
        return 1;
    }
    else {
        return n*permutation(n-1, r-1);
    }

}

int countNumbersWithUniqueDigits(int n) 
{
    int sum = 1;
    if(n > 0) 
    {
        int end = (n > 10) ? 10 : n;    //如果位数超过了十位,则是一定会有重复的元素的
        for(int i = 0; i < end; i++) {
            sum += 9*permutation(9, i);
        }
    }

    return sum;
}
