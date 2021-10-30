

//Leetcode第127题:Word Laddder
//单词接龙

//思路:BFS广度优先


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

int ladderLength(std::string beginword, std::string endWord, std::vector<std::string> &worlList);

int main(){
    std::vector<std::string> worlList = {"hot", "dot", "dog", "lot", "log", "cog"};

    std::cout << ladderLength("hit", "cog", worlList) << std::endl;

    return 0;
}


//BFS:广度优先搜索
//这是从一端搜索

int ladderLength(std::string beginword, std::string endWord, std::vector<std::string> &worlList)
{
    std::unordered_set<std::string> wordSet(worlList.begin(), worlList.end());

    //也可以直接在vector中查找,但是放在set中查询效率较高,哈希表查询效率为O(1)
    //如果endWord没有在wordSet中出现过,则返回0
    if(wordSet.find(endWord) == wordSet.end()) return 0;

    //记录word是否被访问过,避免形成死循环
    std::unordered_map<std::string, int> visitMap;
    //初始化visitMap
    visitMap.insert(std::pair<std::string, int>(beginword, 1));

    //初始化队列
    std::queue<std::string> que;
    que.push(beginword);

    while(!que.empty())
    {
        std::string word = que.front();
        que.pop();
        int path = visitMap[word];  //该路径的长度

        for(int i = 0; i < word.size(); i++)
        {
            std::string newWord = word;     //用一个新单词替换word,因为每次替换一个字母
            for(int j = 0; j < 26; j++)
            {
                newWord[i] = j + 'a';
                if(newWord == endWord) return path + 1;     //找到了endWord则路径加1

                //wordSet中出现了newWord并且newWord没有被访问过         这个find(newWord)不能用visitMap[newWord]==0来替换
                if(wordSet.find(newWord) != wordSet.end() && visitMap.find(newWord) == visitMap.end()) {
                    visitMap.insert(std::pair<std::string, int>(newWord, path+1));    //标记访问信息
                    que.push(newWord);
                }
            }
        }

    }

    return 0;
    
}



//BFS:因为题目给出了beginWord和endWord,我们可以同时从两端开始搜索

int ladderLength(std::string beginword, std::string endWord, std::vector<std::string> &worlList)
{
    std::unordered_set<std::string> dict(worlList.begin(), worlList.end());
    std::unordered_set<std::string> head, tail, *phead, *ptail;
    phead = ptail = nullptr;

    if(dict.find(endWord) == dict.end()) return 0;

    head.insert(beginword);
    tail.insert(endWord);
    int ladder = 2;

    while(!head.empty() && !tail.empty())
    {
        //使得两个集合的体积一样大,提高查找效率
        if(head.size() < tail.size()) {
            phead = &head;
            ptail = &tail;
        }
        else {
            phead = &tail;
            ptail = &head;
        }

        std::unordered_set<std::string> temp;
        for(auto it = phead->begin(); it != phead->end(); it++)
        {
            std::string word = *it;
            for(int i = 0; i < word.size(); i++)
            {
                char t = word[i];
                for(int j = 0; j < 26; j++)
                {
                    word[i] = j + 'a';
                    if(ptail->find(word) != ptail->end()) {
                        return ladder;
                    }
                    if(dict.find(word) != dict.end()) {
                        temp.insert(word);
                        dict.erase(word);
                    }
                }

                word[i] = t;
            }

        }

        ladder++;
        phead->swap(temp);  //将容器内容交换

    }

    return 0;

}