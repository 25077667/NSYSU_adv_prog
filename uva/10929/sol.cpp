#include <math.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    char num[1001];
    while (cin >> num) {
        if (num[0] == '0')
            return 0;

        int sum = 0, a;
        a = strlen(num);
        for (int i = 0; i < a; i++) {
            if ((i + 1) % 2 == 1)
                sum += num[i] - '0';
            else
                sum -= num[i] - '0';
        }

        cout << num;

        if (sum % 11 != 0)
            cout << " is not a multiple of 11.";
        else
            cout << " is a multiple of 11.";
        cout << endl;
    }
}
