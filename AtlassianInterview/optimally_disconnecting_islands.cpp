/*
All N islands are initially connected by bridges. Removing the
bridge between islands i and j costs A[i] * A[j]. Given a budget C,
minimize the number of islands reachable from island 1, including it.
Importance values and the budget are nonnegative.

Read T test cases, each with N C followed by N importance values.
Print one minimum reachable count per test case.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// int tryCuts(const vector<long long>& a, long long budget, size_t i,
//             __int128 removed, __int128 kept, int reachable) {
//     if (i == a.size()) {
//         if (removed == 0 || kept <= budget / removed) {
//             return reachable;
//         }
//         return static_cast<int>(a.size());
//     }
//
//     int keep = tryCuts(a, budget, i + 1, removed, kept + a[i], reachable + 1);
//     int cut = tryCuts(a, budget, i + 1, removed + a[i], kept, reachable);
//     return min(keep, cut);
// }
//
// int minimumReachableIslands(const vector<long long>& a, long long budget) {
//     return tryCuts(a, budget, 1, 0, a[0], 1);
// }

#include <bits/stdc++.h>
using namespace std;

int minimumReachableIslands(vector<long long> a, long long budget) {
    int n = static_cast<int>(a.size());
    sort(a.begin() + 1, a.end());

    __int128 total = 0;
    for (long long importance : a) {
        total += importance;
    }

    int reachable = n;
    __int128 smallestSum = 0;
    __int128 largestSum = 0;
    for (int removed = 1; removed < n; removed++) {
        smallestSum += a[removed];
        largestSum += a[n - removed];

        bool canCutSmallest = smallestSum == 0 ||
                              total - smallestSum <= budget / smallestSum;
        bool canCutLargest = largestSum == 0 ||
                             total - largestSum <= budget / largestSum;
        if (canCutSmallest || canCutLargest) {
            reachable = n - removed;
        }
    }
    return reachable;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    if (!(cin >> tests)) {
        return 0;
    }
    while (tests--) {
        int n;
        long long budget;
        cin >> n >> budget;

        vector<long long> a(n);
        for (long long& importance : a) {
            cin >> importance;
        }
        cout << minimumReachableIslands(move(a), budget) << '\n';
    }
    return 0;
}
