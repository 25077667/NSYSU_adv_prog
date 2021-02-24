#include <ctype.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stack>
using namespace std;
struct data {
    int m, s, t;
} d[1000];

int main()
{
    char wrong[] = "1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./";
    char right[] = "`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.";
    map<char, char> t;
    for (int i = 0; i < strlen(wrong); i++)
        t[wrong[i]] = right[i];
    int n;
    while (cin >> n && n != 0) {
        int p = 0;
        stack<int> s;
        while (n) {
            s.push(n & 1);
            if (n & 1)
                p++;
            n >>= 1;
        }
        cout << "The parity of ";
        while (!s.empty()) {
            cout << s.top();
            s.pop();
        }
        cout << " is " << p << " (mod 2).\n";
    }
    return 0;
}
