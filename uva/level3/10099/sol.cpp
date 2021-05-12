#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int left, right, weight;
    Edge() : left(0), right(0), weight(0) {}
    Edge(int _l, int _r, int _w) : left(_l), right(_r), weight(_w) {}
    inline friend bool operator<(const Edge &lhs, const Edge &rhs)
    {
        return lhs.weight < rhs.weight;
    }
    inline friend bool operator>(const Edge &lhs, const Edge &rhs)
    {
        return lhs.weight > rhs.weight;
    }
};

class Djs
{
public:
    Djs(int n)
    {
        parent = new int[n];
        sz = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    void union_sets(int u, int v)
    {
        u = find_parent(u);
        v = find_parent(v);
        if (sz[u] > sz[v])
            swap(u, v);
        parent[u] = v;
        sz[v] += sz[u];
    }
    bool same_set(int u, int v) { return find_parent(u) == find_parent(v); }
    ~Djs() { delete[] parent; }

private:
    inline int find_parent(int u)
    {
        return (parent[u] == u) ? u : (parent[u] = find_parent(parent[u]));
    }
    int *parent;
    int *sz;
};

int main()
{
    Edge e[10001];  // 100 nodes, at most 100*100 edge
    int n, r, cases = 1;
    while (cin >> n >> r && n && r) {
        for (int i = 0; i < r; i++) {
            int _l, _r, _w;
            cin >> _l >> _r >> _w;
            e[i] = {_l, _r, _w};
        }

        sort(e, e + r, greater<Edge>());
        int start, accept, num, bottleneck = INT_MAX;
        cin >> start >> accept >> num;
        Djs dsu{105};
        for (int i = 0; i < r; i++) {
            dsu.union_sets(e[i].left, e[i].right);
            if (dsu.same_set(start, accept)) {
                bottleneck = e[i].weight;
                break;
            }
        }

        cout << "Scenario #" << cases++ << endl;
        cout << "Minimum Number of Trips = "
             << ceil(num * 1.0 / (bottleneck - 1)) << endl << endl;

        memset(e, 0, sizeof(e));
    }

    return 0;
}