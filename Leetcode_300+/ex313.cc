

//Leetcode第313题 : Super Ugly Number
//寻找指定位数的超级丑数

//思路:仿照第264题  Ugly Number II 的解法

int nthSuperUglyNumber(int n, std::vector<int> &primes)
{
    if(n <= 0) return 0;

    int k = primes.size();
    std::vector<int> res(n);
    std::vector<int> pos(k ,0);
    res[0] = 1;

    for(int i = 1; i < n; i++)
    {
        int temp = INT_MAX;
        for(int j = 0; j < k; j++) {
            temp = std::min(temp, res[pos[j]] * primes[j]);
        }

        for(int j = 0; j < k; j++) {
            if(temp == res[pos[j]] * primes[j]) {
                pos[j]++;
            }
        }

        res[i] = temp;
    }

    return res[n-1];
}
