

//Leetcode第258题:Add Digits


//数根问题
//如果n是0,则树根就是0
//如果n是9的倍数,则树根就是n对9取余
//如果n不是9的倍数,则树根就是9

//对上面三种情况统一,就有下面的公式

int addDigits(int num)
{
    return 1 + (num-1)%9;
}
