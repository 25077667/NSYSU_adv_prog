#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    long int n;
    while (cin >> n) {
        if (n < 0)
            break;

        n = (n + 1) * n / 2 + 1;
        cout << n << endl;
    }
    return 0;
}
