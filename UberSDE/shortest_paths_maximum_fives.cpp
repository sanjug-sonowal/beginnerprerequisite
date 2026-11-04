/*
Print distance and the maximum count of vertices valued 5 on a shortest path.
For an unreachable vertex print -1 0.
Read N M, N vertex values (0 or 5), then M undirected edges.
Vertices are numbered 1 through N. Input is a simple graph.
The source and destination count toward the number of fives.
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

    vector<int> value(n + 1);
    for (int v = 1; v <= n; v++) {
        cin >> value[v];
    }

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> distance(n + 1, -1);
    vector<int> best(n + 1, 0);
    best[1] = (value[1] == 5);
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
            if (distance[v] != distance[u] + 1) {
                continue;
            }

            int candidate = best[u] + (value[v] == 5);
            best[v] = max(best[v], candidate);
        }
    }

    for (int v = 1; v <= n; v++) {
        cout << distance[v] << ' ' << best[v] << '\n';
    }
    return 0;
}
