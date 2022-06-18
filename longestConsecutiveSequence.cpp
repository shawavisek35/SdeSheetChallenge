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

//Best approach: Time: O(n) space: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(auto it : nums) {
            mp[it] = true;
        }
        
        int cnt = 1;
        int maxCnt = 0;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(mp.find(nums[i] - 1) != mp.end()) {
                continue;
            }
            else {
                int val = nums[i];
                int cnt = 1;
                while(mp.find(val + 1) != mp.end()) {
                    cnt ++;
                    val ++;
                }
                
                maxCnt = max(maxCnt, cnt);
            }
        }
        
        return maxCnt;
    }
};
