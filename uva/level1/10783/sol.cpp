#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
    int a, b, n, num0, num1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        num0 = a;
        num1 = b;
        if (a % 2 == 0)  //偶數
            num0 = a + 1;
        if (b % 2 == 0)
            num1 = b - 1;
        num0 = (num0 + num1) * ((num1 - num0) / 2 + 1) / 2;
        cout << "Case " << i + 1 << ": " << num0 << endl;
    }
    return 0;
}
