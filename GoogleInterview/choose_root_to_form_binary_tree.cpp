/*
Given a tree with degree at most 3, print a root that gives every
vertex at most two children. Print the smallest valid root.
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
        if (degree[u] <= 2) {
            cout << u << '\n';
            break;
        }
    }
    return 0;
}
