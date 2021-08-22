/*
 描述
 在情报传递过程中，为了防止情报被截获，往往需要对情报用一定的方式加密，简单的加密算法虽然不足以完全避免情报被破译，但仍然能防止情报被轻易的识别。我们给出一种最简的的加密方法，对给定的一个字符串，把其中从a-y,A-Y的字母用其后继字母替代，把z和Z用a和A替代，则可得到一个简单的加密字符串。
 
 输入
 第一行是字符串的数目n。
 
 其余n行每行一个字符串。
 
 输出
 输出每行字符串的加密字符串。
 
 */

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    string a;
    int n;
    cin>>n;
    getchar();
    while(n--)
    {
        getline(cin,a);
        for(int i=0;i<a.length();i++)
        {
            if(a[i]>='a'&&a[i]<='y')
                a[i]++;
            else if(a[i]>='A'&&a[i]<='Y')
                a[i]++;
            else if(a[i]=='z')
                a[i]='a';
            else if(a[i]=='Z')
                a[i]='A';
        }
        for(int i=0;i<a.length();i++)
            cout<<a[i];
        cout<<endl;
    }
    
    return 0;
}
