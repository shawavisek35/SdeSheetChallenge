#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int startRow = 0;
    int endRow = n;
    int startCol = 0;
    int endCol = m;
    int prev = 0;
    int curr = 0;
    
    while(startRow < endRow && startCol < endCol) {
        
        if(startRow + 1 == endRow || startCol + 1 == endCol) break;\
        prev = mat[startRow + 1][startCol];
        for(int i=startCol;i<endCol;i++) {
            curr = mat[startRow][i];
            mat[startRow][i] = prev;
            prev = curr;
        }
        startRow ++;
        
        for(int i=startRow;i<endRow;i++) {
            curr = mat[i][endCol-1];
            mat[i][endCol-1] = prev;
            prev = curr;
        }
        
        endCol --;
        
        for(int i=endCol - 1;i>=startCol;i--) {
            curr = mat[endRow - 1][i];
            mat[endRow - 1][i] = prev;
            prev = curr;
        }
        
        endRow --;
        
        for(int i=endRow-1;i>=startRow;i--) {
            curr = mat[i][startCol];
            mat[i][startCol] = prev;
            prev = curr;
        }
        startCol ++;
    }
}
