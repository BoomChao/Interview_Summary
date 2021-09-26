


//Leetcode第165题:Compare Version Number
//版本比较

//注意:If a version number does not specify a revision at an index,then treat the revision as 0;
//如:"1.0.1" 和 "1"比较,因为前面的version1有三部分,则后面的version2可以看成 "1.0.0"
//即"1.0.1"和"1.0.0"比价,结果为1


#include <iostream>
#include <algorithm>
#include <sstream>

int compareVersion(std::string version1, std::string version2);

int main(){

    std::cout << compareVersion("0.1", "1.1") << std::endl;

    return 0;
}


//解法一:利用字符串流

int compareVersion(std::string version1, std::string version2)
{
    int count1 = count(version1.begin(), version1.end(), '.');      //利用count统计'.'在字符中出现的次数
    int count2 = count(version2.begin(), version2.end(), '.');

    //将两个字符串补充到等长
    while(count1 < count2) {
        --count2;
        version1 += ".0";
    }

    while(count2 < count1) {
        --count1;
        version2 += ".0";
    }

    std::stringstream ss1(version1), ss2(version2);
    std::string s1, s2;

    //以'.'字符来分割字符串
    while(getline(ss1, s1, '.') && getline(ss2, s2, '.')) {
        if(stoi(s1) > stoi(s2)) return 1;           //利用stoi函数将数字字符串转化成数字
        else if(stoi(s1) < stoi(s2)) return -1;
    }

    return 0;

}



//解法二:利用双指针

int compareVersion(std::string version1, std::string version2)
{
    int n = version1.size(), m = version2.size();
    int i = 0, j = 0;
    int a = 0, b = 0;
    std::string s = "", t = "";

    while(i < n || j < m)
    {
        s = t = "";
        while(i < n && version1[i] != '.') {
            s += version1[i];
            i++;
        }
        
        while(j < m && version2[j] != '.') {
            t += version2[j];
            j++;
        }

        a = s.size() ? stoi(s) : 0;
        b = t.size() ? stoi(t) : 0;

        if(a > b) return 1;
        if(a < b) return -1;

        i++;
        j++;

    }

    return 0;

}