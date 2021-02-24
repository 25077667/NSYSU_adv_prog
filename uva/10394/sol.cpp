#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int PRIME_MAX_LIMIT = 20000000;

int main()
{
    vector<bool> prime(PRIME_MAX_LIMIT + 5, true);
    vector<int> twinPrimes;

    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i <= PRIME_MAX_LIMIT; ++i) {
        if (prime[i]) {
            for (int j = i + i; j <= PRIME_MAX_LIMIT; j += i) {
                prime[j] = false;
            }
            if (prime[i] && prime[i - 2]) {
                twinPrimes.push_back(i - 2);
            }
        }
    }

    int S;
    while (scanf("%d", &S) != EOF) {
        printf("(%d, %d)\n", twinPrimes[S - 1], twinPrimes[S - 1] + 2);
    }

    return 0;
}
