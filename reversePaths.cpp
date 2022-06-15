//Modified merge sort
#include <bits/stdc++.h> 
void merge(vector<int> &arr, int low, int mid, int end, int &cnt) {
    
    vector<int> temp1, temp2;
    for(int i=low;i<=mid;i++) {
        temp1.push_back(arr[i]);
    }
    for(int i=mid+1;i<=end;i++) {
        temp2.push_back(arr[i]);
    }
    
    int i=0;
    int j=0;
    int k=low;
    
    while(i<temp1.size()) {
        while(j < temp2.size() && temp1[i] > temp2[j]*2) {
            j++;
        }
        cnt += j;
        i++;
    }
    
    i=0;
    j=0;
    while(i<temp1.size() && j<temp2.size()) {
        if(temp1[i] > temp2[j]) {
            arr[k++] = temp2[j++];
        }
        else {
            arr[k++] = temp1[i++];
        }
    }
    
    while(i<temp1.size()) {
        arr[k++] = temp1[i++];
    }
    
    while(j<temp2.size()) {
        arr[k++] = temp2[j++];
    }
    
    return;
}
void mergeSort(vector<int> &arr, int i, int j, int &cnt) {
    if(i >= j) return;
    int mid = (i+j)/2;
    mergeSort(arr, i, mid, cnt);
    mergeSort(arr, mid+1, j, cnt);
    merge(arr, i, mid, j, cnt);
    return;
}
int reversePairs(vector<int> &arr, int n){
    int cnt = 0;
    mergeSort(arr, 0, n-1, cnt);
    return cnt;
}
