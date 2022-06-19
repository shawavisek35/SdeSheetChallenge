#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    int n = input.size();
    unordered_map<char, int> fr;
    int maxLength = 0;
    int i = 0;
    int j = 0;
    while(j < n) {
        fr[input[j]]++;
        while(i<n && fr[input[j]] != 1) {
            fr[input[i]] --;
            if(fr[input[i]] == 0) fr.erase(input[i]);
            i++;
        }
        maxLength = max(maxLength, j-i+1);
        j++;
    }
    
    return maxLength;
}
