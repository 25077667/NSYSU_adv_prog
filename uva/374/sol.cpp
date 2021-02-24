#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dc(ll b, ll p, ll m)
{
    if (p == 0)
        return 1;
    else if (p == 1)
        return b % m;
    else {
        ll a = dc(b, p / 2, m);
        if (p % 2)
            return a * a * b % m;
        else
            return a * a % m;
    }
}
int main()
{
    ll b, p, m;
    while (cin >> b >> p >> m)
        cout << dc(b, p, m) << endl;
    return 0;
}
