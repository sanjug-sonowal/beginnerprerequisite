/*
Codeforces 1151D. Minimize total dissatisfaction by ordering the queue.
A person with values a and b contributes a times the number ahead
plus b times the number behind. Input: N, then N pairs a b.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// long long minDissatisfaction(const vector<pair<int, int>>& people) {
//     int n = static_cast<int>(people.size());
//     vector<int> order(n);
//     iota(order.begin(), order.end(), 0);
//     long long best = LLONG_MAX;
//     do {
//         long long total = 0;
//         for (int i = 0; i < n; i++) {
//             auto person = people[order[i]];
//             total += 1LL * person.first * i + 1LL * person.second * (n - 1 - i);
//         }
//         best = min(best, total);
//     } while (next_permutation(order.begin(), order.end()));
//     return best;
// }
//
// int main() {
//     int n;
//     if (!(cin >> n)) {
//         return 0;
//     }
//     vector<pair<int, int>> people(n);
//     for (auto& person : people) {
//         cin >> person.first >> person.second;
//     }
//     cout << minDissatisfaction(people) << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

long long minDissatisfaction(const vector<pair<int, int>>& people) {
    int n = static_cast<int>(people.size());
    vector<long long> differences;
    long long total = 0;
    for (const auto& person : people) {
        total += 1LL * person.second * (n - 1);
        differences.push_back(1LL * person.first - person.second);
    }

    sort(differences.begin(), differences.end(), greater<long long>());
    for (int i = 0; i < n; i++) {
        total += differences[i] * i;
    }
    return total;
}

int main() {
    int n;
    if (!(cin >> n)) {
        return 0;
    }
    vector<pair<int, int>> people(n);
    for (auto& person : people) {
        cin >> person.first >> person.second;
    }
    cout << minDissatisfaction(people) << '\n';
    return 0;
}
