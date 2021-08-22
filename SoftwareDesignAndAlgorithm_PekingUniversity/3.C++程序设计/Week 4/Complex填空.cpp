/*描述

下面程序的输出是：

3+4i

5+6i

请补足Complex类的成员函数。不能加成员变量
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
        }
    
    Complex(){};
    
    Complex(char* s){
       r=s[0]-'0';
       i=s[2]-'0';
    };

    // 在此处补充你的代码
};
    
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
};