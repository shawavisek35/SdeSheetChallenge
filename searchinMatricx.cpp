//Brute force -> O(n2)
#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(mat[i][j] == target) {
                return true;
            }
        }
    }
    
    return false;
}

//optimised approach -> O(n+m)
#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    //Binary search in 2D matrix
    int i = 0;
    int j = n-1;
    
    while(i < m && j >= 0) {
        if(mat[i][j] == target) {
            return true;
        }
        else if(mat[i][j] < target) {
            i++;
        }
        else {
            j--;
        }
    }
    
    return false;
}
