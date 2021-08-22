/*

Huffman编码树

描述
构造一个具有n个外部节点的扩充二叉树，每个外部节点Ki有一个Wi对应，作为该外部节点的权。使得这个扩充二叉树的叶节点带权外部路径长度总和最小：

Min( W1 * L1 + W2 * L2 + W3 * L3 + … + Wn * Ln)

Wi:每个节点的权值。

Li:根节点到第i个外部叶子节点的距离。

编程计算最小外部路径长度总和。

输入
第一行输入一个整数n，外部节点的个数。第二行输入n个整数，代表各个外部节点的权值。

2<=N<=100

输出
输出最小外部路径长度总和。

*/

#include<iostream>
#include<cstring>
#include<queue>
#include<functional>
#include<vector>
 
using namespace std;
 
int n,ans,x;
int main()
{
	cin>>n;
	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=1;i<=n;i++)
		cin>>x,q.push(x);
	while(q.size()!=1)
	{
		int t1,t2;
		t1=q.top();q.pop();
		t2=q.top();q.pop();
		ans+=t1+t2;
		q.push(t1+t2);
	}	
	cout<<ans<<endl;
	
	return 0;
};