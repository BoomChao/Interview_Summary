

//Leetcode第383题:Ransom Note
//判断一个字符串中的字符是否全部位于另一个字符串中

//思路:利用哈希

bool canConstruct(string ransomNote, string magazine) 
{
    std::vector<int> count(26, 0);
    for(char c:magazine) {
        count[c-'a']++;
    }
    
    for(char ch:ransomNote) {
        if(count[ch-'a']-- == 0) {
            return false;
        }
    }
    
    return true;
}