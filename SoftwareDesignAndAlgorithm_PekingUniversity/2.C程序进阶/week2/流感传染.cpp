//编程题＃6：流感传染
//注意： 总时间限制: 1000ms 内存限制: 65536kB

//描述 有一批易感人群住在网格状的宿舍区内，宿舍区为n*n的矩阵，每个格点为一个房间，房间里可能住人，也可能空着。在第一天，有些房间里的人得了流感，以后每天，得流感的人会使其邻居传染上流感，（已经得病的不变），空房间不会传染。请输出第m天得流感的人数。

//输入 第一行一个数字n，n不超过100，表示有n*n的宿舍房间。接下来的n行，每行n个字符，’.’表示第一天该房间住着健康的人，’#’表示该房间空着，’@’表示第一天该房间住着得流感的人。接下来的一行是一个整数m，m不超过100.

//输出 输出第m天，得流感的人数




#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
//流感传染
int main(){
    int n, m;
    cin >> n;
    char matrix[n][n];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    
    cin >> m;
    
    for(int k = 1; k < m; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '@'){
                    if(i - 1 >= 0 && matrix[i - 1][j] =='.')
                        matrix[i - 1][j] = '*';
                    if(i + 1 < n && matrix[i + 1][j] == '.')
                        matrix[i + 1][j] = '*';
                    if(j - 1 >= 0 && matrix[i][j - 1] =='.')
                        matrix[i][j - 1] = '*';
                    if(j + 1 < n && matrix[i][j + 1] == '.')
                        matrix[i][j + 1] = '*';
                }
            }
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == '*')
                    matrix[i][j] = '@';
    }
    
    int sum = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(matrix[i][j] == '@')
                sum += 1;
    
    cout << sum << endl;
    return 0;
}