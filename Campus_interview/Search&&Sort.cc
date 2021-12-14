
/*
*
*   查找和排序
*
*/

/*
    递归实现二分查找
*/

int findNum(std::vector<int> &nums, int left, int right, int target)
{
    if(left > right) return -1;

    int mid = left + ((right-left) >> 1);
    if(nums[mid] < target) {
        return findNum(nums, mid + 1, right, target);
    }
    else if(nums[mid] > target) {
        return findNum(nums, left, mid - 1, target);
    }

    return mid;
}




//冒泡排序
//思想:由下往上,两两比较,将最小的数冒泡到最上面(也就是数组的首部)

//时间复杂度最好为O(n),这时数组是顺序的,只需要做(n-1)比较
//最差为O(n^2),这时数组恰好为逆序的
//平均就是O(n^2)

void bubbleSort(std::vector<int> &nums)
{
    bool flag = true;

    for(int i = 0; i < nums.size() && flag; i++)
    {
        flag = false;
        for(int j = nums.size() - 2; j >= i; j--)
        {
            if(nums[j] > nums[j+1]) {
                std::swap(nums[j], nums[j+1]);
                flag = true;
            }
        }
    }

}



//选择排序
//思想:每一趟依次找到最小的元素与首部元素进行交换

//时间复杂度:最好最差和平均都是O(n^2),因为无论数据是否有序,比较的次数都是一样多

void selectSort(std::vector<int> &nums)
{
    for(int i = 0; i < nums.size(); i++)
    {
        int min = i;
        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[min] > nums[j]) {
                min = j;
            }
        }

        if(i != min) {
            std::swap(nums[i], nums[min]);
        }
    }

}



// 插入排序
// 思想:将一个新的元素插入到已经排好序的序列中

// 时间复杂度:最好为O(n),此时数组本身是有序的,只需(n-1)比较
// 最差情况O(n^2),此时数组恰好是倒序的
// 平均情况为O(n^2)

void insertSort(std::vector<int> &nums)
{
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] < nums[i-1]) 
        {
            int tmp = nums[i];
            int j = i-1;
            for(; nums[j] > tmp && j >= 0; j--) {
                nums[j+1] = nums[j];
            }
            nums[j+1] = tmp;
        }
    }

}



//希尔排序
//思想:引入了一个增量,将相隔某个"增量"的记录组成一个子序列,实现跳跃式的移动,从而使得排序效率更高
//注意:增量序列的最后一个增量必须是1才行

//时间复杂度:最好为O(n^1.3)
//最差为O(n^2)
//注意:希尔排序的增量的选取对算法时间复杂度很重要

void shellSort(std::vector<int> &nums)
{
    int gap = nums.size();
    
    do {
        gap = gap/3 + 1;

        for(int i = gap; i < nums.size(); i++)  //注意:这里下标从0开始,所以i=gap,不是书中的gap+1
        {
            if(nums[i] < nums[i-gap]) 
            {
                int tmp = nums[i];
                int j = i-gap;
                for(; nums[j] > tmp && j >= 0; j -= gap) {
                    nums[j+gap] = nums[j];
                }
                nums[j+gap] = tmp;
            }
        }

    } while(gap > 1);

}


//上面使用了do~while循环,这里直接使用while循环
void shellSort(std::vector<int> &nums)
{
    int gap = nums.size();

    while(gap >= 1)
    {
        gap = gap/3 + 1;

        for(int i = gap; i < nums.size(); i++)
        {
            if(nums[i] < nums[i-gap]) 
            {
                int tmp = nums[i];
                int j = i - gap;
                for(; nums[j] > tmp && j >= 0; j -= gap) {
                    nums[j+gap] = nums[j];
                }
                nums[j+gap] = tmp;
            }
        }

        if(gap == 1) break;     //避免死循环,当跨度等于1直接跳出
    }

}




//堆排序
//思想:将所有数据构造成一个大顶堆或者小顶堆

//时间复杂度:可以看出堆排序对原始记录的状态并不敏感,所以最好最差和平均复杂度都为O(nlogn)
//新建一个堆是针对非终端节点(非叶子节点)的,对于每个非终端节点来说,最多比较两次,所以时间复杂度为O(n)
//在正式排序时,取堆顶和重建堆的时间复杂度为O(nlogn)
//所以总的时间复杂度为O(n+nlogn)

void heapSort(std::vector<int> &nums)
{
    int len = nums.size() - 1;

    for(int i = len/2; i >= 1; i--) {   //建成大顶堆(前面添加的第0个元素不要管,是设置的为了让其下标构成二叉树所做的)         
        heapAdjust(nums, i, len);
    }

    for(int i = len; i > 1; i--) {
        std::swap(nums[1], nums[i]);   //将堆顶记录和当前未排序的子序列的最后一个记录交换
        heapAdjust(nums, 1, i-1);      //将剩下的元素重新调整成大顶堆
    }

}

void heapAdjust(std::vector<int> &nums, int start, int end)
{
    int tmp = nums[start];
    
    for(int j = 2*start; j <= end; j *= 2)
    {
        if(j < end && nums[j] < nums[j+1]) j++;

        if(tmp > nums[j]) break;

        nums[start] = nums[j];

        start = j;
    }

    nums[start] = tmp;
}



//归并排序(二路归并)
//时间复杂度最好最差平均情况均为O(nlogn);
//一趟归并需要把拆分开的子序列都遍历一遍,这需要O(n)时间,由完全二叉树的深度知整个归并排序需要logn次
//所以总的时间复杂度为O(nlogn)

//由于归并排序在原始过程中需要与原始序列同样数量的存储空间存放归并好的结果以及递归深度为logn的栈空间
//因此空间复杂度为O(n+logn)

void mergeSort(std::vector<int> &nums, int left, int right)
{
    if(left < right)
    {
        int mid = left + ((right-left) >> 1);
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

}

void merge(std::vector<int> &nums, int left, int mid, int right)
{
    int lindex = left, rindex = mid + 1;
    int *team = new int[right-left+1];
    int teamIndex = 0;

    while(lindex <= mid && rindex <= right)
    {
        if(nums[lindex] < nums[rindex]) {
            team[teamIndex++] = nums[lindex++];
        }
        else {
            team[teamIndex++] = nums[rindex++];
        }
    }

    while(lindex <= mid) {
        team[teamIndex++] = nums[lindex++];
    }

    while(rindex <= right) {
        team[teamIndex++] = nums[rindex++];
    }

    for(int i = 0; i < teamIndex; i++) {
        nums[left+i] = team[i];
    }

    delete[] team;
}



//快速排序
//时间复杂度最好为O(nlogn),最差为O(n^2);空间复杂度为O(n)

void quickSort(std::vector<int> &nums, int left, int right)
{
    if(left < right)
    {
        int mid = partition(nums, left, right);
        quickSort(nums, left, mid - 1);
        quickSort(nums, mid + 1, right);
    }

}

int partition(std::vector<int> &nums, int left, int right)
{
    int pivot = nums[left];

    while(left < right)
    {
        while(left < right && nums[right] >= pivot) right--;
        std::swap(nums[left], nums[right]);

        while(left < right && nums[left] <= pivot) left++;
        std::swap(nums[left], nums[right]);
    }

    return left;
}

//快排优化

int partition(std::vector<int> &nums, int left, int right)
{
    int mid = left + ((right - left) >> 1);

    //三数取中
    if(nums[left] > nums[right]) std::swap(nums[left], nums[right]);    //保证right最大
    if(nums[mid] > nums[right]) std::swap(nums[mid], nums[right]);
    if(nums[left] < nums[mid]) std::swap(nums[left], nums[mid]);    //保证mid最小

    int pivotkey = nums[left];

    while(left < right)
    {
        while(left < right && nums[right] >= pivotkey) right--;
        nums[left] = nums[right];                               //使用替换而不是交换

        while(left < right && nums[left] <= pivotkey) left++;
        nums[right] = nums[left];
    }

    nums[left] = pivotkey;

    return left;
}


//桶排序: 将待排序序列划分多个范围相同的区间,每个子区间自排序,最后合并
//桶排序是计数排序的扩展版本,计数排序可以看成每个桶只存储相同的元素,而桶排序每个桶存储一定范围的元素,
//通过映射函数,将待排序数组中的元素映射到各个对应的桶中,对每个桶中的元素进行排序,最后将非空桶中的元素放入到原序列中
//桶排序应该尽可能保证元素分散均匀,否则当所有数据集中在一个桶中时,桶排序失效

//时间复杂度:对于待排序序列为N,共分为M个桶
//N次循环,每个元素装入到对应的桶中
//M次循环,对每个桶中的元素进行排序(每个桶N/M个元素)

//时间复杂度度: O(N) + O(M*(N/M*log(N/M))) = O(N) + O(Nlog(N/M))
//当 N = M 时,时间复杂度为 O(N)

//空间复杂度 O(N + M) M个桶以及N个数据

void bucketSort(std::vector<int> &nums)
{
    int maxVal = INT_MIN, minVal = INT_MAX;

    for(const int &n : nums) {
        maxVal = std::max(maxVal, n);
        minVal = std::min(minVal, n);
    }

    //计算桶的数量
    int bucketNum = (maxVal - minVal)/nums.size() + 1;  //桶的数量向上取整，每个桶里存放nums.size()个元素
    //第一个桶的元素范围为 [minVal, minVal+n-1];    //n为数组的长度

    std::vector<std::vector<int>> buckets(bucketNum, std::vector<int>());

    //每个元素放入桶
    for(int i = 0; i < nums.size(); i++) {
        int num = (nums[i] - minVal)/nums.size();
        buckets[num].push_back(nums[i]);
    }

    //对每个桶进行排序
    for(int i = 0; i < bucketNum; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    //下面的这部分代码可以直接放在上面的循环,每个桶排好序后就直接插入

    //将桶中的元素赋值到原序列
    int index = 0;
    for(int i = 0; i < bucketNum; i++) {
        for(int j = 0; j < buckets[i].size(); j++) {
            nums[index++] = buckets[i][j];
        }
    }

}


//Leetcode第164题:利用桶排序

int maximumGap(std::vector<int> &nums)
{
    if(nums.size() < 2) return 0;

    int minVal = INT_MAX, maxVal = INT_MIN;
    for(const int &n : nums) {
        minVal = std::min(minVal, n);
        maxVal = std::max(maxVal, n);
    }

    int n = nums.size();
    int bucketNum = (maxVal - minVal)/n + 1;

    if(maxVal == minVal) return 0;  //表明所有元素都相等

    //记录桶中是否存在元素以及桶中每个元素的最大和最小值
    std::vector<int> hasNum(bucketNum, 0);
    std::vector<int> mins(bucketNum), maxs(bucketNum);    

    for(int i = 0; i < n; i++)
    {
        //计算桶编号
        int num = (nums[i] - minVal)/n;
        mins[num] = hasNum[num] ? std::min(mins[num], nums[i]) : nums[i];
        maxs[num] = hasNum[num] ? std::max(maxs[num], nums[i]) : nums[i];
        hasNum[num] = 1;
    }

    //计算前一个桶的最大值和后一个桶的最小值之差就是最大的diff.不用管桶内数据,因为桶内的数据差肯定要比桶外的数据差小
    int diff = maxs[0] - mins[0];   //防止只有一个桶
    int preMax = maxs[0];
    for(int i = 1; i < bucketNum; i++) {
        if(hasNum[i]) {
            diff = std::max(diff, mins[i] - preMax);
            preMax = maxs[i];
        }
    }

    return diff;
}



// 计数排序 : 计数排序是一种非基于比较的排序,它的优势在于对一定范围内的整数排序时,它的时间复杂度为O(n+k)(k是整数的范围),快于任何比较排序算法
// 其牺牲空间换时间,需要额外的空间存储每个数出现的次数
// 计数排序是稳定的排序算法
// <剑指>面试题11

void sortAges(std::vector<int> &ages)
{
    int n = ages.size();

    std::vector<int> timesOfAge(100, 0);

    for(int i = 0; i < n; i++) {
        timesOfAge[ages[i]]++;
    }

    int index = 0;
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < timesOfAge[i]; j++) {
            ages[index++] = i;
        }
    }

}


//计算逆序对(归并排序) <剑指>面试题51

int reversePairs(std::vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}

int mergeSort(std::vector<int> &nums, int left, int right)
{
    if(left >= right) return 0;

    int mid = left + ((right - left) >> 1);

    int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);

    std::vector<int> tmp(right - left + 1);
    int index = 0;

    int lindex = left, rindex = mid + 1;

    while(lindex <= mid && rindex <= right)     //这和剑指上的思路不同,这是从左往右合并判断
    {
        if(nums[lindex] <= nums[rindex]) {      //注意:这是小于等于
            count += rindex - (mid + 1);
            tmp[index++] = nums[lindex++];
        }
        else {
            tmp[index++] = nums[rindex++];
        }
    }

    while(lindex <= mid) {
        count += rindex - (mid + 1);
        tmp[index++] = nums[lindex++];
    }

    while(rindex <= right) {
        tmp[index++] = nums[rindex++];
    }

    for(int i = 0; i < index; i++) {
        nums[left + i] = tmp[i];
    }    

    return count;
}



int mergeSort(std::vector<int> &nums, int left, int right)
{
    if(left >= right) return 0;

    int mid = left + ((right - left) >> 1);

    int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);

    std::vector<int> tmp(right - left + 1);
    int index = right - left;

    int lindex = mid, rindex = right;

    while(lindex >= left && rindex >= mid + 1)
    {
        if(nums[lindex] > nums[rindex]) {       //从右往左合并并判断,但这里不能使用'='
            count += rindex - mid;
            tmp[index--] = nums[lindex--];
        }
        else {
            tmp[index--] = nums[rindex--];
        }
    }

    while(lindex >= left) {
        tmp[index--] = nums[lindex--];
    }

    while(rindex >= mid + 1) {
        tmo[index--] = nums[rindex--];
    }

    for(int i = 0; i < tmp.size(); i++) {
        nums[left+i] = tmp[i];
    }

    return count;
}



//Leetcode第315题 : 返回逆序个数数组

void mergeSort(std::vector<std::pair<int,int>> &v, std::vector<int> &count, int left, int right)
{
    if(left >= right) return;

    int mid = left + ((right - left) >> 1);

    mergeSort(v, count, left, mid);
    mergeSort(v, count, mid + 1, right);

    int i = left, j = mid + 1;
    std::vector<std::pair<int,int>> tmp(right - left + 1);
    int k = 0;

    while(i <= mid && j <= right)
    {
        if(v[i].first <= v[j].first) {
            count[v[i].second] += j - (mid + 1);
            tmp[k++] = v[i++];
        }
        else {
            tmp[k++] = v[j++];
        }
    }

    while(i <= mid) {
        count[v[i].second] += j - (mid + 1);
        tmp[k++] = v[i++];
    }

    while(j <= right) {
        tmp[k++] = v[j++];
    }

    for(int i = 0; i < tmp.size(); i++) {
        v[left+i] = tmp[i];
    }

}


std::vector<int> countSmaller(std::vector<int> &nums)
{
    std::vector<int> count(nums.size(), 0);

    std::vector<std::pair<int,int>> v;
    for(int i = 0; i < nums.size(); i++) {
        v.push_back({nums[i], i});
    }

    mergeSort(v, count, 0, nums.size() - 1);

    return count;
}
