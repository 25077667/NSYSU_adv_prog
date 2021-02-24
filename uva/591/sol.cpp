#include <iostream>

using namespace std;

int main()
{
    int n, ave, k = 0;
    while (cin >> n) {
        int wall[n], move = 0, sum = 0;
        if (n == 0)
            break;

        for (int i = 0; i < n; i++) {
            cin >> wall[i];
            sum += wall[i];
        }

        ave = sum / n;
        for (int i = 0; i < n; i++) {
            if (wall[i] > ave) {
                move += (wall[i] - ave);
            }
        }
        k++;
        cout << "Set #" << k << endl
             << "The minimum number of moves is " << move << "." << endl;
    }
    return 0;
}
