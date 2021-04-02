#include <iostream>
using namespace std;
int main()
{
    int T, n;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int Fst = 0, Sec = 0, H = 0, L = 0;
        cin >> n;
        cin >> Fst;
        for (int j = 1; j < n; j++) {
            cin >> Sec;
            if (Fst > Sec)
                H++;
            if (Fst < Sec)
                L++;
            Fst = Sec;
        }
        cout << "Case " << i << ": " << L << " " << H << endl;
    }
    return 0;
}
