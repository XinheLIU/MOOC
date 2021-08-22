#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int t;
	int n, i, j;
	int data[31];
	cin>>t;
	while (t--)
	{
		cin>>n>>i>>j;

		for (int ii = 0; ii < 31; ++ii)
		{
			data[ii] = 0;
		}
		data[j] = 1 - ((n & (1<<j)) >> j);
		data[i] = (n & (1<<i))>>i;

		for (int ii = i + 1; ii < j; ++ii)
		{
			data[ii] = 1;
		}

		int result = 0;
		for (int ii = 30; ii >= 0; --ii)
		{
			result = result*2 + data[ii];
		}

		printf("%x\n", result);
	}
}