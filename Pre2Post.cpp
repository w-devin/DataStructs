#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

void PostOrder(char * pre, int x, int len)
{
	if(x > len) return ;
	if(x << 1 <= len) PostOrder(pre, x << 1, len);
	if(x << 1 | 1 <= len) PostOrder(pre, x << 1 | 1, len);
	
	cout << pre[x] << endl;
}

int main()
{
	char pre[] = " ABCDEFG";
	//char bleak[] = " ";
	int len = strlen(pre) - 1;
	//char P[] = strstr(bleak, pre);
	
	cout << len << endl;
	cout << pre << endl;
	
	PostOrder(pre, 1, len);
}