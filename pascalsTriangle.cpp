#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long int>> ans;
    vector<long long int> res = {1};
    ans.push_back(res);
    
    for(int i=1;i<n;i++) {
        vector<long long int> res;
        for(int j=0;j<=i;j++) {
            long long int res1 = 0;
            long long int res2 = 0;
            if(j-1>=0) res1 = ans[i-1][j-1];
            if(j < i) res2 = ans[i-1][j];
            res.push_back(res1 + res2);
        }
        ans.push_back(res);
    }
    
    return ans;
}
