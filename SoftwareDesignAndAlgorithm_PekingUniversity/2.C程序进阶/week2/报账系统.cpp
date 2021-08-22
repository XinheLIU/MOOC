//
//描述有一个小型的报账系统，它有如下功能：1）统计每个人所报发票的总钱数（2）统计每类发票的总钱数
//将此系统简化为如下：假设发票类别共有A、B、C三种;一共有三个人，ID分别为1、2、3。

//输入系统输入包含三行，每行第一个数为人员ID（整型，1或2或3），第二个数为发票总张数(张数不超过100)，之后是多个发票类别（字符型，A或B或C）和相应发票金额（单进度浮点型,不超过1000.0）。

//输出输出包含六行，前三行为每人（按ID由小到大输出）所报发票总钱数（保留两位小数），后三行为每类发票的总钱数（保留两位小数）。

//样例输入1 5 A 1.0 A 2.0 C 1.0 B 1.0 C 1
//3 3 B 1 C 2 C 1
//2 4 B 1 A 1 C 1 A 1

//样例输出
//1 6.00
//2 4.00
//3 4.00
//A 5.00
//B 3.00
//C 6.00


#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int id[3], pages[3];
    char type[3][100];
    float money[3][100], money1=0.00, money2=0, money3=0, moneyA=0, moneyB=0, moneyC=0;
    
    for(int i = 0; i < 3; i++){
        cin >> id[i] >> pages[i];
        for(int  j = 0; j < pages[i]; j++){
            cin >> type[i][j] >> money[i][j];
        }
    }
    
    for(int i = 0; i < 3; i++){
        for(int  j = 0; j < pages[i]; j++){
            
            if(id[i] == 1){
                money1 += money[i][j];
            }else if(id[i] == 2){
                money2 += money[i][j];
            }else if(id[i] == 3){
                money3 += money[i][j];
            }
            
            if(type[i][j] == 'A'){
                moneyA += money[i][j];
            }else if(type[i][j] == 'B'){
                moneyB += money[i][j];
            }else if(type[i][j] == 'C'){
                moneyC += money[i][j];
            }
        }
    }
    
    printf("1 %.2f\n", money1);
    printf("2 %.2f\n", money2);
    printf("3 %.2f\n", money3);
    printf("A %.2f\n", moneyA);
    printf("B %.2f\n", moneyB);
    printf("C %.2f\n", moneyC);
    
    return 0;
}

