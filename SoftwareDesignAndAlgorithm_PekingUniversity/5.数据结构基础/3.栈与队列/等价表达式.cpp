/*
 描述
 判断两个表达式在数学上是否是等价的。
 
 输入
 第一行：N（1<=N<=20），表示测试数据组数。
 
 接下来每组测试数据包括两行，每行包括一个数学表达式，每个表达式的长度不超过80个字符。输入数据没有空行。
 
 一个表达式可能包括：
 
 单个英文字母表示的变量（区分大小写）
 
 数字（只有一位数）
 
 配对的括号
 
 运算符加+、减-、乘*
 
 任意数量的空格或tab（可能出现在表达式中间的任何位置）
 
 注意：表达式保证是语法正确的，且所有运算符的优先级相同，运算次序从左至右。变量的系数和指数保证不超过16位整数。
 
 输出
 对每个测试数据，输出一行：等价则输出“YES”，不等价则输出“NO”。
 
 */


#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
using namespace std;
#define MAX 100
string change(char *p) {
    string cnt;
    int len= int(strlen(p));
    stack<char>astack;
    for(int i=0; i<=len; i++) {
        if((p[i]>='0' && p[i]<='9') || (p[i]>='a' && p[i]<='z'))
            cnt+=p[i];
        else if(p[i]=='(')
            astack.push('(');
        else if(p[i]==')') {
            while(astack.top()!='(') {
                cnt+=astack.top();
                astack.pop();
            }
            astack.pop();
        }
        else if(p[i]=='+' || p[i]=='-') {
            while(!astack.empty() && astack.top()!='(') {
                cnt+=astack.top();
                astack.pop();
            }
            astack.push(p[i]);
        }
        else if(p[i]=='*') {
            while(!astack.empty() && astack.top()!='(' && astack.top()=='*') {
                cnt+=astack.top();
                astack.pop();
            }
            astack.push(p[i]);
        }
        else if(p[i] == ' ' || p[i] == '    ')
            continue;
    }
    while(!astack.empty()) {
        cnt+=astack.top();
        astack.pop();
    }
    return cnt;
}
int getsum(string num) {
    int len = int(num.length());
    stack<int>astack;
    for(int i=0; i<len; i++) {
        if(num[i]<='z' && num[i]>='a') {
            int ascii=num[i];
            astack.push(ascii);
        }
        else if(num[i]>='0' && num[i]<='9')
            astack.push((int)num[i]-'0');
        else if(num[i]=='+') {
            int n=astack.top();
            astack.pop();
            int m=astack.top();
            astack.pop();
            m+=n;
            astack.push(m);
        }
        else if(num[i]=='*') {
            int n=astack.top();
            astack.pop();
            int m=astack.top();
            astack.pop();
            n*=m;
            astack.push(n);
        }
        else if(num[i]=='-') {
            int n=astack.top();
            astack.pop();
            int m=astack.top();
            astack.pop();
            m-=n;
            astack.push(m);
        }
    }
    int result=astack.top();
    astack.pop();
    return result;
}
int main() {
    int N;
    scanf("%d", &N);
    cin.get();
    while(N--) {
        char s1[MAX], s2[MAX];
        cin.getline(s1, MAX);
        string p1=change(s1);
        int a=getsum(p1);
        cin.getline(s2, MAX);
        string p2=change(s2);
        int b=getsum(p2);
        if(a==b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}