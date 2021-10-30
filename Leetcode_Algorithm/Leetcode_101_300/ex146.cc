

//Leetcode第146题:LRU Cache
//设计一个LRU缓存结构

//思路:链表+哈希
//重点在于list的splice方法


class LRUCache
{
public:
    LRUCache(int capacity) : size(capacity) {

    }

    int get() {
        auto it = hash.find(key);
        if(it == hash.end()) {
            return -1;
        }

        cache.splice(cache.begin(), cache, it->second);

        return it->second->second;
    }

    void put(int key, int value) {
        auto it = hash.find(key);
        if(it != hash.end()) {
            it->second->second = value;
            return cache.splice(cache.begin(), cache, it->second);
        }
        
        cache.insert(cache.begin(), std::make_pair(key, value));
        hash[key] = cache.begin();

        if(cache.size() > size) {
            hash.erase(cache.back().first);
            cache.pop_back();
        }
    }


private:
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> hash;
    std::list<std::pair<int, int>> cache;
    int size;
}
