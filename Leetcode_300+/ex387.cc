

//Leetcode第387题:First Character in a String
//找到字符串中第一个不重复的字符

//思路:使用哈希
//但是注意由于这个题目说明了只会是小写字母,可以使用map
//但是自己用数组实现一个哈希表效率会更高


int firstUniqChar(string s) 
{
    if(s.empty()) return -1;
    
    vector<int> count(26, 0);   //26个小写字母
    for(auto &c:s) {
        count[c-'a']++;
    }
    
    for(int i = 0; i < s.size(); i++) {
        if(count[s[i]-'a'] == 1) return i;
    }
    
    return -1;
}