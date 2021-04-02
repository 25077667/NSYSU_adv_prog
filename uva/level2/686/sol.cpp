#include <bits/stdc++.h>
using namespace std;
bool prime[40000];  // 0 is not prime

void is_prime()
{
    memset(prime, 1, 40000);
    prime[0] = prime[1] = 0;
    prime[2] = 1;
    for (int i = 2; i <= 200; i++)
        if (prime[i])
            for (long long j = i * i; j <= 40000; j += i)
                prime[j] = false;
}

int main()
{
    int num;
    is_prime();
    while (cin >> num && num) {
        int counter = 0;
        for (int i = 2; i < num / 2 + 1; i++)
            if (prime[i] && prime[num - i])
                counter++;
        cout << counter << endl;
    }
    return 0;
}
