/*
Return the length of the longest contiguous subarray in which
all pairs differ by at most limit.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// class Solution {
// public:
//     int longestSubarray(vector<int>& nums, int limit) {
//         int best = 0;
//         for (int left = 0; left < static_cast<int>(nums.size()); left++) {
//             int low = nums[left];
//             int high = low;
//             for (int right = left; right < static_cast<int>(nums.size()); right++) {
//                 int value = nums[right];
//                 low = min(low, value);
//                 high = max(high, value);
//                 if (1LL * high - low <= limit) {
//                     best = max(best, right - left + 1);
//                 }
//             }
//         }
//         return best;
//     }
// };

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        if (limit < 0) {
            return 0;
        }

        deque<int> minIndices, maxIndices;
        int left = 0;
        int best = 0;

        for (int right = 0; right < static_cast<int>(nums.size()); right++) {
            while (!minIndices.empty() && nums[minIndices.back()] >= nums[right]) {
                minIndices.pop_back();
            }
            while (!maxIndices.empty() && nums[maxIndices.back()] <= nums[right]) {
                maxIndices.pop_back();
            }
            minIndices.push_back(right);
            maxIndices.push_back(right);

            while (1LL * nums[maxIndices.front()] - nums[minIndices.front()] > limit) {
                if (minIndices.front() == left) {
                    minIndices.pop_front();
                }
                if (maxIndices.front() == left) {
                    maxIndices.pop_front();
                }
                left++;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
