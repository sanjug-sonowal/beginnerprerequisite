/*
Print DFS preorder starting at vertex 1 of an undirected graph.
Explore neighbors in input order and visit each reachable vertex once.
Input: N M, followed by M edges between vertices numbered 1 through N.
*/

// Recursive DFS Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// void dfs(int source, const vector<vector<int>>& graph,
//          vector<bool>& visited, vector<int>& order) {
//     visited[source] = true;
//     order.push_back(source);
//     for (int neighbor : graph[source]) {
//         if (!visited[neighbor]) {
//             dfs(neighbor, graph, visited, order);
//         }
//     }
// }
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
//     vector<vector<int>> graph(n + 1);
//     for (int i = 0; i < m; i++) {
//         int u, v;
//         cin >> u >> v;
//         graph[u].push_back(v);
//         graph[v].push_back(u);
//     }
//
//     vector<bool> visited(n + 1, false);
//     vector<int> order;
//     dfs(1, graph, visited, order);
//
//     for (size_t i = 0; i < order.size(); i++) {
//         if (i > 0) {
//             cout << ' ';
//         }
//         cout << order[i];
//     }
//     cout << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void dfs(int source, const vector<vector<int>>& graph,
         vector<bool>& visited, vector<int>& order) {
    vector<size_t> nextNeighbor(graph.size(), 0);
    stack<int> path;

    visited[source] = true;
    order.push_back(source);
    path.push(source);

    while (!path.empty()) {
        int vertex = path.top();
        if (nextNeighbor[vertex] == graph[vertex].size()) {
            path.pop();
            continue;
        }

        int neighbor = graph[vertex][nextNeighbor[vertex]];
        nextNeighbor[vertex]++;
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            order.push_back(neighbor);
            path.push(neighbor);
        }
    }
}

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

    vector<bool> visited(n + 1, false);
    vector<int> order;
    dfs(1, graph, visited, order);

    for (size_t i = 0; i < order.size(); i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << order[i];
    }
    cout << '\n';
    return 0;
}
