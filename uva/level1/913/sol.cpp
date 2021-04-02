#include <bits/stdc++.h>
using namespace std;
unsigned long long sum(unsigned long long n)
{
    return (3 * (n + 1) * (n + 1) / 2) - 9;
}

int main()
{
    int n;
    while (cin >> n) {
        cout << sum(n) << endl;
    }
}
