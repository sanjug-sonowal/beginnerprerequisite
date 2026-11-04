/*
Each second, every living enemy deals damage before Bob attacks one.
Bob reduces that enemy's health by power. Return the minimum total
damage Bob takes before defeating every enemy.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// class Solution {
// public:
//     long long minDamage(int power, vector<int>& damage, vector<int>& health) {
//         int n = static_cast<int>(damage.size());
//         vector<int> order(n);
//         iota(order.begin(), order.end(), 0);
//         long long best = LLONG_MAX;
//         do {
//             long long elapsed = 0;
//             long long total = 0;
//             for (int i : order) {
//                 elapsed += (health[i] - 1) / power + 1;
//                 total += elapsed * damage[i];
//             }
//             best = min(best, total);
//         } while (next_permutation(order.begin(), order.end()));
//         return best;
//     }
// };

#include <bits/stdc++.h>
using namespace std;

bool higherPriority(const pair<int, int>& a, const pair<int, int>& b) {
    return 1LL * a.first * b.second > 1LL * b.first * a.second;
}

class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        vector<pair<int, int>> enemies;
        for (size_t i = 0; i < damage.size(); i++) {
            int hits = (health[i] - 1) / power + 1;
            enemies.push_back({damage[i], hits});
        }

        sort(enemies.begin(), enemies.end(), higherPriority);
        long long elapsed = 0;
        long long total = 0;
        for (const auto& enemy : enemies) {
            elapsed += enemy.second;
            total += elapsed * enemy.first;
        }
        return total;
    }
};
