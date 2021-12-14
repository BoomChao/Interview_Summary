
/*
    [][][]+[][][]=[][][]
    将1-9的数字填入上式使得等式成立
*/

#include <iostream>
#include <vector>

void dfs(std::vector<int> &nums, std::vector<int> &count, int step);
int count = 0;

int main() {
    std::vector<int> nums(10);
    std::vector<int> visited(10, 0);     //这个数组用来记录哪个数被填写过

    dfs(nums, visited, 1);

    std::cout << count/2 << std::endl;

    return 0; 
}

void dfs(std::vector<int> &nums, std::vector<int> &visited, int step)
{
    if(step > 9) {
        if(nums[1]*100 + nums[2]*10 + nums[3] + nums[4]*100 + nums[5]*10 + nums[6] == nums[7]*100 + nums[8]*10 + nums[9]) {
            count++;
            printf("%d%d%d + %d%d%d = %d%d%d\n", nums[1], nums[2], nums[3], nums[4], nums[5], nums[6], nums[7], nums[8], nums[9]);
        }
        return ;
    }

    for(int i = 1; i <= 9; i++) 
    {   //i没有被填入过
        if(!visited[i]) 
        {
            nums[step] = i;
            visited[i] = 1;
        
            dfs(nums, count, step + 1);
        
            visited[i] = 0;
        }
    }

}


/*
    用C语言写一个函数，将字符串里面的空格全部删除掉,返回删除的空格数
*/

int delete_blanks(char *str)
{
    int len = strlen(str);
    int cur = 0;

    for(int i = 0; i < len; i++) {
        if(str[i] == ' ') continue;
        else str[cur++] = str[i];
    }

    //循环出来后cur的值就是删除后的字符串元素个数
    str[cur] = '\0';

    return len - cur;
}


/*
    最大重叠区间数目 (注意：是求最大重叠区间数目，不是所有重叠的区间数目)

    有一个party,一个记录仪记录下了每个人到达的时间start和离开的时间end, 也就是每个人在party的时间为 (start,end)
    已知 start = {1,2,10,5,5}, end = {4,5,12,9,12}, 代表第一个人在party的时间为(1,4), 第二个人(2,5), 第三个人(9,12)
    求出这个party同一时段内最多接纳了多少人

    思路：按照时间对start和end进行排序,之后合并
    时刻    类型    人数
    1       S       1
    2       S       2
    4       E       1
    5       S       2
    5       S       3       人数最多为3人
    5       E       2
    9       E       1
    10      S       2
    12      E       1
    12      E       1       
*/

int findMaxGuests(std::vector<int> &start, std::vector<int> &end)
{
    int n = start.size();

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i = 0, j = 0;
    int count = 0, res = 0;

    while(i < n && j < n)
    {
        if(start[i] <= end[j]) {
            count++;
            res = std::max(res, count);
            i++;
        }
        else {
            count--;
            j++;
        }
    }

    return res;
}


