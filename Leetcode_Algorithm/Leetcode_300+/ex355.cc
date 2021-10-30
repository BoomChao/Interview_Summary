

//Leetcode第355题:Design Twitter
//设计推特

//思路:再一次利用到了优先队列

class Twitter
{
private:
    std::unordered_map<int, std::set<int>> fo;
    std::unordered_map<int, std::vector<std::pair<int, int>>> t;
    long long time;


public:
    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        t[userId].push_back({time++, tweetId});
    }

    std::vector<int> getNewsFeed(int userId) {
        std::priority_queue<std::pair<int, int>> maxHeap;
        for(auto it = t[userId].begin(); it != t[userId].end(); it++) {
            maxHeap.push(*it);
        }

        for(auto it1 = fo[userId].begin(); it1 != fo[userId].end(); it1++) 
        {
            int usr = *it1;
            for(auto it2 = t[usr].begin(); it2 != t[usr].end(); it2++) {
                maxHeap.push(*it2);
            }
        }

        std::vector<int> res;
        while(!maxHeap.empty()) {
            res.push_back(maxHeap.top().second);
            if(res.size() == 10) break;
            maxHeap.pop();
        }

        return res;
    }

    //followerId可以理解为粉丝,followeeId可以理解为明星
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            fo[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        fo[followerId].erase(followeeId);
    }

};

