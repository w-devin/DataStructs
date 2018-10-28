#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

int Binary_Search(int *A, int k)
{
	int low = 0, high = 11 - 1;
	
	while(low <= high)
	{
		cout << "low = " << low << ", high = " << high << endl;
		
		int mid = (low + high) >> 1;
		
		if(A[mid] == k)
			return mid;
		else if(A[mid] > k)
			high = mid - 1;
		else
			low = mid + 1;
	}
	
	return -1;
}

int BSearch(int *A, int l, int r, int k)
{
	cout << "l = " << l << ", r = " << r << endl;

	if (l > r) return -1;
	
	int mid = (l + r) >> 1;
	if(A[mid] == k) return mid;
	else if(A[mid] > k) return BSearch(A, l, mid - 1, k);
	else return BSearch(A, mid + 1, r, k);
}

int main()
{
	int A[] = {7, 10, 13, 16, 19, 29, 32, 33, 37, 41, 43}, n = 11 - 1;
	
	int k;
	
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
	

	cin >> k;
	cout << Binary_Search(A, k) << endl;
	cout << BSearch(A, 0, n, k) << endl;
}
