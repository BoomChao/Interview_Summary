


//Leetcode第412题:Fizz Buzz


//解法一:利用除法运算提前计算处需要的个数

std::vector<std::string> fizzBuzz(int n)
{
    if(n <= 0) return {};

    std::vector<std::string> ans(n, "");

    for(int i = 0; i < n; i++) {
        ans[i] = std::to_string(i + 1) ;
    }

    int timeOf3 = n / 3;
    int timeOf5 = n / 5;
    int timeOf15 = n / 15;

    for(int i = 1; i <= timeOf3; i++) {
        ans[i*3-1] = "Fizz";
    }

    for(int i = 1; i <= timeOf5; i++) {
        ans[i*5-1] = "Buzz";
    }

    for(int i = 1; i <= timeOf15; i++) {
        ans[i*15-1] = "FizzBuzz";
    }

    return ans;

}


//解法二:除法操作一定程序上会效率比较低;这里使用循环替代

std::vector<std::string> fizzBuzz(int n)
{
    std::vector<std::string> res(n);

    for(int i = 1; i <= n; i++) {
        res[i - 1] = to_string(i);
    }

    for(int i = 2; i < n; i += 3) {
        res[i] = "Fizz";
    }

    for(int i = 4; i < n; i += 5) {
        res[i] = "Buzz";
    }

    for(int i = 14; i < n; i += 15) {
        res[i] = "FizzBuzz";
    }

    return res;
}
