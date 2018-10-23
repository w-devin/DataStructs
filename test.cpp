#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdio>
#include <stack>
using namespace std;

int main()
{
	stack<int> S;

	for (int i = 0; i < 10; i++)
		S.push(i);

	S.push(0);
	S.push(9);


	while(int x = S.top())
	{
		S.pop();
		cout << x << endl;
	}

	system("pause");
}


/**
 * 
 * 2018. BTree PostOrder with stack
 * 
 */

//K J I h G b a 
//K J I h G F e  | D  C  b    a
