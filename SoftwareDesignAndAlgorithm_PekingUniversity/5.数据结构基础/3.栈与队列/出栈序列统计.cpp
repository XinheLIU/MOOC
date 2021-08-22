/*
 描述
 栈是常用的一种数据结构，有n个元素在栈顶端一侧等待进栈，栈顶端另一侧是出栈序列。你已经知道栈的操作有两种：push和pop，前者是将一个元素进栈，后者是将栈顶元素弹出。现在要使用这两种操作，由一个操作序列可以得到一系列的输出序列。请你编程求出对于给定的n，计算并输出由操作数序列1，2，…，n，经过一系列操作可能得到的输出序列总数。
 
 输入
 就一个数n(1≤n≤15)。
 
 输出
 一个数，即可能输出序列的总数目。
 
 */

#include <iostream>
using namespace std;

int counts = 0;

void dfs(int istack, int ostack) {
    if (ostack==0){
        counts++;
    }
    else if (istack==0){
        dfs(istack+1,ostack-1);
    }
    else {
        dfs(istack-1, ostack);
        dfs(istack+1, ostack-1);
    }
}

int  main()
{
    int n;
    cin >> n;
    dfs(0, n);
    cout << counts << endl;
    return 0;
}

