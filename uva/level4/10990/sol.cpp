#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
constexpr int SIZE = 2000005;
using ull = unsigned long long int;

ull phi[SIZE];
ull dephi[SIZE];

inline ull fdephi(ull n)
{
    return phi[n] == 1 ? 1 : 1 + fdephi(phi[n]);
}

inline ull SODF(ull m, ull n)
{
    ull sum = 0;
    for (int i = m; i <= n; i++)
        sum += dephi[i];
    return sum;
}

void init()
{
    phi[1] = 1;
    for (int i = 2; i < SIZE; i++)
        phi[i] = i - 1;

    for (int i = 2; i < SIZE; i++)
        for (int j = 2 * i; j < SIZE; j += i)
            phi[j] -= phi[i];

    for (ull i = 2; i < SIZE; i++)
        dephi[i] = fdephi(i);
}

int main()
{
    init();
    int n;
    cin >> n;
    while (n--) {
        ull m, n;
        cin >> m >> n;
        cout << SODF(m, n) << endl;
    }
    return 0;
}