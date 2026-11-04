/*
Root the tree at vertex 1. Print each vertex's number of children,
then print all leaves in increasing vertex order on a second line.
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

    vector<int> degree(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }

    for (int u = 1; u <= n; u++) {
        if (u > 1) {
            cout << ' ';
        }
        cout << degree[u] - (u != 1);
    }
    cout << '\n';
    bool first = true;
    for (int u = 1; u <= n; u++) {
        if (degree[u] == (u != 1)) {
            if (!first) {
                cout << ' ';
            }
            cout << u;
            first = false;
        }
    }
    cout << '\n';
    return 0;
}
