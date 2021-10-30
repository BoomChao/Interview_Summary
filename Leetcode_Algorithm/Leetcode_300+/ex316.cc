

//Leetcode第316题: Remove Duplicate Letters
//删除重复的字母

//思路:将字符串中的重复的单词删除,但是字符的相对位置不能改变,而且要使得返回结果的字典序最小

//如:字符串bcabc
//重复的字母为b和c,但是是删除掉前面的b和c还是后面的b和c呢,因为要保持返回结果的字典序最小,所以只能删除前面的b和c,结果为abc

//如:字符串cbacdcbc
//重复的字符为c和b,保证返回结果的字典序最小,所以只能取a字符后面的c和b,但是由于d字母只有一个,不能改变d的相对位置,所以结果为acdb


std::string removeDuplicateLetters(std::string s)
{
    int m[256] = {0};
    int visited[256] = {0};

    std::string res = "0";

    for(char &c:s) {
        m[c]++;
    }

    for(char &ch:s) 
    {
        m[ch]--;    //出现的次数减1
        if(visited[ch]) {   //如果已经出现了就不再写入
            continue;
        }

        //如果出现比res之前写入的字符还小的字符,且这个已经写入的字符之后还会出现
        //则将之前写入的字符倒出
        while(ch < res.back() && m[res.back()])
        {
            visited[res.back()] = 0;
            res.pop_back();
        }
        
        res += ch;      //写入新的字符
        visited[ch] = 1;    //标记已经写入的字符
    }

    return res.substr(1);   //将开头的标记位0去掉

}
