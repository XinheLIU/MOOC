/*
 编程题＃5：走出迷宫
 
 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)
 
 注意： 总时间限制: 1000ms 内存限制: 65536kB
 
 描述
 
 当你站在一个迷宫里的时候，往往会被错综复杂的道路弄得失去方向感，如果你能得到迷宫地图，事情就会变得非常简单。
 
 假设你已经得到了一个n*m的迷宫的图纸，请你找出从起点到出口的最短路。
 
 输入
 
 第一行是两个整数n和m(1 <= n,m <= 100)，表示迷宫的行数和列数。
 
 接下来n行，每行一个长为m的字符串，表示整个迷宫的布局。字符'.'表示空地，'#'表示墙，'S'表示起点,'T'表示出口。
 
 输出
 
 输出从起点到出口最少需要走的步数。(你不能起出迷宫外)
 
 样例输入
 
 3 3
 S#T
 .#.
 ...
 样例输出
6
 
 */

#include <iostream>
#include <cstring>
using namespace std;
//走出迷宫 ***** 难题！

int m, n, steps = 0;
char map[101][101];
int pass[101][101];

void route(int u, int v, int i, int j)        //startx, starty, endx, endy    and after repeat, u, v become the current location
{
    int t = pass[u][v];                    //the start is marked zero
    if(u == i && v == j){
        steps = t;
    }
    t++;                             //every one time, we need one more step
    
    if(v < m - 1 && map[u][v+1] != '#'  && pass[u][v+1] > t){        //v is not the rightest, go to right and never goes back
        pass[u][v+1] = t;
        route(u, v+1, i, j);
    }
    if(u > 0 && map[u-1][v] != '#'  && pass[u-1][v] > t){         //go upwards
        pass[u-1][v] = t;
        route(u-1, v, i, j);
    }
    if(v > 0 && map[u][v-1] != '#'  && pass[u][v-1] > t){         //go left
        pass[u][v-1] = t;
        route(u, v-1, i, j);
    }
    if(u < n - 1 && map[u+1][v] != '#' && pass[u+1][v] > t){        //go downwards
        pass[u+1][v] = t;
        route(u+1, v, i, j);
    }
}

int main(){
    int startx, starty, endx, endy;
    cin >> n >> m;
    
    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 'S'){
                startx = i;
                starty = j;
            }
            if(map[i][j] == 'T'){
                endx = i;
                endy = j;
            }
        }
    }
    
    memset(pass,1,sizeof(pass));        //every one is set to be 16843009
    
    //void *memset(void *s, int ch, size_t n);
    // 函数解释：将s中前n个字节 （typedef unsigned int size_t ）用 ch 替换并返回 s
    //memset是对每个字节赋值，而int有4字节(32位)
    pass[startx][starty] = 0;
    route(startx, starty, endx, endy);
    cout << steps << endl;
    
    return 0;
}