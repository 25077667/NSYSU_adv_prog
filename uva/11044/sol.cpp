
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
    int t, n, m;
    cin >> t;
    for (int i = 0; i < t; i++) {
        while (cin >> n >> m) {
            cout << (n / 3) * (m / 3) << endl;
        }
    }
    return 0;
}
