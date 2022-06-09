//Brute force method
#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
	unordered_map<int, bool> mp;
    for(auto it : arr) {
        if(mp.find(it) != mp.end()) {
            return it;
        }
        mp[it] = true;
    }
    return -1;
}

//optimal method -> linked list cycle method
#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
    int slow = arr[0];
    int fast = arr[0];
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow != fast);
    
    fast = arr[0];
    while(slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
    
    return fast;
}
