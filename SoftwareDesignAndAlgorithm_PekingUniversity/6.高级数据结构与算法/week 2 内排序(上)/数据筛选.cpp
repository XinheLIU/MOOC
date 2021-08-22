/*

http://www.voidcn.com/article/p-xggyqpsc-bbo.html

2. 数据筛选
来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 10000ms 内存限制: 3000kB

描述
小张需要从一批数量庞大的正整数中挑选出第k小的数，因为数据量太庞大，挑选起来很费劲，希望你能编程帮他进行挑选。

输入
第一行第一个是数据的个数n(10<=n<=106)，第二个是需要挑选出的数据的序号k(1<=k<=105)，n和k以空格分隔；

第二行以后是n个数据T(1<=T<=109)，数据之间以空格或者换行符分隔。

输出
第k小数（如果有相同大小的也进行排序，例如对1,2,3,8,8，第4小的为8，第5小的也为8）。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, k, input, n1, n2;
    vector<int> vec;
    cin >> n >> k;
    --k;
    n1 = n;
    n2 = n;
    for (int i = 0; i <= n/100000; ++i){
        n2 = n1 > 100000 ? 100000 : n1;
        for (int j = 0; j < n2; ++j){
            cin >> input;
            vec.push_back(input);
        }
        sort(vec.begin(), vec.end());
        vec.erase(vec.begin() + k, vec.end());
        n1 -= n2;
        if (n1 <= 0){
            cout << vec[k];
            break;
        }
    }
}
