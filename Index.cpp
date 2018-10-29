#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int Index(char *S, char *T){
		int i = 0, j = 0;
		int a = strlen(S), b = strlen(T);

		//while(i <= S[0] && j <= T[0]){
		while(i < a && j < b){
				cout << "i = " << i << ", j = " << j << endl;
				if(S[i] == T[j])
						++i, ++j;
				else i = i - j + 1, j = 0;
		}

		if(j >= b) return i - b;
		else return -1;

}

int Index_book(char *S, char *T){
		int i = 1, j = 1;

		while(i <= S[0] && j <= T[0]){
				cout << "i = " << i << ", j = " << j << endl;
				if(S[i] == T[j])
						++i, ++j;
				else i = i - j + 2, j = 1;
		}

		if(j > T[0]) return i - T[0];
		else return 0;

}

void get_next(char *T, int *next){
		int i = 1, j = 0;
		int a = strlen(T);
		next[0] = -1;

		while(i < a){
				if (j == 0 || T[i] == T[j])
					++i, ++j, next[i] = j;
				else j = next[j];
		}
}

void get_next_book(char T[], int next[]){
		int i = 1, j = 0;
		next[1] = 0;

		while(i <= T[0]){
				if (j == 0 || T[i] == T[j])
						++i, ++j, next[i] = j;
				else j = next[j];
		}
}

int KMP_book(char *S, char *T, int *next, int pos){
		int i = pos, j = 1;

		while(i <= S[0] && j <= T[0]){
				cout << "i = " << i << ", j = " << j << endl;
				if(j == 0 || S[i] == T[j])
					++i, ++j;
				else j = next[j];
		}

		if(j > T[0])
				return i - T[0];
		return 0;

}

int main()
{
		char S[] = " abcabaaabaabcac";
		char T[] = " abaabcac";
		S[0] = strlen(S);
		T[0] = strlen(T);
		int next[strlen(T)]; 
		next[0] = strlen(T);

		cout << Index_book(S, T) << endl;

		get_next_book(T, next);

		for (int i = 0; i < strlen(T); i++)
				cout << next[i] << " ";
		cout << endl;

		cout << KMP_book(S, T, next, 1) << endl;
}
