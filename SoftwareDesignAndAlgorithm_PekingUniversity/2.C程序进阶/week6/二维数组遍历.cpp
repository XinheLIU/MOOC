/*
 编程题＃2: 二维数组右上左下遍历
 
 给定一个row行col列的整数数组array，要求从array[0][0]元素开始，按从左上到右下的对角线顺序遍历整个数组。
 输入
 
 输入的第一行上有两个整数，依次为row和col。
 
 余下有row行，每行包含col个整数，构成一个二维整数数组。
 
 （注：输入的row和col保证0 < row < 100, 0 < col < 100）
 
 输出
 
 按遍历顺序输出每个整数。每个整数占一行。
 
 样例输入
 3 4
 1 2 4 7
 3 5 8 10
 6 9 11 12
 样例输出
 1
 2
 3
 4
 5
 6
 7
 8
 9
 10
 11
 12

*/

#include <iostream>
using namespace std;
//二维数组右上左下遍历
int main(){
    int row, col;
    cin >> row >> col;
    int matrix[row][col];
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> matrix[i][j];
        }
    }
    
    int m = 0;
    for(int i = 0; i < row + col - 1; i++){
        
        if(i < col ){
            int k = 0;                        //the first number in n th coloum as a start
            int j = i;
            cout << matrix[k][j] << endl;
            
            while(k + 1 < row && j - 1 >= 0){          // 注：另一种思路 算行数，列数和不断增加/减少的数目 （分成两半）
                k += 1;
                j -= 1;
                cout << matrix[k][j] << endl;     //the other numbers, deduct colum and add row while you can
            }
            
        }else{                                  //after pass the columns, start from the second row, last number
            m += 1;
            int j = col - 1;
            cout << matrix[m][col-1] << endl;
            int k = m;
            
            while(k + 1 < row && j - 1 >= 0){      //if can out put, deduct columns and add rows
                k += 1;
                j -= 1;
                cout << matrix[k][j] << endl;
            }
        }
    }
}