#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++) {
        if(i>0 && arr[i] == arr[i-1]) continue;
        int remSum = K - arr[i];
        int low = i+1;
        int high = n-1;
        
        while(low<high) {
            int sum = arr[low] + arr[high];
            if(sum > remSum) {
                high --;
            }
            else if(sum < remSum) {
                low ++;
            }
            else {
                vector<int> temp = {arr[i], arr[low], arr[high]};
                while(arr[low] == temp[1]) low ++;
                while(arr[high] == temp[2]) high --;
                ans.push_back(temp);
            }
        }
    }
    return ans;
}
