#include <ctype.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
long long int gcd(long long int m, long long int n)
{
    while (n != 0) {
        long long int r = m % n;
        m = n;
        n = r;
    }
    return m;
}
long long int lcm(long long int a, long long int b)
{
    return abs(a * b) / gcd(a, b);
}
using namespace std;
int main()
{
    vector<int> v;
    for (int i = 0; i <= 317; i++)
        v.push_back(i * i);
    int a, b;
    while (cin >> a >> b && a != 0 && b != 0) {
        vector<int>::iterator l, u;
        l = lower_bound(v.begin(), v.end(), a);
        u = upper_bound(v.begin(), v.end(), b);
        cout << (u - v.begin()) - (l - v.begin()) << endl;
    }
    return 0;
}
