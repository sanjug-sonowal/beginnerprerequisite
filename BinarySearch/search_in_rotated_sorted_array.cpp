/*
Given a rotated ascending array of distinct integers, return the
0-based index of target, or -1 if it is absent.
*/

// Brute Force Approach - Inactive
// #include <bits/stdc++.h>
// using namespace std;
//
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         auto it = find(nums.begin(), nums.end(), target);
//         if (it == nums.end()) {
//             return -1;
//         }
//         return static_cast<int>(it - nums.begin());
//     }
// };

// Pivot and Binary Search Approach - Inactive
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int left = 0;
//         int right = static_cast<int>(nums.size()) - 1;
//
//         while (left < right) {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] > nums[right]) {
//                 left = mid + 1;
//             } else {
//                 right = mid;
//             }
//         }
//         auto begin = nums.begin();
//         auto end = begin + left;
//         if (target <= nums.back()) {
//             begin = end;
//             end = nums.end();
//         }
//
//         auto it = lower_bound(begin, end, target);
//         if (it == end || *it != target) {
//             return -1;
//         }
//         return static_cast<int>(it - nums.begin());
//     }
// };

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
