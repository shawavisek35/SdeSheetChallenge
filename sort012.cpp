#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
    int i = 0; //for zero
    int j = 0; //for one
    int k = n-1; //for two
    
    for(int m=0;m<n;m++) {
        if(arr[j] == 0) {
            swap(arr[j], arr[i]);
            i++;
            j++;
        }
        else if(arr[j] == 2) {
            swap(arr[j], arr[k]);
            k--;
        }
        else {
            j++;
        }
    }
    
    return;
}
