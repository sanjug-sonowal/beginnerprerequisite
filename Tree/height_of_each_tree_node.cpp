/*
Root the tree at vertex 1 and print each vertex's height in edges.
A leaf has height 0.
Input: N, then N-1 undirected edges on vertices 1 through N.
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

    vector<int> height(n + 1, 0);
    for (int i = n - 1; i > 0; i--) {
        int u = order[i];
        height[parent[u]] = max(height[parent[u]], height[u] + 1);
    }

    for (int u = 1; u <= n; u++) {
        if (u > 1) {
            cout << ' ';
        }
        cout << height[u];
    }
    cout << '\n';
    return 0;
}
