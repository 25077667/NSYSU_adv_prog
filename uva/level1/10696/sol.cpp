#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    int n;
    while (cin >> n) {
        if (n == 0)
            break;
        cout << "f91(" << n << ") = " << (n > 101) * (n - 101) + 91 << endl;
    }

    return 0;
}
