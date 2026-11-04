/*
Root the tree at vertex 1 and print the sum of each subtree, including
its root. Node values may be negative. Subtree sums fit in 64 bits.
Input: N, then N node values, then N-1 undirected edges on vertices 1 through N.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    vector<long long> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
    }

    vector<vector<int>> graph(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> parent(n + 1, 0);
    vector<int> order = {1};
    for (size_t i = 0; i < order.size(); i++) {
        int u = order[i];
        for (int v : graph[u]) {
            if (v != parent[u]) {
                parent[v] = u;
                order.push_back(v);
            }
        }
    }

    for (int i = n - 1; i > 0; i--) {
        int u = order[i];
        sum[parent[u]] += sum[u];
    }

    for (int u = 1; u <= n; u++) {
        if (u > 1) {
            cout << ' ';
        }
        cout << sum[u];
    }
    cout << '\n';
    return 0;
}
