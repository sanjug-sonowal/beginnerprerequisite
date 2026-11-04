/*
Given a string consisting of uppercase
English letters, insert at most one
character at any position.

Find the maximum number of "LCT"
subsequences possible after insertion.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();

        vector<long long> prefixL(n + 1, 0);
        vector<long long> suffixT(n + 1, 0);

        long long countL = 0;
        long long countLC = 0;
        long long countLCT = 0;

        for (int i = 0; i < n; i++) {
            prefixL[i + 1] = prefixL[i];

            if (s[i] == 'L') {
                countL++;
                prefixL[i + 1]++;
            }
            else if (s[i] == 'C') {
                countLC += countL;
            }
            else if (s[i] == 'T') {
                countLCT += countLC;
            }
        }

        long long countT = 0;
        long long countCT = 0;

        for (int i = n - 1; i >= 0; i--) {
            suffixT[i] = suffixT[i + 1];

            if (s[i] == 'T') {
                countT++;
                suffixT[i]++;
            }
            else if (s[i] == 'C') {
                countCT += countT;
            }
        }

        long long insertL = countCT;
        long long insertT = countLC;
        long long insertC = 0;

        for (int i = 0; i <= n; i++) {
            long long sum = prefixL[i] * suffixT[i];
            insertC = max(insertC, sum);
        }

        long long extra = max(insertL, max(insertC, insertT));

        return countLCT + extra;
    }
};

// int main() {
//     string s = "LCCT";
//
//     Solution obj;
//
//     cout << obj.numOfSubsequences(s) << endl;
//
//     return 0;
// }
