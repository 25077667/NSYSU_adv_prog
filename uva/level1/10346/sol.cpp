#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    int n, k;
    while (cin >> n >> k) {
        int sum = n;
        while (n >= k) {
            int sp = n % k;
            n = n / k;
            sum = sum + n;
            n = n + sp;
        }
        cout << sum << endl;
    }
    return 0;
}
