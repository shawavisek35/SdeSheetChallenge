#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
    unordered_map<int,int> fr;
    for(int i=0;i<n;i++) {
        fr[arr[i]]++;
    }
    
    int ans = -1;
    //int maxA = 0;
    int major = floor(n/2);
    for(auto it : fr) {
        if(it.second > major) {
            ans = it.first;
            break;
        }
    }
    
    return ans;
}
