

//Leetcode第242题:Valid Anagran
//判断两个字符串中的字符是否完全相同

//思路:使用哈希

#include <iostream>
#include <unordered_map>

bool isAnagram(std::string s, std::string t);

int main(){
    std::cout << isAnagram("rat", "car") << std::endl;

    return 0;
}


//方法一:使用map

bool isAnagram(std::string s, std::string t)
{    
    if(s.size() != t.size()) return false;

    int n = s.size();
    std::unordered_map<char, int> counts;

    for(int i = 0; i < n; i++)
    {
        counts[s[i]]++;
        counts[t[i]]--;
    }

    for(auto count:counts) 
    {
        if(count.second) {
            return false;
        }
    }

    return true;

}



//方法二:由于哈希表会进行复杂的数学运算来存储,而且这里规定了输入的字符串只可能是小写
//所以使用数组来替代map会有更好的性能

bool isAnagram(std::string s, std::string t)
{
    if(s.size() != t.size()) return false;

    int n = s.size();
    int counts[26] = {0};

    for(int i = 0; i < n; i++)
    {
        counts[s[i]-'a']++;
        counts[t[i]-'a']--;
    }

    for(int i = 0; i < 26; i++)
    {
        if(counts[i] == 1) {
            return false;
        }
    }

    return true;

}