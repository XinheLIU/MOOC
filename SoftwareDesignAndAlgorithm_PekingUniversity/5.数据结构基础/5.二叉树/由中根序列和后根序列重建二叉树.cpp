/*

1. 由中根序列和后根序列重建二叉树
来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意：总时间限制: 500ms 内存限制: 65535kB

描述

我们知道如何按照三种深度优先次序来周游一棵二叉树，来得到中根序列、前根序列和后根序列。反过来，如果给定二叉树的中根序列和后根序列，或者给定中根序列和前根序列，可以重建一二叉树。本题输入一棵二叉树的中根序列和后根序列，要求在内存中重建二叉树，最后输出这棵二叉树的前根序列。

用不同的整数来唯一标识二叉树的每一个结点，下面的二叉树


中根序列是9 5 32 67

后根序列9 32 67 5

前根序列5 9 67 32

输入
两行。第一行是二叉树的中根序列，第二行是后根序列。每个数字表示的结点之间用空格隔开。结点数字范围0～65535。暂不必考虑不合理的输入数据。

输出
一行。由输入中的中根序列和后根序列重建的二叉树的前根序列。每个数字表示的结点之间用空格隔开。

二叉树重建问题，根据后序和中序重建二叉树，大体思路：1、后序最后一个数是根 2、找到中序中刚才那个数，该数字左边的数字就是左子树上的数字，右边的数字就是右子树上的数字。3、 将后序中刚才的数字删去，再找最后一个数字，判断分别两个子树。AC代码如下，有些地方没处理好。

http://www.voidcn.com/article/p-bjkiwfjj-rt.html


*/


#include <iostream>
using namespace std;
struct node{
	int data;
	node* l;
	node* r;
};
int find(int a[],int left,int right,int x)
{
	int i;
	for(i=left;i<=right;i++)
		if(a[i]==x)
			break;
	return i;
}
int n=0;
node* createtree(int a[],int b[],int left,int right)
{
	if(left<=right&&n>0)
	{
		node* p=new node;
		p->data=b[n-1];
		p->l=NULL;
		p->r=NULL;
		int j=find(a,left,right,b[n-1]);
		if(j>right)
			return NULL;
		n--;
		p->l=createtree(a,b,left,j-1);
		p->r=createtree(a,b,j+1,right);
		if(p->l==NULL)
			p->l=createtree(a,b,left,j-1);
		if(p->r==NULL)
			p->r=createtree(a,b,left,j-1);
		return p;
	}
	return NULL;
}

void travel(node* p)
{
	static int a=0;
	if(p!=NULL)
	{
		if(a==0)
		{
			cout<<p->data;
			a=1;
		}
		else
			cout<<' '<<p->data;
		travel(p->l);
		travel(p->r);
	}
}
int main()
{
	int a[65535];
	int b[65535];
	int i=0;
	while(cin>>a[i++])
		if(cin.get()!=' ')
			break;
	int j=0;
	while(cin>>b[n++])
		if(cin.get()!=' ')
			break;
	node* root=createtree(a,b,0,i-1);
	travel(root);
	cout<<endl;
	return 0;
}
