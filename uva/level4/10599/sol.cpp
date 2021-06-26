#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

// (g_pos, number, route)
using Ele = tuple<int, int, int>;
inline int &get_pos(Ele &ele)
{
    return get<0>(ele);
}
inline int &get_num(Ele &ele)
{
    return get<1>(ele);
}
inline int &get_route(Ele &ele)
{
    return get<2>(ele);
}


int main()
{
    int m, n;
    int count = 0;
    while (cin >> m >> n && (m + n) != -2) {
        int x, y;

        vector<Ele> dp;
        while (cin >> x >> y && x && y) {
            const auto &g_pos = (x - 1) * n + y;
            dp.push_back(make_tuple(g_pos, 1, -1));
        }

        for (auto iter = dp.begin() + 1; iter != dp.end(); iter++) {
            for (auto jter = dp.begin(); jter != dp.end(); jter++)
                if (((get_pos(*jter) - 1) % n >= (get_pos(*iter) - 1) % n) &&
                    get_num(*jter) + 1 > get_num(*iter)) {
                    // Update collected garbade number
                    get_num(*iter) = get_num(*jter) + 1;
                    // Update route
                    get_route(*iter) = get_num(*jter);

                    cout << "From " << get_pos(*jter) << " ";
                }
            cout << endl << "In " << get_pos(*iter) << endl;
            for (auto &i : dp)
                cout << get_pos(i) << " " << get_num(i) << " " << get_route(i)
                     << endl;
            cout << endl;
        }



        // cout << "Case#" << ++count << endl;
    }
    return 0;
}