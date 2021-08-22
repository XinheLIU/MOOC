/*
 编程题＃2：字符串中次数第2多的字母
 
 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)
 
 注意： 总时间限制: 1000ms 内存限制: 65536kB
 
 描述
 
 输入一串长度不超过500个符号的字符串，输出在串中出现第2多的英语字母(大小写字母认为相同)和次数（如果串中有其它符号，则忽略不考虑）。如果有多个字母的次数都是第2多，则按串中字母出现的顺序输出第1个。
 
 例 ab&dcAab&c9defgb
 
 这里，a 和 b都出现3次，c和d都出现2次，e、f 和 g 各出现1次，其中的符号&和9均忽略不考虑。因此，出现第2多的应该是 c 和 d，但是 d 开始出现的位置在 c 的前面，因此，输出为
 
 D+d:2
 
 (假定在字符串中，次数第2多的字母总存在)
 
 输入
 
 一个字符串
 
 输出
 
 大写字母+小写字母:个数
 
 样例输入
 
 ab&dcAab&c9defgb
 样例输出
 
 

 D+d:2


 */

#include<iostream>
using namespace std;
//字符串中次数第2多的字母

struct charStatus{
    char ch;
    int count;
};

int main(){
    struct charStatus s[501], max, second;
    char input[501];
    cin >> input;
    int i, j, k = 0;
    
    for(i = 0; input[i] != '\0'; i++){
        
        if((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')){
            char temp;              //assign input[i] to temp
            if(input[i] >= 'a')
                temp = input[i] - 32;
            else
                temp = input[i];
            bool found = false;
            
            for(j = 0; j < k; j++){    //if has been found before
                if(s[j].ch == temp){
                    s[j].count++;
                    found = true;
                }
            }
            if(!found){              //if not been found before
                s[k].ch = temp;
                s[k].count = 1;
                k++;
            }
        }
    }
    
    max = s[0];
    bool foundSecond = false;
    i = 0;
    
    while(!foundSecond){                      //simply found a second max num
        if(s[i].count > max.count){
            second = max;
            max = s[i];
            foundSecond = true;
        }
        else if(s[i].count < max.count){
            second = s[i];
            foundSecond = true;
        }
        i++;
    }
    
    for(i; i < k; i++){
        if(s[i].count > max.count){                     //sort the first k-1 elements to find the second
            second = max;
            max = s[i];
        }else if(s[i].count < max.count && s[i].count > second.count){
            second = s[i];
        }
    }
    
    cout << second.ch << "+" << (char)(second.ch+32) << ":" << second.count;
    return 0;
}