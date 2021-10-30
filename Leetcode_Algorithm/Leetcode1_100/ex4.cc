

//Leetcode第4题:Median of Two Sorted Arrays
//给出两个已经排序好的数组,返回这两个数组的中位数(注意题目要求时间复杂度为O(log(m+n)))


//下面两种解法的时间复杂度都是O(m+n)

//第一种解法,利用vector的insert函数
double findMedianSortedArrays_1(std::vector<int>&num1, std::vector<int>&num2)
{
    double res;
    std::vector<int> nums;
    nums.insert(nums.begin(), num1.begin(), num1.end());      //将两个vector插入进一个vector
    nums.insert(nums.begin(), num2.begin(), num2.end());
    sort(nums.begin(), nums.end());

    int index = nums.size()/2;
    if(nums.size()%2 == 0){
        res = double( nums[index] + nums[index-1] )/2;
    }else{
        res= (double)(nums[index]);
        
    }

    return res;

}


//第二种解法,利用vector的merge函数          无论是sort函数还是merge函数都需要包含头文件<algorithm>
double findMedianSortedArrays_2(std::vector<int>&num1, std::vector<int>&num2)
{   
    std::vector<int>nums(num1.size() + num2.size());

    merge(num1.begin(), num1.end(), num2.begin(), num2.end(), nums.begin());    //注意merge()中的参数

    int index = nums.size()/2;
    if(nums.size()%2 == 1) return nums[index];

    return double(nums[index] + nums[index-1])/2;

}


//第三种解法,比前面两种解法要好一些  时间复杂度为O((m+n)/2)
//利用归并排序,时间复杂度为O(m+n)

double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
{
    if(nums1.empty() && nums2.empty()) return 0;

    if(nums1.empty()) {
        return getResult(nums2);
    }
    else if(nums2.empty()) {
        return getResult(nums1);
    } 

    int n1 = nums1.size(), n2 = nums2.size();
    int *team = new int[n1 + n2];
    int i = 0, j = 0, teamIndex = 0;
    while(i < n1 && j < n2) {
        if(nums1[i] < nums2[j]) {
            team[teamIndex++] = nums1[i++];
        }
        else {
            team[teamIndex++] = nums2[j++];
        }
    }

    while(i < n1) {
        team[teamIndex++] = nums1[i++];
    }
    while(j < n2) {
        team[teamIndex++] = nums2[j++];
    }

    if((n1 + n2) & 1) {
        return team[(n1+n2)/2];
    }
    
    return (team[(n1+n2)/2] + team[(n1+n2)/2-1])/2.0;
}


double getResult(std::vector<int> &nums)
{
    int n = nums.size();

    if(n & 1) {
        return nums[n/2];
    }

    return (nums[n/2] + nums[n/2-1])/2.0;
}




//解法四:时间复杂度为O(log(min(m,n)))

double findMedianSortedArray(std::vector<int> &nums1, std::vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();

    if(m > n) {
        return findMedianSortedArray(nums2, nums1);
    }

    int i = 0, j = 0, imin = 0, imax = m, half = (m + n + 1) / 2;
    double maxLeft = 0, minRight = 0;
    while(imin <= imax)
    {
        i = (imin + imax)/2;
        j = half - i;

        if(j > 0 && i < m && nums2[j-1] > nums1[i]) {
            imin = i + 1;
        }
        else if(i > 0 && j < n && nums1[i-1] > nums2[j]) {
            imax = i - 1;
        }
        else {
            if(i == 0) {
                maxLeft = (double)nums2[j-1];
            }
            else if(j == 0) {
                maxLeft = (double)nums1[i-1];
            }
            else {
                maxLeft = (double)std::max(nums1[i-1], nums2[j-1]);
            }

            break;
        }

    }

    if((m + n) % 2 == 1) {      //两个数组元素个数和是奇数
        return maxLeft;
    }

    if(i == m) {
        minRight = (double)nums2[j];
    }
    else if(j == n) {
        minRight = (double)nums1[i];
    }
    else {
        minRight = (double)std::min(nums1[i], nums2[j]);
    }

    return (double)(maxLeft + minRight)/2;    
}

