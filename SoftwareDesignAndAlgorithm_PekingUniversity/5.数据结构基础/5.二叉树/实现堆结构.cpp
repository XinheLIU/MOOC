/* 2. 实现堆结构
来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意：总时间限制: 3000ms 内存限制: 65535kB

描述
定义一个数组，初始化为空。在数组上执行两种操作：

1、增添1个元素，把1个新的元素放入数组。

2、输出并删除数组中最小的数。

使用堆结构实现上述功能的高效算法。

输入
第一行输入一个整数t，代表测试数据的组数。

对于每组测试数据，第一行输入一个整数n，代表操作的次数。

每次操作首先输入一个整数type。

当type=1，增添操作，接着输入一个整数u，代表要插入的元素。

当type=2，输出删除操作，输出并删除数组中最小的元素。

1<=n<=100000。

输出
每次删除操作输出被删除的数字。

https://blog.csdn.net/NNNNNNNNNNNNY/article/details/51866312 
*/

#include <iostream>
#include <cstdio>
#include <cstring>
long heap[100010];
long sz = 0;
void insert(long x)
{
    //插入一个新元素，先将其放置最后端，逐步向上提升
    long i = sz++;
    while(i>0)
    {
        //p为父节点
        long p = (i-1)/2;
        //如果父节点值大于x，则将新插入结点上提
        if(heap[p]>x)
        {
            heap[i]=heap[p];
            i = p;
        }
        else break;
    }
    heap[i]=x;
}
long pop()
{
    long ans = heap[0];
    printf("%ld\n",ans);
    //将末尾结点的值提上来
    long x=heap[--sz];
    //从根节点开始比对
    long i = 0;
    while(2*i+1<sz)
    {
        long left = 2*i+1;
        long right = 2*i+2;
        if(right<sz&&heap[right]<heap[left])
        {
            //注意left的变化
            left = right;
        }
        if(heap[left]>=x) break;
        heap[i] = heap[left];
        i = left;
    }
    heap[i] = x;
}
using namespace std;
int main()
{
    long t;
    cin>>t;
    while(t--)
    {
        sz = 0;
        memset(heap,0,sizeof(heap));
        long n;
        cin>>n;
        while(n--)
        {
            int type;
            long num;
            scanf("%d",&type);
            if(type==1)
            {
                scanf("%ld",&num);
                insert(num);
            }
            else
            {
                pop();
            }
        }
        
    }
}

