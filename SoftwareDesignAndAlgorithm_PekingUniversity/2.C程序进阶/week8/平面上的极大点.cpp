/*
 编程题＃4：寻找平面上的极大点
 
 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)
 
 注意： 总时间限制: 1000ms 内存限制: 65536kB
 
 描述
 
 在一个平面上，如果有两个点(x,y),(a,b),如果说(x,y)支配了(a,b)，这是指x>=a,y>=b;
 
 用图形来看就是(a,b)坐落在以(x,y)为右上角的一个无限的区域内。
 
 给定n个点的集合，一定存在若干个点，它们不会被集合中的任何一点所支配，这些点叫做极大值点。
 
 编程找出所有的极大点，按照x坐标由小到大，输出极大点的坐标。
 
 本题规定：n不超过100，并且不考虑点的坐标为负数的情况。
 
 输入
 
 输入包括两行，第一行是正整数n，表示是点数，第二行包含n个点的坐标，坐标值都是整数，坐标范围从0到100，输入数据中不存在坐标相同的点。
 
 输出
 
 按x轴坐标最小到大的顺序输出所有极大点。
 
 输出格式为:(x1,y1),(x2,y2),...(xk,yk)
 
 注意：输出的每个点之间有","分隔,最后一个点之后没有",",少输出和多输出都会被判错
 
 样例输入
 5
 1 2 2 2 3 1 2 3 1 4
 */

#include <iostream>
using namespace std;
//寻找平面上的极大点
int main(){
    int n, l = 0;
    cin >> n;
    int a[101][2], b[101][2];
    
    for(int i = 0; i < n; ++i)
        cin >> a[i][0] >> a[i][1];
    
    for(int i = 0; i < n; ++i){
        bool badPoint = false;
        for(int j = 0; j < n; ++j)
        {
            if(a[i][0] <= a[j][0] && a[i][1] <= a[j][1] && i != j){
                badPoint = true;
                break;
            }
        }
        if(!badPoint){
            b[l][0] = a[i][0];
            b[l][1] = a[i][1];
            l++;
        }
    }
    
    for(int i = 1; i < l; ++i){
        for (int j = 0; j < i; ++j){
            if(b[j][0]>b[i][0] || (b[j][0] == b[i][0] && b[j][1]>b[i][1])){         //排序，也可以单写sort 或者swap function
                int temp[2];
                temp[0] = b[j][0];
                temp[1] = b[j][1];
                b[j][0] = b[i][0];
                b[j][1] = b[i][1];
                b[i][0] = temp[0];
                b[i][1] = temp[1];
            }
        }
    }
    
    for(int i = 0; i < l - 1; ++i)                            //输出数组b
        cout << "(" << b[i][0] << "," << b[i][1] << "),";
    
    cout << "(" << b[l - 1][0] << "," << b[l-1][1] << ")";
    
    return 0;
}