

//Leetcode第168题:Excel Sheet Column Title
//Excel表格名称

std::string convertTitle(int n)
{
    std::string res = "";

    while(n > 0)
    {
        res = (char)('A' + (n-1)%26) + res;   //注意:这个类型转换char是必要的,不然会报错
        n = (n-1)/26;
    }

    return res;

}

