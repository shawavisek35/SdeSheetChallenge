#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int target){
   // Write your code here.
   sort(arr.begin(), arr.end());
    int i = 0;
    int j = arr.size()-1;
    vector<vector<int>> ans;
    while(i<j) {
        if(arr[i] + arr[j] == target) {
            ans.push_back({arr[i], arr[j]});
            int leftCount = 0;
            int rightCount = 0;
            int left = arr[i];
            int right = arr[j];
            
            if(arr[i] == arr[j]) {
                int c = j - i + 1;
                for(int k=1;k<=c*(c-1)/2-1;k++) {
                    ans.push_back({ left, right });
                }
                break;
            }
            
            while(arr[i] == left && i<=j) {
                i++;
                leftCount++;
            }
            
            while(arr[j] == right && i<=j) {
                j--;
                rightCount++;
            }
            
            for(int k=1;k<=leftCount*rightCount-1;k++) {
                ans.push_back({left, right});
            }
        }
        else if(arr[i] + arr[j] > target) {
            j--;
        }
        else {
            i++;
        }
    }
    
    return ans;
}
