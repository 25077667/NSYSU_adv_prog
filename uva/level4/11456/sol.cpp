#include <bits/stdc++.h>
using namespace std;

int lis(const deque<int> &seq)
{
    deque<int> p;

    if (seq.empty())
        return 0;
    p.push_back(seq[0]);
    for (const auto &i : seq) {
        if (i > p.back())
            p.push_back(i);
        else
            *lower_bound(p.begin(), p.end(), i) = i;
    }
    return p.size();
}

int main()
{
    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        deque<int> seq;
        while (n--) {
            int tmp;
            cin >> tmp;
            seq.emplace_back(tmp);
            seq.emplace_front(tmp);
        }
        cout << lis(seq) << endl;
    }
    return 0;
}