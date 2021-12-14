

//1.实现赋值运算符函数

class CMyString
{
public:
    CMyString(char *pData = nullptr);
    CMyString(const CMyString &str);
    ~CMyString();

private:
    char *m_pData;

};

//第一种解法
CMyString& CMyString::operator=(const CMyString &str)
{
    if(this != &str)
    {
        delete[] m_pData;
        m_pData = nullptr;

        m_pData = new char[strlen(str) + 1];    //存在一个隐患，如果分配内存失败,则是会抛出异常的
        strcpy(m_pData, str.m_pData);          //则m_pData是一个空指针,这样非常容易导致程序崩溃
    }                                          //也即CMyString的实例也不存在了,在申请内存之前释放掉了

    return *this;
}

//第二种写法:考虑线程安全
CMyString& CMyString::operator=(const CMyString &str)
{
    if(this != &str)
    {
        CMyString strTmp(str);      //先申请一个临时对象申请够足够的内存,如果程序崩溃了原对象还存在

        char *pTmp = strTmp.m_pData;
        strTmp.m_pData = m_pData;   //strTmp的m_pData指向的是实例之前的内存,所以相当于自动调用析构函数释放内存
        m_pData = pTmp;
    }

    return *this;
}