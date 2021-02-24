#include <cstdlib>
#include <iostream>

using namespace std;
int g(int a)
{
    if (a < 0)
        a *= -1;

    return a;
}
int main(int argc, char *argv[])
{
    int x1, y1, x2, y2, dx, dy;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        dx = g(x1 - x2);
        dy = g(y1 - y2);
        if (x1 == x2 && x2 == y1 && y1 == y2 && y2 == x1 && x1 == 0)
            break;


        if (x1 == x2 && y1 == y2)
            cout << 0 << endl;
        else if (x1 - x2 != 0 && y1 - y2 == 0)
            cout << 1 << endl;
        else if (x1 - x2 == 0 && y1 - y2 != 0)
            cout << 1 << endl;
        else if (dx == dy)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
    return 0;
}
