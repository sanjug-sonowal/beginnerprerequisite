/*
For each target price, find the fewest operations needed to make
every item cost that amount. One operation changes one price by 1.
Each query starts from the original prices. Return answers in query
order. There can be up to 200000 prices and 200000 queries.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// vector<long long> countMinimumOperations(vector<int> price, vector<int> query) {
//     vector<long long> answers;
//     answers.reserve(query.size());
//
//     for (int target : query) {
//         long long operations = 0;
//         for (int value : price) {
//             operations += abs(1LL * value - target);
//         }
//         answers.push_back(operations);
//     }
//
//     return answers;
// }

#include <bits/stdc++.h>
using namespace std;

vector<long long> countMinimumOperations(vector<int> price, vector<int> query) {
    sort(price.begin(), price.end());

    int n = static_cast<int>(price.size());
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + price[i];
    }

    vector<long long> answers;
    answers.reserve(query.size());
    for (long long target : query) {
        int split = lower_bound(price.begin(), price.end(), target) - price.begin();
        long long increase = target * split - prefix[split];
        long long decrease = prefix[n] - prefix[split] - target * (n - split);
        answers.push_back(increase + decrease);
    }
    return answers;
}
