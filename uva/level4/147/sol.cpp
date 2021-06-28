#include <bits/stdc++.h>
using namespace std;

const array<int, 11> money = {10000, 5000, 2000, 1000, 500, 200,
                              100,   50,   20,   10,   5};
array<long long, 30001> dp = {1};

inline void init()
{
    for (auto iter = money.rbegin(); iter != money.rend(); iter++)
        for (auto j = *iter; j < dp.size(); j++)
            dp[j] += dp[j - *iter];
}

int main()
{
    init();
    int i, f;
    while (::scanf("%d.%d", &i, &f) != EOF && (i | f))
        ::printf("%3d.%02d%17lld\n", i, f, dp[i * 100 + f]);
    return 0;
}