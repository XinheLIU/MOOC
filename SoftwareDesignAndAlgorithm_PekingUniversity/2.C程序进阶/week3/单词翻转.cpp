//编程题＃1：单词翻转
//来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)
//注意： 总时间限制: 1000ms 内存限制: 65536k 描述 输入一个句子（一行），将句子中的每一个单词翻转后输出。

//输入只有一行，为一个字符串，不超过500个字符。单词之间以空格隔开。所谓单词指的是所有不包含空格的连续的字符。这道题请用cin.getline输入一行后再逐个单词递归处理。
//输出翻转每一个单词后的字符串，单词之间的空格需与原文一致。
#include <iostream>
#include <stdio.h>

using namespace std;

void SwapWord(char temp[], int lenWord){
    for(int i = lenWord-1; i >= 0; i--){
        cout << temp[i];
    }
    cout << " ";
}

int main(){
    char input[501], temp[100];
    cin.get(input, 500);
    
    int lenWord = 0;
    unsigned long len = strlen(input);
    for(int i = 0; i < len; i++){
        if(input[i] != ' ' && input[i] != '\0'){
            temp[lenWord] = input[i];
            lenWord += 1;
        }else{
            SwapWord(temp, lenWord);
            lenWord = 0;
        }
    }
    SwapWord(temp, lenWord);
    
    return 0;
}
