#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

constexpr int MAX_N = 1000001;
vector<bool> mark(MAX_N, true);
array<int, 78498> pt;
vector<int> factors;

inline void init_pt()
{
    mark[0] = mark[1] = false;
    for (int p = 2; p * p < MAX_N; p++)
        if (mark[p] == true)
            for (int i = p * p; i < MAX_N; i += p)
                mark[i] = false;

    int counter = 0;
    for (int p = 2; p < MAX_N; p++)
        if (mark[p])
            pt[counter++] = p;
}

inline void gen_factors(int n)
{
    factors.clear();
    for (int i = 0; n != 1 && i < pt.size(); i++) {
        if (__glibc_unlikely(n % pt[i] == 0)) {
            factors.push_back(pt[i]);
            while (!(n % pt[i]))
                n /= pt[i];
        }
    }
}

inline int find_nsf(int n)
{
    unordered_set<int> peeked;
    priority_queue<int, vector<int>, greater<int>> pq;
    int minimal = 1;
    for (const auto &i : factors)
        minimal *= i;
    peeked.insert(minimal);
    pq.push(minimal);

    while (pq.size()) {
        int t = pq.top();
        pq.pop();
        if (t > n)
            return t;
        for (const auto &i : factors) {
            const auto m = (unsigned long long) i * t;
            if (peeked.find(m) != peeked.end() || m > 2000000 ||
                m < 0)  // searched or to big
                continue;
            pq.push(m);
            peeked.insert(m);
        }
    }
    return -1;
}

int main()
{
    init_pt();
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    while (cin >> n) {
        gen_factors(n);
        const auto &nsf = find_nsf(n);
        if (nsf != -1)
            cout << nsf << endl;
        else
            cout << "Not Exist!" << endl;
    }

    return 0;
}