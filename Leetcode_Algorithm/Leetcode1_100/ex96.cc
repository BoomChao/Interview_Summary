

//Leetcode第96题: Unique Binary Search Trees
//给出一个数字n,求出有多少个不同的叉搜索树可以存储值1-n

//思路
//1.如果给定的整数是1的话,那么结果只可能会是1
//2.如果给定的整数大于1的话那么就需要考虑根为i(2<=i<=n)的情况
//定义函数f(n)代表返回以n为输入的二叉树的个数
//根节点的左边有i-1个数,根节点的右边有n-i个数;那么左边二叉树的个数就为f(i-1),右边二叉树的个数就为f(n-i)
//此时还有一种情况没有考虑,那就是 f(0)=1,f(0)就代表没有左子树或者右子树
//则:f(0)=1, f(1)=1;
//  f(n)=f(i-1)*f(n-i)(i从1到n累加)


//这种迭代解法会超时,为此将这种递归解法写成迭代解法

int numTrees(int n)
{

    return numTreesCore(n);
}

int numTreesCore(int n)
{
    if(n == 0 || n == 1) return 1;

    int res = 0;

    for(int i = 1; i <= n; i++)
    {
        res += numTreesCore(i-1)*numTreesCore(n-i);
    }

    return res;

}


// f(n) 表示节点数为n时的二叉树种类数
// f(0) = 1, f(1) = 1
// f(2) = f(0)*根*f(2-1-0) + f(1)*根*f(2-1-1)

// f(n) = f(0)*根*f(n-1-0) + ... f(i)*根*f(n-1-i) + ... + f(n-1)*根*f(0)

//迭代解法:利用动态规划

int numTrees(int n)
{
    std::vector<int> res(n+1, 0);
    res[0] = res[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            res[i] += res[j-1]*res[i-j];
        }

    }

    return res[n];
}


func numTrees(n int) int {
    dp := make([]int, n + 1)
    dp[0], dp[1] = 1, 1

    for i := 2; i <= n; i++ {
        for j := 1; j <= i; j++ {
            dp[i] += dp[j-1]*dp[i-j]
        }
    }

    return dp[n]
}

