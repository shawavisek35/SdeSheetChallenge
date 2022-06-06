#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long maxSum = 0;
    long long sum = 0;
    
    for(int i=0;i<n;i++) {
        if(sum + arr[i] < arr[i]) {
            sum = arr[i];
        }
        else {
            sum += arr[i];
        }
        
        maxSum = max(sum, maxSum);
    }
    
    return maxSum;
}
