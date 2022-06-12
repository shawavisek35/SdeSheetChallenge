//Brute force approach -> O(n) + space -> O(n)

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

//Optimal Approach -> O(n)
//Moore's voting algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int ans = 0;
        for(auto it : nums) {
            if(cnt == 0) {
                ans = it;
            }
            
            if(ans == it) {
                cnt ++;
            }
            else {
                cnt --;
            }
        }
        
        return cnt > 0 ? ans : -1;
    }
};
