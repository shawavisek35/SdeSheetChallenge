//Brute force approach
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // int m = matrix[0].size();
        vector<vector<int>> temp(n, vector<int>(n, 0));
        
        int row = 0;
        int col = n-1;
        
        while(row < n) {
            for(int i=0;i<n;i++) {
                temp[i][col] = matrix[row][i];
            }
            row++;
            col--;
        }
        
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                matrix[i][j] = temp[i][j];
            }
        }
        
        return;
    }
};

//space optimised solution
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        
        //finding transpose
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //reverse each row of the transpose matrix
        for(int i=0;i<n;i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
        return;
    }
};
