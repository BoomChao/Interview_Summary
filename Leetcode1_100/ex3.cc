//Leetcode第三题
//(Longest Substring Without Repeating Characters) 在给定的字符串中寻找不重复最长的子字符串,返回其长度大小


#include <iostream>
#include <vector>
#include <set>
using string = std::string;

int lengthOfLongestSubstring_1(string s);
int lengthOfLongestSubstring_2(string s);
int lengthOfLongestSubstring_3(string s);


int main(){
    string str = "pwwkew";
    std::cout << lengthOfLongestSubstring_3(str) << std::endl;

    return 0;
}



//方法一:使用集合
int lengthOfLongestSubstring_1(string s)
{
    int i = 0, res = 0;
    std::set<char> set;
    for(int j = 0; j < s.size(); j++)
    {
        if(set.find(s[j]) == set.end()){        //对STL中的容器,除了vector容器没有find函数,其他容器都有find函数;返回的是一个迭代器
            set.insert(s[j]);                   //如果集合set中存在元素s[j]就返回该元素的迭代器,不存在就是返回set.end()
            res = std::max(j-i+1, res);        //Leetcode中可以直接这样写,不用包含什么头文件
        }else{                                 
            while(s[i] != s[j]){
                set.erase(s[i++]);
            }
            ++i;
            res = std::max(j-i+1, res);
        }
    }
    
    return res;
}


//方法二:利用滑动窗口
int lengthOfLongestSubstring_3(string s)
{
    int freq[256] = {0};
    int l = 0, r = -1;
    int res = 0;
    while(l < s.size()){
        if(r+1<s.size() && freq[s[r+1]]==0){
            r++;
            freq[s[r]]++;
        }else{    //这种情况是r=s.size()-1,即r已经到头了 或者 freq[s[r+1]]=1
            l++;
            freq[s[r]]--;
        }
        res = std::max(res, r-l+1);
    }

    return res;
}


//方法三:使用字典(本质上利用的也是滑动窗口)
int lengthOfLongestSubstring_2(string s)
{
    std::vector<int>dict(256, -1);      //题目要求s可能包含英文字母,数字,符号,以及空格;所以向量dict的个数必须>=这些可能的个数总和
    int maxLen = 0, start = -1;         //查看SACII表可知计算机中表示英文中的字符一共有256种,所以这里向量的大小定为256

    for(int i = 0; i < s.size(); i++)   //start是窗口左端,i是窗口右端
    {  
        if(dict[s[i]] > start) {        //如果存在重复元素就更新窗口的起点位置
            start = dict[s[i]];
        }
        dict[s[i]] = i;
        maxLen = std::max(maxLen, i-start);
    }

    return maxLen;
}