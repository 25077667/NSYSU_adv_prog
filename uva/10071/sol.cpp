#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
    int v, t;

    while (cin >> v >> t) {
        cout << v * 2 * t << endl;
    }

    return 0;
}
