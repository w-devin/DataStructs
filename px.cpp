#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define MaxSize 100

double p(int n, double x){
		struct stack{
				int no;
				double val;
		}st[MaxSize];

		int top = -1, i;
		double fv1 = 1, fv2 = 2 * x;

		for (i = n; i >= 2; i--){
				top++;
				st[top].no = i;
		}

		while(top >= 0){
				st[top].val = 2 * x * fv2 - 2 * (st[top].no - 1) * fv1;
				fv1 = fv2;
				fv2 = st[top].val;
				top--;
		}
		if(n == 0)
				return fv1;
		
		return fv2;
}

double pp(int n, double x){
		if(n == 0) return 1;
		if(n == 1) return 2 * x;

		return 2 * x * pp(n - 1, x) - 2 * (n - 1) * pp(n - 2, x);
}

int main(){
		for (int i = 1; i <= 10; i++){
				cout << p(i, 3) << endl;
				cout << pp(i, 3) << endl;
		}
}
