//brute force -> O(n2)
#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    int count = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(arr[j] > arr[i]) count++;
        }
    }
    
    return count;
}
