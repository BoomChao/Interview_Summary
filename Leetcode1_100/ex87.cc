

//Leetcode第87题
//Scramble String : 判断字符串s1能否生成字符串s2


//思路:使用递归
//1.假如有两个字符串,great和rgeat
//2.第一种情况:将s1切割成两部分,判断,然后进行若干步交换,最后判断两个子树是否相等
//3.第二种情况:将s1切割并且交换成两部分,再判断



#include <iostream>
#include <vector>
#include <algorithm>

bool isScramble(std::string s1, std::string s2);

int main(){
    std::cout << isScramble("great", "rgeat") << std::endl;

    return 0;
}


bool isScramble(std::string s1, std::string s2)
{
    if(s1.size() != s2.size()) return false;
    if(s1 == s2) return true;

    std::string s_1 = s1;
    std::string s_2 = s2;
    sort(s_1.begin(), s_1.end());
    sort(s_2.begin(), s_2.end());
    if(s_1 != s_2) return false;      //如果发现s1和s2中有不同的字符,则s1肯定不能生成s2

    int n = s1.size();
    for(int i = 1; i < s1.size(); i++){
        
        //将s1的切割后的左半部分与s2对应的左半部分比较,s1的右半部分与s2的右半部分比较
        bool left = isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i));    

        //将s1切割后的左半部分与s2的右半部分比较,s1右半部分与s2的左半部分比较
        bool right = isScramble(s1.substr(0,i), s2.substr(n-i)) && isScramble(s1.substr(i), s2.substr(0,n-i));  

        if(left || right) return true;  //上面两种情况只要有一种是true,则返回true

    }


    return false; 

}



//上面判断s1字符串和s2中是否有重复元素,是将其排序后比较的;
//我们可以直接用数组构成一个哈希表来存储字符在这两个字符串中出现的字符

bool isScramble(std::string s1, std::string s2)
{
    if(s1.size() != s2.size()) return false;
    if(s1 == s2) return true;
    
    
    int n = s1.size();
    int count[256] = {0};   //一共只可能存在256中字符

    for(int i = 0; i < n; i++){
        count[s1[i]-'a']++;
        count[s2[i]-'a']--;
    }
    //上面count数组最后的结果是,如果s1和s2都有该字符,则count为0;如果仅s1中有该字符,则count为1;如果仅s2中有该字符,则count为-1

    for(int i = 0; i < 256; i++){
        if(count[i] != 0) return false;
    }

    for(int i = 1; i < s1.size(); i++){
        
        //将s1的切割后的左半部分与s2对应的左半部分比较,s1的右半部分与s2的右半部分比较
        bool left = isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i));    

        //将s1切割后的左半部分与s2的右半部分比较,s1右半部分与s2的左半部分比较
        bool right = isScramble(s1.substr(0,i), s2.substr(n-i)) && isScramble(s1.substr(i), s2.substr(0,n-i));  

        if(left || right) return true;  //上面两种情况只要有一种是true,则返回true

    }

    return false;


}