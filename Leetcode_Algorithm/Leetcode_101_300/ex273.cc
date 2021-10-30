

//Leetcode第273题 : Interger to English Words
//将数字转化成英文读法


//方法一:(缺点是代码太长)
//该题尤其要注意空格,有两种情况
//1.比如每三位的那一组,或许就是几百几十
//2.比如整个数或许就是几千,没有零头


std::string numberToWords(int num)
{
    std::vector<std::string> ss;
    std::string ans;

    if(num == 0) return "Zero";

    for(int i = 0; i < 4; i++)
    {
        std::string temp = check(num % 1000);
        ss.push_back(temp);
        num /= 1000;
    }

    //注意,下面这个顺序不能调换
    if(ss[3] != "") ans += ss[3] + " Billion ";
    if(ss[2] != "") ans += ss[2] + " Million ";
    if(ss[1] != "") ans += ss[1] + " Thousand ";
    if(ss[0] != "") ans += ss[0];

    if(ans[ans.size()-1] == ' ') return ans.substr(0, ans.size()-1);    //如果数字就是几千,则需要将最后一位的空格去掉

    return ans;

}

std::string check(int num)
{
    std::string temp = "";
    int onePlace = 0;       //代表个数上的数字
    int tenPlace = 0;       //代表十位上的数字
    int hundredPlace = 0;   //代表百位上的数字

    std::string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};          //前面元素用空格是因为ones[2]就代表的是"Two"
    std::string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    std::string onestens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    if(num == 0) return "";
    onePlace = num % 10;
    tenPlace = (num/10)%10;
    hundredPlace = num/100;

    if(hundredPlace > 0)
    {
        temp += (ones[hundredPlace] + " Hundred");
        if(tenPlace*10 + onePlace != 0) temp += " ";    //后面十位和个位不为空,则这里添加一个空格隔开
    }

    if(tenPlace == 1) {
        temp += onestens[onePlace];     //是十几的情况
    }
    else if(tenPlace >= 2) {
        temp += tens[tenPlace];
        if(onePlace != 0) {
            temp += " ";
            temp += ones[onePlace];
        }
    }
    else {
        temp += ones[onePlace];
    }

    return temp;

}




//方法二:(辗转相除)

std::string digits[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
std::string tens[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

std::string numberToWords(int num)
{
    if(num == 0) {
        return "Zero";
    }
    else {
        std::string res = int2String(num);
        return res.substr(1, res.size()-1);
    }

}


std::string int2String(int n)
{
    if(n >= 1000000000) {       //十亿(Billion)
        return int2String(n / 1000000000) + " Billion" + int2String(n % 1000000000);
    }
    else if(n >= 1000000) {     //百万(Mullion)
        return int2String(n / 1000000) + " Million" + int2String(n % 1000000);
    }
    else if(n >= 1000) {
        return int2String(n / 1000) + " Thousand" + int2String(n % 1000);
    }
    else if(n >= 100) {
        return int2String(n / 100) + " Hundred" + int2String(n % 100);
    }
    else if(n >= 20) {
        return " " + tens[n / 10] + int2String(n%10); 
    }
    else if(n >= 1) {
        return " " + digits[n];
    }
    else {
        return "";
    }

}
