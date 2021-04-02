#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            int edge[4];
            for (int j = 0; j < 4; j++)
                cin >> edge[j];

            sort(edge, edge + 4);
            if (edge[0] == edge[3])
                cout << "square" << endl;
            else if (edge[0] == edge[1] && edge[2] == edge[3] &&
                     edge[0] != edge[3])
                cout << "rectangle" << endl;
            else if (edge[0] + edge[1] + edge[2] <= edge[3])
                cout << "banana" << endl;
            else
                cout << "quadrangle" << endl;
        }
    }
}
