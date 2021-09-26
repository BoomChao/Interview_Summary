


//Leetcode第187题:Repeated DNA Sequences
//找到重复的字符串序列(重复字符至少为两次)


//两种方法:1.利用哈希表     2.位运算+哈希


#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <bitset>

std::vector<std::string> findRepeatDnaSequences(std::string s);

int char2val(char c);

int main(){
    std::string s = "AAAAAAAAAAAAAAAA";

    std::vector<std::string> ans = findRepeatDnaSequences(s);

    for(auto str:ans) {
        std::cout << str << std::endl;
    }


    return 0;
}



//解法一(暴力破解):利用哈希表(unordered_map)

std::vector<std::string> findRepeatDnaSequences(std::string s)
{
    std::unordered_map<std::string, int> mp;
    std::vector<std::string> ans;

    if(s.size() <= 10) return ans;

    for(int i = 0; i <= s.size()-10; i++)
    {
        std::string temp = s.substr(i, 10);

        if(mp.find(temp) != mp.end()) {
            mp[temp] += 1;      //已经存在就将次数加1
        }
        else {
            mp[temp] = 1;       //不存在就记录进map中
        }

    }

/*
    for(std::unordered_map<std::string, int>::iterator it = mp.begin(); it != mp.end(); it++) 
    {
        if(it->second > 1) 
        {
            ans.push_back(it->first);
        }
    }
*/

    //利用上面的迭代器或者下面的这种auto的写法都可以,但是如果使用迭代器,则需要使用"->"运算符,使用auto则使用"."运算符
    for(auto it:mp) 
    {
        if(it.second > 1) 
        {
            ans.push_back(it.first);
        }
    }

    return ans;

}



//解法二:位运算加上哈希

int char2val(char c)
{
    switch(c){
        case 'A' : return 0;
        case 'B' : return 1;
        case 'G' : return 2;
        case 'T' : return 3;
    }

}


std::vector<std::string> findRepeatDnaSequences(std::string s)
{
    std::vector<std::string> ans;
    std::bitset<1<<20> s1;          //s1用来判断字符串是否出现过
    std::bitset<1<<20> s2;          //s2用来判断字符串出现过几次

    if(s.size() <= 10) return ans;

    int val = 0;
    for(int i = 0; i < 10; i++) {
        val = (val << 2) | char2val(s[i]);
    }
    s1.set(val);
    // std::cout << val << " | ";

    int mask = (1 << 20) - 1;
    for(int i = 10; i < s.size(); i++)
    {
        val = ((val<<2) & mask) | char2val(s[i]);
        
        if(s2[val]) {
            continue;
        }
        
        if(s1[val]) {
            ans.push_back(s.substr(i-10+1, 10));
            s2.set(val);
        }
        else {
            s1.set(val);            
        }

    }

    return ans;

}

