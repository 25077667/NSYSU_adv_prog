#include <iostream>

using namespace std;


int main(int argc, char **argv)
{
    int s, d, n, num0, num1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> d;
        // s得分和  d得分差
        num0 = (s + d) / 2;
        num1 = (s - d) / 2;
        if (num0 + num1 != s)
            cout << "impossible" << endl;
        else if (num0 < 0 || num1 < 0)
            cout << "impossible" << endl;
        else
            cout << num0 << " " << num1 << endl;
    }


    return 0;
}
