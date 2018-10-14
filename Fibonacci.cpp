#include <iostream>
using namespace std;

int twoVar(int n)
{
    if (n <= 2) return 1;

    int a = 1, b = 1;
    for (int i = 3; i <= n; ++i)
    {
        b = a + b;
        a = b - a;
    }

    return b;
}

int main()
{
    int n = 20;

    cout << twoVar(n) << endl;

    system("pause");
}