

//Leetcode第233题:Number of Digit 1
//寻找1~n中数字1一共出现的次数


//方法一:暴力破解
//时间复杂度O(nlogn)

int countDigitOne(unsigned int n)
{
    int number = 0;

    for(unsigned int i = 1; i <=n ;i++) {
        number += numbeOf1(i);
    }

    return number;

}

int numbeOf1(unsigned int n)
{
    int number = 0;
    while(n) 
    {
        if(n%10 == 1) {
            number++;
        }

        n = n/10;
    }

    return number;
}



//方法二:寻找数字规律
//时间复杂度为O(logn)

int countDigitOne(int n)
{
    if(n <= 0) return 0;

    std::string str = std::to_string(n);

    return countDigitOneCore(str);

}


int countDigitOneCore(const std::string &str)
{
    int first = str[0] - '0';
    unsigned int length = str.size();

    if(length == 1 && first == 0) {
        return 0;
    }

    if(length == 1 && first > 0) {
        return 1;
    }

    int numFirstDigit = 0;
    if(first > 1) {
        numFirstDigit = (int)pow(10, length-1);
    }
    else if(first == 1) {
        numFirstDigit = std::stoi(str.substr(1)) + 1;
    }

    int numOtherDigit = first*(length-1)*(int)pow(10, length-2);

    int numRecursive = countDigitOneCore(str.substr(1));    //如果前面不加const则这里会报错

    return numFirstDigit + numOtherDigit + numRecursive;

}


