#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n, f[51] = {1, 1};
    for (int i = 2; i < 51; i++)
        f[i] = f[i - 1] + f[i - 2];
    while (cin >> n && n)
        cout << f[n] << endl;
    return 0;
}
