/*
 3. 文本二叉树
 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)
 
 注意：总时间限制: 1000ms 内存限制: 65536kB
 
 描述
 
 如上图，一棵每个节点都是一个字母，且字母互不相同的二叉树，可以用以下若干行文本表示:
 
 A
 -B
 --*
 --C
 -D
 --E
 ---*
 ---F
 
 在这若干行文本中：
 
 1) 每个字母代表一个节点。该字母在文本中是第几行，就称该节点的行号是几。根在第1行
 
 2) 每个字母左边的'-'字符的个数代表该结点在树中的层次（树根位于第0层）
 
 3) 若某第 i 层的非根节点在文本中位于第n行，则其父节点必然是第 i-1 层的节点中，行号小于n,且行号与n的差最小的那个
 
 4) 若某文本中位于第n行的节点(层次是i) 有两个子节点，则第n+1行就是其左子节点，右子节点是n+1行以下第一个层次为i+1的节点
 
 5) 若某第 i 层的节点在文本中位于第n行，且其没有左子节点而有右子节点，那么它的下一行就是 i+1个'-' 字符再加上一个 '*'
 
 给出一棵树的文本表示法，要求输出该数的前序、后序、中序遍历结果
 
 输入
 第一行是树的数目 n
 
 接下来是n棵树，每棵树以'0'结尾。'0'不是树的一部分
 
 每棵树不超过100个节点
 
 输出
 对每棵树，分三行先后输出其前序、后序、中序遍历结果
 
 两棵树之间以空行分隔
 
 
 解析：开始没往递归方向想，想用循环来做，发现根本没法找到上一个父节点，所以只能用递归。写程序的时候是按照给定的输入一个一个来写的条件，递归的时候返回条件一个是很明显的输入0，直接全部返回，一个是插入右子树的时候。判断是否是右子树，用c来存储有几个‘-’，k来存储是第几层就可以了。
 其实程序一遍就写对了，但是没想到在遍历的时候粗心大意忘记判断左右子树是否空了，结果改了半天递归。
 
 原文：https://blog.csdn.net/qq_26919935/article/details/77801698
 */

#include<iostream>
#include<string.h>
using namespace std;
struct node{
    char val;
    node *l,*r;
};
char a[110];
int n,c;//c是‘-’的个数
node *cur;
node *f(node *x,int k){
    if(a[0]=='0'){
        return x;
    }
    int len=strlen(a);
    c=len-1;
    if(c<k){//要插入右子树
        return x;
    }
    if(c==k&&x==NULL){
        x=new node;
        x->val=a[len-1];
        x->l=NULL;
        x->r=NULL;
        cin>>a;
        x->l=f(x->l,k+1);//递归调用返回到这里
    }
    if(c==k&&x){
        return x;//返回到父节点去调用右子树
    }
    if(c>k){//右子树的插入
        x->r=f(x->r,k+1);
    }
    return x;
}

void pre(node *x){
    if(x->val!='*')cout<<x->val;
    if(x->l!=NULL)pre(x->l);
    if(x->r!=NULL)pre(x->r);
}
void in(node *x){
    if(x->l!=NULL)in(x->l);
    if(x->val!='*')cout<<x->val;
    if(x->r!=NULL)in(x->r);
}
void out(node *x){
    if(x->l!=NULL)out(x->l);
    if(x->r!=NULL)out(x->r);
    if(x->val!='*')cout<<x->val;
}

int main(){
    cin>>n;
    while(n--){
        node *root=NULL;
        cin>>a;
        root=f(root,0);
        pre(root);
        cout<<endl;
        out(root);
        cout<<endl;
        in(root);
        cout<<endl<<endl;
    }
}

