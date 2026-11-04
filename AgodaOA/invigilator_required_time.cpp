/*
For each query interval, return the elapsed time when at least k
students are taking exams in the same room. An exam contributes
duration from its start to its end. An instant adds no duration.
Return one integer duration per query, in the original order.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// vector<int> minTime(vector<int> start, vector<int> end,
//                     vector<int> q_start, vector<int> q_end, int k) {
//     vector<int> ans(q_start.size(), 0);
//     for (size_t q = 0; q < q_start.size(); q++) {
//         for (long long time = q_start[q]; time < q_end[q]; time++) {
//             int active = 0;
//             for (size_t i = 0; i < start.size(); i++) {
//                 if (start[i] <= time && time < end[i]) {
//                     active++;
//                 }
//             }
//             if (active >= k) {
//                 ans[q]++;
//             }
//         }
//     }
//     return ans;
// }

#include <bits/stdc++.h>
using namespace std;

vector<int> minTime(vector<int> start, vector<int> end,
                    vector<int> q_start, vector<int> q_end, int k) {
    map<int, int> events;
    for (size_t i = 0; i < start.size(); i++) {
        events[start[i]]++;
        events[end[i]]--;
    }
    for (size_t q = 0; q < q_start.size(); q++) {
        events[q_start[q]] += 0;
        events[q_end[q]] += 0;
    }

    map<int, long long> prefix;
    int active = 0;
    long long elapsed = 0;
    int previous = 0;
    if (!events.empty()) {
        previous = events.begin()->first;
    }

    for (const auto& event : events) {
        int time = event.first;
        if (active >= k) {
            elapsed += static_cast<long long>(time) - previous;
        }
        prefix[time] = elapsed;
        active += event.second;
        previous = time;
    }

    vector<int> ans(q_start.size());
    for (size_t q = 0; q < q_start.size(); q++) {
        ans[q] = prefix[q_end[q]] - prefix[q_start[q]];
    }
    return ans;
}
