#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
	int a[] = {-1, 1, 1, 1, 1, 0, 1, -1};
	int n = 8;
	
	int i = 0, j = 0, k = n - 1;
	
	while(j <= k)
		switch(a[j]){
			case -1: swap(a[i], a[j]); i++; j++; break;
			case 0: j++; break;
			case 1: swap(a[j], a[k]); k--;
		}
		
		
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}