/*
CodeChef SHOOT0, the one-row case. Each cell contains neither
group (0), Aarsi (1), Krypto (2), or both (3). For each column,
print the absolute difference between the groups' total distances
to that column.

Input: T test cases, each with N = 1 and M, then M cell values.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// void printCostDifferences(const vector<int>& cells) {
//     int m = static_cast<int>(cells.size());
//     for (int line = 0; line < m; line++) {
//         long long aarsi = 0, krypto = 0;
//         for (int i = 0; i < m; i++) {
//             int distance = abs(line - i);
//             if (cells[i] == 1 || cells[i] == 3) {
//                 aarsi += distance;
//             }
//             if (cells[i] == 2 || cells[i] == 3) {
//                 krypto += distance;
//             }
//         }
//         if (line > 0) {
//             cout << ' ';
//         }
//         cout << abs(aarsi - krypto);
//     }
//     cout << '\n';
// }

#include <bits/stdc++.h>
using namespace std;

void printCostDifferences(const vector<int>& cells) {
    int m = static_cast<int>(cells.size());
    long long totalBalance = 0;
    long long difference = 0;

    for (int i = 0; i < m; i++) {
        int balance = (cells[i] == 1) - (cells[i] == 2);
        totalBalance += balance;
        difference += 1LL * i * balance;
    }

    long long prefixBalance = 0;
    for (int line = 0; line < m; line++) {
        if (line > 0) {
            cout << ' ';
        }
        cout << abs(difference);

        prefixBalance += (cells[line] == 1) - (cells[line] == 2);
        difference += prefixBalance - (totalBalance - prefixBalance);
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    if (!(cin >> tests)) {
        return 0;
    }

    while (tests--) {
        int n, m;
        cin >> n >> m;
        vector<int> cells(m);
        for (int& cell : cells) {
            cin >> cell;
        }
        printCostDifferences(cells);
    }
    return 0;
}
