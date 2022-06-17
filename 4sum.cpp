#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int left = j+1;
            int right = n-1;
            
            int remTarget = target - (arr[i] + arr[j]);
            while(left < right) {
                if(arr[left] + arr[right] > remTarget) {
                    right --;    
                }
                else if(arr[left] + arr[right] < remTarget) {
                    left ++;
                }
                
                else {
                    return "Yes";
                }
            }
        }
    }
    
    return "No";
}
