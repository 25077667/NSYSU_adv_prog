#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t = 0;
    vector<int> v;
    while (cin >> t) {
        v.insert(lower_bound(v.begin(), v.end(), t), t);
        if (v.size() & 1)
            cout << v[v.size() >> 1] << endl;
        else
            cout << ((v[v.size() >> 1] + v[(v.size() >> 1) - 1]) >> 1) << endl;
    }
    return 0;
}