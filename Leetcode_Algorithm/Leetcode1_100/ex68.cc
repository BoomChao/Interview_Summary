
//Leetcode第68题
//Text Justification : 文本转换


//思路:看清题意
//1.若一行有三个及多个单词:则要求转换到每一行的单词文本必须每一个单词之间只有一个间隔;且左边的空格数要大于右边的空格数
//2.若一行有连个单词:则要求两端对齐,中间用空格补齐
//3.若一行只有一个单词:则要求左对齐,右边补空格


#include <iostream>
#include <vector>

std::vector<std::string> fullJustify(std::vector<std::string> &words, int maxWidth);

int main(){
    std::vector<std::string> words = {"this", "is", "an"};

    std::vector<std::string> ans = fullJustify(words, 16);

    for(int i = 0; i < ans.size(); i++){
        std::cout << ans[i] << std::endl;
    }


    return 0;
}


std::vector<std::string> fullJustify(std::vector<std::string> &words, int maxWidth)
{
    std::vector<std::string> res;

    for(int i = 0, j; i < words.size(); i = j){
        int width = 0;
        for(j = i; j < words.size() && width+words[j].size()+j-i <= maxWidth; j++){
            width += words[j].size();
        }
        
        int space = 1, extra = 0;
        if(j-i != 1 && j != words.size()){          //这是为了防止是最后一行,因为最后一行的单词是左对齐的,使得单词间隔为1即可
            space = (maxWidth - width)/(j-i-1);     //如 words = {"what", "must", "be"};    这几个单词相加不超过16,
            extra = (maxWidth - width)%(j-i-1);     //输出结果为 "what must be"; 最后一行只需要左对齐,且每个单词有一个间隔
        }
        std::string line(words[i]);
        for(int k = i+1; k < j; k++){
            line += std::string(space, ' ');
            if(extra-- > 0){
                line += ' ';
            }
            line += words[k];
        }

        line += std::string(maxWidth-line.size(), ' ');

        res.push_back(line);

    }

    return res;


}