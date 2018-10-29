#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int* build_next(char* T){
	int m = strlen(T), j = 0;
	int* next = new int[m];
	int t = next[0] = -1;

	while(j < m - 1)
		if(t < 0 || next[j] == next[t])
			next[++j] = ++t;
		else t = next[t];
		
	return next;
}

int KMP(char* S, char* T){
	int* next = build_next(T);

	int n = strlen(S), i = 0;
	int m = strlen(T), j = 0;

	while(j < m && i < n)
		if(j < 0 || S[i] == T[j])
			++i, ++j;
		else j = next[j];
			
	delete [] next;
	return i - j;
}

int main()
{
	char S[] = "abcabaaabaabcac";
	char T[] = "abaabcac";

	cout << KMP(S, T) << endl;
}
