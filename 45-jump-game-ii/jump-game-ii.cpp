class Solution {
public:
    int solve(int i, vector<int> &nums, vector<int> &dp){
        int n = nums.size();
        if(i == n - 1){
            return dp[i] = 0;
        }
        if(dp[i] != INT_MAX) return dp[i];
        if(nums[i] == 0)  return dp[i] = n + 1;
        
        if(i + nums[i] >= n -1){
            return dp[i] = 1;
        }
        
        int sol = n + 1;

        for(int j = 1; j <= nums[i]; j++){
            sol = min(sol,1 + solve(i + j,nums,dp));
        }

        return dp[i] = sol;
    }
    
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,INT_MAX);
        return solve(0,nums,dp);
    }
};