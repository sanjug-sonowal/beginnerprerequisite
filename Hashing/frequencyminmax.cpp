/*
We are given an Array of Numbers. 
We have to find and 
print any Number with Maximum Frequency and Minimum Frequency
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr = {2,4,54,5,5,3,2,1};

    unordered_map<int,int>freq;
    for(int x : arr){
        freq[x]++;
    }

    int minfreq = INT_MAX, maxfreq = 0;
    int minele = arr[0], maxele = arr[0];

    for(auto &p : freq){
        int ele = p.first;
        int f   = p.second;

        if(f > maxfreq){
            maxfreq = f;
            maxele  = ele;
        }
        if(f < minfreq){
            minfreq = f;
            minele  = ele;
        }
    }

    cout << "Minimum frequency : " << minfreq << ", element : " << minele << "\n";
    cout << "Maximum frequency : " << maxfreq << ", element : " << maxele << "\n";
    return 0;
}