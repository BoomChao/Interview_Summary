

//Leetcode第354题 : Russian Doll Envelopes
//计算能嵌套的最多的区间数目


struct compapare {
    bool operator()(std::vector<int> &i, std::vector<int> &j) {
        if(i[0] < j[0]) {
            return true;
        }
        else if(i[0] == j[0]) {
            return i[1] > j[1];
        }

        return false;
    }

};

int maxEnvelopes(std::vector<std::vector<int>> &envelopes)
{
    if(envelopes.empty()) return 0;

    sort(envelopes.begin(), envelopes.end(), compapare());

    std::vector<int> dp;
    for(auto e:envelopes) 
    {
        auto iter = lower_bound(dp.begin(), dp.end(), e[1]);
        if(iter == dp.end()) {
            dp.push_back(e[1]);
        }
        else if(e[1] < *iter) {
            *iter = e[1];           //注:这行语句一定要; 这个的作用是使外层区间在能包含内层区间的情况下尽可能的范围小一点
        }
    }

    return dp.size();
    
}
