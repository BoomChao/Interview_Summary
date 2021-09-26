

//Leetcode第223题:Rectangle Area
//计算两个矩形区域的面积和

//这题主要分为矩形相交或者不相交两种情况来考虑

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int s1 = (C-A)*(D-B);
    int s2 = (G-E)*(H-F);

    //如果两个矩形没有相交的部分,则直接返回两个面积和
    if(A >= G || C <= E || D <= F || B >= H) {
        return s1+s2;
    }

    //否则两个面积和再减去相交部分的面积
    return s1-(std::min(G,C)-std::max(A,E))*(std::min(D,H)-std::max(B,F))+s2;

}