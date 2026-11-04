/*
Given an array of size N and Q queries of the form (L,R), for each query find the sum of elements in the range [L…R] in the array.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    int n = a.size();
    vector<int> p(n);
    p[0] = a[0];
    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1] + a[i];
    }
    vector<pair<int, int>> queries = {{0, 2}, {1, 3}, {2, 4}};
    for (auto &q : queries) {
        int L = q.first, R = q.second;
        int sum = p[R] - (L > 0 ? p[L - 1] : 0);
        cout << sum << endl;
    }
    return 0;
}