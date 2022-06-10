//Brute force approach
#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    int repeating = 0;
    unordered_map<int, bool> mp;
    
    int sum = 0;
    for(auto it : arr) {
        if(mp.find(it) != mp.end()) {
            repeating = it;
        }
        mp[it] = true;
        sum += it;
    }
    
    return { n*(n+1)/2 - sum + repeating, repeating };
}

//optimal approach
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
