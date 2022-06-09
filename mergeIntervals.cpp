#include <bits/stdc++.h> 

bool comparator(const vector<int> &intA, const vector<int> &intB) {
    return intA[0] < intB[0];
}
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), comparator);
    vector<int> prev = intervals[0];
    vector<vector<int>> ans;
    
    for(int i=1;i<n;i++) {
        vector<int> curr = intervals[i];
        if(curr[0] <= prev[1]) {
            prev[1] = max(prev[1], curr[1]);
        }
        else {
            ans.push_back(prev);
            prev = curr;
        }
    }
    
    ans.push_back(prev);
    return ans;
}
