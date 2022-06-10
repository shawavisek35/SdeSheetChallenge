#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    long long sumArr = 0;
    long long pArr = 0;
    long long sumN = n*(n+1)/2;
    long long pN = n*(n+1)*(2*n+1)/6;
    
    for(auto it : arr) {
        sumArr += it;
        pArr += (it * it);
    }
    
    int s = (int)(sumN - sumArr);
    int p = (int)(pN - pArr);
    int missing = (s + p/s)/2;
    int repeated = missing - s;
    
    return { missing, repeated };
    
}
