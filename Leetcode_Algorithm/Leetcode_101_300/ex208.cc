

//Leetcode第208题 : Implement Trie(Prefix Tree)
//构建字典树


class Trie 
{
public:
    Trie() {}

    bool insert(std::string word) {
        Trie *node = this;

        for(char c:word)
        {
            if(node->next.count(c) == 0) {      //不存在后继节点则新建后继节点并存储后继节点指针
                node->next[c] = new Trie();
            }

            node = node->next[c];
        }

        node->isword = true;    //最后一个字符插入完毕,表示存在到此为止的单词
    }

    bool search(std::string word) {
        Trie *node = this;

        for(char c:word)
        {
            if(node->next.count(c) == 0) {      //不存在该字符则直接返回false
                return false;
            }

            node = node->next[c];
        }

        return node->isword;
    }

    bool startsWith(std::string prefix) {
        Trie *node = this;

        for(char c:prefix) 
        {
            if(node->next.count(c) == 0) {
                return false;
            }

            node = node->next[c];
        }

        return false;
    }



private:
    map<char, Trie*> next = {};
    bool isword = false;

};

