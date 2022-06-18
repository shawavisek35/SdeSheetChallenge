class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for(int i=0;i<n;i++) {
            long long target1 = target - arr[i];
            for(int j=i+1;j<n;j++) {
                long long target2 = target1 - arr[j];
                int left = j+1;
                int right = n-1;
                
                int currJ = arr[j];
                while(left < right) {
                    long long int rem = arr[left] + arr[right];
                    if(rem > target2) {
                        right --;
                    }
                    else if(rem < target2) {
                        left ++;
                    }
                    else {
                        vector<int> quad = { arr[i], arr[j], arr[left], arr[right] };
                        ans.push_back(quad);
                        
                        //making sure that the duplicates are skipped
                        while(left < right && arr[left] == quad[2]) {
                            left ++;
                        }
                        
                        while(left < right && arr[right] == quad[3]) {
                            right --;
                        }
                    }
                }
                //making sure that the duplicates are skipped
                while(j + 1<n && arr[j+1] == arr[j]) j++;
            }
            //making sure that the duplicates are skipped
            while(i+1<n && arr[i+1] == arr[i]) i++;
        }
        return ans;
    }
};
