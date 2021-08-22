/*
 编程题＃1：分配病房

 描述
 
 某个科室的病房分为重症和普通，只有当病人的疾病严重程度超过了入住重症病房的最低严重值，才可以安排入住重症病房。
 现在要求设计一个程序，给病人安排好病房。疾病的严重程度用0到10来表示，0表示小毛病，10表示非常严重。
 
 输入
 第一行输入病人的个数m(m < 50)，以及安排住入重症病房的最低严重值a
 紧接着m行，每行表示病人编号（三个位，用0补齐）及其疾病的严重程度（浮点数，1位小数）。
 每个病人的疾病严重程度都不一样。
 输出
 要求按照病人的严重程度输出住在重症病房里的病人的编号
 注意：
 如果当前所有病人的严重程度并不满足住在重症病房里，则输出“None.”（不包括引号）
 
 样例输入

 10 7.55
 006 6.5
 005 8.0
 004 3.5
 009 8.5
 011 7.0
 043 9.5
 003 5.0
 103 6.0
 112 4.0
 118 9.0
 样例输出
 043 9.5
 118 9.0
 009 8.5
 005 8.0
 
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    
    int m, seq[50], new_seq[50], nSize=0;
    float a, mark[50], new_mark[50];
    
    cin >> m >> a;
    
    for(int i=0; i < m; i++){
        cin >> *(seq+i) >> *(mark+i);     //用指针操作数组
        if(*(mark+i)>a){
            new_seq[nSize] = *(seq+i);
            new_mark[nSize] = *(mark+i);
            nSize++;
        }
    }
    
    if(nSize <= 0){
        cout << "None." << endl;
    }else{
        for(int k = 0; k < nSize; k++){
            for(int l = k; l < nSize; l++){
                if(new_mark[k] < new_mark[l]){        //排序
                    swap(new_seq[k], new_seq[l]);
                    swap(new_mark[k], new_mark[l]);
                }
            }
        }
        
        for(int j = 0; j < nSize; j++){
            cout << setfill('0') << setw(3) << new_seq[j] << ' ';     //输出
            cout << fixed;
            cout << showpoint << setprecision(1) << new_mark[j] <<endl;
        }
    }
    
    return 0;
    
}
