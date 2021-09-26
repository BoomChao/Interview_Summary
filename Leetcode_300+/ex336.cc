

//Leetcode第336题:Palindrome Pairs
//回文对字符串

//思路:哈希

std::vector<std::vector<int>> palindromePairs(std::vector<std::string> &words)
{
    std::unordered_map<std::string, int> mp;
    std::vector<std::vector<int>> ans;

    for(int i = 0; i < words.size(); i++) 
    {
        std::string key = words[i];
        reverse(key.begin(), key.end());
        mp[key] = i;
    }

    // 处理边界条件
    // 如果存在字符串为"",添加所有的回文对("", self)
    if(mp.find("") != mp.end())
    {
        for(int i = 0; i < words.size(); i++) 
        {
            if(mp[""] == i) continue;
            if(isPalindrome(words[i])) {
                ans.push_back({mp[""], i}); 
            }
        }
    }

    for(int i = 0; i < words.size(); i++)
    {
        for(int j = 0; j < words[i].size(); j++)
        {
            std::string left = words[i].substr(0, j);
            std::string right = words[i].substr(j);

            if(mp.find(left) != mp.end() && isPalindrome(right) && mp[left] != i) {
                ans.push_back({i, mp[left]});
            }

            if(mp.find(right) != mp.end() && isPalindrome(left) && mp[right] != i) {
                ans.push_back({mp[right], i});
            }
        }
    }

    return ans;
}


// 判断一个字符串是否为回文串
bool isPalindrome(std::string str) 
{
    int i = 0;
    int j = str.size() - 1;

    while(i < j) {
        if(str[i++] != str[j--]) return false;
    }

    return true;
}