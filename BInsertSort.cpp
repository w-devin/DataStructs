#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

void BInsertSort(int A[], int n)
{
	int i, j, low, high, mid;
	for (i = 2; i <= n; i++)
	{
		A[0] = A[i];
		low = 1, high = i - 1;
		while(low > 0 && low <= high){
			mid = (low + high) / 2;
			if(A[mid] > A[0])
			
				high = mid;
			else low = mid; 
			
			if (low == high) break;
		}
		for(j = i - 1; j >= high; --j)
			A[j + 1] = A[j];
		A[high] = A[0];
		
		cout << "high = " << high << endl;
		for (int t = 0; t <= n; t++)
			cout << A[t] << " ";
		cout << endl;
	}
}

int A[] = {0, 14, 2, 43, 6, 2, 3, 2};
int n = 7;

int main()
{
	BInsertSort(A, n);
	
	for(int i = 1; i <= n; i++)
		cout << A[i] << " ";
	cout << endl;
}