/* 编程题＃4：扩号匹配问题

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

在某个字符串（长度不超过100）中有左括号、右括号和大小写字母；规定（与常见的算数式子一样）任何一个左括号都从内到外与在它右边且距离最近的右括号匹配。写一个程序，找到无法匹配的左括号和右括号，输出原来字符串，并在下一行标出不能匹配的括号。不能匹配的左括号用"$"标注,不能匹配的右括号用"?"标注.

输入

输入包括多组数据，每组数据一行，包含一个字符串，只包含左右括号和大小写字母，字符串长度不超过100

注意：cin.getline(str,100)最多只能输入99个字符！

输出

对每组输出数据，!!!输出两行，第一行包含原始输入字符!!!，第二行由"$","?"和空格组成，"$"和"?"表示与之对应的左括号和右括号不能匹配。

样例输入
((ABCD(x)
  )(rttyy())sss)(
样例输出
((ABCD(x)
    $$
 )(rttyy())sss)(
?            ?$
 */

#include <iostream>
#include <cstring>
using namespace std;

int match(char input[], int n){
    
    int i = 0, j = 0;
    
    if(input[n] == '$'||input[n]==' ')          //从右往左递归 左括号或空格（已经成功）则不动 递归
        return match(input, n - 1);
    
    for(i = n-1; i >= 0; i--){              //左移直到碰到没有配对的左括号
        if (input[i] == '$')
            break;
    }
    
    if(i == -1)                   //左移结束
        return 0;
    
    else{                              //检查左括号右侧的右括号，进行配对处理
        for(j = i; j <= n; j++){
            if (input[j] == '?'){
                input[i] = ' ';
                input[j] = ' ';
                break;
            }
        }
        
        if(j == n + 1)   //j 右移结束
            return 0;
        else return match(input, n);
    }
}

int main(){
    char input[101];
    char str[101];
    int i;
    
    while(cin.getline(input, 101)){
        int len = strlen(input);
        for(i = 0; i < len; i++){
            if(input[i] == '('){
                str[i] = '$';
            }else if(input[i] == ')')
                str[i] = '?';
            else str[i] = ' ';
        }
        
        str[i] = '\0';
        
        match(str, len - 1);
        
        cout <<input << endl;
        cout  << str << endl;
    }
    return 0;
}
