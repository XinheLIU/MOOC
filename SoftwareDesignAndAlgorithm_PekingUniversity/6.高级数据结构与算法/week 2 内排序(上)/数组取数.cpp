/*

https://blog.csdn.net/pku_Coder/article/details/53346526 

3. 数组取数
来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
有一个整数数组A和一个目标整数T，希望从A中没有放回地取出两个数，使得两个数之差等于T。请问有多少种不同的取法？（取出的两个数分别相等时视为同一种取法）

输入
输入由两行组成。第一行为两个整型范围内的整数N和T，N为数组长度（N的范围是[2,100000]），T为目标整数。第二行为N个整数，表示数组A，每个整数的范围是[-1000000,1000000]。

输出
A中取出两个数之差为T的不同的取法的数目。

*/


#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a;
int is_happen[2000010];
int _index[100010];
int main()
{
    int n, t, ans = 0, num = 0;
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        a += 1000000;
        if(is_happen[a] == 0)
        {
            _index[num++] = a;
        }
        is_happen[a]++;
    }
    //sort(_index,_index+num);        //有num种数字
    if(t == 0)
    {
        for(int i=0;i<num;i++)
        {
            if(is_happen[_index[i]] >1)
                ans++;
        }
    }
    else if(t>0)
    {
        for(int i=0;i<num;i++)
            if(_index[i]+t<=2000009 && is_happen[_index[i]+t]!=0)
                ans++;
    }
    else
    {
        for(int i=0;i<num;i++)
            if(_index[i]+t>=0 && is_happen[_index[i]+t]!=0)
                ans++;
    }
    //printf("%d\n",num);
    printf("%d\n",ans);
    return 0;
}
