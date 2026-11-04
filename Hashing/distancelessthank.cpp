/*
Check if there are any 
two Equal numbers in an array at a 
distance less than or equal to k
*/

#include<bits/stdc++.h>
using namespace std;


bool hasDuplicateWithinK(vector<int>& arr, int k){
    // two distinct positions can't be at distance 0
    if(k <= 0) return false;

    unordered_map<int,int>lastidx;

    int n = arr.size();

    for(int i = 0; i < n; i++){
        int x = arr[i];

        if(lastidx.count(x) && i - lastidx[x] <= k){
            return true;
        }

        lastidx[x] = i;
    }
    return false;
}
int main(){
    vector<int> arr = {13, 4, 5, 66, 4, 5, 6, 2};
    cout << "k=2 -> " << (hasDuplicateWithinK(arr, 2) ? "Yes" : "No") << "\n";
    cout << "k=3 -> " << (hasDuplicateWithinK(arr, 3) ? "Yes" : "No") << "\n";
    return 0;
}