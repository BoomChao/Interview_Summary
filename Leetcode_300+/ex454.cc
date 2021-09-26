

//Leetcode第454题:4Sum II
//4Sum的升级班

//思路:利用哈希

int fourSum(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C, std::vector<int> &D)
{
    int res = 0;
    std::unordered_map<int, int> mpAB;

    for(int a:A) {
        for(int b:B) {
            mpAB[a+b]++;
        }
    }

    for(int c:C) {
        for(int d:D) {
            res += mpAB[-c-d];
        }
    }

    return res;
}