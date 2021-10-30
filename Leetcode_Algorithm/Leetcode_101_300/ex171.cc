

//Leetcode第171题:Excel Sheet Column Number
//将excel表格名称转换成数字

//和第168题相似,将其看成27进制的转换即可

int titleToNumber(std::string s)
{
    int result = 0;
    
    for(int i = 0; i < s.size(); i++) {
        result = result*26 + (s[i] - 'A' + 1);
    }

    return result;

}
