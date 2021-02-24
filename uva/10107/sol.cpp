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
int main()
{
    int t = 0, d[10000], p;
    while (cin >> d[t]) {
        p = t;
        while (d[p] < d[p - 1]) {
            swap(d[p], d[p - 1]);
            p--;
        }
        t++;
        if (t % 2 == 1)
            cout << d[t / 2] << endl;
        else
            cout << (d[t / 2] + d[t / 2 - 1]) / 2 << endl;
    }
    /*int a,b;
        while(cin>>a>>b)
            {
                    cout<< ((a+b)%2)? "= =\"" :" >\\\<";
                            cout<<endl;
                                }*/
}
