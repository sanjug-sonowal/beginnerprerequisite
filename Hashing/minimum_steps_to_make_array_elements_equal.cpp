/*
Given an array of size N, in one operation,
select the largest element and replace it
with the second-largest distinct element.

Find the minimum number of operations
required to make all array elements equal.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {5, 5, 4, 3};
    int n = a.size();

    map<int, int, greater<int>> freq;

    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    long long steps = 0;
    long long count = 0;

    for (auto it : freq) {
        steps += count;
        count += it.second;
    }

    cout << steps << endl;

    return 0;
}
