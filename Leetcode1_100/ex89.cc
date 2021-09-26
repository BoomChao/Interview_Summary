

//Leetcode第89题:
//Gray Code : 格雷编码


//格雷编码是值连续的两个数字只有一个bit位不同;  如:00 01 11 10 ->0 1 3 2 就是格雷码数
//对三个比特位, 000 001 011 010 100 101 111 110 前四个前面补0,后四个前面补1
//但是后面四个之前在前面补1的数就不是格雷编码,因为010 和 100有三个bit位不同,格雷码要求只能有一个bit位不同;
//所以对n=3,不能简单的在n=2形成的数前面补0或者1
//格雷码数的第一个数一定以0开头


//思路1:
//对n=1, 有 0 -> 0 1
//对n=2, 我们按照倒序在前面加2,有 00 01 11 10 -> 0 1 3 2
//对n=3, 我们按照倒序在前面加4,有 000 001 011 010 110 111 101 100 -> 0 1 3 2 6 7 5 4



#include <iostream>
#include <vector>

std::vector<int> grayCode(int n);
std::vector<int> grayCode_1(int n);

int main(){
    std::vector<int> ans = grayCode_1(2);
    
    for(int i = 0; i < ans.size(); i++){
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}


std::vector<int> grayCode(int n)
{
    std::vector<int> res(1, 0);

    for(int i = 0; i < n; i++){
        int add = 1<<i;
        for(int j = res.size()-1; j >= 0; j--){
            res.push_back(res[j] + add);
        }
    }

    return res;

}




//思路二:按照格雷码的生成规则
//1.将一个二进制数转换成对应的格雷码操作为
//比如10110 将最高位保留,其他位是当前位与它的高一位进行异或,结果为 11101
// i = 0, 结果为 0
// i = 1, 结果为 1
// i = 2, 010^001 = 011, 结果为3
// i = 3, 011^001 = 010, 结果为2

//输入n,一共有(1<<n)个结果, 1<<n = 2^n

std::vector<int> grayCode_1(int n)
{
    std::vector<int> res;

    for(int i = 0; i < (1<<n); i++){
        res.push_back(i^(i>>1));
    }

    return res;

}