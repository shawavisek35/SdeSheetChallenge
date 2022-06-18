#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector<int> arr) {
    unordered_map<int,int> mp;
    int maxLength = 0;
    int sum = 0;
    int n = arr.size();
    for(int i=0;i<n;i++) {
        sum += arr[i];
        if(sum == 0) {
            maxLength = max(maxLength, i+1);
        }
        if(mp.find(sum) != mp.end()) {
            maxLength = max(maxLength, i - mp[sum]);
        }
        else {
            mp[sum] = i;
        }
    }
    
    return maxLength;
}
