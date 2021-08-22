#include <iostream>
#include <string>
using namespace std;

int* findNext(string P){
    int j, k;
    int m = int(P.length());
    assert( m > 0);
    int *next = new int[m];
    next[0] = -1;
    j=0; k=-1;
    while (j < m-1) {
        while (k >= 0 && P[k] != P[j])
            k = next[k];
        j++;   k++;  next[j] = k;
    }
    return next;
}

int KMPStrMatching(string T, string P, int *N, int start) {
    int j= 0;
    int i = start;
    int pLen = int(P.length( ));
    int tLen = int(T.length( ));
    if (tLen - start < pLen)
        return (-1);
    while(j<pLen && i<tLen) {
        if ( j == -1  ||  T[i] == P[j])
        {
            i++; j++;
        }
        else j = N[j];
    }
    if (j >= pLen)
        return (i-pLen);
    else return (-1);
}
// Program to implement KMP Algorithm in C++
int main()
{
    string text = "ABABABACC";
    string pattern = "ABAC";
    int *next;
    next = findNext(pattern);
    for(int i=0;i<4;++i)
        cout << next[i];
    int x = 0;
    x = KMPStrMatching(text, pattern, next, 0);
    return 0;
}
