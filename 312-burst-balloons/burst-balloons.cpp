class Solution {
public:
    int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int sol = INT_MIN;
        for(int k = i; k <= j; k++){
            int add = nums[k] * nums[i - 1] * nums[j + 1];
            sol = max(sol,add + solve(i,k - 1,nums,dp) + solve(k + 1, j, nums,dp));
        }


        return dp[i][j] = sol;
    }
    
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);  
        vector<vector<int>> dp(n + 1,vector<int>(n + 1, -1));
        return solve(1,n,nums,dp);
    }
}; 