class Solution {
public:
    int solve(int i, int last, vector<int> &nums, vector<vector<int>> &dp){
        int n = nums.size();
        if(dp[i][last] != -1){
            return dp[i][last];
        }
        if(i == 0){
            if(last == n){
                return 1;
            }
            else{
                if(nums[0] < nums[last]){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }

        int take = 0;
        if(last == n){
            take = 1 + solve(i - 1,i,nums,dp);
        }
        else{
            if(nums[i] < nums[last]){
                take = 1 + solve(i - 1,i,nums,dp);
            }
        }
        int notTake = solve(i - 1,last,nums,dp);


        return dp[i][last] = max(take,notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        dp[0][n] = 1;
        for(int i = 0; i < n; i++){
            if(nums[0] < nums[i]){
                dp[0][i] = 1;
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= n; j++){
                int take = 0;
                int notTake = dp[i - 1][j];
                if(j == n || nums[i] < nums[j]){
                    take = 1 + dp[i - 1][i];
                }
                dp[i][j] = max(take,notTake);
            }
            
        }

        return dp[n - 1][n];
    }
};