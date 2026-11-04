/*
Print YES for each vertex reachable from vertex 1, and NO otherwise.
Read N M, then M undirected edges.
Vertices are numbered 1 through N. Input is a simple graph.
Print one result per vertex in vertex order.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) {
        return 0;
    }

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> distance(n + 1, -1);
    queue<int> pending;
    distance[1] = 0;
    pending.push(1);

    while (!pending.empty()) {
        int u = pending.front();
        pending.pop();

        for (int v : graph[u]) {
            if (distance[v] == -1) {
                distance[v] = distance[u] + 1;
                pending.push(v);
            }
        }
    }

    for (int v = 1; v <= n; v++) {
        cout << (distance[v] == -1 ? "NO" : "YES") << '\n';
    }
    return 0;
}
