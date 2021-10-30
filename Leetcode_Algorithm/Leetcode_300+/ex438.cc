


///Leetcode第438题:Find All Anagrams in a String
//在字符串中找到所有字母异位词

//思路:典型的滑动窗口思想

//解法一:(会超时)

std::vector<int> findAnagrams(std::string s, std::string p)
{
    std::vector<int> res;
    if(s.empty()) return res;

    std::vector<int> count(26, 0);
    for(int i = 0; i < p.size(); i++) {     //统计p中字符出现的次数
        count[p[i]-'a']++;  
    }

    int start = 0, end = -1;        //注意:end=-1是必须的
    while(start < s.size())
    {
        //有剩余元素未考察且窗口内字符串长度小于字符串p的长度,则扩大右侧边界
        if(end + 1 < s.size() && (end - start + 1) < p.size()) {
            end++;
        }
        else {      //右侧边界不能继续扩大或者窗口内的字符串长度等于字符串p的长度,则缩小左边界
            start++;
        }

        if((end - start + 1) == p.size() && isAnagrams(s.substr(start, p.size()), count)) {
            res.push_back(start);
        }
    }

    return res;

}


bool isAnagrams(std::string str, std::vector<int> count)
{
    for(char c:str) {
        count[c-'a']--;
    }

    for(char ch:str) 
    {
        if(count[ch-'a'] != 0) {
            return false;
        }
    }

    return true;
}



//解法二:利用哈希的思想

std::vector<int> findAnagrams(std::string s, std::string p)
{
    std::vector<int> pv(26, 0);
    std::vector<int> sv(26, 0);
    std::vector<int> res;

    if(s.size() < p.size()) return res;

    for(int i = 0; i < p.size(); i++) {
        ++pv[p[i]-'a'];
        ++sv[s[i]-'a'];
    }

    if(pv == sv) {
        res.push_back(0);
    }

    for(int i = p.size(); i < s.size(); i++)
    {
        ++sv[s[i]-'a'];
        --sv[s[i-p.size()]-'a'];

        if(pv == sv) {
            res.push_back(i - p.size() + 1);
        }
    }

    return res;
}
