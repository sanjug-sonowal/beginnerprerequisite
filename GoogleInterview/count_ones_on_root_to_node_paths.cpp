/*
Given a tree with 0 or 1 at each vertex, print the number of ones on
each path from vertex 1, including both endpoints.
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

    vector<int> ones(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ones[i];
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

    for (int u : order) {
        ones[u] += ones[parent[u]];
    }

    for (int u = 1; u <= n; u++) {
        if (u > 1) {
            cout << ' ';
        }
        cout << ones[u];
    }
    cout << '\n';
    return 0;
}
