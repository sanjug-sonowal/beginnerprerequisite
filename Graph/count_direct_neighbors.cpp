/*
Given an undirected graph with vertices 1 through N, count the distinct
vertices directly connected to each vertex. Repeated edges count once.
A self-loop counts its own vertex once.

Input: N M, followed by M endpoint pairs u v.
Print one count per line in vertex order.
*/

// Adjacency Matrix Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//
//     int n, m;
//     if (!(cin >> n >> m)) {
//         return 0;
//     }
//
//     vector<vector<bool>> adjacent(n + 1, vector<bool>(n + 1, false));
//     for (int i = 0; i < m; i++) {
//         int u, v;
//         cin >> u >> v;
//         adjacent[u][v] = true;
//         adjacent[v][u] = true;
//     }
//
//     for (int u = 1; u <= n; u++) {
//         int count = 0;
//         for (int v = 1; v <= n; v++) {
//             count += adjacent[u][v];
//         }
//         cout << count << '\n';
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) {
        return 0;
    }

    vector<vector<int>> adjacent(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }

    vector<int> lastSeenFrom(n + 1, 0);
    for (int u = 1; u <= n; u++) {
        int count = 0;
        for (int v : adjacent[u]) {
            if (lastSeenFrom[v] != u) {
                lastSeenFrom[v] = u;
                count++;
            }
        }
        cout << count << '\n';
    }
    return 0;
}
