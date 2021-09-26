/*
#include <string>
#include <iostream>
#include <algorithm>

using string = std::string;

string res;     //定义两个全局变量
int count, max;

void fun(string s, int k);
string longestPalindrome(string s);

int main(){
    string str = "cdbbd";
    std::cout << longestPalindrome(str) << std::endl;
    
    return 0;
}



bool isPalindrome(string s);
string longestPalindrome(string s);

//解法一(时间复杂度为O(n))
bool isPalindrome(string s)
{
    string temp = s;
    reverse(temp.begin(), temp.end());

    return temp == s;
}


string longestPalindrome(string s)
{
    if(s.size() == 0) return "";
    int N = s.size();
    string res;
    
    for(int i = 0; i < N; i++){
        for(int j = 1; j <= N-i; j++){
            string temp;
            temp = s.substr(i,j);

            if( isPalindrome(temp) ){
                if(temp.size() > res.size()){
                    res = temp;
                }
            }
        }
    }

    return res;

}




//解法二(推荐该解法)
void fun(string s, int k)
{
    int i = k;
    int n = s.size(), j;
    for(j = i; j < n; j++){     //计算连续重复的字符,如 abbba, 计算bbb
        if(s[j] == s[i]){
            count++;
        }
        else break;     //这个break千万不要忘了
    }

    i--;    //i前移一位是为下面这一步做准备的; 连续重复的字符的的一位索引为i,最后一位为j;由于上面结束循环时j已经加了1,所以这里只需将i-1
    while(i>=0 && j<n){     //上面一步判断出了连续重复的字符,由于连续重复的字符一定是回文数,这时判断
        if(s[i] == s[j]){   //连续重复的字符的左右两端的字符是否相等;相等则也是回文数
            count += 2;
            i--;
            j++;
        }
        else break;     //这个break千万不要忘了
    }

    if(max < count){
        max = count;
        res = s.substr(i+1, count); 
    }


}

string longestPalindrome(string s)
{
    max = 0;
    res = "";
    for(int i = 0; i < s.size(); i++){
        count = 0;
        fun(s, i);
    }

    return res;
}

*/

/*
#include <iostream>
#include <vector>

int maxArea(std::vector<int> &height);

int main(){
    std::vector<int> num = {1,8,6,2,5,4,8,3,7};
    std::cout << maxArea(num) << std::endl;

    return 0;
}

int maxArea(std::vector<int> &height)
{
    
    int wide, hei;
    int max = 0, area = 0;
    int left = 0, right = height.size()-1;
    
    while(left < right){
        wide = right - left;
        hei = height[left] < height[right] ? height[left++] : height[right--];
        area = wide*hei;

        if(area > max) max = area; 

    }

    return max;

}*/


#include <iostream>
#include <vector>
#include <algorithm>

using std::string;

string convert(string s, int numRows);

int main(){
    string s = "PAYPALISHIRING";
    std::cout << convert(s, 4) << std::endl;

    // std::vector<string> rows(3);

    return 0;
}

string convert(string s, int numRows)
{
    if(numRows == 1) return s;

    std::vector<string> rows(std::min(numRows, (int)s.size()));
    int curRow = 0;
    bool goingDown = false;
    for(char c:s){
        rows[curRow] += c;
        if(curRow == 0 || curRow == numRows-1)  goingDown = !goingDown;
        curRow += goingDown ? 1 :-1;
    }

    string res;
    for(string row:rows){
        res += row;
    }

    return res;

}

