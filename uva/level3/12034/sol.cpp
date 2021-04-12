#include <bits/stdc++.h>
#define MODULE 10056
using namespace std;

int dp[1001][1002] = {1};

void run()
{
    for (int i = 1; i <= 1000; i++) {
        unsigned int s = 0;
        for (int j = 1; j <= 1000; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MODULE * j;
            s = (s + dp[i][j]) % MODULE;
        }
        dp[i][1001] = s;
    }
}

int main()
{
    run();

    int n, cases = 0, t;
    cin >> n;
    while (n-- && cin >> t)
        cout << "Case " << ++cases << ": " << dp[t][1001] << "\n";
    return 0;
}