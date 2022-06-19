#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    unordered_map<int,int> mp;
    int cnt = 0;
    int xorSum = 0;
    for(int i=0;i<n;i++) {
        xorSum ^= arr[i];
        if(xorSum == x) cnt++;
        if(mp.find(xorSum ^ x) != mp.end()) {
            cnt += mp[xorSum ^ x];
        }
        mp[xorSum]++;
    }
    
    return cnt;
}
