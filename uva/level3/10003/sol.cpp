#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l;

    while (cin >> l && l) {
        int n;
        cin >> n;
        int DP[52][52] = {0};
        int need[52] = {0};

        for (int i = 0; i < n; i++)
            cin >> need[i + 1];
        need[++n] = l;

        for (int i = 2; i <= n; i++)
            for (int j = 0, k = i + j; k <= n; j++, k++) {
                int min = INT_MAX;
                for (int m = j + 1; m < k; m++) {
                    auto tmp = DP[j][m] + DP[m][k] + need[k] - need[j];
                    min = std::min(tmp, min);
                }
                DP[j][k] = min;
            }

        cout << "The minimum cutting is " << DP[0][n] << "." << endl;
    }

    return 0;
}