

/*
    面试题5:替换空格
*/
//这题如果用C语言有难度,但是用C++写很简单

//注意:需要询问面试官是在原来的字符串上进行替换还是可以创建新的字符串来进行替换
//1.如果是在原来的字符串上进行替换,则需要保证原来的字符串后面有足够多的内存
//2.如果可以创建新的字符串并在新的字符串上修改,那么我们可以申请足够的内存
//但是通常面试官会要求直接在原来的字符串上进行替换,不允许申请额外内存


//思路:尾插法
//length为字符数组string的总容量,并且要比string的字符串的长度大好多

//C语言写法
//时间复杂度O(n), 空间复杂度O(1)

void replaceBlank(char string[], int length)
{
    if(string == nullptr || length <= 0) return;

    //originalLength为字符串未替换空格之前的长度
    //numberOfBlank为字符串中空格的数量
    int originalLength = 0;    
    int numberOfBlank = 0;     

    int i = 0;
    while(string[i] != '\0')
    {
        ++originalLength;
        if(string[i] == ' ') {
            ++numberOfBlank;
        }

        ++i;
    }

    //newLength为替换空格之后字符串的长度
    int newLength = originalLength + 2*numberOfBlank;
    
    //如果替换之后的字符串的长度大于原来string数组的总容量,说明替换后的新字符串原来的数组装不下
    if(newLength > length) return;  

    //从尾部向前替换
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        //遇到空格就开始替换
        if(string[indexOfOriginal] == ' ')
        {
            string[indexOfNew--] = '0';
            string[indexOfNew--] = '2';
            string[indexOfNew--] = '%';
        }
        else
        {
            string[indexOfNew--] = string[indexOfOriginal];
        }

        --indexOfOriginal;
    }

}

//上面方法的简化:双指针

void ReplaceBlank(char *str)
{
    if(str == NULL) return ;

    int n = strlen(str);

    int numBlank = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == ' ') numBlank++;
    }

    int newLen = n + 2*numBlank;

    int i = n, j = newLen;
    
    while(i >= 0 && i < j)
    {
        if(str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        }
        else {
            str[j--] = str[i];
        }

        i--;
    }

}


//C++写法,利用string,并且使用额外内存
//时间复杂度O(n), 空间复杂度O(n)
std::string replaceBlank(const std::string str)
{
    std::string res;
    for(auto &c:str)
    {
        if(c == ' ') {
            res += "%20";
        }
        else {
            res.push_back(c);
        }
    }

    return res;
}


//C++写法,不使用额外内存
//利用自带的find和replace函数
void replaceBlank(std::string &str)
{
    int pos;

    while((pos = str.find(' ')) != str.npos) {
        str.replace(pos, 1, "%20");
    }

}




#include <iostream>

int main(){

    //需要显示指定字符串的容量
    char str[20] = "We are happy.";     //char str[] = "We are happy.";
    replaceBlank(str, 20);              //replaceBlank(str,30);    这种写法是错误的,因为不显示指定str的容量,则str的容量就只刚好容纳下现有字符串    

    std::cout << str << std::endl;

    return 0;
}