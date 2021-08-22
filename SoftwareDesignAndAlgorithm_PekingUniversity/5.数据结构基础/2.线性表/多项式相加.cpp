/*
 
 描述
 我们经常遇到两多项式相加的情况，在这里，我们就需要用程序来模拟实现把两个多项式相加到一起。首先，我们会有两个多项式，每个多项式是独立的一行，每个多项式由系数、幂数这样的多个整数对来表示。
 
 如多项式2x20- x17+ 5x9- 7x7+ 16x5+ 10x4 + 22x2- 15
 
 对应的表达式为：2 20 -1 17 5 9 - 7 7 16 5 10 4 22 2 -15 0。
 
 为了标记每行多项式的结束，在表达式后面加上了一个幂数为负数的整数对。
 
 同时输入表达式的幂数大小顺序是随机的。
 
 我们需要做的就是把所给的两个多项式加起来
 
 */


#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        map<int,int> poly;
        int coef,pow;
        
        while(cin>>coef>>pow)
        {
            if(pow<0)
                break;
            
            if(poly.find(pow)!=poly.end())
                poly[pow]+=coef;
            else
                poly.insert(make_pair(pow,coef));
        }
        while(cin>>coef>>pow)
        {
            if(pow<0)
                break;
            if(poly.find(pow)!=poly.end())
                poly[pow]+=coef;
            else
                poly.insert(make_pair(pow,coef));
        }
        
        for(map<int,int>::reverse_iterator rit=poly.rbegin();rit!=poly.rend();++rit)
            if(rit->second!=0)
                cout<<"[ "<<rit->second<<" "<<rit->first<<" ] ";
        cout<<endl;
    }
    
    return 0;
}
