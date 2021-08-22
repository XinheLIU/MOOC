/*
 描述
 在这个问题中，将用英语给你一个或多个整数。你的任务是将这些数字转换成整型表示。数字范围从-999,999,999到999,999,999.下面是你的程序必须考虑的详尽的英语单词表：
 
 negative, zero, one, two, three, four,five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen,fifteen, sixteen, seventeen, eighteen, nineteen, twenty, thirty, forty, fifty,sixty, seventy, eighty, ninety, hundred, thousand, million
 
 输入
 输入包括多个样例，注意：
 
 1.负数前面有词negative
 
 2.当能用thousand的时候，将不用hundred。例如1500将写为"one thousand five hundred",而不是"fifteen hundred".
 
 输入将以一个空行结束
 
 输出
 输出将是每一个单独一行，每一个后面一个换行符
 
 http://blog.acbingo.cn/2016/05/01/coursera%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84_%E5%AD%97%E7%AC%A6%E4%B8%B2_%E8%AF%BE%E5%90%8E%E4%BD%9C%E4%B8%9A/
 
 */


#include <string>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;
map<string, long> mp;
int main()
{
    string s;
    mp["zero"] = 0;
    mp["one"] = 1;
    mp["two"] = 2;
    mp["three"] = 3;
    mp["four"] = 4;
    mp["five"] = 5;
    mp["six"] = 6;
    mp["seven"] = 7;
    mp["eight"] = 8;
    mp["nine"] = 9;
    mp["ten"] = 10;
    mp["eleven"] = 11;
    mp["twelve"] = 12;
    mp["thirteen"] = 13;
    mp["fourteen"] = 14;
    mp["fifteen"] = 15;
    mp["sixteen"] = 16;
    mp["seventeen"] = 17;
    mp["eighteen"] = 18;
    mp["nineteen"] = 19;
    mp["twenty"] = 20;
    mp["thirty"] = 30;
    mp["forty"] = 40;
    mp["fifty"] = 50;
    mp["sixty"] = 60;
    mp["seventy"] = 70;
    mp["eighty"] = 80;
    mp["ninety"] = 90;
    long ans = 0; int f = 0;
    while (getline(cin, s)) {
        if (s == "") return 0;
        stringstream ss(s);
        string t; ans = 0; f = 0;
        ss >> t;
        if (t == "negative") {
            f = 1;
            ss >> t;
        }
        long tt=0;
        do {
            
            if (t == "hundred")
            {
                tt *= 100;
            }
            else if (t == "thousand")
            {
                tt *= 1000;
                ans += tt;
                tt = 0;
            }
            else if (t == "million")
            {
                tt *= 1000000;
                ans += tt;
                tt = 0;
            }
            else
                tt += mp[t];
        } while (ss >> t);
        ans += tt;
        if (f) ans = -ans;
        cout << ans << endl;
    }
    return 0;
}
