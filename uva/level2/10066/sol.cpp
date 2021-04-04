#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N1, N2, s1[102], s2[102], counter = 0;
    while (cin >> N1 >> N2 && N1 && N2) {
        for (int i = 0; i < N1; i++)
            cin >> s1[i + 1];
        for (int i = 0; i < N2; i++)
            cin >> s2[i + 1];

        int LCS[102][102] = {0};
        for (int i = 1; i <= N1; i++)
            for (int j = 1; j <= N2; j++) {
                if (s1[i] == s2[j])
                    LCS[i][j] = LCS[i - 1][j - 1] + 1;
                else
                    LCS[i][j] = (LCS[i - 1][j] > LCS[i][j - 1]) ? LCS[i - 1][j]
                                                                : LCS[i][j - 1];
            }

        cout << "Twin Towers #" << ++counter << "\n"
             << "Number of Tiles : " << LCS[N1][N2] << endl
             << endl;
    }
    return 0;
}
