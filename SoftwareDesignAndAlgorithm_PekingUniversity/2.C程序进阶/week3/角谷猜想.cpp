//编程题＃2：角谷猜想

//来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)注意： 总时间限制: 1000ms 内存限制: 65536kB

//描述所谓角谷猜想，是指对于任意一个正整数，如果是奇数，则乘3加1，如果是偶数，则除以2，得到的结果再按照上述规则重复处理，最终总能够得到1。如，假定初始整数为5，计算过程分别为16、8、4、2、1。

//程序要求输入一个整数，将经过处理得到1的过程输出来。

//输入

//一个 正整数输出 从输入整数到1的步骤，每一步为一行，每一部中描述计算过程，假定输入为7

#include <iostream>
using namespace std;

void JGGuess(int number){
    if(number == 1){
        cout << "End" << endl;
    }else{
        if(number % 2 != 0){
            cout << number << "*3+1=" << number * 3 + 1 << endl;
            number = number * 3 + 1;
            return JGGuess(number);
        }else{
            cout << number << "/2=" << number / 2 << endl;
            number = number / 2;
            return JGGuess(number);
        }
    }
}

int main(){
    int number;
    
    cin >> number;
    JGGuess(number);
    
    return 0;
}

