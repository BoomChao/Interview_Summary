//Leetcode第13题
//Roman to Integer


#include <iostream>
#include <unordered_map> 

using string = std::string;


int romanToInt(std::string s);

int main(){
    std::string str = "MCMXCIV";
    std::cout << romanToInt(str) << std::endl;
    
    return 0;
}

int romanToInt(std::string s){
    std::unordered_map<char, int> m = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
    int result = 0;
    int i;
    
    for(i = 0; i < s.size()-1; i++){
        if( m[s[i]] >= m[s[i+1]] ){
            result += m[s[i]];
        }else{
            result -= m[s[i]];
        }
    }
    result += m[s[i]];

    return result;

}
