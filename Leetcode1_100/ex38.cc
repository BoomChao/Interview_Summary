//Leetcode第38题
//Count and Say:数数组中的元素


//思路:
//假设n为2,则需要数三次,n=3,需要数三次;需要注意无论n为多少,每次都是从n=1开始数的
//每一次数的过程中,定义一个临时字符串来存储该次数完的结果,数的过程中,判断当前字符与后一个字符是否相同,
//若相同计数加1,直到找到不相同的为止,需要注意初始结果字符串赋值为"1"
//再将临时字符串赋值给结果字符串,一共这样循环n次即可

#include <iostream>

using std::string;

string countArray(int n);

int main(){
    std::cout << countArray(5) << std::endl;

    return 0;
}

string countArray(int n)
{
    if(n == 0) return "";
    string res = "1";
    
    while(--n){
        string cur = "";
        for(int i = 0; i < res.size(); i++){
            int count = 1;
            while(i<res.size()-1 && res[i]==res[i+1]){
                count++;
                i++;
            }
            cur += std::to_string(count)+res[i];
        }
        res = cur;
    }

    return res;

}
