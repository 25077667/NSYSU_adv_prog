#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int SIZE = 200001;
array<ll, SIZE> phi;
array<ll, SIZE> s_g;
array<ll, SIZE> ans;

inline void init_phi()
{
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= SIZE; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= SIZE; i++)
        for (int j = 2 * i; j <= SIZE; j += i)
            phi[j] -= phi[i];
}

inline void init_sg()
{
    for (int i = 2; i < SIZE; i++) {
        for (int j = 1; j * i < SIZE; j++)
            s_g[i * j] += phi[i] * j;
    }
}

// Prefix sum
inline void init_ans()
{
    for (int i = 2; i < SIZE; i++)
        ans[i] = ans[i - 1] + s_g[i];
}

int main()
{
    init_phi();
    init_sg();
    init_ans();

    int n;
    while (cin >> n && n)
        cout << ans[n] << endl;

    return 0;
}