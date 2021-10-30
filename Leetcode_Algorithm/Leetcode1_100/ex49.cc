

//Leetcode第49题
//Group Anagrams:给出一个字符串,归类出次序不同但元素相同的字符串

//思路:使用unordered_map,将具有次序不同但元素相同的字符串映射到同一个map中
//再提取出map的第二项的value值

std::vector<std::vector<string>> groupAnagrams(std::vector<string> &strs)
{
    std::unordered_map<string, std::vector<string>> mp;

    for(string &s:strs) {    //这里传递引用可以减少传值时的值复制的时间
        // string tmp = s;
        // sort(tmp.begin(), tmp.end());
        // mp[tmp].push_back(s);            //使用sort的时间复杂度为O(nlogn)
        mp[strSort(s)].push_back(s);        //使用strSort函数的时间复杂度为O(n)
    }

    std::vector<std::vector<string>> anagrams;

    for(auto &p:mp) {    //注意:这里p不是unordered_map 而是 pair,即等价于 std::pair<string, std::vector<string>> &p:mp
        anagrams.push_back(p.second);     //这里auto的用法很巧妙,需要仔细体会,而且使用.second就说明p是一个pair,不是map
    }
    
    return anagrams;
}



//由于给定的字符串数组中的字符串只包含小写字母
//上述将字符串排序的函数可以自己书写来减小时间复杂度
//因为自带的sort函数的时间复杂度为nlogn,下面函数的时间复杂度为n

std::string strSort(std::string s)
{
    int counter[26] = {0};

    for(char c : s) {
        counter[c-'a']++;
    }

    std::string res;
    for(int i = 0; i < 26; i++) {
        res += std::string(counter[i], (char)('a' + i));
    }

    return res;
}