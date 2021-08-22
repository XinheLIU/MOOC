/*
 3. 前缀中的周期
 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)
 
 注意： 总时间限制: 3000ms 内存限制: 65536kB
 
 描述
 一个字符串的前缀是从第一个字符开始的连续若干个字符，例如"abaab"共有5个前缀，分别是a, ab, aba, abaa, abaab。
 
 我们希望知道一个N位字符串S的前缀是否具有循环节。换言之，对于每一个从头开始的长度为 i （i 大于1）的前缀，是否由重复出现的子串A组成，即 AAA...A （A重复出现K次,K 大于 1）。如果存在，请找出最短的循环节对应的K值（也就是这个前缀串的所有可能重复节中，最大的K值）。
 
 输入
 输入包括多组测试数据。每组测试数据包括两行。
 
 第一行包括字符串S的长度N（2 <= N <= 1 000 000）。
 
 第二行包括字符串S。
 
 输入数据以只包括一个0的行作为结尾。
 
 输出
 对于每组测试数据，第一行输出 "Test case #“ 和测试数据的编号。
 
 接下来的每一行，输出前缀长度i和重复测数K，中间用一个空格隔开。前缀长度需要升序排列。
 
 在每组测试数据的最后输出一个空行。
 
 https://blog.csdn.net/m0_37975647/article/details/77454113
 
 
 */

#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
using namespace std;
int n;
string s;
int Next[1000005];
int main()
{
    int Case=0;
    while(cin>>n&&n)
    {
        Case++;
        cin>>s;
        Next[0]=-1;
        Next[1]=0;
        for(int i=2;i<=n;++i)
        {
            int t=Next[i-1];
            while(t>=0&&s[i-1]!=s[t])
            {
                t=Next[t];
            }
            Next[i]=t+1;
        }
        
        cout<<"Test case #"<<Case<<endl;
        for(int i=2;i<=n;++i)
        {
            if(i%(i-Next[i])==0&&Next[i]!=0)
            {
                cout<<i<<" "<<i/(i-Next[i])<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
