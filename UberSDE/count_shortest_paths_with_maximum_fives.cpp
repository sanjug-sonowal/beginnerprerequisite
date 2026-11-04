/*
Print the number of shortest paths from vertex 1 that maximize the count
of vertices valued 5 among all shortest paths to each destination.
Read N M, N vertex values (0 or 5), then M undirected edges.
Vertices are numbered 1 through N. Input is a simple graph.
The source and destination count toward the number of fives.
The source has one empty path. Unreachable vertices have zero paths.
Print one result per vertex in vertex order.
*/

#include <bits/stdc++.h>
using namespace std;

void addCount(string& count, const string& other) {
    int carry = 0;
    size_t length = max(count.size(), other.size());
    count.resize(length, '0');

    for (size_t i = 0; i < length; i++) {
        int digit = count[i] - '0' + carry;
        if (i < other.size()) {
            digit += other[i] - '0';
        }
        count[i] = '0' + digit % 10;
        carry = digit / 10;
    }
    if (carry != 0) {
        count.push_back('0' + carry);
    }
}

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
    vector<string> ways(n + 1, "0");
    ways[1] = "1";
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
            if (candidate > best[v]) {
                best[v] = candidate;
                ways[v] = ways[u];
            } else if (candidate == best[v]) {
                addCount(ways[v], ways[u]);
            }
        }
    }

    for (int v = 1; v <= n; v++) {
        reverse(ways[v].begin(), ways[v].end());
        cout << ways[v] << '\n';
    }
    return 0;
}
