

//面试题40 : 最小的k个数



//方法一：
//这种方法会修改输入的数组

void getLeastNumber(int *input, int n, int *output, int k)
{
    if(input == nullptr || output == nullptr || k > n || n <= 0 || k <= 0) return;

    int start = 0;
    int end = n-1;
    int index = partition(input, n, start, end);
    
    while(index != k-1){
        if(index > k-1){
            end = index -1;
            index = partition(input, n, start, end);
        
        }else{
            start = index + 1;
            index = partition(input, n, start, end);

        }
    }

    for(int i = 0; i < k; i++){
        output[i] = input[i];
    }

}


//方法二:
//该方法不会修改输入的数组

//greater函数在头文件<functional>
//set和multiset都是在<set>中,multiset中允许出现重复元素

typedef std::multiset<int, std::greater<int>> intSet;     //用来构建一个最大堆
typedef std::multiset<int, std::greater<int>> ::iterator setIterator;

void getLeastNumbers(const std::vector<int> &data, intSet &leastNumbers, int k)
{
    leastNumbers.clear();

    if(k < 1 || data.size() < k) return;

    std::vector<int>::const_iterator iter = data.begin();
    for(; iter != data.end(); iter++)
    {
        if(leastNumbers.size() < k) {
            leastNumbers.insert(*iter);
        }
        else {
            setIterator iterGreatest = leastNumbers.begin();
            if(*iter < *(leastNumbers.begin())) {
                leastNumbers.erase(iterGreatest);
                leastNumbers.insert(*iter);
            }
        }
    }

}



//附：如何求最大的k个数
//最大的k个数
void getLeastNumber_1(int *input, int n, int *output, int k)
{
    if(input == nullptr || output == nullptr || k > n || n <= 0 || k <= 0) return;

    int start = 0;
    int end = n-1;
    int index = partition(input, n, start, end);
    
    while(index != (n-k)){
        if(index > n-k){
            end = index -1;
            index = partition(input, n, start, end);
        
        }else{
            start = index + 1;
            index = partition(input, n, start, end);

        }
    }

    for(int i = 0; i < k; i++){
        output[i] = input[index++];
    }

}


