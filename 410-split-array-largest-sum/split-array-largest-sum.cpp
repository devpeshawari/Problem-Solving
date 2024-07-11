class Solution {
public:
    int solve(int ind, vector<int> &nums, int k, vector<vector<int>> &dp){
        if(k < 0){
            return INT_MAX;
        }
        if(dp[ind][k] != -1){
            return dp[ind][k];
        }
        int n = nums.size();
        int sol = INT_MAX;
        int sum = 0;
        
        for(int i = ind; i < n; i++){
            sum+=nums[i];
            int temp = INT_MAX;
            if(i == n - 1){
                if(k == 0){
                    temp = sum;
                    sol = min(temp,sol);
                }
                continue;
            }
            temp = max(sum, solve(i + 1,nums,k - 1,dp));
            sol = min(temp,sol);
        }

        

        return dp[ind][k] = sol;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(k,-1));
        return solve(0,nums,k - 1,dp);
    }
};