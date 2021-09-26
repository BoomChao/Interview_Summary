//Leetcode第60题
//Permutation Sequence : 找到顺序排列组合的第k个排列


//方法一:使用递归
//思路:假定 n=4,k=14,则对于序列 {1,2,3,4}
//有以下四种情况: 1+pemute(2,3,4)   2+permute(1,3,4)  3+pemute(1,2,4)   4+permute(1,2,3); 每种情况有6个子集
//由于14-6*2=2,则结果一定是在第三种情况中
//permute(1,2,4)有以下三种情况: 1+permute(2,4)   2+permute(1,4)  4+permute(1,2); 每种情况有2个子集
//由于2-2*1=0 所以结果一定是在第1种情况中,并且是pemute(2,4)的第二个子集,为{4,2}
//故结果为 "3,1,4,2"



#include <iostream>
#include <vector>
#include <algorithm>

std::string getPermutation(int n, int k);
void helper(std::string &res, std::string &str, int n, int k, std::vector<int> &tmp);


int main(){
    std::cout << getPermutation(3, 3) << std::endl;

    return 0;
}

std::string getPermutation(int n, int k)
{
    std::string str(n, '0');          //str字符串存储的是初始的n个字,比如 n= 4, 则为 "1234"
    for(int i = 1; i <= n; i++){
        str[i-1] += i;
    }

    std::vector<int> tmp(n+1, 1);     //tmp数组中存储的是阶乘 {1,1,2,6,24}
    for(int i = 2; i <= n; i++){       //首位索引为0的不用管 如:tmp[3] = 6, 代表3的阶乘是6
        tmp[i] = tmp[i-1]*(i);
    }

    std::string res;
    helper(res, str, n, k-1, tmp);   //注意:数组是从下标为0开始的,这里k需要减去1

    return res;

}

void helper(std::string &res, std::string &str, int n, int k, std::vector<int> &tmp){
    if(n == 1){
        res += str[0];
        return;
    }

    int m = k/tmp[n-1];
    k = k%tmp[n-1];
    res += str[m];
    str.erase(m, 1);    //将取出的字符从原字符串中删除

    helper(res, str, n-1, k, tmp);

}