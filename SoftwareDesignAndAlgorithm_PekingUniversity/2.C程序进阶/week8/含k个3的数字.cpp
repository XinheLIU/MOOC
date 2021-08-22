/*
 编程题＃1：含k个3的数
 
 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)
 
 注意： 总时间限制: 1000ms 内存限制: 65536kB
 
 描述
 
 输入二个正整数m 和 k，其中1 < m < 100000，1 < k <5 ，判断m 能否被19整除，且恰好含有k个3，如果满足条件，则输出YES，否则，输出NO。
 
 例如，输入：
 
 43833 3
 
 满足条件，输出YES
 
 如果输入
 
 39331 3
 
 尽管有3个3，但不能被19整除，也不满足条件，应输出NO
 
 输入
 
 m 和 k 的值，空格间隔
 
 输出
 
 满足条件时输出 YES，不满足时输出 NO


 */


#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
//含k个3的数
int NumberOfThree(int number){
    int Three = 0;
    char number_ch[100];
    /*
     int sprintf( char *buffer, const char *format, [ argument] … );
     参数列表
     buffer：char型指针，指向将要写入的字符串的缓冲区。
     format：格式化字符串。
     [argument]...：可选参数，可以是任何类型的数据。
     返回值
     返回写入buffer 的字符数，出错则返回-1. 如果 buffer 或 format 是空指针，且不出错而继续，函数将返回-1，并且 errno 会被设置为 EINVAL。
     sprintf 返回被写入buffer 的字节数，结束字符‘\0’不计入内。即，如果“Hello”被写入空间足够大的buffer后，函数sprintf 返回5。[1]
     */
    sprintf(number_ch, "%d", number);
    for(int i = 0; number_ch[i] != '\0'; i++){
        if(number_ch[i] == '3'){
            Three++;
        }
    }
    return Three;
}

int main(){
    int m, k;
    cin >> m >> k;
    
    if(m % 19 == 0){
        if(NumberOfThree(m) == k){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }else{
        cout << "NO" << endl;
    }
    
    return 0;
}