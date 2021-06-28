#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n) {
        long long ans = 0, times, L = 1;
        while (L <= n) {
            times = n / L;
            long long R = n / times;
            ans += times * ((L + R) * (R - L + 1) / 2);
            L = R + 1;
        }
        cout << ans - 1 << endl;
    }

    return 0;
}