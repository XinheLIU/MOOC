/*描述
 描述
 
 写一个二维数组类 Array2,使得下面程序的输出结果是：
 
 0,1,2,3,
 
 4,5,6,7,
 
 8,9,10,11,
 
 next
 
 0,1,2,3,
 
 4,5,6,7,
 
 8,9,10,11,
 
 程序：
  */
#include <iostream>
#include <cstring>
using namespace std;    

class Array2
{
private:
    int * p;
    int r,c;
public:
    Array2() { p = NULL ; }
    Array2( int r_, int c_  ) :r(r_),c(c_)
    {
        p = new int [ r * c];
    }
    Array2( Array2 & a ):r(a.r),c(a.c) {
        p = new int [r * c];
        memcpy( p, a.p,sizeof(int ) * r * c);
    }
    Array2 & operator=( const Array2 & a ) {
        if( p )
            delete [] p;
        r = a.r;
        c = a.c;
        p = new int [r * c];
        memcpy( p, a.p,sizeof(int ) * r * c);
        return * this;
    }
    ~Array2() {
        if( p)
            delete [] p;
    }
    int * operator [] ( int i ) {
        return p + i * c;
    }
    int & operator() ( int i,int j ) 
    {
        return p[ i * c + j];
    }
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}