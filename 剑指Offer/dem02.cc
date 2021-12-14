
//P81
//实现一个时间复杂度为O(n)的排序算法

void sortAges(int ages[], int length)
{
    if(ages == nullptr || length < 0) return;

    const int oldestAge = 99;    //年龄范围为0~99
    int timeOfAge[oldestAge+1];     //存储某个年龄出现的次数

    for(int i = 0; i <= oldestAge; i++)
    {   
        //初始化数组,每个元素赋值为0
        timeOfAge[i] = 0;                   
    }

    for(int i = 0; i < length; i++)
    {
        int age = ages[i];
        if(age < 0 || age > oldestAge) {
            std::cout << "Error:age out of range.";
            exit(1);
        }
        timeOfAge[age]++;    //timeOfAge里面存储的是每个年龄出现的次数
    }                        //如timeOfAge[1]=2,代表年龄1出现了2次; timeOfAge[4]=3,代表年龄4出现了3次
                             //有些年龄不出现,就是0,如timeOfAge[0]=0,代表年龄0出现了0次,那么排序的时候就会跳过该年龄

    int index = 0;
    for(int i = 0; i <= oldestAge; i++) 
    {
        for(int j = 0; j < timeOfAge[i]; j++) 
        {
            ages[index] = i;
            ++index;
        }
    }

}