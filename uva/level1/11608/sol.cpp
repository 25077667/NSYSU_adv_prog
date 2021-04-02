#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    int m[13], n[12], h = 1;
    while (cin >> m[0] && m[0] >= 0) {
        for (int i = 1; i <= 12; i++)
            cin >> m[i];
        for (int i = 0; i < 12; i++)
            cin >> n[i];

        cout << "Case " << h << ":\n";

        for (int i = 0; i < 12; i++) {
            if (m[i] >= n[i]) {
                m[i + 1] += (m[i] - n[i]);
                cout << "No problem! :D\n";
            } else {
                cout << "No problem. :(\n";
                m[i + 1] += m[i];
            }
        }
        h++;
    }

    return 0;
}
