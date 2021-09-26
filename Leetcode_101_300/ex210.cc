

//Leetcode第210题 : Course Schedule II
//课程表II

//思路和207题完全相同,只是将返回值修改一下即可


bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisities)
{
    std::vector<std::vector<int>> graph(numCourses);
    std::vector<int> degree(numCourses ,0);         //用来记录课程的度
    std::vector<int> ans;

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

    //就只有返回值与207题有所不同
    if(ans.size() == numCourses) {
        return ans;
    }
    else {
        return {};
    }

}
