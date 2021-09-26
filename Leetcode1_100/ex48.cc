

//Leetcode第48题 : Rotate Image
//翻转矩阵,将矩阵顺时针翻转九十度


//思路:
//方法一:先将矩阵从低向上翻转,再将矩阵对称交换

//方法二:原地旋转数组,注意变换规律是第(i,j)个元素和(j,n-1-i)个元素互换位置
//但这种方法需要特别注意i,和j的取值范围
//由于i代表行号,j代表列号,i<(n+1)/2, j<n/2



void rotate_1(std::vector<std::vector<int>> &matrix)
{
    int beg = 0, end = matrix.size()-1;
    //先将矩阵从底向上翻转
    while(beg < end){     
        std::vector<int> tmp = matrix[beg];
        matrix[beg] = matrix[end];
        matrix[end] = tmp; 
        beg++;
        end--;
    }

    //再将矩阵对称交换
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = i+1; j < matrix[i].size(); j++) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

}


void rotate_2(std::vector<std::vector<int>> &matrix)
{
    int n, rows, clos;
    n = rows = clos = matrix.size();

    for(int i = 0; i < (rows+1)/2; i++){
        for(int j = 0; j < clos/2; j++){
            int v1,v2,v3,v4;            //下面很关键的一步就是依照(i,j)<->(j,n-1-i)来进行变换
            v1 = matrix[i][j];
            v2 = matrix[j][n-1-i];
            v3 = matrix[n-1-i][n-1-j];
            v4 = matrix[n-1-j][i];
            matrix[i][j] = v4;
            matrix[j][n-1-i] = v1;
            matrix[n-1-i][n-1-j] = v2;
            matrix[n-1-j][i] = v3; 
        }
    }

}



//解法三:找到变换规律即可
void rotate(std::vector<std::vector<int>> &matrix)
{
    int n = matrix.size() - 1;

    for(int i = 0; i <= n/2; i++)
    {
        for(int j = i; j < n-i; j++)        //下面这个转换关系要细心一点
        {
            int temp = matrix[j][n-i];
            matrix[j][n-i] = matrix[i][j];
            matrix[i][j] = matrix[n-j][i];
            matrix[n-j][i] = matrix[n-i][n-j];
            matrix[n-i][n-j] = temp;
        }
    }

}


//方法三(最佳解法):

void rotate(std::vector<std::vector<int>> &matrix)
{
    //顺时针旋转
    //先将给定的二维数组逆序(up to down)
    reverse(matrix.begin(), matrix.end());

    //交换
    for(int i = 0; i < matrix.size(); i++) 
    {
        for(int j = i + 1; j < matrix.size(); j++) 
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

}


//补充:如果要求逆时针旋转90度
//则将二维矩阵从左往右翻转(left to right)

void rotate(std::vector<std::vector<int>> &matrix)
{
    for(auto vec : matrix) reverse(vec.begin(), vec.end());

    //交换
    for(int i = 0; i < matrix.size(); i++) 
    {
        for(int j = i + 1; j < matrix.size(); j++)
        {
            std::swap(nums[i], nums[j]);
        }
    }

}