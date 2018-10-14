#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
    int *n = new int[10];

    n[1] = 12;
    n[2] = 43;

    for (int i = 0; i < 10; i++)
        cout << n[i] << " ";
    cout << endl;
    
    cout << sizeof(n) << endl;
    cout << sizeof(&n) << endl;
    cout << sizeof(*n) << endl;

    delete[] n;
    system("pause");
}