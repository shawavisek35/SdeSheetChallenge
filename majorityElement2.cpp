#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    vector<int> ans;
    unordered_map<int,int> fr;
    for(auto it : arr) {
        fr[it]++;
    }
    
    int majority = arr.size()/3;
    for(auto it : fr) {
        if(it.second > majority) {
            ans.push_back(it.first);
        }
    }
    
    return ans;
}
