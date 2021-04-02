#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        auto i = 1;
        unsigned long long the_ones = 1 % n;
        while (the_ones) {
            i++;
            the_ones = (the_ones * 10 + 1) % n;
        }
        cout << i << endl;
    }
    return 0;
}