

/*
    给一个数组,将奇数放到奇数位,偶数放到偶数位
*/

void OddInOddEvenInEven(std::vector<int> &nums)
{
    if(nums.size() <= 1) return;

    int i = 0, j = 1;
    while(i < nums.size() && j < nums.size())
    {
        //判断nums[i]是否为偶数,如果为偶数则向前进两位到达下一个偶数位
        while(i < nums.size() && (nums[i]%2 == 0)) {
            i += 2;   
        }

        while(j < nums.size() && (nums[j]%2 == 1)) {
            j += 2;
        }
        
        if(i < nums.size() && j < nums.size()) {
            std::swap(nums[i], nums[j]);
        }
    }

}


/*
    给一个数组,数字内的每一个数组范围都是1~数组长度(n),求每个数字出现了多少次?返回一个合适的数据结构
*/
//返回数组或者map

std::vector<int> theFreqencyOfNums(std::vector<int> &nums)
{
    for(int i = 0; i < n; i++) {
        nums[(nums[i]-1)%n] += n;   //注意:这里要取余,因为前面的数会改变掉后面的数的值
    }

    for(int i = 0; i < n; i++) {
        nums[i] = (nums[i]-1)/n;
    }

    return nums;  //如果nums = {1,0,2,3}就表示1出现1次,2出现0次,3出现2次,4出现3次 
}

std::vector<int> theFreqencyOfNums(std::vector<int> &nums)
{
    std::vector<int> res(nums.size());

    for(const int &n : nums) {
        res[n-1]++;
    }

    return res;
}



/*
    计算100以内的素数和
*/

int primeSum(int n)
{
    std::vector<int> prime(n, 1);
    std::vector<int> res;

    for(int i = 2; i*i < n; i++)
    {
        if(prime[i]) 
        {
            for(int j = i*i; j < n; j += i) {
                if(prime[j]) {
                    prime[j] = 0;
                    res.push_back(j);
                }
            }
        }
    }

    if(!res.empty()) {
        return accumulate(res.begin(), res.end(), 0);
    }

    return -1;  //表示n以内没有素数
}


/*
    求出用{1,2,5}这三个数不同个数组合出的和为100的组合个数(184种)
*/

int count = 0;

int combineCount(std::vector<int> &nums, int target)
{
    dfs(nums, target, 0);

    return count;
}

void dfs(std::vector<int> &nums, int target, int pos)
{
    if(target == 0) {
        count++;
        return;
    }

    if(target < 0) return;

    for(int i = pos; i < nums.size(); i++) {
        dfs(nums, target - nums[i], i);
    }



/*
    实现一个bitmap
*/

class BitMap {
private:
    std::vector<size_t> vec;        //这是用unsigned int来模拟,用unsigned char来模拟只需要把32改成8即可
                                    //不用int来模拟的原因是int是有符号数，第一个bit位会存储的符号位
public:
    BitMap(size_t size) {           //size_t为无符号整形,不会存在负数.size为存储的元素总个数
        vec.resize(size/32 + 1);    //每个整形可以存储32个数,当size<32时,size/32=0,因此为了保证小于32的元素个数能存储,需要加1
    }

    //设置第x bit位为1
    bool set(size_t x) 
    {
        if(x/32 > vec.size()) {
            return false;
        }

        size_t index = x/32;        //找到是第几个数
        size_t num = x%32;          //找到是在vec[index]第几个bit位

        vec[index] |= (1 << num);
        return true;
    }

    bool reset(size_t x)    //将x的状态为置为0
    {
        if(x/32 > vec.size()) {
            return false;
        }

        size_t index = x/32;
        size_t num = x%32;

        vec[index] ^= (1 << num);

        return true;
    }

    int find(size_t x)  //查找x的状态并返回
    {
        if(x/32 > vec.size()) {
            return -1;
        }

        size_t index = x/32;
        size_t num = x%32;

        return (vec[index] >> num) & 1;
    }


    void clear()    //置空该位图
    {
        vec.clear();
    }
};







