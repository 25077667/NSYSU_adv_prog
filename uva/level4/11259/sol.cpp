#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define DP_SIZE 100001
array<long long, DP_SIZE> dp;

void genDP(const array<pair<int, int>, 5> &cq)
{
    for (auto &i : dp)
        i = 0;
    dp[0] = 1;
    for (int i = 0; i < 4; i++)
        for (int j = cq[i].first; j <= DP_SIZE; j++)
            dp[j] += dp[j - cq[i].first];
}

long long doDP(const array<pair<int, int>, 5> &cq)
{
    long long ans = 0;
    for (int i = 0; i < (1 << 4); i++) {
        auto subset = cq[4].second;
        auto neg = 1;
        for (int j = 0; j < 4; j++)
            if (i & (1 << j)) {
                neg = -neg;
                subset -= cq[j].first * (cq[j].second + 1);
            }
        if (subset >= 0)
            ans += neg * dp[subset];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    while (N--) {
        array<pair<int, int>, 5> cq;  // cq[4] = (q, v)
        for (int i = 0; i < 5; i++)
            cin >> cq[i].first;

        genDP(cq);

        // Process the queries
        for (int i = 0; i < cq[4].first; i++) {
            for (int j = 0; j < 5; j++)
                cin >> cq[j].second;
            cout << doDP(cq) << endl;
        }
    }
    return 0;
}