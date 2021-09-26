

//Leetcode第395题:Longest Substring with At Least K Repeating Characters
//找到一个字符串,其中元素的出现次数都>=k

//思路:使用递归

int longestSubstring(std::string s, int k)
{
    if(s.empty() || s.size() < k) return 0;
    if(k == 0) return s.size();

    //第一次遍历记录各个元素出现的次数
    std::unordered_map<char, int> mp;
    for(int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
    }

    //第二次遍历找到出现次数小于k的元素,这个元素肯定不在目标序列中
    //该元素将整个字符串分为左右两个部分,求出左右两个部分的最大值就行
    int index = 0;
    while(index < s.size() && mp[s[index]] >= k) index++;
    if(index == s.size()) return s.size();

    int left = longestSubstring(s.substr(0, index), k);
    int right = longestSubstring(s.substr(index + 1), k);

    return std::max(left, right);
}



//对上面代码的优化
int longestSubstring(std::string s, int k)
{
    if(s.empty() || s.size() < k) return 0;
    if(k == 0) return s.size();

    //因为题目说了字符串只会有小写字母,这里可以使用vector来代替map
    std::vector<int> count(26, 0);
    for(char c:s) {
        count[c-'a']++;
    }

    //第二次遍历找到出现次数小于k的元素,这个元素肯定不在目标序列中
    //该元素将整个字符串分为左右两个部分,求出左右两个部分的最大值就行

    //因为字符串aaabcdeee可能是这样,中间有若干个元素出现次数都小于3
    int mid = 0;
    while(mid < s.size() && count[s[mid]-'a'] >= k) mid++;
    if(mid == s.size()) return s.size();
    int left = longestSubstring(s.substr(0, mid), k);       //此时mid=3

    while(mid < s.size() && count[s[mid]-'a'] < k) mid++;       //此时mid=6(这个while循环的作用就是跳过中间出现次数小于k的字符)
    int right = longestSubstring(s.substr(mid), k);

    return std::max(left, right);
}
