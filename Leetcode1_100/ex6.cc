

//Leetcode第6题
//ZigZag Conversion :将Z字形排列的字符按照一定顺序输出


#include <iostream>
#include <vector>
using string = std::string;


string convert(string s, int numRows);

int main(){
    string s = "PAYPALISHIRING";
    std::cout << convert(s, 4) << std::endl;

    return 0;
}



//解法一  (其中第31行的规律很难想到)
string convert(string s, int numRows)
{
    if(numRows == 1) return s;  //下面的步骤对numRows=1也照样适用,但是没必要对其执行下面的步骤;直接返回即可

    int n = s.size();
    int cycleLen = 2*numRows-2;
    string res;

    for(int i = 0; i < numRows; i++){       //i表示当前行
        for(int j = 0; i+j<n; j += cycleLen){
            res += s[i+j];
            if(i!=0 && i!=numRows-1 && j+cycleLen-i<n){    //其中的规律:j-i+cycleLen可先通过单个例子推导出来
                res += s[j+cycleLen-i];
            }
        }
    }

    return res;

}




//解法二(思路很简洁)
string convert(string s, int numRows)
{
    if(numRows == 1) return s;
    std::vector<string> rows(std::min(numRows, s.size()));    //min函数要求的数据类型为int,这里s.size()的返回类型为long,所以加上一个强制类型转换

    int curRow = 0;
    bool goingDown = false;
    for(char c:s){
        rows[curRow] += c;
        if(curRow == 0 || curRow == numRows-1) goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
    }

    string res;
    for(string row:rows) res += row;
    return res;

}