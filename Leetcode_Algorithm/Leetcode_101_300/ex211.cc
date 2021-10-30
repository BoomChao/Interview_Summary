


//Leetcode第211题 : Design Add and Search Words Data Structure 
//设计添加和搜索单词的数据结构


//思路:利用map来构造这个类


#include <iostream>
#include <unordered_map>
#include <vector>


class  WordDictionary
{
public:
    WordDictionary() {}

    void addWord(std::string word) {
        words[word.size()].push_back(word);
    }

    bool search(std::string  word) {
        for(auto s:words[word.size()]) 
        {
            if(isEqual(s, word)) {
                return true;
            }
        }

        return false;
    }


private:
    std::unordered_map<int, std::vector<std::string>> words;     //按照字符个数分类

    bool isEqual(std::string s, std::string t)
    {
        for(int i = 0; i < s.size(); i++) {
            if(t[i] == '.') continue;
            if(s[i] != t[i]) return false;
        }

        return true;
    }

};


int main(){
    WordDictionary *obj = new WordDictionary();
    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");

    std::cout << obj->search("pad") << std::endl;
    std::cout << obj->search("bad") << std::endl;
    std::cout << obj->search(".ad") << std::endl;
    std::cout << obj->search("b..") << std::endl;

    return 0;
}
