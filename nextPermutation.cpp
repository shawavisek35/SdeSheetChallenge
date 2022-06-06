#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int i = n-2;
    for(;i>=0;i--) {
        if(permutation[i] < permutation[i+1]) {
            break;
        }
    }
    
    if(i < 0) {
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }
    int l = n-1;
    for(;l>i;l--) {
        if(permutation[l] > permutation[i]) {
            break;
        }
    }
    
    swap(permutation[l], permutation[i]);
    reverse(permutation.begin() + i + 1, permutation.end());
    return permutation;
}
