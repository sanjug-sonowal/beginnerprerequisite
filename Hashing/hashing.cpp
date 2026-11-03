/*
You are given an array of size “n” ; 
you are also given “Q” queries 
for each of the query please tell how many times a 
given number occurs in the array
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr = {3,2,4,3,3,5,4,3};
    vector<int>queries = {2,4,3};

    unordered_map<int,int>mp;

    for(int x : arr){
        mp[x]++;
    }

    for(int q: queries){
        cout<<mp[q]<<" ";
    }
    return 0;
}