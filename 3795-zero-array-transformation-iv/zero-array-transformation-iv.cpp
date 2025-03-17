class Solution {
public:
    int solve(int i, int num, vector<int> &arr, vector<int> &index, vector<vector<int>> &dp){
        int n = arr.size();
        if(num < 0){
            return INT_MAX;
        }
        if(num == 0){
            if(i == 0){
                return 0;
            }
            else{
                return index[i - 1];
            }
        }
        if(i == n){
            return INT_MAX;
        }
        if(dp[num][i] != -1) return dp[num][i];
        int take = solve(i + 1,num - arr[i], arr, index, dp);
        int notTake = solve(i + 1,num, arr, index, dp);

        return dp[num][i] = min(take,notTake);
    }
    
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        int sol = INT_MIN;
        vector<vector<int>>arr(n);
        vector<vector<int>>index(n);
        
        for(int i = 0; i < q; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            for(int j = l; j <= r; j++){
                arr[j].push_back(val);
                index[j].push_back(i + 1);
            }
        }

        for(int i = 0; i < n; i++){
            int num = nums[i];
            vector<vector<int>> dp(num + 1,vector<int>(arr[i].size() + 1,-1));
            sol = max(sol,solve(0,num,arr[i],index[i],dp));
    
        }

        if(sol == INT_MAX) return -1;

        return sol;
    }
};