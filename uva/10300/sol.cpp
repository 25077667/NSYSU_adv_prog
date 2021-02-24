#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    while (n--) {
        long long int f, s = 0;
        cin >> f;
        while (f--) {
            long long int d[3];
            cin >> d[0] >> d[1] >> d[2];
            s += d[0] * d[2];
        }
        cout << s << endl;
    }
    return 0;
}
