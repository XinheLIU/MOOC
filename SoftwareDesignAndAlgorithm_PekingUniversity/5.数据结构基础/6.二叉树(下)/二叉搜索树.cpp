/*

注意：总时间限制: 1000ms 内存限制: 1024kB

描述
二叉搜索树在动态查表中有特别的用处，一个无序序列可以通过构造一棵二叉搜索树变成一个有序序列，构造树的过程即为对无序序列进行排序的过程。每次插入的新的结点都是二叉搜索树上新的叶子结点，在进行插入操作时，不必移动其它结点，只需改动某个结点的指针，由空变为非空即可。

这里，我们想探究二叉树的建立和序列输出。

输入
只有一行，包含若干个数字，中间用空格隔开。（数字可能会有重复）

输出
输出一行，对输入数字建立二叉搜索树后进行前序周游的结果。

https://blog.csdn.net/u014391294/article/details/50221813 

*/



#include <iostream>
using namespace std;
struct node
{
	int info;
	node *l, *r;
};
void pre(node *root)
{
	if (root)
	{
		cout << root->info << ' ';
		pre(root->l);
		pre(root->r);
	}
}
int main()
{
	int temp;
	node *root = new node,*cur,*next;
	cin >> temp;
	root->info = temp;
	root->l = NULL;
	root->r = NULL;
	while (cin >> temp)
	{
		next = root;
		cur = new node;
		cur->info = temp;
		cur->l = NULL;
		cur->r = NULL;
		while (next)
		{
			if (temp == next->info)
				break;
			if (temp < next->info)
			{
				if (next->l)
					next = next->l;
				else
				{
					next->l = cur;
					break;
				}
			}
			else
			{
				if (next->r)
					next = next->r;
				else
				{
					next->r = cur;
					break;
				}
			}
		}
	}
	pre(root);
	return 0;
}
