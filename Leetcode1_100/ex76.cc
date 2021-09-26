

//Leetcode第76题
//Minimum Window Substring : 在给定的字符串s中找到最短的包含字符串t所有元素的最短的字符串


//思路:滑动窗口


#include <iostream>
#include <vector>
#include <climits>

std::string minWindow(std::string s, std::string t);

int main(){
    std::cout << minWindow("ADOBECODEBANC", "ABC") << std::endl;

    return 0;
}



std::string minWindow(std::string s, std::string t)
{
    if(s.size() == 0 || t.size() == 0) return "";

    std::vector<int> map(128);      //注意:  写成数组形式 int map[128]; 在leetcode中会提示溢出,这是C++解题,最好写成vector形式

    for(auto c:t){
        map[c]++;   //统计t字符串中每个字母出现的次数
    }

    int left = 0;   //左指针
    int right = 0;  //右指针
    int ans_left = 0;     //窗口左边界
    int ans_right = 0;   //窗口右边界
    int ans_len = INT_MAX;
    int count = 0;   //字符串t的长度

    //遍历字符串t
    while(right < s.size()){
        char c = s[right];
        map[c]--;
        if(map[c] >= 0) count++;

        //当滑动窗口包含t中所有字母时,开始移动左指针,缩小窗口
        while(count == t.size()){       
            int tmp_len = right - left + 1;
            if(tmp_len < ans_len){
                ans_left = left;
                ans_right = right;
                ans_len = tmp_len;
            }
            // std::cout << ans_right << std::endl;

            char key = s[left];     //左指针对应字符
            map[key]++;
            if(map[key] > 0) count--;
            left++;     //左指针右移
        }
        right++;    //右指针右移

    }

    if(ans_len != INT_MAX){     //在字符串s不存在t中所有元素,则返回空
        return s.substr(ans_left, ans_len);
    }

    return "";

}



//滑动窗口解法二:(比较好理解)

std::string minWindow(std::string s, std::string p)
{
    std::string res;
    if(s.size() < p.size()) return res;

    std::vector<int> pFreq(128, 0);
    for(char c:p) {
        pFreq[c]++;
    }

    std::vector<int> windowFreq(128, 0);     //用于记录窗口中每个字符出现的次数
    int windowSameCount = 0;                //当前窗口中和字符串t中字符相同的字符个数
    int minWindowLen = s.size() + 1;
    int startIndex = -1;

    int start = 0, end = -1;
    while(start < s.size())
    {
        if(end + 1 < s.size() && windowSameCount < p.size()) {
            windowFreq[s[end+1]]++;

            //窗口当前出现的字符的个数小于等于字符串t中字符的出现次数
            //则窗口中当前出现的字符是在字符串t中出现的
            if(windowFreq[s[end+1]] <= pFreq[s[end+1]]) {   //这里只能用<=,因为p中可能出现重复的字符
                windowSameCount++;
            }

            end++;
        }
        else {
            //字符串p中字符全部都在窗口中出现
            if(windowSameCount == p.size() && (end - start + 1) < minWindowLen) {
                minWindowLen = end - start + 1;
                startIndex = start;
            }

            //窗口左移
            windowFreq[s[start]]--;
            if(windowFreq[s[start]] < pFreq[s[start]]) {
                windowSameCount--;
            }

            start++;
        }
    }
    
    if(startIndex != -1) {
        res = s.substr(startIndex, minWindowLen);
    }

    return res;
}
