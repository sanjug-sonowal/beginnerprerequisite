/*
AtCoder Frog 2. Reach stone N from stone 1 using jumps of length
1 through K. A jump costs the absolute difference in heights.
Print the minimum total cost.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// long long minimumCost(const vector<int>& height, int i, int k) {
//     int n = static_cast<int>(height.size()) - 1;
//     if (i == n) {
//         return 0;
//     }
//     long long best = LLONG_MAX;
//     for (int jump = 1; jump <= k && jump <= n - i; jump++) {
//         int next = i + jump;
//         long long cost = abs(1LL * height[i] - height[next]);
//         best = min(best, cost + minimumCost(height, next, k));
//     }
//     return best;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) {
        return 0;
    }

    vector<int> height(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> height[i];
    }

    vector<long long> dp(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        dp[i] = LLONG_MAX;
        for (int jump = 1; jump <= k && jump < i; jump++) {
            int previous = i - jump;
            long long cost = abs(1LL * height[i] - height[previous]);
            dp[i] = min(dp[i], dp[previous] + cost);
        }
    }

    cout << dp[n] << '\n';
    return 0;
}
