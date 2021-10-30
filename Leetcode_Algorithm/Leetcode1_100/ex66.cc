

//Leetcode第66题 : Plus One
//给出一个数组,返回该数组加1之后的数组
//如:[1,2,3],返回[1,2,4];   [9,9,9],返回[1,0,0,0]

//思路:
//利用尾指针,判断末尾是否小于9,如果小于9,直接在末尾加上1返回
//如果末尾等于9,将末尾置于0,判断前一位是否小于9,如果小于9直接加上1返回,否则若等于9置于0
//这样一轮完成遍历,考虑另一种情形{9,9,9},此时digits全都置于{0,0,0}而且在循环中没有返回
//则在循环外,将首位置于1,末尾添加0


std::vector<int> plusOne(std::vector<int> &digits)
{
    std::vector<int> ans;
    if(digits.empty()) return ans;

    for(int i = digits.size()-1; i >= 0; i--)
    {
        if(digits[i] < 9) {
            digits[i]++;
            return digits;
        }
        else {
            digits[i] = 0;
        }
    }

    digits[0]++;    //当为{9,9,9}这种情形时,执行完上述for循环后digits数组为{0,0,0};此时需要进位,首位加1,末尾添加0
    digits.push_back(0);
    
    return digits;
}