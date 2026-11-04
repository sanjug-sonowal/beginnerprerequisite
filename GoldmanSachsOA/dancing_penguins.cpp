/*
Form as many disjoint male-female penguin pairs as possible.
A positive signed height means the penguin wants a taller partner,
and a negative height means it wants a shorter one. Both preferences
must be satisfied, and equal heights cannot be paired.

Read N, then N signed male heights and N signed female heights.
Print the maximum number of pairs.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// int tryPairs(const vector<int>& male, const vector<int>& female,
//              vector<bool>& used, size_t i) {
//     if (i == male.size()) {
//         return 0;
//     }
//
//     int best = tryPairs(male, female, used, i + 1);
//     for (size_t j = 0; j < female.size(); j++) {
//         bool valid = (male[i] > 0 && female[j] < 0 && male[i] < -female[j]) ||
//                      (male[i] < 0 && female[j] > 0 && female[j] < -male[i]);
//         if (!used[j] && valid) {
//             used[j] = true;
//             best = max(best, 1 + tryPairs(male, female, used, i + 1));
//             used[j] = false;
//         }
//     }
//     return best;
// }
//
// int maxDancingPairs(const vector<int>& male, const vector<int>& female) {
//     vector<bool> used(female.size(), false);
//     return tryPairs(male, female, used, 0);
// }

#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& shorter, vector<int>& taller) {
    sort(shorter.begin(), shorter.end());
    sort(taller.begin(), taller.end());

    size_t i = 0;
    for (int height : taller) {
        if (i == shorter.size()) {
            break;
        }
        if (shorter[i] < height) {
            i++;
        }
    }
    return static_cast<int>(i);
}

int maxDancingPairs(const vector<int>& male, const vector<int>& female) {
    vector<int> maleWantsTaller, maleWantsShorter;
    vector<int> femaleWantsTaller, femaleWantsShorter;

    for (int height : male) {
        if (height > 0) {
            maleWantsTaller.push_back(height);
        } else {
            maleWantsShorter.push_back(-height);
        }
    }
    for (int height : female) {
        if (height > 0) {
            femaleWantsTaller.push_back(height);
        } else {
            femaleWantsShorter.push_back(-height);
        }
    }

    return countPairs(maleWantsTaller, femaleWantsShorter) +
           countPairs(femaleWantsTaller, maleWantsShorter);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    vector<int> male(n), female(n);
    for (int& height : male) {
        cin >> height;
    }
    for (int& height : female) {
        cin >> height;
    }

    cout << maxDancingPairs(male, female) << '\n';
    return 0;
}
