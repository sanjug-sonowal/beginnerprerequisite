/*
Find the longest substring of a lowercase word in which the ASCII
difference between adjacent characters is at most k in absolute value.
If several substrings have maximum length, return the earliest one.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// string longestKInterspaceSubstring(string word, int k) {
//     size_t bestStart = 0;
//     size_t bestLength = 0;
//     for (size_t start = 0; start < word.size(); start++) {
//         for (size_t end = start; end < word.size(); end++) {
//             if (end > start && abs(word[end] - word[end - 1]) > k) {
//                 break;
//             }
//             size_t length = end - start + 1;
//             if (length > bestLength) {
//                 bestStart = start;
//                 bestLength = length;
//             }
//         }
//     }
//     return word.substr(bestStart, bestLength);
// }

#include <bits/stdc++.h>
using namespace std;

string longestKInterspaceSubstring(string word, int k) {
    size_t start = 0;
    size_t bestStart = 0;
    size_t bestLength = 0;

    for (size_t i = 0; i < word.size(); i++) {
        if (i > 0 && abs(word[i] - word[i - 1]) > k) {
            start = i;
        }

        size_t length = i - start + 1;
        if (length > bestLength) {
            bestStart = start;
            bestLength = length;
        }
    }

    return word.substr(bestStart, bestLength);
}
