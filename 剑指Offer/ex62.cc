/*
    面试题62:圆圈中最后剩下的一个数字 (约瑟夫环问题)
    
*/



//使用环形链表解决

int lastRemaining(unsigned int n, unsigned int m)
{
    if(n < 1 || m < 1) return -1;

    unsigned int i = 0;
    std::list<int> numbers;
    
    for(i = 0; i < n; i++)
    {
        numbers.push_back(i);
    }

    std::list<int>::iterator current = numbers.begin();

    while(numbers.size() > 1)
    {
        for(int i = 1; i < m; i++)
        {
            current++;
            if(current == numbers.end()){
                current == numbers.begin();
            }
        }
        
        std::list<int>iterator next = current++;
        if(next == numbers.end()) {
            next = numbers.begin();
        }

        current--;
        numbers.erase(current);
        current = next;

    }

    return *current;

}




//找规律,使用迭代

int lastRemaining(unsigned int n, unsigned int m)
{
    if(n < 1 || m < 1) return -1;

    int last = 0;
    for(int i = 2; i <= n; i++)
    {
        last = (last+m)%i;
    }

    return last;

}