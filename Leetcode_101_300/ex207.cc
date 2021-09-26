


//Leetcode第207题 : Course Schedule
//课程表


#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisities);

int main(){
    // std::vector<std::vector<int>> prerequisities = {{3,0}, {3,1}, {4,1}, {4,2}, {5,3}, {5,4}};

    std::vector<std::vector<int>> prerequisities = {{1,0}, {0,1}};
    std::cout << canFinish(2, prerequisities) << std::endl;

    return 0;
}



//解法一:

bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisities)
{
    std::unordered_map<int, int> degree;    //用来记录课程的度
    std::vector<int> e[numCourses];

    std::queue<int> que;

    for(int i = 0; i < prerequisities.size(); i++) 
    {
        e[prerequisities[i][1]].push_back(prerequisities[i][0]);
        degree[prerequisities[i][0]]++;
    }

    for(int i = 0; i < numCourses; i++) 
    {
        if(degree[i] == 0) {
            que.push(i);
        }
    }


    std::vector<int> ans;
    while(!que.empty())
    {
        int x = que.front();
        ans.push_back(x);
        que.pop();
        
        for(auto tmp:e[x])
        {
            degree[tmp]--;
            if(degree[tmp] == 0) {
                que.push(tmp);
            }
        }
    }

    return ans.size() == numCourses;

}



//优化:

bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisities)
{
    std::vector<std::vector<int>> graph(numCourses);
    std::vector<int> degree(numCourses ,0);
    std::vector<int> ans;

/*
    for(int i = 0; i < prerequisities.size(); i++)
    {
        G[prerequisities[i][1]].push_back(prerequisities[i][0]);
        degree[prerequisities[i][0]]++;
    }
*/

    //如果觉得上面写的太过繁琐,可以这样写
    for(auto &e:prerequisities) {
        graph[e[1]].push_back(e[0]);
        degree[e[0]]++;
    }

    for(int i = 0; i < numCourses; i++) 
    {
        if(!degree[i]) {
            ans.push_back(i);
        }
    }

    for(int i = 0; i < ans.size(); i++)
    {
        for(int &num:graph[ans[i]]) 
        {
            if(--degree[num] == 0) {
                ans.push_back(num);
            }
        }
    }

    return ans.size() == numCourses;

}

