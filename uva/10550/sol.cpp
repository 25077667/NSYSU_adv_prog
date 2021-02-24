#include <bits/stdc++.h>
using namespace std;
struct p {
    int x, y;
} p[200];

int gcd(int m, int n)
{
    while (n != 0) {
        int r = m % n;
        m = n;
        n = r;
    }
    return m;
}
int bs(int num[], int n, int f)
{
    int l = 0, r = n - 1, m;
    while (l <= r) {
        m = (l + r) / 2;
        if (f == num[m])
            return m + 1;
        else if (f > num[m])
            l = m + 1;
        else
            r = m - 1;
    }
    return 0;
}
int main()
{
    int n, p1, p2, p3;
    while (cin >> n >> p1 >> p2 >> p3 && (n || p1 || p2 || p3)) {
        int sum = 1080;
        sum += ((n + 40 - p1) % 40) * 9;
        sum += ((p2 + 40 - p1) % 40) * 9;
        sum += ((p2 + 40 - p3) % 40) * 9;
        cout << sum << endl;
        //順 逆 順
    }
}
