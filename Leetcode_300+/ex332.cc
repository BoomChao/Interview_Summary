

//Leetcode第332题:Reconstruct Itinerary
//重构飞行路线


//思路:本身题目不难,但是涉及到多种数据结构


std::vector<std::string> findItinerary(std::vector<std::vector<std::string>> &tickets)
{
    std::vector<std::string> itinerary;
    if(tickets.empty()) return itinerary;

    std::unordered_map<std::string, std::multiset<std::string>> graph;

    for(auto tick : tickets) {
        graph[tick[0]].insert(tick[1]);
    }

    std::stack<std::string> sta;
    sta.push("JFK");
    while(!sta.empty())
    {
        std::string toAirport = sta.top();

        if(graph[toAirport].empty()) {      //这个if语句里面的内容一定是遍历结束了才开始执行的,否则给出的数组就不对
            itinerary.push_back(toAirport);
            sta.pop();
        }
        else {
            sta.push(*(graph[toAirport].begin()));
            graph[toAirport].erase(graph[toAirport].begin());
        }

    }

    //将itenerary翻转顺序(因为出栈顺序是反着的)
    reverse(itinerary.begin(), itinerary.end());

    return itinerary;

}
