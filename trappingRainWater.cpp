#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    vector<long> prefix(n, 0);
    vector<long> suffix(n, 0);
    prefix[0] = arr[0];
    suffix[n-1] = arr[n-1];
    long ans = 0;
    for(int i=1;i<n;i++) {
        prefix[i] = max(prefix[i-1], arr[i]);
    }
    
    for(int i=n-2;i>=0;i--) {
        suffix[i] = max(suffix[i+1], arr[i]);
    }
    
    for(int i=1;i<n-1;i++) {
        long maxHeight = min(prefix[i], suffix[i]);
        ans += (maxHeight - arr[i]);
    }
    
    return ans;
}
