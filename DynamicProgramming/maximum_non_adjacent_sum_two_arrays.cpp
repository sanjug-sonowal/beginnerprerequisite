/*
Given two arrays of equal size, select at most one value per column.
Selected columns cannot be adjacent. Maximize the sum.
The empty selection is allowed and has sum 0.
Input: N, followed by the two arrays of N values each.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// long long tryChoices(const vector<int>& a, const vector<int>& b, size_t i) {
//     if (i >= a.size()) {
//         return 0;
//     }
//     long long skip = tryChoices(a, b, i + 1);
//     long long take = max(a[i], b[i]) + tryChoices(a, b, i + 2);
//     return max(skip, take);
// }
//
// long long maxNonAdjacentSum(const vector<int>& a, const vector<int>& b) {
//     return tryChoices(a, b, 0);
// }
//
// int main() {
//     int n;
//     if (!(cin >> n)) {
//         return 0;
//     }
//
//     vector<int> a(n), b(n);
//     for (int& value : a) {
//         cin >> value;
//     }
//     for (int& value : b) {
//         cin >> value;
//     }
//     cout << maxNonAdjacentSum(a, b) << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

long long maxNonAdjacentSum(const vector<int>& a, const vector<int>& b) {
    long long twoBack = 0;
    long long previous = 0;
    for (size_t i = 0; i < a.size(); i++) {
        long long current = max(previous, twoBack + max(a[i], b[i]));
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

    vector<int> a(n), b(n);
    for (int& value : a) {
        cin >> value;
    }
    for (int& value : b) {
        cin >> value;
    }
    cout << maxNonAdjacentSum(a, b) << '\n';
    return 0;
}
