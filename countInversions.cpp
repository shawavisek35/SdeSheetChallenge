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

//optimised approach -> Merge Sort -> O(nlogn)
#include <bits/stdc++.h>
void merge(long long *arr, int low, int mid, int end, long long &count) {
    vector<long long> leftArr;
    vector<long long> rightArr;
    for(int i=low;i<=mid;i++) {
        leftArr.push_back(arr[i]);
    }
    for(int i=mid+1;i<=end;i++) {
        rightArr.push_back(arr[i]);
    }
    
    int i=0;
    int j=0;
    int k = low;
    while(i<leftArr.size() && j<rightArr.size()) {
        if(leftArr[i] > rightArr[j]) {
            count += (leftArr.size() - i);
            arr[k++] = rightArr[j++];
        }
        else {
            arr[k++] = leftArr[i++];
        }
    }
    
    while(i<leftArr.size()) {
        arr[k++] = leftArr[i++];
    }
    while(j<rightArr.size()) {
        arr[k++] = rightArr[j++];
    }
    
    return;
}

void mergeSort(long long *arr, int i, int j, long long &count) {
    if(i>=j) return;
    int mid = (i+j)/2;
    mergeSort(arr, i, mid, count);
    mergeSort(arr, mid+1, j, count);
    merge(arr, i, mid, j, count);
    return;
}
long long getInversions(long long *arr, int n){
    long long count = 0;
    mergeSort(arr, 0, n-1, count);
    return count;
}
