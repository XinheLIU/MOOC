/*编程题＃1：计算矩阵边缘元素之和
 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)
 描述
 输入一个整数矩阵，计算位于矩阵边缘的元素之和。所谓矩阵边缘的元素，就是第一行和最后一行的元素以及第一列和最后一列的元素。
 输入
 第一行为整数k，表示有k组数据。
 每组数据有多行组成，表示一个矩阵：
 第一行分别为矩阵的行数m和列数n（m < 100，n < 100），两者之间以空格分隔。
 接下来输入的m行数据中，每行包含n个整数，整数之间以空格作为间隔。
 输出
 输出对应矩阵的边缘元素和，一个一行样例输入


 2
 4 4
 1 1 1 1
 0 0 0 0
 1 0 1 0
 0 0 0 0
 3 3
 3 4 1
 3 7 1
 2 0 1
 样例输出
 5
 15
*/

#include <iostream>
using namespace std;
//计算矩阵边缘元素之和
#include <iostream>
using namespace std;
//计算矩阵边缘元素之和
int main(){
    int nSize;
    cin >> nSize;
    int m, n;
    int sum[101]={0};
    
    for(int i = 0; i < nSize; i++){
        cin >> m >> n;
        int matrix[100][100];
        for(int j = 0; j < m; j++){
            for(int k = 0; k < n; k++){
                cin >> matrix[j][k];
            }
        }
        for(int j = 0; j < m; j++){
               sum[i]=sum[i] + **(matrix+j);   //sum[i]=sum[i]+matrix[j][0];
            if(n > 1){
               sum[i]=sum[i] + *(*(matrix + j) + n - 1);    //sum[i]=sum[i]+matrix[j][n-1];
            }
        }
        for(int j = 1; j < n-1; j++){
            sum[i]=sum[i] + *(*matrix + j);
            if(m > 1){
                sum[i]=sum[i] + *(*(matrix + m - 1) + j);
            }
        }
    }
    for(int i = 0; i < nSize; i++){
        cout << sum[i] <<endl;
    }
}

