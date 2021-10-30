//Leetcode第30题
//给出k个子字符串,在一个大字符串中寻找连续的这几个子字符串;返回首字母索引


#include <iostream>
#include <unordered_map>
#include <vector>

using std::string ;

std::vector<int> findSubstring_1(string s, std::vector<string>& words);
std::vector<int> findSubstring_2(string s, std::vector<string>& words);


int main(){
    string s = "barfoothefoobarman";    std::vector<string> words = {"foo", "bar"};
    // string s = "barfoofoobarthefoobarman";  std::vector<string> words = {"bar", "foo", "the"};
    std::vector<int> ans;
    ans = findSubstring_2(s, words);
    for(int i = 0; i < ans.size(); i++) std::cout << ans[i] << " ";
    std::cout << std::endl;

    return 0;
}


//解法一:比较好理解(但效率没有解法二高)

std::vector<int> findSubstring_1(string s, std::vector<string>& words)
{
    std::vector<int> res;
    if(s.size()==0 || words.size() == 0) return res;
    std::unordered_map<string,int> counts;
    for(string word:words) counts[word]++;  //将子字符串存到map中,其映射的值均为1
    
    int n = s.size();       //字符串s的长度
    int num = words.size();       //words中子字符串的个数
    int length = words[0].size();    //每个子字符串的长度
    if(n < num*length) return res;      //大字符串比所有字符串的长度还要小,直接返回

    for(int i = 0; i < n-num*length+1; i++){
        std::unordered_map<string,int> seen;
        int j = 0;
        for(; j < num; j++){
            string word = s.substr(i+j*length, length);
            if(counts.find(word) != counts.end()){     //说明当前检索的字符串是要搜索的目标子字符串
                seen[word]++;
                if(seen[word]>counts[word]) break;     //判断seen中是否有重复字符串
            }
            else break;
        }
        if(j==num) res.push_back(i);
    }

    return res;

}



//解法二:效率很高(需要仔细理解)

std::vector<int> findSubstring_2(string s, std::vector<string>& words)
{
    std::vector<int> res;
    if(s.size()==0 || words.size()==0) return res;
    std::unordered_map<string, int> counts;
    for(string word:words) counts[word]++;

    int n = s.size(), num = words.size(), length = words[0].size();
    if(n < num*length) return res;

    for(int i = 0; i < length; i++){
        int j = i;
        while(j <= n-num*length){
            int count = num;
            std::unordered_map<string, int> seen;
            while(count > 0){
                string word = s.substr(j+(count-1)*length, length);
                seen[word]++;
                if((counts.find(word)==counts.end()) || (seen[word]>counts[word])) break;
                count--;
            }
            if (count == 0) res.push_back(j);
            j += std::max(count,1)*length;      //max函数声明不在头文件<algorithm>中,不需要包括<algorithm>
        }
    }

    return res; 

}

