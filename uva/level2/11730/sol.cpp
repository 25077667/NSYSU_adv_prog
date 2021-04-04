#include <bits/stdc++.h>

using namespace std;

const array<int, 168> prime_vec{
    2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,
    47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107,
    109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
    191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263,
    269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
    353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433,
    439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521,
    523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613,
    617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701,
    709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
    811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887,
    907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997,
};

const list<int> gen_prime_factor(const int &val)
{
    list<int> fac_lst;
    for (const auto &i : prime_vec) {
        if (i > val)
            break;
        if (val % i == 0)
            fac_lst.push_back(i);
    }
    return fac_lst;
}

int main()
{
    int s, t;
    int cases = 0;
    while (cin >> s >> t && s && t) {
        cout << "Case " << ++cases << ": ";
        queue<pair<int, int>> bfs;
        unordered_set<int> seen;
        unsigned long counter = 0;
        bfs.push(make_pair(s, 0));

        do {
            auto front = bfs.front();
            if (front.first == t)
                break;
            bfs.pop();
            if (front.first > t)
                continue;

            auto &&l = gen_prime_factor(front.first);

            for (auto iter = l.begin(); iter != l.end(); iter++) {
                const auto next_val = *iter + front.first;
                if (seen.find(next_val) == seen.end()) {
                    bfs.push(make_pair(next_val, front.second + 1));
                    seen.insert(next_val);
                    // cerr << next_val << " ";
                }
            }
        } while (!bfs.empty());

        cout << ((bfs.front().first == t) ? bfs.front().second : -1) << endl;
    }

    return 0;
}