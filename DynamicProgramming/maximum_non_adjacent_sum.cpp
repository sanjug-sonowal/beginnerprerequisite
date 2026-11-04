/*
Given an integer array, maximize the sum of a subset of elements
whose indices are pairwise non-adjacent.
The empty selection is allowed and has sum 0.
Input: N, followed by N values.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// long long tryChoices(const vector<int>& a, size_t i) {
//     if (i >= a.size()) {
//         return 0;
//     }
//     long long skip = tryChoices(a, i + 1);
//     long long take = a[i] + tryChoices(a, i + 2);
//     return max(skip, take);
// }
//
// long long maxNonAdjacentSum(const vector<int>& a) {
//     return tryChoices(a, 0);
// }
//
// int main() {
//     int n;
//     if (!(cin >> n)) {
//         return 0;
//     }
//
//     vector<int> a(n);
//     for (int& value : a) {
//         cin >> value;
//     }
//     cout << maxNonAdjacentSum(a) << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

long long maxNonAdjacentSum(const vector<int>& a) {
    long long twoBack = 0;
    long long previous = 0;
    for (size_t i = 0; i < a.size(); i++) {
        long long current = max(previous, twoBack + a[i]);
        twoBack = previous;
        previous = current;
    }
    return previous;
}

int main() {
    int n;
    if (!(cin >> n)) {
        return 0;
    }

    vector<int> a(n);
    for (int& value : a) {
        cin >> value;
    }
    cout << maxNonAdjacentSum(a) << '\n';
    return 0;
}
