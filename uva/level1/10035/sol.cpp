#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c1, c2;  // c1 count
    while (cin >> a >> b && (a || b)) {
        c1 = 0;
        c2 = 0;
        while (a || b) {
            c2 += a % 10 + b % 10;
            a /= 10;
            b /= 10;
            c2 /= 10;
            if (c2)
                c1++;
        }
        if (c1 == 0)
            cout << "No carry operation." << endl;
        else if (c1 == 1)
            cout << c1 << " carry operation." << endl;
        else if (c1 > 1)
            cout << c1 << " carry operations." << endl;
    }
}
