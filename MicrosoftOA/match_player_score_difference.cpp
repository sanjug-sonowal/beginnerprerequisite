/*
Two players alternate turns, starting with player one. On each turn,
remove the first number and add it to that player's score. Reverse the
remaining sequence if the removed number is even.

Return player one's score minus player two's score.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// int getScoreDifference(vector<int> numSeq) {
//     int difference = 0;
//     bool firstTurn = true;
//
//     while (!numSeq.empty()) {
//         int value = numSeq.front();
//         numSeq.erase(numSeq.begin());
//
//         if (firstTurn) {
//             difference += value;
//         } else {
//             difference -= value;
//         }
//
//         if (value % 2 == 0) {
//             reverse(numSeq.begin(), numSeq.end());
//         }
//         firstTurn = !firstTurn;
//     }
//     return difference;
// }

#include <bits/stdc++.h>
using namespace std;

int getScoreDifference(vector<int> numSeq) {
    int left = 0;
    int right = static_cast<int>(numSeq.size()) - 1;
    int difference = 0;
    bool reversed = false;
    bool firstTurn = true;

    while (left <= right) {
        int value;
        if (reversed) {
            value = numSeq[right];
            right--;
        } else {
            value = numSeq[left];
            left++;
        }

        if (firstTurn) {
            difference += value;
        } else {
            difference -= value;
        }

        if (value % 2 == 0) {
            reversed = !reversed;
        }
        firstTurn = !firstTurn;
    }

    return difference;
}
