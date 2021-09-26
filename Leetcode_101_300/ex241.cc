


//Leetcode第241题:Different Ways to Add Parentheses
//对表达式添加括号判断其能组成几种计算结果


std::vector<int> diffWaysToCompute(std::string input)
{
    std::vector<int> result;

    for(int i = 0; i < input.size(); i++)
    {
        char cur = input[i];
        if(cur == '+' || cur == '-' || cur == '*')
        {
            std::vector<int> res1 = diffWaysToCompute(input.substr(0, i));
            std::vector<int> res2 = diffWaysToCompute(input.substr(i+1));

            for(auto &n1:res1) {
                for(auto &n2:res2) {
                    if(cur == '+') {
                        result.push_back(n1 + n2);
                    }
                    else if(cur == '-') {
                        result.push_back(n1 - n2);
                    }
                    else {
                        result.push_back(n1 * n2);
                    }
                }
            }
        }

    }

    if(result.empty()) {
        result.push_back(std::stoi(input));
    }

    return result;

}



//上面的解法存在重复计算,使用map保存已经计算过的字符串表达式
//动态规划

std::vector<int> diffWaysToCompute(std::string input)
{
    std::unordered_map<std::string, std::vector<int>> dpMap;

    return diffWaysToComputeCore(input, dpMap);

}

std::vector<int> diffWaysToComputeCore(std::string input, std::unordered_map<std::string, std::vector<int>> &dpMap)
{
    std::vector<int> result;

    for(int i = 0; i < input.size(); i++)
    {
        char cur = input[i];
        if(cur == '+' || cur == '-' || cur == '*')
        {
            std::vector<int> res1, res2;
            std::string substring = input.substr(0, i);

            //检查map中是否存储了计算福substring的结果
            if(dpMap.find(substring) != dpMap.end()) {
                res1 = dpMap[substring];
            }
            else {
                res1 = diffWaysToComputeCore(substring, dpMap);
            }

            substring = input.substr(i + 1);
            if(dpMap.find(substring) != dpMap.end()) {
                res2 = dpMap[substring];
            }
            else {
                res2 = diffWaysToComputeCore(substring, dpMap);
            }

            for(auto &n1:res1) {
                for(auto &n2:res2) {
                    if(cur == '+') {
                        result.push_back(n1 + n2);
                    }
                    else if(cur == '-') {
                        result.push_back(n1 - n2);
                    }
                    else {
                        result.push_back(n1 * n2);
                    }
                }
           }

        }

    }

    if(result.empty()) {
        result.push_back(stoi(input));
    }

    dpMap[input] = result;

    return result;

}
