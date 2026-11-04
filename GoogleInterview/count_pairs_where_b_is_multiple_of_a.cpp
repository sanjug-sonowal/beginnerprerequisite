/*
Count index pairs (i, j) with B[j] divisible by A[i].
Repeated values at different indices contribute separate pairs.
Input: N, then N values of A and N values of B.
Values are in [1, 1000000] and N is at most 100000.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// long long countDivisiblePairs(const vector<int>& a, const vector<int>& b) {
//     long long count = 0;
//     for (int divisor : a) {
//         for (int value : b) {
//             if (value % divisor == 0) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

#include <bits/stdc++.h>
using namespace std;

long long countDivisiblePairs(const vector<int>& a, const vector<int>& b) {
    int limit = *max_element(b.begin(), b.end());
    vector<int> freqA(limit + 1, 0), freqB(limit + 1, 0);

    for (int value : a) {
        if (value <= limit) {
            freqA[value]++;
        }
    }
    for (int value : b) {
        freqB[value]++;
    }

    long long count = 0;
    for (int divisor = 1; divisor <= limit; divisor++) {
        if (freqA[divisor] == 0) {
            continue;
        }

        for (int multiple = divisor; multiple <= limit; multiple += divisor) {
            count += 1LL * freqA[divisor] * freqB[multiple];
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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

    cout << countDivisiblePairs(a, b) << '\n';
    return 0;
}
