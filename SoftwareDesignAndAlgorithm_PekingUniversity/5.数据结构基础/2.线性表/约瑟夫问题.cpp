/*
 描述
 有n只猴子，按顺时针方向围成一圈选大王（编号从1到n），从第1号开始报数，一直数到m，数到m的猴子退出圈外，剩下的猴子再接着从1开始报数。就这样，直到圈内只剩下一只猴子时，这个猴子就是猴王，编程求输入n，m后，输出最后猴王的编号。
 
 输入
 输入包含两个整数，第一个是n，第二个是m (0 < m,n <=300)。
 
 输出
 输出包含一行，即最后猴王的编号。
 
 */

#include <iostream>
using namespace std;

int joseph(int m, int n)
{
    if(n<=0||m<=0)
        return -1;
    int s=0;
    for(int i=2;i<=n;i++)
        s=(s+m)%i;
    return s+1;
}

int main()
{
    int m, n;
    cin >> n >> m;
    cout << joseph(m, n) << endl;
}


// Use Array
/*
 
 
 
 */

//Use Linked List( Jave )

/*
 credit to jc3939
 
 #include<iostream>
 using namespace std;
 
 //一共最多有300只猴子
 int succedent[300]; //这个数组用于保存一个猴子后一位是谁，
 //比如“next[5]的值是7”就是说5号猴子的下一位是7号猴子，6号猴子已经在之前退出了。
 int precedent[300];//这个数组用于保存一个猴子前一位是谁，用法和上面的类似。
 
 int main() {
 int n, m;
 while (true) {
 cin >> n >> m;
 if (n == 0 && m == 0)
 break;
 for (int i = 0; i < n - 1; i++) {
 succedent[i] = i + 1;
 precedent[i + 1] = i;
 }
 succedent[n - 1] = 0;
 precedent[0] = n - 1;
 
 int current = 0;
 while (true) {
 //如果一共要报m次号，那么取m-1次succedent之后就是需要退出的那只猴子
 for (int count = 0; count < m-1; count++)
 current = succedent[current];
 
 int pre = precedent[current];
 int suc = succedent[current];
 //让current号猴子退出很简单，就是把前一位的“下一位”指向current的下一位，
 //下一位的“前一位”指向current的前一位就好了
 succedent[pre] = suc;
 precedent[suc] = pre;
 if (pre == suc) {
 //如果只剩下两个了，那么每个人的前位和后位就是同一个了。
 //current是退出的，那么另一个就是剩下的。
 //我们的序号是从0编号的，输出时要加一
 cout << pre+1 << endl;
 break;
 }
 current = suc;
 }
 }
 return 0;
 }

 
 
 
 // Linked List
  from https://blog.csdn.net/wliu0828/article/details/40042447
 /*
 using namespace std;
 
 struct monkey
 {
 int num;
 monkey *next;
 };
 
 int joseph(int sum, int cycle)
 {
 int i;
 monkey *p_old, *p_new, *head=NULL;
 
 head = new monkey;
 //此处创建一个循环链表(create a circular chained table)
 head->num = 1;
 p_old = head;
 for(i=2; i<=sum; i++)
 {
 p_new = new monkey;
 p_new->num = i;
 
 p_old->next = p_new;
 p_old = p_new;
 }
 
 p_old->next = head; //把尾巴链接到 head
 
 p_old = head;
 i = 1;
 //循环删除元素直到只剩下最后一个元素(delete elements circularly until the last element left)
 while(1)
 {
 p_new = p_old->next;
 i++;
 
 if ( p_old->num == p_new->num) //or if (sum == 1)
 break;
 if((i % cycle) == 0)
 {
 p_old->next = p_new->next;
 p_old = p_old->next;
 //          sum--;
 delete p_new;
 i = 1;
 }
 else
 {
 p_old = p_new;
 }
 }
 
 return p_new->num;
 }
 
 int main(void)
 {
 int n,m;
 cout<<"How many monkeys are there? input the number(n): ";
 cin>>n;
 
 cout<<"What's the numebr you wanna call? input(m): ";
 cin>>m;
 
 cout<<"In this circumstance, the monkey king is the No.";
 cout << joseph(n,m)<<endl;
 return 0;
 }
 ---------------------
 作者：丢丢小老鼠
 来源：CSDN
 原文：https://blog.csdn.net/wliu0828/article/details/40042447
 版权声明：本文为博主原创文章，转载请附上博文链接！
 
 
 */
