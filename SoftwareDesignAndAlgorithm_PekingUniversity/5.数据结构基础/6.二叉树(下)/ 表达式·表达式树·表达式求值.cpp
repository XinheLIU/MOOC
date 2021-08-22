/*
表达式·表达式树·表达式求值
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65535kB
描述
众所周知，任何一个表达式，都可以用一棵表达式树来表示。例如，表达式a+b*c，可以表示为如下的表达式树：
   +
  / \
a   *
    / \
    b c
现在，给你一个中缀表达式，这个中缀表达式用变量来表示（不含数字），请你将这个中缀表达式用表达式二叉树的形式输出出来。
输入
输入分为三个部分。
第一部分为一行，即中缀表达式(长度不大于50)。中缀表达式可能含有小写字母代表变量（a-z），也可能含有运算符（+、-、*、/、小括号），不含有数字，也不含有空格。
第二部分为一个整数n(n < 10)，表示中缀表达式的变量数。
第三部分有n行，每行格式为C　x，C为变量的字符，x为该变量的值。
输出
输出分为三个部分，第一个部分为该表达式的逆波兰式，即该表达式树的后根遍历结果。占一行。
第二部分为表达式树的显示，如样例输出所示。如果该二叉树是一棵满二叉树，则最底部的叶子结点，分别占据横坐标的第1、3、5、7……个位置（最左边的坐标是1），然后它们的父结点的横坐标，在两个子结点的中间。如果不是满二叉树，则没有结点的地方，用空格填充（但请略去所有的行末空格）。每一行父结点与子结点中隔开一行，用斜杠（/）与反斜杠（\）来表示树的关系。/出现的横坐标位置为父结点的横坐标偏左一格，\出现的横坐标位置为父结点的横坐标偏右一格。也就是说，如果树高为m，则输出就有2m-1行。
第三部分为一个整数，表示将值代入变量之后，该中缀表达式的值。需要注意的一点是，除法代表整除运算，即舍弃小数点后的部分。同时，测试数据保证不会出现除以0的现象。
样例输入
a+b*c
3
a 2
b 7
c 5
样例输出
abc*+
   +
  / \
 a   *
    / \
    b c
37

https://blog.csdn.net/u014391294/article/details/50221977

*/

#include<iostream>
#include<cstring>
#include<stack>
#include<map>
#define MAXROW 70
#define MAXCOL 300
using namespace std;
char buf[MAXROW][MAXCOL];
map<char,int> m;
int pow(int x, int y){
	int result = 1;
	for (int i=0;i<y;++i) result*=x;
	return result;
}
struct btn{
	char data;
	struct btn * left;
	struct btn * right;
	btn(char c):data(c){
		left = NULL;
		right = NULL;
	}
};
int tree_layers(btn * root){
	int left,right;
	if (!root) return 0;
	left = tree_layers(root->left);
	right = tree_layers(root->right);
	return left>right? left+1: right+1;
}
void print_tree(btn * root, int root_x, int root_y, int space){
	int left_child, right_child;
	if (!root) return;
	buf[root_y][root_x-1] = root->data;
	if (root->left){
		buf[root_y+1][root_x-2] = '/';
		print_tree(root->left,root_x-space,root_y+2,space>>1);
	}
	if (root->right){
		buf[root_y+1][root_x] = '\\';
		print_tree(root->right,root_x+space,root_y+2,space>>1);
	}
}
int calculate(btn * root){
	if (isalpha(root->data)) return m[root->data];
	if (root->data=='+') return calculate(root->left)+calculate(root->right);
	if (root->data=='-') return calculate(root->left)-calculate(root->right);
	if (root->data=='*') return calculate(root->left)*calculate(root->right);
	if (root->data=='/') return calculate(root->left)/calculate(root->right);
}
int main(){
	char inexp[52], preexp[52], tmp;
	stack<char> s;
	cin >> inexp;
	int len = strlen(inexp), j=0, v_count, val;
	cin >> v_count;
	for (int i=0;i<v_count;++i){
		cin >> tmp >> val;
		m[tmp] = val;
	}
	for (int i=0;i<len;++i){
		if (isalpha(inexp[i])) preexp[j++] = inexp[i];
		else if (inexp[i]=='(') s.push(inexp[i]);
		else if (inexp[i]==')'){
			 while (s.top()!='('){
			 	preexp[j++] = s.top();
			 	s.pop();
			 }
			 s.pop();
		}
		else if (inexp[i]=='+'||inexp[i]=='-'){
			while (!s.empty()&&s.top()!='('){
				preexp[j++] = s.top();
				s.pop();
			}
			s.push(inexp[i]);
		}
		else{
			while (!s.empty()&&(s.top()=='*'||s.top()=='/')){
				preexp[j++] = s.top();
				s.pop();
			}
			s.push(inexp[i]);
		}
	}
	while (!s.empty()){
		preexp[j++] = s.top();
		s.pop();
	}
	preexp[j] = '\0';
	cout << preexp << endl; 
	btn * root;
	stack<btn*> s1;
	for (int i=0;i<j;++i){
		root = new btn(preexp[i]);
		if(!isalpha(preexp[i])){
			root->right = s1.top();
			s1.pop();
			root->left = s1.top();
			s1.pop();
		}
		s1.push(root);
	}
	memset(buf,' ',sizeof(buf));
	int n = tree_layers(root);
	print_tree(root,pow(2,n-1),0,pow(2,n-2));
	int effective_lines = 0;
	for (int i=0;i<MAXROW;++i){
		j = MAXCOL -1;
		while (j>=0&&buf[i][j]==' ') --j;
		if (j>-1){
			++effective_lines;
			buf[i][j+1] = '\0';
		}
		else break;
	}
	for (int i=0;i<effective_lines;++i) cout << buf[i] << endl;
	cout << calculate(root) << endl;
	return 0;
}