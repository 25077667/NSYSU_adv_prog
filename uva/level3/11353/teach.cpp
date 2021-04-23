#include <bits/stdc++.h>
using namespace std;
#define _SIZE_ 24

struct Ele {
    int key, val;
    // Stable sorting
    bool operator<(const Ele &e) const
    {
        if (val != e.val)
            return val < e.val;
        else
            return key < e.key;
    }
} dp[_SIZE_ + 2];


void pt()
{
    for (int i = 1; i <= _SIZE_; i++)
        cout << dp[i].val << " ";
    cout << endl;
}

void sieve()
{
    // Init
    for (int i = 0; i <= _SIZE_; i++)
        dp[i].key = i;

    dp[1].val = dp[2].val = 1;
    for (int i = 2; i <= _SIZE_; i++) {
        if (!dp[i].val)
            dp[i].val = 1;
        for (int j = 2; i * j <= _SIZE_; j++) {
            dp[i * j].val = dp[i].val + dp[j].val;
            pt();
        }
    }
    pt();
}

int main()
{
    sieve();
    sort(dp, dp + _SIZE_ + 2);

    int n, cases = 0;
    while (cin >> n && n)
        cout << "Case " << ++cases << ": " << dp[n + 1].key << "\n";
    return 0;
}