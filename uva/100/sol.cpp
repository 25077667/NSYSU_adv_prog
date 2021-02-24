#include <cmath>
#include <iostream>

using namespace std;

int f(int n)
{
    int num = 1;
    while (n != 1) {
        if (n % 2 == 1)
            n = n * 3 + 1;
        else
            n /= 2;
        num++;
    }
    return num;
}
int main(int argc, char *argv[])
{
    int m, n, num, a, b;

    while (cin >> n >> m) {
        num = 0;
        a = n;
        b = m;

        if (n > m)
            swap(n, m);

        for (int i = n; i <= m; i++)
            num = max(num, f(i));
        cout << a << " " << b << " " << num << endl;
    }
    return 0;
}
