#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    sort(arr.begin(), arr.end());
    int cnt = 1;
    int maxCount = 1;
    
    for(int i=1;i<n;i++) {
        if(arr[i] - arr[i-1] == 0) continue;
        else if(arr[i] - arr[i-1] != 1) {
            cnt = 1;
        }        
        else {
            cnt ++;
        }
        maxCount = max(maxCount, cnt);
    }
    
    return maxCount;
}
