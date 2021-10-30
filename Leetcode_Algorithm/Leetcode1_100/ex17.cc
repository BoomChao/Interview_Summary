

//Leetcode第17题
//Letter Combinations of a Phone Number : 输入电话机上的任意个数字,给出所有这些电话数对应的字符的所有有序集合



std::vector<std::string> res;

//解法一:使用递归 深度优先搜索

std::vector<string> letterCombination(string digits){
    if(digits.empty()) return {};

    std::unordered_map<char, string> letter{ {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, {'6',"mno"}, {'7', "pqrs"}, {'8',"tuv"}, {'9',"wxyz"} };
    std::vector<string>res;
    string combination(digits.length(), ' ');   //这是使用了字符串的构造函数
    dfs(digits, combination, 0, letter);
    
    return res;
}

void dfs(string digits, string &combination, int pos, std::unordered_map<char,string> letter)
{
    if(idx == digits.length()){
        res.push_back(combination);
        return;
    }

    for(char c:letter[digits[pos]-'0']){
        combination[pos] = c;
        dfs(digits, combination, pos+1, letter);
    }


}


//附:字符串的构造函数:
//1.string(string s) 用字符串s对当前字符串初始化
//2.string(int n, char c) 用n的字符c初始化当前字符串









//解法二:使用迭代
std::vector<string> letterCombination(string digits)
{
    if (digits.size()==0) return {};

    std::vector<string> res;
    res.push_back("");         //res必须要提前给定一个位置为1的元素,这个元素为空;此时res.size()=1
    std::unordered_map<char, string> num_to_char = { {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, {'6',"mno"}, {'7', "pqrs"}, {'8',"tuv"}, {'9',"wxyz"} };
    
    for(int i = 0; i < digits.size(); i++){
        if(digits[i]<'2' || digits[i]>'9')    continue;

        std::vector<string> temp;
        string cur = num_to_char[digits[i]];

        for(int j = 0; j < res.size(); j++){
            for(int k = 0; k < cur.size(); k++){        //这个循环要放在里面
                temp.push_back(res[j] + cur[k]);
            }
        }
        res = temp;
        temp.clear();
    }

    return res;

}